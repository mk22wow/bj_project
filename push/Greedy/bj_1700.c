#include <stdio.h>
#include <limits.h>

int N, K, count = 0;
int list[100];
int plug[101] = {0};
int multitap[100];

int main(void){
    scanf("%d %d", &N, &K);
    for(int i=0; i<K; i++){
        scanf("%d", &list[i]);
    }
    
    int answer = 0;
    for(int i=0; i<K; i++){
        if(plug[list[i]] == 0){
            if(count<N){
                plug[list[i]] = 1;
                multitap[count++] = list[i];
            }
            else{
                int appear[101] = {0};
                int replace = 0, pass = 1;
                for(int j=0; j<N; j++){
                    for(int k=i+1; k<K; k++){
                        if(multitap[j] == list[k]){
                            appear[j] = k;
                            break;
                        }
                    }
                    if(!appear[j]){
                        replace = j;
                        pass = 0;
                        break;
                    }
                }

                if(pass && i!=K-1){
                    int temp = appear[0];
                    for(int j=1; j<N; j++){
                        if(appear[j]>temp){
                            temp = appear[j];
                            replace = j;
                        }
                    }
                }
                plug[multitap[replace]] = 0;
                multitap[replace] = list[i];
                plug[list[i]] = 1;
                answer++;
            }
        }
    }
    printf("%d\n", answer);
}




/*int N, K, Min = INT_MAX;
int list[100];
int Q[100];

void Find(int s, int count, int rear){
    while(s<K){
        if(rear<N){
            int pass = 1;
            for(int j=0; j<rear; j++){
                if(Q[j] == list[s]){
                    pass = 0;
                    break;
                }
            }
            if(pass) Q[rear++] = list[s];
        }
        else{
            int pass = 1;
            for(int j=0; j<rear; j++){
                if(Q[j] == list[s]){
                    pass = 0;
                    break;
                }
            }
            if(pass){
                for(int j=0; j<rear; j++){
                    int temp = Q[j];
                    Q[j] = list[s];
                    Find(s+1, count+1, rear);
                    Q[j] = temp;
                }
                break;
            }       
        }
        s++;
    }

    if(s == K){
        for(int i=0; i<rear; i++){
            printf("%d ", Q[i]);
        }
        printf("\n%d\n",count);
        if(Min>count) Min = count;
        return;
    }
}

int main(void){
    scanf("%d %d", &N, &K);
    for(int i=0; i<K; i++){
        scanf("%d", &list[i]);
    }
    Find(0, 0, 0);
    printf("%d\n", Min);
}*/