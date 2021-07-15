#include <iostream>
#include <string>

using namespace std;

int main(int argc, const char * argv[])
{
    std::ios::sync_with_stdio(false);
    string S;
    
    cin >> S;
    bool isChanged[S.size()] = { false };
    long long Q;
    cin >> Q;
    for(long long i = 0; i < Q; i++)
    {
        long long L, R;
        cin >> L >> R;
        if(L > R)
            swap(L, R);
        L--;

        if(L + 1 != R)
        {
            isChanged[L] = !isChanged[L];
            isChanged[R] = !isChanged[R];
        }
        else
        {
            if(S[L] < 95)
                S[L] += 32;
            else
                S[L] -= 32;
        }
    }

    bool needChange = false;
    for(long long i = 0; i < S.size(); i++)
    {
        if(isChanged[i])
            needChange = !needChange;

        if(needChange)
        {
            if(S[i] < 95)
                S[i] += 32;
            else
                S[i] -= 32;
        }

    }
    cout << S;
    
    return 0;
}