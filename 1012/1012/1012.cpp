#include<cstdio>
#include<algorithm>
using namespace std;
struct student{
	int stu;
	int clan;
	int math;
	int english;
	int ave;
	int rankc;
	int rankm;
	int rankeng;
	int rankave;
}a[2050];
bool cmp(student a, student b)
{
	
	return (a.english + a.math + a.clan) / 3>(b.english + b.math + b.clan)/3;
	

	
}
bool cmp1(student a, student b)
{
	return a.clan > b.clan;
}
bool cmp2(student a, student b)
{
	return a.math > b.math;
}
bool cmp3(student a, student b)
{
	return a.english > b.english;
}
int num;
int main(){
	int ran = 0;
	int b[2050];
	int num;
	int check;
	scanf("%d %d", &num, &check);
	for (int i = 0; i < num; i++)
	{
		scanf("%d %d %d %d\n",&a[i].stu,&a[i].clan,&a[i].math,&a[i].english);
	}
	for (int i = 0; i < check; i++)
	{
		scanf("%d",&b[i]);
	}
	sort(a, a + num, cmp);

	a[0].rankave = 1;
	a[0].ave = (a[0].english + a[0].math + a[0].clan) / 3;;   //ע��ave���⣬struct���޷������õ�ave������������δ���ɣ�
																		//��aveҪ�Լ�����
	for (int i = 1; i < num; i++)   //��1��ʼ��ǰ�滹Ҫ�ֶ���0��    ������ѧ�ɼ��Ȳ�������鷳
	{
		a[i].ave = (a[i].english + a[i].math + a[i].clan) / 3;
		
		if (a[i-1].ave == a[i].ave){ a[i].rankave = a[i-1].rankave; }    //�����п�����ֵ��ͬ�ĵ���rank��Ų�ͬ������ĿҪ������ͬrankӦ����ȡ�rank��ȡ��һ��ʱ���rank
		else a[i].rankave = i + 1;
		
	}

	sort(a, a + num, cmp1);
	a[0].rankc = 1;
	for (int i = 0; i < num; i++)
	{
		if (a[i - 1].clan == a[i].clan){ a[i].rankc = a[i - 1].rankc; }
		else a[i].rankc = i + 1;
	}
	sort(a, a + num, cmp2);
	a[0].rankm = 1;
	for (int i = 0; i < num; i++)
	{
		if (a[i - 1].math == a[i].math){ a[i].rankm = a[i - 1].rankm; }
		else a[i].rankm = i + 1;
	}
	sort(a, a + num, cmp3);
	a[0].rankeng = 1;
	for (int i = 0; i < num; i++)
	{
		if (a[i - 1].english == a[i].english){ a[i].rankeng = a[i - 1].rankeng; }
		else a[i].rankeng = i + 1;
	}
													
	int temp=-1;
	for (int i = 0; i < check; i++)
	{
		for (int j = 0; j < num; j++)
		{
			if (b[i] == a[j].stu)
			{
				temp = j;
				break;
			}
			else temp = -1;
		}

		
		if (temp != -1)						
		{
			if (a[temp].rankave <= a[temp].rankc&&a[temp].rankave <= a[temp].rankm&&a[temp].rankave <= a[temp].rankeng)
				printf("%d A\n", a[temp].rankave);
			else if (a[temp].rankc <= a[temp].rankave&&a[temp].rankc <= a[temp].rankm&&a[temp].rankc <= a[temp].rankeng)
				printf("%d C\n", a[temp].rankc);
			else if (a[temp].rankm <= a[temp].rankc&&a[temp].rankm <= a[temp].rankave&&a[temp].rankm <= a[temp].rankeng)
				printf("%d M\n", a[temp].rankm);
			else if (a[temp].rankeng <= a[temp].rankc&&a[temp].rankeng <= a[temp].rankm&&a[temp].rankeng <= a[temp].rankave)
				printf("%d E\n", a[temp].rankeng);
		}
		if (temp == -1)printf("N/A\n");
		
	}
	
	
	
	
}