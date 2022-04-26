#include<stdio.h>

int queue[100], n = 100, front = -1, rear = -1;

//Thêm vào cuối
void push() {
    int val;
    if(rear == n - 1) {
        printf("Tràn hàng đợi");
    } else {
        if(front == -1) {
            front = 0;
            printf("Chèn phần tử vào hàng đợi: \n");
            scanf("%d", &val);
            rear++;
            queue[rear] = val;
        }
    }
}

//Xoá đầu
void pop() {
    
    if(front == -1 || front > rear) {
        printf("Làm gì có cái gì để mà xoá");
        return;
    } else {
        printf("Phần tử đã xoá khỏi hàng đợi");
        front++;
    }
}

void print() {
    if(front == -1) {
        printf("Hàng đợi rỗng\n");
    } else {
        printf("Các phần tử có trong hàng đợi là: ");
        for(int i = front; i <=rear; i++) {
            printf("%d ", queue[i]);
        }
    }
}

int main() {
    int x;
    printf("1. Thêm vào Queue\n");
    printf("2. Xoá phần tử khỏi Queue\n");
    printf("3. Hiển thị tất cả phần tử của Queue");
    printf("4. Thoát\n");
    do {
        printf("Nhập lựa chọn: ");
        scanf("%d", &x);
        switch(x) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                print();
            case 4:
                printf("Thoát");
                break;
            default:
                printf("Không có cái này thằng mù chữ ạ");
        }
    }while(x != 4);
    return 0;
}