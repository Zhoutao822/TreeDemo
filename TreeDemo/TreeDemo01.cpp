// TreeDemo01.cpp : �������̨Ӧ�ó������ڵ㡣
//�������Ĵ洢�ṹ���������

#include "stdafx.h"
#include<queue>
using namespace std;
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

//�������
void preorder(node* root) {
	if (root == NULL) {
		return;
	}
	printf("%d\n", root->data);
	preorder(root->lchild);
	preorder(root->rchild);
}

//�������
void inorder(node* root) {
	if (root == NULL) {
		return;
	}
	inorder(root->lchild);
	printf("%d\n", root->data);
	inorder(root->rchild);
}

//�������
void postorder(node* root) {
	if (root == NULL) {
		return;
	}
	postorder(root->lchild);
	postorder(root->rchild);
	printf("%d\n", root->data);
}

//�򵥲������
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

//�����εĲ������
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

//����һ�Ŷ��������������������������ؽ�������
//��ǰ������������Ϊ[preL,preR],������������Ϊ[inL,inR],���ظ�����ַ
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

