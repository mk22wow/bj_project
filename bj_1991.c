#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node {
	char C;
	struct Node* Left;
	struct Node* Right;
}Node;

Node* createNode(char C) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->C = C;
	newNode->Left = NULL;
	newNode->Right = NULL;
	return newNode;
}

void insertNode(Node* root, char* list, int root_index, int num) {
	if (list[root_index * 3 + 1] != '.') {
		for (int i = 0; i < num; i++) {
			if (list[root_index * 3 + 1] == list[i * 3]) {
				Node* temp = createNode(list[i * 3]);
				root->Left = temp;
				insertNode(temp, list, i, num);
			}
		}
	}
	if (list[root_index * 3 + 2] != '.') {
		for (int i = 0; i < num; i++) {
			if (list[root_index * 3 + 2] == list[i * 3]) {
				Node* temp = createNode(list[i * 3]);
				root->Right = temp;
				insertNode(temp, list, i, num);
			}
		}
	}
}

void TreeTraversal(Node* root, int input) {
	switch (input) {
		case 1:
			if (root != NULL) {
				printf("%c", root->C);
				TreeTraversal(root->Left, 1);
				TreeTraversal(root->Right, 1);
			}
			break;
		case 2:
			if (root != NULL) {
				TreeTraversal(root->Left, 2);
				printf("%c", root->C);
				TreeTraversal(root->Right, 2);
			}
			break;
		case 3:
			if (root != NULL) {
				TreeTraversal(root->Left, 3);
				TreeTraversal(root->Right, 3);
				printf("%c", root->C);
			}
			break;
	}
}

freeTree(Node* root) {
	if (root != NULL) {
		freeTree(root->Left);
		freeTree(root->Right);
		free(root);
	}
}

int main(void) {
	int num = 0;
	scanf("%d", &num);
	char* list = (char*)malloc(num*3);
	int root_index = 0;
	for (int i = 0; i < num; i++) {
		scanf(" %c %c %c", &list[i * 3], &list[i * 3 + 1], &list[i * 3 + 2]);
		if (&list[i * 3] == 'A') {
			root_index = i;
		}
	}

	Node* root = createNode(list[root_index * 3]);
	int i = 0;
	insertNode(root, list, root_index, num);
	TreeTraversal(root, 1);
	printf("\n");
	TreeTraversal(root, 2);
	printf("\n");
	TreeTraversal(root, 3);
	printf("\n");
	
	freeTree(root);
	free(list);
	return 0;
}