#include<iostream>
#include<map>
#include <stack>
#include <stdlib.h>
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

int lengthNode(struct Node *head){
    int len = 0;
	Node *cur = head;
	while(cur) {
		cur = cur->next;
		len++;
	}

	return len;
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


struct Node* FindBeginnig(struct Node *head){
    struct Node *slow =head;
    struct Node *fast = head;

    while(fast != NULL && fast->next !=NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            break;
        }
    }

    if(fast ==NULL || fast->next ==NULL){
        return NULL;
    }

    slow = head;
    while(slow != fast){
        slow = slow->next;
        fast = fast->next;
    }
    return fast;
}





int main(){


    struct Node *number1 = new Node;
    struct Node *tail;
    struct Node *collid_spot;

    initNode(number1,11);
    tail = number1;
    collid_spot = number1;
    addNode(number1,29);
    tail = tail->next;
    collid_spot = collid_spot->next;
    addNode(number1,63);
    tail = tail->next;
    collid_spot = collid_spot->next;
    addNode(number1,57);
    tail = tail->next;
    collid_spot = collid_spot->next;
    addNode(number1,12);
    tail = tail->next;
    collid_spot = collid_spot->next;
    addNode(number1,22);
    tail = tail->next;
    collid_spot = collid_spot->next;
    addNode(number1,31);
    tail = tail->next;
    addNode(number1,53);
    tail = tail->next;
    addNode(number1,33);
    tail = tail->next;
    addNode(number1,23);
    tail = tail->next;
    addNode(number1,32);
    tail = tail->next;
    addNode(number1,34);
    tail = tail->next;
    tail->next = collid_spot;
    struct Node *beginning_point = FindBeginnig(number1);
    if(beginning_point==NULL){
        cout<<"No, collision"<<endl;
    }else{

        cout<<"Yes, there is a cycle, and the loop beginning point is "<<beginning_point->data<<endl;
    }

return 0;
}

