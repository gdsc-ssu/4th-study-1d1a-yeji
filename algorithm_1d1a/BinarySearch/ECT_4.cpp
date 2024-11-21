/*
 실전문제1. 부품 찾기
*/
//sol1: 이진 탐색
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

//sol2: set 이용
#include<vector>
#include<algorithm>
#include<iostream>

using namespace std;

int n, m;
set<int> s;
vector<int> targets;

int main(void) {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        s.insert(x);
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        int target;
        cin >> target;
        targets.push_back(target);
    }
   
    for (int i = 0; i < m; i++) {
        //부품 존재 여부 확인
        if (s.find(targets[i]) != s.end()) {
            cout << "yes" << ' ';
        }
        else {
            cout << "no" << ' ';
        }
    }
}
