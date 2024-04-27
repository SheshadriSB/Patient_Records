#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>

void gotoxy(int ,int );
void menu();
void add();
void view();
void search();
void modify();
void delrec();

struct patients{
	char full_name[50];
	char contact[15];
	char cause[30];
	int age;
	int cabin;
	char address[50];
	char gender;
	char admit_date[15];

}p;

int main()
{
    gotoxy(15,8);
    printf("<--:Patients Record Management System:-->");
    gotoxy(10,10);
    printf("A C Project By:\n");
    gotoxy(12,12);
    printf("Aayush Poudel\t\t");
    gotoxy(12,14);
    printf("Sheshadri S. Bandyopadhyay\t\t");
    gotoxy(12,16);
    printf("Yogesh Ghale\t\t");
    gotoxy(12,18);
    printf("Wanchhit Acharya\t\t");
    gotoxy(19,21);
    printf("Press any key to continue.");
    getch();
    menu();
    return 0;
}

void menu()
{
    int choice;
    system("cls");
    gotoxy(10,3);
    printf("<--:MENU:-->");
    gotoxy(10,5);
    printf("Enter appropriate number to perform following task.");
    gotoxy(10,7);
    printf("1 : Add Record.");
    gotoxy(10,8);
    printf("2 : View Record.");
    gotoxy(10,9);
    printf("3 : Search Record.");
    gotoxy(10,10);
    printf("4 : Modify Record.");
    gotoxy(10,11);
    printf("5 : Delete.");
    gotoxy(10,12);
    printf("6 : Exit.");
    gotoxy(10,15);
    printf("Enter your choice.");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
        add();
        break;
    case 2:
        view();
        break;
    case 3:
        search();
        break;
    case 4:
        modify();
        break;
    case 5:
        delrec();
        break;
    case 6:
        exit(1);
        break;
    default:
        gotoxy(10,17);
        printf("Invalid Choice.");
    }
}


void add(){
    FILE *fp;
    char ch='y';
    system("cls");
    fp=fopen("patientrecords.txt","a+");
        if(fp == NULL){
        gotoxy(10,5);
        printf("Error opening file");
        exit(1);
    }
    fflush(stdin);
    while(ch=='y')
    {
        gotoxy(10,2);
        printf("<--:ADD RECORD:-->");
        gotoxy(10,4);
        printf("Enter details of patient.");
        gotoxy(10,6);
        printf("Enter Full Name: ");
        gets(p.full_name);
        gotoxy(10,8);
        printf("Enter Age: ");
        scanf("%d",&p.age);
        gotoxy(10,10);
        printf("Enter Gender(M/F/O): ");
        scanf(" %c",&p.gender);
        gotoxy(10,12);
        printf("Enter Contact: ");
        fflush(stdin);
		gets(p.contact);
        gotoxy(10,14);
        printf("Enter Address: ");
        fflush(stdin);
		gets(p.address);
        gotoxy(10,16);
        printf("Enter Cabin Num: ");
        scanf("%d",&p.cabin);
        gotoxy(10,18);
        printf("Enter Cause of Admission: ");
        fflush(stdin);
		gets(p.cause);
        gotoxy(10,20);
        printf("Enter Admission Date AD(YYYY/MM/DD): ");
        fflush(stdin);
		gets(p.admit_date);
        fwrite(&p,sizeof(p),1,fp);
        gotoxy(10,22);
        printf("Want to add another record?(Y/N): ");
        ch=getch();
        system("cls");
        fflush(stdin);
    }
    fclose(fp);
    gotoxy(10,18);
    printf("Press any key to continue.");
    getch();
    menu();
}


void view(){
   FILE *fp;
   int i=1,j=9;
   system("cls");
   gotoxy(10,2);
   printf("<--:VIEW RECORD:-->");
   gotoxy(10,5);
   printf("S.N   Name                Age  Gender   Contact         Address          Cabin    Admission Cause     Admit Date");
   gotoxy(10,7);
   printf("-----------------------------------------------------------------------------------------------------------------");
   fp = fopen("patientrecords.txt","r+");
   if(fp == NULL){
        gotoxy(10,9);
        printf("Error opening file.");
        exit(1);
    }
   
    while(fread(&p,sizeof(p),1,fp) == 1){
        gotoxy(10,j);
		printf("%-7d%-20s%-5d%-8c%-16s%-18s%-8d%-20s%-10s",i,p.full_name,p.age,p.gender,p.contact,p.address,p.cabin,p.cause,p.admit_date);
        i++;
        j+=2;

}
	fclose(fp);
    gotoxy(10,j+3);
    printf("Press any key to continue.");
    getch();
    menu();	
}


void search(){
    FILE *fp;
    char ptname[20];
    int ptcabin,ch,count=0;
    system("cls");
    gotoxy(10,3);
    printf("<--:SEARCH RECORD:-->");
    gotoxy(10,5);
    printf("By what do you want to search ? ");
    gotoxy(10,7);
    printf("1.Name");
    gotoxy(10,9);
    printf("2.Cabin Num");
    gotoxy(10,11);
    printf("Enter appropriate choice: ");
    scanf("%d",&ch);
	if(ch==1){
	count=0;
	system("cls");
	gotoxy(10,3);
	printf("Enter patient Name to Search: ");
    fflush(stdin);
    gets(ptname);
    fp = fopen("patientrecords.txt","r+");
    if(fp == NULL){
        gotoxy(10,6);
        printf("Error opening file");
        exit(1);
    }
    while(fread(&p,sizeof(p),1,fp ) == 1){
        if(strcmp(ptname,p.full_name) == 0){
			count++;
            gotoxy(10,8);
            printf("Name : %s",p.full_name);
            gotoxy(10,10);
            printf("Age : %d",p.age);
            gotoxy(10,12);
            printf("Gender : %c",p.gender);
            gotoxy(10,14);
            printf("Address: %s",p.address);
            gotoxy(10,16);
            printf("Contact: %s",p.contact);
            gotoxy(10,18);
            printf("Cabin Num: %d",p.cabin);
            gotoxy(10,20);
            printf("Cause of Admission: %s",p.cause);
            gotoxy(10,22);
            printf("Admission Date: %s",p.admit_date);
        }
    }
       fclose(fp);
        if(count==0){
        	gotoxy(10,5);
        	printf("Not found");
		}
        

    
}

  	if(ch==2){ 
	count=0;
	system("cls");
	gotoxy(10,3);
	printf("Enter patient cabin number to Search: ");
    scanf("%d",&ptcabin);
    fp = fopen("patientrecords.txt","r+");
    if(fp == NULL){
        gotoxy(10,6);
        printf("Error opening file");
        exit(1);
    }
    while(fread(&p,sizeof(p),1,fp ) == 1){
    	
        if(ptcabin==p.cabin){
			count++;
        	
            gotoxy(10,8);
            printf("Name : %s",p.full_name);
            gotoxy(10,10);
            printf("Age : %d",p.age);
            gotoxy(10,12);
            printf("Gender : %c",p.gender);
            gotoxy(10,14);
            printf("Address: %s",p.address);
            gotoxy(10,16);
            printf("Contact: %s",p.contact);
            gotoxy(10,18);
            printf("Cabin Num: %d",p.cabin);
            gotoxy(10,20);
            printf("Cause of Admission: %s",p.cause);
            gotoxy(10,22);
            printf("Admission Date: %s",p.admit_date);
            
        }
    }
        fclose(fp);
        if(count==0){
        	gotoxy(10,5);
        	printf("Not found");
		}
        

    
}

    gotoxy(10,24);
    printf("Press any key to continue.");
    getch();
    menu();
}




void modify(){
	
char pname[50];
	FILE *fp;
	system("cls");
	gotoxy(10,3);
	printf("<--:MODIFY RECORD:-->");
	gotoxy(10,5);
	printf("Enter full name of patient to modify record: ");
	fflush(stdin);
	gets(pname);
	fp = fopen("patientrecords.txt","r+");
	if(fp == NULL){
		gotoxy(10,6);
		printf("Error opening file.");
		exit(1);
	}
	rewind(fp);
	fflush(stdin);
	while(fread(&p,sizeof(p),1,fp) == 1)
	{
	
		if(strcmp(pname,p.full_name) == 0){
		gotoxy(10,7);
		printf("<--:CURRENT RECORD:-->");
		gotoxy(10,9);
		printf("Name                Age  Gender   Contact         Address          Cabin    Admission Cause     Admit Date");
		gotoxy(10,11);
		printf("%-20s%-5d%-8c%-16s%-18s%-8d%-20s%-10s",p.full_name,p.age,p.gender,p.contact,p.address,p.cabin,p.cause,p.admit_date);
		gotoxy(10,13);
		printf("Enter Full Name: ");
        gets(p.full_name);
        gotoxy(10,15);
        printf("Enter Age: ");
        scanf("%d",&p.age);
        gotoxy(10,17);
        printf("Enter Gender(M/F/O): ");
        scanf(" %c",&p.gender);
        gotoxy(10,19);
        printf("Enter Contact: ");
        fflush(stdin);
				gets(p.contact);

        gotoxy(10,21);
        printf("Enter Address: ");
        fflush(stdin);
				gets(p.address);
        gotoxy(10,23);
        printf("Enter Cabin Num: ");
        scanf("%d",&p.cabin);

        gotoxy(10,25);
       printf("Enter Cause of Admission: ");
        fflush(stdin);
				gets(p.cause);
        gotoxy(10,27);
        printf("Enter Admission Date AD(YYYY/MM/DD): ");
        fflush(stdin);
				gets(p.admit_date);
			fseek(fp ,-sizeof(p),SEEK_CUR);
			fwrite(&p,sizeof(p),1,fp);
			break;
		}
		else{
			gotoxy(10,7);
			printf("RECORD NOT FOUND");
		}
	}
	fclose(fp);
	gotoxy(10,29);
	printf("Press any key to continue.");
	getch();
	menu();
}





void delrec(){
   int ptcabin,count=0;
	FILE *fp,*ft;
	system("cls");
	gotoxy(10,3);
	printf("<--:DELETE RECORD:-->");
	gotoxy(10,5);
	printf("Enter cabin no. of patient to delete record : ");
	scanf("%d",&ptcabin);
	
	
	
	fp = fopen("patientrecords.txt","r+");
	if(fp == NULL){
		gotoxy(10,6);
		printf("Error opening file.");
		exit(1);
	}
	
	
	ft = fopen("temp.txt","w+");
	if(ft == NULL){
		gotoxy(10,6);
		printf("Error opening file.");
		exit(1);
	}
	
	
	
	while(fread(&p,sizeof(p),1,fp) == 1){
		if(ptcabin!=p.cabin)
			fwrite(&p,sizeof(p),1,ft);
		else
			count++;
	}
	fclose(fp);
	fclose(ft);
	
	fp = fopen("patientrecords.txt","w+");
	if(fp == NULL){
		gotoxy(10,6);
		printf("Error opening file.");
		exit(1);
	}
	ft = fopen("temp.txt","r+");
	if(ft == NULL){
		gotoxy(10,6);
		printf("Error opening file.");
		exit(1);
	}
	
	
	while(fread(&p,sizeof(p),1,ft) == 1){
		fwrite(&p,sizeof(p),1,fp);
	}
	fclose(fp);
	fclose(ft);
	remove("temp.txt");
	gotoxy(10,10);
	if(count == 0)
		printf("No records found!");
	else
		printf("Record successfully deleted!");
	gotoxy(10,12);
	printf("Press any key to continue.");
	getch();
	menu();
	}

	
		
	

void gotoxy(int x,int y)
{
        COORD c;
        c.X=x;
        c.Y=y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
