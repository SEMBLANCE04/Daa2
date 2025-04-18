#include<stdio.h>
#include<stdlib.h>

#define INF 99999 //infinity max value
#define min(a,b) (a<b?a:b) //find minimum of 2 value
#define MAX 100 //max size of 100 vertices

void floydWarshall(int n, int graph[MAX][MAX]);

void display(int n, int dist[MAX][MAX]){
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(dist[i][j] == INF){
                printf("INF\t");
            }
            else{
                printf("%d\t",dist[i][j]);
            }
        }
        printf("\n");
    }
}

void main(){
    int i,j,k;
    printf("Enter the number of vertices (less than 100): ");
    int n;
    scanf("%d",&n);
    int graph[MAX][MAX];
    printf("Enter the adjacency matrix (use 0 for no edge): ");

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",&graph[i][j]);
        }
    }

    floydWarshall(n,graph);
}

void floydWarshall(int n, int graph[MAX][MAX]){
    int i,j,k;
    int dist[MAX][MAX];

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            dist[i][j] = graph[i][j];
        }
    }

    for(k=0;k<n;k++){
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }
    }

    display(n,dist);
}
