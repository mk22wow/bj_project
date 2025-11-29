#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_LENGTH 10000

int check_str(char str[], int length){
    int str_len = strlen(str);
    if(str_len>=1 && str_len<=10000){
        if(str_len>=length){
            return 1;
        }
    }
    return 0;
}

/*int find_result1(char str[], int length){
    int str_len = strlen(str);
    int j=0;
    for(int i=length; i<=str_len; i++){
        int alpha[26] = {0};
        for(j=0; j<i; j++){
            alpha[str[j]-'a']++;
        }
        if(alpha[str[j-1]-'a'] == length){
                return i;
        }
        for(int k=i; k<str_len; k++){
            alpha[str[k-i]-'a']--;
            if((++alpha[str[k]-'a']) == length){
                return i;
            }
        }
    }
    return -1;
}

int find_result2(char str[], int length){
    int str_len = strlen(str);
    int max = -1, j = 0;
    for(int i=length; i<=str_len; i++){
        int alpha[26] = {0};
        for(j=0; j<i; j++){
            alpha[str[j]-'a']++;
        }
        if(alpha[str[j-1]-'a'] == length){
            if(str[0] == str[j-1]){
                max = i;
            }
        }
        for(int k=i; k<str_len; k++){
            alpha[str[k-i]-'a']--;
            if((++alpha[str[k]-'a']) == length){
                if(str[k-i+1] == str[k]){
                    if(max<i){
                        max = i;
                    }
                }
            }
        }
    }

    return max;
}*/

/*int find_result1(char str[], int K) {
    int str_len = strlen(str);
    int min_len = 10001; // MAX_LENGTH + 1보다 크게 초기화

    // 각 알파벳 ('a'~'z')에 대해 검사
    for (int c = 0; c < 26; c++) {
        char target_char = 'a' + c;
        int indices[str_len]; // 해당 문자의 인덱스를 저장할 배열
        int count = 0;

        // 1. 해당 문자의 모든 인덱스 수집
        for (int i = 0; i < str_len; i++) {
            if (str[i] == target_char) {
                indices[count++] = i;
            }
        }

        // 2. K개 이상 존재할 때만 검사
        if (count >= K) {
            // K개를 포함하는 윈도우 검사 (K번째 간격)
            for (int i = 0; i <= count - K; i++) {
                // i번째 등장부터 (i+K-1)번째 등장까지의 윈도우
                int start_idx = indices[i];
                int end_idx = indices[i + K - 1];
                
                // 윈도우 길이 계산: (끝 인덱스 - 시작 인덱스 + 1)
                int current_len = end_idx - start_idx + 1;
                
                if (current_len < min_len) {
                    min_len = current_len;
                }
            }
        }
    }
    return (min_len == 10001) ? -1 : min_len;
}

int find_result2(char str[], int K) {
    int str_len = strlen(str);
    int max_len = -1; 

    // 각 알파벳 ('a'~'z')에 대해 검사
    for (int c = 0; c < 26; c++) {
        char target_char = 'a' + c;
        int indices[str_len]; 
        int count = 0;

        // 1. 해당 문자의 모든 인덱스 수집
        for (int i = 0; i < str_len; i++) {
            if (str[i] == target_char) {
                indices[count++] = i;
            }
        }

        // 2. K개 이상 존재할 때만 검사
        if (count >= K) {
            // K개를 포함하는 윈도우 검사
            for (int i = 0; i <= count - K; i++) {
                // 이 윈도우는 시작/끝 문자가 target_char로 같다는 조건을 만족합니다.
                int start_idx = indices[i];
                int end_idx = indices[i + K - 1];
                
                // 윈도우 길이 계산
                int current_len = end_idx - start_idx + 1;
                
                if (current_len > max_len) {
                    max_len = current_len;
                }
            }
        }
    }
    return max_len;
}*/

int main(void){
    int i = 0, time = 0;
    scanf("%d", &time);
    while(getchar() != '\n');
    if(time<1 || time>100){
        return 0;
    }
    char** list = (char**)malloc(time*sizeof(char*));
    for(int j=0; j<time; j++){
        list[j] = (char*)malloc(12*sizeof(char));
        if(list[j] == NULL){
            return 0;
        }
    }

    while(i<time){
        char str[10002];
        int length = 0;
        int result1 = 0, result2 = 0;
        if(fgets(str, MAX_LENGTH+1, stdin) == NULL){
            printf("wrong input");
            continue;
        }
        str[strcspn(str, "\n")] = '\0';
        scanf("%d", &length);
        while(getchar() != '\n');
        if(!check_str(str, length)){
            break;
        }
        result1 = find_result1(str, length);
        if(result1 == -1){
            snprintf(list[i], 12, "%d", result1);
            i++;
            continue;
        }
        result2 = find_result2(str, length);
        if(result2 == -1){
            snprintf(list[i], 12, "%d", result2);
            i++;
            continue;
        }
        snprintf(list[i], 12, "%d %d", result1, result2);
        i++;
    }
    
    for(int j=0; j<time; j++){
        printf("%s\n", list[j]);
        free(list[j]);
    }
    
    free(list);
    return 0;
}