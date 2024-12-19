#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct Students{
	int id;
	char fullName[50];
	int age;
	char phoneNumber[12];
};
int main(){
	struct Students s[5];
	for(int i = 0; i < 5; i++){
		printf("Nhap thong tin sinh vien %d", i + 1);
		s[i].id = i + 1;
		printf("\nNhap ten: ");
		fgets(s[i].fullName, sizeof(s[i].fullName), stdin);
		s[i].fullName[strlen(s[i].fullName) - 1] = '\0';
		printf("Nhap tuoi: ");
		scanf("%d", &s[i].age);
		fflush(stdin);
		printf("Nhap so dien thoai: ");
		fgets(s[i].phoneNumber, sizeof(s[i].phoneNumber), stdin);
		s[i].phoneNumber[strlen(s[i].phoneNumber) - 1] = '\0';
		printf("\n");
	}
	printf("Thong tin sinh vien");
	printf("\n--------------------\n");
	for(int i = 0; i < 5; i++){
		printf("ID: %d", s[i].id);
		printf("\nHo ten: %s", s[i].fullName);
		printf("\nTuoi: %d", s[i].age);
		printf("\nSo dien thoai: %s", s[i].phoneNumber);
		printf("\n--------------------\n");
	}
	return 0;
}

