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
	cout << "1. 추가" << endl;
	cout << "2. 검색" << endl;
	cout << "3. 삭제" << endl;
	cout << "4. 출력" << endl;
	cout << "5. 전체 삭제" << endl;
	cout << "6. 종료" << endl;
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
		cout << "삭제할 전화번호가 없습니다.\n";
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

	cout << "해당 전화번호를 찾지 못했습니다. (" << name << ")\n";
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
		cout << "이름: ";
		cout.width(15);
		cout.setf(ios_base::left);
		cout << n->name << "전화번호: " << n->number << endl;
		cout << "=================================" << endl;
		n = n->right;
	}
}