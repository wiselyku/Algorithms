#include<iostream>
#include<map>
#include <stack>
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


bool isPalindrome(struct Node *head){
    struct Node *fast = head;
    struct Node *slow = head;
    stack<int> mystack;
    while(fast !=NULL && fast->next!=NULL){
        mystack.push(slow->data);
        slow = slow->next;
        fast = fast->next->next;
    }

    if(fast != NULL){
        slow = slow->next;
    }

    while(slow != NULL){
        int top = mystack.top();
        mystack.pop();
        if(top != slow->data){
            return false;
        }
        slow = slow->next;
    }
    return true;
}


int main(){

    bool del;
    struct Node *number1 = new Node;
    struct Node *number2 = new Node;
    struct Node *middle[10];
    initNode(number1,1);
    addNode(number1,2);
    addNode(number1,3);
    addNode(number1,2);
    addNode(number1,1);
    if(isPalindrome(number1)){
        cout<<"Yes, it is a palindrome"<<endl;
    }else{
        cout<<"No, it is not a palindrome"<<endl;
    }



return 0;
}

