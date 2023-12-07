#include <stdio.h>
int n, s, adj[10][10], stack[10];
int visited[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int top = -1;
int item;
void push(int item)
{
    if (top == 9)
        printf("Stack if Full \n");
    else
    {
        if (top == -1)
        {
            top = 0;
            stack[top] = item;
        }
        else
        {
            top = top + 1;
            stack[top] = item;
        }
    }
}
int pop()
{
    int k;
    if (top == -1)
        return (0);
    else
    {
        k = stack[top];
        top--;
        return (k);
    }
}
void dfs(int s, int n)
{
    int p;
    push(s);
    visited[s] = 1;
    p = pop();
    if (p != 0)
    {
        printf("%d \t", p);
    }
    while (p != 0)
    {
        for (int i = 1; i <= n; i++)
        {
            if (adj[p][i] == 1 && visited[i] == 0)
            {
                push(i);
                visited[i] = 1;
            }
        }
        p = pop();
        if (p != 0)
        {
            printf("%d \t", p);
        }
    }
}
int main()
{
    printf("Enter the no of vertices : \n ");
    scanf("%d", &n);
    printf("Enter the adjacency matrix : \n ");
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            scanf("%d", &adj[i][j]);
        }
    }
    printf("Enter the starting vertex : \n ");
    scanf("%d", &s);
    dfs(s, n);
    return 0;
}
