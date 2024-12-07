#include <algorithm>
#include <vector>
#include <iostream>
#define INF 1e9 

using namespace std;

int n, m, start;
vector<pair<int, int> > graph[30001];
//최단 거리 테이블
int d[30001];

void dijkstra(int start) {
    priority_queue<pair<int, int> > pq;
    //시작 노드로 가기 위한 최단 경로는 0 큐에 삽입
    pq.push({0, start});
    d[start] = 0;
    while (!pq.empty()) { //큐가 비어있지 않다면
        //최단 거리가 가장 짧은 노드에 대한 정보
        int dist = -pq.top().first; //비용 
        int now = pq.top().second; 
        pq.pop();

        if (d[now] < dist) continue;
        //현재 노드와 연결된 다른 노드들을 확인
        for (int i = 0; i < graph[now].size(); i++) {
            int cost = dist + graph[now][i].second;
            if (cost < d[graph[now][i].first]) {
                d[graph[now][i].first] = cost;
                pq.push(make_pair(-cost, graph[now][i].first));
            }
        }
    }
}