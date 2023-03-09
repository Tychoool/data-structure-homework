#include <stdio.h>
#include <queue>
int visit[10]={0};
int G[10][10]={0};

void DFS(int i,int n){
    visit[i]=1;
    printf(" %d",i);
    for (int j = 0; j < n; j++)
    {
        if(G[i][j]==1&&visit[j]==0){
            DFS(j,n);
        }
    }
    
}

void BFS(int i,int n){
    int v;
    std::queue<int>q;
    visit[i]=1;
    q.push(i);
    while (!q.empty()){
        v=q.back();
        printf("%d",v);
        q.pop();
        for (int j = 0; j < n; j++){
            if(G[i][j]==1&&visit[j]==0){
                visit[j]=1;
                q.push(j);
            }
        }
        
    }
    

}

int main()
{
    int n,e;
    scanf("%d %d",&n,&e);
    int a,b;
    for (int i = 0; i < e; i++)
    {
        scanf("%d %d",&a,&b);
        G[a][b]=G[b][a]=1;
    }
    for (int i = 0; i < n; i++)
    {
    	if(visit[i]==0){
			printf("{");
        	DFS(i,n);
        	printf(" }\n");	
		}
	}
	for(int i = 0;i < n;i++){
		visit[i]=0;
	}
	for(int i=0;i < n;i++){
		if(visit[i]==0){
			printf("{");
        	BFS(i,n);
        	printf(" }\n");	
		}
    }

    return 0;    
}
