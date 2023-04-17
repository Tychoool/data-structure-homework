#include <stdio.h>
#include <stdlib.h>

void swap(int &a,int &b)
{
    int tmp=a;
    a=b;
    b=tmp;
}

void PercDown(int a[], int N, int rt)
{
    //将N个元素的数组中以a[now]为根的子堆调整为最大堆
    int father, son;
    int tmp = a[rt];
    for(father = rt; (father*2+1) < N; father = son) {
        son = father * 2 + 1;//左儿子
        if(son != N-1 && a[son] < a[son+1]) //右儿子存在且比左儿子大
            son++;
        if(tmp >= a[son]) break;//找到该放的地方
        else a[father] = a[son];//下滤
    }
    a[father] = tmp;
}

void HeapSort(int A[],int n)
{
    for(int i=0;i<n;i++){
        PercDown(A, n, 0);
    }
    for(int i=n-1;i>0;i--){
        swap(A[i],A[0]);
        PercDown(A, i,0);
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    int A[n];
    for(int i=0;i<n;i++){
        scanf("%d",&A[i]);
    }
    HeapSort(A,n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ",A[i]);
    }
    
    return 0;
}