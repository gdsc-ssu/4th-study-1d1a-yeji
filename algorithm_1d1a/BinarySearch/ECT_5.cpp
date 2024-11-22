/*
 실전 문제2: 떡볶이 떡 만들기
*/

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
