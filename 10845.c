#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10000

int push(int *Q, int X, int cnt){
    Q[cnt] = X;
    cnt++;

    return cnt;
}

int pop(int *Q, int cnt){
    if (cnt) {
        printf("%d\n", Q[0]);
        for (int i = 0; i < cnt; i++) Q[i] = Q[i + 1];
        cnt--;
    }
    else printf("-1\n");

    return cnt;
}

void size(int *Q, int cnt) {
    printf("%d\n", cnt);
}

void empty(int *Q, int cnt) {
    if (cnt) printf("0\n");
    else printf("1\n");
}

void front(int *Q, int cnt) {
    if (cnt) printf("%d\n", Q[0]);
    else printf("-1\n");
}

void back(int *Q, int cnt) {
    if (cnt) printf("%d\n", Q[cnt - 1]);
    else printf("-1\n");
}

int main() {
    int Q[MAX_SIZE];
    for (int i = 0; i < MAX_SIZE; i++) Q[i] = 0;
    int current_cnt = 0;

    int cmd_n = 0;
    scanf("%d", &cmd_n);
    getchar();

    char s[MAX_SIZE];
    for (int i = 0; i < MAX_SIZE; i++) s[i] = 0;
    int cmd_len = 0;
    int cmd_word = 0;

    for (; cmd_n > 0; cmd_n--) {
        for (int i = 0; i < MAX_SIZE; i++) s[i] = 0;
        cmd_len = 0;
        cmd_word = 0;

        fgets(s, MAX_SIZE, stdin);
        
        cmd_len = strlen(s);
        for (int i = 0; i < cmd_len; i++) {
            if(s[i] == ' ')
                cmd_word++;
            else if(s[i] == '\t')
                cmd_word++;
            else if(s[i] == '\n')
                cmd_word++;
        }

        char *ptr = strtok(s, " \t\n");
        switch (cmd_word) {
            case 1: 
                if (strcmp(ptr, "pop") == 0) {
                    current_cnt = pop(Q, current_cnt);
                }
                else if (strcmp(ptr, "size") == 0) {
                    size(Q, current_cnt);
                }
                else if (strcmp(ptr, "empty") == 0) {
                    empty(Q, current_cnt);
                }
                else if (strcmp(ptr, "front") == 0) {
                    front(Q, current_cnt);
                }
                else if (strcmp(ptr, "back") == 0) {
                    back(Q, current_cnt);
                }
                else
                    break;

            case 2:
                if (strcmp(ptr, "push") == 0) {
                    ptr = strtok(NULL, " \t\n");
                    int X = atoi(ptr);
                    current_cnt = push(Q, X, current_cnt);
                }
                else
                    break;

            default:
                break;
        }
    }
    return 0;
}