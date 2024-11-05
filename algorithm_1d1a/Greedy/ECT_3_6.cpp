/*
 실전문제3-6 : 1이 될 때까지
*/

#include <iostream>

using namespace std;

int n, k;
int result;

int main() {

    cin >> n >> k;

    while (true) {

        int target = (n / k) * k;
        result += (n - target);
        n = target;

        // N이 K로 더 이상 나눌 수 없을 때까지
        if (n < k) break;

        result += 1;
        n /= k;
    }
    result += (n - 1);
    cout << result << '\n';
}
