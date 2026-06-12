#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
    int height;
};

// Hàm lấy chiều cao
int LayChieuCao(Node *p) {
    if (p == NULL) return 0;
    return p->height;
}

// Tạo node mới
Node* taoNode(int x) {
    Node *p = new Node();
    p->data = x;
    p->left = NULL;
    p->right = NULL;
    p->height = 1; // node lá chieu cao bang 1
    return p;
}

// xoay phai
Node* xoayPhai(Node *y) {
    Node *x = y->left;
    Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    // Tu tinh max chu khong xai thu vien
    int h_yl = LayChieuCao(y->left);
    int h_yr = LayChieuCao(y->right);
    y->height = (h_yl > h_yr ? h_yl : h_yr) + 1;

    int h_xl = LayChieuCao(x->left);
    int h_xr = LayChieuCao(x->right);
    x->height = (h_xl > h_xr ? h_xl : h_xr) + 1;

    return x;
}

// xoay trai
Node* xoayTrai(Node *x) {
    Node *y = x->right;
    Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    int h_xl = LayChieuCao(x->left);
    int h_xr = LayChieuCao(x->right);
    x->height = (h_xl > h_xr ? h_xl : h_xr) + 1;

    int h_yl = LayChieuCao(y->left);
    int h_yr = LayChieuCao(y->right);
    y->height = (h_yl > h_yr ? h_yl : h_yr) + 1;

    return y;
}

// Ham them phan tu vao cay
Node* themNode(Node *root, int x) {
    // Neu cay rong thi tao node
    if (root == NULL) return taoNode(x);

    // Chen nhu cay nhi phan tim kiem binh thuong
    if (x < root->data)
        root->left = themNode(root->left, x);
    else if (x > root->data)
        root->right = themNode(root->right, x);
    else 
        return root; // ko cho them gia tri trung nhau

    // Cap nhat chieu cao cua node hien tai
    int hl = LayChieuCao(root->left);
    int hr = LayChieuCao(root->right);
    root->height = (hl > hr ? hl : hr) + 1;

    // Tinh do lech de xem co can bang khong
    int lech = hl - hr;

    // Truong hop Lech Trai - Trai
    if (lech > 1 && x < root->left->data)
        return xoayPhai(root);

    // Truong hop Lech Phai - Phai
    if (lech < -1 && x > root->right->data)
        return xoayTrai(root);

    // Truong hop Lech Trai - Phai
    if (lech > 1 && x > root->left->data) {
        root->left = xoayTrai(root->left);
        return xoayPhai(root);
    }

    // Truong hop Lech Phai - Trai
    if (lech < -1 && x < root->right->data) {
        root->right = xoayPhai(root->right);
        return xoayTrai(root);
    }

    return root;
}

// Duyet LNR de in ra cac phan tu
void inOrder(Node *root) {
    if (root != NULL) {
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
}

int main() {
    Node *root = NULL;
    
    int a[] = {32, 51, 27, 83, 96, 11, 45, 75, 66};
    int n = 9; // Sinh vien khai bao cung so luong luon
    
    for (int i = 0; i < n; i++) {
        root = themNode(root, a[i]);
    }
    
    cout << "Cac phan tu tren cay AVL la: " << endl;
    inOrder(root);
    cout << endl;
    
    return 0;
}