#include <iostream>
#include <string>

using namespace std;

string num[10][5] = {
	// 0
	"***",
	"* *",
	"* *",
	"* *",
	"***",
	// 1
	"  *",
	"  *",
	"  *",
	"  *",
	"  *",
	// 2
	"***",
	"  *",
	"***",
	"*  ",
	"***",
	// 3
	"***",
	"  *",
	"***",
	"  *",
	"***",
	// 4
	"* *",
	"* *",
	"***",
	"  *",
	"  *",
	// 5
	"***",
	"*  ",
	"***",
	"  *",
	"***",
	// 6
	"***",
	"*  ",
	"***",
	"* *",
	"***",
	// 7
	"***",
	"  *",
	"  *",
	"  *",
	"  *",
	// 8
	"***",
	"* *",
	"***",
	"* *",
	"***",
	// 9
	"***",
	"* *",
	"***",
	"  *",
	"***",
};

int main() {
	// freopen_s(new FILE*, "input.txt", "r", stdin);

	string input[5];
	int num_size; // 몇글자인지 
	int result = 0;  

	// 1. 첫줄을 읽고 문자가 몇개인지 파악해본다
	getline(cin, input[0]);
	input[0] += " "; // 마지막 글자에 공백을 추가해 글자수를 4칸 간격으로 맞춘다
	
	num_size = input[0].size() / 4;

	// 나머지 4줄도 입력받기
	for (int i = 1; i < 5; i++) {
		getline(cin, input[i]);
		input[i] += " "; // 마찬가지로 공백 추가 
	}

	// 2. 각 글자가 어떤 글자인지 체크
	
	for (int i = 0; i < num_size; i++) {
		for (int j = 0; j < 10; j++) { // 0부터 9 까지 어떤 수랑 같은지 체크한다
			bool flag = true;
			for (int k = 0; k < 5; k++) {
				/*cout << num[j][k] << endl;
				cout << input[k].substr(i*4, 3) << endl;*/
				if (num[j][k] != input[k].substr(i*4, 3)) {
					flag = false;
					break;
				}
			}
			if (flag == true) {
				result = result * 10 + j;
			}
		}
	}

	if (result % 6 == 0) {
		cout << "BEER!!" << endl;
	}
	else {
		cout << "BOOM!!" << endl;
	}
	

	return 0;
}