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
			cout << "\n\n" << "이름: ";
			cin >> t_name;
			cout << "전화번호: ";
			cin >> t_number;
			h->insertNode(t_name, t_number);
			break;
		case 2:
			cout << "찾을 이름을 입력하세요: ";
			getline(cin, SearchName);
			SearchResult = h->searchNode(SearchName);
			if (SearchResult) {
				cout << "=================================" << endl;
				cout << "이름: ";
				cout.width(15);
				cout.setf(ios_base::left);
				cout << SearchResult->name << "전화번호: " << SearchResult->number << endl;
				cout << "=================================" << endl;
			}
			else {
				cout << "결과 없음" << endl;
				cout << "\n\n";
			}
			break;
		case 3:
			cout << "삭제할 이름을 입력하세요: ";
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
			cout << "프로그램을 종료합니다.\n";
			break;
		}
	} while (menu != 6);

	h->delete_all();


	return 0;
}