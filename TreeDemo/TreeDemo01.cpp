// TreeDemo01.cpp : 定义控制台应用程序的入口点。
//二叉树的存储结构与基本操作

#include "stdafx.h"
#include<queue>
using namespace std;
//二叉树的存储结构
struct node {
	int data;
	node* lchild;
	node* rchild;
};

//生成一个新结点，v为结点权值
node* newNode(int v) {
	node* Node = new node;
	Node->data = v;
	Node->lchild = Node->rchild = NULL;
	return Node;
}

//二叉树的查找、修改
void search(node* root, int x, int newdata) {
	if (root == NULL) {
		return;
	}
	if (root->data == x) {
		root->data = newdata;
	}
	search(root->lchild, x, newdata);
	search(root->rchild, x, newdata);
}

//二叉树结点的插入
void insert(node* &root, int x) {
	if (root == NULL) {
		root == newNode(x);
		return;
	}
	if (x <= root->data) {//判断方式决定二叉树的构造方法，x比结点值大的在右子树
		insert(root->lchild, x);
	}
	else
	{
		insert(root->rchild, x);
	}
}

//二叉树的创建
node* Create(int data[],int n) {
	node* root = NULL;
	for (int i = 0; i < n; i++) {
		insert(root, data[i]);
	}
	return root;
}

//先序遍历
void preorder(node* root) {
	if (root == NULL) {
		return;
	}
	printf("%d\n", root->data);
	preorder(root->lchild);
	preorder(root->rchild);
}

//中序遍历
void inorder(node* root) {
	if (root == NULL) {
		return;
	}
	inorder(root->lchild);
	printf("%d\n", root->data);
	inorder(root->rchild);
}

//后序遍历
void postorder(node* root) {
	if (root == NULL) {
		return;
	}
	postorder(root->lchild);
	postorder(root->rchild);
	printf("%d\n", root->data);
}

//简单层序遍历
void layerorder(node* root) {
	queue<node*> q;
	q.push(root);
	while (!q.empty()) {
		node* now = q.front();
		q.pop();
		printf("%d", now->data);
		if (now->lchild != NULL) q.push(now->lchild);
		if (now->rchild != NULL) q.push(now->rchild);
	}
}

//计算层次的层序遍历
struct node {
	int data;
	int layer;
	node* lchild;
	node* rchild;
};

void LayerOrder(node* root) {
	queue<node*> q;
	root->layer = 1;
	q.push(root);
	while (!q.empty()) {
		node* now = q.front();
		q.pop();
		printf("%d\n", now->data);
		if (now->lchild != NULL) {
			now->lchild->layer = now->layer + 1;
			q.push(now->lchild);
		}
		if (now->rchild != NULL) {
			now->rchild->layer = now->layer + 1;
			q.push(now->rchild);
		}
	}
}

//给定一颗二叉树的先序遍历和中序遍历，重建二叉树
//当前先序序列区间为[preL,preR],中序序列区间为[inL,inR],返回根结点地址
int pre[];
int in[];
node* create(int preL, int preR, int inL, int inR) {
	if (preL > preR) {
		return NULL;
	}
	node* root = new node;
	root->data = pre[preL];
	int k;
	for (k = inL; k <= inR; k++) {
		if (in[k] == pre[preL]) {
			break;
		}
	}
	int numLeft = k - inL;

	root->lchild = create(preL + 1, preL + numLeft, inL, k - 1);

	root->rchild = create(preL + numLeft + 1, preR, k + 1, inR);

	return root;
}

int main()
{

    return 0;
}

