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


class Result{
public:
    struct Node *node;
    bool result;

};

Result* isPalindromeRecurse(struct Node *head, int length){
    if(head == NULL || length<=0){
        Result *r = new Result;
        r->node = head;
        r->result = true;
        return r;
    }else if(length==1){
        Result *r = new Result;
        r->node = head->next;
        r->result = true;
        return r;
    }

    Result *res = isPalindromeRecurse(head->next, length-2);

    if(!res->result || res->node ==NULL){
        return res;
    }

    res->result = (head->data == res->node->data);

    res->node = res->node->next;

    return res;
}

bool isPalindrome(struct Node *head){
    int length = lengthNode(head);
    Result *p = isPalindromeRecurse(head, length);
    return p->result;
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
    addNode(number1,3);
    if(isPalindrome(number1)){
        cout<<"Yes, it is a palindrome"<<endl;
    }else{
        cout<<"No, it is not a palindrome"<<endl;
    }



return 0;
}

