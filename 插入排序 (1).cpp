#include <stdio.h>
#include <stdlib.h>

void InsertionSort(int A[],int n)
{
    int P,i;
    int tmp;
    for(P=1;P<n;P++){
        tmp=A[P];
        int i;
        for(i=P;i>0&&A[i-1]>tmp;i--){
            A[i]=A[i-1];
        }
        A[i]=tmp;
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
    InsertionSort(A,n);
    for (int i = 0; i < n; i++)
    {
        printf(" %d",A[i]);
    }
    
    return 0;
}