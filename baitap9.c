#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct Dish{
	int id;
	char name[50];
	float price;
};
void printMenu(struct Dish menu[], int *size){
	printf("\nDanh sach mon an\n\n");
	for(int i = 0; i < *size; i++){
		printf("%d, %s, %.3f", menu[i].id, menu[i].name, menu[i].price);
		printf("\n\n");
	}
}
void addMenu(struct Dish menu[], int *size){
	int index;
	printf("\nNhap vi tri muon them ( 0 -> %d): ", *size);
	scanf("%d", &index);
	if(index < 0 || index > *size){
		printf("\nVi tri them khong hop le\n\n");
	}
	else{
		for(int i = *size; i > index; i--){
			menu[i] = menu[i-1];
		}
		printf("\nNhap ID: ");
		scanf("%d", &menu[index].id);
		fflush(stdin);
		printf("\nNhap ten mon an: ");
		fgets(menu[index].name, 50, stdin);
		menu[index].name[strlen(menu[index].name) - 1] = '\0';
		printf("\nNhap gia: ");
		scanf("%f", &menu[index].price);
		printf("\nThem thanh cong\n\n");
		(*size)++;
	}
}
void editMenu(struct Dish menu[], int *size){
	int index;
	printf("\nNhap vi tri muon sua: ");
	scanf("%d", &index);
	if(index < 0 || index > *size){
		printf("\nVi tri sua khong hop le\n\n");
	}
	else{
		printf("\nNhap thong tin muon sua\n\n");
		printf("Nhap ID: ");
		scanf("%d", &menu[index].id);
		fflush(stdin);
		printf("\nNhap ten mon an: ");
		fgets(menu[index].name, 50, stdin);
		menu[index].name[strlen(menu[index].name) - 1] = '\0';
		printf("\nNhap gia: ");
		scanf("%f", &menu[index].price);
		printf("\nSua thanh cong\n\n");
	}
}
void deleteMenu(struct Dish menu[], int *size){
	int index; 
	printf("\nNhap vi tri muon xoa (0 -> %d): ", (*size) - 1);
	scanf("%d", &index);
	if(index < 0 || index > *size){
		printf("\nVi tri xoa khong hop le\n\n");
	}
	else{
		for(int i = index; i < *size; i++){
			menu[i] = menu[i+1];
		}
		(*size)--;
		printf("\nXoa thanh cong\n\n");
	}
}
void sortByPrice(struct Dish menu[], int *size){
	char sortPrice;
	printf("\na. Giam dan theo price\n");
	printf("\nb. Tang gian theo price\n\n");
	fflush(stdin);
	scanf("%c", &sortPrice);
	if(sortPrice == 'a'){
		for(int i = 0; i < (*size); i++){
			int index = i;
			for(int j = i; j < *size; j++){
				if(menu[index].price > menu[j].price){
					index = j;
				}
			}
			struct Dish temp = menu[i];
			menu[i] = menu[index];
			menu[index] = temp;
		}
		printf("\nSap xep hoan tat\n\n");
	}
	else if(sortPrice == 'b'){
		for(int i = 0; i < (*size); i++){
			int index = i;
			for(int j = i; j < *size; j++){
				if(menu[index].price < menu[j].price){
					index = j;
				}
			}
			struct Dish temp = menu[i];
			menu[i] = menu[index];
			menu[index] = temp;
		}
		printf("\nSap xep hoan tat\n\n");
	}
}
void searchByName(struct Dish menu[], int *size){
	char *name, searchName;
	name = (char *)calloc(50, sizeof(char));
	printf("\na. Tim kiem tuyen tinh\n");
	printf("\nb. Tim kiem nhi phan\n\n");
	fflush(stdin);
	scanf("%c", &searchName);
	printf("\nNhap ten mon an: ");
	fflush(stdin);
	fgets(name, 50, stdin);
	name[strlen(name) - 1] = '\0';
	if(searchName == 'a'){
		for(int i = 0; i < (*size); i++){
			if(strstr(menu[i].name, name) != NULL){
				printf("\nID: %d", menu[i].id);
				printf("\nTen mon an: %s", menu[i].name);
				printf("\nGia tien: %.3f", menu[i].price);
				printf("\n\n");
			}
		}
	}
}
int main(){
	struct Dish menu[100] = {
		{1, "Mi tom", 18},
    	{2, "Banh mi", 20},
    	{3, "Com", 22},
    	{4, "Bit tet", 23},
    	{5, "Nem", 24}	
	};
	int choice, size = 5;
	do{
		printf("1. In ra mon an\n");
		printf("2. Them 1 phan tu vao vi tri co dinh\n");
		printf("3. Sua mot phan tu o vi tri co dinh\n");
		printf("4. Xoa mot phan tu o vi tri co dinh\n");
		printf("5. Sap xep cac phan tu\n");
		printf("6. Tim kiem phan tu theo ten\n");
		printf("7. Thoat\n");
		printf("Nhap chuc nang: ");
		scanf("%d", &choice);
		switch(choice){
			case 1:
				printMenu(menu, &size);
				break;
			case 2:
				addMenu(menu, &size);
				break;
			case 3:
				editMenu(menu, &size);
				break;
			case 4:
				deleteMenu(menu, &size);
				break;
			case 5:
				sortByPrice(menu, &size);
				break;
			case 6:
				searchByName(menu, &size);
				break;
			case 7:
				printf("\nThoat thanh cong\n");
				break;
			default:
				printf("\nChuc nang khong ton tai\n\n");
				break;
		}
	}
	while(choice != 7);
	return 0;
}

