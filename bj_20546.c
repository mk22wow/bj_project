#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct{
    int money;
    int stock;
    int price;
}total;

void init_total(total* count, int money){
    count->money = money;
    count->stock = 0;
    count->price = 0;    
}

void bnp(total* count, int stock_price[]){
    int current_stock = 0;
    int current_money = 0;
    for(int i=0; i<14; i++){
        current_stock = 0;
        if(count->money>=stock_price[i]){
            current_stock = count->money/stock_price[i];
            count->stock += current_stock;
            count->money -= current_stock * stock_price[i];
        }
        count->price = stock_price[i];
    }
    return;
}


void check_up_down(int stock_price[], int up_down[]){
    for(int i=3; i<14; i++){
        if(stock_price[i]-stock_price[i-1]>0){
            if(stock_price[i-1]-stock_price[i-2]>0){
                if(stock_price[i-2]-stock_price[i-3]>0){
                    up_down[i] = -1;
                }
            }
        }
        else if(stock_price[i]-stock_price[i-1]<0){
            if(stock_price[i-1]-stock_price[i-2]<0){
                if(stock_price[i-2]-stock_price[i-3]<0){
                    up_down[i] = 1;
                }
            }
        }
    }
}

void timing(total* count, int stock_price[], int up_down[]){
    int current_stock = 0;
    int current_money = 0;
    for(int i=0; i<14; i++){
        current_stock=0;
        if(up_down[i] == 1){
            if(count->money/stock_price[i]>=0){
                current_stock = count->money / stock_price[i];
                count->stock += current_stock;
                count->money -= current_stock * stock_price[i]; 
            }
        }
        else if(up_down[i] == -1){
            count->money += count->stock * stock_price[i];
            count->stock = 0;
        }
        count->price = stock_price[i];
    }    
}

int main(void){
    int money = 0;
    int stock_price[14];
    int up_down[14] = {0};
    total* stock_a = (total*)malloc(sizeof(total));
    total* stock_b = (total*)malloc(sizeof(total));
    
    scanf("%d", &money);
    while(getchar() != '\n');

    init_total(stock_a, money);
    init_total(stock_b, money);

    for(int i=0; i<14; i++){
        scanf("%d", &stock_price[i]);
    }

    check_up_down(stock_price, up_down);

    bnp(stock_a, stock_price);
    timing(stock_b, stock_price, up_down);

    int money_a = stock_a->money + stock_a->price * stock_a->stock;
    printf("%d %d %d\n", stock_a->money, stock_a->price, stock_a->stock);
    int money_b = stock_b->money + stock_b->price * stock_b->stock;
    printf("%d %d %d\n", stock_b->money, stock_b->price, stock_b->stock);
   
    if(money_a>money_b){
        printf("BNP\n");
    }
    else if(money_a == money_b){
        printf("SAMESAME\n");
    }
    else{
        printf("TIMING");
    }

    free(stock_a);
    free(stock_b);
    return 0;
}