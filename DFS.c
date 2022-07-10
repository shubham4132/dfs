#define MAX 20//maximum number of nodes
#include<stdio.h>
void DFS(int,int);
int visited[MAX];//to mark which nodes have been visited
int adj[MAX][MAX];

int main(){
int i,j;

int n;//number of nodes
printf("Enter number of nodes: ");
scanf("%d",&n);

//initially mark all nodes as not visited.
i=0;
while(i<n){
    visited[i++]=0;
}
i=0;

//initialize the adjacency matrix with zero in every cell
for(i=0;i<n;i++){
    for(j=0;j<n;j++){
        adj[i++][j++]=0;
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

    //DFS logic
    //the following loop selects every one by one and calls DFS for this node.
    //advantage of this mechanism is that the entire graph can be explored even if the graph is not connected.

    for(i=0;i<n;i++){
        //pick i only if it is not visited.
        if(visited[i]==0){
            DFS(i,n);
        }
    }
}

void DFS(int v, int n){
int k;
visited[v]=1;
printf("%d--->",v);
for(k=0;k<n;k++){
    if(adj[v][k]==1 && visited[k]==0){
         DFS(k,n);
    }
}
printf("backtraced---->");

}
