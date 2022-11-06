#union #find #unionFind #알고리즘 #자료구조

2021년 8월 25일 

---

- 각각 독립된 데이터들을 그룹화시켜서 관리?
- Disjoint Set(서로소 집합)이라고도 불림
- 같은 그룹인지 확인하고싶으면 각각 FindBoss()호출해서 비교
- 멤버함수
    - setUnion(char a, char b) : 그룹화 시키는 함수
    - findBoss(char target) : 그룹의 장을 찾는 함수
    - Union-Find 자료구조 구현
        
        ```cpp
        #include <iostream>
        
        using namespace std;
        
        int arr[100];
        
        char findBoss(char member) {
        	if (arr[member] == 0) return member;
        	char boss = findBoss(arr[member]);
        	return boss;
        }
        
        void SetUnion(char a, char b) {
        
        	char aboss = findBoss(a);
        	char bboss = findBoss(b);
        	if (aboss == bboss) return;
        	arr[bboss] = aboss;
        
        }
        
        int main() {
        
        	SetUnion('A', 'B');	
        	SetUnion('E', 'F');
        	SetUnion('B', 'F'); 
        	SetUnion('F', 'A');
        	SetUnion('C', 'D');
        
        	char input1, input2;
        
        	cin >> input1 >> input2;
        
        	if (findBoss(input1) == findBoss(input2)) {
        		cout << "같은 그룹";
        	}
        	else {
        		cout << "다른 그룹";
        	}
        }
        ```
        
    - 몇개의 그룹이 있는지 확인하는 문제
        
        ```cpp
        /*
        A,E
        B,D
        F,E
        C,E
        D,B
        C,A
        
        몇개의 그룹 존재?
        */
        
        #include <iostream>
        #include <vector>
        
        using namespace std;
        
        char arr[200];
        
        char findBoss(char target) {
        	if (arr[target] == 0) return target;
        	char boss = findBoss(arr[target]);
        	arr[target] = boss; // 효율성
        	return boss;
        }
        
        void setUnion(char a, char b) {
        
        	int aboss = findBoss(a);
        	int bboss = findBoss(b);
        	// if (aboss == bboss) return;
        	arr[bboss] = aboss;
        }
        
        int main() {
        	
        	vector<string> vect = {
        		"AE",
        		"BD",
        		"FD",
        		"CE",
        		"DB",
        		"CA"
        	};
        
        	int len = vect.size();
        	int cnt = len;
        
        	for (int x = 0; x < len; x++) {
        		if (findBoss(vect[x][0]) != findBoss(vect[x][1])) { // 둘이 보스가 다르면
        			setUnion(vect[x][0], vect[x][1]);
        			cnt--;
        		}
        	}
        
        	// 그룹이 몇개인가?
        	cout << cnt;
        
        	return 0;
        }
        ```
        
- Union-Find를 이용하면 양방향 사이클이 존재하는지 확인할 수 있음
    - n개의 간선 입력 받고 사이클이 존재하는지 확인
        
        ```cpp
        #include <iostream>
        
        using namespace std;
        
        int arr[100];
        
        char findBoss(char target) {
        	if (arr[target] == 0)return target;
        	char boss = findBoss(arr[target]);
        	arr[target] = boss;
        	return boss;
        }
        
        void setUnion(char a, char b) {
        	int aboss = findBoss(a);
        	int bboss = findBoss(b);
        
        	//이미 보스가 같다면 사이클이 존재하는것임!
        	if (aboss == bboss) { return; }
        	arr[bboss] = aboss;
        }
        
        int main() {
        
        	int n;
        	cin >> n;
        
        	for (int i = 0; i < n; i++) {
        		char input1, input2;
        		cin >> input1 >> input2;
        		if (findBoss(input1) == findBoss(input2)) {
        			cout << "사이클 존재" << endl;
        			return 0;
        		}
        		setUnion(input1, input2);
        	}
        	cout << "사이클 없음" << endl;
        
        	return 0;
        }
        ```