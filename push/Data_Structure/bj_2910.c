#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct Node{
    int data;
    int count;
    int first_index;
}Node;

int compare(const void *a, const void *b){
    const Node* pa = (const Node*)a;
    const Node* pb = (const Node*)b;
    if(pa->count != pb->count){
        return pa->count - pb->count;    
    }
    return pb->first_index - pa->first_index;
}

Node createNode(){
    Node newNode;
    newNode.data = 0;
    newNode.count = 0;
    newNode.first_index = -1;
    return newNode;
}

void printNode(Node* list, int num1){
    int i=num1-1;
    while(list[i].count!=0 && i>=0){
        for(int j=0; j<list[i].count; j++){
            printf("%d ", list[i].data);
        }
        i--;
    }
}

int Find_index(Node* list, int input, int num1){
    int index = input%num1;
    while(index<num1){
        if(list[index].data == input || list[index].data == 0){
            return index;
        }
        index++;
        index %= num1;
    }
    return index;
}

int main(void){
    int num1, num2;
    scanf("%d %d", &num1, &num2);
    if(num1<1 || num1>1000 || num2<0|| num2>1000000000){
        printf("wrong input");
        return 0;
    }

    Node* list = (Node*)malloc(sizeof(Node)*num1);
    for(int i=0; i<num1; i++){
        list[i] = createNode();
    }
   for(int i=0; i<num1; i++){
        int input;
        scanf("%d", &input);
        if(input>num2 || input<1){
            printf("wrong input");
            break;
        }
        int index = Find_index(list, input, num1);
        if(list[index].first_index == -1){
            list[index].data = input;
            list[index].first_index = i;
        }
        list[index].count++;
    }
    qsort(list, num1, sizeof(Node), compare);

    printNode(list, num1);

    free(list);

    return 0;
}