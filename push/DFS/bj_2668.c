#include <stdio.h>
#include <stdlib.h>

enum VisitMode {Visited = 1, NotVisited = 0};

typedef struct{
    int Up;
    int Down;
    int Visited;
}Node;

int Find(Node list[], int num, int target){
    Node temp = list[target-1];
    while(1){
        if(temp.Down == num){
            return num;
        }
        if(temp.Visited == Visited){
            break;
        }
        temp.Visited = Visited;
        list[temp.Up-1] = temp;
        temp = list[temp.Down-1];
    }
    return 0;
}

void Reset(Node list[], int N){
    for(int i=0; i<N; i++){
        list[i].Visited = NotVisited;
    }
}

int main(void){
    int N;
    scanf("%d", &N);
    Node list[N];
    for(int i=0; i<N; i++){
        int temp;
        scanf("%d", &temp);
        list[i] = (Node){i+1, temp, NotVisited};
    }
    
    int count = 0;
    int result[N];
    for(int i=0; i<N; i++){
        Node temp = list[i];
        int num = temp.Up;
        int target = temp.Down;
        int Value = Find(list, num, target);
        if(Value != 0){
            result[count++] = Value;
        }
        Reset(list, N);
    }

    printf("%d\n", count);
    for(int i=0; i<count; i++){
        printf("%d\n", result[i]);
    }

    return 0;
}

/*int Find(int list[], int Up, int N){
    int temp = Up;

    for(int i=0; i<N; i++){
        temp = list[temp]-1;
        if(temp == Up){
            return 1;
        }
    }
    return 0;
}

int main(void){
    int N;
    scanf("%d", &N);
    int list[N];
    for(int i=0; i<N; i++){
        scanf("%d", &list[i]);
    }

    int result[N];
    int count = 0;
    for(int i=0; i<N; i++){
        if(Find(list, i, N)){
            result[count++] = i+1;
        }
    }

    printf("%d\n", count);
    for(int i=0; i<count; i++){
        printf("%d\n", result[i]);
    }

    return 0;
}*/