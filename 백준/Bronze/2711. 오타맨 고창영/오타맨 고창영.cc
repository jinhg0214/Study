#include <stdio.h>

void EraseStringWithPos(int pos, char* str) {
	/*printf("%d, %s\n", pos, str);*/
	char tmp[83];
	int idx = 0;
	// 1. 0~pos-1까지 복사 (pos 번째 글자를 제외해야하므로)
	for (int i = 0; i < pos-1; i++) {
		tmp[idx++] = str[i];
	}

	// 2. str[pos+1]부터 끝까지 복사
	for (int i = pos; str[i] != '\0'; i++) {
		tmp[idx++] = str[i];
	}
	tmp[idx] = '\0';

	printf("%s\n", tmp);


	return;
}

int main() {
	// freopen_s(new FILE*, "sample_input.txt", "r", stdin);
	int T;
	scanf("%d", &T);

	while (T--) {
		char str[81];
		int pos;

		scanf("%d %s", &pos, &str);

		EraseStringWithPos(pos, str);
	}

	return 0;
}