#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct Students{
	int id;
	char fullName[50];
	int age;
	char phoneNumber[12];
};
void deleteStudents(struct Students s[], int *n){
	char *name;
	int found = 0;
	name = (char *)calloc(50, sizeof(char));
	printf("Nhap ten: ");
	fgets(name, *n, stdin);
	name[strlen(name) - 1] = '\0';
	for(int i = 0; i < *n; i++){
		if(strstr(s[i].fullName, name) != NULL){
			found = 1;
			(*n)--;
			for(int j = i; j < *n; j++){
				s[j] = s[j+1];
			}
		}
	}
	if(found == 0){
		printf("\nTen sinh vien khong ton tai\n");
	}
	else{
		printf("\nThong tin sinh vien truoc sau xoa la\n");
	    printf("-------------------\n");
	    for(int i = 0; i < *n; i++){
	    	printf("ID: %d", s[i].id);
	    	printf("\nHo ten: %s", s[i].fullName);
	    	printf("\nTuoi: %d", s[i].age);
	    	printf("\nSo dien thoai: %s", s[i].phoneNumber);
	    	printf("\n-------------------\n");
		}
	}
	free(name);
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
    printf("Thong tin sinh vien truoc khi xoa la\n");
    printf("-------------------\n");
    for(int i = 0; i < n; i++){
    	printf("ID: %d", s[i].id);
    	printf("\nHo ten: %s", s[i].fullName);
    	printf("\nTuoi: %d", s[i].age);
    	printf("\nSo dien thoai: %s", s[i].phoneNumber);
    	printf("\n-------------------\n");
	}
	deleteStudents(s, &n);
	return 0;
}

