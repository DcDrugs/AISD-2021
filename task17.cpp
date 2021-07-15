#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    std::ios::sync_with_stdio(false);
    long long N;
    cin >> N;
    vector<long long> arr(N);
    for(auto& i : arr)
        cin >> i;

    sort(arr.rbegin(), arr.rend());
    long long number = 1087388483;
    for(auto& i : arr)
    {
        if(i != 0)
        {
            if(number % i == 0)
                number /= i;
        }
    }
    if(number == 1)
        cout << "YES";
    else
        cout << "NO";


    return 0;
}