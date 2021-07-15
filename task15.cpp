#include <iostream>
#include <string>
#include <string_view>
#include <algorithm>

using namespace std;

 bool palindrom(string_view s)
{
    for (long long i = 0;  i < s.size() / 2; i++ )
        if(s[i] != s[s.size() - 1 - i])
            return false;
  return true;
}

bool is_repeated(string_view s)
{
    for (long long i = 1;  i < s.size(); i++ )
        if(s[i] != s[0])
            return false;
    return true;
}

int not_polindrom(string_view s)
{
    if(!palindrom(s))
        return s.size();
    if(s.size() < 2)
        return -1;
    return max(not_polindrom(s.substr(1, s.npos)), not_polindrom(s.substr(0, s.size() - 1)));
}


int main()
{
	std::ios::sync_with_stdio(false);
    string s;
    cin >> s;
    if(!is_repeated(s))
        cout << not_polindrom(s);
    else
        cout << -1;
    return 0;
}