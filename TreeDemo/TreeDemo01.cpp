// TreeDemo01.cpp : 定义控制台应用程序的入口点。
//二叉树的存储结构与基本操作

#include "stdafx.h"

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

int main()
{

    return 0;
}

