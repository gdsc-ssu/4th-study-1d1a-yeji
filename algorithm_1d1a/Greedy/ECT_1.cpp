/*
 예제 : 거스름돈
*/

#include <iostream>

using namespace std;

int coinType[4]={500,100,50,10};

int main(int argc, char* argv[]){

    int c,r,cnt=0;
    cin>>c;
    r=c;

    for(int i=0; i<4;i++){
        cnt+=r/coinType[i];
        r%=coinType[i];
    }

    cout<<cnt<<endl;

    return 0;
}