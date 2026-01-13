#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
    char str[101];
    int index;
}Word;

Word list[20000];
char original_list[20000][101];
int N, Max = 0;

int Compare(const void* a, const void* b){
    Word pa = *(Word*)a;
    Word pb = *(Word*)b;
    if(strcmp(pa.str, pb.str)==0){
        return pa.index - pb.index;
    }
    return strcmp(pa.str, pb.str);
}

int Find(const char* a, const char* b){
    int i=0;
    while(a[i] && b[i] && a[i] == b[i]){
        i++;
    }
    return i;
}

int main(void){
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        scanf("%s", list[i].str);
        list[i].index = i;
        strcpy(original_list[i], list[i].str);
    }

    qsort(list, N, sizeof(Word), Compare);

    for(int i=0; i<N-1; i++){
        int temp = Find(list[i].str, list[i+1].str);
        if(temp>Max) Max = temp;
    }

    for(int i=0; i<N; i++){
        for(int j=i+1; j<N; j++){
            if(Find(original_list[i], original_list[j]) == Max){
                printf("%s\n%s", original_list[i], original_list[j]);
                return 0;
            }
        }
    }
    
    return 0;
}