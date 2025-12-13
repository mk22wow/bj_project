#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

/*void checkMax(int** list, int N, int M, int* result){
    int max = list[N][M];
    for(int i=0; i<=N; i++){
        for(int j=0; j<=M; j++){
            int temp;
            if(i==0 && j==0){
                temp = list[N][M];
            }
            else if(i == 0){
                temp = max-list[N][j-1];
            }
            else if(j==0){
                temp = max-list[i-1][M];
            }
            else{
                temp = max-list[N][j-1]-list[i-1][M]+list[i-1][j-1];
            }
            (*result) = (*result)>temp ? (*result): temp;
        }
    }
}

int main(void){
    int N, M;
    scanf("%d %d", &N, &M);
    if(N<1 || N>200 || M<1 || M>200){
        return 0;
    }
    int** list = (int**)calloc(N,sizeof(int*));
    int result = INT_MIN;
    for(int i=0; i<N; i++){
        int row = 0;
        list[i] = (int*)malloc(sizeof(int)*M);
        for(int j=0; j<M; j++){
            int temp;
            scanf("%d", &temp);
            if(abs(temp)>10000){
                for(int k=0; k<=i; k++){
                    free(list[k]);
                }
                free(list);
                return 0;
            }
            row+=temp;
            if(i == 0){
                list[i][j] = row;    
            }
            else{
                list[i][j] = row + list[i-1][j];
            }
            checkMax(list, i, j, &result);
        }
    }
    printf("%d\n", result);
    for(int i=0; i<N; i++){
        free(list[i]);
    }
    free(list);
    return 0;
}*/

int Kadane(int* arr, int N){
    int max = INT_MIN;
    int sum = 0;
    for(int i=0; i<N; i++){
        sum += arr[i];
        if(sum>max){
            max = sum;
        }
        if(sum<0){
            sum = 0;
        }
    }
    return max;
}

int checkMAX(int** list, int N, int M){
    int result = INT_MIN;
    for(int i=0; i<M; i++){
        int* temp = (int*)calloc(N, sizeof(int)); 
        for(int j=i; j<M; j++){
            for(int k=0; k<N; k++){
                temp[k] += list[k][j];
            }
            int currentSum = Kadane(temp, N);
            result = result<currentSum ? currentSum : result;
        }
    }
    return result;
}

int main(void){
    int N, M;
    scanf("%d %d", &N, &M);
    if(N<1 || N>200 || M<1 || M>200){
        return 0;
    }
    int** list = (int**)calloc(N,sizeof(int*));
    for(int i=0; i<N; i++){
        list[i] = (int*)malloc(sizeof(int)*M);
        for(int j=0; j<M; j++){
            int temp;
            scanf("%d", &temp);
            if(abs(temp)>10000){
                for(int k=0; k<=i; k++){
                    free(list[k]);
                }
                free(list);
                return 0;
            }
            list[i][j] = temp;   
        }
    }    
    int result = checkMAX(list, N, M);
    printf("%d\n", result);
    for(int i=0; i<N; i++){
        free(list[i]);
    }
    free(list);
    return 0;
}
