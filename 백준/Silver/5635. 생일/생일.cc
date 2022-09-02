#include <iostream>

using namespace std;

int n;
struct student {
	char name[16] = "";
	int year;
	int month;
	int day;
};


int main() {
	// freopen_s(new FILE*, "sample_input.txt", "r", stdin);
	
	cin >> n;
	student min, max;
	
	student now;
	// 초기 세팅
	scanf("%s %d %d %d", &now.name, &now.day, &now.month, &now.year);

	// 첫번쨰 입력을 최소, 최대로 잡고 시작
	min = now;
	max = now;

	for (int i = 0; i < n - 1; i++) {
		scanf("%s %d %d %d", &now.name, &now.day, &now.month, &now.year);
		
		// 가장 나이가 적은사람 찾기
		if (now.year > min.year) {
			min = now;
		}
		else if (now.year == min.year) {
			if (now.month > min.month) {
				min = now;
			}
			else if (now.month == min.month) {
				if (now.day > min.day) {
					min = now;
				}
			}
		}
		
		// 가장 나이가 많은사람 찾기
		if (now.year < max.year) {
			max = now;
		}
		else if (now.year == max.year) {
			if (now.month < max.month) {
				max = now;
			}
			else if (now.month == max.month) {
				if (now.day < max.day) {
					max = now;
				}
			}
		}
	}
	
	printf("%s\n%s\n", min.name, max.name);

	return 0;
}