#include <stdio.h>

int main(void){
    char input[31];
    char list[31];
    int answer = 0, top = -1, temp = 1;
    scanf("%s", input);
    for(int i=0; input[i]; i++){
        if(input[i] == '('){
            list[++top] = '(';
            temp*=2;
        }
        else if(input[i] == '['){
            list[++top] = '[';
            temp*=3;
        }
        else if(input[i] == ')'){
            if(top<0 || list[top] != '('){
                printf("0\n");
                return 0;
            }
            if(input[i-1] == '('){
                answer += temp;
            }
            temp/=2;
            top--;
        }
        else{
            if(top<0 || list[top] != '['){
                printf("0\n");
                return 0;
            }
            if(input[i-1] == '['){
                answer += temp;
            }
            temp/=3;
            top--;
        }
    }

    if(top!=-1){
        printf("0\n");
    }
    else printf("%d\n", answer);
    return 0;
}

/*char input[31];
int pair_count = 0, answer = 0;

typedef struct{
    char c;
    int position;
}Pos;

typedef struct{
    int index_s;
    int index_e;
    int data;
}Pair;

Pos list[31];
Pair value[15];
Pair calculate[15];

void Find(int s){
    int index = 0;
    for(int i=s; input[i]; i++){
        if(input[i] == '(' || input[i] == '['){
            list[index++] = (Pos){input[i], i};
        }
        else if(input[i] == ')'){
            if(index-1<0){
                index = -1;
                break;
            }
            if(list[index-1].c == '('){
                index--;
                value[pair_count++] = (Pair){list[index].position, i, 2};
            }
        }
        else{
            if(index-1<0){
                index = -1;
                break;
            }
            if(list[index-1].c == '['){
                index--;
                value[pair_count++] = (Pair){list[index].position, i, 3};
            }
        }
    }

    if(index!=0){
        printf("%d\n", answer);
    }
    else{
        int c_idx = 0;
        calculate[c_idx++] = value[0]; 
        int idx_s = value[0].index_s, idx_e = value[0].index_e;
        for(int i=1; i<pair_count; i++){
            if(value[i].index_s>value[i-1].index_e){
                calculate[c_idx++] = value[i];
            }
            else{
                for(int j=0; j<c_idx; j++){
                    if(value[i].index_s<calculate[j].index_e){
                        calculate[j].data *= value[i].data;
                    }
                }
            }
        }
        for(int j=0; j<c_idx; j++){
            answer += calculate[j].data;
        }
        printf("%d\n", answer);
    }

    
}

int main(void){
    scanf("%s", input);
    Find(0);
    return 0;
}*/