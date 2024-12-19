#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct Students{
	char fullName[50];
	int age;
	char phoneNumber[12];
};
int main(){
	struct Students s;
	printf("Nhap ten: ");
	fgets(s.fullName, sizeof(s.fullName), stdin);
	s.fullName[strlen(s.fullName) - 1] = '\0';
	printf("Nhap tuoi: ");
	scanf("%d", &s.age);
	fflush(stdin);
	printf("Nhap so dien thoai: ");
	fgets(s.phoneNumber, sizeof(s.phoneNumber), stdin);
	printf("\nThong tin sinh vien");
	printf("\nHo ten: %s", s.fullName);
	printf("\nTuoi: %d", s.age);
	printf("\nSo dien thoai: %s", s.phoneNumber);
	return 0;
}
