#include <iostream>
#include <vector>

using namespace std;

int main() {
    cout << "processes and sort of resources" << endl;
    int processes, resources;
    cin >> processes >> resources;
    vector<vector<int>> max;
    vector<vector<int>> allocation;
    vector<int> available;
    vector<vector<int>> need;


    cout << "MAX: " << endl;
    for (int i = 0; i < processes; ++i) {
        vector<int> oneProcessResources;
        for (int j = 0; j < resources; ++j) {
            int num;
            cin >> num;
            oneProcessResources.push_back(num);
        }
        max.push_back(oneProcessResources);
    }
    cout << "ALLOCATION: " << endl;
    for (int i = 0; i < processes; ++i) {
        vector<int> oneProcessResources;
        for (int j = 0; j < resources; ++j) {
            int num;
            cin >> num;
            oneProcessResources.push_back(num);
        }
        allocation.push_back(oneProcessResources);
    }
    cout << "AVAILABLE" << endl;
    for (int i = 0; i < resources; ++i) {
        int n;
        cin >> n;
        available.push_back(n);
    }

    for (int i = 0; i < processes; ++i) {
        vector<int> oneProcessResources;
        oneProcessResources.reserve(resources);
        for (int j = 0; j < resources; ++j) {
            oneProcessResources.push_back(max[i][j] - allocation[i][j]);
        }
        need.push_back(oneProcessResources);
    }

    // 尝试请求
    cout << "pid and resources required" << endl;
    int pid;
    cin >> pid;
    for (int i = 0; i < resources; ++i) {
        int n;
        cin >> n;
        need[pid][i] -= n;
        available[i] -= n;
        if (need[pid][i] < 0 || available[i] < 0) {
            cout << "illegal request" << endl;
            exit(1);
        }
    }

    // 安全性检查
    // 结束条件, 本loop没有变化.
    int flag = 1;
    int n = 0;
    for (int i = 0; i < processes && flag == 1; ++i) {
        flag = 0;
        if (need[i] < available) {
            for (int j = 0; j < resources; ++j) {
                need[i][j] += available[j];
                flag = 1;
                n++;
            }
        }
    }
    if (n == processes) {
        cout << "safe";
    } else {
        cout << "danger";
    }
    return 0;
}
