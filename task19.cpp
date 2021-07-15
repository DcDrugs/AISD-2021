#include <vector>
#include <iostream>

using namespace std;

long long counter = 0;

void merge(vector<long long>& arr, long long left, long long mid, long long right)
{
    long long n1 = mid - left + 1;
    long long n2 = right - mid;

    long long leftArr[n1], rightArr[n2];
 
    for (long long i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (long long j = 0; j < n2; j++)
        rightArr[j] = arr[mid + 1 + j];
 
    long long i = 0;
 
    long long j = 0;
 
    long long k = left;
 
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k++] = leftArr[i++];
        }
        else {
            arr[k++] = rightArr[j++];
            counter += n1 - i;
        }
    }
 
    while (i < n1)
        arr[k++] = leftArr[i++];

    while (j < n2)
        arr[k++] = rightArr[j++];
}
 
void merge_sort(vector<long long>& arr, long long left, long long right)
{
    if(left >= right)
        return;
    
    long long mid = (right + left) /2;

    merge_sort(arr,left, mid);
    merge_sort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}


int main()
{
	std::ios::sync_with_stdio(false);
    long long N;
    cin >> N;
    vector<long long> v(N);
    for(auto& i : v)
        cin >> i;
    merge_sort(v, 0, v.size() - 1);
    cout << counter;
    return 0;
}