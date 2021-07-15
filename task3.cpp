#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

long long GetMod(long long first, long long second, long long mod = 1000000007)
{
	return (first * second) % mod;
}

int main()
{
	std::ios::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	long long mod = 1000000007;
	vector<long long> arr(n);
	for (auto &i : arr) {
		cin >> i;
	}
	sort(arr.begin(), arr.end());

	long long res = 1;
	int indexLeft = 0, indexRight = arr.size() - 1;
	if (arr[indexRight] <= 0) {
		if (k % 2 != 0)
			for (int i = indexRight - k + 1; i <= indexRight; i++)
				res = GetMod(res, arr[i]);
		else
			for (int i = indexLeft; i < indexLeft + k; i++)
				res = GetMod(res, arr[i]);
	} else {
		for (int i = 0; i < k; i++) {

			if (i + 1 == k ||
			    arr[indexRight] * arr[indexRight - 1] >
				arr[indexLeft] * arr[indexLeft + 1]) {
				res = GetMod(res, arr[indexRight]);
				indexRight--;
			} else {
				res = GetMod(res, GetMod(arr[indexLeft],
							 arr[indexLeft + 1]));
				indexLeft += 2;
				i++;
			}
		}
	}
	cout << (res + mod) % mod;

	return 0;
}
