#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int p;
    int d;
}Lesson;

int n, usedsize = 0, result = 0;
Lesson list[10000];
Lesson pay[10000];

int Compare(const void* a, const void* b){
    Lesson pa = *(Lesson*)a;
    Lesson pb = *(Lesson*)b;
    return pa.d - pb.d;
}

void Push(Lesson L[], Lesson H){
    L[usedsize] = H;
    int currentindex = usedsize;
    int parentindex = (currentindex-1)/2;

    while(currentindex>0 && L[currentindex].p<L[parentindex].p){
        L[currentindex] = L[parentindex];
        L[parentindex] = H;
        currentindex = parentindex;
        parentindex = (currentindex-1)/2;
    }
    usedsize++;
}

Lesson Pop(Lesson L[]){
    Lesson answer = L[0];
    L[0] = L[--usedsize];
    int parentindex = 0;
    int leftindex = 1;
    int rightindex = 2;
    int selectchild;

    while(1){
        if(leftindex>=usedsize){
            break;
        }
        if(rightindex>=usedsize){
            selectchild = leftindex;
        }
        else{
            if(L[leftindex].p<L[rightindex].p){
                selectchild = leftindex;
            }
            else selectchild = rightindex;
        }

        if((L[selectchild].p < L[parentindex].p)){
            Lesson temp = L[parentindex];
            L[parentindex] = L[selectchild];
            L[selectchild] = temp;
            parentindex = selectchild;
            leftindex = parentindex*2 + 1;
            rightindex = leftindex + 1;
        }
        else break;
    }
    return answer;
}

int main(void){
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        list[i] = (Lesson){a,b};
    }
    qsort(list, n, sizeof(Lesson), Compare);
    for(int i=0; i<n; i++){
        Push(pay, list[i]);
        if(list[i].d<usedsize){
            Pop(pay);
        }
    }
    
    for(int i=0; i<usedsize; i++){
        result += pay[i].p;
    }
    printf("%d\n", result);
    return 0;
}

// void Push(Lesson H){
//     list[usedsize] = H;
//     int currentindex = usedsize;
//     int parentindex = (currentindex-1)/2;

//     while(currentindex>0 && list[currentindex].d>=list[parentindex].d){
//         if(list[currentindex].d == list[parentindex].d && list[currentindex].p < list[parentindex].p){
//             break;
//         }
//         list[currentindex] = list[parentindex];
//         list[parentindex] = H;
//         currentindex = parentindex;
//         parentindex = (currentindex-1)/2;
//     }
//     usedsize++;
// }

// Lesson Pop(){
//     Lesson answer = list[0];
//     list[0] = list[--usedsize];
//     int parentindex = 0;
//     int leftindex = 1;
//     int rightindex = 2;
//     int selectchild;

//     while(1){
//         if(leftindex>=usedsize){
//             break;
//         }
//         if(rightindex>=usedsize){
//             selectchild = leftindex;
//         }
//         else{
//             if(list[leftindex].d>list[rightindex].d){
//                 selectchild = leftindex;
//             }
//             else if(list[leftindex].d==list[rightindex].d && list[leftindex].p>list[rightindex].p){
//                 selectchild = leftindex;
//             }
//             else selectchild = rightindex;
//         }

//         if((list[selectchild].d > list[parentindex].d) || (list[selectchild].d == list[parentindex].d && list[selectchild].p>list[parentindex].p)){
//             Lesson temp = list[parentindex];
//             list[parentindex] = list[selectchild];
//             list[selectchild] = temp;
//             parentindex = selectchild;
//             leftindex = parentindex*2 + 1;
//             rightindex = leftindex + 1;
//         }
//         else break;
//     }
//     return answer;
// }

// int main(void){
//     scanf("%d", &n);
//     for(int i=0; i<n; i++){
//         int a, b;
//         scanf("%d %d", &a, &b);
//         Push((Lesson){a,b});
//     }

//     while(list[0].d>0){
//         Lesson current = Pop();
//         result += current.p;
//         int date = current.d;
//         while(1){
//             Lesson temp = Pop();
//             if(temp.d != date){
//                 Push(temp);
//                 break;
//             }
//             temp.d--;
//             Push(temp);
//         }
//         printf("%d %d\n", current.p, current.d);
//     }
    
//     printf("%d\n", result);
//     return 0;
// }