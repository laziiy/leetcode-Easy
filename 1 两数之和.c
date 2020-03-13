/**本题直接进行输入数组之和与target比较即可，相等情况就输出
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
for(int i=0;i<numsSize;i++)
{
    for(int j=i+1;j<numsSize;j++)
    {
        if(nums[i]+nums[j]==target)
        {
            returnsize[0]=i;
            returnSize[1]=j;
        }
    }
}
