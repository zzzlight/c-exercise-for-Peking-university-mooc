#include<cstdio>
#include<algorithm>
using namespace std;
#define max 100001
struct Node{
	int address;
	int data;
	int next;
	bool flag;
}node[max];
bool cmp(Node a,Node b)
	{
	if(a.flag==false||b.flag==false)
	{
		
		return a.flag>b.flag;						//sort��cmp�˴�����Ч�㣨flagΪ0�����ں��棬�ٽ�ǰ�����Ч����������� 
		
	}		
	else return a.data<b.data; 
	}
 
int main()
{
	int num,data,next,s1,address;
	int count=0;
	scanf("%d %d",&num,&s1);
	for(int x=0;x<max;x++)
{
	node[x].flag=0;
}
	for(int i=0;i<num;i++)
	{
		scanf("%d %d %d",&address,&data,&next);
		node[address].address=address;
		node[address].data=data;
		node[address].next=next;
	}
	for(int j=s1;j!=-1;j=node[j].next)
	{
		node[j].flag=1;
		count++;
	}
	if(count==0)
	printf("0 -1");
	else{

	sort(node,node+max,cmp);
	
	for(int z=0;z<count;z++)
 	{
 		if(z!=count-1)
 		node[z].next=node[z+1].address;
 		else node[z].next=-1;
	 }
	printf("%d %05d\n",count,node[0].address);
	
												//����ע������1.sortֻ���������˼ǵ���address
													//		  2.ע�����һλ-1�����
													//		  3.�˽�sort��ʹ���Լ�std
															   
	
	
	
	for(int y=0;y<count;y++)
	{
		if(y==count-1)
		printf("%05d %d %d\n",node[y].address,node[y].data,node[y].next);
		else printf("%05d %d %05d\n",node[y].address,node[y].data,node[y].next);
		 
	}
	
		}
	
	return 0;
}    
