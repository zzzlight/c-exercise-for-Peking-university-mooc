#include<stdio.h>

double seq[100005];
int count[100005];

int main()
{
	double sum=0;
	long long  num;
	scanf("%lld",&num);
	for(int i=0;i<num;i++)
	{
		scanf("%lf",&seq[i]);
		sum+=(i+1)*(num-i)*seq[i];   //i+1��num-i����int�˷��Ľ���ᳬ������ ��longlong��ת����longlong
		//����sum+=(double)(i+1)*(double)(num-i)*seq[i];  �������int 
	 } 

	 printf("%.2f",sum);
 } 
 //int �ᳬ��int��Χ ��longlong 
