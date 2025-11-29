#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int check_str(char str[]){
    int i=0, index_s=0, index_e=0;
    if(str[0] == ' ' || str[strlen(str)-1] == ' ' || strlen(str)>100000){
        return 0;
    }
    while(str[i]!='\0'){
        if(str[i] == '<'){
            index_s = i;
            i++;
            while(str[i] != '>' && str[i] != '\0'){
                if(str[i]== '<'){
                    return 0;
                }
                i++;
            }
            index_e = i;
            if(index_e-index_s<2 || str[index_e] == '\0'){
                return 0;
            }
            if(str[index_e+1] == ' '){
                return 0;
            }
            i++;
            continue;
        }
        i++;
    }
    i=0;
    while(str[i]!='\0'){
        if(!isdigit(str[i]) && !isalpha(str[i])){
            if(str[i] != ' ' && str[i] != '<' && str[i] != '>'){
                return 0;
            }
        }
        i++;
    }
    return 1;
}

void print_reverse(char str[]){
    int i = 0, index_s = 0, index_e = 0;
     while(str[i]!='\0'){
        if(str[i] == '<'){
            index_s = i;
            while(str[i] != '>'){
                i++;
            }
            index_e = i;
            for(index_s; index_s<=index_e; index_s++){
                printf("%c", str[index_s]);
            }
            i++;
        }
        else if(str[i] == ' '){
            printf("%c", str[i]);
            i++;
        }
        else{
            index_s = i;
            while(str[i]!=' ' && str[i] != '<' && str[i] != '\0'){
                i++;
            }
            index_e = i-1;
            for(index_e; index_e>=index_s; index_e--){
                printf("%c", str[index_e]);
            }
        }
    }
}

int main(void){
    char str[100001];
    if(fgets(str, 100001, stdin) == NULL){
        printf("wrong input");
        return 0;
    }
    str[strcspn(str,"\n")] = '\0';
    if(!check_str(str)){
        printf("wrong input");
        return 0;
    }
    print_reverse(str);
}
