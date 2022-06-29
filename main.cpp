#include <iostream>
#include <string>
using namespace std;

#include "telephone.h"

int main() {
	string t_name, t_number;
	telepointer h = new telephone;

	int count = 0;
	string SearchName;
	telepointer SearchResult;

	int menu;
	do {
		h->printMenu();
		cin >> menu;
		cin.ignore();

		switch (menu) {
		case 1:
			cout << "\n\n" << "�̸�: ";
			cin >> t_name;
			cout << "��ȭ��ȣ: ";
			cin >> t_number;
			h->insertNode(t_name, t_number);
			break;
		case 2:
			cout << "ã�� �̸��� �Է��ϼ���: ";
			getline(cin, SearchName);
			SearchResult = h->searchNode(SearchName);
			if (SearchResult) {
				cout << "=================================" << endl;
				cout << "�̸�: ";
				cout.width(15);
				cout.setf(ios_base::left);
				cout << SearchResult->name << "��ȭ��ȣ: " << SearchResult->number << endl;
				cout << "=================================" << endl;
			}
			else {
				cout << "��� ����" << endl;
				cout << "\n\n";
			}
			break;
		case 3:
			cout << "������ �̸��� �Է��ϼ���: ";
			cin >> t_name;
			h->delete_member(t_name);
			break;
		case 4:
			h->show_member();
			break;
		case 5:
			h->delete_all();
			break;
		case 6:
			cout << "���α׷��� �����մϴ�.\n";
			break;
		}
	} while (menu != 6);

	h->delete_all();


	return 0;
}