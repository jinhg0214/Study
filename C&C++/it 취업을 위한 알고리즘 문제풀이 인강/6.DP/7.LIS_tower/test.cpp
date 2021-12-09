#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Brick{
    int xy, h, w; // 밑면 넓이, 높이, 무게
    Brick(int a, int b, int c){
        xy=a;
        h=b;
        w=c;
    }
    bool operator<(const Brick &b)const{
        return xy > b.xy; // 밑면의 넒이에 의해 정렬
        // 내림차순으로 정렬
    }
};

int main(){
    freopen("G:\\Git\\Algorithm-C-\\6.DP\\7.LIS_tower\\input.txt", "rt", stdin);

    int n, a, b, c, res=0;

    cin >> n;

    vector<Brick> arr;

    for(int i=0; i<n; i++){
        cin >> a >> b >> c;
        arr.push_back(Brick(a,b,c));
    }

    // 밑면의 넓이를 기준으로 내림차순 정렬
    sort(arr.begin(), arr.end());

    vector<int> dy(n);

    // LIS
    dy[0] = arr[0].h; // 첫번째 dy원소는 arr배열의 첫번째 Brick의 h

    for(int i=1; i<n; i++){ // 두번째 원소부터 탐색
        int max_h = 0; // 최대 높이를 저장
        
        for(int j=i-1; j>=0; j--){
            if(arr[j].w < arr[i].w && // 조건 5. 무게가 가벼워야 위에 올릴 수 있다
               dy[j] > max_h ){ 
                max_h = dy[j]; // 최대 높이를 갱신
            }
        }

        dy[i] = max_h + arr[i].h; // 최대 높이를 갱신

        res = max(dy[i], res);
    }

    cout << res;

    return 0;
}