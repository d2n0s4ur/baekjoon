#include <stdio.h>

int matrix[1001][1001];
int n, m, s;
int visited[1001];

typedef struct Queue {
    int front, back;
    int data[1001];
}   Queue;

void dfs(int from)
{
    printf("%d ", from);
    for(int i = 1; i <= n; i++)
    {
        if (matrix[from][i] && !visited[i])
        {
            visited[i] = 1;
            dfs(i);
        }
    }
}

void bfs(int from)
{
    Queue q;

    q.front = -1;
    q.back = -1;
    q.data[++q.back] = from;
    while (q.front < q.back)
    {
        int d = q.data[++q.front];
        
        printf("%d ", d);
        for (int i = 1; i <= n; i++)
        {
            if (matrix[d][i] && visited[i])
            {
                visited[i] = 0;
                q.data[++q.back] = i;
            }
        }
    }
}

int main()
{
    int start, end;
    
    scanf("%d %d %d", &n, &m, &s);
    for(int i = 0; i < m; i++)
    {
        scanf("%d %d", &start, &end);
        matrix[start][end] = 1;
        matrix[end][start] = 1;
    }
    visited[s] = 1;
    dfs(s);
    printf("\n");
    visited[s] = 0;
    bfs(s);
    return (0);
}