#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct Students{
	char fullName[50];
	int age;
	char phoneNumber[12];
};
int main(){
	struct Students s[5];
	for(int i = 0; i < 5; i++){
		printf("Nhap thong tin sinh vien %d\n", i + 1);
		printf("Nhap ten: ");
		fgets(s[i].fullName, sizeof(s[i].fullName), stdin);
		s[i].fullName[strlen(s[i].fullName) - 1] = '\0';
		printf("Nhap tuoi: ");
		scanf("%d", &s[i].age);
		fflush(stdin);
		printf("Nhap so dien thoai: ");
		fgets(s[i].phoneNumber, sizeof(s[i].fullName), stdin);
		s[i].phoneNumber[strlen(s[i].phoneNumber) - 1] = '\0';
		printf("\n");
	}
	printf("Thong tin sinh vien\n");
	printf("--------------------\n");
	for(int i = 0; i < 5; i++){
		printf("Ho ten: %s", s[i].fullName);
		printf("\nTuoi: %d", s[i].age);
		printf("\nSo dien thoai: %s", s[i].phoneNumber);
		printf("\n--------------------\n");
	}
	return 0;
}
