#include<iostream>
using namespace std;
struct Node{
    int key;
    Node *left;
    Node *right;
};
struct Tree{
    Node* root;
};
void create_tree(Tree *t){
    t->root = NULL;
}
Node* create_node(int x){
    Node* data = new Node;
    if(data == NULL) return NULL;
    data->key = x;
    data->left = data->right =NULL;
    return data;
}
// Thêm nút vào BST
bool addNode(Node* &root, int x){
    if (root != NULL){
        if(root->key == x) return false;
        if(root->key < x) return addNode(root->right, x);
        else return addNode(root->left, x);
    }
    else {
        root = create_node(x);
        return true;
    }
}
// Duyệt cây
void NLR(Node* root){
    if(root != NULL){
        cout << root->key << " ";
        NLR(root->left);
        NLR(root->right);
    }
}
void LNR(Node* root){
    if(root != NULL){
        LNR(root->left);
        cout << root->key;
        LNR(root->right);
    }
}
// Tìm kiếm giá trị thỏa mãn
Node* search(Tree* t, int x){
    Node* tim = t->root;
    while(tim != NULL){
        if(tim->key == x) return tim;
        if(tim->key <  x) tim = tim->right;
        else tim = tim->left;
    }
    return NULL;
}
int main(){
    int a[]= {2001, 2002, 2006, 2007, 2003, 2004, 2005, 2001, 1999, 2004};
    Tree* t = new Tree;
    create_tree(t);
    for(int i = 0; i < 10; i++){
        addNode(t->root, a[i]);
    }
    Node* result = search(t, 2005);
    if(result != NULL) {
        cout << "Da tim thay: " << result->key << endl;
    } else {
        cout << "Khong tim thay!" << endl;
    }
    delete t;
}