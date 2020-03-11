/*本题写的时候，想着是用字符数组进行数据内容转换，由罗马字符对于数组中的元素值，转换为对应的数字。（构成一个函数）
转换成罗马值的函数中 最开始想使用else if语句对于特殊的情况进行判断，但是感觉分类的种类会比较多，不利于判断，所以就进行了分类。
两大类：罗马数字小的在前，大的在后（减法，比如IV,IX,XL,XC,CD,CM几个）；罗马数字大的在前，小的在后（正常加法）*/
int change(char c);
int romanToInt(char * s)
{
     int i,len,a,b,sum=0;
     len=strlen(s);
     for(i=0;i<len;i++)
    {
        a=change(s[i]);
        b=change(s[i+1]);
        if(a<b) //前面数字小，后面数字大IV
        {
            sum=sum-a;
        }
        else //前面数字大于等于，比如VX
        {
            sum=sum+a;
        }
    }
    return sum;
}

int change(char c)
{
    char a[7]={'I','V','X','L','C','D','M'};
    int b[7]={1,5,10,50,100,500,1000};
    int num=0,i;
    for(i=0;i<7;i++)
    {
        if(c==a[i])
        {
            num=b[i];
        }
    }
    return num;
}


/*不用字符数组转换，也可以用swich case进行分情况找到罗马数字对应的数值,参考相关代码，尝试换了一种方式。
对于题目给的存在特殊情况（小数在大数前面的，需要进行特殊操作减法）对应的罗马字符为I,X,C;
其他情况就是直接进行累计
*/
int romanToInt(char * s)
{
    int num=0,i;
    int a=strlen(s);
    for(i=0;i<a;i++)
    {
        if(s[i]=='V') num+=5;
        else if(s[i]=='L') num+=50;
        else if(s[i]=='D') num+=500;
        else if(s[i]=='M') num+=1000;
        else if(s[i]=='I')
        {
            if(s[i+1]=='V'||s[i+1]=='X')  num-=1;
            else num+=1;
        }
        else if(s[i]=='X')
        {
            if(s[i+1]=='L'||s[i+1]=='C')  num-=10;
            else num+=10;
        }
        else if(s[i]=='C')
        {
            if(s[i+1]=='D'||s[i+1]=='M')  num-=100;
            else num+=100;
        }
    }
    return num;
}











