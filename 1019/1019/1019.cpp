#include<stdio.h>

#define max 45
int main(){

	long long y;
	long long q;    //���Ե�5�д������� Ҫ��longlong  ��ʱ�жϴ�����������40����  ��45��
	scanf("%lld %lld", &y, &q);
    int a[max];
	int num = 0;
	int flag =0 ;
	
	while (y != 0)
	{

		a[num++] = y%q;
		y = y / q;
		
	} 
	for (int j = 0; j <= num / 2; j++)
	{
		if (a[j] != a[num - 1-j])
		{
			
			flag = 1;
			break;
		}
	
		
		
	}
	if (flag == 0)  printf("Yes\n");
	else printf("No\n");
	for (int i = num-1; i >=0; i--)
	{
		if (i==num-1)
		printf("%d", a[i]);
		else printf(" %d", a[i]);
	}
	if (num == 0)printf("0");
}