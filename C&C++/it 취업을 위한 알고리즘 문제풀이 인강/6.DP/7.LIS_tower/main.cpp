#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
벽돌을 저장하는 구조체

dy[n] : 제일 꼭대기에 n번째 벽돌을 올릴 때, 탑의 최대 높이를 저장 (LIS)

dy[1] = 3
dy[2] = 2

자기 앞을 보면서 자기보다 무거운지 확인.(아래에 놓을 수 있는 벽돌 찾기)

놓을 수 있는 벽돌이 여러개인 경우, dy[x]의 값이 큰 벽돌을 선택(더 높이 쌓기 위해)

dy[3] = 5
dy[4] = 4
dy[5] = 10
*/

struct Brick{
    int s, h, w;
    Brick(int a, int b, int c){
        s=a;
        h=b;
        w=c;
    }

    // 정렬 조건
    bool operator<(const Brick &b)const{
       return s > b.s; 
       // s에 의해 내림차순 정렬
       // 앞의 자료가 크면 내림차순
       // 뒤의 자료가 크면 오름차순 외우기!!!
    }
};

int main(){
    freopen("G:\\Git\\Algorithm-C-\\6.DP\\7.LIS_tower\\input.txt", "rt", stdin);
    
    int n, a, b ,c;
    int max_h = 0, res = 0;

    cin >> n;

    vector<Brick> Bricks;
    vector<int> dy(n, 0);

    for(int i=1; i<=n; i++){
        cin >> a >> b >> c;
        Bricks.push_back(Brick(a,b,c));
    }

    // s를 내림차순으로 정렬
    sort(Bricks.begin(), Bricks.end());

    dy[0] = Bricks[0].h; // 첫 dy는 첫번째 벽돌의 높이로 설정, 쌓을 벽돌이 하나밖에 없음
    res=dy[0]; 

    // 두번째 벽돌부터 시작
    for(int i=1; i<n; i++){
        max_h=0;
        
        // 자기 앞의 벽돌을 보면서 확인
        for(int j=i-1; j>=0; j--){
            // 조건 1. 앞의 벽돌이 자신의 무게보다 클 경우 && dy[j]가 최대 값일 경우, 아래에 놓일 수 있음
            if(Bricks[j].w > Bricks[i].w && dy[j] > max_h){
                max_h = dy[j];
            }
        }
        dy[i]=max_h + Bricks[i].h; // 최대 높이 기록
        res = max(res, dy[i]);
    }

    cout << res << endl;

    return 0;
}
