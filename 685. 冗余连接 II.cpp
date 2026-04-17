//
// Created by Ruizhe Hou on 2020/9/17.
//
#include <iostream>
#include <vector>

using namespace std;


// 第一种解法
//class Solution {
//    int n;
//    vector<int> fa;
//
//    int find(int x) {
//        return fa[x] == x ? x : fa[x] = find(fa[x]);
//    }
//
//    bool helper(vector<vector<int>> &edges, int except) {
//        for (int i = 1; i <= n; i++) fa[i] = i;
//        int cnt = n;
//        for (int i = 0; i < n; i++) {
//            if (i == except) continue;
//            int fx = find(edges[i][0]), fy = find(edges[i][1]);
//            if (fx != fy) {
//                cnt--;
//                fa[fy] = fx;
//            }
//        }
//        return cnt == 1;
//    }
//
//public:
//    vector<int> findRedundantDirectedConnection(vector<vector<int>> &edges) {
//        n = edges.size();
//        fa.resize(n + 1);
//        vector<int> degree(n + 1);
//        for (auto &v:edges) {
//            degree[v[1]]++;
//        }
//        for (int i = n - 1; i >= 0; i--) {
//            if (degree[edges[i][1]] == 2) {
//                if (helper(edges, i)) return edges[i];
//            }
//        }
//
//        for (int i = n - 1; i >= 0; i--) {
//            if (degree[edges[i][1]] == 1) {
//                if (helper(edges, i)) return edges[i];
//            }
//        }
//        return {};
//    }
//};

// 第二种解法
struct UnionFind {
    vector<int> ancestor;

    UnionFind(int n) {
        ancestor.resize(n);
        for (int i = 0; i < n; ++i) {
            ancestor[i] = i;
        }
    }

    int find(int index) {
        return index == ancestor[index] ? index : ancestor[index] = find(ancestor[index]);
    }

    void merge(int u, int v) {
        ancestor[find(u)] = find(v);
    }
};

class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>> &edges) {
        int nodesCount = edges.size();
        UnionFind uf = UnionFind(nodesCount + 1);
        auto parent = vector<int>(nodesCount + 1);
        for (int i = 1; i <= nodesCount; ++i) {
            parent[i] = i;
        }
        int conflict = -1;
        int cycle = -1;
        for (int i = 0; i < nodesCount; ++i) {
            auto edge = edges[i];
            int node1 = edge[0], node2 = edge[1];
            if (parent[node2] != node2) {
                conflict = i;
            } else {
                parent[node2] = node1;
                if (uf.find(node1) == uf.find(node2)) {
                    cycle = i;
                } else {
                    uf.merge(node1, node2);
                }
            }
        }
        if (conflict < 0) {
            auto redundant = vector<int>{edges[cycle][0], edges[cycle][1]};
            return redundant;
        } else {
            auto conflictEdge = edges[conflict];
            if (cycle >= 0) {
                auto redundant = vector<int>{parent[conflictEdge[1]], conflictEdge[1]};
                return redundant;
            } else {
                auto redundant = vector<int>{conflictEdge[0], conflictEdge[1]};
                return redundant;
            }
        }
    }
};

int main() {
    Solution sol;
    vector<vector<int>> edges1 = {{1, 2}, {1, 3}, {2, 3}};
    auto r1 = sol.findRedundantDirectedConnection(edges1);
    cout << r1[0] << " " << r1[1] << endl; // 2 3
    vector<vector<int>> edges2 = {{1, 2}, {2, 3}, {3, 4}, {4, 1}, {1, 5}};
    auto r2 = sol.findRedundantDirectedConnection(edges2);
    cout << r2[0] << " " << r2[1] << endl; // 4 1
    return 0;
}
