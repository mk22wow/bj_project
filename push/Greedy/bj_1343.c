#include <stdio.h>
#include <string.h>

char str[51];
int len;

int main(void){
    scanf("%s", str);
    len = strlen(str);

    int start = 0, index = 0, count_x = 0;
    while(index<len){
        while(index<len && str[index]=='X'){
            index++;
            count_x++;
        }
        if(count_x%2 != 0){
            printf("-1\n");
            return 0;
        }
        else{
            int end_A = start + count_x - (count_x % 4);
            for(int i=start; i<end_A; i++){
                str[i] = 'A';
            }
            for(int i=end_A; i<index; i++){
                str[i] = 'B';
            }
        }
        while(index<len && str[index]=='.'){
            index++;
        }
        start = index;
        count_x = 0;
    }

    printf("%s\n", str);
    return 0;
}