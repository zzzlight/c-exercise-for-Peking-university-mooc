#include<stdio.h>
#define max 100010

int main(){
	char zimu[max];
	int leftp[max]={0};
	int rightt=0;
	

	int num=0;

	scanf("%s",zimu);
	

	for(int i=0;i<max;i++)
	{
		if(i>0) leftp[i]=leftp[i-1];    //�����鱣����߲���p�ĸ����������Ǹõ㲻��P����ֵ���䣬Ϊp�õ���ֵ��һ 
		if(zimu[i]=='P') 
		{
			 
			leftp[i]=leftp[i-1]+1;
		}
	
	}
	for(int j=max;j>=0;j--)				//���������������A�ұ�T���������ҽ������A�ұ�P������˵õ��ô�A��PAT������  ��������������һ��A�� 
	{									//�൱��һ�α����ȵ���Ѱ��A��Ҳ����Ѱ��T�����͸��Ӷ� 
		if(zimu[j]=='T') 
		{
			rightt=rightt+1;
			
		}
		else if(zimu[j]=='A')
		num=(num+rightt*leftp[j])%1000000007;
	}



	printf("%d\n",num);
	
	return 0;
} 
