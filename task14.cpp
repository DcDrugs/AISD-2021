#include <iostream>
#include <vector>

using namespace std;

vector<vector<long long>> operator*(const vector<vector<long long>>& lhs, 
        const vector<vector<long long>> & rhs)
{
    vector<vector<long long>> res(lhs.size(), vector<long long>(rhs.size()));
    for(long long i = 0; i < lhs.size(); i++)
    {
        for(long long j=0; j < rhs.size(); j++)
        {
            for(long long k = 0; k < lhs.size(); k++)
            {
                res[i][j] += (rhs[i][k] * lhs[k][j]) % 1000000007;
                res[i][j] %= 1000000007;
            }
        }
    }
    return res;
}

void operator*=(vector<vector<long long>>& lhs, 
        const vector<vector<long long>> & rhs)
{
    lhs = lhs * rhs;
}

vector<vector<long long>> pow(vector<vector<long long>>& v, int n) {
	vector<vector<long long>> res(v.size(), vector<long long>(v.size()));
    for(int i = 0; i < v.size(); i++)
    {
        res[i][i] = 1;
    }
	while (n) 
    {
		if (n & 1)
			res *= v;
		v *= v;
		n >>= 1;
	}
	return res;
}


int main()
{
	std::ios::sync_with_stdio(false);
    long long N, M, L, U, V, x, y;
    cin >> N >> M >> U >> V >> L;
    vector<vector<long long>> v(N,vector<long long>(N));
    for(long long i = 0 ; i < M; i++)
    {
        cin >> x >> y;
        v[y - 1][x - 1]++;
        v[x - 1][y - 1]++;
    }

    v = pow(v, L);
    for(auto& i : v)
    {
        for(auto j : i)
        {
            cout << j << " ";
        }
        cout << "\n";
    }
    cout << v[U - 1][V - 1] % 1000000007;

    return 0;
}