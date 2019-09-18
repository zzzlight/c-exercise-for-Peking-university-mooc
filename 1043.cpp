#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

struct Node
{
	Node* leftchild;
	Node* rightchild;
	int data;
};
vector<int> orgin;
vector<int> preorder;
vector<int> postorder;
vector<int> mirpreorder;
vector<int>mirpostorder;


void insert(Node* &root,int temp)           //�������޸�rootֵ 
{
	if(root==NULL)
	{
		root=new Node;
		root->data=temp;	
		root->leftchild=NULL;
		root->rightchild=NULL;
		return;
	}
	if(temp<root->data)            //���ǿյ����ӽڵ�ȥ ��������ֱ��ΪNULL���½��ڵ� 
	{									 
		insert(root->leftchild,temp);
		
	}
	else
	{
		insert(root->rightchild,temp);
	}
	

}
void preorderfind(Node* root)
{
	if(root==NULL) return;
	preorder.push_back(root->data);
	if(root->leftchild!=NULL)
	{
		preorderfind(root->leftchild);
	}
	if(root->rightchild!=NULL)
	{
		preorderfind(root->rightchild);
	}
	
}
void mirpreorderfind(Node * root)
{
	if(root==NULL) return;
	mirpreorder.push_back(root->data);
	if(root->rightchild!=NULL)               //���������ʵ�ʾ���ԭ�����и����� 
	{
		mirpreorderfind(root->rightchild);
	}
	if(root->leftchild!=NULL)
	{
		mirpreorderfind(root->leftchild);
	}
	
	
}
void postorderfind(Node* root)
{
	if(root==NULL) return;
	if(root->leftchild!=NULL)
	{
		postorderfind(root->leftchild);
	}
	if(root->rightchild!=NULL)
	{
		postorderfind(root->rightchild);
	}
	postorder.push_back(root->data);
}
void mirpostorderfind(Node* root)
{
	if(root==NULL) return;
	if(root->rightchild!=NULL)
	{
		mirpostorderfind(root->rightchild);
	}
	if(root->leftchild!=NULL)
	{
		mirpostorderfind(root->leftchild);
	}
	
	mirpostorder.push_back(root->data);
}
int main()
{
	int num;
	Node* root=NULL;
	scanf("%d",&num);
	for(int i=0;i<num;i++)
	{
		int temp;
		scanf("%d",&temp);
		orgin.push_back(temp);
		insert(root,temp);  //��һ��Ϊ�ñ����޸���root  ����ѭ������root��Ϊnull��������������ѣ������ñ����޸���root�ĺ����ӽڵ� 
	}
	preorderfind(root);
	mirpreorderfind(root);
	if(orgin==preorder||orgin==mirpreorder) 
	{
		printf("YES\n");
		if(orgin==preorder)
		{
			postorderfind(root);
			auto x=postorder.begin();
			for(;x!=postorder.end()-1;x++)
			{
				printf("%d ",*x);
			}
			printf("%d",*x);
		}
		else
		{
			mirpostorderfind(root);
			auto x=mirpostorder.begin();
			for(;x!=mirpostorder.end()-1;x++)
			{
				printf("%d ",*x);
			}
			printf("%d",*x);
		}
	}
	else
	{
		printf("NO");
	}
	
 } 
