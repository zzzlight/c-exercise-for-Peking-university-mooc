#include<stdio.h>
#include<algorithm>
using namespace std;
int num;
int myswap(int a,int swap[],int xiabiao[]);
int main()
{

	scanf("%d",&num);
	int swap[100010];
	int count=0;
	int swapcount=0;
	int copyx=1;
	int xiabiao[100010];
	int sortnum[100010];
	int zero;
	for(int i=0;i<num;i++)
	{
		scanf("%d",&swap[i]);
		xiabiao[swap[i]]=i;
		sortnum[i]=swap[i];
		if(swap[i]==0) zero=i;
	}
	sort(sortnum,sortnum+num);
	int k=num-1;
	while(1)
	{
		
		while(zero!=0)
		{
			zero=myswap(zero,swap,xiabiao);
			swapcount++;
			count++;
		}	
		if(count==num-2) break;
		while(k!=0)
		{
			if(swap[k]==sortnum[k])     //�����ڶ���������ȱ�£���һ�������֡�ֻ�ܵ��ű��� ����ʱ 
				k--;
			else break;
			
		}
		if(k==0) break;
	
		copyx=k;
	
		swap[0]=swap[copyx];
		swap[copyx]=0;
		
		xiabiao[0]=copyx;
		xiabiao[swap[0]]=0;    //����swapǰһ�����˽��� ע������� 
		zero=copyx;
		swapcount++;
	}
	printf("%d",swapcount);
 } 
 int myswap(int a,int swap[],int xiabiao[])
{
	int xb;
	xb=xiabiao[a];
	swap[xb]=0;
	swap[a]=a;
	xiabiao[0]=xb;
	xiabiao[a]=a;
	return xb;
 } 
