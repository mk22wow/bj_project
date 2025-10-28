#include <stdio.h>
#include <stdlib.h>

/*typedef struct {
    int left_right;
    int movement;
}Cow;

void init_list(Cow** list){
    *list = (Cow*)malloc(sizeof(Cow));
    (*list)->left_right = -1;
    (*list)->movement = 0;
}

void print_movement(Cow** list){
    int min_move = 0;
    for(int i=0; i<10; i++){
        min_move += list[i]->movement;
    }
    printf("%d\n", min_move);
}

void free_list(Cow** list){
    for(int i=0; i<10; i++){
        free(list[i]);
    }
    free(list);
}

int main(void){
    Cow** list = (Cow**)malloc(10*sizeof(Cow*));
    if(list == NULL){
        printf("Cow is NULL");
        return 0;
    }
    
    for(int i=0; i<10; i++){
        init_list(&list[i]);
    }

    int i = 0, times = 0;
    scanf("%d", &times);
    while(i<times){
        int num1 = 0, num2 = 0;
        scanf("%d %d", &num1, &num2);
        if(list[num1]->left_right != -1 && list[num1]->left_right != num2){
            list[num1]->movement++;
        }
        list[num1]->left_right = num2;
        i++;
    }

    print_movement(list);

    free_list(list);
}*/


int main(void){
    int* list = (int*)malloc(10*sizeof(int));
    if(list == NULL){
        printf("Cow is NULL");
        return 0;
    }
    
    for(int i=0; i<10; i++){
        list[i] = -1;
    }
    
    int min_move = 0;
    int i = 0, times = 0;
    scanf("%d", &times);
    while(i<times){
        int num1 = 0, num2 = 0;
        scanf("%d %d", &num1, &num2);
        if(list[num1] != -1 && list[num1] != num2){
            min_move++;
        }
        list[num1] = num2;
        i++;
    }

    printf("%d\n", min_move);

    free(list);
}