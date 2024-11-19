/*
 실전문제1
*/

#include<vector>
#include<algorithm>
#include<iostram>
using namespace std;

int binarySearch(vector<int>& arr, int target, int start, int end) {
    while (start <= end) {
        int mid = (start + end) / 2;
        if (arr[mid] == target) return mid;
        else if (arr[mid] > target) end = mid - 1;
        else start = mid + 1; 
    }
    return -1;
}

int n, m;
vector<int> arr;
vector<int> target;

int main(void) {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        arr.push_back(x);
    }
    
    sort(arr.begin(), arr.end());
    
    cin >> m;
    for (int i = 0; i < m; i++) {
        int target;
        cin >> target;
        target.push_back(target);
    }

    for (int i = 0; i < m; i++) {
        //해당 부품 확인
        int result = binarySearch(arr, targets[i], 0, n - 1);
        if (result != -1) {
            cout << "yes" << ' ';
        }
        else {
            cout << "no" << ' ';
        }
    }
}