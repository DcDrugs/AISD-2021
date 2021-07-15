#include <iostream>
#include <list>
#include <vector>

using namespace std;

struct Vertex;

struct Edge {
	Vertex *to;
	long long cost;
};

struct Vertex {
	list<Edge> friends;
	long long sizeTree = 1;
};

long long dfs(Vertex *vert, Vertex *prevNode, const long long N,
	      const long long mod)
{
	long long res = 0;
	for (auto &item : vert->friends) {

		if (prevNode != item.to) {
			res += (dfs(item.to, vert, N, mod) +
			       2 * item.to->sizeTree * (N - item.to->sizeTree) *
				   item.cost) %
			      mod;
			vert->sizeTree += item.to->sizeTree;
		}
	}
	return res % mod;
}

int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	long long mod = 10000007;
	long long N;
	cin >> N;
	vector<Vertex *> v(N);
	for (auto &i : v)
		i = new Vertex();
	int U, V, cost;
	for (int i = 0; i < N - 1; i++) {
		cin >> U >> V >> cost;
		U--;
		V--;
		v[U]->friends.push_back({v[V], cost});
		v[V]->friends.push_back({v[U], cost});
	}
	cout << dfs(v[0], NULL, N, mod);

	return 0;
}