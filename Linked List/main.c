#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#define NumberOfStudent 500

int currentNumber = 0;
int Choice = 0;

typedef struct
{
    char name[50];
    int ID;
    int day;
    int month;
    int year;
    int score;

} Student;

struct node
{
   Student student;
   struct node* next;
};

struct node* head = NULL;
struct node* tail = NULL;

Student *st = NULL;

int pointer = 1;
int pressedKey = 0;

void hidecursor()
{
   HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_CURSOR_INFO info;
   info.dwSize = 100;
   info.bVisible = FALSE;
   SetConsoleCursorInfo(consoleHandle, &info);
}

void setCursorPosition(int x, int y)
{
    HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);

    COORD pos = { x, y };
    SetConsoleCursorPosition(output, pos);
}

void pointHere(int x, int y)
{
    if(x == y)
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);

    else
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}

void Get_Info(Student* getStudent)
{
    system("cls");

    setCursorPosition(0, 8);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");

    setCursorPosition(0, 16);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");

    fflush(stdin);
    setCursorPosition(0, 9);
    printf("Enter student name                          : ");
    while(1 != scanf("%[a-zA-Z ?]+", getStudent->name))
    {
        setCursorPosition(0, 9);
        printf("                                                           ");
        setCursorPosition(0, 9);
        printf("Please Enter a valid input name         : ");
        fflush(stdin);
    }

    fflush(stdin);
    setCursorPosition(0, 10);
    printf("Enter student id                          : ");
    while(1 != scanf("%d", &(getStudent->ID)))
    {
        setCursorPosition(0, 10);
        printf("                                                           ");
        setCursorPosition(0, 10);
        printf("Please Enter a valid input id : ");
        fflush(stdin);
    }

    fflush(stdin);
    setCursorPosition(0, 11);
    printf("Enter student birthday in format dd/mm/yyyy : ");
    while(3 != scanf("%d/%d/%d",&(getStudent->day),&(getStudent->month),&(getStudent->year)))
    {
        setCursorPosition(0, 11);
        printf("                                                           ");
        setCursorPosition(0, 11);
        printf("An Error happened\n");
        getch();
        setCursorPosition(0, 11);
        printf("                                                           ");
        setCursorPosition(0, 11);
        printf("Please Enter student birthday in format dd/mm/yyyy : ");
        fflush(stdin);
    }

    fflush(stdin);
    setCursorPosition(0, 12);
    printf("Enter student score                       : ");
    while(1 != scanf("%d", &(getStudent->score)))
    {
        setCursorPosition(0, 12);
        printf("                                                           ");
        setCursorPosition(0, 12);
        printf("Please Enter a valid input score : ");
        fflush(stdin);
    }
}

void Print(Student* printStudent, int row)
{

    setCursorPosition(0, row);   printf("%d",printStudent->ID);
    setCursorPosition(15, row);  printf("%s",printStudent->name);
    setCursorPosition(45, row);  printf("%d/%d/%d", printStudent->day, printStudent->month, printStudent->year);
    setCursorPosition(60, row);  printf("%d",printStudent->score);
}

void PrintAll( )
{
    int row = 0;

    system("cls");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
    setCursorPosition(0, 0);      printf("ID");
    setCursorPosition(15, 0);     printf("Name");
    setCursorPosition(45, 0);     printf("BirthDay");
    setCursorPosition(60, 0);     printf("Score");

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    if(1 != Choice)
    {
        struct node* temp = head;

        while(NULL != temp)
        {
            Print(&(temp->student), ++row);
            temp = temp->next;
        }
    }
    else
    {
        for(; row < currentNumber; row++)
        {
            Print(&st[row], row + 1);
        }
    }

    getch();
}

void Shift( Student* st1, Student* st2)
{
    strcpy(st2->name, st1->name);
    st2->ID = st1->ID;
    st2->day = st1->day;
    st2->month = st1->month;
    st2->year = st1->year;
    st2->score = st1->score;
}

void InsertAtbeg(  )
{
    if(1 != Choice)
    {
        struct node* add = (struct node*)malloc(sizeof(struct node));

        Get_Info(&(add->student));

        add->next = head;
		if(NULL == head)
            tail = add;
        head = add;
    }
    else
    {
        char i;
        for(i=currentNumber; i>0;i--)
        {
            Shift((st+(i-1)), (st+i));
        }

        Get_Info(st);

        currentNumber++;
    }

    setCursorPosition(0, 13);
    printf("The student is inserted successfully.");

    getch();
}

void InsertAtmid( )
{
    if(1 != Choice)
    {
        if(NULL == head)
        {
            InsertAtbeg();
        }
        else
        {
            struct node* add = (struct node*)malloc(sizeof(struct node));

            Get_Info(&(add->student));

            struct node* slow = head;
            struct node* fast = head->next;

            while(fast != NULL && fast->next != NULL)
            {
                slow=slow->next;
                fast=fast->next->next;
            }
            add->next = slow->next;
            slow->next = add;
        }


    }
    else
    {
        char i;
        for(i=currentNumber; i>(currentNumber/2);i--)
        {
            Shift((st+(i-1)), (st+i));
        }

        Get_Info((st+(currentNumber/2)));

        currentNumber++;
    }

    setCursorPosition(0, 13);
    printf("The student is inserted successfully.");

    getch();
}

void InsertAtlast(  )
{
    if(1 != Choice)
    {

        if(NULL != tail)
        {
            struct node* add = (struct node*)malloc(sizeof(struct node));

            Get_Info(&(add->student));
            add->next = NULL;

            tail->next=add;
            tail=add;
        }
        else
        {
            InsertAtbeg();
        }

    }
    else
    {
        Get_Info((st+currentNumber));

        currentNumber++;
    }

    setCursorPosition(0, 13);
    printf("The student is inserted successfully.");

    getch();
}

void welcome()
{
    setCursorPosition(32, 8);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");

    setCursorPosition(46, 9);
    printf("****Welcome To Our Project.****\n");

    setCursorPosition(32, 10);  printf("Student");
    setCursorPosition(70, 10);  printf("Sec.");
    setCursorPosition(80, 10);  printf("B.N.");

    setCursorPosition(32, 12);  printf("Ahmed Mohammed Hussanein Ali");
    setCursorPosition(70, 12);  printf("1");
    setCursorPosition(80, 12);  printf("15");

    setCursorPosition(32, 11);  printf("Ahmed Mohammoud Hussany");
    setCursorPosition(70, 11);  printf("1");
    setCursorPosition(80, 11);  printf("19");

    setCursorPosition(32, 13);  printf("Osama Ali Mohammed Rashoan");
    setCursorPosition(70, 13);  printf("1");
    setCursorPosition(80, 13);  printf("26");

    setCursorPosition(32, 15);  printf("press any key to continue.");

    setCursorPosition(32, 16);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");

    getch();
}

void choice()
{
    system("cls");

    pointer = 1;
    pressedKey = 0;

    while(1)
    {
        system("cls");

        setCursorPosition(32, 8);
        printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
        printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
        printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");

        setCursorPosition(32, 9);  pointHere(pointer, 0);  printf("Choose Your Data Structure:");
        setCursorPosition(32, 10); pointHere(pointer, 1);  printf("1.Dynamic Array.");
        setCursorPosition(32, 11); pointHere(pointer, 2);  printf("2.Linked List.");

        pointHere(pointer, 0);
        setCursorPosition(32, 12);
        printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
        printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
        printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");


        while(1)
        {
            pressedKey = getch();
            if(pressedKey == 72)
            {
                pointer--;
                if(pointer == 0)
                    pointer = 2;

                break;
            }
            else if(pressedKey == 80)
            {
                pointer++;
                if(pointer == 3)
                    pointer = 1;

                break;
            }
            else if(pressedKey == VK_RETURN)
            {
                Choice = pointer;
                break;
            }
        }
        if(pressedKey == VK_RETURN)
            break;

    }

}

void Options( )
{
    system("cls");

    pointer = 1;
    pressedKey = 0;

    while(1)
    {

        system("cls");

        setCursorPosition(32, 8);
        printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
        printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
        printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");

        setCursorPosition(32, 9);  pointHere(pointer, 0);  printf("What do you want to do?");
        setCursorPosition(32, 10); pointHere(pointer, 1);  printf("1.Insert a student at beginning.");
        setCursorPosition(32, 11); pointHere(pointer, 2);  printf("2.Insert a student at middle.");
        setCursorPosition(32, 12); pointHere(pointer, 3);  printf("3.Insert a student at last.");
        setCursorPosition(32, 13); pointHere(pointer, 4);  printf("4.Print the data base.");
        setCursorPosition(32, 14); pointHere(pointer, 5);  printf("5.Back to the previous menu.");
        setCursorPosition(32, 15); pointHere(pointer, 6);  printf("6.Exit.");

        pointHere(pointer, 0);
        setCursorPosition(32, 16);
        printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
        printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
        printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");


        while(1)
        {
            pressedKey = getch();
            if(pressedKey == 72)
            {
                pointer--;
                if(pointer == 0)
                    pointer = 6;

                break;
            }
            else if(pressedKey == 80)
            {
                pointer++;
                if(pointer == 7)
                    pointer = 1;

                break;
            }
            else if(pressedKey == VK_RETURN)
            {
                switch(pointer)
                {
                case 1:
                    InsertAtbeg();
                    break;

                case 2:
                    InsertAtmid();
                    break;

                case 3:
                    InsertAtlast();
                    break;

                case 4:
                    PrintAll();
                    break;

                case 5:
                    Sleep(500);
                    break;

                case 6:
                    exit(0);
                    break;
                }
            }
            Sleep(100);
            break;
        }
        if (((pointer == 6) || (pointer == 5)) && (pressedKey == VK_RETURN))
            break;

    }
}

int main()
{
    hidecursor();

    st = (Student*)malloc(NumberOfStudent*sizeof(Student));

    welcome();

    while(1)
    {
        choice();
        Options();
        if(pointer == 6)
            break;
    }


    return 0;
}
