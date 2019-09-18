#include<stdio.h>
#include<vector>
#include<algorithm> 
#include<math.h>
using namespace std;

vector<bool> result;
bool flag=true;
struct Node
{
	int data;
	Node* leftchild;
	Node* rightchild;
	int blackcount;
};
int inorder[100];
int preorder[100];
vector<int> black;
bool cmp(int a,int b)
{
	return abs(a)<abs(b);
}
Node* create(int prel,int prer,int inl,int inr)
{
	if(prel>prer)
	{
		return NULL;
	}
	Node* node=new Node;
	node->data=preorder[prel];
	node->leftchild=NULL;
	node->rightchild=NULL;
	int k;
	for(k=inl;k<inr;k++)
	{
		if(preorder[prel]==inorder[k]) break;
	}
	int numl=k-inl;
	node->leftchild=create(prel+1,prel+numl,inl,k-1);
	node->rightchild=create(prel+numl+1,prer,k+1,inr);
	return node;
	
}
void dfs(Node* root,int count)
{
	if(root==NULL) //�ж���root==NULL���ڴ˼�¼  ��Ҫ����root==NULL����root->left&&right==NULL������һ��dfs�� �������� 
	{
		count++;   //Ҷ�ӣ�NULL�������Ǻ� ����ʵ�����ĵ����㲻��Ҳ��ac�� 
		black.push_back(count);  //����NULL�� ��¼���ɫ������ 
		return;
	}
	if(root->data<0)
	{
		if(root->leftchild!=NULL&&root->leftchild->data<0)
		{
			flag=false;
		 } 
		  if(root->rightchild!=NULL&&root->rightchild->data<0)
		 {
		 	flag=false;
		 }
	}
	if(root->data>0) count++;

	dfs(root->leftchild,count);
	dfs(root->rightchild,count);
	
 } 
int main()
{

	int num;
	scanf("%d",&num);
	for(int i=0;i<num;i++)
	{
		int potnum;
		scanf("%d",&potnum);
	//	vector<int> seq;
		flag=true;
		while(!black.empty())
		{
			black.pop_back();
		}
		for(int j=0;j<potnum;j++)
		{
			int temp;
			scanf("%d",&temp);
			inorder[j]=temp;
			preorder[j]=temp;
			if(j==0&&temp<0) flag=false;
		}
		sort(inorder,inorder+potnum,cmp);
		Node* root=create(0,potnum-1,0,potnum-1);
	//	printf("%d\n",root->leftchild->leftchild->data);
		dfs(root,0);
		for(int t=1;t<black.size();t++)
		{
			if(black[0]!=black[t]) flag=false;
		}
		result.push_back(flag);
	}
	
	for(int i=0;i<num;i++)
	{
		if(result[i]==true) printf("Yes");
		else printf("No");
		if(i!=num-1) printf("\n");
	}
 } 
