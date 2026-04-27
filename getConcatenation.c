#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	*getConcatenation(int *nums, int numsSize, int *returnSize)
{
	int	*ret;
	int	i;

	*returnSize = 2 * numsSize;
	ret = malloc(numsSize * sizeof(int) * 2);
	i = 0;
	while (i < numsSize)
	{
		ret[i] = nums[i];
		ret[i + numsSize] = nums[i];
		i++;
	}
	return (ret);
}
