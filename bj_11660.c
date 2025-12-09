#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void){
    int n, m;
    scanf("%d %d", &n, &m);
    if(n<0 || n>1024){
        return 0;
    }
    if(m<0 || m>100000){
        return 0;
    }
    int** list = (int**)malloc(sizeof(int*)*n);
    for(int i=0; i<n; i++){
        list[i] = (int*)malloc(sizeof(int)*n);
        for(int j=0; j<n; j++){
            int temp = 0;
            scanf("%d", &temp);
            if(temp<0 || temp>1000){
                for(int k=0; k<=i; i++){
                    free(list[k]);
                }
                free(list);
                return 0;
            }
            if(i==0){
                if(j==0){
                    list[i][j] = temp;
                }
                else{
                    list[i][j] = temp+list[i][j-1];
                }
            }
            else{
                if(j==0){
                    list[i][j] = temp+list[i-1][j];
                }
                else{
                    list[i][j] = temp+list[i-1][j]+list[i][j-1]-list[i-1][j-1];
                }
            }
        }
    }
    for(int i=0; i<m; i++){
        int x1,y1,x2,y2;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        int result = list[x2-1][y2-1];
        if(x1!=1 && y1!=1){
            result -= (list[x2-1][y1-2] + list[x1-2][y2-1]);
            result += list[x1-2][y1-2];
        }
        if(x1==1 && y1!=1){
            result -= list[x2-1][y1-2];
        }
        if(x1!=1 && y1==1){
            result -= list[x1-2][y2-1];
        }
        printf("%d\n", result);
    }

    for(int i=0; i<n; i++){
        free(list[i]);
    }
    free(list);
    return 0;
}