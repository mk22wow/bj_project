#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int check_digits(int num){
    int count = 0;
    while(num>0){
        num /= 10;
        count++;
    }
    return count;
}

int main(void){
    char str[3001];
    char* list;
    int num = 1;
    int len = 0;
    int i=0, j=0;
    scanf("%s", str);

    while(1){
        len = check_digits(num);
        list = (char*)malloc((len+1)*sizeof(char));
        sprintf(list, "%d", num);
        for(j=0; j<len; j++){
            if(str[i] == list[j]){
                i++;
                if(i==strlen(str)){
                    free(list);
                    goto end_loop;
                }
            }
        }
        free(list);
        num++;
    }

end_loop:
    printf("%d\n",num);
    return 0;
}