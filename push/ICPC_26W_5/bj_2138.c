#include <stdio.h>

int N, Min = 100005;
int result[100005];
int temp1[100005] = {0};
int temp2[100005] = {0};

int main(void){
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        int b;
        scanf("%1d", &b);
        temp1[i] = b;
        temp2[i] = b;
    }
    for(int i=0; i<N; i++){
        scanf("%1d", &result[i]);
    }

    int count1 = 1, count2 = 0;
    temp1[0] = 1-temp1[0];
    temp1[1] = 1-temp1[1];

    for(int i=1; i<N-1; i++){
        if(temp1[i-1]!=result[i-1]){
            temp1[i-1] = 1-temp1[i-1];
            temp1[i] = 1-temp1[i];
            temp1[i+1] = 1-temp1[i+1];
            count1++;
        }
        if(temp2[i-1]!=result[i-1]){
            temp2[i-1] = 1-temp2[i-1];
            temp2[i] = 1-temp2[i];
            temp2[i+1] = 1-temp2[i+1];
            count2++;
        }
    }
    if(temp1[N-2]!=result[N-2]){
        temp1[N-1] = 1-temp1[N-1];
        temp1[N-2] = 1-temp1[N-2];
        count1++;
    }
    if(temp2[N-2]!=result[N-2]){
        temp2[N-1] = 1-temp2[N-1];
        temp2[N-2] = 1-temp2[N-2];
        count2++;
    }
    
    int pass = 1;
    if(temp1[N-1] == result[N-1]){
        if(Min>count1) Min = count1;
        pass = 0;
    } 
    
    if(temp2[N-1] == result[N-1]){
        if(Min>count2) Min = count2;
        pass = 0;
    } 

    if(pass==1) printf("-1\n");
    else printf("%d\n", Min);

    return 0;
}