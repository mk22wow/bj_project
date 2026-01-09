#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(void){
    char Expression[51];
    scanf("%s", Expression);
    int len = strlen(Expression);
    
    int result = 0, temp = 0, idx = 0, Minus = 0;
    char Num[6];
    for(int i=0; i<=len; i++){
        if(isdigit(Expression[i])){
            Num[idx++] = Expression[i];
        }
        else{
            Num[idx] = '\0';
            temp = atoi(Num);
            if(Minus) result -= temp;
            else result += temp;

            if(Minus == 0 && Expression[i] == '-') Minus = 1;
            idx = 0;
        }
    }
    printf("%d\n", result);
    return 0;
}

// int idx = 0, len = 0;
// char Num[6];

// int Find_Minus(char str[]){
//     idx++;
//     memset(Num, 0, sizeof(Num));
//     int i = 0, temp = 0;
//     while(idx<len){
//         if(isdigit(str[idx])){
//             Num[i++] = str[idx];
//         }
//         if(!isdigit(str[idx]) || idx == len-1){
//             Num[i] = '\0';
//             temp += atoi(Num);
//             memset(Num, 0, sizeof(Num));
//             i = 0;
//             if(str[idx] == '-') break;
//         }
//         idx++;
//     }
//     return temp;
// }

// int Find(char str[]){
//     char Num[6];
//     int i = 0, result = 0;
//     while(idx<len){
//         if(isdigit(str[idx])){
//             Num[i++] = str[idx];
//         }
//         else if(str[idx] == '-'){
//             Num[i] = '\0';
//             result += atoi(Num);
//             i = 0;
//             memset(Num, 0, sizeof(Num));
//             result -= Find_Minus(str);
//             continue;
//         }
//         if(str[idx] == '+' || idx == len-1){
//             Num[i] = '\0';
//             result += atoi(Num);
//             memset(Num, 0, sizeof(Num));
//             i = 0;
//         }
//         idx++;
//     }

//     return result;
// }

// int main(void){
//     char Expression[51];
//     scanf("%s", Expression);
//     len = strlen(Expression);
    
//     int result = Find(Expression);
//     printf("%d\n", result);
//     return 0;
// }
