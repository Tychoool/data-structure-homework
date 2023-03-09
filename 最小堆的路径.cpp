#include <stdio.h>

#define MAXN 1001
#define MINN -10001
int H[MAXN],size;

void Create()
{
    size=0;
    H[0]=MINN;
}

void Insert(int x)
{
    int i;
    for(i=++size;H[i/2]>x;i/=2){
        H[i]=H[i/2];
    }
    H[i]=x;
}

int main()
{
    int i,N,M,x,j;
    scanf("%d %d",&N,&M);
    for(i=0;i<N;i++){
        scanf("%d",&x);
        Insert(x);
    }
    for(j=0;j<M;j++){
        scanf("%d",&i);
        printf("%d",H[i]);
        while(i>1){
        	i/=2;
            printf(" %d",H[i]);
            }
    	printf("\n");
    }
    return 0;
}
