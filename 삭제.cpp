#include <iostream>
#include <string>
using namespace std;

typedef struct node {
	struct node* left;
	struct node* right;
	string name;
} listnode;

typedef struct head {
	struct node* first;
}headnode;

void delete_member(headnode* h, string name);

int main() {



	return 0;
}

void delete_member(headnode* h, string name) {

	if (h->first == NULL){	//member가 없을 시 함수 종료
		cout << "삭제할 전화번호가 없습니다.\n";
		return;
	}
	listnode* n = h->first;
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