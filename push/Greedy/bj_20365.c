#include <stdio.h>
#include <string.h>

int N, count = 1;
char str[500005];

// int main(void){
//     scanf("%d", &N);
//     scanf("%s", str);
//     int left = 0, right = N-1;
//     if(str[left]!=str[right]){
//         while(right>0 && str[left]!=str[right]){
//             right--;
//         }
//         count++;
//     }
//     while(left<right){
//         char Color = str[left];
//         while(left<=right && str[left] == Color){
//             left++;
//         }
//         while(left<=right && str[right] == Color){
//             right--;
//         }
//         if(left<=right){
//             count++;
//         }
//     }

//     printf("%d\n", count);
//     return 0;
// }

int main(void){
    scanf("%d", &N);
    int index = 0, count_B = 0, count_R = 0;
    char pred = '\0';
    for(int i=0; i<N; i++){
        char temp;
        scanf(" %c", &temp);
        if(temp != pred){
            str[index++] = temp;
            pred = temp;
            if(temp == 'B') count_B++;
            else count_R++;
        }
    }

    int Min = count_B<count_R ? count_B:count_R;
    count += Min;
    printf("%s %d\n", str, count);
    return 0;
}

