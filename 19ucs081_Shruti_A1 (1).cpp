//ASSINGMENT-1
//19UCS081
//SHRUTI GOYAL
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct student
{
	int id;
	char name[30];
	char branch[7];
};

struct marks
{
	int id,dbms,ds,c,total;
	double percent;
};

void update()
{
	int choice,ID;
	printf("Enter ID of student :: ");
	scanf("%d",&ID);
	FILE *fm=fopen("marks.txt","r");
	struct marks check;
	printf("\n1. Update DBMS student\n2. Update DS student\n3. Update C student\nChoice : ");
	scanf("%d",&choice);
	FILE *tempm=fopen("markstemp.txt","a+");
	fseek(fm,0,0);
	fseek(tempm,0,0);
	while(fread(&check,sizeof(struct marks),1,fm))
	{
		if(check.id!=ID)
			fwrite (&check, sizeof(struct marks), 1, tempm);
		else
		{
			struct marks stu;
			stu.id=ID;
			if(choice==1)
			{
				printf("Enter DBMS student :: ");
				scanf("%d",&stu.dbms);
				stu.ds=check.ds;
				stu.c=check.c;
				stu.total=stu.dbms+stu.ds+stu.c;
				stu.percent=(float)stu.total*1/3;
				fwrite (&stu, sizeof(struct marks), 1, tempm);
			}
			else if(choice==2)
			{
				printf("Enter DS student :: ");
				scanf("%d",&stu.ds);
				stu.dbms=check.dbms;
				stu.c=check.c;
				stu.total=stu.dbms+stu.ds+stu.c;
				stu.percent=(float)stu.total*0.334;
				fwrite (&stu, sizeof(struct marks), 1, tempm);
			}
			else if(choice==3)
			{
				printf("Enter C student :: ");
				scanf("%d",&stu.c);
				stu.dbms=check.dbms;
				stu.ds=check.ds;
				stu.total=stu.dbms+stu.ds+stu.c;
				stu.percent=(float)stu.total*1/3;
				fwrite (&stu, sizeof(struct marks), 1, tempm);
			}
		}
	}
	fclose(fm);
	fclose(tempm);
	remove("marks.txt");
	rename("markstemp.txt","marks.txt");
}
void showstudent()
{
	int ID;
	printf("Enter ID to be displayed:: ");
	scanf("%d",&ID);
	FILE *fm = fopen ("marks.txt","r");
	struct marks stu;
   	fseek(fm,0,0);
   	printf("\nID\t\t\tDBMS\t\t\tDS\t\t\tC\t\t\tTOTAL\t\t\tPERCENTAGE\n");
   	while (fread (&stu, sizeof(struct marks), 1, fm))
   		if(stu.id==ID)
   		{
      		printf ("%d\t\t\t%d\t\t\t%d\t\t\t%d\t\t\t%d\t\t\t%0.2f\n",stu.id,stu.dbms,stu.ds,stu.c,stu.total,stu.percent);
			fclose(fm);
      		return;
   		}
   	printf("ID doesn't exists !\n");
	fclose(fm);
	return;
}
void searchthresh()
{
	float threshold;
	printf("Enter threshold:: ");
	scanf("%f",&threshold);
	FILE *fm = fopen ("file2.txt","r");
	struct marks stu;
   	fseek(fm,0,0);
   	FILE *fs=fopen("marks.txt","r");
   	printf("\nID\t\t\tNAME\t\t\tBRANCH\t\t\tPERCENTAGE\n");
   	while (fread (&stu, sizeof(struct marks), 1, fs))
	   {
			if(stu.percent>=threshold)
			{
				struct student det;
				while (fread (&det, sizeof(struct student), 1, fm))
					if(det.id==stu.id)
						printf ("%d\t\t\t%s\t\t\t%s\t\t\t%0.2f\n",stu.id,det.name,det.branch,stu.percent);
				fclose(fs);
			}
	   }
   	fclose(fm);
}


void search()
{
	double threshold;
	char B[7];
	printf("Enter minimum threshold :: ");
	scanf("%f",&threshold);
	printf("Enter branch:: ");
	scanf("%s",B);
	FILE *fm = fopen ("file2.txt","r");
	FILE * fs= fopen("marks.txt","r");
	struct marks stu;
   	fseek(fm,0,0);
   	printf("\nID\t\t\tNAME\t\t\tPERCENTAGE\n");
   	while (fread (&stu, sizeof(struct marks), 1, fs))
   		if(stu.percent>=threshold)
   		{
   			struct student det;
   			while (fread (&det, sizeof(struct student), 1, fm))
   				if(det.id==stu.id && strcmp(det.branch,B)==0)
      				printf ("%d\t\t\t%s\t\t\t%0.2f\n",stu.id,det.name,stu.percent);
   		}
    fclose(fs);
   	fclose(fm);
}


void insertmarks()
{
	FILE *f = fopen("file2.txt" , "r");
                struct student S;
                struct marks M;
                printf("Enter ID : ");
                scanf("%d",&M.id); int flag = 0;
                printf("\nEnter MARKS to insert:\n");
                while(fread(&S , sizeof(struct marks) , 1, f))
                    if(S.id==M.id)
                    {
                        flag = 1;
                        FILE *p = fopen("marks.txt" , "a+");
                        struct marks check;
                        while(fread(&check , sizeof(struct marks) , 1 , p))
                        if(check.id==M.id)
                        {
                            printf("Marks already entered for this ID!\n");
                            continue;
                        }
                        printf("DBMS : ");
                        scanf("%d",&M.dbms);
                        printf("\nDS : ");
                        scanf("%d",&M.ds);
                        printf("\nC : ");
                        scanf("%d",&M.c);
                        M.total = M.dbms + M.c + M.ds;
                        M.percent = (double)M.total*1.0/3;
                        fwrite (&M , sizeof(struct marks), 1, p);
                        fclose(p);
                        return;
                    }
                if(flag==0)
                    printf("ID doesn't exists !\n");
                fclose(f);
}

void newdata()
{   restart:
	FILE *f=fopen("file2.txt","a+");
	struct student duplicate,stu;

	printf("Enter details to of student\n\nEnter Id (ID SHOULD BE IN INTEGER ONLY):: ");
	scanf("%d",&stu.id);
	while(fread(&duplicate,sizeof(struct student),1,f))
	{	if(duplicate.id==stu.id)
		{
			printf("\nID already exists!\nPlease renter");
			goto restart;
		}
	}
	printf("Enter Name(NAME SHOULD NOT HAVE SPACES IN BETWEEN) : ");
	scanf("%s",stu.name);
	printf("Enter Branch : ");
	scanf("%s",stu.branch);
	fwrite (&stu, sizeof(struct student), 1, f);
	fclose(f);
}


void modifyname()
{
	int ID;
	printf("Enter ID :: ");
	scanf("%d",&ID);
	FILE *f=fopen("file2.txt","r");
	struct student duplicate;
	FILE *temp=fopen("studenttemp.txt","a+");
	fseek(f,0,0);
	fseek(temp,0,0);
	while(fread(&duplicate,sizeof(struct student),1,f))
	{
		if(duplicate.id!=ID)
			fwrite (&duplicate, sizeof(struct student), 1, temp);
		else
		{
			struct student stu;
			stu.id=ID;
			printf("\nEnter new name :: ");
			scanf("%s",stu.name);
			strncpy(stu.branch,duplicate.branch,7);
			fwrite (&stu, sizeof(struct student), 1, temp);
			
		}
	}
	fclose(f);
	fclose(temp);
	remove("file2.txt");
	rename("studenttemp.txt","file2.txt");
	remove("studenttemp.txt");
}
void modifybranch()
{
	int ID;
	printf("Enter ID :: ");
	scanf("%d",&ID);
	FILE *f=fopen("file2.txt","r");
	struct student duplicate;
	FILE *temp=fopen("studenttemp.txt","a+");
	fseek(f,0,0);
	fseek(temp,0,0);
	while(fread(&duplicate,sizeof(struct student),1,f))
	{
		if(duplicate.id!=ID)
			fwrite (&duplicate, sizeof(struct student), 1, temp);
		else
		{
			struct student stu;
			stu.id=ID;
			printf("\nEnter new branch :: ");
			scanf("%s",stu.branch);
			strncpy(stu.name,duplicate.name,30);
			fwrite (&stu, sizeof(struct student), 1, temp);
		}
	}
	fclose(f);
	fclose(temp);
	remove("file2.txt");
	rename("studenttemp.txt","file2.txt");
	remove("studenttemp.txt");
}
void deletestu()
{
	int ID;
	struct student duplicate;
	struct marks mar;
	printf("Enter ID : ");
	scanf("%d",&ID);
	FILE *f=fopen("file2.txt","r");
	FILE *temp=fopen("temp.txt","a+");
	FILE *fm=fopen("marks.txt","a+");
	FILE *tempm=fopen("tempm.txt","a+");
	while(fread(&duplicate,sizeof(struct student),1,f))
		if(duplicate.id!=ID)
			fwrite (&duplicate, sizeof(struct student), 1, temp);
	while(fread(&mar,sizeof(struct marks),1,fm))
		if(mar.id!=ID)
			fwrite (&mar, sizeof(struct marks), 1, tempm);
	fclose(f);
	fclose(temp);
	fclose(fm);
	fclose(tempm);
	remove("file2.txt");
	rename("temp.txt","file2.txt");
//	remove("temp.txt");
	remove("marks.txt");
	rename("tempm.txt","marks.txt");
	//remove("tempm.txt");
}
void searchbranch()
{
	printf("\nEnter branch :: ");
		char B[7];
		scanf("%s",B);
		struct student stu;
		FILE *f = fopen ("file2.txt","r");
   		fseek(f,0,0);
   		printf("\nID\t\t\tNAME\t\t\tBRANCH\n");
   		while (fread (&stu, sizeof(struct student), 1, f))
   			if(strcmp(stu.branch,B)==0)
    	  		printf ("%-2d\t\t\t%-20s\t\t\t%-7s\n",stu.id,stu.name,stu.branch);
}


void searchname()
{
	printf("\nEnter name :: ");
		char N[30];
		scanf("%s",N);
		FILE *f = fopen ("file2.txt","r");
		struct student stu;
   		fseek(f,0,0);
   		printf("\nID\t\t\tNAME\t\t\tBRANCH\n");
   		while (fread (&stu, sizeof(struct student), 1, f))
   			if(strcmp(stu.name,N)==0)
    	  		printf ("%d\t\t\t%s\t\t\t%s\n",stu.id,stu.name,stu.branch);
}



int main()
{
	int ch;
	do
	{
		printf("\t\t\tENTER STUDENT INFORMATION");
		printf("\n(Choose option from menu)\n");
		printf("\n1. Enter new student data\n2. Modify name\n3. Modify branch \n4. Delete student entry\n5. Search according to branch\n6. Search by name\n7. To enter marks menu\n8.To exit\nEnter your Choice :: ");
		scanf("%d",&ch);
		printf("\n");
		switch(ch)
		{
			case 1:
			{
				newdata();
				break;
			}
			case 2:
			{
				modifyname();
				break;
			}
			case 3:
			{
				modifybranch();
				break;
			}
			case 4:
			{
				deletestu();
				break;
			}
			case 5:
			{
				searchbranch();
				break;
			}
			case 6:
			{
				searchname();
				break;
			}
			case 7:
			{
				break;
			}
			case 8:
			{
				return 0;
			}
			default:
			{
				printf("\nWrong option selected\n");
				break;
			}
		}
	}while(ch!=7);

	//MArks menue
	ch=0;
	do
	{
		l:
		printf("\t\t\tENTER marks student");
        printf("\n(Choose option from menu)\n");
		printf("\n1. Enter student marks\n2. Update student marks\n3. Show whole list of a marks.\n4. Search with PERCENTAGE above a threshold.\n5. Search the marks of a particular BRANCH with PERCENTAGE above a threshold.\n6. For exit\n\nEnter your Choice :: ");
		scanf("%d",&ch);
		printf("\n");
		switch(ch)
		{
			case 1:
            {
                FILE *f = fopen("file2.txt" , "r");
                struct student S;
                struct marks M;
                printf("Enter ID : ");
                scanf("%d",&M.id);
				int flag = 0;
                printf("\nEnter MARKS to insert:\n");
                while(fread(&S , sizeof(struct marks) , 1, f))
                    if(S.id==M.id)
                    {
                        flag = 1;
                        FILE *p = fopen("marks.txt" , "a+");
                        struct marks check;
                        while(fread(&check , sizeof(struct marks) , 1 , p))
                        if(check.id==M.id)
                        {
                            printf("Marks already entered for this ID!\n");
                            goto l;
                        }
                        printf("DBMS : ");
                        scanf("%d",&M.dbms);
                        printf("DS : ");
                        scanf("%d",&M.ds);
                        printf("C : ");
                        scanf("%d",&M.c);
                        M.total = M.dbms + M.c + M.ds;
                        M.percent = (double)M.total*1.0/3;
                        fwrite (&M , sizeof(struct marks), 1, p);
                        fclose(p);
                        continue;
                    }
                if(flag==0)
                    printf("ID doesn't exists !\n");
                fclose(f);
                break;
            }
			case 2:
            {
                update();
                break;
            }
			case 3:
            {
                showstudent();
                break;
            }
			case 4:
            {
                searchthresh();
                break;
            }
			case 5:
            {

				double marker;
                char b[25];
                printf("\nEnter threshold precentage :: ");
                scanf("%f",&marker);
                printf("\nEnter branch:: ");
                scanf("%s",&b);
                FILE *f = fopen ("marks.txt" , "r");
                struct marks M;
                int flag=0;
                while (fread (&M, sizeof(struct marks), 1, f))
                {
                    if(M.percent>=marker)
                    {
                        if(flag==0)
                        {
                            flag=1;
                            printf("\nID\t\t\tNAME\t\t\tPERCENTAGE\n");
                        }
                        FILE *p = fopen("file2.txt" , "r");
                        struct student S;
                        while (fread (&S, sizeof(struct student), 1, p))
                            if(S.id==M.id && strcmp(S.branch , b)==0)
                                printf("%d\t\t\t%s\t\t\t%0.2f\n",M.id,S.name,M.percent);
								//cout<<M.id<<"\t\t\t"<<S.name<<"\t\t\t"<<setprecision(10)<<M.percent<<endl;
                        fclose(p);
                    }
                }
                if(flag==0)
                {
                    printf("\nNo one get above %f in ",marker);
                    printf("%s \n",b);
                }
                
                
                fclose(f);
                break;
                //search();
                break;
            }
            case 6:
            {
                break;
            }
			default: 
            {
                printf("\nWrong option selected\n");
                break;
            }
		}
	}while(ch!=6);
	return 0;
}
