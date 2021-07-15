#include <iostream>
#include <vector>
#include <list>
#include <unordered_set>

using namespace std;

long long counter = 0;

struct Edge
{
    int index;
    list<vector<Edge>::iterator> friends;
    bool isUsed = false;
};

void dfs(Edge& edge)
{
    edge.isUsed = true;

    for(auto item : edge.friends)
    {
        if(item->isUsed == true)
            continue;

        counter++;
        dfs(*(item));
    }
}

int main()
{
	std::ios::sync_with_stdio(false);
    int edge_size, vertex_size;
    cin >> edge_size >> vertex_size;
    vector<Edge> connection(edge_size);
    int U, V;
    for(int i = 0; i < vertex_size; i++)
    {
        cin >> U >> V;
        U--;
        V--;
        connection[U].index = U;
        connection[V].index = V;
        connection[U].friends.push_back(connection.begin() + V);
        connection[V].friends.push_back(connection.begin() + U);
    }

    dfs(connection.back());
    int i = 0;
    for(auto& i : connection)
        if(!i.isUsed)
        {
            cout << -1;
            return 0;
        }
    cout << vertex_size - counter;
    return 0;
}