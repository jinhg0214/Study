#include <iostream>

using namespace std;

int directY[4] = { -1, 0, 1, 0 };
int directX[4] = { 0, -1, 0, 1 };

void print_str(int y, int x, string str[][3]) {

	for (int i = 0; i < 4; i++) {
		int yy = y + directY[i];
		int xx = x + directX[i];

		if (yy < 0 || xx < 0 || yy > 2 || xx > 2) { continue; }
	
		cout << str[yy][xx];
	}

}

int main() {

	string str[3][3] = {
		"BHC", "BBQ", "KFC",
		"MC", "7AVE", "PAPA",
		"DHC", "OBS", "MOMS"
	};

	int tar_y, tar_x;

	cin >> tar_y >> tar_x;

	print_str(tar_y, tar_x, str);


	return 0;
}