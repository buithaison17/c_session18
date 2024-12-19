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
	strcpy(s.fullName, "Son Bui");
	s.age = 18;
	strcpy(s.phoneNumber, "032");
	printf("Thong tin sinh vien\n");
	printf("Ho ten: %s", s.fullName);;
	printf("\nTuoi: %d", s.age);
	printf("\nSo dien thoai: %s", s.phoneNumber);
	return 0;
}

