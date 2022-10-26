#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../libs/std_types/std_types.h"
#include "../libs/std_types/Polish_Errors.h"
#include "../libs/func/math.h"
#include "../libs/func/string.h"

#include "config.h"
#include "private.h" 

#include "../stack/Error_States.h"
#include "../stack/stack_config.h"
#include "../stack/stack_privilege.h"


static u32_t Iterator = 0, Jterator = 0;   

PolishError_t Polish_Init(void){
    Iterator = Jterator = 0;
    return POLISH_INITIALIZED;
}


PolishError_t GeneratePostifix(string_t* Postifix, string_t Infix){
    Stack_t st;
    StackEntry e;
    CreateStack(&st);
    StackEntry top;
    
    // A + B * C $ D / E - F
    // ABCD$*/E+F-
    while (*(Infix + Iterator) != '\0'){
        while(Is_Digit(*(Infix + Iterator)) == IS_NUMBER)
            Concatinate(*(Infix + Iterator++), Postifix , Jterator++);
        if(*(Infix + Iterator) == '('){
            Iterator++;            
            GeneratePostifix(Postifix, Infix);
        }
        else if(*(Infix + Iterator) == ')'){        
            break;
        }
        else{           
            Concatinate(' ', Postifix , Jterator++);    
            e.type = IS_OPERATOR;
            e.value.operators = *(Infix + Iterator);
            StackTop(&top, &st);
            while(!precedent(e.value.operators, top.value.operators) && StackEmpty(st) != STACK_EMPTY){
                Pop(&top, &st);
                Concatinate((u8_t)top.value.operators, Postifix , Jterator++);                
                Concatinate(' ', Postifix , Jterator++);
                StackTop(&top, &st);
            }
            Push(e, &st);   
        }
        Iterator++;    
    }

    while (StackEmpty(st) != STACK_EMPTY)
    {
        Concatinate(' ', Postifix , Jterator++);
        Pop(&top, &st);
        Concatinate((u8_t)top.value.operators, Postifix , Jterator++);                
    }
    ClearStack(&st);
    return EXPRESSION_DONE;
}

PolishError_t EvaluatePostifix(f64_t* Result, string_t Postifix){
    Stack_t st;
    StackEntry e, op1, op2;
    CreateStack(&st);
    u32_t Iterator = 0, Jterator = 0;
    // A + B * C $ D / E - F
    // ABCD$*E/+F-
    while(*(Postifix + Iterator) != '\0'){
        while(Is_Digit(*(Postifix + Iterator)) == IS_NUMBER){
            string_t StrNum = (string_t) calloc(10, sizeof(u8_t));
            Jterator = 0;
            while(Is_Digit(*(Postifix + Iterator)) == IS_NUMBER){
                Concatinate(*(Postifix + Iterator++), &StrNum, Jterator++);
            }
            realloc(StrNum, (strlen(StrNum) + 1) * sizeof(u8_t));
            e.type = IS_NUMBER;
            e.value.operand = (f64_t)Sto_int(StrNum);
            Push(e, &st);
            free(StrNum);
            Iterator++;
        }
        if(StackEmpty(st) != STACK_EMPTY && *(Postifix + Iterator) != ' '){
            Pop(&op2, &st);
            Pop(&op1, &st);
            *Result = Calc(op1.value.operand, op2.value.operand, *(Postifix + Iterator));
            e.value.operand = *Result;
            Push(e, &st);
        }        
        Iterator++;
    }
    ClearStack(&st);
    return EXPRESSION_DONE;
}

static u32_t precedent(u8_t op1, u8_t op2){
    if(op1 == '$')
        return op2 != '$';
    else if(op1 == '/' || op1 == '*'){
        return op2 != '$' && op2 != '*' && op2 != '/';
    }
    else
        return op2 != '$' && op2 != '*' && op2 != '/' && op2 != '+' && op2 != '-';
}

static u8_t Is_Digit(u8_t c){
    if(IS_CAPITAL_LATER || IS_SMALL_LATER || IS_DIGIT)
        return IS_NUMBER;
    
    return IS_OPERATOR;
}

static f64_t Calc(f64_t op1, f64_t op2, u8_t operator){
    switch(operator){
        case '+':
            return (f64_t)sum(op1, op2);
            break;
        case '-':
            return (f64_t)subtract(op1, op2);
            break;
        case '*':
            return (f64_t)multiply(op1, op2);
            break;
        case '/':
            return (f64_t)divide(op1, op2);
            break;
        case '$':
            return (f64_t)Power(op1, op2);
            break;
    }
}