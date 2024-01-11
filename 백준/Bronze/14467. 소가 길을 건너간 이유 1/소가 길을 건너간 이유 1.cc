#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
	// freopen_s(new FILE*, "input.txt", "r", stdin);
	int T;
	unordered_map<int, int> um;

	int crossing = 0;
	cin >> T;
	while (T--) {
		int cow, road;
		cin >> cow >> road;

		// 최초로 관측된 소라면 
		if (um.find(cow) == um.end()) { // null is not 0
			um[cow] = road; // 새로 추가하고 현재 위치를 저장
		}
		// 이미 기록된 소인데, 다른 도로에서 관측된 경우 
		else if (um[cow] != road) {
		 	um[cow] = road; // 갱신하고
			crossing++; // 건넜다고 표시
		}
	}

	cout << crossing;

	return 0;
}