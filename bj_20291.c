#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node{
    char* extension;
    int count;
    struct Node* left;
    struct Node* right;
}Node;

Node* createNode(char str[]){
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL){
        return NULL;
    } 

    newNode->extension = (char*)malloc(strlen(str)+1);
    if(newNode->extension == NULL){
        free(newNode);
        return NULL;
    }
    strcpy(newNode->extension, str);
    //printf("createNode: %s\n", newNode->extension);
    newNode->count = 1;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insertNode(Node* root, char extension[]){
    //printf("%s\n",extension);
    if(root == NULL){
        return createNode(extension);
    }
    
    int cmp = strcmp(root->extension, extension);

    if(cmp == 0){
        root->count++;
    }
    else if(cmp<0){
        root->right = insertNode(root->right, extension);
    }
    else{
        root->left = insertNode(root->left, extension);
    }
    return root;
}

void printTree(Node* root){
    //printf("it's printTree");
    if(root!=NULL){
        printTree(root->left);
        printf("%s %d\n",root->extension, root->count);
        printTree(root->right);
    }
}

void freeTree(Node* root){
    if(root!=NULL){
        freeTree(root->left);
        freeTree(root->right);
        free(root->extension);
        free(root);
    }
}

int checkStr(char str[]){
    int i=0, len = strlen(str);
    int check = 0;
    if(len<3 || len>100){
        return 0;
    }
    // for(i=0; i<len; i++){
    //     if(str[i]=='.'){
    //         check++;
    //     }
    // }
    // if(check != 1){
    //     return 0;
    // }
    // if(str[0] == '.' || str[len-1] == '.'){
    //     return 0;
    // }
    char* first_dot = strchr(str, '.');
    char* last_dot = strrchr(str, '.');
    if(first_dot == NULL || first_dot == str || first_dot ==str+len-1){
        return 0;
    }
    if(first_dot != last_dot){
        return 0;
    }
    return 1;
}

int main(void){
    int num = 0;
    char str[255];
    char extension[255];
    Node* root = NULL;
    scanf("%d", &num);
    for(int i=0; i<num; i++){
        scanf("%s", str);
        if(checkStr(str)){
           //printf("insert\n");
           int index = strcspn(str, ".");
            root = insertNode(root, str+index+1);
        }
    }
    printTree(root);
    freeTree(root);
}