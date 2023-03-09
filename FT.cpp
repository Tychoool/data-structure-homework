#define MaxSize 10001
#include <stdio.h>
typedef int ElementType;
typedef int SetName;
typedef ElementType SetType[MaxSize];

SetName Find(SetType S,ElementType x)
{
    if(S[x]<0){
        return x;
    }
    else{
        return S[x]=Find(S,S[x]);
    }
}

void Union(SetType S,SetName Root1,SetName Root2)
{
    if(S[Root1]<S[Root2]){
        S[Root2]+=S[Root1];
        S[Root1]=Root2;
    }
    else{
        S[Root1]+=S[Root2];
        S[Root2]=Root1;
    }
}

void Input_Connection(SetType S)
{
    ElementType a,b;
    SetName Root1,Root2;
    scanf("%d %d",&a,&b);
    Root1=Find(S,a-1);
    Root2=Find(S,b-1);
    if(Root1!=Root2){
        Union(S,Root1,Root2);
    }
}

void Check_Connection(SetType S)
{
    ElementType a,b;
    SetName Root1,Root2;
    scanf("%d %d",&a,&b);
    Root1=Find(S,a-1);
    Root2=Find(S,b-1);
    if (Root1==Root2){
        printf("yes\n");
    }
    else{
        printf("no\n");
    }
}

void Check_Network(SetType S,int N)
{
    int counter=0;
    for(int i=0;i<N;i++){
        if(S[i]<0){
            counter++;
        }
    }
    if(counter==1){
        printf("The network is connected.\n");
    }
    else{
        printf("There are %d components.\n",counter);
    }
}

int main()
{
    SetType S;
    int N;
    char in;
    scanf("%d\n",&N);
    for(int i=0;i<N;i++){
        S[i]=-1;
    }
    do{
        scanf("%c",&in);
        switch (in){
        case 'I':Input_Connection(S);break;
        case 'C':Check_Connection(S);break;
        case 'S':Check_Network(S,N);break;
        }
    }while (in!='S');
    return 0;

}