#include<stdio.h>
#include<stdlib.h>

struct linkedList {
    int data;
    struct linkedList *next;
};

typedef struct linkedList *node; //thay thế kiểu dữ liệu linkedList bằng node

node Createnode(int value) {
    node temp; //declare a node
    temp = (node)malloc(sizeof(struct linkedList)); //cấp phát vùng nhớ 
    temp->next = NULL; //cho next trỏ tới NULL
    temp->data = value; //gán giá trị cho node
    return temp; //trả về node mới đã có giá trị
}

//thêm vào đầu
node addHead(node head, int value) {
    node temp = Createnode(value); //khởi tạo node temp với data = value
    if(head == NULL) {
        head = temp; //Nếu danh sách trống thì gán head = temp
    } else {
        temp->next = head; //trỏ next của temp là head
        head = temp; // đổi head hiện tại bằng temp
    }
    return head;
}

//thêm vào cuối

node addEnd(node head, int value) {
    node temp, p; //Khai báo 2 biến node tạm
    temp = Createnode(value);
    if(head == NULL) {
        head = temp;
    } else {
        p = head;
        while(p->next != NULL) {
            p = p->next;
        }
        p->next = temp;
    }
    return head;
}

//thêm vào vị trí bất kì

node addAt(node head, int value, int position) {
    if(position == 0 || head == NULL) {
        head = addHead(head, value);
    } else {
        //tìm vị trí cần chèn, dùng k để đếm vị trí
        int k = 1;
        node p = head;
        while(p != NULL && k != position) {
            p = p->next;
            ++k;
        }
        if(k != position) {
            //Nếu duyệt hết danh sách mà chưa đến vị trí cần chèn thì chèn vào vị trí cuối cùng
            head = addEnd(head, value);
            printf("Vị trí cần chèn vượt qua vị trí cuối cùng");
        } else {
            node temp = Createnode(value);
            temp->next = p->next;
            p->next = temp;
        }
    }
    return head;
}

//xoá đầu

node deleteHead(node head, int value) {
    if(head == NULL) {
        printf("\nCó cái nịt để xoá");
    } else {
        head = head->next;
    }
    return head;
}

node delete_Head(node head) {
    if(head == NULL) {
        printf("\nCó cái nịt để xoá");
    } else {
        head = head->next;
    }
    return head;
}
//xoá cuối

node deleteEnd(node head, int value) {
    if(head == NULL || head->next == NULL) {
        return deleteHead(head, value);
    }
    node p = head;
    while(p->next->next != NULL) {
        p = p->next;
    }
    p->next = NULL; //cho next = NULL
    return head;
}
node delete_End(node head) {
    if(head == NULL || head->next == NULL) {
        return delete_Head(head);
    }
    node p = head;
    while(p->next->next != NULL) {
        p = p->next;
    }
    p->next = NULL; //cho next = NULL
    return head;
}
//xoá ở vị trí bất kì

node deleteAt(node head, int position) {
    if(position == 0 || head == NULL || head->next == NULL) {
        head = delete_Head(head);
    } else {
        //tìm vị trí cần xoá. Dùng k để đếm
        int k = 1;
        node p = head;
        while(p->next->next != NULL && k != position) {
            p = p->next;
            ++k;
        }
        if(k!= position) {
            //Nếu duyệt hết danh sách mà chưa đến vị trí cần xoá thì mặc định xoá vị trí cuối
            head = delete_End(head);
            //Nếu không muốn xoá vị trí cuối cùng thì comment dòng trên và bỏ comment dòng duới
            printf("Làm đéo gì có vị trí này mà xoá");
        } else {
            p->next = p->next->next;
        }
    }
    return head;
}

int getValue(node head, int index) {
    int k = 0;
    node p = head;
    while(p->next == NULL && k != index) {
        ++k;
        p = p->next;
    }
    return p->data;
}

//hàm tìm kiếm trả về chỉ số của Node đầu tiên có giá trị bằng gía trị cần tìm
int search(node head, int value) {
    int position = 0; 
    for(node p = head; p != NULL; p = p->next) {
        if(p->data == NULL) {
            return position;
        }
        ++position;
    }
    return -1;
}

//Xoá các node có giá trị chỉ định

node delByVal(node head, int value) {
    int position = search(head, value);
    while(position != -1) {
        deleteAt(head, position);
        position = search(head, value);
    }
    return head;
}

//duyệt Linked list

void Traverser(node head) {
    for(node p = head; p != NULL; p = p->next) {
        printf("%3d", p->data);
    }
}
//Init Linked list
node initHead() {
    node head;
    head = NULL;
    return head;
}

//Nhập linked list

node Input() {
    node head = initHead();
    int n, value;
    do {
        printf("\nNhap so luong phan tu: ");
        scanf("%d", &n);
    } while(n <= 0);
    for(int i = 0;i < n; i++) {
        printf("Nhap gia tri can them vao list: ");
        scanf("%d", &value);
        head = addEnd(head, value);
    }
    return head;
}

int main(){
    printf("\n==Tao 1 danh sach lien ket==");
    node head = Input();
    Traverser(head);
 
    printf("\n==Thu them 1 phan tu vao linked list==");
    head = addAt(head, 100, 2);
    Traverser(head);
 
    printf("\n==Thu xoa 1 phan tu khoi linked list==");
    head = deleteAt(head, 1);
    Traverser(head);
 
    printf("\n==Thu tim kiem 1 phan tu trong linked list==");
    int index = search(head, 5);
    printf("\nTim thay tai chi so %d", index);
 
}