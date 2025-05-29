#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define INF 0x3f3f3f3f
int transint(char *str) {
    int a = 0;
    for (int i = 0; i < strlen(str); i++) {
        a = a * 26 + str[i] - 'A';  
    }
    return a;
}
int s, t;
struct Line {
    int r;
    int w;
} line[1005];
int g[30000][1005];
int cnt[30000]={0};
int deep[30000]={0};
int bfs() {
    int que[30000];
    int front = 0, rear = 0;
    que[rear++] = s;
    deep[s] = 1;
    while (front < rear) {
        int top = que[front++];
        for (int i = 0; i < cnt[top]; i++) {
            int z = g[top][i];
            if (!deep[line[z].r] && line[z].w) {
                deep[line[z].r] = deep[top] + 1;
                que[rear++] = line[z].r;
                if (deep[t])
                    return 1;
            }
        }
    }
    return 0;
}
int dfs(int x, int mix) {
    if (x == t ||!mix)
        return mix;
    int ap = 0;
    for (int i = 0; i < cnt[x]; i++) {
        int z = g[x][i];
        if (deep[x] < deep[line[z].r] && line[z].w) {
            int p;
            if (mix < line[z].w)
                p = dfs(line[z].r, mix);
            else
                p = dfs(line[z].r, line[z].w);
            ap += p;
            mix -= p;
            line[z].w -= p;
            line[z+1].w += p;
            if (!mix)
                return ap;
        }
    }
    return ap;
}
int dinic() {
    int sum = 0;
    while (bfs()) {
        sum += dfs(s, INF);
    }
    return sum;
}
int main() {
    char str1[4], str2[4];
    int m;
    scanf("%s %s %d", str1, str2, &m);
    s = transint(str1);
    t = transint(str2);
    for (int i = 0; i < m; i++) {
        char strx[4], stry[4];
        int w;
        scanf("%s %s %d", strx, stry, &w);
        int a = transint(strx);
        int b = transint(stry);
        line[2*i].r = b;
        line[2*i].w = w;
        line[2*i+1].r = a;
        line[2*i+1].w = 0;
        g[a][cnt[a]++] = 2*i;
        g[b][cnt[b]++] = 2*i+1;
    }
    printf("%d\n", dinic());
}