//20. 有效的括号  题目连接：https://leetcode-cn.com/problems/valid-parentheses/submissions/
/*本题最开始设计的时候想用数组进行设计，但是遇到括号交错的时候和三个括号一起操作计数就比较错乱，不好处理。
参考了题解，用堆栈进行操作，左边括号就入栈，遇到右边括号 就对应弹出，对特殊情况可以分类处理*/ 

//在调试的时候，最开始没有考虑 
bool isValid(char * s)
{
    int len=strlen(s);
    char *stack=(char*)malloc(strlen(s)+1);
    if(len==0)  return true;
    if(len%2!=0) return false;
    int i,top;
    top=-1;
    for(i=0;i<len;i++)
    {
        if(s[i]==')'||s[i]==']'||s[i]=='}')  return false; //对特殊情况单独考虑 
        if(s[i]=='('||s[i]=='['||s[i]=='{') 
        {
            top++;
            stack[top]=s[i];
        }
        else if((s[i]==')'&&stack[top]=='(')||(s[i]==']'&&stack[top]=='[')||(s[i]=='}'&&stack[top]=='{'))  top--;  
        else return false;
    }
    if(top==-1) return true;
    else return false;
}

//相同思路，小区别 
bool isValid(char * s)
{
    int len=strlen(s);
    char *stack=(char*)malloc(strlen(s)+1);
    if(len==0)  return true;
    if(len%2!=0) return false;
    int i,top;
    top=-1;
    for(i=0;i<len;i++)
    {
        if(s[i]=='('||s[i]=='['||s[i]=='{') 
        {
            top++;
            stack[top]=s[i];
        }
        else if((top!=-1)&&((s[i]==')'&&stack[top]=='(')||(s[i]==']'&&stack[top]=='[')||(s[i]=='}'&&stack[top]=='{')))  top--; 
		//加对括号的限制条件，不加top！=-1的条件，就会导致对于第一项是有括号的，和top比较出现溢出 
        else return false;
    }
    if(top==-1) return true;
    else return false;
} 
