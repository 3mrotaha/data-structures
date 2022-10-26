#ifndef _PRIVATE_FILE_
#define _PRIVATE_FILE_

#include "../libs/std_types/std_types.h"

typedef struct{
    u8_t type;
    union data{
        f64_t operand;
        u8_t operators;
    }value;
}Element_t;


#define IS_OPERATOR         'o'
#define IS_NUMBER           'n'
#define IS_DIGIT            (c >= '0' && c <= '9')
#define IS_SMALL_LATER      (c >= 'a' && c <= 'z')
#define IS_CAPITAL_LATER    (c >= 'A' && c <= 'Z')

/*

pre: it takes 2 operators and compare the precedent of them
post: it returns 1 if the first operator is high precedence than the other one

*/
static u32_t precedent(u8_t, u8_t);

/*
pre: it takes a character and checks if it's not an operator
post: returns IS_NUMBER if the parameter is a number or a letter (A-Z/a-z)
      otherwise it returns IS_OPERATOR
*/
static u8_t Is_Digit(u8_t);

/*
pre: it takes two numbers and an operator and make an operation on these
     two numbers based on the passed operator (sum - subtraction - multiplication - divisin)
*/
static f64_t Calc(f64_t, f64_t, u8_t);


#endif