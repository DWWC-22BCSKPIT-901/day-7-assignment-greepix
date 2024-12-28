#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <algorithm>
using namespace std;

vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
    unordered_map<string, unordered_set<string>> graph;
    unordered_map<string, string> emailToName;

    for (auto& account : accounts) {
        string name = account[0];
        for (int i = 1; i < account.size(); ++i) {
            emailToName[account[i]] = name;
            if (i > 1) {
                graph[account[i]].insert(account[i - 1]);
                graph[account[i - 1]].insert(account[i]);
            }
        }
    }

    unordered_set<string> visited;
    vector<vector<string>> result;

    for (auto& pair : emailToName) {
        string email = pair.first;
        string name = pair.second;
        if (visited.count(email)) continue;

        vector<string> merged;
        queue<string> q;
        q.push(email);
        visited.insert(email);
        while (!q.empty()) {
            string node = q.front();
            q.pop();
            merged.push_back(node);
            for (const string& neighbor : graph[node]) {
                if (!visited.count(neighbor)) {
                    visited.insert(neighbor);
                    q.push(neighbor);
                }
            }
        }
        sort(merged.begin(), merged.end());
        merged.insert(merged.begin(), name);
        result.push_back(merged);
    }

    return result;
}

int main() {
    vector<vector<string>> accounts = {
        {"John", "johnsmith@mail.com", "john00@mail.com"},
        {"John", "johnnybravo@mail.com"},
        {"John", "johnsmith@mail.com", "john_newyork@mail.com"},
        {"Mary", "mary@mail.com"}
    };
    vector<vector<string>> result = accountsMerge(accounts);
    for (auto& acc : result) {
        for (string& str : acc) cout << str << " ";
        cout << endl;
    }
    return 0;
}
