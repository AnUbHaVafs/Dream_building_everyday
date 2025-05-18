#include <bits/stdc++.h>
using namespace std;

vector<string> parseInput(const string &input)
{
    vector<string> result;
    string temp;
    bool inString = false;

    for (char c : input)
    {
        if (c == '"')
        {
            if (inString)
            {   
                result.push_back(temp);
                temp.clear();
                inString = false;
            }
            else
            {
                inString = true;
            }
        }
        else if (inString)
        {
            temp += c;
        }
    }
    return result;
}

// Custom struct for state
struct State
{
    int dist, x, y, portal_mask;
    State(int d, int i, int j, int pm) : dist(d), x(i), y(j), portal_mask(pm) {}
};

// Comparator for priority queue
struct Compare
{
    bool operator()(const State &a, const State &b)
    {
        return a.dist > b.dist; // min-heap
    }
};

int minMovesToReachEnd(vector<string> &matrix)
{
    int m = matrix.size();
    int n = matrix[0].size();
    vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    unordered_map<char, vector<pair<int, int>>> portals;

    // Build portal map
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            if (isupper(matrix[i][j]))
                portals[matrix[i][j]].push_back(make_pair(i, j));

    // Visited: (x, y, bitmask of used portals)
    set<tuple<int, int, int>> visited;
    priority_queue<State, vector<State>, Compare> pq;

    pq.push(State(0, 0, 0, 0));
    visited.insert(make_tuple(0, 0, 0));

    while (!pq.empty())
    {
        State cur = pq.top();
        pq.pop();
        int x = cur.x, y = cur.y, d = cur.dist, mask = cur.portal_mask;

        if (x == m - 1 && y == n - 1)
            return d;

        char cell = matrix[x][y];
        // Try teleport
        if (isupper(cell))
        {
            int bit = cell - 'A';
            if (((mask >> bit) & 1) == 0)
            {
                int new_mask = mask | (1 << bit);
                vector<pair<int, int>> &locs = portals[cell];
                for (int i = 0; i < locs.size(); ++i)
                {
                    int tx = locs[i].first, ty = locs[i].second;
                    if (tx == x && ty == y)
                        continue;
                    if (!visited.count(make_tuple(tx, ty, new_mask)))
                    {
                        visited.insert(make_tuple(tx, ty, new_mask));
                        pq.push(State(d, tx, ty, new_mask)); // teleport is free
                    }
                }
            }
        }

        // Normal directions
        for (int i = 0; i < 4; ++i)
        {
            int nx = x + dirs[i].first;
            int ny = y + dirs[i].second;

            if (nx < 0 || ny < 0 || nx >= m || ny >= n)
                continue;
            if (matrix[nx][ny] == '#')
                continue;

            if (!visited.count(make_tuple(nx, ny, mask)))
            {
                visited.insert(make_tuple(nx, ny, mask));
                pq.push(State(d + 1, nx, ny, mask));
            }
        }
    }

    return -1;
}

int main()
{
    string input_line;
    getline(cin, input_line);
    vector<string> matrix = parseInput(input_line);
    int result = minMovesToReachEnd(matrix);
    cout << result << "\n";
    return 0;
}
