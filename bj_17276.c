#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

void print_list(int** list);

int** make_list(int num){
    int** list = (int**)malloc(num*sizeof(int*));
    if(list == NULL){
        return NULL;
    }
    int n = 1;
    for(int i=0; i<num; i++){
        list[i] = (int*)malloc(num*sizeof(int));
        if(list[i] == NULL){
            for(int j=0; j<i; j++){
                free(list[j]);
            }
            free(list);
            return NULL;
        }
        for(int j=0; j<num; j++){
            list[i][j] = n++;
        }
    }
    return list;
}

void free_list(int** list, int num){
    for(int i=0; i<num; i++){
        free(list[i]);
    }
    free(list);
}

void copy_list(int** result, int** temp, int num){
    for(int i=0; i<num; i++){
        for(int j=0; j<num; j++){
            result[i][j] = temp[i][j];
        }
    }
    
}

int** rotate_list(int num, int input_deg){
    int** result = make_list(num);
    //print_list(result, num);
    if(result == NULL){
        return NULL;
    }
    if(input_deg == 0 || abs(input_deg) == 360){
        return result;
    }
    int row, col;
    int center = (num-1)/2;
    if(input_deg<0){
        while(input_deg != 0){
            int** temp = make_list(num);
            if(temp == NULL){
                return NULL;
            }
            row = 0, col = 0;
            for(int j=0; j<num; j++){
                temp[center][j] = result[row++][col++];
            }
            row = num-1, col = 0;
            for(int j=0; j<num; j++){
                temp[row--][col++] = result[center][j];
            }
            row = 0, col = num-1;
            for(int j=0; j<num; j++){
                temp[j][center] = result[row++][col--];
            }
            row = 0, col = 0;
            for(int j=0; j<num; j++){
                temp[row++][col++] = result[j][center];
            }
            copy_list(result, temp, num);
            free_list(temp, num);
            input_deg+=45;
        }
    }
    else{
        while(input_deg != 0){
            int** temp = make_list(num);
            row = 0, col = 0;
            for(int j=0; j<num; j++){
                temp[j][center] = result[row++][col++];
            }
            row = 0, col = 0;
            for(int j=0; j<num; j++){
                temp[row++][col++] = result[center][j];
            }
            row = num-1, col = 0;
            for(int j=0; j<num; j++){
                temp[center][j] = result[row--][col++];
            }
            row = 0, col = num-1;
            for(int j=0; j<num; j++){
                temp[row++][col--] = result[j][center];
            }
            copy_list(result, temp, num);
            free_list(temp, num);
            input_deg-=45;
        }
    }
    return result;
}

void print_list(int** list){
    int num = sizeof(list[0])/sizeof(list[0][0]);
    printf("%d\n", num);
    for(int i=0; i<num; i++){
        for(int j=0; j<num; j++){
            printf("%d ", list[i][j]);
        }
        printf("\n");
    }
}

void print_list1(int** list, int num){
    for(int i=0; i<num; i++){
        for(int j=0; j<num; j++){
            printf("%d ", list[i][j]);
        }
        printf("\n");
    }
}

typedef struct Node{
    int** list;
    int num;
    struct Node* next;
}Node;

Node* createNode(int** list, int num){
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL){
        return NULL;
    }
    newNode->num = num;
    newNode->list = make_list(num);
    copy_list(newNode->list, list, num);
    //printf("%d %d", sizeof(list[0]), sizeof(list[0][0]));
    //print_list(list);
    newNode->next = NULL;
    return newNode;
}

void printNode(Node* node){
    Node* temp = node;
    while(temp!=NULL){
        print_list1(temp->list, temp->num);
        temp = temp->next;
    }
}

int main(void){
    int i = 0, times = 0;
    scanf("%d",&times);
    if(times<1 || times>10){
        printf("wrong input");
        return 0;
    }
    Node* result = NULL;
    while(i<times){
        int num = 0, deg = 0;
        scanf("%d %d", &num, &deg);
        if(num<1 || num>500 || num%2 == 0){
            printf("wrong input");
            return 0;
        }
        if(deg<-360 || deg>360 || deg%45 != 0){
            printf("wrong input");
            return 0;
        }
        int** list = rotate_list(num, deg);
        if(list != NULL){
            //print_list1(list, num);
            // free_list(list, num);
            Node* node = createNode(list, num);
            //printNode(node);
            if(result == NULL){
                result = node;
            }
            else{
                Node* temp = result;
                while(temp->next != NULL){
                    temp = temp->next;
                }
                temp->next = node;
            }
        }
        i++;
    }   
    printNode(result);
}

