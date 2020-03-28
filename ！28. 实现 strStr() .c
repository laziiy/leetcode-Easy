//28. 实现 strStr()  题目链接:https://leetcode-cn.com/problems/implement-strstr/submissions/ 
//方法一：常规用指针数组进行比较，暴力逐位比较，时间复杂度过高 
int strStr(char * haystack, char * needle)
{
    int i,len,len1,j=0,flag=0,pos;
    len1=strlen(needle);
    len=strlen(haystack);
    if(len1==0&&len==0) return 0;
    for(i=0;i<len;i++)
    {
        flag=0;
        for(j=0;j<len1;j++)
        {
            if(haystack[i+j]!=needle[j])
            {
                flag=1;
                break;
            }
        }
        if(flag==0)  return i;
    } 
    return -1;
}

//方法二： 用KMP进行匹配，此方法提高了运行效率，降低了时间复杂度，但是代码在编译时存在数组溢出情况，还没找到解决bug的方法
void getnext(int *T,int *next)
{
    int i,j;
    i=1;
    j=0;
    next[1]=0;
    while(i<strlen(T))
    {
        if(j==0||T[i]==T[j])
        {
            i++;
            j++;
            next[i]=j;
        }
        else j=next[j];//j不相等，回溯
    }
}

int strStr(char * haystack, char * needle)
{
    int i=0,j=0;
    int len=strlen(haystack);
    int len1=strlen(needle);
    int next[len];
    getnext(needle,next);
    if(len1==0&&len==0) return 0;
    while(i<len&&j<len1)
    {
        if(j==0||haystack[i]==needle[j])
        {
            i++;
            j++;
        }
        else j=next[j];
    }
    if(j==len1)  
        return i-len1+1;
    else
        return -1; 
} 
