#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int check_list(int list[], int num){
    for(int i=0; i<num; i++){
        if(list[i]<0 || list[i]>num-(i+1)){
            return 1;
        }
    }
    return 0;
}

void check_result(int list[], int result[], int num){
    int* temp = (int*)malloc(num*sizeof(int));
    for(int i=0; i<num; i++){
        temp[i] = 0;
    }

    for(int i=0; i<num; i++){
        int count = list[i];
        int index = 0;
        for(int j=0; j<num; j++){
            if(temp[j]!=0){
                continue;
            }
            else{
                index++;
                if(index == count+1){
                    temp[j] = 1;
                    index = j;
                    break;
                }
            }
        }
        result[index] = i+1;
    }
    free(temp);
}

int main(void){
    int num = 0;
    char input[999];
    scanf("%d", &num);
    while(getchar()!='\n');
    if(num<1 || num>10){
        printf("wrong input");
        return 0;
    }
    fgets(input, 30, stdin);
    input[strcspn(input,"\n")] = '\0';
    int* list = (int*)malloc(num*sizeof(int));
    int* result = (int*)malloc(num*sizeof(int));
    int i = 0;
    char* token = strtok(input, " ");
    while(token != NULL){
        list[i] = atoi(token);
        token = strtok(NULL, " ");
        i++;
    }
    if(check_list(list, num)){
        printf("wrong input");
        return 0;
    }
    check_result(list, result, num);

    for(int i=0; i<num; i++){
        printf("%d ", result[i]);
    }

    free(list);
    free(result);
}