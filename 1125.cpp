#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;

vector<double> seq;

int main()
{
	int num;
	scanf("%d",&num);
	for(int i=0;i<num;i++)
	{
		double temp;             
		scanf("%lf",&temp);
		seq.push_back(temp);
	}
	sort(seq.begin(),seq.end());
	double sum=seq[0];
	for(int i=1;i<num;i++)
	{
		sum=sum/2+seq[i]/2;    //����С������۰봮��ʵ����ʧ��С 
	}
	printf("%d",(int)sum); //�ýض�ʵ������ȡ��  doubleתint�ᷢ���ض� 
 } 
