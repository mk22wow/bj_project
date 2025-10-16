#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_LENGTH 50
#define BUFFER_SIZE (MAX_LENGTH + 2)

int check_str(char str[], int list[]){
    for(int i=0; str[i]!='\0'; i++){
        if(isalpha((unsigned char)str[i])){
            str[i] = toupper((unsigned char)str[i]);
        }
        else{
            return 0;
        }
        list[str[i]-'A']++;
    }
    return 1;
}

void print_palindrome(char str[], int list[], int index){
    int i=0, j=0, times=0;
    int len=strlen(str);
    char result[len+1];
    
    for(i=0; i<26; i++){
        times = list[i]/2;
        while(times!=0){
            result[j++] = (char)('A'+i);
            times--;
        }
    }
    if(index>=0){
        result[j++] = (char)(index+'A');
    }
    for(i=25; i>=0; i--){
        times = list[i]/2;
        while(times!=0){
            result[j++] = (char)('A'+i);
            times--;
        }
    }
    result[len] = '\0';
    printf("%s\n", result);

}

void check_palindrome(char str[], int list[]){
    int even = 0, odd = 0, index = -1;
    for(int i=0; i<26; i++){
        if(list[i]%2 ==0 && list[i]>0){
            even++;
        }
        if(list[i]%2==1){
            odd++;
            index = i;
        }
    }
    //printf("%d %d", even, odd);
    if(even>=0 && odd<=1){
        print_palindrome(str, list, index);
    }
    else{
        printf("I'm Sorry Hansoo");
    }
}

int main(void){
    char str[MAX_LENGTH];
    int alpha[26] = {0};
    if(fgets(str, BUFFER_SIZE, stdin) == NULL){
        printf("wrong input_1\n");
        return 0;
    }
    str[strcspn(str, "\n")] = '\0';
    if(!check_str(str, alpha)){
        printf("wrong input_2\n");
        return 0;
    }
    check_palindrome(str, alpha);

    return 0;
}