#include <stdio.h>
#include <stdlib.h>

// 간선 정보를 저장할 구조체
typedef struct {
    int u, v, weight;
} Edge;

int parent[100001];

// 유니온 파인드: Find 연산 (경로 압축)
int findParent(int x) {
    if (parent[x] == x) return x;
    return parent[x] = findParent(parent[x]);
}

// 유니온 파인드: Union 연산
void unite(int a, int b) {
    a = findParent(a);
    b = findParent(b);
    if (a != b) parent[b] = a;
}

// qsort를 위한 비교 함수 (오름차순 정렬)
int compare(const void* a, const void* b) {
    Edge* edgeA = (Edge*)a;
    Edge* edgeB = (Edge*)b;
    return edgeA->weight - edgeB->weight;
}

int main() {
    int N, M;
    // N: 집의 개수, M: 길의 개수
    if (scanf("%d %d", &N, &M) == EOF) return 0;

    // 간선 배열 동적 할당
    Edge* edges = (Edge*)malloc(sizeof(Edge) * M);
    for (int i = 0; i < M; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].weight);
    }

    // 1. 간선을 가중치 기준으로 오름차순 정렬 (qsort 사용)
    qsort(edges, M, sizeof(Edge), compare);

    // 2. 부모 테이블 초기화
    for (int i = 1; i <= N; i++) {
        parent[i] = i;
    }

    long long total_cost = 0;
    int max_weight = 0;
    int edges_count = 0;

    // 3. 크루스칼 알고리즘 수행
    for (int i = 0; i < M; i++) {
        // N-1개의 간선이 연결되면 MST가 완성됨
        if (edges_count == N - 1) break;

        int u = edges[i].u;
        int v = edges[i].v;
        int w = edges[i].weight;

        // 사이클이 발생하지 않는 경우에만(부모가 다른 경우) 연결
        if (findParent(u) != findParent(v)) {
            unite(u, v);
            total_cost += w;
            max_weight = w; // 정렬된 순서대로 추가하므로 마지막 w가 가장 큼
            edges_count++;
        }
    }

    // 4. 전체 MST 비용에서 가장 유지비가 많이 드는 마지막 간선 하나를 제거
    printf("%lld\n", total_cost - max_weight);

    free(edges);
    return 0;
}