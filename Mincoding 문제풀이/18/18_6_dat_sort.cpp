#include <iostream>
#include <vector>
using namespace std;

int main()
{
    char map[5][3] = {
        'A','B','C',
        'A','G','H',
        'H','I','J',
        'K','A','B',
        'A','B','C'
    };

    int alphabet[26] = { 0 };

    for (int y = 0; y < 5; y++) {
        for (int x = 0; x < 3; x++) {
            alphabet[map[y][x] - 'A']++;
        }
    }

    int ac_sum[26];
    
    ac_sum[0] = alphabet[0];
    for (int i = 1; i < 26; i++) {
        ac_sum[i] = alphabet[i] + ac_sum[i - 1];
    }

    char res[26] = { 0 };

    for (int y = 0; y < 5; y++) {
        for (int x = 0; x < 3; x++) {
            char t = map[y][x]; // 현재 단어
            int pos = ac_sum[t - 'A'];
            res[pos] = t;
            ac_sum[t - 'A']--;
        }
    }

    for (int i = 1; i <= 15; i++) {
        cout << res[i];
    }

    return 0;
}