#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int on_off;
}lightbulb;

void init_list(lightbulb** list, char condition[], int count){
    for(int i=0; i<count; i++){
        list[i] = (lightbulb*)malloc(sizeof(lightbulb));
        list[i]->on_off = condition[i*2] - '0';
    }
}

int perform(lightbulb** list, int num1, int num2, int num3, int count){
    switch(num1){
        case 1:
            if((num2 <= 0 || num2 > count) || (num3 != 0 && num3 != 1)){
                break;
            }
            list[num2-1]->on_off = num3;
            return 1;
        case 2:
            if(num2 <= 0 || num2 > count || num2>num3 || num3>count){
                break;
            }
            for(int i=num2-1; i<num3; i++){
                if(list[i]->on_off == 0){
                    list[i]->on_off = 1;
                }
                else{
                    list[i]->on_off = 0;
                }
            }
            return 1;
        case 3:
            if(num2 <= 0 || num2 > count || num2>num3 || num3>count){
                break;
            }
            for(int i=num2-1; i<num3; i++){
                list[i]->on_off = 0;
            }
            return 1;
        case 4:
            if(num2 <= 0 || num2 > count || num2>num3 || num3>count){
                break;
            }
            for(int i=num2-1; i<num3; i++){
                list[i]->on_off = 1;
            }
            return 1;
        default:
            printf("wrong order");
            return 0;  
    }
    return 0;

}

void print_movement(lightbulb** list, int count){
    for(int i=0; i<count; i++){
        printf("%d ", list[i]->on_off);
    }
    printf("\n");
}

void free_list(lightbulb** list, int count){
    for(int i=0; i<count; i++){
        free(list[i]);
    }
    free(list);
}

int main(void){
    int i = 0, count = 0, times = 0;
    char condition[8001];
    scanf("%d %d", &count, &times);
    while(getchar() != '\n');
    lightbulb** list = (lightbulb**)malloc(count*sizeof(lightbulb*));
    if(list == NULL){
        printf("list is NULL");
        return 0;
    }

    if(fgets(condition, count*2, stdin) == NULL){
        return 0;
    }
    condition[strcspn(condition, "\n")] = '\0';

    init_list(list, condition, count);

    while(i<times){
        int num1 = 0, num2 = 0, num3 = 0;
        scanf("%d %d %d", &num1, &num2, &num3);
        if(!perform(list, num1, num2, num3, count)){
            return 0;
        }
        i++;
    }

    print_movement(list, count);

    free_list(list, count);
}