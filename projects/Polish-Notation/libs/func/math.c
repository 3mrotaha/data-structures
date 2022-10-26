#include <stdio.h>
#include <math.h>
#include "..\std_types\std_types.h"


f64_t squareRoot(f64_t num){
    return sqrt((f64_t) num);
}

f64_t Power(f64_t num, f64_t power){
    return pow((f64_t) num, (f64_t) power);
}

f64_t sum(f64_t num1, f64_t num2){
    return num1 + num2;
}

f64_t subtract(f64_t num1, f64_t num2){
    return num1 - num2;
}

f64_t multiply(f64_t num1, f64_t num2){
    return num1 * num2;
}

f64_t divide(f64_t num1, f64_t num2){
    return num1/(f64_t) num2;
}