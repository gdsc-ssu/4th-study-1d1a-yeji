#include <algorithm>
#include <vector>
#include <iostream>
#define INF 1e9 //경로 무한 1억으로 설정

using namespace std;

//노드의 개수(N), 간선의 개수(M), 시작 노드 번호(Start)
int n, m, start;
//연결되어 있는 노드에 대한 정보
vector<pair<int, int> > graph[100001];
//방문 체크 배열
bool visited[100001];
//최단 거리 테이블
int d[100001];

//방문하지 않은 노드 중 최단 거리가 짧은 노드의 번호를 반환
int getSmallestNode() {
    int min_value = INF;
    int index = 0;
    for (int i = 1; i <= n; i++) {
        if (d[i] < min_value && !visited[i]) {
            min_value = d[i];
            index = i;
        }
    }
    return index;
}

void dijkstra(int start) {

    d[start] = 0;
    visited[start] = true;
    for (int j = 0; j < graph[start].size(); j++) {
        d[graph[start][j].first] = graph[start][j].second;
    }
    //시작 노드를 제외한 전체 n - 1개의 노드에 대해 반복
    for (int i = 0; i < n - 1; i++) {
        int now = getSmallestNode();
        visited[now] = true;
        for (int j = 0; j < graph[now].size(); j++) {
            int cost = d[now] + graph[now][j].second;
            //현재 노드-> 다른 노드로 이동하는 거리가 더 짧은 경우
            if (cost < d[graph[now][j].first]) {
                d[graph[now][j].first] = cost;
            }
        }
    }
}

int main(void) {
    cin >> n >> m >> start;

    //모든 간선 정보를 입력받기
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        //a번 노드에서 b번 노드로 가는 비용이 c
        graph[a].push_back({b, c});
    }

    fill_n(d, 100001, INF);
    
    dijkstra(start);

    //모든 노드로 가기 위한 최단 거리를 출력
    for (int i = 1; i <= n; i++) {
        //도달할 수 없는 경우, 무한(INFINITY)이라고 출력
        if (d[i] == INF) {
            cout << "INFINITY" << '\n';
        }
        //도달할 수 있는 경우 거리를 출력
        else {
            cout << d[i] << '\n';
        }
    }
}
