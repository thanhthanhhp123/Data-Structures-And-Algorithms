
   
#include<stdio.h>
#include<stdlib.h>

struct linkedList {
    int data;
    struct linkedList *next;
};

typedef struct linkedList *node; //thay thế kiểu dữ liệu linkedList bằng node

node Createnode(int value) {
    node temp; //declare a node
    temp = (node)malloc(sizeof(struct linkedList)); 
    temp->data = value;
    temp->next = NULL;
    return temp; 
}

node addHead(node l, int value) {
    node temp = Createnode(value);
    if(l == NULL) {
        l = temp;
    } else {
        temp->next = l;
        l = temp;
    }
    return temp;
}

node addEnd(node l, int value) {
    node temp, p;
    temp = Createnode(value);
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

node addAt(node l, int value, int position) {
    if(position == 0 || l == NULL) {
        return addHead(l, value);
    } else {
        int k = 1;
        node p = l;
        while(p != NULL && k != position) {
            p = p->next;
            ++k;
        }
        if(k != position) {
            printf("Làm gì có vị trí này");
        } else {
            node temp = Createnode(value);
            temp->next = p->next;
            p->next = temp;
        }
        return l;
    }
}

node deleteHead(node l) {
    if(l == NULL) {
        printf("Có cái gì đâu mà xoá");
    } else {
        l = l->next;
    }
    return l;
}

node deleteEnd(node l) {
    if(l == NULL) {
        l = deleteHead(l);
    }
    node p = l;
    while(p->next->next != NULL) {
        p = p->next;
    }
    p->next = NULL;
    return l;
}

node deleteAt(node l, int position) {
    if(position == 0 || l == NULL) {
        l = deleteHead(l);
    } else {
        int k=1;
        node p = l;
        while(p->next->next != NULL && k != position) {
            p = p ->next;
            ++k;
        }
        if(k!= position) {
            printf("Làm gì có vị trí này");
        } else {
            p->next = p->next->next;
        }
    }
    return l;
}

node getValue(node l, int index) {
    int k = 0;
    node  p = l;
    while(p->next == NULL && k != index) {
        ++k;
        p = p->next;
    }
    return p->data;
}

int search(node l, int value) {
    int position = 0;
    for(node p = l; p != NULL; p = p->next) {
        if(p->data == value) {
            return position;
        }
        position++;
    }
    return -1;
}

node delByVal(node l, int value) {
    int position = search(l, value);
    while(position != -1) {
        deleteAt(l, position);
        position = search(l, value);
    }
    return l;
}

node init() {
    node l;
    l = NULL;
    return l;
}

node Input() {
    node l = init();
    int n, value;
    printf("Nhập số lượng phần tử: ");
    scanf("%d", &n);
    for(int i =0; i < n; i++) {
        printf("Nhap gia tri can them: ");
        scanf("%d", &value);
        l = addEnd(l, value);
    }
    return l;
}

void printList(node l) {
    node p;
    p = l;
    while(p != NULL) {
        printf("%d ", p->data);
        p = p->next;
        continue;
    }
}

int main() {
    printf("Tao 1 danh sach lien ket\n");
    node l = Input();
    int position;
    printf("Nhập vị trí cần xoá: ");
    scanf("%d", &position);
    l = deleteAt(l, position);
    printList(l);
}
