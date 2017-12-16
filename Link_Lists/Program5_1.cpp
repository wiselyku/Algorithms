#include<iostream>
#include<map>

using namespace std;

struct Node {
	int data;
	Node* next;
};

void initNode(struct Node *head,int n){
	head->data = n;
	head->next =NULL;
}

void display(struct Node *head) {
	Node *list = head;
	while(list) {
		cout << list->data << " ";
		list = list->next;
	}
	cout << endl;
	cout << endl;
}

void addNode(struct Node *head, int n) {
	Node *newNode = new Node;
	newNode->data = n;
	newNode->next = NULL;

	Node *cur = head;
	while(cur) {
		if(cur->next == NULL) {
			cur->next = newNode;
			return ;
		}
		cur = cur->next;
	}
}

struct Node *searchNode(struct Node *head, int n){
	Node *cur = head;
	while(cur) {
		if(cur->data == n) return cur;
		cur = cur->next;
	}
	//cout << "No Node " << n << " in list.\n";
	return NULL;
}

struct Node *addLists(struct Node *L1, struct Node *L2, int carry){
    if(L1==NULL && L2==NULL && carry ==0){
        return NULL;
    }

    struct Node *result = new Node;
    int value = carry;
    if(L1 != NULL){
        value += L1->data;
    }
    if(L2 != NULL){
        value += L2->data;
    }

    result->data = value%10;
    if(L1!=NULL || L2!=NULL){
        struct Node *more = addLists(L1==NULL?NULL:L1->next, L2==NULL?NULL:L2->next, value>=10?1:0);
        result->next = more;
    }
    return result;

}



int main(){

    bool del;
    struct Node *number1 = new Node;
    struct Node *number2 = new Node;
    struct Node *middle[10];
    initNode(number1,1);
    addNode(number1,5);
    addNode(number1,3);
    addNode(number1,2);
    addNode(number1,2);
    addNode(number1,4);
    initNode(number2,1);
    addNode(number2,5);
    addNode(number2,4);
    addNode(number2,9);
    addNode(number2,3);
    addNode(number2,2);
    addNode(number2,3);
    display(addLists(number1, number2, 0));


return 0;
}

