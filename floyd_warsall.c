
#define MAXSIZE 10
#define INF 1000
#include<stdio.h>
#include<stdlib.h>
int main()
{
    int i,j,k;//for looping
    int n;//number of nodes.
    int adj[MAXSIZE][MAXSIZE];

    printf("Enter the number of nodes: ");
    scanf("%d",&n);

    //initialize cost matrix adj
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
                if(i==j){
                    adj[i][j]=0;
                }
                else{
                 adj[i][j]=INF;
                }
        }
    }


    //taking input for edges
    printf("Enter node1, node2 and edge-weight(-1 -1 -1 to stop): \n");
    int inLoop=1;
    while(inLoop==1){

        int v1,v2,w;
        scanf("%d %d %d",&v1,&v2,&w);
        if(v1>-1 && v2>-1)
        {
            //register this edge in cost matrix
            adj[v1][v2]=w;

        }
        else{
            inLoop=0;
        }

    }
    printf("adj matrix is as follows\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%d\t",adj[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    //applying floyd warshall algorithm

    for(k=0;k<n;k++){
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                if(i==j) continue;
                if(adj[i][j]>adj[i][k]+adj[k][j]){
                    adj[i][j]=adj[i][k]+adj[k][j];
                }
            }
        }
    }

    printf("All pairs shortest path matrix is as follows.\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%d\t",adj[i][j]);
        }
        printf("\n");
    }




}
