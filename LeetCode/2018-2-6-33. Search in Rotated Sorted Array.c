#define _CRT_SECURE_NO_WARNINGS //ȥ��vs��ȫ���
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>
#include<time.h>

int search(int* nums, int numsSize, int target) 
{
	int mid = 0, left = 0, right = 0;
	int i = 0;

	if (numsSize == 0)
		return -1;

	if (numsSize == 1)
	{
		if (target == nums[0])
			return 0;
		else
			return -1;
	}

	left = 0;
	right = numsSize - 1;

	while (left<=right)
	{
		mid = (left + right) / 2;

		if (nums[mid] == target)
			return mid;
		else if (nums[mid] < nums[right])//����ұ��ǵ�������
		{
			if (target > nums[mid] && target <= nums[right])//���Ŀ��ֵ�ڵ���������
				left = mid + 1;
			else
				right = mid - 1;//���Ŀ��ֵ���ٵ���������
		}
		else//�������ǵ�������
		{
			if (target >= nums[left] && target < nums[mid])
			{
				right = mid - 1;
			}
			else
				left = mid + 1;
		}
	}

	return -1;
}

