/*9 回文数*/
//对于整数，有位数限制，long int 32位，long long int 64位，2的64次方，19位十进制 
//方法1：整数的形式 
bool isPalindrome(int x)
{
    int temp[20]={0},i,count=0,a,flag=0; //整数，temp20就够了 
    if(x<0||x%10 == 0 && x != 0) return false; //负数和末尾为0的情况 
    if(x>=0&&x<10) return true;
    while(x!=0)
    {
        a=x%10;
        temp[count]=a; 
        x=x/10;
        count++; 
    }
    for(i=0;i<=count/2;i++) //卡一半 ，考虑对于0数组越界的情况，最开始第二个if写的i>0,那么对于特殊情况0，i=0，count=0，count-i-1=-1，不行 
    {
        if(temp[i]!=temp[count-1-i])  flag=1;  
    }
    if(flag==0) return true;
    else return false;
}


//方法2：提升，不用字符数组，使用整数直接操作 

bool isPalindrome(int x)
{
    int temp,i,a;
    long long int n=0;
    temp=x;
    if(x<0) return 0;
    while(temp!=0)
    {
        a=temp%10;
        n=n*10+a;
        temp=temp/10;
    }
    if(x==n) return 1;
    else return 0;

}

