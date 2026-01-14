#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int N, M, Q;

typedef struct File{
    char F_name[11];
    struct File* next;
}File;

typedef struct Folder{
    char P_name[11];
    int P_count, F_count;
    int P_sort, F_sort;
    File* F_table[1003];
    struct Folder* Parent;
    struct Folder* next;
}Folder;

typedef struct Pending{
    char parent[11];
    char name[11];
    int isFolder;
}Pending;

Folder* Root;
Folder* list[1003];
Pending pending[2005];
int p_count = 0;

int Get(char name[]){
    int value = 0;
    for(int i=0; name[i]; i++){
        value += name[i];
    }
    return value % 1003;
}

Folder* CreateFolder(char n[]){
    Folder* temp = (Folder*)malloc(sizeof(Folder));
    memset(temp, 0, sizeof(Folder));
    strcpy(temp->P_name, n);
    return temp;
}

File* CreateFile(char n[]){
    File* temp = (File*)malloc(sizeof(File));
    strcpy(temp->F_name, n);
    temp->next = NULL;
    return temp;
}

void InsertFolder(char a[], char b[]){
    int value = Get(a);
    Folder* parent = list[value];
    while(parent!= NULL && strcmp(parent->P_name,a)!=0) parent = parent->next;
    value = Get(b);
    Folder* child = CreateFolder(b);
    child->Parent = parent;

    Folder* temp = list[value];
    while(temp){
        if(strcmp(temp->P_name, b) == 0){
            free(child);
            return;
        }
        temp = temp->next;
    }

    child->next = list[value];
    list[value] = child;
}

void InsertFile(char a[], char b[]){
    int value = Get(a);
    Folder* parent = list[value];
    while(parent && strcmp(parent->P_name, a)!=0) parent = parent->next;
    value = Get(b);
    while(parent){
        File* child = CreateFile(b);
        File* temp = parent->F_table[value];
        int pass = 1;

        while(temp){
            if(strcmp(temp->F_name, b) == 0){
                    free(child);
                    parent->F_count++;
                    pass = 0;
                    break;
                }
            temp = temp->next;
        }
        
        if(pass){
            child->next = parent->F_table[value];
            parent->F_table[value] = child;
            parent->F_count++;
            parent->F_sort++;
        }
       
        parent = parent->Parent;
    }
}

void Find(char str[]){
    int value = Get(str);
    Folder* answer = list[value];
    while(answer && strcmp(answer->P_name,str)!=0) answer = answer->next;
    if(answer) printf("%d %d\n", answer->F_sort, answer->F_count);
}

int main(void){
    memset(list, 0, sizeof(list));

    scanf("%d %d", &N, &M);

    Root = CreateFolder("main");
    int value = Get("main");
    list[value] = Root;

    for(int i=0; i<N+M; i++){
        char a[11], b[11], c[2];
        scanf("%s %s %s", &a, &b, &c);

        int hashvalue = Get(a);
        Folder* parent = list[hashvalue];
        while(parent && strcmp(parent->P_name, a) != 0){
            parent = parent->next;
        }
        if(parent){
            if(c[0] == '1'){
                InsertFolder(a, b);
            }
            else InsertFile(a, b);
        }
        else{
            strcpy(pending[p_count].parent, a);
            strcpy(pending[p_count].name, b);
            pending[p_count].isFolder = (c[0]=='1');
            p_count++;
        }
    }
    
    int changed = 1;
    while(changed){
        changed = 0;
        for(int i=0; i<p_count; i++){
            if(pending[i].parent[0] == 0) continue;
            int hashvalue = Get(pending[i].parent);
            Folder* parent = list[hashvalue];
            while(parent && strcmp(parent->P_name, pending[i].parent)!=0){
                parent = parent->next;
            }
            if(parent){
                if(pending[i].isFolder){
                    InsertFolder(pending[i].parent, pending[i].name);
                }
                else InsertFile(pending[i].parent, pending[i].name);
                pending[i].parent[0] = 0;
                changed = 1;
            }
        }
    }

    scanf("%d", &Q);
    for(int i=0; i<Q; i++){
        char question[10003];
        scanf("%s", question);
        int len = strlen(question), index = 0;
        char str[11];
        for(int j=len-1; j>=0; j--){
            if(question[j] == '/'){
                break;
            }
            str[index++] = question[j];
        }
        for(int j=0; j<index/2; j++){
            char temp = str[j];
            str[j] = str[index-1-j];
            str[index-1-j] = temp;
        }
        str[index] = '\0';
        Find(str);
    }
    return 0;
}