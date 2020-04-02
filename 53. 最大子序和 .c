//53. 最大子序和  题目链接 ：https://leetcode-cn.com/problems/maximum-subarray/ 
/*官方题解中给了很多动态规划、贪心算法、分治法等，本题就是动态规划法进行设计的，
时间复杂度 
*/ 
int maxSubArray(int* nums, int numsSize)
{
    int i,sum=nums[0],temp=nums[0];
    for(i=1;i<numsSize;i++)
    {
        if(temp>sum)
        {
            sum=temp;
        }
        if(temp<0)
        {
            temp=0;
        }
        temp=temp+nums[i];
    }
    if(temp>sum) return temp; //最后一项如果最大，sum在循环内没有操作，所以此处补充
    else return sum;
}
