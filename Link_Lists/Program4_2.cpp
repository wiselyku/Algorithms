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

struct Node* partition_list(struct Node *node, int x){
    struct Node *head = node;
    struct Node *tail = node;

    while(node != NULL){
        struct Node *next = node->next;
        if(node->data < x){
            node->next = head;
            head = node;
        }else{
            tail->next = node;
            tail = node;
        }
        node = next;
    }
    tail->next = NULL;
    return head;
}



int main(){

    bool del;
    struct Node *head = new Node;
    struct Node *middle[10];
    initNode(head,10);
    addNode(head,55);
    addNode(head,33);
    addNode(head,15);
    addNode(head,21);
    addNode(head,42);
    addNode(head,15);
    addNode(head,45);
    addNode(head,19);
    display(head);
    display(partition_list(head, 30));

return 0;
}

