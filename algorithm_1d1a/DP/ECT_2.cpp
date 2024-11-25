/*
 피보나치 수열 - 재귀 + 캐싱
*/

#include<iostream>
using namespace std;

int d[100];

int fibo(int x){

    d[1]=1,d[2]=1;
    if(d[x]!=0)return d[x];
    
    d[x]=fibo(x-1)+fibo(x-2);
    return d[x];
}

int main (void){
    int a;
    cin>>a;
    cout<<fibo(a)<<'\n';
}
/*
case0. 1,2 -> 1
case1. 이미 계산 0 -> 리스트에서 꺼내와
case2. 계산 한적 x -> 리스트에 저장
*/
