#include<stdio.h>
#include<math.h>

int main()
{
	int num;
	int count=0;
	scanf("%d",&num);
	int temp=num;
	int len=0;
	int left;
	int right;
	while(num!=0)
	{
		
		
		if(num%10==0)
		{
			left=num/10;
			count+=left*pow(10,len);
		}
		if(num%10==1)							//��Ϊ����1 ����1��0 ���� 
		{										//�̶�ĳһλ �ж�����λ�ı仯������
												//����1�������ڸ�λʱ10�Ĵη��Ρ�����0ֻ�����ȫ�� ���ֱ�ʱ��λ�̶�Ϊ1��Ϊ1�����һ�� 
			left=num/10;																					//�������Ҳ�������Ҳ�仯n�����ڴ�Ϊ1����Ҳ�Ӵ���n�� 
			right=(int(temp-left*pow(10,len))%int(pow(10,len)));
			count+=left*pow(10,len)+right+1;
		 } 
		 if(num%10>1)
		 {
		 	left=num/10;
		 	right=temp-left*pow(10,len);
		 	count+=(left+1)*pow(10,len);
		 }
		num=num/10;
		len++;
	}


	printf("%d",count);
	
 } 

