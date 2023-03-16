#include <stdio.h>
#include <stdlib.h>

typedef struct SNode *PtrToSNode;
struct 
SNode{
    int Data;
    PtrToSNode Next;
};
typedef PtrToSNode Stack;

Stack CreateStack( ) 
{ /* 构建一个堆栈的头结点，返回该结点指针 */
    Stack S;

    S = (Stack)malloc(sizeof(struct SNode));
    S->Next = NULL;
    return S;
}

bool IsEmpty ( Stack S )
{ /* 判断堆栈S是否为空，若是返回true；否则返回false */
    return ( S->Next == NULL );
}

bool Push( Stack S, int X )
{ /* 将元素X压入堆栈S */
    PtrToSNode TmpCell;

    TmpCell = (PtrToSNode)malloc(sizeof(struct SNode));
    TmpCell->Data = X;
    TmpCell->Next = S->Next;
    S->Next = TmpCell;
    return true;
}

int Pop( Stack S )  
{ /* 删除并返回堆栈S的栈顶元素 */
    PtrToSNode FirstCell;
    int TopElem;

    if( IsEmpty(S) ) {
        return 0;
    }
    else {
        FirstCell = S->Next; 
        TopElem = FirstCell->Data;
        S->Next = FirstCell->Next;
        free(FirstCell);
        return TopElem;
    }
}


void solve(int pre[],int in[],int post[],int preL,int inL,int postL,int n) 
{
    if (n==0) return;
    else if(n==1) {post[postL]=pre[preL];return;}
    else{
        int i;
        int root=pre[preL];
        for (i=0; i<n; i++) {
            if (in[inL+i]==root) {
                break;
            }
        }
        post[postL+n-1]=root;
        int L=i,R=n-i-1;
        solve(pre, in, post, preL+1, inL, postL, L);
        solve(pre, in, post, preL+L+1, inL+L+1, postL+L, R);
    }
}
 
int main()
{
    int n,a=0,b=0;
    scanf("%d",&n);
    int pre[n],in[n],post[n];
    Stack pr=CreateStack();
    int *p=pre;
    for(int i=0; i<2*n; i++) {
        char c[5];
        scanf("%4s",c);
        switch (c[1]) {
            case'u':scanf("%d",&pre[a]);
                    Push(pr,pre[a]);
                    a++;
                    break;
            case'o':in[b]=Pop(pr);
                    b++;
                    break;
        }
    }
    int preL=0,inL=0,postL=0;
    solve(pre,in, post,preL,inL,postL,n);
    for (int i=0; i<n; i++) {
        printf("%d ",post[i]);
    }
    return 0;
}
