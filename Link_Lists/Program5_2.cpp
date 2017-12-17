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

struct Node* insertBefore(struct Node *List, int data){
    struct Node *node = new Node;
    node->data = data;
    if(List!=NULL){
        node->next = List;
    }
    return node;

}

class PartialSum{
public:
    struct Node *sum = NULL;
    int carry;
    PartialSum(){
        carry = 0;
    }

};


PartialSum* addListsHelper(struct Node *L1, struct Node *L2){
    if(L1 == NULL && L2==NULL){
        PartialSum *sum = new PartialSum;
        return sum;
    }

    PartialSum *sum = addListsHelper(L1->next, L2->next);

    int val = sum->carry + L1->data + L2->data;

    struct Node *full_result = insertBefore(sum->sum, val%10);
    sum->sum = full_result;
    sum->carry = val/10;
    return sum;
}




struct Node* padList(struct Node *L, int padding){
    struct Node *head =L;
    for(int i=0; i<padding; i++){
        head = insertBefore(head, 0);
    }
    return head;
}


struct Node *addLists(struct Node *L1, struct Node *L2, int carry){
    int len1 = lengthNode(L1);
    int len2 = lengthNode(L2);

    if(len1<len2){
        L1 = padList(L1, len2-len1);
    }else{
        L2 = padList(L2, len1-len2);
    }

    PartialSum *sum = addListsHelper(L1,L2);

    if(sum->carry == 0){
        return sum->sum;
    }else{
        struct Node *result = insertBefore(sum->sum, sum->carry);
        return result;
    }
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

