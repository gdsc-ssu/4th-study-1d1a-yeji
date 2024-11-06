/*
 예제1: 상하좌우
*/

#include <iostream>

using namespace std;

//L,R,U,D 따른 좌표 이동
int dx[4]={-1,1,0,0};
int dy[4]={0,0,1,-1};
char type[4]={'L','R','U','D'};

int main(void){

    int n;
    string plan;
    int x=1,y=1; //위치 좌표
    char move; //이동

    cin>> n;
    cin.ignore(); //버퍼 비우기
    getline(cin,plan);

    for(int i=0;i<plan.size();i++){
        int tmp_x,tmp_y;
        move=plan[i];
        for(int j=0;j<4;j++){
            if(move==type[j]){
                tmp_x=x+dx[j];
                tmp_y=y+dy[j];
            }
        }
        if(tmp_x<1||tmp_x>n||tmp_y<1||tmp_y>n) continue; //범위 벗어날 시 이동 무시

        x=tmp_x;
        y=tmp_y;
    }

    cout<<x<<' '<<y<<'\n';
    return 0;
}
