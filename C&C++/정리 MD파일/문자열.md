# 문자열

2021년 7월 28일 

#문자열 #string #파싱

# 개요

---

ASCII / Unicode

- char 정리
- char string.h
- strlen은 for문 안에 넣으면안됨
- strcpy 대신 memcpy 쓰는거 설명
- string class 소개

---

### 인코딩 방식

C 언어는 ASCII만 사용(Unicode는 따로 Lib)

C++ 역시 기본 ASCII, Unicode Lib

Java는 기본이 Unicode

C# 도 기본이 Unicode

ASCII : 

UTF-8 :1~4

UTF-16 : 2~4

# Cstring, String.h, String 차이

---

P.S.에서는 C++의  string class 사용. 이게 더 편함.

간단한 건 char로 처리

복잡한 것은 string class(C++)을 쓰면

문자열을 쉽게 처리할 수 있음.

그러나 임베디드 개발할 때는 c언어 `string.h`이용

로그 관련 처리할 때 엄청나게 씀!!

strlen, strcpy, strcat, strstr등등 멤버함수 알아둘것!

### cstring, string.h, string 차이

- cstring // strcmp strlen 들어있는 "C언어" Lib
- string.h // strcmp strlen 들어있는 "C언어" Lib. C++ 컨버젼 버전
- string // strcmp strlen 대신 string class를 쓸때 사용하는 Lib

# string과 char배열의 차이

---

string은 기본 자료형이 아닌 객체!

char형 배열은 기본 자료형

string은 \0을 담지 않음

char배열은 마지막에 \0을 담음

---

### iostream

Microsoft <iostream>과 Linux GCC의 <iostream>은 다름!

입력과 결과값은 같지만 내부 구현은 다르다

---

`<string.h>` 에서 문자열과 관련된 자주쓰는 함수

- `int strcmp(const char* string1, const char* string2);` 
두 문자열을 구성하는 문자들을 비교, 동일하면 0을 반환한다
- `int stricmp(const char* string1, const char* string2);` 
알파벳 대문자, 소문자를 구분하지 않고 strcmp와 동일한 기능 수행
- `strcat`, `strncat` : 문자열을 지정한 부분만큼 합친다
- `strstr` : 특정한 문자열을 다른 문자열에서 검색
- `strlen` : 문자열 길이

`<string>` 에서 자주쓰는 함수 

- 정리해볼 것

# 문자열 파싱

2021년 8월 5일

C언어 파싱 스타일 : strlen, strstr등을 사용해서 파싱

C++, Java, C#, Python 파싱 스타일 : index of, substring등을 이용

C++은 split, replace 이 없음!

요즘 코테에서 엄청 자주나옴!!

- str.find 쓰면 문자열을 한번 돌기 때문에 O(n)

C++ string은 replace split이 없음!!!

- replace
    
    ```cpp
    #include <iostream>
    #include <string>
    using namespace std;
    
    int main()
    {
        string str = "ABCOOOABCOOOOOOABCABC";
    
        //ABC 다 찾아서
        //KFCWORLD 라는 문자열로 전부 교체 replace
        int a = 0;
        int size = 3;
    
        while (1) {
            a = str.find("ABC");
    
            if (a == -1) break;
    
            str.erase(a, 3); // 찾은 index부터 "ABC"만큼 삭제
    
            str.insert(a, "KFCWORLD");    // "그 위치에 KFCWORLD삽입"
    
            a = a + 8;
        }
    
        cout << str;
    
        return 0;
    }
    ```
    
- split
    
    ```cpp
    #include <iostream>
    #include <string>
    using namespace std;
    
    int main()
    {
        string str = "ABO|OOO|ABCAB|C";
        string table[4];
        int tn = 0;
    
        // '|' bar를 기준으로 문자열들을 파싱하여 
        //각 테이블 index에 순서대로 채워넣기
    
        //table[0] = ABO
        //table[1] = OOO
        //...
    
        int a = 0;
        int b = 0;
    
        str += "|";
        while (1) {
            b = str.find('|', a);
            if (b == -1) break;
            int size = b - a;
    
            table[tn] = str.substr(a, size);
            tn++;
            a = b + 1;
        }
    
        return 0;
    }
    ```
    
- validCheck 유효성 검사
    
    ```cpp
    #include <iostream>
    #include <string>
    using namespace std;
    
    string id;
    
    // 따로 함수로 빼서 검사
    // 탈락 조건들을 나열하고, 탈락시 false를 반환하는게 빠름
    bool isValid()
    {
        int n = id.size();
        //id가 3 ~ 8 글자 까지 허용 (3, 8 포함)
        if (!(n >= 3 && n <= 8)) return false;
    
        //첫글자는 대문자로 시작해야함
        if (!(id[0] >= 'A' && id[0] <= 'Z')) return false;
    
        //id에 영어 대소문자만 허용
        for (int i = 0; i < n; i++) {
            if (id[i] >= 'A' && id[i] <= 'Z') continue;
            if (id[i] >= 'a' && id[i] <= 'z') continue;
            return false;
        }
    
        //탈락조건만 넣고, 
        //여기까지 살아남았으면 합격
        return true;
    }
    
    int main()
    {
        //cin >> id;
        id = "SDasd";
        bool ret = isValid();
    
        cout << ret;
    
        //출력결과 (둘중 하나 출력)
        //OK VALID
        //NO INVALID
    
        return 0;
    }
    ```
    
- 날짜 금액을 입력받아 등급 리턴하는 문제
    
    ```cpp
    //등급 (오늘 날짜 30일 이내에)
    //브론즈 : 0 ~ 10000 미만 구매 고객
    //실버 : 10000 이상 50000 미만 구매 고객
    //골드 : 50000 이상 구매 고객
    
    //구매 날짜 입력
    
    #include <iostream>
    #include <string>
    using namespace std;
    
    //오늘날짜는 2021/07/28
    int n = 3;
    string input[3] = { "2021/07/05 5000", "2021/07/18 10000", "2021/06/04 60000" };
    
    int getPoint(string str)
    {
    		// 날짜와 금액을 구분
        int line = str.find(' '); // 먼저 띄어쓰기로 구분
        string date = str.substr(0, line);    // 0~line까지는 날짜로
        string money = str.substr(line + 1);    // line+1부터 끝까지는 금액으로
    
    		// 파싱부분 년도,월,일로 구분한다
        int a = date.find('/');
        string temp = date.substr(0, a);
        int year = stoi(temp);
    
        int b = date.find('/', a + 1);
        temp = date.substr(a + 1, b - a - 1);
        int mon = stoi(temp);
    
        int c = date.find('/', b + 1);
        temp = date.substr(b + 1, c - b - 1);
        int day = stoi(temp);
    
    		// 년도,월,일을 모두 일자로 환산
        int num = (year * 12 * 30) + (mon * 30) + day;
        int today = 2021 * 12 * 30 + 7 * 30 + 28;
    
    		// 만약오늘 날짜와 30일 차이 넘게나면 패스
        if (today - num > 30) return 0;
    
        int my = stoi(money);
    
    		// 모든 조건을 충족하면 포인트를 리턴
        return my;
    }
    
    int main()
    {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += getPoint(input[i]);
        }
    
        cout << sum;
    
        //이 회원의 등급이 무엇인지 출력하는 문제    
        //출력결과 : 실버 등급
    
        //조건 1 : 0000/00/00 포맷으로 날짜가 입력됨
        //조건 2 : 한달은 무조건 30일로 간주 (31일, 28, 29일은 고려하지 않음)
        //조건 3 : invalid 한 입력데이터는 주어지지 않음
    
        return 0;
    }
    ```
    

관련 문제들

- [ 와 ] 사이의 문자열 추출
    
    ```cpp
    #include <iostream>
    #include <string> 
    using namespace std;
    
    int main()
    {
        string str = "ABCDEF[1234]ABCDE";
    
        //열기 괄호 [ 와
        //닫기 괄호 ] 사이에 있는 문자열을 추출(파싱)
    
        //출력 find 메서드 substr 메서드 사용하시면 됩니다.
    
        int a = str.find("[");
        int b = str.find("]", a + 1);
    
        int size = b - a - 1;
    
        string ret = str.substr(a+1, size);
    
        int n = stoi(ret);
    
        return 0;
    }
    ```
    
- 여러 [ 와 ] 사이의 문자열 추출
    
    ```cpp
    #include <iostream>
    using namespace std;
    
    int main()
    {
        string str = "ABCDEF[ABCD]ABCDE[ERW]QQ[RRTYU]QQ[Q]";
    
        //괄호 안에 있는 [ ] 문자열을 파싱하여서
        //1. 한 문자열로 합치기 (+)
        //2. 역순으로 출력 (for 출력)
    
        //ABCDERWRRTYU
        //UYTRRWREDCBA
    
        int a = 0;
        int b = 0;
        string sum;
        while (1)
        {
            a = str.find('[', a);
            if (a == -1) break;
            b = str.find(']', a + 1);
    
            int size = b - a - 1;
            string temp = str.substr(a + 1, size);
            sum += temp;
    
            a = b + 1;
        }
    
        
        for (int i = sum.size() - 1; i >= 0; i--) {
            cout << sum[i];
        }
    
        return 0;
    }
    ```
    
- 여러 [ 와 ]사이의 문자열을 추출하고, 합을 출력
    
    ```cpp
    #include <iostream>
    #include <string>
    using namespace std;
    
    int main()
    {
        string str = "QWE[1234]TR[1000][3000]BBQ[4321]AA";
    
        //괄호 안에 있는 수들의 전체 합 출력 (정답 : 9,555)
    
        int a = 0;
        int b = 0;
    
        int sum = 0;
        while (1) {
    
            a = str.find('[', a);
            if (a == -1) break;
            b = str.find(']', a + 1);
    
            int size = b - a - 1;
            string temp = str.substr(a + 1, size);
            int num = stoi(temp);
            sum += num;
    
            a = b + 1;
            int d = 1;
        }
    
        cout << sum;
    
        return 0;
    }
    ```
    
- [ ] 안의 내용물 출력
    
    ```cpp
    string arr = "AB[426]5T[ATS]HA[K]";
    
    int start = 0;
    int end = 0;
    
    while (1) {
        start = arr.find('[',start);
        if (start == -1) break;
        end = arr.find(']', start + 1);
    
        cout << arr.substr(start+1, end - start - 1) << " ";
    
        start = start + 1;
        end = end + 1;
    }
    ```
    
- ]] 괄호가 여러개일땐 신경 안써도됨. 어짜피 find 함수는 가장 앞에있는 괄호의 위치를 리턴함

 문제는 [ [ [ [ [ [와 같이 여는 괄호가 여러개일때?? a 와 c를 두고 이를 이용해, 마지막  [ 의 위치 찾기

- [ [ [ [ [ ]와 같이 괄호가 여러개?
    
    ```cpp
    string str = "AB[426][5T[[[ATS]]]H]A[[K]";
    
        int a = 0;
        int b = 0;
        int c = 0;
    
        while (1) {
           
            a = str.find('[', a);
            b = str.find(']', a + 1);
            c = str.find('[', a + 1);
    
            if (a == -1)break;
    
            // c가 b를 넘어갈때 까지 반복해야함
            while (c != -1 && c < b) {
                if (b > c) {
                    a = c;
                }
                c = str.find('[', a + 1);
            }
            
            cout << str.substr(a+1, b - a-1) << " ";
    
            a = a + 1;
            b = b + 1;
                
        }
    ```
    
    ```cpp
    string str = "AB[426][5T[[[ATS]]]H]A[[K]";
    
        int a = 0;
        int b = 0;
        int c = 0;
    
        while (1) {
           
            a = str.find('[', a);
            if (a == -1) break;
    
            b = str.find(']', a + 1);
            if (a == -1) break;
    
            // a와 c를 이용해서 ] 왼쪽에 
            while (1) {
                c = str.find('[', a + 1);
                if (c == -1) break;
                if (b > c) {
                    a = c;
                }
                else break;
            }
            
            cout << str.substr(a+1, b - a-1) << " ";
    
            a = a + 1;
            b = b + 1;
                
        }
    ```
    

---

- 프린터 문제  [https://programmers.co.kr/learn/courses/30/lessons/42587](https://programmers.co.kr/learn/courses/30/lessons/42587)
    
    ```cpp
    /*
    설계 phase:
    
    구조체로 우선순위와 인덱스를 묶었음!! 페어도 사용 가능함
    
    큐가 빌때까지 반복
    1. max값 찾기
    2. q.front()가 맥스인가? 
    	아니라면 다시 맨 뒤로(push, pop)
    	맞다면 
    			입력받은 location과 q.front()의 인덱스가 같은지 확인. 맞다면 answer++ return
    			아니라면 location과 q.front()의 인덱스와 다르면 pop() cnt++
    */
    #include <string>
    #include <vector>
    #include <queue>
    #include <algorithm>
    #include <iostream>
    using namespace std;
    
    int solution(vector<int> priorities, int location) {
        int answer = 0;
    
        struct node {
            int prio;
            int index;
        };
    
        queue<node>q; 
    
        int t = priorities.size(); // 크기 
    
        for (int x = 0; x < t; x++) // 묶어서 큐 등록
        {
            q.push({ priorities[x],x }); // 우선순위와 인덱스를 구조체를 생성하면서 저장
        }
    
    		// 큐가 빌때까지 반복
    		// 최대값을 구하고
    		// 현재 q.front()와 최대값을 비교
    		// if) Max가 더 크면 뒤에 넣고 다시 while처음으로
        // else) Max와 같으면 
    		//     if)Max의 idx가 location인지 확인 => 맞으면 출력하고 answer++ 후 return answer.
    	  //     else)  출력하고 answer++;
    
        while (!q.empty())
        {
    				// 1. 최대값 찾기
            int Max = -21e8; // -21 * 10^8
            for (int x = 0; x < q.size(); x++) {    // 우선순위가 가장 높은것 찾기
                if (Max < q.front().prio)
                {
                    Max = q.front().prio;
                }
                q.push(q.front()); // 큐의 크기만큼 순회하면서 반복
                q.pop();
            }
    
    				// 2. q.front와 max를 비교.
            if (Max > q.front().prio) { //큐에 프런트가 맥스보다 작으면 뒤로 가시오
                q.push(q.front());
                q.pop();
            }
    
            else // 큐에 프런트가 맥스라면
            {
                if (location == q.front().index) { // 입력받은 인덱스가 큐에 프런트의 인덱스와 같다면
                    answer++;
                    return answer;                  // 몇번째로 출력되는지 리턴하고
                }
                else {                 // 입력받은 인덱스가 큐에 프런트인덱스와 다르다면
                    q.pop();        // 출력하고 
                    answer++;       // 몇번째 증가
                }
            }
    
        }
        return answer;
    }
    
    int main()
    {
        vector<int> priorities = { 1,1,9,1,1,1 };
        int location = 0;
        int ret = solution(priorities, location);
        cout << ret;
        return 0;
    }
    ```
    

---

### string 형 변환

`<string>` 라이브러리에 저장되어있음

- to_string(int n) :  int to string
- stoi(string str) : string to int
- 문자열에서 숫자 또는 알파벳을 찾기(커스텀함수)
    
    ```cpp
    // 직접 find 커스텀 함수를 구현하여 위치를 반환하도록한다
    
    #include <iostream>
    #include <string>
    
    using namespace std;
    
    // 문자열과 검색 위치를 받고
    // 숫자를 찾아 idx를 리턴하는 함수
    int findnum(string& str, int index) {
    
        int n = str.length();
    
        for (int i = index; i < n; i++) {
            if (str[i] >= '0' && str[i] <= '9') {
                return i;
            }
        }
        return -1;
    
    }
    
    // 문자열과 검색 시작 위치를 받아 알파벳을 찾는 함수
    // 
    int findchar(string& str, int index) {
    
        int n = str.length();
    
        for (int i = index; i < n; i++) {
            if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <='z')) {
                return i;
            }
        }
        return -1;
    
    }
    
    int main()
    {
        string str = "ASDF1031BBQFESTIVAL1335ASDF";
    
        // 0~9 사이의 숫자를 문자로 바꾼 후, 7 더해서 출력하기
        int a, b;
        a = 0;
        while (1) {
            a = findnum(str, a);    // 사용자 지정 함수 findnum을 이용함. 알파벳도 이처럼 이용가능할듯
            if (a == -1)break;
    
            b = findchar(str, a + 1);
            if (b == -1) break;
    
            string result = str.substr(a, b - a);
    
            cout << stoi(result) + 7 << " ";
            a = b + 1;
            b = b + 1;
        }
    
        return 0;
    }
    ```
    
    ```cpp
    #include<iostream>
    
    #include<string>
    using namespace std;
    int findnum(string& arr, int index)
    {
        int n = arr.length();
        for (int x = index; x < n; x++)
        {
            if (arr[x] >= '0' && arr[x] <= '9')
            {
                return x;
            }
        }
        return -1;
    
    }
    int findchar(string& arr, int index)
    {
    
        int n = arr.length();
        for (int x = index; x < n; x++)
        {
            if (!(arr[x] >= '0' && arr[x] <= '9'))
            {
                return x;
            }
        }
        return -1;
    }
    int main()
    {
        string arr = "ABT1031BT1335Aab";
        //    0에서 9사이의 문자를 숫자로 바꾼 후
        //  7 더해서 출력하기
        int a, b;
        a = 0;
        while (1)
        {
            a = findnum(arr, a);
            if (a == -1)break;
            b = findchar(arr, a + 1);
            if (b == -1)break;
    
            string result = arr.substr(a, b - a);
            cout << stoi(result) + 7 << endl;
            a = b + 1;
    
        }
    
        return 0;
    }
    ```
    
- 문자열에서 target 문자열 찾기
    
    ```cpp
    #include <iostream>
    #include <string>
    
    using namespace std;
    
    int main() {
    	string str = "asdOKAYUfsafl1230OKAOOKAMIMIOYU41849saldkfgjsadKORONEl2380OKAYU49234";
    	string target = "OK";
    
    	int cnt = 0;
    	int n = target.length();
    
    	int a = 0;
    
    	while (1) {
    		a = str.find(target, a);
    		if (a == -1)break;
    
    		cnt++;
    
    		a = a + n;
    	}
       
    	cout << cnt;
    
    	return 0;
    }
    ```
    
    ```cpp
    string str = "asdOKAYUfsafl1230OKAYU41849saldkfgjsadl2380OKAYU49234";
        string target = "OKAYU";
        
        int n = target.length();
    
        int a;
        a = 0;
        int cnt = 0;
    
        while (1) {
            a = str.find(target, a);
            if (a == -1)break;
    
            cnt++;
    
            a = a + n;
        }
    
        cout << cnt;
    ```
    
- '#' 기준으로 split 하기
    
    ```cpp
    #include<iostream>
    
    #include<string>
    
    #include<vector>
    using namespace std;
    
    int main()
    {
        string arr = "KFC#MC#MST#BBQ";   
        // KFC
        // MC
        // MST
        // BBQ
        int a, b;
        a = 0;
        vector<string>result;
        while (1)
        {
            b = arr.find('#', a);
            if (b == -1) // 파싱할때는 마지막 처리에 신경써줄것!
            {
                b = arr.length();
                string temp = arr.substr(a, b - a);
                result.push_back(temp);
                break;
            }
            string temp = arr.substr(a, b - a);
            result.push_back(temp);
            a = b + 1;
        }
        int t = result.size();
        for (int x = 0; x < t; x++)
        {
            cout << result[x] << '\n';
        }
    
      
    
        return 0;
    }
    ```
    
    ```cpp
    // 문자열을 앞에서부터 지우면서 하는 버전
    
    #include <iostream>
    #include <string>
    #include <vector>
    
    using namespace std;
    
    int main() {
    
    	string str = "KFC#MC#MST#BBQ";
    	vector<string> vect;
    	int a;
    
    	str += '#';
    
    	while (1) {
    		a = str.find('#');
    		if (a == -1) {
    			break;
    		};
    
    		string tmp = str.substr(0, a);
    		cout << tmp << endl;
    		vect.push_back(tmp);
    
    		str.erase(0, tmp.length() + 1);
    
    	}
    
    	return 0;
    }
    ```
    
- replace 연습
    
    ```cpp
    #include<iostream>
    #include<string>
    
    using namespace std;
    
    int main()
    {
        string str = "BBKFCAAAAAKFCAA";
        string target = "KFC";
    
        // KFC문자열을 BBQ로 바꾼 후 문자열 전체 출력하기
        // BBBBQAAAAABBQAA
        int a = 0;
        int n = target.length();
    
        while (1) {
            a = str.find(target, a);
            if (a == -1)break;
    
            str.replace(a, n, "BBQ");
    
            a = n + 1;
        }
    
        cout << str;
    
        return 0;
    }
    ```
    
    ```cpp
    // replace 구현하기 
    
    #include<iostream>
    #include<string>
    
    using namespace std;
    
    // 직접 구현한 replace 함수 C++에는 replace가 있지만 C에는 없음!
    void replace(string& str, string before, string after) {
        // 문장 길이구하기
        int bn = before.length();
        int an = after.length();
    
        int a = 0;
        int b;
    
        while (1) {
            a = str.find(before, a);
            if (a == -1)break;
            str.erase(a, bn); // bn만큼 지워주고
            str.insert(a, after); // after를 그 위치에 넣어줌
            a += an;
        }
    
        return;
    }
    
    int main()
    {
        string str = "BBKFCAAAAAKFCAA";
    
        replace(str, "KFC", "BBQ");
    
        cout << str;
    
        return 0;
    }
    ```
    
    ```cpp
    #include<iostream>
    
    #include<string>
    
    #include<vector>
    using namespace std;
    int main()
    {
    
    string arr = "ASDFASDF";
    string before = "FA";
    string changed = "KKK";
    
    arr.replace(arr.find(before), before.length(), changed);
            // 바꾸고 싶은 문자열    // 바꾸고 싶은 문자열의 길이  //  바꿀 문자열 
    
    return 0;
    }  // replace  함수 사용법
    ```
    
- https:// .com문제 (mincoding Lv25.5 6번 문제)
    
    http://, https:// 를 [와 {로 보고,
    
    .com, .co.kr, .org등을 ], }로 보고 처리한다.
    
    위의 [ [ [ [ ] 괄호 문제와 같이 a b c로 놓고 c가 b앞에 있는지 보고 처리
    

# **1. 문자열 처리**

| C++에서 가장 번거로운것이 문자열 처리!

1.  getline은 앞뒤 개행 문자들도 다 읽어온다.
    
    ```cpp
    string s
    getline(cin, s);
    ```
    
2. 숫자형 문자 (”0” ~ “9”)를 int로 바꾸고 싶을땐, `atoi`말고 `-'0'` 을 빼면 더 쉬움
3. `str.find(str2)` 를 했는데 못찾은 경우, `string:npos` 를 반환하지만, -1을 반환한다고 생각하면 됨.
4. `str.find(str2, index)` 는 index 부터 탐색 시작
5. `str.erase(index, size)` 삭제 시작할 index, 그리고 사이즈

# 2. 문자열 자르기

1. string 클래스 사용시 
    
    ```cpp
    #include <string>
    using namespace std;
    
    int main() {
       string lines = "hello,my,name,is";
       size_t previous = 0, current; 
    	// size_t 형이란? 문자열이나 메모리의 사이즈를 나타낼 때 사용함. 부호없는 32비트 정수
      // unsinged int 랑 차이점은?
       current = lines.find(','); //찾지못한경우 npos반환
    
       while(current !=string::npos) {
           string substring = lines.substr(previous, current - previous); 
    				// previous에서 current - previous 만큼 자른다
           cout << substring << " ";
           previous = current + 1; // 이전 끝자리보다 한칸 앞에서 다시 검색 시작
           current = lines.find(',', previous);  // previous에서 다음 ,를 찾는다
       }
       cout << lines.substr(previous, current - previous);
       return 0;
    }
    ```
    
2. sstream 클래스 이용시 
    
    ```cpp
    #include <sstream>
    
        string lines = "hello my name is";
        stringstream ss(lines);
        string tmp;
        while ((ss >> tmp)) {
            log.push_back(tmp);
            cout << tmp << "\n";
        }
    ```
    
    ```cpp
    string lines = "2002:04:21";
        istringstream iss(lines);
        string token;
        while(getline(iss, token, ":")) {
            cout << token << "\n";
        }
    ```
    

# 3. 대소문자 변환

transform 함수 이용

```cpp
// 대문자 -> 소문자
string word = "HELLO";
transform(word.begin(), word.end(), word.begin(), ::tolower);
cout<<word<<"\n"; //hello

// 소문자 -> 대문자
for(int i=0; i<word.size(); i++) {
    word[i] = ::toupper(word[i]);
}
cout<<word<<"\n"; //HELLO
```

# 4. 특정 문자열 찾기

```cpp
using namespace std;
    string line = "hello my namloe is siyeon";
    string word = "lo";
    int pos = line.find(word);

    while(pos != string::npos) { //찾지못할때까지 반복
        cout<<line.substr(pos, word.size()) << "\n";
        pos = line.find(word, pos+word.size());
    }
```

# 5. 알파벳 제외 특수문자 공백으로 바꾸기

replace_if 이용