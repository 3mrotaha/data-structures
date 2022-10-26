#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libs/std_types/std_types.h"
#include "src/config.h"
#include "src/privilege.h"


void main(void){
    /*************************************************************
     * These superior test cases are provided by Eng. Menna Adel *
     * GitHub : https://github.com/MennaadAdeel                  *
     *************************************************************/

    string_t post;
    f64_t res;
    post = (string_t) calloc(POLISH_MAX_LENGTH, sizeof(u8_t));
    Polish_Init();
    GeneratePostifix(&post, "A+(B+C$D)/E+F*G-H\0");
    printf("%s\n", post);
    free(post);

    post = (string_t) calloc(POLISH_MAX_LENGTH, sizeof(u8_t));
    Polish_Init();
    GeneratePostifix(&post, "3+5*(2$3)+5\0");    
    printf("%s\n", post);
    EvaluatePostifix(&res, post);
    printf("Postifix Value : %0.5lf\n", res);
    free(post);

    post = (string_t) calloc(POLISH_MAX_LENGTH, sizeof(u8_t));
    Polish_Init();
    GeneratePostifix(&post, "(7/2)+4-2\0");
    printf("%s\n", post);
    EvaluatePostifix(&res, post);
    printf("Postifix Value : %0.5lf\n", res);
    free(post);

    post = (string_t) calloc(POLISH_MAX_LENGTH, sizeof(u8_t));
    Polish_Init();
    GeneratePostifix(&post, "(2*4)+5-2$2/(2+2)\0");
    printf("%s\n", post);
    EvaluatePostifix(&res, post);
    printf("Postifix Value : %0.5lf\n", res);
    free(post);

    post = (string_t) calloc(POLISH_MAX_LENGTH, sizeof(u8_t));
    Polish_Init();
    GeneratePostifix(&post, "5+(7$2+3-1)*2\0");
    printf("%s\n", post);
    EvaluatePostifix(&res, post);
    printf("Postifix Value : %0.5lf\n", res);
    free(post);

    post = (string_t) calloc(POLISH_MAX_LENGTH, sizeof(u8_t));
    Polish_Init();
    GeneratePostifix(&post, "(8+(4$3+7))*5\0");
    printf("%s\n", post);
    EvaluatePostifix(&res, post);
    printf("Postifix Value : %0.5lf\n", res);
    free(post);

    post = (string_t) calloc(POLISH_MAX_LENGTH, sizeof(u8_t));
    Polish_Init();
    GeneratePostifix(&post, "(82+(24$3+(42*(6+7))))*5+3214*(21+6$(3/5))\0");
    printf("%s\n", post);
    EvaluatePostifix(&res, post);
    printf("Postifix Value : %0.5lf\n", res);
    free(post);
}