#include <stdio.h>


int main() {
	// freopen_s(new FILE*, "sample_input.txt", "r", stdin);

	char str[105];

	while (fgets(str, 105, stdin) != NULL){
		
		int lower = 0, upper = 0, number = 0, space = 0;

		for (int i = 0; str[i] != '\0'; i++) {
			if (65 <= str[i] && str[i] <= 90) upper++;
			else if (97 <= str[i] && str[i] <= 122) lower++;
			else if (str[i] == 32) space++;
			else if (48 <= str[i] && str[i] <= 57) number++;
		}
		printf("%d %d %d %d\n", lower, upper, number, space);
	}
	

	return 0;
}