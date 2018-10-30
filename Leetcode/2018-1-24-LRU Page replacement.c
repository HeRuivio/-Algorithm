#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>
#include<time.h>
#include<stdbool.h>

void LRU_PageReplacement(int *resource, int *times,int length, int page_num);
//���ֺ�FIFO�Ľӿڷ��һ�£�������times����������¼�ϴ�ʹ�õĴ��������resource����ı�ʶ����ԭ������λ�����λ

int main()
{
	int length = 4;//�ڴ�ҳ����󳤶�
	int *resource = (int *)calloc(sizeof(int), length + 2);//����ռ�,0��λΪ��ʶ����1��λΪ�˴��滻��λ�ã�2��λΪ��һ���滻��λ��
	int *times = (int*)calloc(sizeof(int), length);//����ռ䣬��Ӧ��λ�ñ�ʾ�Ѿ�ͣ�����ڴ��еĴ���,�˴�һ��Ҫ��ʼ��Ϊ0
	int i = 0;

	for (i = 0; i < length + 2; i++)
	{
		resource[i] = -1;//��ʼ��Ϊ-1����ʾ��
	}
	for (i = 0; i < length; i++)
	{
		times[i] = 0;
	}


	//------------------����----------------------
	int list[25] = { 7,0,1,2,0,3,0,4,2,3,0,3,2,1,2,0,1,7,0,1 };
	int j = 0;
	for (i = 0; i < 20; i++)
	{
		LRU_PageReplacement(resource,times, length, list[i]);

		for (j = 0; j < length + 2; j++)
			printf_s("%d ", resource[j]);
		printf_s("	");
		for (j = 0; j < length; j++)
		{
			printf_s("%d ", times[j]);
		}
		printf_s("\n");
	}

	system("pause");
}

void LRU_PageReplacement(int *resource, int* times,int length, int page_num)//lengthΪ�ڴ������ɵ���󳤶ȣ�page_numΪ�����ҳ��
{
	int i = 0, j = 0;
	int max = 0, max_pos = 0;

	for (i = 2; i < length + 2; i++)
	{
		if (page_num == resource[i])//��ʾ�����ҳ�����Ѿ�������ڴ���
		{
			resource[0] = 0;//0��ʾ����Ҫ�����µ�ҳ��
			resource[1] = i;//�����ҳ���ڵ�i��λ��
			times[i - 2] = 1;//��¼�����ҳ������ڴ��еĴ�������Ϊ1
			for (j = 0; j < length; j++)//ѭ�������ڴ���ҳ���ͣ������
			{
				if (times[j] == 0)//�����λ�õ�ͣ������Ϊ0����ʾ��λ�û�����û�б������ҳ�棬����
					continue;
				if (j == i - 2)
					continue;//�����ڴ��Ӧ�ļ�¼������λ�ã�����Ϊ1����ʾ��һ������ʱ����ҳ���Ѿ����ڴ���ͣ����һ��
				else 
					times[j] += 1;//����λ����������1��ͣ��ʱ��
			}

			return;
		}
	}

	//�����ҳ�治���ѷ�����ڴ���
	max = times[0];
	for (j = 0; j < length; j++)//�ҵ�ͣ����õ�ҳ�����ڴ��е�λ��
	{
		if (times[j] == 0)//�����λ�û�û�б����������ֱ�ӷ���
		{
			max_pos = j;
			break;
		}
		if (times[j] > max)
		{
			max = times[j];
			max_pos = j;
		}
	}

	resource[max_pos + 2] = page_num;
	resource[0] = 1;
	resource[1] = max_pos + 2;
	times[max_pos] = 1;

	for (j = 0; j < length; j++)//ѭ�������ڴ���ҳ���ͣ������
	{
		if (times[j] == 0)//�����λ�õ�ͣ������Ϊ0����ʾ��λ�û�����û�б������ҳ�棬����
			continue;
		if (j == max_pos)
			continue;//�����ڴ��Ӧ�ļ�¼������λ�ã�����Ϊ1����ʾ��һ������ʱ����ҳ���Ѿ����ڴ���ͣ����һ��
		else
			times[j] += 1;//����λ����������1��ͣ��ʱ��
	}

	return;
}
