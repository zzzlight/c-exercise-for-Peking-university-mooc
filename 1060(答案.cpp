#include<iostream>
#include<string>
using namespace std; 


int num;
string trans(string a,int& e)
{
	int k=0;
	while(a[0]=='0'&&a.length()>0)
	{
		a.erase(a.begin());
	 } 
	 if(a[0]=='.')
	{
		a.erase(a.begin());
		while(a[0]=='0'&&a.length()>0)
		{
			a.erase(a.begin());
			e--;
		}
	}    //˵����С��1 
	else    //����1 
	{
		while(k<a.length()&&a[k]!='.')    //�Ҵ���1��С���� 
		{
			k++;
			e++;
		}
		if(k<a.length())
		{
			a.erase(a.begin()+k); 
		}    //����˵��������С���� 
	}
	if(a.length()==0)
	{
		e=0;
	}
	int n=0;
	k=0;
	string re;
	while(n<num)
	{
		if(k<a.length())
		{
			re+=a[k++];
		}
		else
		{
			re+='0';       //Ϊ0ʱ 
		}
		n++;
	}
	return re;
}

int main()
{
	string a;
	string b;
	int m=0;
	int n=0;
	cin>>num>>a>>b;
	string transa=trans(a,m);
	string transb=trans(b,n);
	if(transa==transb&&m==n)
	{
		cout<<"YES ";
		cout<<"0."<<transa<<"*10^"<<m;
	}
	else
	{
		cout<<"NO ";
		cout<<"0."<<transa<<"*10^"<<m<<" "<<"0."<<transb<<"*10^"<<n;
	}
}
