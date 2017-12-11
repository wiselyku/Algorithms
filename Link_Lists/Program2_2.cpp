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
			return;
		}
		cur = cur->next;
	}
}

struct Node *searchNode(struct Node *head, int n) {
	Node *cur = head;
	while(cur) {
		if(cur->data == n) return cur;
		cur = cur->next;
	}
	//cout << "No Node " << n << " in list.\n";
	return NULL;
}

bool deleteNode(struct Node **head, Node *ptrDel) {
	Node *cur = *head;
	if(ptrDel == *head) {
		*head = cur->next;
		delete ptrDel;
		return true;
	}

	while(cur) {
		if(cur->next == ptrDel) {
			cur->next = ptrDel->next;
			delete ptrDel;
			return true;
		}
		cur = cur->next;
	}
	return false;
}

int printKthToLast(struct Node *head, int k){

    if(head == NULL){
        return 0;
    }
    int index = printKthToLast(head->next, k)+1;
    if(index == k){
        cout<<"the k-th to last node is "<<head->data;
    }
    return index;
}

struct Node* nthToLast(struct Node* head, int k, int& i){
    if(head == NULL){
        return NULL;
    }
    struct Node *nd = nthToLast(head->next, k, i);
    i = i + 1;
    if(i == k){
        return head;
    }

    return nd;
}

int main(){

    bool del;
    struct Node *head = new Node;
    initNode(head,10);
    addNode(head,12);
    addNode(head,14);
    addNode(head,15);
    addNode(head,21);
    addNode(head,42);
    addNode(head,33);
    addNode(head,45);
    addNode(head,51);
    display(head);
    int num = 0;
    int k = 3;
    //num = printKthToLast(head, k);
    struct Node *result = nthToLast(head, k, num);
    cout<<"i ="<<num<<" value ="<<result->data;

return 0;
}

