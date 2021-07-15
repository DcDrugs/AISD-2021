#include <iostream>
#include <limits>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

struct Request
{
    long long L;
    long long R;
    long long V;
};

bool operator<(const Request& lhs, const Request& rhs)
{
    return lhs.V > rhs.V;
}

istream& operator>>(istream &in, Request& req)
{
    in >> req.L >> req.R >> req.V;
    req.L--;
    return in;
}

ostream& operator<<(ostream &out,const vector<long long>& v)
{
    for(auto i : v)
        out << i << " ";
    return out;
}

vector<long long> GetRes(multiset<Request>& v, long long N)
{
    vector<long long*> nextIndex(N, NULL);
    vector<long long> res(N);
    for(auto i : v)
    {
        long long* tmp = new long long();
        for(long long j = i.L; j < i.R;)
        {
            if(nextIndex[j] == NULL)
            {
                res[j] = i.V;
                nextIndex[j] = tmp;
                *tmp = ++j;
            }
            else
                j = *nextIndex[j];
        }
    }
    return res;
}

int main()
{
    std::ios::sync_with_stdio(false);
    long long N, M;
    cin >> N >> M;
    multiset<Request> requests;

    for(long long i = 0; i < M; i++)
    {
        Request req;
        cin >> req;
        requests.insert(req);
    }
    cout << GetRes(requests, N);
    return 0;
}