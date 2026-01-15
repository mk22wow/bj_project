#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int N, M, idx = 0;
int value[100001] = {0};

typedef struct{
    int num;
    int level;
}Quiz;

Quiz Max_Heap[111111];
Quiz Min_Heap[111111];
int max_size = 0;
int min_size = 0;

void pushMax(Quiz q){
    int i = max_size;
    Max_Heap[max_size++] = q;
    while(i>0){
        int parent_i = (i-1)/2;
        if(Max_Heap[parent_i].level<Max_Heap[i].level || (Max_Heap[parent_i].level==Max_Heap[i].level && Max_Heap[parent_i].num<Max_Heap[i].num)){
            Quiz temp = Max_Heap[parent_i];
            Max_Heap[parent_i] = Max_Heap[i];
            Max_Heap[i] = temp;
            i = parent_i;
        }
        else break;
    }
}

void popMax(){
    Max_Heap[0] = Max_Heap[--max_size];
    int parentindex = 0;
    int leftchild = parentindex*2+1;
    int rightchild = leftchild+1;
    while(1){
        int selectchild;
        if(leftchild>=max_size) break;
        if(rightchild>=max_size) selectchild = leftchild;
        else{
            if(Max_Heap[leftchild].level>Max_Heap[rightchild].level || (Max_Heap[rightchild].level==Max_Heap[leftchild].level && Max_Heap[leftchild].num>Max_Heap[rightchild].num)){
                selectchild = leftchild;        
            }
            else selectchild = rightchild;
        }

        if(Max_Heap[selectchild].level>Max_Heap[parentindex].level || (Max_Heap[selectchild].level==Max_Heap[parentindex].level && Max_Heap[selectchild].num>Max_Heap[parentindex].num)){
            Quiz temp = Max_Heap[parentindex];
            Max_Heap[parentindex] = Max_Heap[selectchild];
            Max_Heap[selectchild] = temp;
            parentindex = selectchild;
            leftchild = parentindex*2 + 1;
            rightchild = leftchild+1;
        }
        else break;
    }
}

void pushMin(Quiz q){
    int i = min_size;
    Min_Heap[min_size++] = q;
    while(i>0){
        int parent_i = (i-1)/2;
        if(Min_Heap[parent_i].level>Min_Heap[i].level || (Min_Heap[parent_i].level==Min_Heap[i].level && Min_Heap[parent_i].num>Min_Heap[i].num)){
            Quiz temp = Min_Heap[parent_i];
            Min_Heap[parent_i] = Min_Heap[i];
            Min_Heap[i] = temp;
            i = parent_i;
        }
        else break;
    }
}

void popMin(){
    Min_Heap[0] = Min_Heap[--min_size];
    int parentindex = 0;
    int leftchild = parentindex*2+1;
    int rightchild = leftchild+1;
    while(1){
        int selectchild;
        if(leftchild>=min_size) break;
        if(rightchild>=min_size) selectchild = leftchild;
        else{
            if(Min_Heap[leftchild].level<Min_Heap[rightchild].level || (Min_Heap[rightchild].level==Min_Heap[leftchild].level && Min_Heap[leftchild].num<Min_Heap[rightchild].num)){
                selectchild = leftchild;        
            }
            else selectchild = rightchild;
        }

        if(Min_Heap[selectchild].level<Min_Heap[parentindex].level || (Min_Heap[selectchild].level==Min_Heap[parentindex].level && Min_Heap[selectchild].num<Min_Heap[parentindex].num)){
            Quiz temp = Min_Heap[parentindex];
            Min_Heap[parentindex] = Min_Heap[selectchild];
            Min_Heap[selectchild] = temp;
            parentindex = selectchild;
            leftchild = parentindex*2 + 1;
            rightchild = leftchild+1;
        }
        else break;
    }
}

void Add(int a, int b){
    value[a] = b;
    pushMax((Quiz){a,b});
    pushMin((Quiz){a,b});
}

void Solved(int a){
    value[a] = 0;
}

void Recommend(int a){
    if(a == 1){
        while(1){
            Quiz temp = Max_Heap[0];
            if(temp.level != value[temp.num]){
                popMax();
            }
            else{
                printf("%d\n", temp.num);
                break;
            }  
        }
    }
    else{
        while(1){
            Quiz temp = Min_Heap[0];
            if(temp.level != value[temp.num]){
                popMin();
            }
            else{
                printf("%d\n", temp.num);
                break;
            }  
        }
    }
}

int main(void){
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        value[a] = b;
        pushMax((Quiz){a,b});
        pushMin((Quiz){a,b});
    }
    
    scanf("%d", &M);
    for(int i=0; i<M; i++){
        char temp[10];
        int a, b;
        scanf("%s", temp);
        if(strcmp(temp, "add") == 0){
            scanf("%d %d", &a, &b);
            Add(a, b);
        }
        else if(strcmp(temp, "solved") == 0){
            scanf("%d", &a);
            Solved(a);
        }
        else{
            scanf("%d", &a);
            Recommend(a);
        }
    }
    return 0;
}