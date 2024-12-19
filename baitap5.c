#include<stdio.h>
#include<string.h>
struct Students{
	int id;
	char fullName[50];
	int age;
	char phoneNumber[12];
};
void editStudents(struct Students s[], int id){
	int found = 0;;
	for(int i = 0; i < 5; i++){
		if(id == s[i].id){
			printf("Nhap ten: ");
			fgets(s[i].fullName, sizeof(s[i].fullName), stdin);
			s[i].fullName[strlen(s[i].fullName) - 1] = '\0';
			printf("Nhap tuoi: ");
			scanf("%d", &s[i].age);
			found = 1;
		}
	}
	if(found == 0){
		printf("\nID khong ton tai\n");
	}
	else{
		printf("\nThong tin sinh vien\n");
		printf("--------------------\n");
		for(int i = 0; i < 5; i++){
			printf("ID: %d", s[i].id);
			printf("\nHo ten: %s", s[i].fullName);
			printf("\nTuoi; %d", s[i].age);
			printf("\nSo dien thoai: %s", s[i].phoneNumber);
			printf("\n--------------------\n");
		}
	}
}
int main(){
	    struct Students s[5] = {
        {1, "Nguyen Van A", 18, "0901234567"},
        {2, "Nguyen Van B", 21, "0912345678"},
        {3, "Nguyen Van C", 22, "0923456789"},
        {4, "Nguyen Van D", 23, "0934567890"},
        {5, "Nguyen Van D", 24, "0945678901"}
    };
    int id;
    printf("Nhap ID muon sua: ");
    scanf("%d", &id);
    fflush(stdin);
    editStudents(s, id);
	return 0;
}

