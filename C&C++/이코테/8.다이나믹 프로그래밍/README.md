# **다이나믹 프로그래밍 DP**

## **중복되는 연산을 줄이자**

- 컴퓨터로 해결하기 어려운 문제
    - 최적의 해를 구하기에 시간이 매우 많이 필요하거나, 메모리 공간이 매우 많이 필요함
- 어떤 문제들은 메모리 공간을 약간 더 사용하면, 연산 속도를 비약적으로 증가시킬 수 있다.
- 탑다운, 바텀업, 메모이제이션

### 메모이제이션

- 대표적 문제 : 피보나치 수열 문제
    
    ```cpp
    #include <iostream>
    
    using namespace std;
    
    int fibo(int x) {
    	if (x == 1 || x == 2) {
    		return 1;
    	}
    	else {
    		return fibo(x - 1) + fibo(x - 2);
    	}
    }
    
    int main() {
    	
    	cout << fibo(4);
    
    	return 0;
    }
    ```
    
    ```cpp
    #include <iostream>
    
    using namespace std;
    
    int arr[101] = { 0 };
    
    int fibo(int x) {
    	if (x == 1 || x == 2) {
    		return 1;
    	}
    	else if (arr[x] != 0) { // 한번 계산한적이 있다면 그대로 반환
    		return arr[x];
    	}
    	else {
    		arr[x] = fibo(x - 1) + fibo(x - 2);
    		return arr[x];
    	}
    }
    
    int main() {
    	cout << fibo(11);
    
    	return 0;
    }
    ```
    
- 즉, 큰 문제를 작게 나누고, 같은 문제라면 한번씩만 풀어 문제를 효율적으로 해결하는 알고리즘
- 큰 문제를 해결하기 위해, 작은 문제를 호출하는 방식 : 탑다운 방식(Top-Down)
- 단순히 반복문을 이용하여 소스코드를 작성, 작은 문제부터 차근차근 답을 도출 : 바텀 업 방식(Bottom-Up)
    
    ```cpp
    #include <iostream>
    
    using namespace std;
    
    int arr[101] = { 0 };
    
    int main() {
    	arr[1] = 1;
    	arr[2] = 2;
    	int n = 99;
    
    	for (int i = 3; i < n + 1; i++) {
    		arr[i] = arr[i - 1] + arr[i - 2];
    	}
    
    	cout << arr[n];
    
    	return 0;
    }
    ```
    
- 바텀업 방식에 사용되는 결과 저장용 리스트를 DP 테이블이라고 부름
- 가능하면 재귀함수 방식보다, 바텀업 방식으로 구현할 것을 권장함.