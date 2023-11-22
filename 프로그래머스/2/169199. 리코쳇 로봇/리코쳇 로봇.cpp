#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int map[101][101];
int visited[101][101];
int y_size;
int x_size;

struct Node{
    int y;
    int x;
    int level = 0;
};

Node robot, target;

int direct[4][2] ={0,1,1,0,0,-1,-1,0};

void Debug_print(){
    for(int y=0; y<y_size; y++){
        for(int x=0; x<x_size; x++){
            cout << visited[y][x];        
        }
        cout << endl;
    }
}

void Input(vector<string> board){
    y_size = board.size();
    x_size = board[0].size();
    
    for(int y=0; y<y_size; y++){
        for(int x=0; x<x_size; x++){
            char ch = board[y][x];
            if(ch == '.'){ map[y][x] = 0; }
            else if(ch == 'R'){
                robot.y = y;
                robot.x = x;
                robot.level = 0;
                map[y][x] = 5;
            }
            else if(ch == 'G'){
                target.y = y;
                target.x = x;
                map[y][x] = 9;
            }
            else if(ch == 'D'){
                map[y][x] = 1;
            }
        }
    }
}

int BFS() {
    queue<Node> qu;
    qu.push({ robot });
    visited[robot.y][robot.x] = 1;

    while (!qu.empty()) {
        Node now = qu.front();
        qu.pop();

        for (int t = 0; t < 4; t++) {
            int dy = now.y;
            int dx = now.x;

            // 경계 또는 벽을 만날때까지 쭉 이동 
            while (true) {
                if (dy < 0 || dx < 0 || dy >= y_size || dx >= x_size) break; // 맵 경계처리
                if (map[dy][dx] == 1) break; // 벽이라면 더이상 진행 불가

                dy += direct[t][0];
                dx += direct[t][1];
            }
            // 경계 또는 벽을 만나서 탈출했기 때문에 다시 한칸 뒤로
            dy -= direct[t][0];
            dx -= direct[t][1];

            if (dy == target.y && dx == target.x) {
                return now.level + 1;
            }

            if (visited[dy][dx]) continue; // 이미 방문한곳 처리

            visited[dy][dx] = now.level + 1;
            qu.push({ dy, dx, now.level + 1 });
        }
    }
    return -1;
}

int solution(vector<string> board) {
    int answer = 0;
    
    Input(board);
    
    answer = BFS();
    
    return answer;
}