#include<stdio.h>
#include<set>
using namespace std;
struct Setcoop
{
	set<int> aset;
}setcoop[100];

int main()
{
	Setcoop setcoop2[2002];
	int n;
	scanf("%d", &n);
	int setnum;
	for (int i =1; i <=n; i++)
	{
		scanf("%d", &setnum);
		for (int j = 0; j < setnum; j++)
		{
			int inset;
			scanf("%d", &inset);
			setcoop[i].aset.insert(inset);
		}
	}
	int putoutnum;
	scanf("%d", &putoutnum);
	double baifenbi[2002];

 
	for (int x = 0; x < putoutnum; x++)
	{
		double cha=0;
		int set1;
		int set2;
		scanf("%d", &set1);
		scanf("%d", &set2);
		double qian = setcoop[set1].aset.size() + setcoop[set2].aset.size();
		set<int>::iterator it=setcoop[set1].aset.begin();
		for(;it!=setcoop[set1].aset.end();it++)
		{																		//ע��δ���ҵ�ʱָ������ĩβ 
				if(setcoop[set2].aset.find(*it)!=setcoop[set2].aset.end()) cha++;    //findΪnlogn  ���ֱ�Ӳ�Ϊn2����Ȼ��vs����һ����ʱ 
																							//vs����Ϊinsert�����Ӷ�n�������nҲ��n2�� 
		}
		baifenbi[x] = cha / (qian-cha) * 100;
	}
	for (int n = 0; n < putoutnum; n++)
	{
		if (n!=putoutnum-1)
		printf("%0.1lf%%\n", baifenbi[n]);
		else
		printf("%0.1lf%%", baifenbi[n]);
	}
	
}
