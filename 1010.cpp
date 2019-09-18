#include<iostream>
#include<string>
#include<map>
#include<algorithm>
using namespace std;
long long inf = 0x7FFFFFFFFFFFFFFF;
map<char, int> mymap;
long long sumn1 = 0;
long long sumn2 = 0;
string n1;
string n2;
long long tag;
long long radix;

void init()
{
	for (char i = '0'; i <= '9'; i++)
	{
		mymap[i] = i - '0';
	}
	for (char i = 'a'; i <= 'z'; i++)
	{
		mymap[i] = 10 + (i - 'a');
	}
}

long long totherax(string num,long long rax,long long t)
{
	long long sum = 0;
	for (long long i = 0; i < num.length(); i++)
	{
		sum=mymap[num[i]]+rax*sum;
		if(sum<0||sum>t) return -1; //���ظ��������Ǹ������ᷢ����� ������С��0ר������cmp��n2������� 
	}
	return sum;
}
int cmp(string n2,long long rax,long long t)  //t��n1��ʮ���� 
{
	long long num=totherax(n2,rax,t);
	if(num<0) return 1;  //������� ˵��n2�ش���n1
	if(t==num)  return 0;
	else if(t>num) return -1; //n1����n2  ˵���趨��radix��С�� 
	else return 1;  //�����д�С  n1С��n2  �趨radix���� 
}
long long binarysearch(string n2,long long left,long long right,long long t)
{
	long long mid;
	while(left<=right)
	{
		mid=(left+right)/2;
		int flag=cmp(n2,mid,t);
		if(flag==0) return mid;
		if(flag==-1) left=mid+1;
		else right=mid-1;
	}
	return -1;
}
int main()
{

	cin >> n1;
	cin >> n2;
	cin >> tag >> radix;
	init();
	if(tag==2)
	{
		swap(n1,n2); //��֤n1������֪���Ƶ� 
	}
	long long n1flag=totherax(n1,radix,inf);
	long long mymax=-1;
	for(long long i=0;i<n2.length();i++)
	{
		if(mymax<mymap[n2[i]]) mymax=mymap[n2[i]];
	}
	long long low=mymax+1; //��n2��������ּ�һ ����С���ܵĽ���

	long long high ;//n1��Ϊʮ���ƺ�� 
	if(low>n1flag) high=low+1;
	else high=n1flag+1;
	long long  result=binarysearch(n2,low,high,n1flag);
	if(result==-1) cout<<"Impossible";
	else cout<<result;
}
