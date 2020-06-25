#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>
#include<time.h>
#include<stdbool.h>
#include <ctype.h>

// ������ܹ�������������ģ����ģ��ַ�����
#define char_max 1000

// �˴������л��� Visual Studio 2017
// "#define _CRT_SECURE_NO_WARNINGS" ȥ��VS��ȫ���
// Ϊ�˼������߼����˴���Ĭ�Ͻ��м��ܲ���
// keyΪ����ĸ����ƶ���keyΪ����ǰ�ƶ���keyֵ�������棬����ģ���������ܹ���

void CaesarsCipher(char* text, char* result, int key);

int main()
{
	// �洢���������(������)
	char* text = (char*)malloc(sizeof(char)*char_max);
	// �洢���
	char* result = (char*)malloc(sizeof(char)*char_max);
	// ��Կ
	int key = 0;
	// ��ʱ�������������������
	int c = 0;

	// ����ʧ�ܵĴ���������3������ʧ�ܳ����Զ��˳�
	int fail_time = 0;
	//
	printf_s("����������(������),�Իس�������:\n");
	// �Ӽ��̻�ȡ����
	gets(text);
	printf_s("��������Կ(����):");
	// ��ȡ��Կ����������
	while (scanf_s("%d", &key) != 1)
	{
		// ��ջ�����
		while ((c = getchar()) != '\n' && c != EOF);
		fail_time++;
		if (fail_time == 3)
		{
			printf_s("����ʧ�ܴﵽ3�Σ������Զ��˳�\n");
			system("pause");
			return 0;
		}
		printf_s("������������Կ:");
	}

	CaesarsCipher(text, result, key);
	printf_s("%s\n", result);
	free(text);
	free(result);

	system("pause");

	return 0;
}

void CaesarsCipher(char* text, char* result,int key)
{
	// ��¼��ǰλ��
	int pos = 0;
	// ��¼��Ч��ֵ
	int vaild = 0;
	// ��ĸ��ascii��ֵ
	int code = 0;
	// ��ʼ���������
	memset(result, 0, char_max*sizeof(char));
	// �Թؼ���ȡģ����
	key = abs(key) % 26;
	// ��������������ַ�
	while (text[pos])
	{
		// �������ĸ�����д���
		if (isalpha(text[pos]))
		{
			// ��ȡ��ĸASCIIֵ
			code = toupper(text[pos]);
			// ���м��ܻ���ܲ���
			code += key;
			// �ж�ASCII�Ƿ�Խ��
			if (code > 90)
				code = code - 26;
			if (code < 65)
				code = code + 26;
			result[vaild] = (char)code;
			vaild++;
		}
		// ȥ������' ','\t','\n','\v','\r','\f'��ʾΪ�յ��ַ�
		else if (isspace(text[pos]))
		{
			pos++;
			continue;
		}
		// �����ַ�ԭ������
		else
		{
			result[vaild] = text[pos];
			vaild++;
		}
		pos++;
	}

	return;
}
