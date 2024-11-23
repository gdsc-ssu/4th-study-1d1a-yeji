/*
 실전 문제2: 떡볶이 떡 만들기
*/
//sol0. 순차 탐색
//높이가 최대 10억 정수까지 -> 순차 탐색은 시간 초과 발생
/*
#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;

int main(void){
    int n,m,length; //떡의 개수, 길이
    int totalServe=0;
    vector<int> arr;
    cin>>n>>m;

    for(int i=0;i<n;i++){
        int tmp;
        cin>>tmp;
        arr.push_back(tmp);
    }

    length=*max_element(arr.begin(),arr.end());

    int tmp,add;
    while(totalServe<m){

        totalServe=0;
        length--;
        for(int j=0;j<arr.size();j++){
        add=arr[j]-length;
        if(add>0)totalServe+=add;
        }
    }

    cout<<length<<'\n';

    return 0;
}
*/
/*
 note:
    시간 복잡도: 최악의 경우 O(N^2)
    - *max_element(v.begin(), v.end())
*/
/*
 1. 절단기 높이를 가장 긴 떡의 길이에 맞춘다
 2. 절단기 길이 1씩 줄여가며 떡 수집
 3. 손님이 요구한 총합 길이 이상 되면 멈춤
*/


//sol1. 파라메트릭 서치
#include<algorithm>
#include<vector>
#include<iostream>

using namespace std;

int main(void){
    int n,m,length; //떡의 개수, 길이
    vector<int> arr;
    cin>>n>>m;

    for(int i=0;i<n;i++){
        int tmp;
        cin>>tmp;
        arr.push_back(tmp);
    }

    int start=0;
    int end=*max_element(arr.begin(),arr.end());
    long long int total;
    int length;
    while(start<=end){ //왜 조건이 이럴까
        total=0;
        int middle=(start+end)/2;
        for(int j=0;j<n;j++){
            if(arr[j]>middle)total+=(arr[j]-middle);
        }
        if(total<m){//떡 적음-> 절단기 줄이기
            end=middle-1;
        }
        else{//떡 충분-> 절단기 늘리기
            length=middle;//절단기 최대길이 이므로 기록
            start=middle+1;
        
        }

    }

    cout<<length<<'\n';
    
    return 0;
}
