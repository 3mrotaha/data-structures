#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "../std_types/std_types.h"


void GetString(string_t* str){
    *str = (string_t) malloc(100 * sizeof(**str));
    scanf("%s", *str);
    *str = realloc(*str, strlen(*str) * sizeof(**str));
}

void Concatinate(u8_t c, string_t* str, u32_t pos){
    *(*str + pos) = c;
}

u128_t Sto_int(string_t str){
    u128_t num = 0;
    s16_t i = strlen(str) - 1, pw = 0;
    while (i >= 0)
    {
        num += ((*(str + i) - '0') * pow(10, pw));
        i--, pw++;
    }    
    return num;
}