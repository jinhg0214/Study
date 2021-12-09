#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector< vector<char> > town(3, vector<char>(3));

    town[0][0] = 'C';
    town[0][1] = 'D';
    town[0][2] = 'A';
    town[1][0] = 'B';
    town[1][1] = 'M';
    town[1][2] = 'Z';
    town[2][0] = 'Q';
    town[2][1] = 'P';
    town[2][2] = 'O';

    vector<char> black(4);

    for (int i = 0; i < black.size(); i++) {
        cin >> black[i];
    }

    int cnt = 0;
    for (int i = 0; i < black.size(); i++) {
        for (int y = 0; y < town.size(); y++) {
            for (int x = 0; x < town[y].size(); x++) {
                if (black[i] == town[y][x]) {
                    cnt++;
                }
            }
        }
    }
    cout << cnt << "명" << endl;


    return 0;
}