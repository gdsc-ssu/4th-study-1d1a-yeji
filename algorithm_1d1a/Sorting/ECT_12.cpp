/*
 실전문제 3
*/
#include<iostream>
#include<vector>
using namespace std;

int n, k;
vector<int> a, b;

bool compare(int x, int y) {
    return x > y;
}

int main(void) {

    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a.push_back(x);
    }

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        b.push_back(x);
    }
    //배열 A 오름차순 정렬
    sort(a.begin(), a.end());
    //배열 B 내림차순 정렬 
    sort(b.begin(), b.end(), compare);

    //두 배열의 원소 최대 K번 비교 
    for (int i = 0; i < k; i++) {
        if (a[i] < b[i]) swap(a[i], b[i]); // 두 원소를 교체
        else break;
    }

    long long result = 0;
    for (int i = 0; i < n; i++) {
        result += a[i];
    }
    cout << result << '\n';
}
