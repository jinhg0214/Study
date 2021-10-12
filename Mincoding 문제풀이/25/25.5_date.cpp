#include <iostream>
#include <string>

using namespace std;

int main() {
	string date;

	cin >> date;

	int a = date.find('.');
	string temp = date.substr(0, a);
	string year = temp;

	int b = date.find('.', a + 1);
	temp = date.substr(a + 1, b - a - 1);
	string mon = temp;

	temp = date.substr(b+1, 2);
	string day = temp;

	int mon_case, day_case;

	// month 경우의 수 
	// mon이 두자리 XX
	if (mon == "XX") { 
		mon_case = 3;
	}
	// mon이 두자리고, 앞자리가 공개됨
	else if (mon.size() == 2 && mon[1] == 'X') {
		mon_case = 3;
	}
	// mon이 두자리고, 뒷자리가 공개됨 
	else if (mon.size() == 2 && mon[0] == 'X') {
		mon_case = 1;
	}
	// mon이 한자리 1~9
	else if (mon.size() == 1) {
		mon_case = 9;
	}

	// Day 경우의수
	// day의 두자리 XX
	if (day == "XX") {
		day_case = 31;
	}
	// day가 두자리고, 앞자리가 공개됨
	else if(day.size() == 2 && day[1] == 'X') {
		if (day[0] == 3) day_case = 2;
		else day_case = 10;
	}
	// day가 두자리고, 뒷자리가 공개됨
	else if (day.size() == 2 && day[0] == 'X') {
		if (day[1] == 0 || day[1] == 1) { day_case = 3; }
		else { day_case = 2; }
	}
	else if (day.size() == 1) {
		day_case = 9;
	}
	
	cout << mon_case * day_case;

	return 0;
}