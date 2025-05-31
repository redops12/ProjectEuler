#pragma once
#include <map>
#include <vector>

class Node {
public:
    int weight;
    std::vector<int> adjacency;
    Node();
    Node(int weight, std::vector<int> adjacency);
};

int shortest_path(const std::map<int, Node> &graph, int src, int dst);
