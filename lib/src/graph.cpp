#include "graph.h"
#include <queue>
#include <unordered_map>
#include <set>
#include <climits>

using namespace std;

Node::Node() {}
Node::Node(int weight, std::vector<int> adjacency):weight(weight), adjacency(adjacency) {}

int shortest_path(const std::map<int, Node> &graph, int src, int dst) {
    priority_queue<pair<unsigned int, int>, vector<pair<unsigned int, int>>, greater<pair<unsigned int, int>>> visitable;
    unordered_map<int, unsigned int> shortest_dist;
    set<int> visited;

    for (auto p : graph) {
        shortest_dist[p.first] = UINT_MAX;
    }

    visitable.push(make_pair(graph.at(src).weight, src));

    while (!visitable.empty()) {
        auto p = visitable.top();
        visitable.pop();
        if (visited.find(p.second) != visited.end()) {
            continue;
        }
        visited.insert(p.second);
        shortest_dist[p.second] = p.first;
        for (int id : graph.at(p.second).adjacency) {
            visitable.push(make_pair(p.first + graph.at(id).weight, id));
        }
    }
    return shortest_dist[dst];
}
