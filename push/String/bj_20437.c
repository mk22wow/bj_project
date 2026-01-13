#include <stdio.h>
#include <string.h>
#include <limits.h>

int T, K;
char str[10001];

int main(void){
    scanf("%d", &T);
    int n=0;
    while(T--){
        scanf("%s %d", str, &K);
        int list[26] = {0};
        int len = strlen(str);
        int Min = INT_MAX,  Max = INT_MIN;
        for(int i=0; i<len; i++){
            int temp = str[i] - 'a';
            list[temp]++;
            if(list[temp] >= K){
                int s = i, count = K;
                while(s>=0 && count!=0){
                    if(str[s] == str[i]){
                        count--;
                    }
                    s--;
                }
                int value =  i - s;
                if(value>Max) Max = value;
                if(value<Min) Min = value;
            }
        }
        if(Max <0) printf("-1\n");
        else printf("%d %d\n", Min, Max);
    }
    return 0;
}