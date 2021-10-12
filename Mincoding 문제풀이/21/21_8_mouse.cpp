#include <iostream>
#include <string>

using namespace std;

struct cursor {
    int x; 
    int y;

    void up() {
        y--;
    }
    void down() {
        y++;
    }
    void left() {
        x--;
    }
    void right() {
        x++;
    }
    void click() {
        cout << y << "," << x << endl;
    }
};

int main(){
    int n;
    cursor mouse;
    mouse.x = 5;
    mouse.y = 5;

    cin >> n;

    for (int i = 0; i < n; i++) {
        string cmd;

        cin >> cmd;

        if (cmd == "up") {
            mouse.up();
        }
        else if (cmd == "down") {
            mouse.down();
        }
        else if (cmd == "left") {
            mouse.left();
        }
        else if (cmd == "right") {
            mouse.right();
        }
        else if (cmd == "click") {
            mouse.click();
        }



    }

    return 0;
}