#include<stdio.h>
#include<algorithm>

using namespace std;

int seq[100005];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	int num;
	scanf("%d",&num);
	for(int i=0;i<num;i++)
	{
		scanf("%d",&seq[i]);
	}
	sort(seq,seq+num,cmp);
	int out=0;
	for(int i=0;i<num;i++)   //�����0 ��ʱ���жϵ�һ���Ƿ����� ��out=1�����ж� 
	{								//����out���Ǵ�0  ����2  �м�1ʱ�Ƿ���ȷ�޷��ж� 
		if(seq[i]>i+1)
		{
			out=i+1;   //ÿ���ж���һλ�����  ����һλ������(���ܵȺ� ��Ϊ��more than ) ֱ��break  ��ֹ���ظ������жϴ��� 
		}else
		{
			break;
		}
		
	}
	
	printf("%d",out);
	
 } 
