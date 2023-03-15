/*
Name: Student Information System

*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<conio.h>
/* function declaration start*/
	void add();
	void display();
	void search_modify();
	void input();
	void output();
	void division1();
	void division2();
	void division3();
	void division4();
	void delete();
	/*Function declaration End*/
FILE *SCIENCE,*ARTS,*COMMERCE;					 //file pointer
typedef struct
{
	char f_name[25],l_name[25],address[100],phone_no[15],section;
	char roll[15];
	float marks[6],obt_marks,avg_marks,total_marks[5],percent;
}student;
student st;							//global declaration of structure

int main()							//main function start
{
	int c=1;
	char password[10];
	char pass[]={"1031"};
	printf("\t\t\tUTTOR-DOKKHIN COLLEGE");
	printf("\n\n\t\tplease enter the password:>  ");
	gets(password);
	if(strcmp(password,pass)==0)  /*Password Compare*/
 {

	start: system("cls");
	int no;
	do
	{
		system("cls");

     height: printf("\t\t====== STUDENT INFORMATION SYSTEM ======"); /*Menu*/
      printf("\n\n                                          ");
      printf( "\n\n");
      printf( "\n \t\t\t 1. Add    Records");
   	  printf( "\n \t\t\t 2. List   Records");
      printf( "\n \t\t\t 3. Search and Modify Records");
      printf( "\n \t\t\t 4. Delete Records");
      printf( "\n \t\t\t 5. Exit   Program");
      printf( "\n\n");
      printf("\t\t\t Select Your Choice(1,2,3,4 or 5) :=> ");
     target : scanf("%d",&no);
      switch(no)
      {
      	case 1:
      		add(); /* Add Function Calling*/
      		break;
      	case 2:
      		display(); /*Display Function Calling*/
      		break;
      	case 3:
      		search_modify(); /*Search_ modify Function Calling*/
      		break;
      	case 4:
      		delete(); /*Delete Function Calling*/
      		break;
      	case 5: /*Program exit with leaving this message*/
      		     printf( "\n\n");
             printf("\t\t     THANK YOU FOR USING THIS ");
           printf( "\n\n");
           getch();
              exit(0); "\n\n";
             break;
             default :
             	printf("\n\t\tInvalid choice--please enter the valid choice again:");
             	goto target;
             	break;


     }
	}while(no!=5);
}
	else
	{
		while(1) /* password comparing*/
		{
				if(c==1)
				printf("\n\t\tincorrect password :(  try again o_o) ");
				printf("\n\t\tenter the correct password again  ");
				gets(password);
				if(strcmp(password,pass)==0)
			{
				goto start; //goto is a jumping statement in c which transfer programs control from one statement to another(where lebel is defined )
			}

		}
	}
	return 0;
}								//end of main function
void add()						//start of add function
{
	system("cls");
	int ch,no;
	char ans;
	  printf("\n\n\n");														//add menu
	  printf( "\n \t\t\t 1. add record in Science Group");
   	  printf( "\n \t\t\t 2. add record in Arts Group");
      printf( "\n \t\t\t 3. add record in Commerce Group");
      printf( "\n \t\t\t 4. return to main menu");
      printf( "\n\n");
      printf("\t\t\t Select Your Choice(1,2,3 or 4) :=> ");
	  top:scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			system("cls");										//for science file
			SCIENCE=fopen("science.txt","ab");
			if(SCIENCE==NULL)
			{
				printf("error in opening science.txt file");
				getch();
				exit(0);
			}

			do
			{
				input();
				fwrite(&st,sizeof(st),1,SCIENCE);
				printf("do you want to add another record (y for yes)");
				fflush(stdin);
				scanf("%c",&ans);
			}while(tolower(ans)=='y');
			fclose(SCIENCE);
			break;
		case 2:
				system("cls");
			ARTS=fopen("arts.txt","ab");					//for arts file
			if(ARTS==NULL)
			{
				printf("error in opening arts.txt file");
				getch();
				exit(0);
			}
			do
			{
				input();
				fwrite(&st,sizeof(st),1,ARTS);
				printf("do you want to add another record (y for yes)");
				fflush(stdin);
				scanf("%c",&ans);
			}while(tolower(ans)=='y');
			fclose(ARTS);
			break;
		case 3:
			system("cls");								//	for COMMERCE file
			COMMERCE=fopen("commerce.txt","ab");
			if(COMMERCE==NULL)
			{
				printf("error in opening commerce.txt file");
				getch();
				exit(0);
			}
			do
			{
				input();
				fwrite(&st,sizeof(st),1,COMMERCE);
				printf("do you want to add another record (y for yes)");
				fflush(stdin);
				scanf("%c",&ans);
			}while(tolower(ans)=='y');
			fclose(COMMERCE);
			break;
		case 4:
			break;

			default :
			printf("\t\tenter the valid choice");
			goto top;
			break;

	}
}													//end of add function
void input()											//start of input function
{
			int z;
		for(z=0;z<6;z++)
		{
			st.total_marks[z]=0;
			st.marks[z]=0;
		}
		int i;
		float sum=0,total=0;
		char ans;
				printf("\tplease enter the first name:>");
				fflush(stdin);
				gets(st.f_name);													//name,roll no,section
				printf("\tplease enter the last name:>");
				fflush(stdin);
				gets(st.l_name);
				printf("\tplease enter the section:>");
				fflush(stdin);
				scanf("%c",&st.section);
				printf("\tplease enter the roll number:>");
				scanf("%s",st.roll);
				printf("do u want to add marks(y for yes)");
				fflush(stdin);
				scanf("%c",&ans);
				for(i=0;i<1;i++)
				{
					if(tolower(ans)!='y')
					break;																	//input of marks
					printf("enter the total marks & marks obtained in Bangla:>");
					scanf("%f%f",&st.total_marks[i],&st.marks[i]);
					i=i+1;
					printf("enter the total marks & marks obtained in History:>");
					scanf("%f%f",&st.total_marks[i],&st.marks[i]);
					i=i+1;
					printf("enter the total marks & marks obtained in English:>");
					scanf("%f%f",&st.total_marks[i],&st.marks[i]);
					i=i+1;
					printf("enter the total marks & marks obtained in Mathematics:>");
					scanf("%f%f",&st.total_marks[i],&st.marks[i]);
					i=i+1;
					printf("enter the total marks & marks obtained in ICT:>");
					scanf("%f%f",&st.total_marks[i],&st.marks[i]);
					i=i+1;
				}
				if(i!=0)
				{
				for(i=0;i<6;i++)
				{																//calculation of percent,average and obtained marks
					sum+=st.marks[i];
					total+=st.total_marks[i];
				}
				st.obt_marks=sum;
				st.avg_marks=sum/5;
				st.percent=(sum/total)*100;
				}
				printf("please enter the phone number:>");				//phone number
				fflush(stdin);
				gets(st.phone_no);
				printf("please enter the address:>");					//address
				fflush(stdin);
				gets(st.address);

}
int dist,first,sec,pass;																//end of input function
void display()															//start of display function
{
	int no,fail,ch;
	char blood[5];
system("cls");
reverse:	printf("\n\n\n\n");
	printf("\n\t\t\t1.list all");
	printf("\n\t\t\t2.list of science Group");
	printf("\n\t\t\t3.list of arts Group");
	printf("\n\t\t\t4.list of commerce Group");
	printf("\n\t\t\t5.list of passed student");
	printf("\n\t\t\t6.list of failed student");
	printf("\n\t\t\t7.return to main menu");
	printf("\n\n\t\t\tenter the choice your choice from(1-7)=>");
upper: scanf("%d",&no);
	switch(no)
	{
		case 1:
			system("cls");										//for science file
			SCIENCE=fopen("science.txt","rb");
			if(SCIENCE==NULL)
			{
				printf("\n\n\t\terror in opening science.txt file\n");
				getch();
			exit(0);
			}
		else
		{
			printf("\n\n\t\tGroup \"SCIENCE\"");
			while(fread(&st,sizeof(st),1,SCIENCE)==1)
			{
				output();
			}
		}
			ARTS=fopen("arts.txt","rb");
			if(ARTS==NULL)
			{
				printf("\n\n\t\terror in opening arts.txt file\n");
				getch();
				exit(0);
			}
		else
		{
			printf("\n\t\t\tGroup \"ARTS\"");
			while(fread(&st,sizeof(st),1,ARTS)==1)
			{
				output();
			}
		}
			COMMERCE=fopen("commerce.txt","rb");
			if(COMMERCE==NULL)
			{
				printf("\n\n\t\terror in opening commerce.txt file");
				getch();
				break;
			exit(0);
			}
			printf("\n\t\t\tGroup \"COMMERCE\"");
			while(fread(&st,sizeof(st),1,COMMERCE)==1)
			{
				output();
			}
			getch();
			fclose(SCIENCE);
					fclose(ARTS);
					fclose(COMMERCE);
			break;
		case 2:
				system("cls");										//for science file
			SCIENCE=fopen("science.txt","rb");
			if(SCIENCE==NULL)
			{
				printf("\n\n\t\terror in opening science.txt file");
				getch();
				break;
				exit(0);
			}
			printf("Group \"SCIENCE\"");
		     rewind(SCIENCE);
			while(fread(&st,sizeof(st),1,SCIENCE)==1)
			{
				output();
			}
			getch();
			fclose(SCIENCE);
			break;
		case 3:
				system("cls");
				ARTS=fopen("D:\\arts.txt","rb");
			if(ARTS==NULL)
			{
				printf("\n\n\t\terror in opening arts.txt file");
				getch();
				break;
			//	exit(0);
			}
			printf("Group \"ARTS\"");
		//	rewind(ARTS);
			while(fread(&st,sizeof(st),1,ARTS)==1)
			{
				output();
			}
			getch();
			fclose(ARTS);
			break;
		case 4:
				system("cls");
				COMMERCE=fopen("D:\\commerce.txt","rb");
			if(COMMERCE==NULL)
			{
				printf("\n\n\t\terror in opening COMMERCE.txt file");
				getch();
				break;
			//	exit(0);
			}
			printf("Group \"COMMERCE\"");
		//	rewind(COMMERCE);
			while(fread(&st,sizeof(st),1,COMMERCE)==1)
			{
				output();
			}
			getch();
			fclose(COMMERCE);
			break;
		case 5:
				system("cls");
			printf("enter the distiction percent=");
			scanf("%d",&dist);
			printf("enter the first division percent=");
			scanf("%d",&first);
			printf("enter the second division percent=");
			scanf("%d",&sec);
			printf("enter the passed division percent=");
			scanf("%d",&pass);
			system("cls");
			printf("\n\n");
			printf("\n\t\t500.all student");
			printf("\n\t\t600.science student");
			printf("\n\t\t700.arts student");
			printf("\n\t\t800.commerce student");
			printf("\n\t\t900.return to menu");
			printf("\n\n\t\t\tenter the choice(500,600,700,800,900)=>");
		above:	scanf("%d",&ch);
			switch(ch)
			{
				case 500:
					system("cls");
						SCIENCE=fopen("science.txt","rb");
						if(SCIENCE==NULL)
					{
						printf("\n\n\t\terror in opening science.txt file\n\n");
					}
					else
					{
						while(fread(&st,sizeof(st),1,SCIENCE)==1)
						{
							division1();
						}

                            rewind(SCIENCE);
							while(fread(&st,sizeof(st),1,SCIENCE)==1)
						{
							division2();

						}
								rewind(SCIENCE);
								while(fread(&st,sizeof(st),1,SCIENCE)==1)
						{
								division3();

						}

							rewind(SCIENCE);
							while(fread(&st,sizeof(st),1,SCIENCE)==1)
						{
								division4();

						}

						fclose(SCIENCE);
					}
							ARTS=fopen("arts.txt","rb");
							if(ARTS==NULL)
						{
						printf("\n\n\t\terror in opening arts.txt file\n\n");
						}
					else
					{
						while(fread(&st,sizeof(st),1,ARTS)==1)
						{
							division1();
						}
							rewind(ARTS);
							while(fread(&st,sizeof(st),1,ARTS)==1)
							{
								division2();
							}

							rewind(ARTS);
							while(fread(&st,sizeof(st),1,ARTS)==1)
							{
							division3();
							}

								rewind(ARTS);
							while(fread(&st,sizeof(st),1,ARTS)==1)
							{
								division4();
							}

							fclose(ARTS);
					}
						COMMERCE=fopen("commerce.txt","rb");
						if(COMMERCE==NULL)
						{
							printf("\n\n\t\terror in opening commerce.txt file");
							getch();
							break;
								exit(0);
						}
							while(fread(&st,sizeof(st),1,COMMERCE)==1)
							division1();

								rewind(COMMERCE);
							while(fread(&st,sizeof(st),1,COMMERCE)==1)
							division2();

								rewind(COMMERCE);
							while(fread(&st,sizeof(st),1,COMMERCE)==1)
							division3();

								rewind(COMMERCE);
							while(fread(&st,sizeof(st),1,COMMERCE)==1)
							division4();
							getch();
					fclose(COMMERCE);
							break;

					case 600:
						system("cls");
						SCIENCE=fopen("science.txt","rb");
						if(SCIENCE==NULL)
					{
						printf("\n\t\t\terror in opening science.txt file");
						getch();
						break;
					}
						while(fread(&st,sizeof(st),1,SCIENCE)==1)
							division1();
							rewind(SCIENCE);
						while(fread(&st,sizeof(st),1,SCIENCE)==1)
							division2();
							rewind(SCIENCE);
						while(fread(&st,sizeof(st),1,SCIENCE)==1)
							division3();
							rewind(SCIENCE);
						while(fread(&st,sizeof(st),1,SCIENCE)==1)
							division4();
							fclose(SCIENCE);
							getch();
							break;
					case 700:
						system("cls");
						ARTS=fopen("arts.txt","rb");
							if(ARTS==NULL)
						{
						printf("\n\n\t\terror in opening arts.txt file");
						getch();
							break;
						}
						while(fread(&st,sizeof(st),1,ARTS)==1)
						{
							division1();
						}
							rewind(ARTS);
							while(fread(&st,sizeof(st),1,ARTS)==1)
							{
								division2();
							}
							rewind(ARTS);
							while(fread(&st,sizeof(st),1,ARTS)==1)
							{
							division3();
							}
								rewind(ARTS);
							while(fread(&st,sizeof(st),1,ARTS)==1)
							{
								division4();
							}
							getch();
							fclose(ARTS);
							break;
					case 800:
						system("cls");
						COMMERCE=fopen("commerce.txt","rb");
						if(COMMERCE==NULL)
						{
							printf("\n\n\t\terror in opening commerce.txt file");
							getch();
							break;
						}
							while(fread(&st,sizeof(st),1,COMMERCE)==1)
							division1();
								rewind(COMMERCE);
							while(fread(&st,sizeof(st),1,COMMERCE)==1)
							division2();
								rewind(COMMERCE);
							while(fread(&st,sizeof(st),1,COMMERCE)==1)
							division3();
								rewind(COMMERCE);
							while(fread(&st,sizeof(st),1,COMMERCE)==1)
							division4();
							getch();
					fclose(COMMERCE);
							break;
					case 900:
						system("cls");
						goto reverse;
						break;
					default :
					printf("enter the valid choice");
					goto above;
					break;
			}
			break;
		case 6:
			system("cls");
			printf("enter the fail percent");
			scanf("%d",&fail);
				SCIENCE=fopen("science.txt","rb");
						if(SCIENCE==NULL)
					{
						printf("\n\t\t\terror in opening science.txt file");
						getch();
						break;
					}
						while(fread(&st,sizeof(st),1,SCIENCE)==1)
						{

						if(st.percent<=fail)
							{
								printf("\nName=%s %s",st.f_name,st.l_name);
								printf("\nRoll number=%s",st.roll);
								printf("\nSection=%c",st.section);

								printf("\nPhone no=%s",st.phone_no);
								printf("\nAddress=%s",st.address);
								printf("\n\n    \t\tMarks obtained in each subject are:>\n");
								printf("Subject  \t\ttotal marks\tobt marks\t\n\n");
								printf("Bangla= \t\t%.2f\t\t%.2f\n",st.total_marks[0],st.marks[0]);
								printf("History=  \t\t%.2f\t\t%.2f\n",st.total_marks[1],st.marks[1]);
								printf("English= \t\t%.2f\t\t%.2f\n",st.total_marks[2],st.marks[2]);
								printf("Mathematics=\t\t%.2f\t\t%.2f\n",st.total_marks[3],st.marks[3]);
								printf("ICT=    \t\t%.2f\t\t%.2f\n",st.total_marks[4],st.marks[4]);
								printf("\n\ntotal obtained marks=%f",st.obt_marks);
								printf("\nAverage marks=%f",st.avg_marks);
								printf("\nPercentage=%f\n",st.percent);
								printf("\n\t------------------------------\n\n\n\n");
							}
						}
						ARTS=fopen("arts.txt","rb");
							if(ARTS==NULL)
						{
						printf("\n\n\t\terror in opening arts.txt file");
						getch();
							break;
						}
							while(fread(&st,sizeof(st),1,ARTS)==1)
						{

						if(st.percent<=fail)
							{
								printf("\nName=%s %s",st.f_name,st.l_name);
								printf("\nRoll number=%s",st.roll);
								printf("\nSection=%c",st.section);
								printf("\nPhone no=%s",st.phone_no);
								printf("\nAddress=%s",st.address);
								printf("\n\n    \t\tMarks obtained in each subject are:>\n");
								printf("Subject  \t\ttotal marks\tobt marks\t\n\n");
								printf("Bangla= \t\t%.2f\t\t%.2f\n",st.total_marks[0],st.marks[0]);
								printf("physics=  \t\t%.2f\t\t%.2f\n",st.total_marks[1],st.marks[1]);
								printf("English= \t\t%.2f\t\t%.2f\n",st.total_marks[2],st.marks[2]);
								printf("Mathematics=\t\t%.2f\t\t%.2f\n",st.total_marks[3],st.marks[3]);
								printf("ICT=  \t\t%.2f\t\t%.2f\n",st.total_marks[4],st.marks[4]);

								printf("\n\ntotal obtained marks=%f",st.obt_marks);
								printf("\nAverage marks=%f",st.avg_marks);
								printf("\nPercentage=%f",st.percent);
								printf("\n\t------------------------------\n\n\n\n");
							}
						}
							COMMERCE=fopen("commerce.txt","rb");
						if(COMMERCE==NULL)
						{
							printf("\n\n\t\terror in opening commerce.txt file");
							getch();
							break;
						}
							while(fread(&st,sizeof(st),1,COMMERCE)==1)
						{

						if(st.percent<=fail)
							{
									printf("\nName=%s %s",st.f_name,st.l_name);
								printf("\nRoll number=%s",st.roll);
								printf("\nSection=%c",st.section);
								printf("\nPhone no=%s",st.phone_no);
								printf("\nAddress=%s",st.address);
								printf("\n\n    \t\tMarks obtained in each subject are:>\n");
								printf("Subject  \t\ttotal marks\tobt marks\t\n\n");
								printf("Bangla= \t\t%.2f\t\t%.2f\n",st.total_marks[0],st.marks[0]);
								printf("physics=  \t\t%.2f\t\t%.2f\n",st.total_marks[1],st.marks[1]);
								printf("English= \t\t%.2f\t\t%.2f\n",st.total_marks[2],st.marks[2]);
								printf("Mathematics=\t\t%.2f\t\t%.2f\n",st.total_marks[3],st.marks[3]);
								printf("ICT=  \t\t%.2f\t\t%.2f\n",st.total_marks[4],st.marks[4]);
								printf("\n\ntotal obtained marks=%f",st.obt_marks);
								printf("\nAverage marks=%f",st.avg_marks);
								printf("\nPercentage=%f",st.percent);
								printf("\n\t------------------------------\n\n\n\n");
							}
						}
						getch();
						fclose(SCIENCE);
					fclose(ARTS);
					fclose(COMMERCE);
						break;
				case 7:
					fclose(SCIENCE);
					fclose(ARTS);
					fclose(COMMERCE);
					system("cls");
					break;
				default :
					printf("enter the valid choice");
					goto upper;
						break;
	}


}
void output()
{
	printf("\nName=%s %s",st.f_name,st.l_name);
	printf("\nRoll number=%s",st.roll);
	printf("\nSection=%c",st.section);
	printf("\nPhone no=%s",st.phone_no);
	printf("\nAddress=%s",st.address);
	printf("\n\n    \t\tMarks obtained in each subject are:>\n");
	printf("Subject  \t\ttotal marks\tobt marks\t\n\n");
	printf("Bangla= \t\t%.2f\t\t%.2f\n",st.total_marks[0],st.marks[0]);
	printf("History=  \t\t%.2f\t\t%.2f\n",st.total_marks[1],st.marks[1]);
	printf("English= \t\t%.2f\t\t%.2f\n",st.total_marks[2],st.marks[2]);
	printf("Mathematics=\t\t%.2f\t\t%.2f\n",st.total_marks[3],st.marks[3]);
	printf("ICT=  \t\t%.2f\t\t%.2f\n",st.total_marks[4],st.marks[4]);
	printf("\n\ntotal obtained marks=%.2f",st.obt_marks);
	printf("\nAverage marks=%.2f",st.avg_marks);
	printf("\nPercentage=%.2f",st.percent);
	printf("\n\t------------------------------\n\n\n\n");
}
void division1()
{
		if(st.percent>=dist)
							{
									printf("\nName=%s %s",st.f_name,st.l_name);
									printf("\nRoll number=%s",st.roll);
									printf("\nSection=%c",st.section);
									printf("\nPhone no=%s",st.phone_no);
									printf("\nAddress=%s",st.address);
									printf("\n\n    \t\tMarks obtained in each subject are:>\n");
									printf("Subject  \t\ttotal marks\tobt marks\t\n\n");
									printf("Bangla= \t\t%.2f\t\t%.2f\n",st.total_marks[0],st.marks[0]);
									printf("History=  \t\t%.2f\t\t%.2f\n",st.total_marks[1],st.marks[1]);
									printf("English= \t\t%.2f\t\t%.2f\n",st.total_marks[2],st.marks[2]);
									printf("Mathematics=\t\t%.2f\t\t%.2f\n",st.total_marks[3],st.marks[3]);
									printf("ICT=  \t\t%.2f\t\t%.2f\n",st.total_marks[4],st.marks[4]);
									printf("\n\ntotal obtained marks=%f",st.obt_marks);
									printf("\nAverage marks=%f",st.avg_marks);
									printf("\nPercentage=%f",st.percent);
									printf("\n\t------------------------------\n\n\n\n");
}

}
void division2()
{
		if(st.percent>=first && st.percent<dist)
							{
								printf("\nName=%s %s",st.f_name,st.l_name);
								printf("\nRoll number=%s",st.roll);
								printf("\nSection=%c",st.section);
								printf("\nPhone no=%s",st.phone_no);
								printf("\nAddress=%s",st.address);
								printf("\n\n    \t\tMarks obtained in each subject are:>\n");
								printf("Subject  \t\ttotal marks\tobt marks\t\n\n");
								printf("Bangla= \t\t%.2f\t\t%.2f\n",st.total_marks[0],st.marks[0]);
								printf("History=  \t\t%.2f\t\t%.2f\n",st.total_marks[1],st.marks[1]);
								printf("English= \t\t%.2f\t\t%.2f\n",st.total_marks[2],st.marks[2]);
								printf("Mathematics=\t\t%.2f\t\t%.2f\n",st.total_marks[3],st.marks[3]);
								printf("ICT=  \t\t%.2f\t\t%.2f\n",st.total_marks[4],st.marks[4]);
								printf("\n\ntotal obtained marks=%f",st.obt_marks);
								printf("\nAverage marks=%f",st.avg_marks);
								printf("\nPercentage=%f",st.percent);
								printf("\n\t------------------------------\n\n\n\n");
							}
}
void division3()
{
		if(st.percent>=sec && st.percent<first)
							{
								printf("\nName=%s %s",st.f_name,st.l_name);
								printf("\nRoll number=%s",st.roll);
								printf("\nSection=%c",st.section);
								printf("\nPhone no=%s",st.phone_no);
								printf("\nAddress=%s",st.address);
								printf("\n\n    \t\tMarks obtained in each subject are:>\n");
								printf("Subject  \t\ttotal marks\tobt marks\t\n\n");
								printf("Bangla= \t\t%.2f\t\t%.2f\n",st.total_marks[0],st.marks[0]);
								printf("History=  \t\t%.2f\t\t%.2f\n",st.total_marks[1],st.marks[1]);
								printf("English= \t\t%.2f\t\t%.2f\n",st.total_marks[2],st.marks[2]);
								printf("Mathematics=\t\t%.2f\t\t%.2f\n",st.total_marks[3],st.marks[3]);
								printf("ICT=  \t\t%.2f\t\t%.2f\n",st.total_marks[4],st.marks[4]);

								printf("\n\ntotal obtained marks=%f",st.obt_marks);
								printf("\nAverage marks=%f",st.avg_marks);
								printf("\nPercentage=%f",st.percent);
								printf("\n\t------------------------------\n\n\n\n");
							}
}
void division4()
{
		if(st.percent>=pass && st.percent<sec)
							{
								printf("\nName=%s %s",st.f_name,st.l_name);
								printf("\nRoll number=%s",st.roll);
								printf("\nSection=%c",st.section);
								printf("\nPhone no=%s",st.phone_no);
								printf("\nAddress=%s",st.address);
								printf("\n\n    \t\tMarks obtained in each subject are:>\n");
								printf("Subject  \t\ttotal marks\tobt marks\t\n\n");
								printf("Bangla= \t\t%.2f\t\t%.2f\n",st.total_marks[0],st.marks[0]);
								printf("History=  \t\t%.2f\t\t%.2f\n",st.total_marks[1],st.marks[1]);
								printf("English= \t\t%.2f\t\t%.2f\n",st.total_marks[2],st.marks[2]);
								printf("Mathematics=\t\t%.2f\t\t%.2f\n",st.total_marks[3],st.marks[3]);
								printf("ICT=  \t\t%.2f\t\t%.2f\n",st.total_marks[4],st.marks[4]);

								printf("\n\ntotal obtained marks=%f",st.obt_marks);
								printf("\nAverage marks=%f",st.avg_marks);
								printf("\nPercentage=%f",st.percent);
								printf("\n\t------------------------------\n\n\n\n");
							}
}
void search_modify()
{
	int ch;
	char g,r[15],ph[15],fname[25],lname[25];
	system("cls");
			printf("\n\t\t1.search by name");
			printf("\n\t\t2.search by roll number");
			printf("\n\t\t3.search by phone number");
			printf("\n\t\t4.return to menu");
			printf("\n\n\t\t\tenter the choice(1,2,3,4)=>");
			read:	scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				system("cls");
				printf("\n\t\t\tenter the first name:");
				fflush(stdin);
				gets(fname);
				printf("\n\t\t\tenter the last name:");
				fflush(stdin);
				gets(lname);
					SCIENCE=fopen("science.txt","rb+");
			if(SCIENCE==NULL)
			{
				printf("\n\t\terror in opening science.txt file\n");
			}
				while(fread(&st,sizeof(st),1,SCIENCE)==1)
					{
						if(strcmp(st.f_name,fname)==0)
						{
								if(strcmp(st.l_name,lname)==0)
							{
								output();
								printf("\n\n\t\tDo you want to modify this record");
								printf("\n enter 'y' for yes or press any other key =  ");
								scanf("%c",&g);
								if('y'==tolower(g))
								{
								input();
								fseek(SCIENCE,-sizeof(st),SEEK_CUR);
								fwrite(&st,sizeof(st),1,SCIENCE);
								break;
								}
								if('d'==tolower(g))
								{
									if(strcmp(st.l_name,lname)==0)
									continue;
									rewind(SCIENCE);

								}
							}
						}

					}
						fclose(SCIENCE);
						ARTS=fopen("arts.txt","rb+");
						if(ARTS==NULL)
						{
							printf("\n\t\terror in opening arts.txt file\n");
						}
							while(fread(&st,sizeof(st),1,ARTS)==1)
					{
						if(strcmp(st.f_name,fname)==0)
						{
								if(strcmp(st.l_name,lname)==0)
							{
								output();
								printf("\n\n\t\tDo you want to modify this record");
								printf("\n enter 'y' for yes or press any other key =  ");
								scanf("%c",&g);
								if('y'==tolower(g))
								{
								input();
								fseek(ARTS,-sizeof(st),SEEK_CUR);
								fwrite(&st,sizeof(st),1,ARTS);
								break;
								}
							}
						}

					}
						fclose(ARTS);
						COMMERCE=fopen("commerce.txt","rb+");
						if(COMMERCE==NULL)
					{
							printf("\n\t\terror in opening commerce.txt file");
							getch();
							break;
					}
						while(fread(&st,sizeof(st),1,COMMERCE)==1)
					{
						if(strcmp(st.f_name,fname)==0)
						{
								if(strcmp(st.l_name,lname)==0)
							{
								output();
								printf("\n\n\t\tDo you want to modify this record");
								printf("\n enter 'y' for yes or press any other key =  ");
								scanf("%c",&g);
								if('y'==tolower(g))
								{
								input();
								fseek(COMMERCE,-sizeof(st),SEEK_CUR);
								fwrite(&st,sizeof(st),1,COMMERCE);
								break;
								}
							}
						}

					}
						getch();
						fclose(COMMERCE);
						break;
			case 2:
				system("cls");
				printf("\n\t\t\tenter the roll number you want to search:");
				fflush(stdin);
				gets(r);
					SCIENCE=fopen("science.txt","rb+");
			if(SCIENCE==NULL)
			{
				printf("\n\t\terror in opening science.txt file\n");
			}
				while(fread(&st,sizeof(st),1,SCIENCE)==1)
					{
						if(strcmp(st.roll,r)==0)
						{
								output();
								printf("\n\n\t\tDo you want to modify this record");
								printf("\n enter 'y' for yes or press any other key =  ");
								scanf("%c",&g);
							if('y'==tolower(g))
								{
								input();
								fseek(SCIENCE,-sizeof(st),SEEK_CUR);
								fwrite(&st,sizeof(st),1,SCIENCE);
								break;
								}
						}

					}
						fclose(SCIENCE);
						ARTS=fopen("arts.txt","rb+");
						if(ARTS==NULL)
						{
							printf("\n\t\terror in opening arts.txt file\n");
						}
							while(fread(&st,sizeof(st),1,ARTS)==1)
					{
						if(strcmp(st.roll,r)==0)
						{
								output();
								printf("\n\n\t\tDo you want to modify this record");
								printf("\n enter 'y' for yes or press any other key =  ");
								scanf("%c",&g);
						if('y'==tolower(g))
								{
								input();
								fseek(ARTS,-sizeof(st),SEEK_CUR);
								fwrite(&st,sizeof(st),1,ARTS);
								break;
								}
						}

					}
						fclose(ARTS);
						COMMERCE=fopen("commerce.txt","rb+");
						if(COMMERCE==NULL)
					{
							printf("\n\t\terror in opening commerce.txt file");
							getch();
							break;
					}
						while(fread(&st,sizeof(st),1,COMMERCE)==1)
					{
						if(strcmp(st.roll,r)==0)
						{
								output();
								printf("\n\n\t\tDo you want to modify this record");
								printf("\n enter 'y' for yes or press any other key =  ");
								scanf("%c",&g);
							if('y'==tolower(g))
								{
								input();
								fseek(COMMERCE,-sizeof(st),SEEK_CUR);
								fwrite(&st,sizeof(st),1,COMMERCE);
								break;
								}
						}

					}
						getch();
						fclose(COMMERCE);
						break;
			case 3:
						system("cls");
				printf("\n\tenter the phone number you want to search:");
				fflush(stdin);
				gets(ph);
					SCIENCE=fopen("science.txt","rb+");
			if(SCIENCE==NULL)
			{
				printf("\n\t\terror in opening science.txt file\n");
			}
				while(fread(&st,sizeof(st),1,SCIENCE)==1)
					{
						if(strcmp(st.phone_no,ph)==0)
						{
								output();
								printf("\n\n\tDo you want to modify this record");
								printf("\n enter 'y' for yes or press any other key =  ");
								scanf("%c",&g);
							if('y'==tolower(g))
								{
								input();
								fseek(SCIENCE,-sizeof(st),SEEK_CUR);
                                fwrite(&st,sizeof(st),1,SCIENCE);
								break;
								}
						}

					}
						fclose(SCIENCE);
						ARTS=fopen("arts.txt","rb+");
						if(ARTS==NULL)
						{
							printf("\n\t\terror in opening arts.txt file\n");
						}
							while(fread(&st,sizeof(st),1,ARTS)==1)
					{
						if(strcmp(st.phone_no,ph)==0)
						{
								output();
								printf("\n\n\t\tDo you want to modify this record");
								printf("\n enter 'y' for yes or press any other key =  ");
								scanf("%c",&g);
							if('y'==tolower(g))
								{
								input();
								fseek(ARTS,-sizeof(st),SEEK_CUR);
								fwrite(&st,sizeof(st),1,ARTS);
								break;
								}
						}

					}
						fclose(ARTS);
						COMMERCE=fopen("commerce.txt","rb+");
						if(COMMERCE==NULL)
					{
							printf("\n\t\terror in opening commerce.txt file");
							getch();
							break;
					}
						while(fread(&st,sizeof(st),1,COMMERCE)==1)
					{
						if(strcmp(st.phone_no,ph)==0)
						{
								output();
								printf("\n\n\t\tDo you want to modify this record");
								printf("\n enter 'y' for yes or press any other key =  ");
								scanf("%c",&g);
						if('y'==tolower(g))
								{
								input();
								fseek(COMMERCE,-sizeof(st),SEEK_CUR);
								fwrite(&st,sizeof(st),1,COMMERCE);
								break;
								}
						}

					}
						getch();
						fclose(COMMERCE);
						break;
			case 4:
				break;
			default :
					printf("invalid choice\?\?--please enter correct choice");
					goto read;
					break;
		}
}
void delete()
{

}

