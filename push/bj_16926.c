#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

void rotate_list(int** list, int row_top, int col_top, int row_bottom, int col_bottom, int r){
    if(row_top<=row_bottom && col_top<=col_bottom){
    int length = 2*(row_bottom-row_top+1+col_bottom-col_top+1-2);
    int rotation = r%length;
    int* temp = (int*)malloc(length*sizeof(int));
    int index = 0;
    for(int i=row_top; i<=row_bottom; i++){
        temp[index++] = list[i][col_top]; //left
    }
    for(int i=col_top+1; i<col_bottom; i++){
        temp[index++] = list[row_bottom][i]; //down
    }
    for(int i=row_bottom; i>=row_top; i--){
        temp[index++] = list[i][col_bottom]; //right
    }
    for(int i=col_bottom-1; i>col_top; i--){
        temp[index++] = list[row_top][i]; //up
    }

    /*for(int i=0; i<rotation; i++){
        int last = temp[length-1];
        memmove(&temp[1], &temp[0], sizeof(int)*(length-1));
        temp[0] = last;
    }*/

    int* rot = (int*)malloc(sizeof(int)*length);
    for(int i=0; i<length; i++){
        rot[(i+rotation)%length] = temp[i];
    }

    index = 0;
    for(int i=row_top; i<=row_bottom; i++){
        list[i][col_top] = rot[index++]; //left
    }
    for(int i=col_top+1; i<col_bottom; i++){
        list[row_bottom][i] = rot[index++]; //down
    }
    for(int i=row_bottom; i>=row_top; i--){
        list[i][col_bottom] = rot[index++]; //right
    }
    for(int i=col_bottom-1; i>col_top; i--){
        list[row_top][i] = rot[index++]; //up
    }

    free(rot);
    free(temp);
    rotate_list(list, row_top+1, col_top+1, row_bottom-1, col_bottom-1, r);
}
else return;
}


int main(void){
    int n, m, r;
    scanf("%d %d %d", &n, &m, &r);
    /*while(getchar()!='\n');
    int** list = (int**)malloc(n*sizeof(int*));
    for(int i=0; i<n; i++){
        list[i] = (int*)malloc(m*sizeof(int));
        int j = 0;
        char str[999];
        fgets(str,sizeof(str),stdin);
        str[strcspn(str, "\n")] = '\0';
        char* token = strtok(str, " ");
        while(token!=NULL){
            list[i][j++] = atoi(token);
            token = strtok(NULL, " ");
        }
    }*/

    int** list = (int**)malloc(n*sizeof(int*));
    for(int i=0; i<n; i++){
        list[i] = (int*)malloc(m*sizeof(int));
       for(int j=0; j<m; j++){
           scanf("%d",&list[i][j]);
       }
    }
    int row_top = 0, col_top = 0, row_bottom = n-1, col_bottom = m-1;

    rotate_list(list, row_top, col_top, row_bottom, col_bottom, r);
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            printf("%d ", list[i][j]);
        }
        free(list[i]);
        printf("\n");
    }
    free(list);
    return 0;
}



/*void rotate_list(int** list, int row_top, int col_top, int row_bottom, int col_bottom, int r){
    int temp_for = (row_bottom-row_top+1); 
    int row = (row_bottom-row_top+1);
    int col = (col_bottom-col_top+1);
    int** temp = (int**)malloc(row*sizeof(int*));
    for(int i=0; i<row; i++){
        temp[i] = (int*)malloc(col*sizeof(int));
        for(int j=0; j<col; j++){
            temp[i][j] = list[row_top+i][col_top+j];
        }
    }
    
    while(row_top<=row_bottom && col_top<=col_bottom){
        row = row_top;
        while(row+1<=row_bottom){
            list[row][col_top] = temp[(row++)][col_top]; //left         
        }
        
        col = col_top;
        while(col+1<=col_bottom){
            list[row_bottom][col] = temp[row_bottom][(col++)]; //down
        }

        row = row_bottom;
        while(row-1>=row_top){
            list[row][col_bottom] = temp[(row--)][col_bottom]; //right
        }

        col = col_bottom;
        while(col-1>=col_top){
            list[row_top][col] = temp[row_top][(col--)]; //up
        }
        
        ++row_top, ++col_top, --row_bottom, --col_bottom;
    }
    for(int i=0; i<temp_for; i++){
            free(temp[i]);
    }
    free(temp);
}*/  //둘레가 계속 변하는데 r을 고정함


/*void rotate_list(int** list, int row_top, int col_top, int row_bottom, int col_bottom){

    if(row_top >= row_bottom || col_top >= col_bottom) return;

    int height = row_bottom - row_top + 1;
    int width  = col_bottom - col_top + 1;

    // 테두리 둘레만 임시 저장
    int perimeter = 2*(height + width - 2);
    int* temp = (int*)malloc(sizeof(int)*perimeter);

    int idx = 0;

    // top row: left → right
    for(int c = col_top; c <= col_bottom; c++)
        temp[idx++] = list[row_top][c];

    // right col: top+1 → bottom-1
    for(int r = row_top+1; r <= row_bottom-1; r++)
        temp[idx++] = list[r][col_bottom];

    // bottom row: right → left
    for(int c = col_bottom; c >= col_top; c--)
        temp[idx++] = list[row_bottom][c];

    // left col: bottom-1 → top+1
    for(int r = row_bottom-1; r >= row_top+1; r--)
        temp[idx++] = list[r][col_top];

    // rotate by 1 (반시계)
    int first = temp[0];
    memmove(temp, temp+1, sizeof(int)*(perimeter-1));
    temp[perimeter-1] = first;

    idx = 0;

    // write back
    for(int c = col_top; c <= col_bottom; c++)
        list[row_top][c] = temp[idx++];

    for(int r = row_top+1; r <= row_bottom-1; r++)
        list[r][col_bottom] = temp[idx++];

    for(int c = col_bottom; c >= col_top; c--)
        list[row_bottom][c] = temp[idx++];

    for(int r = row_bottom-1; r >= row_top+1; r--)
        list[r][col_top] = temp[idx++];

    free(temp);

    // 내부 레이어도 재귀 호출하여 회전
    rotate_list(list, row_top+1, col_top+1, row_bottom-1, col_bottom-1);
}

void rotate_layer_r_times(int** list, int row_top, int col_top, int row_bottom, int col_bottom, int r){
    if(row_top >= row_bottom || col_top >= col_bottom) return;

    int height = row_bottom - row_top + 1;
    int width  = col_bottom - col_top + 1;
    int perimeter = 2*(height + width - 2);

    int effective_r = r % perimeter;

    for(int i = 0; i < effective_r; i++)
        rotate_one_layer(list, row_top, col_top, row_bottom, col_bottom);

    // inner layer rotate
    rotate_layer_r_times(list, row_top+1, col_top+1, row_bottom-1, col_bottom-1, r);
}*/