#include <iostream>
#include <limits>
#include <vector>
#include <map>
#include <set>

using namespace std;

struct Vertex
{
        map<Vertex*, long long> neighbors;
        long long distance = numeric_limits<long long>::max();
        bool isUsed = false;
};

long long Dijkstra(Vertex* from, Vertex*  to)
{
    map<long long, Vertex*> qu;
    from->distance = 0;
    qu.insert({from->distance, from});
    while(qu.size() > 0)
    {
        Vertex* vert = qu.begin()->second;
        qu.erase(qu.begin());
        vert->isUsed = true;

        if(vert == to)
            return vert->distance;

        for(auto& i : vert->neighbors)
        {
            if(i.first->isUsed)
                continue;
            long long dis = vert->distance + i.second;
            if(dis < i.first->distance)
            {
                qu.erase(i.first->distance);
                i.first->distance = dis;
                qu.insert({i.first->distance, i.first});
            }
        }
    }
    return to->distance;
}

int main()
{
    std::ios::sync_with_stdio(false);
    long long N, M;
    cin >> N >> M;
    vector<Vertex*> v(N);
    long long A, B, C;
    for(long long i = 0; i< N; i++)
        v[i] = new Vertex();
    for(long long i = 0; i < M; i++)
    {
        cin >> A >> B >> C;
        A--; B--;
        auto cost = v[A]->neighbors[v[B]];
        if(cost > C || cost == 0)
        {
            v[A]->neighbors[v[B]] = C;
            v[B]->neighbors[v[A]] = C;
        }
    }

    cin >> A >> B;
    A--; B--;

    cout << Dijkstra(v[A], v[B]);
}