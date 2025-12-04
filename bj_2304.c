#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Node {
    int L;
    int H;
}Node;

int Compare_L(const void* a, const void* b) {
    const Node** pa_ptr = (const Node**)a;
    const Node** pb_ptr = (const Node**)b;

    const Node* pa = *pa_ptr;
    const Node* pb = *pb_ptr;
    return pa->L - pb->L;
}

int Compare_H(const void* a, const void* b) {
    const Node** pa_ptr = (const Node**)a;
    const Node** pb_ptr = (const Node**)b;

    const Node* pa = *pa_ptr;
    const Node* pb = *pb_ptr;
    if (pa->H == pb->H) {
        return pb->L - pa->L;
    }
    return pb->H - pa->H;
}

Node* createNode(int L, int H) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->L = L;
    newNode->H = H;
    return newNode;
}

void freeNode(Node** list, int num) {
    for (int i = 0; i < num; i++) {
        free(list[i]);
    }
    free(list);
}

int countArea(Node** list, int Max_Index, int Max_H, int num) {
    int i = 0, result = 0;
    result += Max_H;
    while (list[i]->L < Max_Index) {
        int temp = i;
        for (int j = temp; list[j]->L <= Max_Index; ++j) {
            if (temp != j && list[temp]->H <= list[j]->H) {
                result += (list[j]->L - list[temp]->L) * list[temp]->H;
                i = j;
                break;
            }
        }
    }
    i = num-1;
    while (list[i]->L > Max_Index) {
        int temp = i;
        for (int j = temp; list[j]->L >= Max_Index; --j) {
            if (temp != j && list[temp]->H <= list[j]->H) {
                result += (list[temp]->L - list[j]->L) * list[temp]->H;
                i = j;
                break;
            }
        }
    }
    printf("%d\n", result);
}

int main(void) {
    int num, i = 0;
    scanf("%d", &num);
    Node** list = (Node**)malloc(sizeof(Node*) * num);
    while (i < num) {
        int num1, num2;
        scanf("%d %d", &num1, &num2);
        Node* newNode = createNode(num1, num2);
        list[i] = newNode;
        i++;
    }

    qsort(list, num, sizeof(Node*), Compare_H);
    int Max_Index = list[0]->L;
    int Max_H = list[0]->H;
    //printf("%d\n", Max_Index);
    qsort(list, num, sizeof(Node*), Compare_L);

    countArea(list, Max_Index, Max_H, num);
    freeNode(list, num);
}

// int countArea(Node** list, int num){
//     int index = 0, i = 0, result = 0;
//     while(i<num){
//         int current_H = list[i]->H;
//         int current_L = list[i]->L;
//         int current_I = i;
//         int max = 0;
//         i++;
//         while(i<num){
//             if(list[i]->H>=current_H){
//                 result += (list[i]->L-current_L)*list[i]->H;
//                 break;
//             }
//             else{
//                 max = max > list[i]->H ? max : list[i]->H;
//             }
//             i++;
//             if(i == num){

//             }

//         }
//     }
// }
