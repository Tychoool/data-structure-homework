#include <cmath>
#include <stdio.h>
#include <math.h>
int G[100][100]={0},N,D;
int visit[100]={0};
int answer=0;
typedef struct VNode Vertax;

struct VNode
{
    int x;//横、纵坐标
    int y;
};

int IsSafe(Vertax* p,int i)
{
    if((p->x+D) >= 50 || (p->x+D) <= -50 ||(p->y-D) <= -50 ||(p->y+D) >= 50)
    {
        return 1;
    }
    else
    {
        return 0;
    }    //这个跳走函数太麻烦了，救救(ㄒㄒ)

}

int DFS(Vertax *p,int i)
{
    if(IsSafe(p,i)) answer=1;
    else{
        for (int j = 1; j <= N; j++,p++){
            if(!visit[i] && G[i][j]==1){
                visit[i]=1;
                answer = DFS(p,j);
                if(answer == 1) break;
                
            }    
        }
    }
    return answer;
}

int main()
{
    int a,b;
    scanf("%d %d",&N,&D);
    Vertax Vs[N+1];
    Vs[0].x=0;
    Vs[0].y=0;
    Vertax *p=Vs;
    double R=7.5;
    for(int i=1;i<=N;i++){
        scanf("%d %d",&a,&b);
        Vs[i].x=a;
        Vs[i].y=b;  
        if(((Vs[i].x)*(Vs[i].x)+(Vs[i].x)*(Vs[i].x))<=pow(D+R,2)){
            G[0][i]=G[i][0]=1;
        }
    }
    for(int i = 1; i <= N; i++){
        for (int j = 1; j <= N; j++){
            if(!G[i][j]&&(((Vs[i].x-Vs[j].x)*(Vs[i].x-Vs[j].x)+(Vs[i].y-Vs[j].y)*(Vs[i].y-Vs[j].y)) <= D*D)&&(i!=j)){     //判断一下有没路径
                G[i][j]=G[j][i]=1;
            }
        } 
    }
    for (int i = 0; i <= N; i++,p++){
        if(!visit[i]&&G[0][i]){
            answer=DFS(p,i);
            if (answer==1) break;    
        }
    }
    if(answer==1){
        printf("Yes\n");
    }
    else{
        printf("No\n");
    }
}