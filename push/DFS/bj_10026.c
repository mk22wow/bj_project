#include <stdio.h>
#include <stdlib.h>

int x[4] = {0, 0, 1, -1};
int y[4] = {1, -1, 0, 0};

typedef struct{
    int y;
    int x;
}Node;

void Find(int N, char** list, int i, int j, char temp){
    list[i][j] = 'V';
    for(int k=0; k<4; k++){
        int temp_x = j+x[k];
        int temp_y = i+y[k];
        
        if(temp_x>=0 && temp_x<N && temp_y>=0 && temp_y<N){
            if(list[temp_y][temp_x]==temp){
                Find(N, list, temp_y, temp_x, temp);
            }
        }
    }
}

void DFS(int N, char** list, int i, int j, char temp){
    Node* Stack = (Node*)malloc(sizeof(Node)*N*N);
    int top = -1;

    Stack[++top] = (Node){i,j};

    while(top>=0){
        Node current = Stack[top--];
        int current_y = current.y;
        int current_x = current.x;

        if(list[current_y][current_x] == 'V'){
            continue;
        }
        list[current_y][current_x] = 'V';

        for(int k=0; k<4; k++){
            int temp_y = current_y + y[k];
            int temp_x = current_x + x[k];
            if(temp_x>=0 && temp_x<N && temp_y>=0 && temp_y<N){
                if(list[temp_y][temp_x]==temp){
                    Stack[++top] = (Node){temp_y, temp_x};
                }
            }
        }
    }
    free(Stack);
}

int main(void){
    int N;
    scanf("%d", &N);
    char** list = (char**)malloc(sizeof(char*)*N);
    char** str = (char**)malloc(sizeof(char*)*N);
    for(int i=0; i<N; i++){
        list[i] = (char*)malloc(sizeof(char)*N);
        str[i] = (char*)malloc(sizeof(char)*N);
        for(int j=0; j<N; j++){
            scanf(" %c", &list[i][j]);
            if(list[i][j]=='G'){
                str[i][j] = 'R';
            }else{
                str[i][j] = list[i][j];
            }
        }
    }

    int num1 = 0, num2 = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(list[i][j]!='V'){
                char temp = list[i][j];
                num1++;
                DFS(N, list, i, j, temp);
            }
            if(str[i][j]!='V'){
                char temp = str[i][j];
                num2++;
                DFS(N, str, i, j, temp);
            }
        }
    }

    for(int i=0; i<N; i++){
        free(list[i]);
        free(str[i]);
    }
    free(str);
    free(list);

    printf("%d %d\n", num1, num2);
    return 0;
}