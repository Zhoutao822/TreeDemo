// TreeDemo01.cpp : �������̨Ӧ�ó������ڵ㡣
//�������Ĵ洢�ṹ���������

#include "stdafx.h"

//�������Ĵ洢�ṹ
struct node {
	int data;
	node* lchild;
	node* rchild;
};

//����һ���½�㣬vΪ���Ȩֵ
node* newNode(int v) {
	node* Node = new node;
	Node->data = v;
	Node->lchild = Node->rchild = NULL;
	return Node;
}

//�������Ĳ��ҡ��޸�
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

//���������Ĳ���
void insert(node* &root, int x) {
	if (root == NULL) {
		root == newNode(x);
		return;
	}
	if (x <= root->data) {//�жϷ�ʽ�����������Ĺ��췽����x�Ƚ��ֵ�����������
		insert(root->lchild, x);
	}
	else
	{
		insert(root->rchild, x);
	}
}

//�������Ĵ���
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

