#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

vector<long long> seq;
int main()
{
    //Ҫ�������  max����һ����sort�����һλ 
	int num;
	long long p;
	scanf("%d",&num);
	scanf("%lld",&p);
	for(int i=0;i<num;i++)
	{
		long long temp;
		scanf("%lld",&temp);
		seq.push_back(temp);
	}

	sort(seq.begin(),seq.end());
	int result=0;
	
		for(int j=0;j<num;j++)
		{
				long long sum=seq[j]*p;
				int x=upper_bound(seq.begin(),seq.end(),sum)-seq.begin()-1;   //upper_bound����Ϊ��m*p�ոմ�ĵ�ַ����Ҫ��begin�����õ�int����ǰһλ��Ϊ���ڻ�С�� �������г�Ҫ��ǰһλ�� 
			
				if(x+1-j>result)  //vector��0��ʼ����Ҫ��һ 
				{
					result=x+1-j;
				}
			
			
		}	
	
	

	printf("%d",result);
 } 
