#include<iostream>

using namespace std;

struct node {
    int data;
    node *next;
};

node *createNode(int value) {
    node *temp = new node;
    temp->next = NULL;
    temp->data = value;
    return temp;
}

void printList(node *l) {
    node *p = l;
    while(p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }
}

// node *addElement(node *p, int value) {
//     node *temp = createNode(value);
//     p->next = temp;
//     return temp;
// }

//thêm vào đầu
node *addHead(node *l, int value) {
    node *temp = createNode(value);
    if(l == NULL) {
        l = temp;
    } else {
        temp->next = l;
        l = temp;
    }
    return l;
}

//thêm vào cuối
node *addEnd(node *l, int value) {
    node *temp, *p;
    temp = createNode(value);
    if(l == NULL) {
        l = temp;
    } else {
        p = l;
        while(p->next != NULL) {
            p = p->next;
        }
        p->next = temp;
    }
    return l;
}

//thêm vào vị trí bất kì

node *addAt(node *l, int value, int positon) {
    if(positon == 0 || l == NULL) {
        l = addHead(l, value); //Nếu vị trí cần điền là 0 hoặc vị trí đầu là NULL thì thêm luôn vào đầu
    } else {
        //tìm vị trí cần chèn, dùng k để duyệt vị trí
        int k = 1;
        node *p = l;
        while(p != NULL && k != positon) {
            p = p->next;
            k++;
        }
        if(k != positon) {
            //Nếu duyệt hết ds mà chưa tìm thấy vị trí cần điền thì tự động điền vào cuối
            l = addHead(l, value);
            //Hoặc nếu không muốn điền vào cuối tìm comment dòng trên và bỏ comment dòng dưới
            cout << "Vị trí cần chèn vượt quá vị trí cuối";
        } else {
            node *temp = createNode(value);
            temp->next = p->next;
            p->next = temp;
        }
    }
    return l;
}

//xoá đầu

node *deleteHead(node *l) {
    if(l == NULL) {
        cout << "Có con cc gì đâu mà xoá";
    } else {
        l = l->next;
    }
    return l;
}

node *deleteEnd(node *l) {
    if(l == NULL || l->next == NULL) {
        return deleteHead(l);
    }
    node *p = l;
    while(p->next->next != NULL) {
        p = p->next;
    }
    p->next = NULL;
    return l;
}

node *deleteAt(node *l, int position) {
    if(position == 0 || l == NULL || l->next == NULL) {
        l = deleteHead(l);
    } else {
        int k = 1;
        node *p =l;
        while(p->next->next != NULL && k != position) {
            p= p->next;
            ++k;
        }
        if(k != position) {
            cout << "Làm đéo gì có vị trí này mà xoá";
        } else {
            p->next = p->next->next;
        }
    }
    return l;
}

int getVal(node *l, int index) {
    int k = 0;
    node *p = l;
    while(p->next == NULL && k != index) {
        ++k;
        p = p->next;
    }
    return p->data;
}

int search(node *l, int value) {
    int position = 0;
    for(node *p = l; p != NULL; p = p->next) {
        if(p->data == NULL) {
            return position;
        }
        ++position;
    }
    return -1;
}

//xoá các node có giá trị chỉ định

node *delByVal(node *l, int value) {
    int position = search(l, value);
    while(position != -1) {
        deleteAt(l, position);
        position = search(l, value);
    }
    return l;
}

node *init() {
    node *l;
    l = NULL;
    return l;
}

node *Input() {
    node *l = init();
    int n, value;
    do {
        cout << "Nhap so luong phan tu: ";
        cin >> n;
    } while(n <= 0);
    for(int i =0; i < n; i++) {
        cout << "Nhap gia tri can them vao: ";
        cin >> value;
        l = addEnd(l, value);
    }
    return l;
}

int main() {
    // cout << "Tao 1 danh sach lien ket\n";
    // node *l = Input();
    // printList(l);
    // addHead(l, 5);
    // printList(l);

    //THÍCH CÁI GÌ THÌ GỌI HÀM Ở ĐÂY
}
