#include <iostream>
#include <vector> 
#include <list>

using namespace std;

struct Vertex;

struct Edge
{
    Vertex* to;
    long long cost;  
};

struct Vertex
{
    long long index;
    list<Edge> friends;
    bool isUsed = false;
    long long maxInTree = 0;
    long long maxNotInTree = 0;
    long long max = 0;

    Vertex(long long ind)
    {
        index = ind;
    }
};

void dfs(Vertex* vert)
{
    if (vert->isUsed == true)
            return;
    vert->isUsed = true;
    for (auto& item : vert->friends)
    {
        if (item.to->isUsed == true)
            continue;

        dfs(item.to);
        vert->maxInTree = max(vert->maxInTree, 
            item.to->maxNotInTree + item.cost - item.to->max);
        vert->maxNotInTree += item.to->max;

    }
    vert->max = vert->maxInTree + vert->maxNotInTree;
}

int main()
{   
    std::ios::sync_with_stdio(false);
    long long N;
    cin >> N;
    vector<Vertex*> v(N);
    for(long long i = 0; i < N; i++)
        v[i] = new Vertex(i);
    int U, V, cost;
    for(int i = 0; i < N -1; i++)
    {
        cin >> U >> V;
        U--; V--;
        v[U]->friends.push_back({v[V], 1});
        v[V]->friends.push_back({v[U], 1});
    }
    dfs(v[0]);
    long long m = -1;
    if(N > 1)
        m = v[0]->max;

    for(long long i = 0; i < N; i++)
    {
        if(m < v[i]->max)
            m = v[i]->max;
    }

    cout << m;

    return 0;
}