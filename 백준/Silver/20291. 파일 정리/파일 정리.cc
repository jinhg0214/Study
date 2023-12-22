#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

int N;
unordered_map<string, int> um;

bool compare(pair<string, int>& a, pair<string, int>& b) {
	if (a.first < b.first) return true;
	if (a.first > b.first) return false;
	return a.second < b.second;
}

int main() {
	// freopen_s(new FILE*, "input.txt", "r", stdin);
	cin >> N;
	while (N--) {
		string filename;
		cin >> filename;
		
		string format = filename.substr(filename.find('.') + 1, filename.size() - 1);
		um[format]++;
	}

	vector < pair<string, int> > vec(um.begin(), um.end()); // unordered map 을 정렬하기 위해선 벡터로 변환해줘야함

	sort(vec.begin(), vec.end(), compare);

	for (auto e : vec) {
		cout << e.first << " " << e.second << endl;
	}

	return 0;
}