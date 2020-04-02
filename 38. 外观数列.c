//38. 外观数列  题目链接：https://leetcode-cn.com/problems/count-and-say/submissions/
/*解题思路： 本题就是后面的数用来表示前面的数。理解题目之后发现可以用迭代的方式进行，每一次表示前面的数有两部分组成，
个数+数字，比如11代表一个1，所以需要设定计数器在每一轮中进行count统计，用指针进行后移位置，继续统计，直到所有内容遍历结束*/ 
char * countAndSay(int n)
{
    char *mark=(char *)malloc(sizeof(char)*5000);
    char *temp=(char *)malloc(sizeof(char)*5000);
    mark[0]='1';
    mark[1]='\0';//结束标志
    int i,count,j;
    char key,*p;
    for(i=1;i<n;i++)//迭代次数
    {
        j=0;
        key=mark[0];
        count=0;
        p=mark;
        while(*p!='\0')
        {
            if(*p==key)//计数
                count++;
            else{
                temp[j++]=count+'0';//先存计数器
                count=1;
                temp[j++]=key;//再存关键字
                key=*p;
            }
            p++;

        }
        temp[j++]=count+'0';//先存计数器
        temp[j++]=key;//再存关键字
        temp[j]='\0';
        strcpy(mark,temp);
    }
    return mark;
}
