#include <iostream>
#define INF 1e9
using namespace std;

//노드, 간선
int n, m;
int graph[101][101];

int main(void) {
    cin >> n >> m;

    //최단 거리 테이블 초기화
    for (int i = 0; i < 101; i++) {
        fill(graph[i], graph[i] + 101, INF);
    }

    for (int a = 1; a <= n; a++) {
        for (int b = 1; b <= n; b++) {
            if (a == b) graph[a][b] = 0;
        }
    }

    //간선 값 초기화
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a][b] = 1;
        graph[b][a] = 1;
    }

    //거쳐 갈 노드 X, 최종 목적지 노드 K
    int x, k;
    cin >> x >> k;

    //플로이드 워셜 알고리즘
    for (int k = 1; k <= n; k++) {
        for (int a = 1; a <= n; a++) {
            for (int b = 1; b <= n; b++) {
                graph[a][b] = min(graph[a][b], graph[a][k] + graph[k][b]);
            }
        }
    }

    int distance = graph[1][k] + graph[k][x];

    //도달X -> -1
    if (distance >= INF) {
        cout << "-1" << '\n';
    }
    else {
        cout << distance << '\n';
    }
}
