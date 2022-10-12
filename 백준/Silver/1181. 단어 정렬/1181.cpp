#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string str[20005];

void swap(string& a, string& b) {
	string tmp = a;
	a = b;
	b = tmp;
}

bool compare(string s1, string s2) {
	if (s1.size() < s2.size()) return true;
	else if (s1.size() > s2.size()) return false;

	if (s1 == s2) return false; // ���� ���� ���ٸ� �� ����

	int str_size = s1.size();
	for (int i = 0; i<str_size; i++) {
		if (s1[i] > s2[i]) return false;
		else if (s1[i] < s2[i]) return true;
	}
}

int main() {
	freopen_s(new FILE*, "sample_input.txt", "r", stdin);
	
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> str[i];
	}

	// �������� �̿� -> �ð��ʰ�
	//for (int i = 0; i < N; i++) {
	//	for (int j = 0; j < i; j++) {
	//		// ���� ���� 1. ���̰� ª�� �� ����,
	//		if (str[j].size() > str[i].size()) {
	//			swap(str[j], str[i]);
	//		}
	//		// ���� ���� 2. ���̰� ���ٸ� ���� ������
	//		else if (str[j].size() == str[i].size()) {
	//			for (int k = 0; k < str[i].size(); k++) {
	//				if (str[i][k] < str[j][k]) {
	//					swap(str[i], str[j]);
	//				}
	//			}
	//		}
	//	}
	//}

	// algorithm ���̺귯�� �� sort �Լ� ���
	sort(str, str + N, compare);

	// ���� �ܾ �Էµ� ��� �ѹ����� ���
	cout << str[0] << endl;
	for (int i = 1; i < N; i++) {
		if (str[i] == str[i - 1]) continue;
		cout << str[i] << endl;
	}

	return 0;
}