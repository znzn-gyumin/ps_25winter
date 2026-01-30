# ps_25winter

## 목차
1. [week 1](#week-1)
2. [week 2](#week-2)
3. [week 3](#week-3)

### week 1

##### 2783(배열 연산)
[Baekjoon no.2783](https://www.acmicpc.net/problem/2783)
```c
int main() {
    int m = 0;
    int n = 0;
    scanf("%d %d", &m, &n);
    getchar();

    int **matrix_one = (int**)malloc(m * sizeof(int*));
    int **matrix_two = (int**)malloc(m * sizeof(int*));
    int **matrix_res = (int**)malloc(m * sizeof(int*));
    for(int i = 0; i < m; i++) matrix_one[i] = (int*)malloc(n * sizeof(int));
    for(int i = 0; i < m; i++) matrix_two[i] = (int*)malloc(n * sizeof(int));
    for(int i = 0; i < m; i++) matrix_res[i] = (int*)malloc(n * sizeof(int));
    
    for (int i = 0; i < m; i++) {
        char string[MAX_LENGTH] = "\0"; 
        fgets(string, MAX_LENGTH, stdin);
        char *ptr = strtok(string, " \n");

        int j = 0;
        while (ptr != NULL) {
            matrix_one[i][j] = atoi(ptr);
            ptr = strtok(NULL, " \n");
            j++;
        }
    }
    for (int i = 0; i < m; i++) {
        char string[MAX_LENGTH] = "\0"; 
        fgets(string, MAX_LENGTH, stdin);
        char *ptr = strtok(string, " \n"); 

        int j = 0;
        while (ptr != NULL) {
            matrix_two[i][j] = atoi(ptr);
            ptr = strtok(NULL, " \n");
            j++;
        }
    }
```
입력받은 숫자 크기의 2차원 배열을 만들고 fgets()함수로 한 행씩 입력받아 같은 위치의 숫자끼리 연산

##### 2751(정렬)
[Baekjoon no.2751](https://www.acmicpc.net/problem/2751)
```c
if(left<right){
    mid = (left+right)/2 // 중간 위치를 계산하여 리스트를 균등 분할 -분할(Divide)
    merge_sort(list, left, mid); // 앞쪽 부분 리스트 정렬 -정복(Conquer)
    merge_sort(list, mid+1, right); // 뒤쪽 부분 리스트 정렬 -정복(Conquer)
    merge(list, left, mid, right); // 정렬된 2개의 부분 배열을 합병하는 과정 -결합(Combine)
}
```

### week 2

##### 10845(큐)
[Baekjoon no.10845](https://www.acmicpc.net/problem/10845)
```c
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
```
입력받을 명령어의 수는 scanf()로, 이후 명령어들은 공백을 포함한 line 단위로 입력받기 위해 fgets()를 사용

입력받은 line에 존재하는 word 수를 count하여 이를 통해 push일지 그 외 명령어일지를 구분

strtok()을 사용하여 실제로 입력받은 명령어가 정확한지 확인하고 각 상황에 맞게끔 구현한 함수를 실행

```c
int pop(int *Q, int cnt){
    if (cnt) {
        printf("%d\n", Q[0]);
        for (int i = 0; i < cnt; i++) Q[i] = Q[i + 1];
        cnt--;
    }
    else printf("-1\n");

    return cnt;
}
```
특히 pop()의 경우, Queue의 가장 처음을 출력하고 그 다음 정수를 차례로 앞으로 한 단계씩 복사하는 과정을 반복함으로써 구현

### week 3

##### 10845(그래프)
[Baekjoon no.1647](https://www.acmicpc.net/problem/1647)
1. 크루스칼 알고리즘을 활용해서 사이클을 형성하는(=불필요한) 간선을 제외하고 모든 노드가 연결될 수 있도록 하는 간선들의 최소 비용을 출력하도록 구상
2. 구조체를 활용해서 간선의 정보를 저장하고 배열로 사이클 형성 여부를 나타내고자 함
3. 논리성 뿐만 아니라 알고리즘 시간에 학습했던 것처럼 시간복잡도 등 여러 cost 관리가 필수적
