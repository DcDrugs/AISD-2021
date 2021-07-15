#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class SuffixTree
{
	using Node = size_t;
	using PosInTree = size_t;
	private:

		struct SuffixNode
		{
			size_t posInStr = 0;
			size_t len;
			PosInTree link = -1;

			SuffixNode(size_t pos, size_t lenght)
			{
				posInStr = pos;
				len = lenght;
			} 
		};
		

		size_t nodeCount = 1;

		vector<map<char, PosInTree>> suffix;
		vector<SuffixNode> nodes;
		string_view str;

		PosInTree curNode = 0, curPos = 0;

		size_t counter = 0;

		size_t AddNewNode(size_t pos, size_t len)
		{
			nodes.push_back(SuffixNode(pos, len));
			suffix.push_back(map<char, PosInTree>());
			return nodes.size() - 1;
		}

		void GoEdge()
		{
			while(curPos > nodes[suffix[curNode][str[counter - curPos]]].len)
			{
				curNode = suffix[curNode][str[counter - curPos]];
				curPos -= nodes[curNode].len;
			}
		}

		void AddLink(size_t last)
		{
			nodes[last].link = curNode;
		}

		void AddNode(size_t& v, size_t& last)
		{
			v = AddNewNode(counter - curPos, str.npos);
			AddLink(last);
			last = 0;
		}

		void AddNodeOnEdge(size_t& v, size_t& last, char letter, char t)
		{
			size_t u = AddNewNode(nodes[v].posInStr, curPos - 1);
			suffix[u][letter] = AddNewNode(counter - 1, str.npos);
			suffix[u][t] = v;
			nodes[v].posInStr += curPos - 1;
			nodes[v].len -= curPos - 1;
			v = u;
			nodes[last].link = u;
			last = u;
		}

		void AddLetter(char letter)
		{
			counter++;
			curPos++;
			size_t last = 0;
			while(curPos > 0)
			{
				GoEdge();
				char edge = str[counter - curPos];
				size_t& v = suffix[curNode][edge];
				char t = str[nodes[v].posInStr + curPos - 1];
				
				if(v == 0) AddNode(v, last);
				else if(t == letter) { AddLink(last); return; }
				else AddNodeOnEdge(v, last, letter, t);

				if(curNode == 0)
					curPos--;
				else
					curNode = nodes[curNode].link;
			}
		}

	public:
		SuffixTree(string_view s)
		{
			str = s;
			suffix.reserve(str.size() + 1);
			nodes.reserve(str.size() + 1);
			AddNewNode(0, str.npos);
			for(auto i : s)
			{
				AddLetter(i);
			}
		}

		size_t GetSuffixCounter()
		{
			size_t res = 0;
			 for(size_t i = 1; i < nodes.size(); i++)
        		res += min(str.size() - nodes[i].posInStr, nodes[i].len);
			return res;
		}
};

 
int main()
{
	std::ios::sync_with_stdio(false);
	string s;
	cin >> s;
	SuffixTree tree(s);
	cout << tree.GetSuffixCounter();
	return 0;
}
