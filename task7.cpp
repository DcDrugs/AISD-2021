#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	int M, N, X1, X2, Y1, Y2;
	cin >> M >> N >> X1 >> Y1 >> X2 >> Y2;
    if(abs(X1 - X2) != abs(Y1 - Y2))
        cout << "YES";
    else
        cout << "NO";
	return 0;
}