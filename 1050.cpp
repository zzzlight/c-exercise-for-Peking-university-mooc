#include<stdio.h>

#include<string.h>


bool amap[10001];
int main()
{
		char orgin[100050];
		char sub[100050];
		fgets(orgin,100050,stdin);      //fgets   ���������������ʱ��Ļ��з� 
		fgets(sub,100050,stdin);
		for(int j=0;j<strlen(sub);j++)     //�˴�strlen-1���Ļ��в�Ӱ�� ��Ϊ�ж�ʱ��ɾ����  ���ұ�������Ĳ��Ậ���� 
		{
			amap[sub[j]]=true;	
		}
		for(int i=0;i<strlen(orgin);i++)
		{
			if(amap[orgin[i]]==false) printf("%c",orgin[i]);
		}
		 
		
		
} 
/*
fgets(...)�����ı���ʱ�����������

 1.���n����һ�е��ַ������ȣ���ô�������ַ���ĩβ�Ļ��з�ʱ��fgets(..)�᷵�ء�������s���������ַ���������־'\0'�� ��s������ʣ���λ�ò�������䡣

example��

 123abc

fgets(s,10,fp);

��ʱ�������߸��ַ���123abc\n,ʵ���ϻ�������'\0',���ԣ�strlen(s)=7; ���Ҫȥ��ĩβ��\n��s[strlen(s)-1]='\0';��ɡ�

2.���nС�ڵ���һ�е��ַ����ĳ��ȣ���ô����n-1���ַ�����ʱ��û�ж���\n��Ϊ��û�е���β ��ͬ�����������'\0'.

 example:
 123abc

 char s[5];

fgets(s,5,fp);

��ʱ����4���ַ���123a,��û�л��з�������strlen(s)=4.
--------------------- 

*/ 
/*
#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main()
{
		string orgin;
		vector<char> t;
		string tt;
		getline(cin,orgin);
		
	//	cout<<orgin<<endl;
		getline(cin,tt);
		
		for(auto it1=orgin.begin();it1!=orgin.end()-1;it1++)
		{
			for(auto it2=tt.begin();it2!=tt.end();it2++)
			{
				if((*it1)==(*it2))
				{
					orgin.erase(it1);
				}
			}
		}    //11112222   ����1  ����2  �����
		
		cout<<orgin;
		
} */
