#include <stdio.h>
#include <string.h>

int len;
char str[51];
int DP[51][51][51][4][4] = {0};
int cnt[3] = {0};
int ans[51];

void push(int check[], int curr){
    check[0] = check[1];
    check[1] = check[2];
    check[2] = curr;
}

int Find(int a, int b, int c, int pred1, int pred2){
    if(a == 0 && b == 0 && c == 0) return 1;
    
    if(DP[a][b][c][pred1][pred2] != 0) return 0;
    DP[a][b][c][pred1][pred2] = 1;
    int curr = len-a-b-c;
    
    if(a>0){
        ans[curr] = 1;
        if(Find(a-1, b, c, pred2, 1)) return 1;
    }

    if(b>0 && pred2 != 2){
        ans[curr] = 2;
        if(Find(a, b-1, c, pred2, 2)) return 1;
    }

    if(c>0 && pred1 != 3 && pred2 != 3){
        ans[curr] = 3;
        if(Find(a, b, c-1, pred2, 3)) return 1;
    }

    return 0;
}

int main(void){
    scanf("%s", str);
    len = strlen(str);
    for(int i=0; i<len; i++){
        char c = str[i];
        if(c=='A') cnt[0]++;
        else if(c=='B') cnt[1]++;
        else cnt[2]++;
    }

    if(Find(cnt[0], cnt[1], cnt[2], 0, 0) == 1){
        for(int i=0; i<len; i++){
            if(ans[i] == 1){
                printf("A");
            }
            else if(ans[i] == 2){
                printf("B");
            }
            else printf("C");
        }    
    }
    else printf("-1\n");
    
    return 0;
}