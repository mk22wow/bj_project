#include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

#define MAX 1000000

int T, K;
int heapsize;
long long list[MAX];

// int Compare(const void* a, const void* b){
//     long long pa = *(long long*)a;
//     long long pb = *(long long*)b;
//     if(pa<pb) return -1;
//     if(pa>pb) return 1;
//     return 0;
// }

long long pop(){
    long long answer = list[0];
    heapsize--;
    list[0] = list[heapsize];
    int parentindex = 0;
    int leftindex = 1;
    int rightindex = 2;
    while(1){
        int selectchild = 0;
        if(leftindex>=heapsize){
            break;
        }
        if(rightindex>=heapsize){
            selectchild = leftindex;
        }
        else{
            if(list[leftindex]<list[rightindex]){
                selectchild = leftindex;
            }
            else selectchild = rightindex;
        }

        if(list[parentindex]>list[selectchild]){
            long long temp = list[parentindex];
            list[parentindex] = list[selectchild];
            list[selectchild] = temp;
            parentindex = selectchild;
            leftindex = selectchild*2 + 1;
            rightindex = leftindex + 1;
        }
        else break;
    }
    return answer;
}

void push(long long num){
    int currentindex = heapsize;
    int parentindex = (currentindex-1)/2;
    list[currentindex] = num;
    while(currentindex>0 && list[currentindex]<list[parentindex]){
        list[currentindex] = list[parentindex];
        list[parentindex] = num;
        currentindex = parentindex;
        parentindex = (currentindex-1)/2;
    }
    heapsize++;
}

int main(void){
    int N=0;
    scanf("%d", &T);
    while(N<T){
        N++;
        long long result = 0;
        scanf("%d", &K);
        heapsize = 0;
        for(int i=0; i<K; i++){
            long long temp;
            scanf("%lld", &temp);
            push(temp);
        }
        //qsort(list, K, sizeof(long long), Compare);
        while(heapsize!=1){
            long long temp = pop() + pop();
            result += temp;
            push(temp);
        }
        printf("%lld\n", result);
    }
    return 0;
}