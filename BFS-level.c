#define MAXSIZE 10
#define INF 1000
#include<stdio.h>
#include<stdlib.h>
int main()
{
    int i,j;//for looping
    int n;//number of nodes.
    int visitedNodes[MAXSIZE];//for marking which nodes are already part of the MST
    int adj[MAXSIZE][MAXSIZE];
    int frontier[MAXSIZE];
    int frontierSize=0;
    int visitOrder[MAXSIZE];
    int visitedCount=0;
    int level[MAXSIZE];
    int currentLevel=0;
    printf("Enter the number of nodes: ");
    scanf("%d",&n);

    //initialize visitedNodes
    i=0;
    while(i<n){
        visitedNodes[i++]=0;
    }

    //initialize level
    i=0;
    while(i<n){
        level[i++]=0;
    }
    //initialize frontier
    i=0;
    while(i<n){
        frontier[i++]=0;
    }

    //initialize adjacency matrix adj
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            adj[i][j]=0;
        }
    }


    //taking input for edges
    printf("Enter node1 and node2(-1 -1 to stop): \n");
    int inLoop=1;
    while(inLoop==1){

        int v1,v2;
        scanf("%d %d",&v1,&v2);
        if(v1>=0)
        {
            //register this edge in cost matrix
            adj[v1][v2]=1;
            adj[v2][v1]=1;
        }
        else{
            inLoop=0;
        }

    }

    //BFS
    frontier[0]=1;
    frontierSize=1;
    visitedNodes[0]=1;
    visitOrder[visitedCount++]=0;
    level[0]=0;

    while(frontierSize>0)
    {
    int nextFrontier[n];
    currentLevel++;
    frontierSize=0;
    for(i=0;i<n;i++){
        if(frontier[i]==0) continue;
        for(j=0;j<n;j++){
            if(visitedNodes[j]==1) continue;
            if(adj[i][j]==1){
                visitOrder[visitedCount++]=j;
                level[j]=currentLevel;
                nextFrontier[frontierSize++]=j;
                visitedNodes[j]=1;
            }
        }
    }
    //copy nextFrontier to frontier
    i=0;
    while(i<n){
        frontier[i++]=0;
    }

    for(i=0;i<frontierSize;i++){
        frontier[nextFrontier[i]]=1;
    }
    }

    //print order of traversal
    printf("node \t level\n");
    for(i=0;i<n;i++){
        printf("%d \t %d\n",visitOrder[i],level[i]);
    }


}
