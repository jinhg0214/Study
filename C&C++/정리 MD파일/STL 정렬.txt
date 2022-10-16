# STL

#STL #StandardLibrary #sort #정렬

2021년 8월 25일 

---

## 정렬

- insert sort : 하나 넣고 크기 비교후 swap, 하나 넣고 크기비교 후 swap, ... 이를 반복
    - int형 sort
        
        ```cpp
        #include <iostream>
        
        using namespace std;
        
        int main() {
        	int arr[6] = { 4,9,11,8,6,2 };
        
        	int result[6];
        
        	for (int y = 0; y < 6; y++) {
        		result[y] = arr[y]; // 하나 내리고
        
        		for (int x = y; x > 0; x--) { // 크기비교
        			if (result[x - 1] < result[x]) {
        				swap(result[x - 1], result[x]);
        			}
        			else { // 더이상 안봐도 되면 종료
        				break;
        			}
        		}
        	}
        
        	for (int i = 0; i < 6; i++) {
        		cout << result[i] << " ";
        	}
        }
        ```
        
    - 비교 대상이 여러개인 구조체 sort : compare() 함수 운용
        
        ```cpp
        #include <iostream>
        
        using namespace std;
        
        struct node {
        	int a;
        	char b;
        } arr[5];
        
        void swap(node* a, node* b) {
        	node* tmp = a;
        	a = b;
        	b = a;
        }
        
        bool compare(node front, node back) {
        
        	// 우선순위 1. 숫자는 오름차순
        	if (front.a < back.a) return true; // 앞의 숫자가 더 작아야한다: 참
        	if (front.a > back.a) return false;
        
        	// 두 숫자가 같은 경우
        	return front.b > back.b; // 문자 비교. 
        
        }
        
        int main() {
        	arr[0] = { 1, 'A' };
        	arr[1] = { 3, 'A' };
        	arr[2] = { 2, 'C' };
        	arr[3] = { 1, 'B' };
        	arr[4] = { 3, 'B' };
        
        	// 1. 숫자는 오름차순
        	// 2. 알파벳은 내림차순
        	node result[5];
        
        	for (int y = 0; y < 5; y++) {
        		result[y] = arr[y];
        
        		for (int x = y; x > 0; x--) {
        			node front = result[x - 1];
        			node back = result[x];
        
        			if (compare(front,back) == false) {
        				swap(result[x-1], result[x]);
        			}
        			else break;
        		}
        	}
        
        	for (int i = 0; i < 5; i++) {
        		cout << result[i].a << " " << result[i].b << endl;
        	}
        
        }
        ```
        

---

## STL Sort

- STL Sort를 사용하기 위해선 `<algorithm>` 헤더가 필요

STL은 자동적으로 sort 종류를 선택함

- sort → 자료가 적으면 quick sort, 많으면 heap sort
- stable sort → 자료가 적으면 insert sort, 많으면 merge sort 사용
- STL sort 테스트
    
    ```cpp
    // sort(arr, arr + 6); // default는 오름차순
    int arr[6] = { 3,6,2,1,5,8 };
    sort(arr, arr + 6, less<int>()); // 배열, 배열크기, 오름차순<자료형>
    sort(arr, arr + 6, greater<int>()); // 배열, 배열크기, 내림차순<자료형>
    
    // String형 sort
    string str = "kevinchoi";
    sort(str.begin(), str.end());
    sort(str.begin(), str.end(), greater<int>());
    
    // String 배열 정렬
    string brr[4] = { "kevin", "bob", "jane", "kate" };
    sort(brr, brr + 4);
    sort(brr, brr + 4, greater<string>());
    
    // Vector형 sort
    vector<int> vect = { 6,3,4,6,5,2,1,9 };
    sort(vect.begin(), vect.end());
    sort(vect.begin(), vect.end(), greater<int>()); // 자료형은 int이므로 int를 호출
    
    // 2차원 Vector
    vector< vector<int> > t = { {3,2}, {1,3}, {6,2} };
    sort(t.begin(), t.end()); // 앞의 원소 기준으로 정렬됨
    sort(t.begin(), t.end(), greater<vector<int>>()); // 앞의 원소 기준으로 정렬됨
    
    // pair 자료형
    pair<int, int> p;
    vector< pair<int, int> > pp = { {8,2}, {3,3}, {5,2} };
    sort(pp.begin(), pp.end()); // 앞의 원소 기준으로 정렬됨
    sort(pp.begin(), pp.end(),greater<pair<int,int>>());
    ```
    
- 다중 조건을 적용한 STL : compare 사용
    - 1. 짝수 우선.  2. 내림차순
        
        ```cpp
        bool compare(int front, int back) {
        
        	// 짝수 우선
        	if (front % 2 == 0 && back % 2 == 1) return true;
        	if (front % 2 == 1 && back % 2 == 0) return false;
        
        	// 내림차순
        	return front > back;
        
        }
        
        int main() {
        	int arr[7] = { 2,6,41,3,7,4,8 };
        
        	sort(arr, arr + 7, compare); // compare함수에 우선순위를 적용
        
        	return 0;
        }
        ```
        
    - 구조체 compare
        
        ```cpp
        bool compare(node front, node back) {
        
        	// 1. 숫자 내림차순
        	if (front.n > back.n) return true;
        	else if (front.n < back.n) return false;
        	// 문자 오름차순
        	else
        		return front.ch < back.ch;
        
        }
        
        int main() {
        	node arr[4] = {
        		'A',1,
        		'B',2,
        		'B',1,
        		'A',9,
        	};
        
        	sort(arr, arr + 4, compare);
        	return 0;
        }
        ```
        
- 'H'~'O"에 우선순위, 나머지는 내림차순
    
    ```cpp
    bool compare(char front, char back) {
    	int aa = 0;
    	int bb = 0;
    
    	// 'H'~'O'우선순위
    	if ('H' <= front && front <= 'O') aa = 1;
    	if ('H' <= back && back <= 'O') bb = 1;
    
    	if (aa == 1 && bb == 0) return true;
    	if (aa == 0 && bb == 1) return false;
    
    	// 나머지는 내림차순
    	return front > back;
    
    }
    
    int main() {
    	string str = "KEVINCHOIGOODMAN";
    
    	sort(str.begin(), str.end(), compare);
    
    	return 0;
    }
    ```
    

---

코테할때 sort한번씩 생각해볼 것! → 정렬 후에 답이 보일수도 있음