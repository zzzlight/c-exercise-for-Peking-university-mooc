#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
struct person{
	int wealth;
	char name[10];
	int age;
	
}a[100020],b[100020];
struct wealthgroup{
	int min;
	int max;
	int  groupnum;
}sgroup[1001];
bool cmp(person a, person b)
{
	if (a.wealth != b.wealth)return a.wealth > b.wealth;
	else if (a.age != b.age) return a.age < b.age;
	else return  strcmp(a.name,b.name)<0;
	
}
int main(){
	int num;
	int group;
	 
	scanf("%d %d", &num, &group);
	for (int i = 0; i < num; i++)
	{
		scanf("%s", &a[i].name);
		scanf("%d %d", &a[i].age, &a[i].wealth);
	};
	
	int age[200]={0};     //���䷶Χ��200 
	sort(a, a + num, cmp);
	int vaildnum=0;
	for(int i=0;i<num;i++)
	{
	  if(age[a[i].age]<100)		//��һ������γ���100���򲻼�¼ 
	  {
	    age[a[i].age]++;
	    b[vaildnum++]=a[i];     //��������һ��b��˳���0��ʼ�洢��Ч�����ڵ�������ݡ���Ϊһ������������100�� 
	  }							//����100�˺󲻽���if���� 
	}
	int k = 0;
	int count = 0;
	for (int i = 0; i < group; i++)
	{
	  scanf("%d %d %d", &sgroup[i].groupnum, &sgroup[i].min, &sgroup[i].max);
		printf("Case #%d:\n",(i+1));
		for (int j = 0; j < num; j++)
		{
			
			if (b[j].age <= sgroup[i].max&&b[j].age >= sgroup[i].min&&k<sgroup[i].groupnum)

			{
				
				printf("%s %d %d\n", b[j].name, b[j].age, b[j].wealth);
				k++;
				count = 1;
			}
		
			
		}
			 if (count==0)
			{
				printf("None\n");
			}
		k = 0;
		count = 0;
	}


}
