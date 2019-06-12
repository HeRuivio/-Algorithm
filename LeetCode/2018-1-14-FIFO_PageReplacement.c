#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

void FIFO_PageReplacement(int *resource, int length, int page_num);

int main()
{
	int length = 4;//�ڴ�ҳ����󳤶�
	int *resource = (int *)calloc(sizeof(int),length);//����ռ�
	int i = 0;

	for (i = 0; i < length; i++)
	{
		resource[i] = -1;//��ʼ��Ϊ-1����ʾ��
	}


	//------------------����----------------------
	int list[10] = { 0,4,7,4,8,6,7,2,0,4 };
	int j = 0;
	for (i = 0; i < 10; i++)
	{
		FIFO_PageReplacement(resource, 4, list[i]);
		
		for (j = 0; j < 4; j++)
			printf_s("%d ", resource[j]);
		printf_s("\n");
	}

	system("pause");
}

void FIFO_PageReplacement(int *resource,int length,int page_num)//lengthΪ�ڴ������ɵ���󳤶ȣ�page_numΪ�����ҳ��
{
	int i = 0, temp = 0;

	for (i = 0; i < length; i++)//�ж��Ƿ��пյ�λ�ã�����У��������ҳ�����յ�λ�ã�����
	{
		if (resource[i] == -1)
		{
			resource[i] = page_num;
			return;
		}		
	}
	
	for (i = 0; i < length; i++)//ִ�е������ʾû�пյ�ҳ�棬�ж������ҳ�����ѷ����ҳ�����Ƿ��Ѿ����ڣ������ڣ���ֱ�ӷ���
	{
		if (resource[i] == page_num)
			return;
	}

	for (i = 1; i < length; i++)//ִ�е������ʾû�пյ�ҳ�棬�������ҳ��û�����ѷ����ҳ���У����ǰ���������滻һ��ҳ�棬�������ҳ��ŵ����һ��λ��
	{
		resource[i - 1] = resource[i];
	}
	resource[length-1] = page_num;
}