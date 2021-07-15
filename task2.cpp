#include <array>
#include <iostream>

using namespace std;

long long &GetMinlvalue(long long &first, long long &second)
{
	return (first > second) ? second : first;
}

long long &GetMaxlvalue(long long &first, long long &second)
{
	return (first > second) ? first : second;
}

int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	array<long long, 4> arr;
	arr.fill(0);
	int n;
	cin >> n;
	long long num;
	for (int i = 0; i < n; i++) {
		cin >> num;
		if (num >= 0) {
			auto &tmp = GetMinlvalue(arr[2], arr[3]);
			if (tmp < num)
				tmp = num;
		} else {
			auto &tmp = GetMaxlvalue(arr[0], arr[1]);
			if (tmp > num)
				tmp = num;
		}
	}

	if (n == 2)
		cout << arr[1] * arr[2];
	else if (arr[0] * arr[1] > arr[2] * arr[3])
		cout << arr[0] * arr[1];
	else
		cout << arr[2] * arr[3];

	return 0;
}