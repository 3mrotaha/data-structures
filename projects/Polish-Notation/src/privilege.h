#ifndef _POLISH_PRIVILEGES_
#define _POLISH_PRIVILEGES_
#include "../libs/std_types/std_types.h"
#include "../libs/std_types/Polish_Errors.h"

/*
pre: it initializes the polish for a new operation, it should be used
     before using (GeneratePostifix) to initialize the indeces
post: initialize the polish and returns POLISH_INITIALIZED
*/
PolishError_t Polish_Init(void);

/*
pre: takes two parameters the first parameter is a pointer to a string to recieve the 
     value of the postfix
     the second parameter is the Infix to be evaluated (it shouldn't contain any space), it can 
     contain numbers of 1 or more digits or Letters (a-z/A-Z)
post: generate a postfix from the infix passed to the second parameter and returns EXPRESSION_DONE
*/
PolishError_t GeneratePostifix(string_t*, string_t);

/*
pre: it takes two parameters a pointer to float to recieve the evaluation value,
     and a string which is the postfix to be evaluated
post: Evaluates  the postfix to a final numerical value and returns EXPRESSION_DONE     
*/
PolishError_t EvaluatePostifix(f64_t*, string_t);


#endif