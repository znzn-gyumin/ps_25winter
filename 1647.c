#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int u, v, weight;
} Edge;

int parent[100001];

int findParent(int x) {
    if (parent[x] == x) return x;
    return parent[x] = findParent(parent[x]);
}

void unite(int a, int b) {
    a = findParent(a);
    b = findParent(b);
    if (a != b) parent[b] = a;
}

int compare(const void* a, const void* b) {
    Edge* edgeA = (Edge*)a;
    Edge* edgeB = (Edge*)b;
    return edgeA->weight - edgeB->weight;
}

int main() {
    int N, M;
    if (scanf("%d %d", &N, &M) == EOF) return 0;

    Edge* edges = (Edge*)malloc(sizeof(Edge) * M);
    for (int i = 0; i < M; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].weight);
    }

    qsort(edges, M, sizeof(Edge), compare);

    for (int i = 1; i <= N; i++) {
        parent[i] = i;
    }

    long long total_cost = 0;
    int max_weight = 0;
    int edges_count = 0;

    for (int i = 0; i < M; i++) {
        if (edges_count == N - 1) break;

        int u = edges[i].u;
        int v = edges[i].v;
        int w = edges[i].weight;

        if (findParent(u) != findParent(v)) {
            unite(u, v);
            total_cost += w;
            max_weight = w; 
            edges_count++;
        }
    }

    printf("%lld\n", total_cost - max_weight);

    free(edges);
    return 0;
}
