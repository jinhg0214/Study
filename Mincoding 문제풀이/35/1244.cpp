#include <iostream>

using namespace std;

struct swatch {
	int n;
	bool on_off;
}arr[101];

int switch_n;

void Init() {

	cin >> switch_n;

	for (int i = 0; i < switch_n; i++) {
		arr[i].n = i + 1;
		cin >> arr[i].on_off;
	}
}

int main() {
	freopen_s(new FILE*, "test.txt", "r", stdin);

	Init();

	int student_n;
	cin >> student_n;

	for (int i = 0; i < student_n; i++) {
		int student_type, student_num;
		cin >> student_type >> student_num;

		// 남학생
		if (student_type == 1) {
			for (int i = 0; i < switch_n; i++) {
				if (arr[i].n % student_num == 0) { // 배수라면 토글
					arr[i].on_off = !arr[i].on_off;
				}
			}
		}

		// 여학생
		else {
			int start = student_num - 1, end = student_num - 1;
			while (1) {
				if (arr[start].on_off != arr[end].on_off) break;

				start--;
				if (start < 0) {
					start = 0;
					break;
				}

				end++;
				if (end > switch_n - 1) {
					end = switch_n - 1;
					break;
				}
			}

			// 범위 토글
			for (int i = start; i <= end; i++) {
				arr[i].on_off = !arr[i].on_off;
			}
		}
	}

	for (int i = 0; i < switch_n; i++) {
		cout << arr[i].on_off << " ";
	}

	return 0;
}