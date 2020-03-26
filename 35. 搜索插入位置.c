//35. 搜索插入位置  题目：https://leetcode-cn.com/problems/search-insert-position/submissions/
//方法一：正常搜索插入（通过遍历，能找到的值进行标记，如果没有找到相等值，分情况处理） 此方法效率较低
int searchInsert(int* nums, int numsSize, int target)
{
    int i,flag=0;
    for(i=0;i<numsSize;i++)
    {
        if(target==nums[i])  
        {
            flag=1;
            return i;
            break;
        }
    }
    if(flag==0)
    {
        for(i=0;i<numsSize;i++)
        {
            if(numsSize>1&&target>nums[i]&&target<nums[i+1])  return i+1;
            else if(target>nums[numsSize-1])  return numsSize; 
        }
    }
    return 0;
}
//方法二：二分法查找位置 （找到位置的话，和target相等，返回mid对应的数组下标，不相等的话，需要插入，返回他前一个数组下标） ，更加高效常用
int searchInsert(int* nums, int numsSize, int target)
{
    int low=0;
    int high=numsSize-1;
    int mid=0;
    mid=(low+high)/2;
    while(low<=high)
    {
        mid=(low+high)/2;  //每次重新判断mid
        if(target<nums[mid]) high=mid-1;
        else if(target>nums[mid]) low=mid+1;
        else if(nums[mid]==target) return mid;
    }
    return low;
}
