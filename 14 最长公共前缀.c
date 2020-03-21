//14 最长公共前缀
char * longestCommonPrefix(char ** strs, int strsSize) {
    if(strsSize==0)
    return "";
	int i = 1, j = 0, num = strlen(strs[0]), n ;
	char *str;
	while (i < strsSize)
	{
		j = 0;
		while (strs[0][j] == strs[i][j] && strs[0][j] != '\0')
		{
			j++;
		}
		if (num > j)
		{
			num = j;
		}
		i++;
	}
	str = (char*)malloc(sizeof(char)*(num + 1));
	for (n = 0;n < num;n++)
	{
		str[n] = strs[0][n];
	}
	str[n] = '\0';
	return str;
}

//方法二：更加简洁 
/*这里在调试过程中，要不然写进循环j<strlen(strs[0]);,要不然外圈num=strlen（strs[0]）,不这样写的时候会发生数组越界，
比如abc 空格 bcd 进行比较的时候，strs[0][0]和strs[1][0]不相等，造成strs[0]=0，下一次num为0，后面都不比较，数组溢出。*/
char * longestCommonPrefix(char ** strs, int strsSize)
{
    int i,j,num=0;
    if(strsSize==0) return "";
    for(i=1;i<strsSize;i++)
    {
        num=strlen(strs[0]);
        for(j=0;j<num;j++)
        {
            if(strs[0][j]!=strs[i][j]) 
            {
                strs[0][j]='\0';
                break;
            } 
        }
    }
    return strs[0];
}
