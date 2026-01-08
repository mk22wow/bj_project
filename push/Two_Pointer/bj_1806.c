#include <stdio.h>

int N, S;
int list[100000];
int length = 0;

int main(void){
    scanf("%d %d", &N, &S);
    int temp = 0, index = 0;
    for(int i=0; i<N; i++){
        scanf("%d", &list[i]);
        temp += list[i]; 
        if(temp>=S){
            while(temp>=S){
                temp -= list[index++];
            }
            temp += list[--index];
            int current_length = i+1-index;
            //printf("%d %d\n", i, current_length);
            if(length == 0) length = current_length;
            else length = length<current_length ? length:current_length;
        }
    }

    printf("%d\n", length);
    return 0;
}