#include <algorithm>
#include <array>
#include <iostream>
#include <limits>
#include <map>
#include <tuple>
#include <vector>

using namespace std;

struct Coordinates {
	int x;
	int y;

	Coordinates(int x, int y)
	{
		this->x = x;
		this->y = y;
	}

	int DistanceTo(Coordinates coor)
	{
		return abs(x * y - coor.y * coor.x);
	}

	bool operator==(Coordinates coor)
	{
		return make_tuple(x, y) == make_tuple(coor.x, coor.y);
	}
};

struct Vertex {
	long long distance = numeric_limits<long long>::max();
	Coordinates coordinate;
	long long heristic = 0;
	bool isUsed = false;

	Vertex(int i, int j) : coordinate(i, j) {}

	long long GetHDistance() { return distance + heristic; }
};

Vertex *zeroVetex = new Vertex(-1, -1);

bool operator<(const Vertex &rhs, const Vertex &lhs)
{
	return rhs.distance + rhs.heristic < lhs.distance + lhs.heristic;
}

array<Vertex *, 8> GetNeightbors(vector<vector<Vertex *>> &v, Vertex *vertex)
{
	array<Vertex *, 8> res;
	int x = vertex->coordinate.x;
	int y = vertex->coordinate.y;

	if (x + 2 < v.size() && y - 1 >= 0)
		res[0] = v[x + 2][y - 1];
	else
		res[0] = zeroVetex;

	if (x + 2 < v.size() && y + 1 < v[x + 2].size())
		res[1] = v[x + 2][y + 1];
	else
		res[1] = zeroVetex;

	if (x + 1 < v.size() && y + 2 < v[x + 1].size())
		res[2] = v[x + 1][y + 2];
	else
		res[2] = zeroVetex;

	if (x - 1 >= 0 && y + 2 < v[x - 1].size())
		res[3] = v[x - 1][y + 2];
	else
		res[3] = zeroVetex;

	if (x - 2 >= 0 && y + 1 < v[x - 2].size())
		res[4] = v[x - 2][y + 1];
	else
		res[4] = zeroVetex;

	if (x - 2 >= 0 && y - 1 >= 0)
		res[5] = v[x - 2][y - 1];
	else
		res[5] = zeroVetex;

	if (x - 1 >= 0 && y - 2 >= 0)
		res[6] = v[x - 1][y - 2];
	else
		res[6] = zeroVetex;

	if (x + 1 < v.size() && y - 2 >= 0)
		res[7] = v[x + 1][y - 2];
	else
		res[7] = zeroVetex;

	return res;
}

long long AStar(vector<vector<Vertex *>> &v, int posX, int posY)
{
	multimap<long long, Vertex *> qu;
	v[0][0]->distance = 0;
	qu.insert({0, v[0][0]});
	while (qu.size() > 0) {
		Vertex *vert = qu.begin()->second;
		qu.erase(qu.begin());
		vert->isUsed = true;

		if (vert == v[posX][posY])
			return vert->distance;

		for (auto neightbor : GetNeightbors(v, vert)) {
			if (neightbor == zeroVetex || neightbor->isUsed)
				continue;

			long long dis = vert->distance + 1;
			if (neightbor->distance ==
			    numeric_limits<long long>::max()) {
				neightbor->distance = dis;
				neightbor->heristic =
				    vert->coordinate.DistanceTo(
					neightbor->coordinate);
				qu.insert(
				    {neightbor->GetHDistance(), neightbor});
			} else if (dis < neightbor->distance) {
				auto range =
				    qu.equal_range(neightbor->GetHDistance());
				auto it = find_if(range.first, range.second,
						  [neightbor](auto &el) {
							  return el.second ==
								 neightbor;
						  });
				qu.erase(it);
				neightbor->distance = dis;
				qu.insert(
				    {neightbor->GetHDistance(), neightbor});
			}
		}
	}
	return -1;
}

int main()
{
	std::ios::sync_with_stdio(false);
	int N, M, posX, posY;
	cin >> N >> M >> posX >> posY;
	vector<vector<Vertex *>> v(N, vector<Vertex *>(M));
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v[i].size(); j++) {
			v[i][j] = new Vertex(i, j);
		}
	}

	long long dis = AStar(v, --posX, --posY);
	if (dis == -1)
		cout << "NEVAR";
	else
		cout << dis;
}