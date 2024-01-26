#include <iostream>

using namespace std;

int N, M;
int arr[100001];
int cycle = 0;
int ans = 0;

// 노드의 부모를 찾는 함수
int findBoss(int target) {
	if (arr[target] == target) 
		return target; // 만약 부모가 자기 자신이라면 그 노드가 부모임
	//int boss = findBoss(arr[target]);
	// arr[target] = boss;
	return arr[target] = findBoss(arr[target]);
}

// 노드를 묶는 함수 
void setUnion(int a, int b) {
	int aboss = findBoss(a);
	int bboss = findBoss(b);
	// b의 부모를 a의 부모로 설정한다
	if (aboss != bboss) 
		arr[bboss] = aboss; 
}

int main() {
	// freopen_s(new FILE*, "input.txt", "r", stdin);

	scanf("%d %d", &N, &M);

	// union-find 초기화 : 자기 자신으로 부모를 초기화 시켜둠
	for (int i = 0; i <= N; i++) 
		arr[i] = i;

	// m개의 에지를 입력받는다 
	while(M--) {
		int a, b;
		scanf("%d %d", &a, &b);
		// a와 b를 입력받고 부모가 다르다면, 묶어준다
		if (findBoss(a) != findBoss(b)) {
			setUnion(a, b);
		}
		// 부모가 같다면? 사이클 발생이므로, 사이클 개수 증가
		else {
			cycle++;
		}
	}
	
	for (int i = 1; i <= N; i++) {
		if (arr[i] == i) ans++;
	}

	// 
	printf("%d\n", ans - 1 + cycle);

	return 0;
}