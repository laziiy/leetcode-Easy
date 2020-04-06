/*序列和  题目：https://www.nowcoder.com/practice/46eb436eb6564a62b9f972160e1699c9?spm=a1z3e1.11874879.0.0.6a9d723atNRugR 
//方法一：采用简单的循环直接求解，导致题目的运行时间超时 
#include"stdio.h"
int main()
{
    int i,j,L,N,count=0,sum=0,flag=0,flag1=0,flag2=0,cnt=0;
    scanf("%d %d",&N,&L);
    for(i=2;i<=100;i++)
    {
        sum=0;
        count=0;
        for(j=i;j<=N/L;j++)
        {
            if(sum<N)
            {
                sum+=j;
                count++;
            }
            else if(sum==N)
            {
            	if(flag=0) cnt=count; 
            	flag=1;
                flag1=i;
                flag2=j-1;
                break;
            }
            else if(count>100) break;
            else break;
        }
        if(count<cnt)
        {
            flag1=i;
            flag2=j;
        }
    }

    if(flag==0&&count>100)
        printf("No");
    else
    {
    	for(i=flag1;i<=flag2;i++)
    	{
    		if(i!=flag2)
    			printf("%d ",i);
    		else
    			printf("%d",i);
		}
    return 0;
    }
}*/

/*
 未能编译通过，将方法改进。
 改进：方法二  利用等差数列的求和公式 ，题目给出的N，对于两个正整数N(1 ≤ N ≤ 1000000000),L(2 ≤ L ≤ 100)，
 int型可以满足，2的32次方涵盖N。等差数列求和公式：N=[（a1+（X-1）d）*X] /2; 
 本题差值是1，所以可以计算 N=(a1X+X*X-X)/2，换算式子得到a1=（2N-X(X-1))/2X 
 */ 
#include"stdio.h"
 int main()
 {
	int i,j,N,L,a;
	scanf("%d %d",&N,&L);
 	for(i=L;i<=100;i++)
 	{
 		if((2*N-i*i+i)%(2*i)==0) //恰好相加为N，满足连续加和的条件
 		{
 			a=(2*N-i*i+i)/(2*i);
			for(j=0;j<=i-1;j++)
			{
				if(j!=i-1)
					printf("%d ",(a+j));
				else
					printf("%d",(a+j));
		 	} 
	        return 0;	
		}
	}
    printf("No");
    return 0;
 }
