#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct Node {
	int index;
	char* name;
	struct Node* next;
}Node;

typedef struct HashTable {
	int tablesize;
	char** index_list;
	Node** name_list;
}HashTable;

unsigned long create_hash(char* name, int tablesize){
	int i=0;
	unsigned long HashValue = 0;
	for(i=0; name[i]!='\0'; i++){
		HashValue += name[i];
	}
	return HashValue % tablesize;
}

HashTable* createHashTable(int tablesize){
	HashTable* HT = (HashTable*)malloc(sizeof(HashTable));
	if(HT == NULL){
		return NULL;
	}
	HT->index_list = (char**)calloc(tablesize, sizeof(char*));
	if(HT->index_list == NULL){
		free(HT);
		return NULL;
	}
	HT->name_list = (Node**)calloc(tablesize, sizeof(Node*));
	HT->tablesize = tablesize;
	if(HT->name_list == NULL){
		free(HT->index_list);
		free(HT);
		return NULL;
	}	
	return HT;
}

Node* createNode(int index, char* name){
	Node* newNode = (Node*)malloc(sizeof(Node));
	if(newNode == NULL){
		return NULL;
	}
	newNode->index = index;
	newNode->name = (char*)malloc(strlen(name)+1);
	if(newNode->name == NULL){
		free(newNode);
		return NULL;
	}
	strcpy(newNode->name, name);
	newNode->next = NULL;
	return newNode;
}

void insertHash(HashTable* HT, int index, char* name){
	unsigned int hashvalue = create_hash(name, HT->tablesize);
	Node** head = &HT->name_list[hashvalue];
	Node* temp = *head;
	while(temp != NULL){
		if(strcmp(name, temp->name) == 0){
			return;
		}
		temp = temp->next;
	}
	Node* newNode = createNode(index, name);
	if(newNode == NULL){
		return;
	}
	newNode->next = *head;
	*head = newNode;

	HT->index_list[index] = (char*)malloc(strlen(name)+1);
	if(HT->index_list[index] == NULL){
		// for(int i=0; i<index; i++){
		// 	free(HT->index_list[i]);
		// 	Node* temp = HT->name_list[i];
		// 	Node* next = NULL;
		// 	while(temp!= NULL){
		// 		next = temp->next;
		// 		free(temp->name);
		// 		free(temp);
		// 		temp = next;
		// 	}
		// 	free(HT->name_list[i]);
		// }
		return;
	}
	strcpy(HT->index_list[index], name);
}

void findHash(HashTable* HT, char* input){
	int digit = 0;
	for(int i=0; i<strlen(input); i++){
		if(!isdigit(input[i])){
			digit = 1;
			break;
		}
	}
	
	if(digit == 0){
		int find_index = atoi(input);
		printf("%s\n", HT->index_list[find_index-1]);
	}
	else{
		int HashValue = create_hash(input, HT->tablesize);
		Node* temp = HT->name_list[HashValue];
		while(temp != NULL){
			if(strcmp(temp->name, input) == 0){
				break;
			}
			temp = temp->next;
		}
		if(temp!=NULL){
			printf("%d\n", temp->index+1);
		}
	}
}

void freeHashTable(HashTable* HT){
	for(int i=0; i<HT->tablesize; i++){
		free(HT->index_list[i]);
		Node* temp = HT->name_list[i];
		Node* next = NULL;
		while(temp!= NULL){
			next = temp->next;
			free(temp->name);
			free(temp);
			temp = next;
		}
		//free(HT->name_list[i]);
	}
	free(HT->name_list);
	free(HT->index_list);
	free(HT);
}

int main(void) {
	int num1, num2, i=0;
	scanf("%d %d", &num1, &num2);
	HashTable* HT = createHashTable(num1);
	while(i<num1){
		char name[22];
		scanf("%s", name);
		if(strlen(name) < 2 || strlen(name)>20){
			printf("wrong input");
			continue;
		}
		insertHash(HT, i, name);
		i++;
	}
	i=0;
	while(i<num2){
		char input[22];
		scanf("%s", input);
		findHash(HT, input);
		i++;
	}

	freeHashTable(HT);
	return 0;
}