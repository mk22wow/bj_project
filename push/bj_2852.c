#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_TIME 4800

typedef struct Node{
    int team;
    int time;
    struct Node* next;
}Node;

typedef struct HeadNode{
    int team1;
    int team2;
    int win_team1;
    int win_team2;
    int time;
    struct Node* next;
}HeadNode;

int calculate_time(int time1, int time2, char c){
    int min_1 = time1/100;
    int min_2 = time2/100;
    int sec_1 = time1%100;
    int sec_2 = time2%100;
    int result = 0;
    if(c == '-'){
        int temp_sec = sec_2 - sec_1;
        if(temp_sec<0){
            result = (min_2-min_1-1)*100;
            result += 60+temp_sec;
        }
        else{
            result = (min_2-min_1)*100;
            result += temp_sec;
        }
        return result;
    }
    else{
        int temp_sec = sec_1 + sec_2;
        if(temp_sec>=60){
            result = (min_1+min_2+1)*100;
            result += temp_sec-60;
        }
        else{
            result = (min_1+min_2)*100;
            result += temp_sec;
        }
        return result;
    }
}

HeadNode* createHeadNode(){
    HeadNode* newNode = (HeadNode*)malloc(sizeof(HeadNode));
    newNode->team1 = 0;
    newNode->team2 = 0;
    newNode->win_team1 = 0;
    newNode->win_team2 = 0;
    newNode->time = 0;
    newNode->next = NULL;
    return newNode;
}

Node* createNode(int list[]){
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL){
        return NULL;
    }
    newNode->team = list[0];
    newNode->time = list[1]*100 + list[2];
    newNode->next = NULL;
    return newNode;
}

void check_time(HeadNode* total, int list[]){
    Node* newNode = createNode(list);

    if(total->next == NULL){
        total->next = newNode;
        total->time = newNode->time;
        if(newNode->team == 1){
        total->team1++;
        }
        else{
            total->team2++;
        }
        return;
    }
    else{
        Node* temp = total->next;
        while(temp->next!=NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }


    if(total->team1>total->team2){
        int time = calculate_time(total->time, newNode->time, '-');
        total->win_team1 = calculate_time(time, total->win_team1,'+');
    }
    else if(total->team1<total->team2){
        int time = calculate_time(total->time, newNode->time, '-');
        total->win_team2 = calculate_time(time, total->win_team2,'+');
    }
    if(newNode->team == 1){
        total->team1++;
    }
    else{
        total->team2++;
    }

    total->time = newNode->time;
}

void last_check(HeadNode* total){
    if(total->team1>total->team2){
        int time = calculate_time(total->time, MAX_TIME, '-');
        total->win_team1 = calculate_time(time, total->win_team1,'+');
    }
    else if(total->team1<total->team2){
        int time = calculate_time(total->time, MAX_TIME, '-');
        total->win_team2 = calculate_time(time, total->win_team2,'+');
    }
    total->time = MAX_TIME;
}

void token_input(HeadNode* total, char* str, int list[]){
    char* token;
    int n = 0;
    token = strtok(str, " :");
    while(token!=NULL){
        list[n++] = atoi(token);
        token = strtok(NULL, " :");
    }
    check_time(total, list);
}

int main(void){
    int i = 0, count = 0;
    scanf("%d", &count);
    while(getchar()!='\n');
    HeadNode* total = createHeadNode();
    while(i<count){
        char str[10];
        int list[3] = {0};
        if(fgets(str,9, stdin) == NULL){
            return 0;
        }
        str[strcspn(str, "\n")] = '\0';
        token_input(total, str, list);
        i++;
    }
    last_check(total);

    printf("%02d:%02d\n",total->win_team1/100, total->win_team1%100);
    printf("%02d:%02d\n",total->win_team2/100, total->win_team2%100);
    return 0;
}