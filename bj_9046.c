#include <stdio.h>
#include <string.h>
#include <ctype.h>

// void lowerCase(char* str){
//     while(*str != '\0'){
//         *str = tolower((unsigned char)*str);
//         str++;
//     }
// }

void checkTime(char* str, int* list, int size){
    char* temp_ptr = str;
    int letter = 0;
    while(*temp_ptr !='\0'){
        letter = (*temp_ptr - 'a');
        if(letter>=0 && letter<size){
            list[letter]++;
        }
        temp_ptr++;
    }
    for(int i=0; i<size; i++){
        printf("%d ",list[i]);
    }
    int* temp_list = list;
    int max_position = 0;
    int duplication = 0;
    for(int i=1; i<size; i++){
        if(temp_list[max_position] < temp_list[i]){
            max_position = i;
            duplication = 0;
        }
        else if(temp_list[max_position] == temp_list[i]){
            duplication++;
        }

    }

    if(duplication>=1){
        printf("?\n");
        return;
    }
    printf("%c\n", 'a'+ max_position);
}



int main(void){
    int time = 0;
    scanf("%d", &time);
    while(getchar() != '\n');
    if(time<1 || time>20){
        printf("wrong input1");
        return 0;
    }
    for(int i=0; i<time; i++){
        char str[257];
        int list[26] = {0};
        if(fgets(str, sizeof(str), stdin) == NULL){
            printf("wrong input2");
            return 0;
        }
        str[strcspn(str, "\n")] = '\0';
        //lowerCase(str);
        // for(int i=0; i<strlen(str); i++){
        //     printf("%c ",str[i]);
        // }
        checkTime(str, list, 26);
    }

    return 0;
}