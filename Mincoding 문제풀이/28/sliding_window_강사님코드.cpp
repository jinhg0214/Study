#include<iostream>
using namespace std;
int main()
{
    int n = 8;//음식 개수
    int r = 2;//범위 거리
    int arr_temp[] = { 65, 65, 81, 66, 65, 65, 69, 69 };
    int arr[16] = { 0 }; // 0~7 인덱스 원본 8~15 인덱스 까지 복사본

    // 원형으로 만들지 않고 아예 2*n 사이즈의 배열을 만듬 (길게 펼침)
    for (int x = 0; x < 8; x++)
    {
        arr[x] = arr_temp[x];
        arr[x + n] = arr[x];
    }

    // 로테이션 준비
    // 원하는것 은 : 각 음식이 몇개씩 있는가??  3개 이상이면 땡

    int dat[201] = { 0 };
    int check = 0;

    // 슬라이딩 윈도 해주는데 확인할 구간은
    // 2 * r +1개 를 확인

    for (int x = 0; x < 2 * r; x++)
    {
        //2*r개에 대한 처리
        dat[arr[x]]++;
        if (dat[arr[x]] >= 3)
        {
            check = 1;
        }
    }

    for (int x = 0; x < n; x++)
    {
        //2*r 개-> 2*r+1개를 확인

        dat[arr[x + 2 * r]]++;
        // 2*r+1개의  음식에 대한 처리

        if (dat[arr[x + 2 * r]] >= 3) {
            check = 1;
        }
        // 다음 구간에 겹치는 음식만 남기기 위해서

        // 현재 구간의 맨앞 data를 삭제

        dat[arr[x]]--;
    }


    if (check == 1)cout << "노";
    else cout << "예스";

    return 0;
}