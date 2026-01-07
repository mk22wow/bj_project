#include <stdio.h>
#include <string.h>

int main(void){
    int N;
    scanf("%d", &N);
    if(N<1 || N>10000) return 0;

    int i=666, count = 0;
    char str[99];
    while(1){
        sprintf(str, "%d", i);
        if(strstr(str, "666") != NULL) {
            count++;
            if(count == N){
                printf("%d\n", i);
                break;
            }
        }
        i++;
    }
    return 0;
}