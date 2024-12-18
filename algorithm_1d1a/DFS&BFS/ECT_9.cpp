/*
 예제9: BFS예제
*/

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

void bfs(vector<int> *graph,int start,bool *visited){
    queue<int> q;
    q.push(start);
    //현재 노드 방문 처리
    visited[start]=true;
    while(!q.empty()){
        //큐에서 하나의 원소를 뽑아 출력
        int x=q.front();
        q.pop();
        cout<<x<<' ';
        for(int i=0;i<graph[x].size();i++){
            int y=graph[x][i];
            if(!visited[y]){
                q.push(y);
                visited[y]=true;
            }
        }
    }

}

int main(void){
    bool visited[9];
    vector<int> graph[9];
    
    //노드 1에 연결된 노드 저장
    graph[1].push_back(2);
    graph[1].push_back(3);
    graph[1].push_back(8);

    //노드 2에 연결된 노드 저장
    graph[2].push_back(1);
    graph[2].push_back(7);

    //노드 3에 연결된 노드 저장
    graph[3].push_back(1);
    graph[3].push_back(4);
    graph[3].push_back(5);

    //노드 4에 연결된 노드 저장
    graph[4].push_back(3);
    graph[4].push_back(5);

    //노드 5에 연결된 노드 저장
    graph[5].push_back(3);
    graph[5].push_back(4);

    //노드 6에 연결된 노드 저장
    graph[6].push_back(7);

    //노드 7에 연결된 노드 저장
    graph[7].push_back(2);
    graph[7].push_back(6);
    graph[7].push_back(8);

    //노드 8에 연결된 노드 저장
    graph[8].push_back(1);
    graph[8].push_back(7);

    bfs(graph,1,visited);

    return 0;
}
