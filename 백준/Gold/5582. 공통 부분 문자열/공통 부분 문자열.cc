#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

#define MAX 4001

int matrix[MAX][MAX]; // 0으로 초기화 되어있음

int main() {
	// freopen_s(new FILE*, "input.txt", "r", stdin);
	string first, second;
	cin >> first >> second;

	int max_len = 0;

	for (int i = 0; i <= second.size(); i++) {
		for (int j = 0; j <= first.size(); j++) {
            // 0번 인덱스는 matrix[i][j] = 0으로 초기화 되어있으므로 패스해도됨
			if (i == 0 || j == 0) continue; 
			
            // j-1, i-1로 각각 문자 확인 후 같다면 +1
			if (first[j-1] == second[i-1]) { 
				matrix[i][j] = matrix[i - 1][j - 1] + 1;
				max_len = max(max_len, matrix[i][j]);
			}
		}
	}

	cout << max_len;
	return 0;
    
    // https://jinhg0214.github.io/posts/substring/
}