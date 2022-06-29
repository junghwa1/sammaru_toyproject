#include <iostream>
#include <string>
using namespace std;

typedef struct telephone* telePointer; // refered to insert.cpp

struct telephone // refered to insert.cpp
{
	telePointer left;
	string name;
	string number;
	telePointer right;
};

void delete_member(telePointer h, string name);

void delete_all(telePointer h);

telephone createNode();
telePointer searchNode(telePointer h, string name);
void printMenu();

void insertnode(telePointer h, string name, string number); // refered to insert.cpp
void init(telePointer node); // refered to insert.cpp

int main()
{	
	string t_name, t_number;
	telePointer h=new telephone;
	h->right = NULL;
	h->left = NULL;
	int count = 0;
	string searchName;
	telePointer SearchResult;

	int Menu;
	do
	{
		printMenu();
		cin >> Menu;
		cin.ignore();
		switch (Menu)
		{
		case 1:
			cout << "\n\n"<<"이름 : ";
			cin >> t_name;
			cout << "전화번호 : ";
			cin >> t_number;
			insertnode(h,t_name,t_number);
			break;
		case 2:
			cout << "Enter the name you want to search : ";
			getline(cin, searchName);
			SearchResult = searchNode(h, searchName);
			if (SearchResult)
			{
				cout << "=================================" << endl;
				cout.width(18);
				cout.setf(ios_base::left);
				cout << SearchResult->name << SearchResult->number << endl;
				cout << "=================================" << endl;
			}
			else
			{
				cout << "No result" << endl;
				cout << "\n\n";
			}
			break;
		case 3:
			cout << "Enter the name you want to delete : ";
			cin >> t_name;
			delete_member(h, t_name);
			break;
		case 4: {
			cout << "The program has been ended" << endl;
		}
		default:
			cout << "Plese again\n";
		}

	} while (Menu != 4);

	return 0;
}
telephone createNode()
{
	telephone newNode;

	newNode.left = NULL;
	newNode.right = NULL;
	newNode.name = "";
	newNode.number = "";

	return newNode;
}
telePointer searchNode(telePointer h, string name)
{
	telePointer n = new telephone;
	n = h->right;
	while (n) {
		if (n->name == name)
			return n;
		n = n->right;
	}
	
	return NULL;
}
void printMenu()
{
	cout << "===========Menu===========" << endl;
	cout << "1. Add Contacts" << endl;
	cout << "2. Search Contacts" << endl;
	cout << "3. Delete Contacts" << endl;
	cout << "4. Exit the program" << endl;
	cout << "==========================" << endl;
	cout << "Menu : ";
}

void init(telePointer node) // refered to insert.cpp
{
	node->name = " ";
	node->number = " ";
	node->left = NULL;
	node->right = NULL;
}

void insertnode(telePointer h, string name, string number) {
	telePointer newnode = new telephone;
	newnode->left=NULL;
	newnode->right = NULL;
	newnode->name = name;
	newnode->number = number;

	telePointer n=h->right;
	
	if (h->right == NULL) {
		h->right = newnode;
		newnode->left = h;
		return;
	}
	telePointer trail;
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


void delete_member(telePointer h, string name) {

	if (h->right == NULL){	//member가 없을 시 함수 종료
		cout << "삭제할 전화번호가 없습니다.\n";
		return;
	}
	telePointer n = h->right;
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

	cout <<"해당 전화번호를 찾지 못하였습니다.("<< name <<")\n"; //탐색 실패
	return;
}

void delete_all(telePointer h) {
	telePointer p=h->right;
	telePointer trail;
	while (p) {
		trail = p;
		p=p->left;
		free(trail);
	}
	free(h);
}