#include <stdio.h>

int n;
int k;
int A[100000];

int p(int x) {
	int k_req = 0;
	int i;
	for (i = 0; i < n; i++) {
		// A[i]/xの切り上げ（i番目の人が必要なりんごバックの数）を足し合わせる
		k_req += (A[i] + x - 1) / x;
	}
	return k_req <= k;
}

int main() {
	int i, lb, ub;
	scanf("%d%d", &n, &k);
	for (i = 0; i < n; i++) {
		scanf("%d", &A[i]);
	}

	// すべての人が最小値である1個のりんごを収穫するという，
	// xが最小となる状況を考えた場合，x=1となる．
	// lbの初期値はその1つ少ない値を選択する．
	lb = 0;		

	// すべての人が最大値である10^9個のりんごを収穫し,
	// かつ，りんごバックが人数分のn個しか用意されないという，
	// xが最大となる状況を考えた場合，x=10^9となる．
	// ubの初期値はその1つ大きい値を選択する．
	ub = 1E+9+1;

	while (ub - lb > 1) {
		int mid = (lb + ub) / 2;
		if (p(mid)) {
			ub = mid;
		}
		else {
			lb = mid;
		}
	}

	printf("%d\n", ub);
	return 0;
}
