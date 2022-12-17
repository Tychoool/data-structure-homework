/*01-复杂度2 Maximum Subsequence Sum
给定K个整数组成的序列{ N1, N2, ..., NK}，“连续子列”被定义为{ Ni, Ni+1, ..., Nj}，其中 1≤i≤j≤K。
“最大子列和”则被定义为所有连续子列元素的和中最大者。例如，给定序列 { -2， 11， -4， 13， -5， -2 }，其最大子序列为 { 11， -4， 13 }，最大和为 20。

现在，您应该找到最大的总和，以及最大子序列的第一个和最后一个数字。

输入规范：
每个输入文件包含一个测试用例。每个案例占据两行。第一行包含一个正整数K (≤10000).第二行包含K数字，用空格分隔。

输出规格：
对于每个测试用例，在一行中输出最大总和，以及最大子序列的第一个和最后一个数字。数字必须用一个空格分隔，但行尾不得有多余的空格。如果最大子序列不唯一，则输出具有最小索引的子序列我和j（如示例案例所示）。如果所有K数字为负数，则其最大总和定义为 0，您应该输出整个序列的第一个和最后一个数字。

示例输入：
10
-10 1 2 3 4 -5 -23 3 7 -21
示例输出：
10 1 4*/

#include <stdio.h>


int main() 
{
    int k,maxSum=0,thisSum=0,i=0,temp=0;
    scanf("%d",&k);
    int a[k],first=0,last=k-1;
    int flag=0,zero=0;
    for (i = 0; i < k; i++)
    {
        scanf("%d",&a[i]);
        if(a[i]>0){
        	flag=1;
		}
		if(a[i]==0){
			zero=1;
		}
    }
	if(flag){
	    for(i=0;i<k;i++){
	        thisSum+=a[i];
	        if (maxSum<thisSum){
	            maxSum=thisSum;
	            first=temp;
	            last=i;
	        }
	        else if (thisSum<0){
	            thisSum=0;
	            temp=i+1;
	        }	        
    	}
        printf("%d %d %d\n",maxSum,a[first],a[last]);
    }
    else if(zero){
    	printf("0 0 0\n");
	}
	else{
		printf("0 %d %d\n",a[first],a[last]);
	}
	return 0;
}

