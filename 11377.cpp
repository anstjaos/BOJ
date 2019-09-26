#include <stdio.h>

int N, M, K, workCount[1005], workArr[1005][1005], pred[1005];
bool visit[1005];
int max(int a, int b) { return (a > b ? a : b); }

bool dfs(int cur)
{
	if (cur == -1) return true;

	int cnt = workCount[cur];
	for (register int i = 0; i < cnt; i++) {
		int next = workArr[cur][i];
		if (visit[next]) continue;
		visit[next] = true;
		if (dfs(pred[next])) {
			pred[next] = cur;
			return true;
		}
	}

	return false;
}

int main()
{
	scanf("%d %d %d", &N, &M, &K);
	for (register int i = 1; i <= N; i++) {
		scanf("%d", workCount + i);
		for (register int j = 0; j < workCount[i]; j++) {
			scanf("%d", &workArr[i][j]);
		}
	}

	int ans = 0;
	int cnt = 0;
	for (register int i = 1; i <= M; i++) pred[i] = -1;

	for (register int i = 1; i <= N; i++) {
		for (register int j = 1; j <= M; j++) visit[j] = false;
		if (dfs(i)) {
			ans += 1;
		}
	}

	for (register int i = 1; i <= N; i++) {
		for (register int j = 1; j <= M; j++) visit[j] = false;
		if (dfs(i)) {
			ans += 1;
			cnt += 1;
		}
		if (cnt == K) break;
		
	}
	printf("%d\n", ans);
	return 0;
}