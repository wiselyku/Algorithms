#include<iostream>

using namespace std;

class TreeNode{
public:
    TreeNode *leftchild;
    TreeNode *rightchild;
    TreeNode *parent;
    int value;

};

bool insertNode(TreeNode *root, TreeNode *newNode){
    if(root==nullptr || root==0){
        return false;
    }
    TreeNode *tempRoot = root;
    TreeNode *target = nullptr;
    while(tempRoot!=nullptr){
        target = tempRoot;
        if(tempRoot->value>newNode->value){
            tempRoot = tempRoot->leftchild;
        }else{
            tempRoot = tempRoot->rightchild;
        }
    }

    newNode->parent = target;
    if(target->value>newNode->value){
        target->leftchild = newNode;
    }else{
        target->rightchild = newNode;
    }
    return true;
}

TreeNode* searchNode(TreeNode **root, int value){
    if( (*root)==nullptr || (*root)==0){
        return nullptr;
    }
    TreeNode *tempRoot = (*root);
    while(tempRoot!=nullptr){
        if(tempRoot->value > value){
            tempRoot = tempRoot->leftchild;
        }else if(tempRoot->value < value){
            tempRoot = tempRoot->rightchild;
        }else{
            return tempRoot;
        }
    }
    return nullptr;

}

void inorderTraversal(TreeNode *root){

    if(root==nullptr){
            return;
    }
    else
    {
        inorderTraversal(root->leftchild);
        cout<<root->value<<", ";
        inorderTraversal(root->rightchild);
    }

}

void preorderTraversal(TreeNode *root){

    if(root==nullptr){
            return;
    }
    else
    {
        cout<<root->value<<", ";
        preorderTraversal(root->leftchild);
        preorderTraversal(root->rightchild);
    }

}

void postorderTraversal(TreeNode *root){

    if(root==nullptr){
            return;
    }
    else
    {
        postorderTraversal(root->leftchild);
        postorderTraversal(root->rightchild);
        cout<<root->value<<", ";
    }

}


TreeNode* successor(TreeNode *node){
    TreeNode *tempNode = node;
    TreeNode *target = nullptr;
    if(tempNode->rightchild==nullptr){
        return nullptr;
    }else{
        tempNode = tempNode->rightchild;
    }

    while(tempNode!=nullptr){
        target = tempNode;
        tempNode = tempNode->leftchild;
    }

    return target;

}

bool deleteNode(TreeNode **root, int value){
    if(root==nullptr || root==0){
        return false;
    }
    TreeNode *tempRoot = (*root);

    while(tempRoot!=nullptr){
        if(tempRoot->value > value){
            tempRoot = tempRoot->leftchild;
        }else if(tempRoot->value < value){
            tempRoot = tempRoot->rightchild;
        }else{
            // 找到要刪除的點

            TreeNode *successorNode = successor(tempRoot);
            if(successorNode==nullptr){
                    // 處理case 1， 要刪除的點沒有右子樹，所以直接左子樹往上
                if(tempRoot->parent!=nullptr){
                    if(tempRoot == tempRoot->parent->rightchild){
                        tempRoot->parent->rightchild = tempRoot->leftchild;
                    }else{
                        tempRoot->parent->leftchild = tempRoot->leftchild;
                    }
                }else{
                    // 要刪除的點是root
                    if(tempRoot->leftchild!=nullptr){
                        (*root) = tempRoot->leftchild;
                        (*root)->parent = nullptr;
                    }else{
                        (*root) = nullptr;
                    }
                }

            }else{
                if(successorNode->parent==tempRoot){
                    // 處理case 2， 要刪除的點的successor 剛好是他的右兒子，所以直接把右兒子拉上來，這個case右兒子剛好沒有左兒子，所以左兒子指向要刪除的點的左兒子

                    // 如果要刪除的點又剛好是root
                    if(tempRoot==(*root)){
                         successorNode->leftchild = (*root)->leftchild;
                        (*root) = successorNode;
                        (*root)->parent = nullptr;
                    }else{
                        if(tempRoot == tempRoot->parent->rightchild){
                            tempRoot->parent->rightchild = successorNode;
                            successorNode->parent = tempRoot->parent;
                            successorNode->leftchild = tempRoot->leftchild;
                            if(tempRoot->leftchild!=nullptr){
                                tempRoot->leftchild->parent = successorNode;
                            }else{

                            }

                        }else{
                            tempRoot->parent->leftchild = successorNode;
                            successorNode->parent = tempRoot->parent;
                            successorNode->leftchild = tempRoot->leftchild;
                            if(tempRoot->leftchild!=nullptr){
                                tempRoot->leftchild->parent = successorNode;
                            }else{

                            }
                        }
                    }
                }else{
                    // 處理 case 3，要刪除的點有比較遠的successor，把successor 取代要刪除的點，successor 的父親的左兒子指向successor 的右兒子
                    // successor 的左右兒子改為指向要被刪除的點的左右兒子
                    successorNode->parent->leftchild = successorNode->rightchild;
                    // 又要刪除的點剛好是root
                    if(tempRoot==(*root)){
                         successorNode->rightchild = tempRoot->rightchild;
                         successorNode->leftchild = tempRoot->leftchild;
                         (*root) = successorNode;
                         (*root)->parent = nullptr;
                    }else{
                        if(tempRoot == tempRoot->parent->rightchild){
                            tempRoot->parent->rightchild = successorNode;
                            successorNode->parent = tempRoot->parent;
                            successorNode->rightchild = tempRoot->rightchild;
                            successorNode->leftchild = tempRoot->leftchild;
                            tempRoot->rightchild->parent = successorNode;
                            if(tempRoot->leftchild!=nullptr){
                                tempRoot->leftchild->parent = successorNode;
                            }

                        }else{
                            tempRoot->parent->leftchild = successorNode;
                            successorNode->parent = tempRoot->parent;
                            successorNode->rightchild = tempRoot->rightchild;
                            successorNode->leftchild = tempRoot->leftchild;
                            tempRoot->rightchild->parent = successorNode;
                            if(tempRoot->leftchild!=nullptr){
                                tempRoot->leftchild->parent = successorNode;
                            }

                        }

                    }

                }

            }
            delete tempRoot;
            tempRoot = nullptr;
            if(root==nullptr){
                cout<<"address of tempRoot"<<&tempRoot<<endl;
            }

            return true;
        }
    }
    return false;
}


int main(){
    TreeNode *root = nullptr;
    int input;
    int number;
    while(1){

        cout<<"Functions are listed below:"<<endl;
        cout<<"(1)新增節點"<<endl;
        cout<<"(2)刪除節點"<<endl;
        cout<<"(3)尋找節點"<<endl;
        cout<<"(4)Preorder Traversal 樹"<<endl;
        cout<<"(5)Inorder Traversal 樹"<<endl;
        cout<<"(6)Postorder Traversal 樹"<<endl;
        cout<<"(7)找尋節點的Successor"<<endl;
        cout<<"(8)離開"<<endl;
        cout<<"=============================="<<endl;
        cout<<"Please input a number of the function: ";
        cin>>input;
        switch(input){
        case 1:
            cout<<"請輸入要新增的節點的值(數字):";
            cin>>number;
            if(root==nullptr){
                root = new TreeNode;
                root->leftchild = nullptr;
                root->rightchild = nullptr;
                root->parent = nullptr;
                root->value = number;
            }else{
                TreeNode *newNode = new TreeNode;
                newNode->leftchild = nullptr;
                newNode->rightchild = nullptr;
                newNode->parent = nullptr;
                newNode->value = number;

                insertNode(root, newNode);

            }
            break;
        case 2:
            cout<<"請輸入要刪除的節點的值(數字):";
            cin>>number;
            bool result_of_delete;

            result_of_delete = deleteNode(&root, number);
            if(result_of_delete){
                cout<<"delete successful"<<endl;
                if(root==nullptr){
                    cout<<"hello"<<endl;
                }
            }else{
                cout<<"delete failed, something wrong!"<<endl;
            }
            break;
        case 3:
            cout<<"請輸入要尋找的節點的值(數字):";
            cin>>number;
            TreeNode* result_of_search ;
            result_of_search = searchNode(&root, number);
            if(result_of_search!=nullptr){
                cout<<"此樹有此數字"<<endl;
            }else{
                cout<<"此樹無此數字"<<endl;
            }
            break;
        case 4:
            cout<<"Preorder 結果如下:"<<endl;
            preorderTraversal(root);
            cout<<endl;
            break;
        case 5:
            cout<<"Inorder 結果如下:"<<endl;
            inorderTraversal(root);
            cout<<endl;
            break;
        case 6:
            cout<<"Postorder 結果如下:"<<endl;
            postorderTraversal(root);
            cout<<endl;
            break;
        case 7:
            cout<<"請輸入要尋找的節點的值(數字)的successor:";
            cin>>number;
            TreeNode* result_of_successor ;
            TreeNode* successorNode;
            result_of_successor = searchNode(&root, number);
            if(result_of_search!=nullptr){
                successorNode = successor(result_of_successor);
                if(successorNode!=nullptr){
                    cout<<"successor node is "<<successorNode->value<<endl;
                }else{
                    cout<<"此數字沒有successor"<<endl;
                }
            }else{
                cout<<"此樹無此數字,所以也沒有successor"<<endl;
            }
            break;
        case 8:
            cout<<"謝謝光臨"<<endl;
            break;
        default:
            cout<<"輸入錯誤的數字, 請重新輸入."<<endl;
            break;


        }

        if(input==8){
            break;
        }

    }




    return 0;
}

