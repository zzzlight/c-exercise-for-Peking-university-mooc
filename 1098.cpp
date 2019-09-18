#include<stdio.h>
#include<vector> 
#include<algorithm>
using namespace std;
vector<int> initial;
vector<int> middle;
vector<int> insert;
vector<int> heap;
vector<int>result;
int num;
void swap(int &a,int &b)
{
	int temp=a;
	a=b;
	b=temp;
	
}
void downadjust(int low,int high)
{
	int i=low;
	int j=i*2+1;
	while(j<=high)
	{
		if(j+1<=high&&heap[j+1]>heap[j])
		{
			j=j+1;
		}
		if(heap[j]>heap[i])
		{
			swap(heap[j],heap[i]);
			i=j;
			j=i*2+1;
		}
		else
		{
			break;
		}
	}
	
}
void createheap()
{
	
	for(int i=(num-1)/2;i>=0;i--)
	{
		downadjust(i,num-1);
	}
	
}


int main()
{
	scanf("%d",&num);
	for(int i=0;i<num;i++)
	{
		int temp;
		scanf("%d",&temp);
		initial.push_back(temp);
	}
	for(int j=0;j<num;j++)
	{
		int temp;
		scanf("%d",&temp);
		middle.push_back(temp);
	}
	insert=initial;
	heap=initial;
	int i;
	for(i=2;i<=num;i++)      //�м�����middle��Ϊ����ڶ�����֮������У�i=1��sortû���м���Ϊ��ʼ���в��ܲ���Ƚ� 
	{									//�������ֳ�ʼ�͵ڶ�������һ��ʱ����������i=1�����ڵ�һ�ξ�ͣ�˵õ�һ���ڶ����Ļ��͵�һ��һ���Ľ��
							//ʵ��Ҫ�����i2�����һ�� 
		sort(insert.begin(),insert.begin()+i);
		if(insert==middle)
		{
			sort(insert.begin(),insert.begin()+i+1);
			result=insert;
			printf("Insertion Sort\n");
			for(auto it=result.begin();it!=result.end();it++)
			{
				printf("%d",*it);
				if(it!=result.end()-1)
				{
					printf(" ");
				}
			}
			break;
			
		}
		
	}
	if(i>num)
	{
		
		createheap();
		int n;
		for(n=num-1;n>0;n--)
		{
			swap(heap[n],heap[0]);
			downadjust(0,n-1);
			if(heap==middle)
			{
				n--;
				swap(heap[n],heap[0]);
				downadjust(0,n-1);
				result=heap;
				break;
			}	
		}
	
		
		printf("Heap Sort\n");
		for(auto it=result.begin();it!=result.end();it++)
		{
			printf("%d",*it);
			if(it!=result.end()-1)
			{
				printf(" ");
			}
		}
		
		
		
		
		
	}

	
}
