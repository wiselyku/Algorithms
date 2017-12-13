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

struct Node* addNode(struct Node *head, int n) {
	Node *newNode = new Node;
	newNode->data = n;
	newNode->next = NULL;

	Node *cur = head;
	while(cur) {
		if(cur->next == NULL) {
			cur->next = newNode;
			return cur->next;
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

bool deleteNode(struct Node* n){
    if(n == NULL || n->next ==NULL){
        cout<<"I am here"<<endl;
        return false;
    }
    struct Node* next = n->next;
    n->data = next->data;
    n->next = next->next;
    return true;

}

int main(){

    bool del;
    struct Node *head = new Node;
    struct Node *middle[10];
    initNode(head,10);
    middle[0] = addNode(head,12);
    middle[1] = addNode(head,14);
    middle[2] = addNode(head,15);
    middle[3] = addNode(head,21);
    middle[4] = addNode(head,42);
    middle[5] = addNode(head,33);
    middle[6] = addNode(head,45);
    middle[7] = addNode(head,51);
    display(head);
    int num = 0;
    int k = 3;
    if(deleteNode(middle[5])){
        cout<<"Yes, deleted the middle"<<endl;
    }else{
        cout<<"No, this node is not in the middle"<<endl;
    }
    display(head);
return 0;
}

