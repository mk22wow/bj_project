#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int s;
    int e;
}Time;

int N;
Time list[100000];

int Compare(const void* a, const void* b){
    Time* pa = (Time*)a;
    Time* pb = (Time*)b;
    if(pa->e != pb->e){
        return pb->e - pa->e;
    }
    return pb->s - pa->s;
}

int main(void){
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        list[i] = (Time){a, b};
    }

    qsort(list, N, sizeof(Time), Compare);
    int Min_s[100000];
    int index = 0;
    for(int i=0; i<N; i++){
        int Add = 1;
        for(int j=0; j<index; j++){
            if(list[i].e<=Min_s[j]){
                Min_s[j] = list[i].s;
                Add = 0;
                break;
            }
        }
        if(Add){
            Min_s[index++] = list[i].s;
        }
    }

    printf("%d\n", index);
    return 0;
}


// int Min_e[100000];
// int UsedSize = 0;

// int Compare(const void* a, const void* b){
//     Time* pa = (Time*)a;
//     Time* pb = (Time*)b;
//     if(pa->s != pb->s){
//         return pa->s - pb->s;
//     }
//     return pa->e - pb->e;
// }

// int push(int new_e){
//     int currentindex = UsedSize;
//     int parentindex = (currentindex-1)/2;

//     Min_e[currentindex] = new_e;
//     while(currentindex>0 && Min_e[currentindex] < Min_e[parentindex]){
//         Min_e[currentindex] = Min_e[parentindex];
//         Min_e[parentindex] = new_e;
//         currentindex = parentindex;
//         parentindex = (currentindex-1)/2;
//     }
//     UsedSize++;
// }

// void pop(){
//     Min_e[0] = Min_e[--UsedSize];
//     int parentindex = 0;
//     int leftindex = 1;
//     int rightindex = 2;
//     while(1){
//         int selectchild = 0;
//         if(leftindex>=UsedSize){
//             break;
//         }
//         if(rightindex>=UsedSize){
//             selectchild = leftindex;
//         }
//         else{
//             if(Min_e[leftindex]>Min_e[rightindex]){
//                 selectchild = rightindex;
//             }
//             else selectchild = leftindex;
//         }

//         if(Min_e[parentindex]>Min_e[selectchild]){
//             int temp = Min_e[parentindex];
//             Min_e[parentindex] = Min_e[selectchild];
//             Min_e[selectchild] = temp;
//             parentindex = selectchild;
//             leftindex = selectchild*2 +1;
//             rightindex = leftindex+1;
//         }
//         else break;
//     }
// }

// int top(){
//     return Min_e[0];
// }

// int main(void){
//     scanf("%d", &N);
//     for(int i=0; i<N; i++){
//         int a, b;
//         scanf("%d %d", &a, &b);
//         list[i] = (Time){a, b};
//     }

//     qsort(list, N, sizeof(Time), Compare);
    
//     push(list[0].e);

//     for(int i=1; i<N; i++){
//         if(top() <= list[i].s){
//             pop();
//         }
//         push(list[i].e);
//     }

//     printf("%d\n", UsedSize);
//     return 0;
// }