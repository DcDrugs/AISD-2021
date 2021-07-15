#include <iostream>
#include <vector> 
#include <list> 
#include <unordered_set>

using namespace std;

struct Edge
{
    int index; 
    list<vector<Edge>::iterator> friends;
    bool isUsed = false;
    int parent = -1;
};

void _dfs(Edge &edge, int index, bool type)
{
    if (edge.friends.size() != 0)
        edge.parent = index;

    edge.isUsed = !type;

    for (auto item : edge.friends)
    {
        if (item->isUsed == type)
        {
            item->parent = index;
            _dfs(*(item), index, type);
        }
    }
}

void dfs(Edge &edge)
{
    _dfs(edge, edge.index, edge.isUsed);
}

int main()
{
    std::ios::sync_with_stdio(false);
    int edge_size, vertex_size;
    cin >> edge_size >> vertex_size;
    vector<Edge> connection(edge_size);
    int U, V;
    for (int i = 0; i < vertex_size; i++)
    {
        cin >> U >> V;
        U--;
        V--;
        connection[U].index = U;
        connection[V].index = V;
        connection[U].friends.push_back(connection.begin() + V);
        connection[V].friends.push_back(connection.begin() + U);
    }

    int count = 0;

    for (auto &edge : connection)
    {
        if (edge.parent == -1)
        {
            dfs(edge);
            count++;
        }
    }

    cout << count - 1;

    return 0;
}