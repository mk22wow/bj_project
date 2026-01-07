#include <stdio.h>
#include <stdlib.h>

void findNK(int N, int K){
    int* list = (int*)malloc(sizeof(int)*(N-1));
    for(int i=N-1; i>0; i--){
        list[i-1] = i+1;
    }
    int count = 0;
    for(int i=0; i<N-1; i++){
        int min;
        if(list[i] != 0){
            min = list[i];
            if(i == N-2){
                count++;
                if(count == K){
                    printf("%d\n", list[i]);
                }
                list[i] = 0;
            }
            for(int j=i; j<N-1; j++){
                if(list[j] != 0 && list[j]%min == 0){
                    count++;
                    if(count == K){
                        printf("%d\n", list[j]);
                    }
                    list[j] = 0;
                }
            }
            } 
        }
    
    free(list);
}

int main(void){
    int num1, num2;
    scanf("%d %d", &num1, &num2);
    findNK(num1, num2);
    return 0;
}
