#include <iostream>
#include <string>

using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
    int year;
    cin >> year;
    if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
        cout << "YES";
    else
        cout << "NO";
    return 0;
}