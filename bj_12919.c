#include <stdio.h>
#include <string.h>

char S[100];
char T[100];
char addA[2] = "A";
char addB[2] = "B";
int result = 0;

void Swap(char current[]){
    int len = strlen(current);
    char temp[100];
    strcpy(temp, current);
    for(int i=len-1; i>0; i--){
        current[len-1 - i] = temp[i];
    }
    current[len-1] = '\0';
}

void Find(char temp[]){
    if(result == 1) return;

    if(strlen(temp) == strlen(S)){
        if(strcmp(temp, S) == 0){
            result = 1;
        }
        return;
    }

    int len = strlen(temp);
    if(temp[len-1] == 'A'){
        char current[100];
        strcpy(current, temp);
        current[len-1] = '\0';
        Find(current);
    }

    if(temp[0] == 'B'){
        char current[100];
        strcpy(current, temp);
        Swap(current);
        Find(current);
    }
    
}

int main(void){
    scanf("%s", S);
    scanf("%s", T);

    Find(T);
    printf("%d\n", result);
}

// void Swap(char current[]){
//     int len = strlen(current);
//     char swapStr[100];
//     for(int i=0; i<len; i++){
//         swapStr[len-1-i] = current[i];
//     }
//     swapStr[len] = '\0';
//     strcpy(current, swapStr);
// }

// void Find(char temp[]){
//     if(strlen(temp) == strlen(T)){
//         if(strcmp(temp, T) == 0){
//             result = 1;
//             return;
//         }
//         else return;
//     }

//     for(int i=0; i<2; i++){
//         char current[100];
//         strcpy(current, temp);
//         if(i==0){
//             strcat(current, addA);
//             Find(current);
//         }
//         else{
//             strcat(current, addB);
//             Swap(current);
//             Find(current);
//         }
//     }
    
// }

// int main(void){
//     scanf("%s", S);
//     scanf("%s", T);

//     Find(S);
//     printf("%d\n", result);
// }