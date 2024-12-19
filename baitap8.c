#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Students {
    int id;
    char fullName[50];
    int age;
    char phoneNumber[15];
};
void addStudents(struct Students s[], int *n, int index){
	for(int i = (*n); i > index; i--){
		s[i] = s[i-1];
	}
	printf("Nhap ID: ");
	scanf("%d", &s[index].id);
	fflush(stdin);
	printf("Nhap ten: ");
	fgets(s[index].fullName, sizeof(s[index].fullName), stdin);
	s[index].fullName[strlen(s[index].fullName) - 1] = '\0';
	printf("Nhap tuoi: ");
	scanf("%d", &s[index].age);
	fflush(stdin);
	printf("Nhap so dien thoai: ");
	fgets(s[index].phoneNumber, sizeof(s[index].phoneNumber), stdin);
	s[index].phoneNumber[strlen(s[index].phoneNumber) - 1] ='\0';
	(*n)++;
}
int main(){
	struct Students s[50] = {
        {1, "Nguyen Van A", 18, "0901234567"},
        {2, "Nguyen Van B", 21, "0912345678"},
        {3, "Nguyen Van C", 22, "0923456789"},
        {4, "Nguyen Van D", 23, "0934567890"},
        {5, "Nguyen Van D", 24, "0945678901"}
    };
    int n = 5, index;
    printf("Thong tin sinh vien truoc khi them la\n");
    printf("--------------------\n");
    for(int i = 0; i < n; i++){
    	printf("ID: %d", s[i].id);
    	printf("\nHo ten: %s", s[i].fullName);
    	printf("\nTuoi: %d", s[i].age);
    	printf("\nSo dien thoai: %s", s[i].phoneNumber);
    	printf("\n--------------------\n");
	}
    printf("\nNhap vi tri muon chen (0 -> %d): ", n);
    scanf("%d", &index);
    if(index < 0 || index > 5){
    	printf("\nVi tri chen khong hop le\n");
	}
	else{
		addStudents(s, &n, index);
		printf("Thong tin sinh vien sau khi them la\n");
    	printf("--------------------\n");
    	for(int i = 0; i < n; i++){
	    	printf("ID: %d", s[i].id);
	    	printf("\nHo ten: %s", s[i].fullName);
	    	printf("\nTuoi: %d", s[i].age);
	    	printf("\nSo dien thoai: %s", s[i].phoneNumber);
	    	printf("\n--------------------\n");
		}
	}
    return 0;
}

