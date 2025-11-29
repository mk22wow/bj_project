#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_DATE 365

typedef struct Node {
	int s;
	int e;
	int length;
	struct Node* left;
	struct Node* right;
}Node;

Node* createNode(int s, int e) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (newNode == NULL) {
		return NULL;
	}
	newNode->s = s;
	newNode->e = e;
	newNode->length = e - s;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

Node* insertNode(Node* root, int s, int e) {
	if (root == NULL) {
		return createNode(s, e);
	}
	if (root->s < s) {
		root->right = insertNode(root->right, s, e);
	}
	else if (root->s > s) {
		root->left = insertNode(root->left, s, e);
	}
	else {
		if (root->length > (e - s)) {
			root->right = insertNode(root->right, s, e);
		}
		else {
			root->left = insertNode(root->left, s, e);
		}
	}
	return root;
}

void tree_traversal(Node* root, int list[]) {
	if (root != NULL) {
		tree_traversal(root->left, list);
		for (int i = root->s - 1; i < root->e; i++) {
			list[i]++;
		}
		tree_traversal(root->right, list);
	}
}

void freeTree(Node* root) {
	if (root!=NULL) {
		freeTree(root->left);
		freeTree(root->right);
		free(root);
	}
}


void print_list(int list[]) {
	int result = 0;
	int index_l = 0, index_r = 0, height = 0;
	while(1){
		height = 0;
		while (index_l < MAX_DATE && list[index_l] == 0) {
			index_l++;
		}
		if (index_l != MAX_DATE) {
			height = list[index_l];
		}
		index_r = index_l;
		while (index_r < MAX_DATE && list[index_r] != 0) {
			if (list[index_r] > height) {
				height = list[index_r];
			}
			index_r++;
		}
		result += (index_r - index_l) * height;
		//printf("%d %d %d\n", index_r, index_l, height);
		index_l = index_r;
		if (index_l == MAX_DATE) {
			break;
		}
	}

	/*while (1) {
		while (list[index_l] == 0) {
			index_l++;
			if (index_l == MAX_DATE) {
				break;
			}
		}
		index_r = index_l;

		while (list[index_r] != 0) {
			index_r++;
			if (index_r == MAX_DATE) {
				break;
			}
		}

		result += (index_r - index_l) * height;
		index_l = index_r;
		if (index_l == MAX_DATE) {
			break;
		}
	}*/


	printf("%d\n", result);
}

int main(void) {
	int num = 0;
	scanf("%d", &num);
	Node* root = NULL;
	int list[MAX_DATE] = { 0 };
	for (int i = 0; i < num; i++) {
		int s, e;
		scanf("%d %d", &s, &e);
		root = insertNode(root, s, e);
	}
	tree_traversal(root, list);
	/*for (int i = 0; i < MAX_DATE; i++) {
		printf("%d ", list[i]);
	}*/

	print_list(list);
	freeTree(root);
	return 0;
}