#include <stdio.h>
#include <math.h>

#define MAX 1000000000

// int checkFive(int time){
//     int result = 1;
//     for(int i=0; i<time; i++){
//         result *= 5;
//     }
//     return result;
// }

void checkZero(int input){
    int count = 0;
    int five_count = 0;
    int temp = input;
    while(1){
        temp /= 5;
        if(temp == 0){
            break;
        }
        five_count++;
    }
    for(int i=1; i<=five_count; i++){
        int divider = pow(5, i);
        //printf("%d %d %d\n", input/divider);
        count = count + (input / divider);
    }
    printf("%d\n", count);
}

int main(void){
    int num = 0;
    scanf("%d", &num);
    for(int i=0; i<num; i++){
        int  input = 0;
        scanf("%d", &input);
        if(input<1 || input>MAX){
            return 0;
        }
        checkZero(input);
    }
}