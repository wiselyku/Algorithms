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


class Result{
public:
    struct Node *tail;
    int size_of_list;
    Result(struct Node *t, int s){
        this->tail = t;
        this->size_of_list = s;
    }
};

Result* getTailAndSize(struct Node *List){
    if(List==NULL){
        return NULL;
    }

    int size_s = 1;
    struct Node *current = List;
    while(current->next!=NULL){
        size_s++;
        current = current->next;
    }
    return new Result(current, size_s);
}

struct Node* getKthNode(struct Node *head, int k){
    struct Node *current = head;
    while(k>0 && current!=NULL){
        current = current->next;
        k--;
    }
    return current;
}

struct Node* findIntersection(struct Node *list1, struct Node *list2){
    if(list1 == NULL || list2 ==NULL){
        return NULL;
    }

    Result *result1 = getTailAndSize(list1);
    Result *result2 = getTailAndSize(list2);

    if(result1->tail!=result2->tail){
        return NULL;
    }

    struct Node *shorter = result1->size_of_list < result2->size_of_list ? list1: list2;
    struct Node *longer = result1->size_of_list < result2->size_of_list ? list2: list1;

    longer =getKthNode(longer, abs(result1->size_of_list - result2->size_of_list));

    while(shorter != longer){
        shorter = shorter->next;
        longer = longer->next;
    }

    return longer;
}




int main(){

    bool del;
    struct Node *number1 = new Node;
    struct Node *number2 = new Node;
    struct Node *number3 = new Node;
    struct Node *middle[10];
    initNode(number1,1);
    addNode(number1,2);
    addNode(number1,3);
    addNode(number1,2);
    addNode(number1,3);

    struct Node *number1_tail = number1;
    number1_tail = number1_tail->next->next;

    initNode(number2,1);
    addNode(number2,2);
    addNode(number2,3);
    addNode(number2,2);
    addNode(number2,3);
    struct Node *number2_tail = number2;
    number2_tail = number2_tail->next;

    initNode(number3,1);
    addNode(number3,2);
    addNode(number3,3);
    addNode(number3,2);
    addNode(number3,3);
    number1_tail->next = number3;
    number2_tail->next = number3;



    struct Node *result = findIntersection(number1, number2);
    if(result==NULL){
            cout<<"No intersection"<<endl;
    }else{
        cout<<"Has an intersection"<<endl;
    }

return 0;
}

