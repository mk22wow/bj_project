#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void list_cloud(int list[], char cloud[], int w){
    for(int i=0; i<w; i++){
        if(cloud[i] == 'c'){
            list[i] = 0;
        }
        else {
            list[i] = -1;
        }
    }
}

void free_list(int** list, int h){
    for(int i=0; i<h; i++){
        free(list[i]);
    }
    free(list);
}

int main(void){
    int h = 0, w = 0;
    scanf("%d %d", &h, &w);
    int** list = (int**)malloc(h*sizeof(int*));
    for(int i=0; i<h; i++){
        list[i] = (int*)malloc(w*sizeof(int));
    }

    while(getchar() != '\n');
    for(int i=0; i<h; i++){
            if((h>0 && h<=100) && (w>0 && w<=100)){
            char* cloud = (char*)malloc(w+2);
            // if(fgets(cloud, w+2, stdin) == NULL){
            //     free(cloud);
            //     free_list(list, h);
            //     return 0;
            // }
            //fgets(cloud, w+2, stdin);
            //cloud[strcspn(cloud, "\n")] = '\0';
            scanf("%s", cloud);
            if(strlen(cloud) != w){
                free(cloud);
                return 0;
            }

            list_cloud(list[i], cloud, w);
            free(cloud);
        }
    }
    
    for(int i=0; i<h; i++){
        int index = w;
        for(int j=0; j<w; j++){
            if(list[i][j] == 0){
                index = j;
            }
            else if(index<j){
                list[i][j] = j-index;
            }
            printf("%d ", list[i][j]);
        }
        printf("\n");
    }

    free_list(list, h);

    return 0;
}