// vector<int> findMedian(int n, vector<vector<int>> &edges, vector<vector<int>> &queries)
// {
    // const int LOG = 20;
    // vector<vector<pair<int, int>>> adj(n);
    // vector<vector<int>> up(n, vector<int>(LOG));
    // vector<int> depth(n, 0);
    // vector<long long> dist(n, 0); // distance from root
    // vector<int> parent(n);
    // vector<int> parentEdge(n);

//     // Build tree
    // for (auto &e : edges)
    // {
    //     int u = e[0], v = e[1], w = e[2];
    //     adj[u].push_back({v, w});
    //     adj[v].push_back({u, w});
    // }

//     function<void(int, int, int)> dfs = [&](int v, int p, int w)
//     {
//         parent[v] = p;
//         parentEdge[v] = w;
//         dist[v] = dist[p] + w;
//         up[v][0] = p;
        // for (int i = 1; i < LOG; ++i)
        //     up[v][i] = up[up[v][i - 1]][i - 1];
        // for (auto &[u, wt] : adj[v])
        // {
        //     if (u == p)
        //         continue;
        //     depth[u] = depth[v] + 1;
        //     dfs(u, v, wt);
        // }
//     };

//     dfs(0, 0, 0); // root at 0

    // auto lca = [&](int u, int v) -> int
    // {
    //     if (depth[u] < depth[v])
    //         swap(u, v);
    //     for (int i = LOG - 1; i >= 0; --i)
    //         if (depth[u] - (1 << i) >= depth[v])
    //             u = up[u][i];
    //     if (u == v)
    //         return u;
    //     for (int i = LOG - 1; i >= 0; --i)
    //         if (up[u][i] != up[v][i])
    //             u = up[u][i], v = up[v][i];
    //     return up[u][0];
    // };

    // auto get_path_nodes = [&](int u, int v) -> vector<int>
    // {
    //     int L = lca(u, v);
    //     vector<int> path_u, path_v;
    //     while (u != L)
    //     {
    //         path_u.push_back(u);
    //         u = parent[u];
    //     }
    //     path_u.push_back(L);
    //     while (v != L)
    //     {
    //         path_v.push_back(v);
    //         v = parent[v];
    //     }
    //     reverse(path_v.begin(), path_v.end());
    //     for (int node : path_v)
    //         path_u.push_back(node);
    //     return path_u;
    // };

    // auto get_prefix_weights = [&](const vector<int> &path) -> vector<long long>
    // {
    //     vector<long long> prefix(path.size(), 0);
    //     for (int i = 1; i < path.size(); ++i)
    //     {
    //         int from = path[i - 1];
    //         int to = path[i];
    //         for (auto &[nei, wt] : adj[from])
    //         {
    //             if (nei == to)
    //             {
    //                 prefix[i] = prefix[i - 1] + wt;
    //                 break;
    //             }
    //         }
    //     }
    //     return prefix;
    // };

    // vector<int> ans;
    // for (auto &q : queries)
    // {
    //     int u = q[0], v = q[1];
    //     vector<int> path = get_path_nodes(u, v);
    //     vector<long long> prefix = get_prefix_weights(path);
    //     long long total = prefix.back();
    //     long long half = (total + 1) / 2;
    //     int res = path.back(); // fallback
    //     for (int i = 0; i < prefix.size(); ++i)
    //     {
    //         if (prefix[i] >= half)
    //         {
    //             res = path[i];
    //             break;
    //         }
    //     }
    //     ans.push_back(res);
    // }

    // return ans;
// }
