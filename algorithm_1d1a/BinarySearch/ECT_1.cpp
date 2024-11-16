/*
 예제1. 순차 탐색
*/

#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int sequentialSearch(int n,vector<string> list,string find){
    int cnt=1;
    for(int i=0;i<n;i++){
        if(list[i]==find)break;
        else if(i==n-1)throw runtime_error("찾고자 하는 문자열이 존재하지 않습니다."); //문자열 탐색 실패
        else cnt++;
    }
    return cnt;
}

int main(void){

    int n;
    string find;
    vector<string> words;


    cout<<"생성할 원소 개수를 입력한 다음 한 칸 띄고 찾을 문자열을 입력하세요"<<'\n';
    cin>>n>>find;
    cout<<"앞서 적은 원소 개수만큼 문자열을 입력하세요. 구분은 띄어쓰기 한 칸으로 합니다"<<'\n';

    for(int i=0;i<n;i++){
        string tmp;
        cin>>tmp;
        words.push_back(tmp);
    }

    //call by value
    cout<<sequentialSearch(n,words,find)<<'\n';

    return 0;
}
