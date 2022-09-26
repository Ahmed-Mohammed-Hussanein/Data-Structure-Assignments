#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>

#define N 26   // size of array

int Choice = 0; // Open or Closed hashing
// if 1 --> open hashing
// if 2 --> closed hashing

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


struct node* hashTable[N]; // Open Hashing
Student*  cell[N]; //closed Hashing


int pointer = 1;
int pressedKey = 0;

// to hide the cursor
void hidecursor()
{
   HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_CURSOR_INFO info;
   info.dwSize = 100;
   info.bVisible = FALSE;
   SetConsoleCursorInfo(consoleHandle, &info);
}

// to go to definite position
void setCursorPosition(int x, int y)
{
    HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);

    COORD pos = { x, y };
    SetConsoleCursorPosition(output, pos);
}

// to change the text color
void pointHere(int x, int y)
{
    if(x == y)
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);

    else
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}

// to get the information from the user
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

// to print certain student
void Print(Student* printStudent, int row)
{

    setCursorPosition(0, row);   printf("%d",printStudent->ID);
    setCursorPosition(15, row);  printf("%s",printStudent->name);
    setCursorPosition(45, row);  printf("%d/%d/%d", printStudent->day, printStudent->month, printStudent->year);
    setCursorPosition(60, row);  printf("%d",printStudent->score);
}

// to print all students
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
    if(1 == Choice)
    {
        int i;
        for(i=0; i<N; i++)
        {
            struct node* temp = hashTable[i];

            while(temp)
            {
                Print(&(temp->student), ++row);
                temp = temp->next;
            }
        }
    }
    else
    {
        int i;
        for(i=0; i<N; i++)
        {
            Student* temp = cell[i];

            if(temp)
            {
                Print((temp), ++row);
            }
        }
    }


    getch();
}

// to initializing the arrays
void Init()
{
    int i;
    for(i=0; i<N; i++)
        hashTable[i] = NULL;

    for(i=0; i<N; i++)
        cell[i] = NULL;
}

// to compute the key
int hashKey(int hash)
{
    return hash%N;
}

// to insert a student
void Insert()
{
    if(Choice == 1)
    {
        struct node* add = (struct node*)malloc(sizeof(struct node));

        Get_Info(&(add->student));
        add->next = NULL;

        int key = hashKey((int)(add->student.name[0]));
        struct node* temp = hashTable[key];

        if(NULL == temp)
        {
            temp = add;
            hashTable[key]=temp;
        }
        else
        {
            while((temp->next))
                temp = (temp->next);

            (temp->next) = add;
        }
        printf("Inserted Successfully.");
        getch();
    }
    else
    {
        Student* add = (Student*)malloc(sizeof(Student));

        Get_Info(add);
        int key = hashKey(add->day + add->month + add->year);
        if(NULL == cell[key])
        {
            cell[key] = add;
        }
        else
        {
            key++;
            while(NULL == cell[key])
                {
                    key++;
                    if(key == N)
                        {
                            printf("unable to insert.");
                            break;
                        }
                }

            if(key != N)
            {
                cell[key] = add;
                printf("Inserted Successfully.");
                getch();
            }
        }
    }

}

// to delete a student
void Delete()
{
    if(Choice == 1)
    {
        system("cls");
        char name[50];
        fflush(stdin);
        setCursorPosition(0, 9);
        printf("Enter student name                          : ");
        while(1 != scanf("%[a-zA-Z ?]+", name))
        {
            setCursorPosition(0, 9);
            printf("                                                           ");
            setCursorPosition(0, 9);
            printf("Please Enter a valid input name         : ");
            fflush(stdin);
        }

        int key= hashKey((int)(name[0]));
        struct node* deleted = hashTable[key];

        if(NULL != deleted)
        {
            if(!strcmp(deleted->student.name, name))
            {
                hashTable[key] = hashTable[key]->next;
                free(deleted);
                printf("The student is deleted.");
            }

            else
            {
                deleted = deleted->next;
                struct node* pre = hashTable[key];

                while(!strcmp(deleted->student.name, name))
                {
                    deleted = deleted->next;
                    if(NULL == (deleted))
                    {
                        printf("The student is not exist.\n");
                        break;
                    }
                    pre = pre->next;
                }

                if(NULL != (deleted))
                {
                    pre->next = deleted->next;
                    free(deleted);
                    printf("The student is deleted.");
                }
            }
        }
        else
        {
            printf("The student is not exist.\n");
        }

        getch();
    }
    else
    {
        system("cls");
        int day,month,year;
        fflush(stdin);
        setCursorPosition(0, 11);
        printf("Enter student birthday in format dd/mm/yyyy : ");
        while(3 != scanf("%d/%d/%d",&(day),&(month),&(year)))
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

        Student* temp = NULL;
        int key = hashKey(day + month + year);
        while(cell[key] != NULL)
        {
            temp = cell[key];
            if((temp->day == day) && (temp->month == month) && (temp->year == year))
            {
                break;
            }
            else
                key++;

        }
        if(cell[key] == NULL)
            printf("Not Found.");

        else
        {
            free(temp);
            cell[key] = NULL;
            printf("Deleted.");
        }
        getch();

    }

}

// to search foe a student
void Find()
{
    if(Choice == 1)
    {
        system("cls");
        char name[50];
        fflush(stdin);
        setCursorPosition(0, 9);
        printf("Enter student name                          : ");
        while(1 != scanf("%[a-zA-Z ?]+", name))
        {
            setCursorPosition(0, 9);
            printf("                                                           ");
            setCursorPosition(0, 9);
            printf("Please Enter a valid input name         : ");
            fflush(stdin);
        }

        int key = hashKey((int)(name[0]));
        struct node* findName = hashTable[key];

        while(findName)
        {
            if(!strcmp(findName->student.name,name))
                break;

            findName = findName->next;

        }
        if(NULL != (findName))
        {
            system("cls");
            Print(&(findName->student),0);
        }
        else if(NULL == findName)
        {
            printf("The Name You Entered Is Not Exist.\n");
        }
        getch();

    }
    else
    {
        system("cls");
        int day,month,year;
        fflush(stdin);
        setCursorPosition(0, 11);
        printf("Enter student birthday in format dd/mm/yyyy : ");
        while(3 != scanf("%d/%d/%d",&(day),&(month),&(year)))
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

        int key = hashKey(day + month + year);
        while(cell[key] != NULL)
        {
            Student* temp = cell[key];
            if((temp->day == day) && (temp->month == month) && (temp->year == year))
            {
                Print(temp, 0);
                break;
            }
            else
                key++;

        }
        if(cell[key] == NULL)
            printf("Not Found.");

        getch();

    }
}

void welcome()
{
    setCursorPosition(32, 8);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");

    setCursorPosition(46, 9);
    printf("*Welcome To Our Project.*\n");

    setCursorPosition(32, 10);  printf("Student");
    setCursorPosition(70, 10);  printf("Sec.");
    setCursorPosition(80, 10);  printf("B.N.");

    setCursorPosition(32, 11);  printf("Ahmed Mohammed Hussanein Ali");
    setCursorPosition(70, 11);  printf("1");
    setCursorPosition(80, 11);  printf("15");

    setCursorPosition(32, 12);  printf("Ahmed Mohammoud Hussany");
    setCursorPosition(70, 12);  printf("1");
    setCursorPosition(80, 12);  printf("19");

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

 // to choose open or closed
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
        setCursorPosition(32, 10); pointHere(pointer, 1);  printf("1.Open Hashing.");
        setCursorPosition(32, 11); pointHere(pointer, 2);  printf("2.Closed Hashing(Linear probing).");

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

// to choose insert, find or delete
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
        setCursorPosition(32, 10); pointHere(pointer, 1);  printf("1.Insert a student.");
        setCursorPosition(32, 11); pointHere(pointer, 2);  printf("2.Find a student.");
        setCursorPosition(32, 12); pointHere(pointer, 3);  printf("3.Delete a student.");
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
                    Insert();
                    break;

                case 2:
                    Find();
                    break;

                case 3:
                    Delete();
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
