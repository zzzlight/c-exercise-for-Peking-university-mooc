#include<stdio.h>
#include<math.h>
long long int  gcd(long long int a,long long int b)
{
	long long int c=1;
	while(c!=0)
	{
		c=a%b;
		a=b;
		b=c;
	}
//	printf("%d",a);
	return a;
}
int main()
{
	int num;
	long long int fz[200];
	long long int fm[200];
	long long int myfm[200];   //eifen
	long long int j_fz=0;
	long long int  zs=0;
	long long int fs_fz=0;
	long long int fs_fm=0;
	scanf("%d",&num);
	
	for(int i=0;i<num;i++)	
	{
		scanf("%lld/%lld",&fz[i],&fm[i]);
		myfm[i]=fm[i];
	}
	long long int mylcm;
	for(int j=0;j<num-1;j++)
	{
		long long int temp;            
		temp=gcd(fm[j],fm[j+1]);
		fm[j+1]=fm[j]/temp*fm[j+1];     //��ԭ����fm���к�������  ���һ��ʱj+1��num-1��  �����Ǵ�0��ʼ  ��Ϊ���һ���� 
	}
	mylcm=fm[num-1];
	for(int i=0;i<num;i++)
	{
		j_fz+=fz[i]*(mylcm/myfm[i]);  //longlongû��� 
	}
	zs=j_fz/mylcm;
	fs_fz=j_fz%mylcm;
	
	if(zs!=0)
	{
		printf("%lld",zs);
	}
	if(fs_fz!=0)
	{
		if(zs!=0)  printf(" ");   //���ǰ����ҪԼ�� 
		long long int fz_gcd=abs(gcd(fs_fz,mylcm));   //��fz_gcdΪ���� ��ֹ���������ĸ��   ��ʵò��û������жϵ� 
		long long int newfs_fz=fs_fz/fz_gcd;
		long long int newfs_fm=mylcm/fz_gcd;
	//	int flag=false;
	
	//	if(newfs_fm<0||newfs_fz<0) 
	//	{
	//		newfs_fm=abs(newfs_fm);
	//		newfs_fz=abs(newfs_fz);
		//	printf("%d",fz_gcd);
		//	flag=true;
	//	}
	//	if(flag==false)
		printf("%lld/%lld",newfs_fz,newfs_fm);
	//	else
	//	printf("-%lld/%lld",newfs_fz,newfs_fm);   //���������� 2 -1/3 1/6��õ�1/-6 
	}
	if(fs_fz==0&&zs==0)  printf("0");   //0������  ���һ����   
 } 
