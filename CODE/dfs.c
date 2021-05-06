#include<stdio.h>
#include<stdlib.h>
#include<time.h>

double size;
void dfs(int n, int a[10][10], int u, int t[10][10], int s[]){
    int v;
    static int k = 0;
    s[u] = 1;
    for(v = 0; v < n; v++){
        if(a[u][v] == 1 && s[v] == 0){
            t[k][0] = u;
            t[k][1] = v;
            k++;
            dfs(n, a, v, t, s);
        }
    }
    size = sizeof(t) + sizeof(s);
}

void main(){
    int flag = 0;
    int n, i, j, source, a[10][10], s[10], t[10][10];
    double clk;
    clock_t startTime, endTime;
    printf("Enter the number of nodes\n");
    scanf("%d", &n);
    printf("Enter the adjacency matrix\n");
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            scanf("%d", &a[i][j]);
    printf("Enter the source\n");
    scanf("%d", &source);
    for(i = 0; i < n; i++)
        s[i] = 0;
    startTime = clock();
    dfs(n, a, source, t, s);
    endTime = clock();
    for(i = 0; i < n; i++){
        if(s[i] == 0)
            flag = 1;
    }
    if(flag  == 1)
        printf("The graph is not connected\n");
    else    
        printf("The graph is connected\n");
    printf("The DFS traversal path is\n");
    for(i = 0; i < n-1; i++){
        printf("%d->%d\n", t[i][0], t[i][1]);
    }
    clk = ((double)(endTime - startTime)) / CLOCKS_PER_SEC;
    printf("The time taken is %f\n", clk);
    printf("The space taken is %f Bytes\n",size + ((n*n)*sizeof(int)));
}