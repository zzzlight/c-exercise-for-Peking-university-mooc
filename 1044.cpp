#include<stdio.h>
#include<vector>

using namespace std;

int number[100001];
struct XB
{
	int start;
	int final;
};

vector<XB> result;
vector<XB> bresult;
int main()
{
	int num;
	int amount;
	bool flag1=false;
	int minlost=100000000;
	bool flag=false;
	scanf("%d",&num);
	scanf("%d",&amount);
	for(int i=0;i<num;i++)
	{
		int temp;
		scanf("%d",&temp);
		number[i]=temp;
	}
	
	for(int i=0;i<num;i++)
	{
		int tempamount=0;
		int j=i;
		while(tempamount<amount)
		{
			if(j>num) 	break;     //  ����num�ټӻ�δ���Ҳ�����Ż��ٶ� 
			tempamount+=number[j];
			j++;
		}
		if(j>num) break;   //�Ż�����  ������������Ҳ���ᳬ��amount  ˵���Ѿ�������ǰ������ 
		if(tempamount>amount&&tempamount<minlost)
		{
			minlost=tempamount;
		}
		if(tempamount==amount)
		{
			XB a;
			a.start=i+1;
			a.final=j;
			result.push_back(a);
			flag=true;
		}
		
	}
	if(flag==false)
	{
		for(int i=0;i<num;i++)
		{
			int tempamount=0;
			int j=i;
			while(tempamount<minlost)
			{
				if(j>num) break;
				tempamount+=number[j];
				j++;
			}
			if(j>num) break;
			if(tempamount==minlost)
			{
				XB a;
				a.start=i+1;
				a.final=j;
				result.push_back(a);
		
			}
		} 
	}
	for(auto it=result.begin();it!=result.end();it++)
	{
		printf("%d-%d",(*it).start,(*it).final);
		if(it!=result.end()-1) printf("\n");
	}
	
	
 } 
