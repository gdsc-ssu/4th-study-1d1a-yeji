#include<algorithm>
#include<vector>
#include<iostream>
#define INF 1e9 //무한

using namespace std;

int n, m, start;
vector<pair<int, int> > graph[100001];
//최단 거리 테이블
int d[100001];

void dijkstra(int start) {
    priority_queue<pair<int, int> > pq;
    //시작 노드로 가기 위한 최단 경로 0
    pq.push({0, start});
    d[start] = 0;
    while (!pq.empty()) { //큐가 비어있지x
        //최단 거리 정보
        int dist = -pq.top().first;
        int now = pq.top().second; 
        pq.pop();
        //현재 노드가 처리된 적이 있는 노드라면 무시
        if (d[now] < dist) continue;
        //현재 노드와 인접한 노드들을 확인
        for (int i = 0; i < graph[now].size(); i++) {
            int cost = dist + graph[now][i].second;
            //현재 노드를 거쳐서, 다른 노드로 이동하는 거리가 더 짧은 경우
            if (cost < d[graph[now][i].first]) {
                d[graph[now][i].first] = cost;
                pq.push(make_pair(-cost, graph[now][i].first));
            }
        }
    }
}

int main(void) {
    cin >> n >> m >> start;

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        graph[a].push_back({b, c});
    }

    fill(d, d + 100001, INF);
    
    //다익스트라 알고리즘
    dijkstra(start);

    for (int i = 1; i <= n; i++) {
        if (d[i] == INF) {
            cout << "INFINITY" << '\n';
        }
        else {
            cout << d[i] << '\n';
        }
    }
}