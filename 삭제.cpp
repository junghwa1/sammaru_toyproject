#include <iostream>
#include <string>
using namespace std;

struct telephone {
	telePointer left;
	string name;
	string number;
	telePointer right;
};

typedef struct telephone* telePointer;

typedef struct head {
	telePointer first;
}headnode;

void delete_member(headnode* h, string name);

void delete_all(headnode* h);

int main() {



	return 0;
}

void delete_member(headnode* h, string name) {

	if (h->first == NULL){	//member가 없을 시 함수 종료
		cout << "삭제할 전화번호가 없습니다.\n";
		return;
	}
	telePointer n = h->first;
	while (n != NULL) {
		if (n->name == name) {
			if (n == h->first) {
				h->first = n->right;
				
				free(n);
			}
			else if (n->right == NULL) {
				n->left->right == NULL;
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

void delete_all(headnode* h) {
	telePointer p=h->first;
	telePointer trail;
	while (p) {
		trail = p;
		p=p->left;
		free(trail);
	}
	free(h);
}