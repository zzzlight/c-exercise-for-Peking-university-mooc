#include<stdio.h>
#include<algorithm>
#include<math.h>
using namespace std;

int main(){
	long long num;
	long long mynum;
	scanf("%lld",&num);
	mynum=num;
	int printout[10000];
	int temp[10000];
	int mycount=0;
	int m=2;

	while(1)
	{
	
		int j=0;
		int count=0;
		long long hehe=1;
		for(int i=m;i<sqrt(mynum)+1;i++)
		{
			hehe=hehe*i;     //��������������㣬��ԭ������������Ƿ������жϣ����ֻ���������Ƿ����������������120=3 4 5 6 ���� 
			if(num%hehe==0)
			{
				printout[count]=i;
				count++;
			}
			else break;
		}
		if(count>mycount) 
		{
			mycount=count;
			for(int q=0;q<mycount;q++)
			{
				temp[q]=printout[q];
				}	
		}
		m++;
		if(m>sqrt(mynum)) break;
	}
	//sort(printout,printout+mycount);  û��Ҫ���� 
	
	if(mycount==0)
	{
		printf("1\n");
		printf("%d",mynum);
	}
	else
	{
	printf("%d\n",mycount);
	for(int x=0;x<mycount;x++)
	{
		if(x!=mycount-1)printf("%d*",temp[x]);
		else printf("%d",temp[x]);
	}
	}
}
