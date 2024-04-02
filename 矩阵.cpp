#include <iostream>
#include <unordered_map>
#include<cmath>
#include<string>
#include<vector> 
using namespace std;

int juzhennum, shurunum;
unordered_map<char, pair<int, int>> juzhen;
vector<string> s;

int main()
{
	while (cin >> juzhennum >> shurunum) {

		s.clear();
		juzhen.clear();
		for (int i = 0; i < juzhennum; i++) {
			char q;
			int w, e;in >> q >> w >> e;
			juzhen[q] = pair<int, int>(w, e);
		}
		string a;
		for (int i = 0; i < shurunum; i++)
		{
			cin >> a;
			c
			s.push_back(a);

		}

		for (int q = 0; q < shurunum; q++) {
			string sr = s[q];
			bool isLegal = true;
			for (int i = 0; i < sr.size() - 1; i++) {
				char qian = sr[i];
				char hou = sr[i + 1];
				if (juzhen[qian].second != juzhen[hou].first) {
					isLegal = false;
					break;
				}
			}
			if (!isLegal) {
				cout << "MengMengDa" << endl;
				continue;
			}


			int size = sr.size();
			vector<vector<int>> biao(size, vector<int>(size));
			for (int i = 0; i < size; i++)
				biao[i][i] = 0;
			for (int r = 2; r <= size; r++) {
				for (int i = 0; i <= size - r; i++) {
					int j = i + r - 1;
					biao[i][j] = biao[i + 1][j] + juzhen[sr[i]].first * juzhen[sr[i]].second * juzhen[sr[j]].second;
					for (int k = i; k <= j - 1; k++) {
						int min1 = biao[i][k] + biao[k + 1][j] + juzhen[sr[i]].first * juzhen[sr[k]].second * juzhen[sr[j]].second;
						biao[i][j] = min(biao[i][j], min1);
					}
				}
			}
			cout << biao[0][size - 1] << endl;
			biao.clear();
		}
	}
	return 0;
}
