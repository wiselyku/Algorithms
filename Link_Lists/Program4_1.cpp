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

struct Node *searchNode(struct Node *head, int n) {
	Node *cur = head;
	while(cur) {
		if(cur->data == n) return cur;
		cur = cur->next;
	}
	//cout << "No Node " << n << " in list.\n";
	return NULL;
}

struct Node* partition_list(struct Node *node, int x){
    struct Node *beforeStart = NULL;
    struct Node *beforeEnd = NULL;
    struct Node *afterStart = NULL;
    struct Node *afterEnd = NULL;
    while(node != NULL){
        struct Node *next = node->next;
        node->next = NULL;
        if(node->data < x){
            if(beforeStart == NULL){
                beforeStart = node;
                beforeEnd = beforeStart;
            }else{
                beforeEnd->next = node;
                beforeEnd = node;
            }
        }else{
            if(afterStart == NULL){
                afterStart = node;
                afterEnd = afterStart;
            }else{
                afterEnd->next = node;
                afterEnd = node;
            }
        }
        node = next;
    }

    if(beforeStart == NULL){
        return afterStart;
    }
    beforeEnd->next = afterStart;
    return beforeStart;
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

