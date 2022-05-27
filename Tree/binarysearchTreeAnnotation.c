/*

lƯU Ý: ĐOẠN CODE DƯỚI ĐÂY KHÔNG CHẠY ĐƯỢC CHO ĐẾN KHI COMMENT 2 HÀM BSTT ĐẦU TIÊN (TỪ DÒNG 23 ĐẾN 40)




*/


#include <stdio.h>
#include <stdlib.h>
//Code này theo slide 11. BST


//Tạo nút của bst
typedef struct node {
	int item;
	struct node* left;
	struct node* right;
}btnode;


//Hàm duyệt cây nhị phân tìm kiếm
void BSTT(btnode* curr) { //slide 21
	if (curr == NULL) //duyệt qua các node của cây nhị phân tìm kiếm theo thứ tự:
		return;
	printf("%d ", curr->item); //node cha (parent)
	BSTT(curr->left); // node con bên trái
	BSTT(curr->right); // node con bên phải
	// Thứ tự duyệt: cha -> trái -> phải (bắt đầu duyệt từ gốc -> node ngoài cùng bên trái, sau đó duyệt sang node bên phải)
}
//Duyệt tìm phần tử có giá trị bằng c trong cây nhị phân tìm kiếm
void BSTT(btnode* curr,int c) { //slide 22,23
	if (curr == NULL) //Nếu cây rỗng thì không tìm thấy
		return;
	if (curr->item == c){printf("Found! %d ", curr->item); return;} //Tìm thấy phần tử có giá trị bằng c thì in ra và dừng hàm
	if ( curr->item > c) //Duyệt node con bên trái nếu node cha có giá trị lớn hơn c
		BSTT(curr->left, c);
	else //Còn lại duyệt node con bên phải
		BSTT(curr->right, c);
}

void BSTT(btnode* curr,int c) { //slide 25
	if (curr == NULL) //Nếu cây rỗng thì không tìm thấy và in ra
		{printf("Not found!\n");
		return;}
	if (curr->item == c){printf("Found! %d ", curr->item); return;} //Tìm thấy phần tử có giá trị bằng c thì in ra và dừng hàm
	if ( curr->item > c) //Duyệt node con bên trái nếu node cha có giá trị lớn hơn c
		BSTT(curr->left, c);
	else //Còn lại duyệt node con bên phải
		BSTT(curr->right, c);
}

//hàm bstt2 xác định vị trí cần chèn vào cây nhị phân tìm kiếm
btnode* BSTT2(btnode* curr,int c) { //slide 31
	if (curr == NULL) //Nếu cây rỗng thì không tìm thấy và in ra
		{printf("Not found!\n");
		return;}
	if (curr->item == c){printf("Found! %d ", curr->item); return;} //Tìm thấy phần tử có giá trị bằng c thì in ra và dừng hàm
	if ( curr->item > c) //Duyệt node con bên trái nếu node cha có giá trị lớn hơn c
		if (curr->left == NULL) return curr; //Nếu node con bên trái rỗng thì trả về node cha
		else {return BSTT2(curr->left, c);} //Nếu node con bên trái không rỗng thì duyệt node con bên trái
	else //Duyệt node con bên phải nếu node cha có giá trị nhỏ hơn c
		if (curr->right == NULL) return curr; //Nếu node con bên phải rỗng thì trả về node cha
		else {return BSTT2(curr->right, c);} //Nếu node con bên phải không rỗng thì duyệt node con bên phải
}


//hàm chèn nút mới vào cây nhị phân tìm kiếm
void addnode(btnode *curr,int c){ // slide 32
		btnode node_cha = BSTT2(curr,c); //Tìm node cha cần chèn
		//Nếu node cha bằng null thì c đã tồn tại trong cây nhị phân tìm kiếm
		if (node_cha == NULL)
			{
				printf("\nNode %d đã có trong cây!\n",c);
				return;
			}
		



		btnode *node_moi = (btnode*)malloc(sizeof(btnode)); //Tạo node mới
		node_moi->item = c; //Gán giá trị cho node mới
		node_moi->left = NULL; //Khởi tạo node con bên trái
		node_moi->right = NULL; //Khởi tạo node con bên phải
		if (node_cha->item > c) //Nếu node cha có giá trị lớn hơn c thì chèn vào node con bên trái
			node_cha->left = node_moi;
		else //Còn lại chèn vào node con bên phải
			node_cha->right = node_moi;
}

//Hàm xóa nút tring cây nhị phân tìm kiếm
void delete(btnode *curr,int c){
	if (curr == NULL) //Nếu cây rỗng thì không tìm thấy và in ra
		{printf("Not found!\n");
		return;}
	if (curr->item == c){ //Nếu node có giá trị bằng c thì xóa nó
		if (curr->left == NULL && curr->right == NULL) //Nếu node có 2 con rỗng thì xóa nó
			{
				free(curr);
				return;
			}
		if (curr->left == NULL) //Nếu node có con bên trái rỗng thì chuyển con bên phải vào vị trí của node cha
			{
				curr = curr->right;
				free(curr);
				return;
			}
		if (curr->right == NULL) //Nếu node có con bên phải rỗng thì chuyển con bên trái vào vị trí của node cha
			{
				curr = curr->left;
				free(curr);
				return;
			}
		btnode *node_moi = curr->right; //Tạo node mới là con bên phải của node cần xóa
		while (node_moi->left != NULL) //Duyệt các node con bên trái của node con bên phải của node cần xóa cho đến khi node con bên trái của node cần xóa rỗng
			node_moi = node_moi->left;
		curr->item = node_moi->item; //Chuyển giá trị của node vừa duyệt vào node cần xóa, sau đó xóa node con bên phải của node cần xóa
		delete(curr->right,node_moi->item);


	}

//hàm in cây nhị phân tìm kiếm
void print(btnode *curr){
	if (curr == NULL) return; //Nếu cây rỗng thì không tìm thấy và in ra
	print(curr->left); //In cây con bên trái
	printf("%d ",curr->item); //In giá trị của node
	print(curr->right); //In cây con bên phải
}
int main()
{
//tạo cây nhị phân tìm kiếm
	btnode *root = NULL;
	addnode(root,10);
	addnode(root,5);
	addnode(root,15);
	addnode(root,2);
	addnode(root,7);
	addnode(root,12);
	addnode(root,17);
	addnode(root,13);
	addnode(root,18);
	addnode(root,20);
	addnode(root,25);
	addnode(root,30);
	addnode(root,35);
	//in cây nhị phân
	print(root);
	//duyệt tìm phần tử 13 trong cây nhị phân tìm kiếm
	btnode *node_13 = BSTT2(root,13);
	//xóa phần tử 13 trong cây nhị phân tìm kiếm
	delete(root,13);
	print(root);
}

