#include <iostream>
#include <string.h>
using namespace std;
char key[6][20] = {"begin","if","then","while","do","end"};//����һ����ά�����Źؼ��� 
char token[20];	//����ַ������ʣ� 
//�жϹؼ��� 
int isKey(char s[])
{
	for(int i = 0; i<6;i++)
	{
		if(strcmp(s,key[i]) == 0)
		{
			return i+1;	//�ؼ��ֵ��ֱ�������Ϊ begin=1,if=2,then=3,while=4,do=5,end=6��Ϊ i+1 ��ֵ 
		}
	}
	return -1;
}
//�ж��ǲ�����ĸ 
bool isChar(char ch)
{
	if((ch>='a' && ch<='z') || (ch>='A' && ch<='Z'))
	return true;
	else return false;
}
//�ж��ǲ������� 
bool isNum(char ch)
{
	if(ch>='0' && ch<='9')
	return true;
	else
	return false;
}
//�����ӳ���
void scanner(int &syn,int &p,char s[])
{
	int count = 0;
	if(s[p] == ' ') p++;
	//��ͷ����ĸ
	if(isChar(s[p]))
	{
		while(isNum(s[p]) || isChar(s[p]))
		{
			token[count++] = s[p];
			p++;
		}
		token[count] = '\0';	//'\0'��Ϊ������ ,�����ʷָ��� 
		syn = isKey(token);
		if(syn == -1)	
		{
			syn = 10;	//��ʶ��letter(letter|digit) *
		}
	}
	
	//��ͷ������
	else if(isNum(s[p]))
	{
		while(isNum(s[p]))
		{
			token[count++] = s[p];
			p++;
		}
		token[count] = '\0';//������ʶ 
		syn = 11;	//����digit(digit) *
	}
	
	//�������������߽��
	else
	{	
		//�ȴ���û��������ַ� 
		switch(s[p])
		{
			case '+': syn = 13;token[0] = s[p];token[1]='\0';break;
			case '-': syn = 14;token[0] = s[p];token[1]='\0';break;
			case '*': syn = 15;token[0] = s[p];token[1]='\0';break;
			case '/': syn = 16;token[0] = s[p];token[1]='\0';break;
			case '=': syn = 25;token[0] = s[p];token[1]='\0';break;
			case ';': syn = 26;token[0] = s[p];token[1]='\0';break;
			case '(': syn = 27;token[0] = s[p];token[1]='\0';break;
			case ')': syn = 28;token[0] = s[p];token[1]='\0';break;
			case '#': syn = 0 ;token[0] = s[p];token[1]='\0';break;
			case '[': syn=29; token[0]=s[p];token[1]='\0';break;
			case ']': syn=30; token[0]=s[p];token[1]='\0';break;
		}
		
		
		//�����������
		//: :=
		if(s[p] == ':')
		{
			token[count++] = s[p];
			if(s[p+1] == '=')
			{
				p++;
				token[count++] = s[p];
				syn = 18;
			}
			else
			{
				syn = 17;
			}
			token[count] = '\0';
		}
		
		//< <> <=
		if(s[p] == '<')
		{
			token[count++] = s[p];
			if(s[p+1] == '>')
			{
				p++;
				token[count++] = s[p];
				syn = 21;
			}
			else if(s[p+1] == '=')
			{
				p++;
				token[count++] = s[p];
				syn = 22;
			}
			else
			{
				syn = 20;
			}
			token[count] = '\0';
		}
		
		//> >=
		if(s[p] == '>')
		{
			token[count++] = s[p];
			if(s[p+1] == '=')
			{
				p++;
				token[count++] = s[p];
				syn = 24;
			}
			else
			{
				syn = 23;
			}
			token[count] = '\0';
		}
		
		//���� 
		p++;	//�ж�������ͽ�����ⲿ������ָ�� p û�����ָ��������Ҫ��ָ�� p �����һλ 
	}
	 
} 
int main()
{
	char s[100];	//�����ַ��� 
	while(cin.get(s,100))
	{
		int p = 0;
		int syn;
		while(p < strlen(s))	//ѭ������ ,p��δָ���ַ������	
		{
			scanner(syn,p,s);
			cout<<'<'<<token<<','<<syn<<'>'<<endl;
		}
	}
	return 0;
}
