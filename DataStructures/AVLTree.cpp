#include<iostream>

using namespace std;

class TreeNode{
public:
    TreeNode *leftchild;
    TreeNode *rightchild;
    TreeNode *parent;
    int value;
    int Lheight;
    int Rheight;
};

int max(int a, int b){
    if(a>=b){
        return a;
    }else{
        return b;
    }

}

void LL_rotation(TreeNode **target){

    TreeNode *temp = (*target)->leftchild;
    (*target)->leftchild = temp->rightchild;
    temp->rightchild = (*target);
    if((*target)->parent==nullptr){
        temp->parent = (*target)->parent;
    }else{
        temp->parent = (*target)->parent;
        if((*target)->parent->leftchild == (*target)){
            (*target)->parent->leftchild = temp;
        }else{
            (*target)->parent->rightchild = temp;
        }

    }

    (*target)->parent = temp;

    if((*target)->leftchild!=nullptr){
        (*target)->Lheight = max((*target)->leftchild->Lheight, (*target)->leftchild->Rheight)+1;
    }else{
        (*target)->Lheight = 0;
    }
    if(temp->rightchild!=nullptr){
        temp->Rheight = max(temp->rightchild->Lheight, temp->rightchild->Rheight)+1;
    }else{
        temp->Rheight = 0;
    }
    (*target) = temp;
}


void LR_rotation(TreeNode **target){
    TreeNode *temp = (*target)->leftchild;
    TreeNode *tempChild = temp->rightchild;

    temp->rightchild = tempChild->leftchild;
    (*target)->leftchild = tempChild->rightchild;

    tempChild->leftchild = temp;
    tempChild->rightchild = (*target);

    if((*target)->parent==nullptr){
        tempChild->parent = (*target)->parent;
    }else{
        tempChild->parent = (*target)->parent;
        if((*target)->parent->leftchild == (*target)){
            (*target)->parent->leftchild = tempChild;
        }else{
            (*target)->parent->rightchild = tempChild;
        }
    }

    temp->parent = tempChild;
    (*target)->parent = tempChild;

    if((*target)->leftchild!=nullptr){
        (*target)->Lheight = max((*target)->leftchild->Lheight, (*target)->leftchild->Rheight)+1;
    }else{
        (*target)->Lheight = 0;
    }
    if(temp->rightchild!=nullptr){
        temp->Rheight = max(temp->rightchild->Lheight, temp->rightchild->Rheight)+1;
    }else{
        temp->Rheight = 0;
    }
    tempChild->Rheight = max(tempChild->rightchild->Lheight, tempChild->rightchild->Rheight)+1;
    tempChild->Lheight = max(tempChild->leftchild->Lheight, tempChild->leftchild->Rheight)+1;

    (*target) = tempChild;
}

void RR_rotation(TreeNode **target){
    TreeNode *temp = (*target)->rightchild;
    (*target)->rightchild = temp->leftchild;
    temp->leftchild = (*target);
    if((*target)->parent==nullptr){
        temp->parent = (*target)->parent;
    }else{
        temp->parent = (*target)->parent;
        if((*target)->parent->leftchild == (*target)){
            (*target)->parent->leftchild = temp;
        }else{
            (*target)->parent->rightchild = temp;
        }
    }

    (*target)->parent = temp;

    if((*target)->rightchild!=nullptr){
        (*target)->Rheight = max((*target)->rightchild->Lheight, (*target)->rightchild->Rheight)+1;
    }else{
        (*target)->Rheight = 0;
    }
    if(temp->leftchild!=nullptr){
        temp->Lheight = max(temp->leftchild->Lheight, temp->leftchild->Rheight)+1;
    }else{
        temp->Rheight = 0;
    }
    (*target) = temp;
}

void RL_rotation(TreeNode **target){
    TreeNode *temp = (*target)->rightchild;
    TreeNode *tempChild = temp->leftchild;

    temp->leftchild = tempChild->rightchild;
    (*target)->rightchild = tempChild->leftchild;

    tempChild->rightchild = temp;
    tempChild->leftchild = (*target);

    if((*target)->parent==nullptr){
        tempChild->parent = (*target)->parent;
    }else{
        tempChild->parent = (*target)->parent;
        if((*target)->parent->leftchild == (*target)){
            (*target)->parent->leftchild = tempChild;
        }else{
            (*target)->parent->rightchild = tempChild;
        }
    }

    temp->parent = tempChild;
    (*target)->parent = tempChild;

    if((*target)->rightchild!=nullptr){
        (*target)->Rheight = max((*target)->rightchild->Lheight, (*target)->rightchild->Rheight)+1;
    }else{
        (*target)->Rheight = 0;
    }
    if(temp->leftchild!=nullptr){
        temp->Lheight = max(temp->leftchild->Lheight, temp->leftchild->Rheight)+1;
    }else{
        temp->Lheight = 0;
    }
    tempChild->Rheight = max(tempChild->rightchild->Lheight, tempChild->rightchild->Rheight)+1;
    tempChild->Lheight = max(tempChild->leftchild->Lheight, tempChild->leftchild->Rheight)+1;

    (*target) = tempChild;
}


bool insertNode(TreeNode **root, TreeNode *newNode){
    if((*root)==nullptr || (*root)==0){
        return false;
    }

    // 尋找新增的位置
    TreeNode *tempRoot = (*root);
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

    // 由下往上調整
    tempRoot = newNode;
    while(tempRoot->parent!=nullptr){
        if(tempRoot == tempRoot->parent->leftchild){
            tempRoot = tempRoot->parent;
            tempRoot->Lheight = max(tempRoot->leftchild->Lheight, tempRoot->leftchild->Rheight)+1;
            // 檢查是否需要rotation
            if(tempRoot->Lheight - tempRoot->Rheight > 1){
                if(tempRoot->leftchild->Lheight - tempRoot->leftchild->Rheight == 1){
                    //做LL Rotation
                    LL_rotation(&tempRoot);

                }else{
                    //做 LR Rotation
                    LR_rotation(&tempRoot);

                }
            }

        }else{
            tempRoot = tempRoot->parent;
            tempRoot->Rheight = max(tempRoot->rightchild->Lheight, tempRoot->rightchild->Rheight)+1;
            // 檢查是否需要rotation
            if(tempRoot->Lheight - tempRoot->Rheight < -1){
                if(tempRoot->rightchild->Lheight - tempRoot->rightchild->Rheight == 1){
                    // 做RL rotation
                    RL_rotation(&tempRoot);
                }else{
                    // 做RR rotation
                    RR_rotation(&tempRoot);
                }
            }


        }
    }
    // 因為有可能動到root 所以置換一下確保
    (*root) = tempRoot;


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
        cout<<root->value<<"("<<max(root->Lheight,root->Rheight)<<"), ";
        inorderTraversal(root->rightchild);
    }

}

void preorderTraversal(TreeNode *root){

    if(root==nullptr){
            return;
    }
    else
    {
        cout<<root->value<<"("<<max(root->Lheight,root->Rheight)<<"), ";
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
        cout<<root->value<<"("<<max(root->Lheight,root->Rheight)<<"), ";
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
        }else if(tempRoot->value == value){
            // 找到要刪除的點
            TreeNode *target;
            TreeNode *successorNode = successor(tempRoot);
            if(successorNode==nullptr){
                    // 處理case 1， 要刪除的點沒有右子樹，所以直接左子樹往上
                if(tempRoot->parent!=nullptr){
                    if(tempRoot == tempRoot->parent->rightchild){
                        tempRoot->parent->rightchild = tempRoot->leftchild;
                        tempRoot->parent->Rheight = tempRoot->parent->Rheight -1;
                        target = tempRoot->parent;
                    }else{
                        tempRoot->parent->leftchild = tempRoot->leftchild;
                        tempRoot->parent->Lheight = tempRoot->parent->Lheight -1;
                        target = tempRoot->parent;
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
                        successorNode->Lheight = (*root)->Lheight;
                        (*root) = successorNode;
                        (*root)->parent = nullptr;
                         target = (*root);
                    }else{
                        if(tempRoot == tempRoot->parent->rightchild){
                            tempRoot->parent->rightchild = successorNode;
                            successorNode->parent = tempRoot->parent;
                            successorNode->leftchild = tempRoot->leftchild;
                            if(tempRoot->leftchild!=nullptr){
                                tempRoot->leftchild->parent = successorNode;
                            }else{
                                //do nothing
                            }
                            successorNode->Lheight = tempRoot->Lheight;
                            target = successorNode;
                        }else{
                            tempRoot->parent->leftchild = successorNode;
                            successorNode->parent = tempRoot->parent;
                            successorNode->leftchild = tempRoot->leftchild;
                            if(tempRoot->leftchild!=nullptr){
                                tempRoot->leftchild->parent = successorNode;
                            }else{
                                //do nothing
                            }
                            successorNode->Lheight = tempRoot->Lheight;
                            target = successorNode;
                        }
                    }
                }else{
                    // 處理 case 3，要刪除的點有比較遠的successor，把successor 取代要刪除的點，successor 的父親的左兒子指向successor 的右兒子
                    // successor 的左右兒子改為指向要被刪除的點的左右兒子
                    successorNode->parent->leftchild = successorNode->rightchild;
                    target = successorNode->parent;
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

            //由下往上調整rotation
            while(target!=nullptr){
                    // 先計算高度
                if(target->rightchild==nullptr){
                    target->Rheight = 0;
                }else{
                    target->Rheight = max(target->rightchild->Lheight, target->rightchild->Rheight)+1;
                }

                if(target->leftchild==nullptr){
                    target->Lheight = 0;
                }else{
                    target->Lheight = max(target->leftchild->Lheight, target->leftchild->Rheight)+1;
                }

                if(target->Lheight - target->Rheight > 1 ){
                    if(target->leftchild->Lheight - target->leftchild->Rheight == 1){
                        LL_rotation(&target);
                    }else{
                        LR_rotation(&target);
                    }

                }else if(target->Lheight - target->Rheight < -1){
                    if(target->rightchild->Lheight - target->rightchild->Rheight == 1){
                        RL_rotation(&target);
                    }else{
                        RR_rotation(&target);
                    }

                }
                (*root) = target;
                target = target->parent;

            }
    //end of 由下往上調整rotation


            delete tempRoot;
            tempRoot = nullptr;
            if(root==nullptr){
                cout<<"address of tempRoot"<<&tempRoot<<endl;
            }

            return true;
        }else{
            return false;
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
                root->Rheight = 0;
                root->Lheight = 0;
            }else{
                TreeNode *newNode = new TreeNode;
                newNode->leftchild = nullptr;
                newNode->rightchild = nullptr;
                newNode->parent = nullptr;
                newNode->value = number;
                newNode->Rheight = 0;
                newNode->Lheight = 0;

                insertNode(&root, newNode);

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

