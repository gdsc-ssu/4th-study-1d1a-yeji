/*
 실전 문제1: 왕실의 나이트
*/

#include<iostream>
#include<utility>

using namespace std;

int cnt,x,y;
pair<int,int> moveType[]={
    {2, 1}, {2, -1}, {1, 2}, {-1, 2},
    {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}
};

bool isInRange(int a, int b){
    if(a<8&&a>=0&&b<8&&b>=0) return true;
    else return false;
}

int main(void){
    char x_c;
    int check_x=x, check_y=y;
    cnt=0;

    cin>>x_c>>y; //x_아스키코드로 저장
    x=x_c-97; //with 자동 캐스팅
              //입력과 동시에 캐스팅은 안됨 _ 잘못된 값 저장


    for(int i=0;i<8;i++){
        check_x-=moveType[i].first;
        check_y+=moveType[i].second;
        if(isInRange(check_x,check_y)==true)cnt++;

        check_x=0;
        check_y=0;
    }

    cout<<cnt<<'\n';

    return 0;
}

/*
notice
- 경우의 수 적을 경우, 직접 작성할 가능성 생각하자
- 빨리 정하고 밀고 나가기.. 고민하다가 시간 다 가겠다

시간 복잡도
- O(1)
*/
