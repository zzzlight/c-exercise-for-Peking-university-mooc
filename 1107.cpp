#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
int hobby[1001];
int father[1001];
int isroot[1001];
bool cmp(int a,int b)
{
	return a>b;
}
void orgin(int num)
{
	for(int i=1;i<=num;i++)   //��ʼ����ó�ʼ��Ϊ������ �������ó�ʼ 
	{
		father[i]=i;
		isroot[i]=false;
	}
}
int findfather(int x)
{
	int a=x;
	while(father[x]!=x)
	{
		x=father[x];
	}
	while(a!=father[a])   //·��ѹ�� 
	{
		int z=a;
		a=father[a];
		father[z]=x;
		
	}
	return x;
}
 void unionab(int a,int b)
 {
 	int fathera=findfather(a);
 	int fatherb=findfather(b);
 	if(fathera!=fatherb)
 	{
 		father[fathera]=fatherb;
	 }
  } 
int main()
{
	 vector<int> out;

	int  num;
	int t=0;
	scanf("%d",&num);
		orgin(num);
	for(int i=1;i<=num;i++) 
	{
		int tempnum;
		scanf("%d:",&tempnum);
		int flag;
		for(int j=1;j<=tempnum;j++)
		{
			int tempj;
		
			scanf("%d",&tempj);
			if(hobby[tempj]==0)    
			{
				hobby[tempj]=i;     //��һ�����¼����������õ���id 
			}
			
			
			unionab(findfather(hobby[tempj]),i); 	
			
		
			
		 } 
		
	 } 
	 
	for(int t=1;t<=num;t++)    //��ʾ�˵�id�Ǵ�1һֱ��n ������һ������һ��ʱ��ֱ���ڴ˴���Ϊ1����Ϊһ��ʼ����ʼ��Ϊ���� 
	{                              //ԭ�����ظ��ľ��ò��鼯�ϲ���û�ظ���Ĭ��Ϊ1       
		isroot[findfather(t)]++;
	}
	int mycount=0;
	for(int x=1;x<=num;x++)
	{
		if(isroot[x]>0)
		{
			mycount++;
			out.push_back(isroot[x]);
		}
		
	 } 
	sort(out.begin(),out.end(),cmp);
	
	 printf("%d\n",mycount);
	 
	 if(mycount>1)
	 {
	 	auto it=out.begin();
	 	 for(;it!=out.end()-1;it++)
	 	{
	 		printf("%d ",*it);
	 	}
	 	printf("%d",*it);
	 }
	 else
	 {
	 	printf("%d",out[0]);
	 }
	
	 
	 
 } 
