//11. 盛最多水的容器  题目链接：https://leetcode-cn.com/problems/container-with-most-water/
//方法一:暴力拆解法 ，时间复杂度  时间复杂度：O(n^2)，空间复杂度 O(1)
int maxArea(int* height, int heightSize)
{
    int i,j,size=0,a=0,b=0,min,temp=0;
    for(i=0;i<heightSize;i++)
    {
        a=height[i];
        for(j=i+1;j<heightSize;j++)
        {
            if(a<height[j]) 
                min=a;
            else 
                min=height[j];
            temp=min*(j-i);
            if(temp>size)
                size=temp;
        }
    }
    return size;
}

//方法二 :双指针（优化了，降低了时间复杂度）  时间复杂度：O(n)，空间复杂度 O(1)
int maxArea(int* height, int heightSize)
{
    int i=0,j=heightSize-1,size=0,max=0;
    while(i<j)
    {
        if(height[i]<height[j])
        {
            size=(j-i)*height[i];
            i++;
        }
        else
        {
            size=(j-i)*height[j];
            j--;
        }
        if(size>max)
            max=size;
    }
    return max;
}
