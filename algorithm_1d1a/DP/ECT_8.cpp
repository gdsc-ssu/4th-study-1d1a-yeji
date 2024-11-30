#include <iostream>

using namespace std;

int n, m;
vector<int> arr;

int main(void) {

    cin >> n >> m;
    
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        arr.push_back(x);
    }

    vector<int> d(m + 1, 10001);

    //DP 보텀업
    d[0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = arr[i]; j <= m; j++) {
            //원을 만드는 방법이 존재하는 경우
            if (d[j - arr[i]] != 10001) {
                d[j] = min(d[j], d[j - arr[i]] + 1);
            }
        }
    }

    if (d[m] == 10001) { // 최종적으로 M원을 만드는 방법이 없는 경우
        cout << -1 << '\n';
    }
    else {
        cout << d[m] << '\n';
    }
}