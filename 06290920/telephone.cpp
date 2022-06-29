#include <iostream>
#include <string>
using namespace std;

#include "telephone.h"

telephone::telephone() {
	left = NULL;
	name = " ";
	number = " ";
	star=false;
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
	cout << "6. 수정" << endl;
	cout << "7. 즐겨찾기" << endl;
	cout << "8. 종료" << endl;
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

void telephone::delete_member(telepointer h, string name) {
	if (h->right == NULL) {
		cout << "삭제할 전화번호가 없습니다.\n";
		return;
	}
	telepointer n = h->right;
	while (n != NULL) {
		if (n->name == name) {
			if (n == h->right) {
				h->right = n->right;
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

void telephone::insertNode(telepointer h, string name, string number) {
	telepointer newnode = new telephone;
	newnode->left = NULL;
	newnode->right = NULL;
	newnode->name = name;
	newnode->number = number;

	telepointer n = h->right;

	if (h->right == NULL) {
		h->right = newnode;
		newnode->left = h;
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
	cout << "=================================" << endl;
	while (n) {
		cout << "이름: ";
		cout.width(15);
		cout.setf(ios_base::left);
		cout << n->name << "전화번호: " << n->number << endl;
		n = n->right;
	}
	cout << "=================================" << endl;
}

void telephone::modify(telepointer h) {
	string menu;
	cout << "수정하고 싶은 부분을 입력하세요: ";
	getline(cin, menu);

	if (menu == "이름") {
		string old_name, new_name, new_number;
		cout << "바꿀 이름을 입력하세요: ";
		getline(cin, new_name);
		old_name = this->name;
		new_number = this->number;
		delete_member(h, old_name);
		insertNode(h, new_name, new_number);
	}
	else if (menu == "전화번호") {
		string new_number;
		cout << "바꿀 번호를 입력하세요: ";
		getline(cin, new_number);
		this->number = new_number;
	}
	else if (menu == "모두") {
		string old_name, new_name, new_number;
		cout << "바꿀 이름을 입력하세요: ";
		getline(cin, new_name);
		cout << "바꿀 번호를 입력하세요: ";
		getline(cin, new_number);
		old_name = this->name;
		delete_member(h, old_name);
		insertNode(h, new_name, new_number);
	}
	else {
		cout << "잘못된 메뉴입니다.\n";
	}
}

void telephone::add_Favorites() {
	string s_name;
	telepointer p;
	cout << "즐겨찾기에 추가할 이름: ";
	cin >> s_name;
	p=searchNode(s_name);
	p->star = true;
}
void telephone::delete_Favorites() {
	string s_name;
	telepointer p;
	cout << "즐겨찾기에서 삭제할 이름: ";
	cin >> s_name;
	p = searchNode(s_name);
	p->star = false;
}
void telephone::print_Favorites() {
	telepointer n = this->right;
	cout << "=================================" << endl;
	cout << "\t즐겨찾기 목록\n";
	cout << "=================================" << endl;
	while (n) {
		if (n->star == true) {
			cout << "이름: ";
			cout.width(15);
			cout.setf(ios_base::left);
			cout << n->name << "전화번호: " << n->number << endl;
		}
		n = n->right;
	}
	cout << "=================================" << endl;
}