/*#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(void){
    int i = 0, times = 0;
    scanf("%d", &times);
    while(i<times){
        int members = 0;
        int team[200] = {0};
        int team_score[200] = {0};
        int member_rank[1000] = {0};
        scanf("%d", &members);
        while(getchar()!='\n');

        char str[220002];
        fgets(str, 220000, stdin);
        str[strcspn(str, "\n")] = '\0';
        //printf("%s\n",str);
        int j = 0, z = 0;
        while(j<strlen(str)){
            char* number = (char*)malloc(4);
            int k = 0;
            while(str[j] != '\0' && str[j] != ' '){
                    number[k] = str[j];
                    j++;
                    k++;
            }
            j++;
            number[k] = '\0';
            int member_num = atoi(number);
            team[member_num-1]++;
            member_rank[z++] = member_num-1;
            //printf("%d %d\n", member_num,team[member_num]);
            free(number);
        }

        j=0, z=0;
        int score = 1;
        int team_count[200] = {0};
        while(j<members){
            int temp = member_rank[j];
            //printf("%d %d %d\n", j, temp, team[temp]);
            if(team[temp] == 6){
                if(team_count[temp]<4){
                    team_score[temp] += score;
                    team_count[temp]++;
                }
                score++;
               
            }
            j++;
        }
        int min = 0, repeat = 0;
        while(z<members){
            if(team_score[z] != 0 ){
                if(min == 0){
                    min = team_score[z];    
                }
                else if(team_score[z] < min){
                    min = team_score[z];
                    repeat = 0;
                }
                else if(team_score[z] == min){
                    repeat++;
                }
            }
            z++;
        }

        int index_team = 0, index_score = 0, min_score = 0;
        j = 0, z = 0;
        if(repeat>0){
            while(z<members){
                int temp = 0, index = 0;
                if(team_score[z] == min){
                    index = member_rank[z];
                    for(j=0; j<members; j++){
                        if(member_rank[j] == index){
                            temp++;
                            if(temp == 5){
                                break;
                            }
                        }
                    }
                    if(min_score == 0){
                        min_score = j;
                    }
                    else if(j<min_score){
                        min_score = j;
                    }
                }
                z++;
            }
            printf("%d\n", member_rank[min_score]+1);
        }
        else{
            while(z<members){
                if(team_score[z] == min){
                    int index = member_rank[z];
                    printf("%d\n", index+1);
                    break;
                }
                z++;
            }
        }
        i++;
    }
    return 0;
}*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_SIZE 200002
#define MAX_TEAM_SIZE 200

typedef struct Node{
    int member_score;
    struct Node* next;
}Node;

typedef struct HeadNode {
    int team_member;
    int team_score;
    int fifth_score;
    struct Node* next;
}HeadNode;

HeadNode* create_headNode(int num){
    HeadNode* newNode = (HeadNode*)malloc(sizeof(HeadNode));
    if(newNode == NULL){
        return NULL;
    }
    newNode->team_member++;
    newNode->team_score = 0;
    newNode->fifth_score = 0;
    newNode->next = NULL;
    return newNode;
}

void insert_headNode(HeadNode** list){
    for(int i=0; i<MAX_TEAM_SIZE; i++){
        HeadNode* newNode = (HeadNode*)malloc(sizeof(HeadNode));
        if(newNode == NULL){
            return;
        }
        newNode->team_member = 0;
        newNode->team_score = 0;
        newNode->fifth_score = 0;
        newNode->next = NULL;
        list[i] = newNode;
    }
}

void insert_team(HeadNode** list, char** str, int members){
    for(int i=0; i<members; i++){
        int num = atoi(str[i]);
        list[num-1]->team_member++;
    }
}

Node* createNode(int rank){
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL){
        return NULL;
    }
    newNode->member_score = rank;
    newNode->next = NULL;
    return newNode;
}

void insertNode(HeadNode* list, int rank){
    Node* newNode = createNode(rank);
    if(list->next == NULL){
        list->next = newNode;
        list->team_score += newNode->member_score;
    }
    else{
        Node* temp = list->next;
        int num = 2;
        while(temp->next != NULL){
            temp = temp->next;
            num++;
        }
        temp->next = newNode;
        if(num<5){
            list->team_score += newNode->member_score;
        }
        else if(num == 5){
            list->fifth_score = newNode->member_score;
        }
    }
}

void insert_member(HeadNode** list, char** str, int members){
    int rank = 1;
    for(int i=0; i<members; i++){
        int num = atoi(str[i]);
        if(list[num-1]->team_member == 6){
            insertNode(list[num-1], rank);
            rank++;
        }
    }
}

void insert_score(HeadNode** list, char* input, char** str, int members){
    int i = 0, j = 0;
    int len = strlen(input);
    // while(i<len){
    //     int k = 0;
    //     while(isdigit(input[i]) && k<4){
    //         str[j][k] = input[i];
    //         k++;
    //         i++;
    //     }
    //     str[j][k] = '\0';
    //     j++;
    //     i++;
    // }

    const char delim[] = " ";
    char* token;
    token = strtok(input, delim);
    int z=0;
    while(token!=NULL){
        strcpy(str[z], token);
        z++;
        token = strtok(NULL, delim);
    }
    insert_team(list, str, members);
    insert_member(list, str, members);
}

void create_str(char** str, int members){
    for(int i=0; i<members; i++){
        str[i] = (char*)malloc(4);
    }
}

void check_victory(HeadNode** list, int members){
    int min_score = 0, fifth_score = 0;
    int victory = -1;

    for(int i=0; i<MAX_TEAM_SIZE; i++){
        if(list[i]->team_member==6){
            if(min_score == 0){
                min_score = list[i]->team_score;
                fifth_score = list[i]->fifth_score;
                victory = i;
                continue;
            }
            
            if(list[i]->team_score<min_score){
                min_score = list[i]->team_score;
                fifth_score = list[i]->fifth_score;
                victory = i;
            }
            else if(list[i]->team_score==min_score && list[i]->fifth_score<fifth_score){
                min_score = list[i]->team_score;
                fifth_score = list[i]->fifth_score;
                victory = i;
            }
        }
    }
    printf("%d\n", victory+1);
}

void free_str(char** str, int members){
    for(int i=0; i<members; i++){
        free(str[i]);
    }
    free(str);
}

void free_headNode(HeadNode** list){
    for(int i=0; i<MAX_TEAM_SIZE; i++){
        if(list[i] != NULL){
            Node* temp = list[i]->next;
            Node* nextNode;
            while(temp != NULL){
                nextNode = temp->next;
                free(temp);
                temp = nextNode;
            }
            free(list[i]);
            list[i] = NULL;
        }
    }
    free(list);
}

int main(void){
    int i = 0, times = 0;
    scanf("%d", &times);
    while(getchar() != '\n');
    while(i<times){
        int members;
        scanf("%d",&members);
        while(getchar()!='\n');

        HeadNode** list = (HeadNode**)malloc(MAX_TEAM_SIZE*sizeof(HeadNode*));
        insert_headNode(list);
        char* input = (char*)malloc(MAX_SIZE);
        char** str = (char**)malloc(members*sizeof(char*));
        create_str(str, members);

        if(fgets(input,MAX_SIZE, stdin) == NULL){
            printf("wrong input");
            break;
        }
        input[strcspn(input,"\n")] = '\0';
        insert_score(list, input, str, members);

        // for(int z =0; z<MAX_TEAM_SIZE; z++){
        //     if(list[z]->team_member == 6){
        //         printf("%d %d %d\n",z+1,list[z]->team_score, list[z]->fifth_score);
        //     }
        // }
        check_victory(list, members);
        free(input);
        free_str(str, members);
        free_headNode(list);
        list = NULL;
        i++;
    }
}