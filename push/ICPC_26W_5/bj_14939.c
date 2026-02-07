#include <stdio.h>
#include <string.h>

int min = 111;
int list[11][11];
int dx[5] = {0, 0, 1, 0, -1};
int dy[5] = {0, -1, 0, 1, 0};

void Turn(int curr[][11], int y, int x){
    for(int i=0; i<5; i++){
        int temp_x = x+dx[i];
        int temp_y = y+dy[i];
        if(temp_x>=0 && temp_x<10 && temp_y>=0 && temp_y<10){
            curr[temp_y][temp_x] = 1-curr[temp_y][temp_x];
        }
    }
}

void Find(){
    for(int i=0; i<1024; i++){
        int temp[11][11];
        int count = 0;
        memcpy(temp, list, sizeof(list));
        for(int j=0; j<10; j++){
            if(i&(1<<j)){
                Turn(temp, 0, j);
                count++;
            }
        }

        for(int k=1; k<10; k++){   
            for(int j=0; j<10; j++){
                if(temp[k-1][j] != 0){
                    Turn(temp, k, j);
                    count++;
                }
            }
        }
        

        int pass = 1;

        for(int j=0; j<10; j++){
            if(temp[9][j] != 0){
                pass = 0;
                break;
            }
        }
        if(pass==1&& min>count){
            min = count;
        }
    }
}

int main(void){
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            char c;
            scanf(" %c", &c);
            if(c == '#') list[i][j] = 0;
            else list[i][j] = 1;
        }
    }

    Find();
    if(min == 111) printf("-1\n");
    else printf("%d\n", min);
    return 0;
}