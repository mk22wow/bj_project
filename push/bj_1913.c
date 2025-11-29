#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(void){
    int num1 = 0, num2 = 0;
    scanf("%d", &num1);
    if(num1%2 == 0 || num1>999 || num1<3){
        printf("wrong input");
        return 0;
    }
    scanf("%d", &num2);
    int total = num1 * num1;
    if(num2<0 || num2>total){
        printf("wrong input");
        return 0;
    }
    int** list = (int**)malloc(num1*sizeof(int*));
    for(int i=0; i<num1; i++){
        list[i] = (int*)malloc(num1*sizeof(int));
    }

    
    int row = (num1-1)/2;
    int col = row;
    int count = 1;
    list[row][col] = count++;
    
    
    for(int i = 1; i<num1; i++){
        for(int j=0; j<2; j++){
            int z = 0;
            if(i%2==1){
                if(j==0){
                    while(z<i){
                        z++;
                        list[--row][col] = count++;
                    }
                }
                else{
                    while(z<i){
                        z++;
                        list[row][++col] = count++;
                    }
                }
            }
            else{
                if(j==0){
                    while(z<i){
                        z++;
                        list[++row][col] = count++;
                    }
                }
                else{
                    while(z<i){
                        z++;
                        list[row][--col] = count++;
                    }
                }
            }
        }
    }
    int z=0;
    while(z<num1-1){
        z++;
        list[--row][col] = count++;
    }

    int index_r = 0, index_c = 0;
    for(int i=0; i<num1; i++){
        for(int j=0; j<num1; j++){
            printf("%d ",list[i][j]);
            if(list[i][j] == num2){
                index_r=i+1;
                index_c=j+1;
            }
        }
        printf("\n");
    }

    printf("%d %d\n", index_r, index_c);

}