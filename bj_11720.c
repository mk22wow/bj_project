#include <stdio.h>
#include <string.h>
#include <ctype.h>

int numeric_string(char* str){
    while(*str != '\0'){
        if(!isdigit((unsigned char)*str)){
            return 0;
        }
        str++;
    }
    return 1;
}


int main(void){
    int size, total = 0;
    char num[101];
    scanf("%d", &size);
    // while(getchar() != '\n');
    // fgets(num, sizeof(num), stdin);
    // num[strcspn(num, "\n")] = '\0';
    scanf("%100s", num);
    if(strlen(num) != size || !numeric_string(num)){
        printf("wrong input");
        return 0;
    }
    char* ptr = num;
    while(*ptr != '\0'){
        total += (*ptr - '0');
        //printf("%d\n", total);
        ptr++;
    }
    printf("%d\n", total);

}