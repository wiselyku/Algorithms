#include<iostream>
#include<map>
#include <stack>
#include <stdlib.h>
using namespace std;

class FixedMultiStack{

private:
    int numberOfStacks;
    int stackCapacity;
    int *values;
    int *sizes;
    int indexOfTop(int stackNum){
        int offset = stackNum * stackCapacity;
        int size = sizes[stackNum];
        return offset + size -1;
    }

public:
    FixedMultiStack(int stackSize){
	numberOfStacks = 3;
        stackCapacity = stackSize;
        values = new int[stackSize*numberOfStacks];
        sizes = new int[numberOfStacks];
    }

    void push(int stackNum, int value){
        if(isFull(stackNum)){
            cout<<"stack is full"<<endl;
        }
        sizes[stackNum]++;
        values[indexOfTop(stackNum)] = value;
    }

    int pop(int stackNum){
        if(isEmpty(stackNum)){
            cout<<"stack is empty"<<endl;
        }

        int topIndex = indexOfTop(stackNum);
        int value = values[topIndex];
        values[topIndex] = 0;
        sizes[stackNum]--;
        return value;
    }

    int peek(int stackNum){
        if(isEmpty(stackNum)){
            cout<<"stack is empty"<<endl;
        }
        return values[indexOfTop(stackNum)];
    }

    bool isEmpty(int stackNum){
        return sizes[stackNum] ==0;
    }

    bool isFull(int stackNum){
        return sizes[stackNum] == stackCapacity;
    }



};



int main(){
    FixedMultiStack *stack_A = new FixedMultiStack(3);
    stack_A->push(1,1);
    stack_A->push(1,2);
    stack_A->push(1,3);
    cout<<stack_A->peek(1)<<endl;
    stack_A->push(1,4);

return 0;
}

