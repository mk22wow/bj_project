/*#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


void count_list(int** list, int h, int w) {
	int index_l, index_r;
	int count = 0, col = 0;
	for (int i = 0; i < h; i++) {
		col = 0;
		while (col < w) {
			if (list[i][col] == 1) {
				index_l = col;
				index_r = col+1;
				//printf("%d %d\n", index_l, index_r);
				while (index_r < w) {
					if (list[i][index_r] == 1) {
						//printf("%d %d\n", index_l, index_r);
						break;
					}
					index_r++;
				}
				if (index_r != w) {
					count += (index_r - index_l - 1);
					col = index_r;
					continue;
				}
			}
			col++;
		}
	}
	printf("%d\n", count);
}

void print_list(int** list, int h, int w) {
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			printf("%d ", list[i][j]);
		}
		printf("\n");
	}
}

void free_list(int** list, int h, int w) {
	for (int i = 0; i < h; i++) {
		free(list[i]);
	}
	free(list);
}

int main(void) {
	int h, w;
	scanf("%d %d", &h, &w);
	if ((h < 1 || h>500) || (w < 1 || h>500)) {
		printf("wrong input");
		return 0;
	}
	int** list = (int**)malloc(h * sizeof(int*));
	if (list == NULL) {
		return 0;
	}
	for (int i = 0; i < h; i++) {
		list[i] = (int*)calloc(w, w * sizeof(int));
		if (list[i] == NULL) {
			for (int j = 0; j < i; j++) {
				free(list[j]);
			}
			free(list);
			return 0;
		}
	}

	for (int i = 0; i < w; i++) {
		int input;
		scanf("%d", &input);
		if (input < 0 || input > h) {
			printf("wrong input");
			free_list(list, h, w);
			return 0;
		}
		for (int j = 0; j < input; j++) {
			list[h-j-1][i] = 1;
		}
	}

	//print_list(list, h, w);
	count_list(list, h, w);
	free_list(list, h, w);
	return 0;
}*/