python의 dic형식 {key, value}의 자료구조

또는 C++의 Map, Unordered_map과 같은 자료구조

음수는 카운팅 불가능!

```cpp
// 2중 for문을 이용한 방법
    for (int i = 0; i < 8; i++) {
        for (int j = 1; j <= 9; j++) {
            if (arr[i] == j) { // 해당 원소가 있다면, 
                res[j]++; // 그 원소의 값을 증가시킴
            }
        }
    }

    for (int i = 1; i <= 9; i++) {
        cout << i << ":" << res[i] << "개" << endl;
    }
```

```cpp
// for문 한번만 이용하는 방법? DAT
    for (int i = 0; i < 8; i++) {
        int val = arr[i];
        cnt[ val ]++;
    }

    for (int i = 1; i <= 9; i++) {
        cout << i << ":" << cnt[i] << "개" << endl;
    }
```

조건 파악 후 사용할것! 

index가 -1일때 이 개수? 카운팅 불가!!

```cpp
#include <iostream>

using namespace std;

char arr[8] = { 'A', 'B', 'C', 'A', 'D', 'B', 'C' };
int cnt[26] = { 0 };

int main()
{
    for (int i = 0; i < 8; i++) {
        char val = arr[i];
        cnt[arr[i] - 'A']++;
    }

    for (int i = 0; i < 26; i++) {
        if (cnt[i] != 0) {
            cout << char(i + 'A');
        }
    }

    return 0;
}
```

```cpp
#include<iostream>
using namespace std;

int de;
int main()
{
    char vect[9] = "ABCQADBC"; 
    
    int flag[100] = { 0 }; 
    for (int i = 0; i < 8; i++) {
        int val = vect[i]; 
        flag[val] = 1;
    }

    for (char target = 'A'; target <= 'Z'; target++) {
        if (flag[target] == 1)
            cout << target;
    }

    return 0;
    
}
```

DAT을 이용한 정렬?

## DAT 를 이용한 정렬

- 계수 정렬 : countSort ⇒ O(n)
    
    ```cpp
    #include <iostream>
    
    using namespace std;
    
    int main() {
    	int arr[7] = { 3,9,1,2,1,3,4 };
    	int bucket[11] = { 0 };
    
    	// DAT
    	for (int x = 0; x < 7; x++) {
    		bucket[arr[x]]++;
    	}
    
    	// 누적합
    	for (int x = 1; x < 11; x++) {
    		bucket[x] += bucket[x - 1];
    	}
    
    	// 값넣기
    	int result[11] = { 0 };
    	for (int x = 0; x < 7; x++) {
    		int t = arr[x];
    		result[bucket[t]--] = t;
    	}
    
    	return 0;
    }
    ```