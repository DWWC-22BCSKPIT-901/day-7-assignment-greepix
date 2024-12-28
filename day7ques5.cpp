#include <iostream>
#include <vector>
#include <queue>
#include <algorithm> 
#include <climits>
using namespace std;

int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    vector<vector<pair<int, int>>> graph(n + 1);
    for (auto& time : times)
        graph[time[0]].emplace_back(time[1], time[2]);

    vector<int> dist(n + 1, INT_MAX);
    dist[k] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push(make_pair(0, k));

    while (!pq.empty()) {
        pair<int, int> front = pq.top();
        pq.pop();
        int time = front.first;
        int node = front.second;

        if (time > dist[node]) continue;

        for (auto& edge : graph[node]) {
            int neighbor = edge.first;
            int weight = edge.second;
            if (dist[neighbor] > dist[node] + weight) {
                dist[neighbor] = dist[node] + weight;
                pq.push(make_pair(dist[neighbor], neighbor));
            }
        }
    }

    int maxDist = *max_element(dist.begin() + 1, dist.end());
    return maxDist == INT_MAX ? -1 : maxDist;
}

int main() {
    vector<vector<int>> times = {{2, 1, 1}, {2, 3, 1}, {3, 4, 1}};
    int n = 4, k = 2;
    cout << networkDelayTime(times, n, k) << endl;
    return 0;
}
