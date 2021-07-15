#include <vector>
#include <iostream>
#include <algorithm>
#include <array>

using namespace std;

short next_min(vector<short>& v, int from)
{
    short res = v[from];
    short index = from;
    for(int i = from + 1; i < v.size(); i++)
    {
        if(res > v[i])
        {
            return i;
        }
    }
    return from;
}

template <class RandomAccessIterator>
void counter_sort(RandomAccessIterator first, RandomAccessIterator last)
{
    array<short, 10> tmp = {0};
    auto it = first;
    while(it != last)
    {
        tmp[*(it)]++;
        it++;
    }
    for(int i = 0; i < tmp.size(); i++ )
    {
        while(tmp[i] != 0)
        {
            *(first) = i;
            tmp[i]--;
            first++;
        }
    }
}


vector<short> newNumber(vector<short> v, short index1, short index2)
{
    swap(v[index1], v[index2]);
    counter_sort(v.rbegin() + v.size() - index1, v.rend());
    return v;
}

int main()
{
	std::ios::sync_with_stdio(false);
    long long N;
    cin >> N;
    vector<short> v;
    v.reserve(7);
    while(N != 0)
    {
        v.push_back(N % 10);
        N /= 10;
    }

    vector<vector<short>> numbers;

    for(int i = v.size() - 1; i >= 0 ; i--)
    {
        for(int j = i - 1; j >= 0; j--)
        {
            if(v[i] < v[j])
                numbers.push_back(newNumber(v, i, j));
        }
    }

    for(int i = v.size() - 1; i >= 0; i--)
    {
        if(numbers.size())
        {
            short item = numbers[0][i];
            for(auto& j : numbers)
                if(item > j[i])
                    item = j[i];
            for(int j = 0; j < numbers.size(); j++)
            {
                if(item != numbers[j][i])
                {
                    numbers.erase(numbers.begin() + j);
                    j--;
                }
            }
        }
        else
        {
            break;
        }
        
    }
    
    if(numbers.size())
    {
        auto& number = numbers[0];
        for(short j = number.size() - 1; j >= 0; j-- )
        {
            cout << number[j];
        }
    }
    else
        cout << -1;

    return 0;
}