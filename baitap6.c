#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct Students{
	int id;
	char fullName[50];
	int age;
	char phoneNumber[12];
};
void addStudents(struct Students s[], int *n){
	printf("\nNhap thong tin sinh vien muon them");
	printf("\nNhap ID: ");
	scanf("%d", &s[*n].id);
	fflush(stdin);
	printf("Ho ten: ");
	fgets(s[*n].fullName, 50, stdin);
	s[*n].fullName[strlen(s[*n].fullName) - 1] = '\0';
	printf("Nhap tuoi: ");
	scanf("%d", &s[*n].age);
	fflush(stdin);
	printf("Nhap so dien thoai: ");
	fgets(s[*n].phoneNumber, 12, stdin);
	s[*n].phoneNumber[strlen(s[*n].phoneNumber) - 1] = '\0';
	(*n)++;
}
int main(){
	int n = 5;
	struct Students s[50] ={
		{1, "Nguyen Van A", 18, "0901234567"},
        {2, "Nguyen Van B", 21, "0912345678"},
        {3, "Nguyen Van C", 22, "0923456789"},
        {4, "Nguyen Van D", 23, "0934567890"},
        {5, "Nguyen Van D", 24, "0945678901"}
	};
    printf("Thong tin sinh vien truoc khi them la\n");
    printf("-------------------\n");
    for(int i = 0; i < n; i++){
    	printf("ID: %d", s[i].id);
    	printf("\nHo ten: %s", s[i].fullName);
    	printf("\nTuoi: %d", s[i].age);
    	printf("\nSo dien thoai: %s", s[i].phoneNumber);
    	printf("\n-------------------\n");
	}
	addStudents(s, &n);
	printf("\nThong tin sinh vien sau khi them la\n");
    printf("-------------------\n");
    for(int i = 0; i < n; i++){
    	printf("ID: %d", s[i].id);
    	printf("\nHo ten: %s", s[i].fullName);
    	printf("\nTuoi: %d", s[i].age);
    	printf("\nSo dien thoai: %s", s[i].phoneNumber);
    	printf("\n-------------------\n");
	}
}

