#include<stdio.h>
#include<string.h>
int num;

struct Max
{
	int max=-1;          //��ʼ��Ϊ-1������һ��0���ⶼ�Ǹ����ʱfindmax�������á�
	int myleft=0;
	int myright=num-1;
};
Max findmax(int a[], int num);
int main()
{
	int num;
	scanf("%d", &num);
	int seq[10500];
	memset(seq, 0, sizeof(seq));
	for (int i = 0; i < num; i++)
	{
		scanf("%d", &seq[i]);
	}
	Max sum;
	int left=0;
	int right=num-1;
	int j;
	Max mymax;
	
	for ( j = 0; j < num; j++)
	{
		mymax=findmax(seq+j, num - j);
		mymax.myleft = j;
		mymax.myright = mymax.myright + j; //ƫ��
		if (mymax.max > sum.max)
		{
			sum.max = mymax.max;
			sum.myleft = mymax.myleft;
			sum.myright = mymax.myright;
		}
	}
	int x = 0;
	while (seq[x]<0)
	{
		
		x++;

	}
	if (x == num) printf("0 %d %d",seq[0],seq[num-1]);
	else
	printf("%d %d %d", sum.max, seq[sum.myleft], seq[sum.myright]);

}

Max findmax(int a[],int num)
{
	Max max;
	int sum=0 ;

	for (int i = 0; i < num; i++)
	{
		sum += a[i];
		if (sum > max.max)
		{
			max.max = sum;
			max.myright = i;
		}
		
	}
	return max;
}
//����Ҫô���� Ҫô��̬�滮