#include <iostream>
#include <string>
using namespace std;

#include "telephone.h"

telephone::telephone() {
	left = NULL;
	name = " ";
	number = " ";
	right = NULL;
}

telephone::~telephone() {
}

void telephone::printMenu() {
	cout << "\n";
	cout << "===========Menu===========" << endl;
	cout << "1. �߰�" << endl;
	cout << "2. �˻�" << endl;
	cout << "3. ����" << endl;
	cout << "4. ���" << endl;
	cout << "5. ��ü ����" << endl;
	cout << "6. ����" << endl;
	cout << "==========================" << endl;
	cout << "Menu : ";
}

telephone telephone::createNode() {
	telephone newNode;

	newNode.left = NULL;
	newNode.name = "";
	newNode.number = "";
	newNode.right = NULL;

	return newNode;
}

void telephone::delete_member(string name) {
	if (this->right == NULL) {
		cout << "������ ��ȭ��ȣ�� �����ϴ�.\n";
		return;
	}
	telepointer n = this->right;
	while (n != NULL) {
		if (n->name == name) {
			if (n == this->right) {
				this->right = n->right;
				free(n);
			}
			else if (n->right == NULL) {
				n->left->right = NULL;
				free(n);
			}
			else {
				n->left->right = n->right;
				n->right->left = n->left;
				free(n);
			}
			return;
		}
		n = n->right;
	}

	cout << "�ش� ��ȭ��ȣ�� ã�� ���߽��ϴ�. (" << name << ")\n";
	return;
}

void telephone::delete_all() {
	telepointer p = this->right;
	telepointer trail;
	while (p) {
		trail = p;
		p = p->right;
		delete trail;
	}
	this->right = NULL;
}

telepointer telephone::searchNode(string name) {
	telepointer n = new telephone;
	n = this->right;
	while (n) {
		if (n->name == name)
			return n;
		n = n->right;
	}

	return NULL;
}

void telephone::insertNode(string name, string number) {
	telepointer newnode = new telephone;
	newnode->left = NULL;
	newnode->right = NULL;
	newnode->name = name;
	newnode->number = number;

	telepointer n = this->right;

	if (this->right == NULL) {
		this->right = newnode;
		newnode->left = this;
		return;
	}

	telepointer trail;
	while (n) {
		if (newnode->name < n->name) {
			newnode->left = n->left;
			newnode->right = n;
			n->left->right = newnode;
			n->left = newnode;
			break;
		}
		trail = n;
		n = n->right;
	}
	if (n == NULL) {
		trail->right = newnode;
		newnode->left = trail;
	}
}

void telephone::show_member() {
	telepointer n = this->right;
	while(n){
		cout << "=================================" << endl;
		cout << "�̸�: ";
		cout.width(15);
		cout.setf(ios_base::left);
		cout << n->name << "��ȭ��ȣ: " << n->number << endl;
		cout << "=================================" << endl;
		n = n->right;
	}
}