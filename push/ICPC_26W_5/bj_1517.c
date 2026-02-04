#include <stdio.h>

#define MAXN 500005

int N;
long long count = 0;
int list[MAXN];
int temp_list[MAXN];

void merge(int arr[], int left, int mid, int right){
    int i=left;
    int j=mid+1;
    int idx=left;

    while(i<=mid && j<=right){
        if(arr[i]>arr[j]){
            count += (long long)(mid-i+1);
            temp_list[idx++] = arr[j++];
        }
        else{
            temp_list[idx++] = arr[i++];
        }
    }

    while(j<=right){
        temp_list[idx++] = arr[j++];
    }
    while(i<=mid){
        temp_list[idx++] = arr[i++];
    }

    for(int k=left; k<=right; k++){
        arr[k] = temp_list[k];
    }
}

void merge_sort(int arr[], int left, int right){
    if(left<right){
        int mid = (left+right)/2;

        merge_sort(arr, left, mid);
        merge_sort(arr, mid+1, right);

        merge(arr, left, mid, right);
    }
}

int main(void){
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        scanf("%d", &list[i]);
    }

    merge_sort(list, 0, N-1);

    printf("%lld\n", count);
    return 0;
}