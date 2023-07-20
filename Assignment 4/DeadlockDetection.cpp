#include <bits/stdc++.h>
using namespace std;

#define vb vector<bool>
vector<vector<int>> graph;
vector<bool> visited, state;
int cycles = 0;
bool dfs(int v)
{
    if (!visited[v])
    {
        visited[v] = true;
        state[v] = true;

        for (int i = 0; i < graph.size(); i++)
        {
            if (graph[v][i])
            {
                if (!visited[i] && dfs(i))
                    return true;
                else if (state[i])
                    return true;
            }
        }
    }

    return state[v] = false;
}

void getCycle()
{
    int n = graph.size();
    visited = vector<bool>(n, false);
    state   = visited;

    for (int i = 0; i < n; i++)
       cycles += ( dfs(i) ?  1 : 0 );

}

int main()
{
    // RAG
    vector<vector<int>> resource = {
        {0, 0, 1, 0},
        {1, 0, 0, 0},
        {0, 1, 0, 1},
        {1, 0, 0, 0}};
    graph = resource;
    getCycle();
    cout << "Total Cycle      : " << cycles << endl;
    if (cycles)
        cout << "Deadlock detected!" << endl;
    else
        cout << "No deadlock." << endl;

    return 0;
}
