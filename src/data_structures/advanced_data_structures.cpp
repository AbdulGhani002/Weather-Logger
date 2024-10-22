#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>

class TreeNode {
public:
    int value;
    std::vector<TreeNode*> children;

    TreeNode(int val) : value(val) {}
};

class CustomTree {
public:
    CustomTree() : root(nullptr) {}

    void insert(int value) {
        if (!root) {
            root = new TreeNode(value);
        } else {
            insertHelper(root, value);
        }
    }

    void traverse() {
        if (root) {
            traverseHelper(root);
        }
    }

private:
    TreeNode* root;

    void insertHelper(TreeNode* node, int value) {
        if (value < node->value) {
            if (node->children.empty() || !node->children[0]) {
                node->children.push_back(new TreeNode(value));
            } else {
                insertHelper(node->children[0], value);
            }
        } else {
            if (node->children.size() < 2 || !node->children[1]) {
                if (node->children.size() < 2) {
                    node->children.push_back(new TreeNode(value));
                } else {
                    node->children[1] = new TreeNode(value);
                }
            } else {
                insertHelper(node->children[1], value);
            }
        }
    }

    void traverseHelper(TreeNode* node) {
        if (node) {
            traverseHelper(node->children[0]);
            std::cout << node->value << " ";
            traverseHelper(node->children[1]);
        }
    }
};

class CustomHashMap {
public:
    CustomHashMap() {}

    void insert(int key, int value) {
        hashMap[key] = value;
    }

    int get(int key) {
        return hashMap[key];
    }

private:
    std::unordered_map<int, int> hashMap;
};

class Graph {
public:
    Graph(int vertices) : vertices(vertices) {
        adjList.resize(vertices);
    }

    void addEdge(int u, int v) {
        adjList[u].push_back(v);
    }

    void bfs(int start) {
        std::vector<bool> visited(vertices, false);
        std::queue<int> q;
        visited[start] = true;
        q.push(start);

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            std::cout << node << " ";

            for (int neighbor : adjList[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
    }

    void dfs(int start) {
        std::vector<bool> visited(vertices, false);
        std::stack<int> s;
        s.push(start);

        while (!s.empty()) {
            int node = s.top();
            s.pop();

            if (!visited[node]) {
                std::cout << node << " ";
                visited[node] = true;
            }

            for (int neighbor : adjList[node]) {
                if (!visited[neighbor]) {
                    s.push(neighbor);
                }
            }
        }
    }

private:
    int vertices;
    std::vector<std::vector<int>> adjList;
};

class GeospatialIndex {
public:
    GeospatialIndex() {}

    void insert(double latitude, double longitude, int data) {
        index[std::make_pair(latitude, longitude)] = data;
    }

    int query(double latitude, double longitude) {
        return index[std::make_pair(latitude, longitude)];
    }

private:
    std::unordered_map<std::pair<double, double>, int, pair_hash> index;

    struct pair_hash {
        template <class T1, class T2>
        std::size_t operator()(const std::pair<T1, T2>& p) const {
            auto hash1 = std::hash<T1>{}(p.first);
            auto hash2 = std::hash<T2>{}(p.second);
            return hash1 ^ hash2;
        }
    };
};

class DataSorter {
public:
    DataSorter() {}

    void sort(std::vector<int>& data) {
        std::sort(data.begin(), data.end());
    }
};

class RealTimeDataProcessor {
public:
    RealTimeDataProcessor() {}

    void processData(const std::vector<int>& data) {
        for (int value : data) {
            std::cout << "Processing: " << value << std::endl;
        }
    }
};
