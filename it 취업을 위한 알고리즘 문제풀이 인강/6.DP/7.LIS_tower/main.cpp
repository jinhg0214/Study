#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
������ �����ϴ� ����ü

dy[n] : ���� ����⿡ n��° ������ �ø� ��, ž�� �ִ� ���̸� ���� (LIS)

dy[1] = 3
dy[2] = 2

�ڱ� ���� ���鼭 �ڱ⺸�� ���ſ��� Ȯ��.(�Ʒ��� ���� �� �ִ� ���� ã��)

���� �� �ִ� ������ �������� ���, dy[x]�� ���� ū ������ ����(�� ���� �ױ� ����)

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

    // ���� ����
    bool operator<(const Brick &b)const{
       return s > b.s; 
       // s�� ���� �������� ����
       // ���� �ڷᰡ ũ�� ��������
       // ���� �ڷᰡ ũ�� �������� �ܿ��!!!
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

    // s�� ������������ ����
    sort(Bricks.begin(), Bricks.end());

    dy[0] = Bricks[0].h; // ù dy�� ù��° ������ ���̷� ����, ���� ������ �ϳ��ۿ� ����
    res=dy[0]; 

    // �ι�° �������� ����
    for(int i=1; i<n; i++){
        max_h=0;
        
        // �ڱ� ���� ������ ���鼭 Ȯ��
        for(int j=i-1; j>=0; j--){
            // ���� 1. ���� ������ �ڽ��� ���Ժ��� Ŭ ��� && dy[j]�� �ִ� ���� ���, �Ʒ��� ���� �� ����
            if(Bricks[j].w > Bricks[i].w && dy[j] > max_h){
                max_h = dy[j];
            }
        }
        dy[i]=max_h + Bricks[i].h; // �ִ� ���� ���
        res = max(res, dy[i]);
    }

    cout << res << endl;

    return 0;
}
