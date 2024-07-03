#include <iostream>

using namespace std;

bool arr[21];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	// freopen_s(new FILE*, "input.txt", "r", stdin);
	int M; cin >> M;
	while (M--) {
		string cmd;
		int x;
		cin >> cmd;

		if (cmd == "add") {
			cin >> x;
			arr[x] = true;
		}
		else if (cmd == "remove") {
			cin >> x;
			arr[x] = false;
		}
		else if (cmd == "check") {
			cin >> x;
			cout << arr[x] << '\n';
		}
		else if (cmd == "toggle") {
			cin >> x;
			arr[x] = !arr[x];
		}
		else if (cmd == "all") {
			for (int i = 1; i <= 20; i++) {
				arr[i] = true;
			}
		}
		else if (cmd == "empty") {
			for (int i = 1; i <= 20; i++) {
				arr[i] = false;
			}
		}

	}

	return 0;
}