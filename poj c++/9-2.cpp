#include <stdio.h>
#include<map>

using namespace std;



map<int,int> mymap;


int main()
{
	int num;
	scanf("%d",&num);
	mymap[1000000000]=1;

	for(int i=0;i<num;i++)     //map��ʵ���ڳ���  ��map�ڲ�Ϊ���� �ʸ���map�ĵ�����ǰ�������������ʵ�� 
	{
		int tempid,temppow;
		scanf("%d %d",&tempid,&temppow);
		mymap[temppow]=tempid;
		auto iter=mymap.find(temppow);
		auto nex=iter;
		++nex;
		auto les=iter;
		--les;
		if(iter==mymap.begin()) printf("%d %d\n",tempid,nex->second);
		else if(iter==mymap.end()) printf("%d %d\n",tempid,les->second);
		else 
		{
			if(nex->first-iter->first<iter->first-les->first) printf("%d %d\n",tempid,nex->second);
			else if (iter->first-les->first<nex->first-iter->first) printf("%d %d\n",tempid,les->second);
			else if(iter->first-les->first==nex->first-iter->first) printf("%d %d\n",tempid,les->second);
		}
	}
}

