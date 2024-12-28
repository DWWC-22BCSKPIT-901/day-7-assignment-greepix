#include <iostream>
#include <vector>
using namespace std;

void dfs(int node, vector<vector<int>>& graph, vector<int>& path, vector<vector<int>>& result) {
    path.push_back(node);
    if (node == graph.size() - 1) {
        result.push_back(path);
    } else {
        for (int neighbor : graph[node]) {
            dfs(neighbor, graph, path, result);
        }
    }
    path.pop_back();
}

vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
    vector<vector<int>> result;
    vector<int> path;
    dfs(0, graph, path, result);
    return result;
}

int main() {
    vector<vector<int>> graph = {{1, 2}, {3}, {3}, {}};
    vector<vector<int>> result = allPathsSourceTarget(graph);
    for (const auto& path : result) {
        for (int node : path) {
            cout << node << " ";
        }
        cout << endl;
    }
    return 0;
}
