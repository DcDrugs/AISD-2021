#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main()
{
    std::ios::sync_with_stdio(false);
    long long N;
    cin >> N;
    if(N % 10 != 0)
    {
        cout << N % 10;
    }
    else
        cout << "NO";

    return 0;
}