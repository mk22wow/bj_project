#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
    int l;
    int r;
}Index;

char str[202];
Index list[10];
int list_index;

int remove_pair[10];
char answer[1024][202];
int answer_count = 0;

int Compare(const void* a, const void* b){
    return strcmp((char*)a, (char*)b);
}

void Find(int d){
    if(d == list_index){
        int remove_index[202] = {0};
        for(int i=0; i<list_index; i++){
            if(remove_pair[i]){
                remove_index[list[i].l] = 1;
                remove_index[list[i].r] = 1;
            }
        }

        char temp[202];
        int idx = 0;
        for(int i=0; str[i]; i++){
            if(!remove_index[i]){
                temp[idx++] = str[i];
            }
        }
        temp[idx] = '\0';
        printf("d : %s\n", temp);
        if(strcmp(temp, str) == 0){
            return;
        }
        for(int i=0; i<answer_count; i++){
            if(strcmp(temp, answer[i]) == 0){
                return;
            }
        }
        strcpy(answer[answer_count++], temp);
        return ;
    }
    remove_pair[d] = 1;
    Find(d+1);

    remove_pair[d] = 0;
    Find(d+1);
}

int main(void){
    scanf("%s", str);
    int position[20], position_index = 0;
    for(int i=0; str[i]; i++){
        if(str[i] == '('){
            position[position_index++] = i;
            continue;
        }
        if(str[i] == ')'){
            list[list_index++] = (Index){position[--position_index], i}; 
        }
    }

    Find(0);
    qsort(answer, answer_count, sizeof(answer[0]), Compare);   
    
    for(int i=0; i<answer_count; i++){
        printf("%s\n", answer[i]);
    }
    return 0;
}