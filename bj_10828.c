//#define _CRT_SECURE_NO_WARNINGS
//
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//typedef struct Node {
//	int data;
//	struct Node* next;
//}Node;
//
//typedef struct {
//	int count;
//	Node* top;
//}Stack;
//
//Node* createNode(int data) {
//	Node* newNode = (Node*)malloc(sizeof(Node));
//	if (newNode == NULL) {
//		return NULL;
//	}
//	newNode->data = data;
//	newNode->next = NULL;
//	return newNode;
//}
//
//void insertNode(Stack* s, int data) {
//	Node* newNode = createNode(data);
//	if (newNode == NULL) {
//		return;
//	}
//	newNode->next = s->top;
//	s->top = newNode;
//	s->count++;
//}
//
//void freeStack(Stack* s) {
//	while (s->top != NULL) {
//		Node* temp = s->top->next;
//		free(s->top);
//		s->top = temp;
//	}
//	free(s);
//}
//int main(void) {
//	int num, i = 0;
//	scanf("%d", &num);
//	if (num < 1 || num>10000) {
//		printf("wring input");
//		return 0;
//	}
//	Stack* list = (Stack*)malloc(sizeof(Stack));
//	list->count = 0;
//	list->top = NULL;
//
//	while (i < num) {
//		char str[10];
//		int integer;
//		scanf("%s", str);
//		if (strcmp(str, "push") == 0) {
//			scanf("%d", &integer);
//			insertNode(list, integer);
//		}
//		else if (strcmp(str, "pop") == 0 || strcmp(str, "top") == 0) {
//			if (list->top == NULL) {
//				printf("-1\n");
//			}
//			else {
//				printf("%d\n", list->top->data);
//					if (strcmp(str, "pop") == 0) {
//						Node* temp = list->top;
//						list->top = list->top->next;
//						list->count--;
//						free(temp);
//					}
//			}
//		}
//		else if (strcmp(str, "size") == 0) {
//			printf("%d\n", list->count);
//		}
//		else if (strcmp(str, "empty") == 0) {
//			if (list->count == 0) {
//				printf("1\n");
//			}
//			else {
//				printf("0\n");
//			}
//		}
//		i++;
//	}
//	freeStack(list);
//	return 0;
//}