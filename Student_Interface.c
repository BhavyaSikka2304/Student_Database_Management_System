#include<stdio.h>
#include"Structure_studentInterface.c"
#include<string.h>
#include<stdlib.h>

#define MAX_STUDENTS 1000
#define MAX_STRING_LENGTH 100


int var = 0;
struct student_info t[MAX_STUDENTS];
struct student_info z[MAX_STUDENTS];

// Function to save student records to a text file

void saveStudentRecords(const char *filename)
{
    FILE *file = fopen("storage.txt", "w");
    if (file == NULL)
    {
        printf("Error opening file for writing.\n");
        return;
    }

    for (int i = 0; i < var; i++)
    {
        struct student_info student = t[i];
        fprintf(file, "%ld %s %s %d %d %d %d %d %s %s %s %s %ld %ld\n",
                student.student_id, student.first_name, student.last_name,student.rollno,
                student.date, student.month, student.year,
                student.house_number, student.area, student.city,
                student.father_firstname, student.father_lastname,
                student.student_phoneno, student.father_phoneno);
    }

    fclose(file);
    printf("Student records saved to %s\n", filename);
    printf("\n");
}

// Function to load student records from a text file
void loadStudentRecords(const char *filename)
{
    FILE *file = fopen("storage.txt", "r");
    if (file == NULL)
    {
        printf("Error opening file for reading.\n");
        return;
    }

    // int s=0;


    var = 0; // Reset the count of student records

    while (fscanf(file, "%ld", &t[var].student_id) != EOF)
    {
        t[var].first_name = (char *)malloc(MAX_STRING_LENGTH * sizeof(char));
        t[var].last_name = (char *)malloc(MAX_STRING_LENGTH * sizeof(char));
        t[var].area = (char *)malloc(MAX_STRING_LENGTH * sizeof(char));
        t[var].city = (char *)malloc(MAX_STRING_LENGTH * sizeof(char));
        t[var].father_firstname = (char *)malloc(MAX_STRING_LENGTH * sizeof(char));
        t[var].father_lastname = (char *)malloc(MAX_STRING_LENGTH * sizeof(char));

        fscanf(file, "%s %s %d %d %d %d %d %s %s %s %s %ld %ld",
               t[var].first_name, t[var].last_name,&t[var].rollno,
               &t[var].date, &t[var].month, &t[var].year,
               &t[var].house_number, t[var].area, t[var].city,
               t[var].father_firstname, t[var].father_lastname,
               &t[var].student_phoneno, &t[var].father_phoneno);

        var++;
    }

    fclose(file);
    printf("Student records loaded from %s\n", filename);
    printf("\n");
}

void addstudents()
{
    struct student_info newStudent;
    // Allocate memory for strings
    newStudent.first_name = (char *)malloc(MAX_STRING_LENGTH * sizeof(char));
    newStudent.last_name = (char *)malloc(MAX_STRING_LENGTH * sizeof(char));
    newStudent.area = (char *)malloc(MAX_STRING_LENGTH * sizeof(char));
    newStudent.city = (char *)malloc(MAX_STRING_LENGTH * sizeof(char));
    newStudent.father_firstname = (char *)malloc(MAX_STRING_LENGTH * sizeof(char));
    newStudent.father_lastname = (char *)malloc(MAX_STRING_LENGTH * sizeof(char));

    //take all inputs
    printf("Enter Student ID\n");
    scanf("%ld", &newStudent.student_id);
    printf("\n");
    printf("Enter the First Name of the Student\n");
    scanf("%s", newStudent.first_name);
    printf("\n");
    printf("Enter the Last Name of the Student\n");
    scanf("%s", newStudent.last_name);
    printf("\n");
    printf("Enter the roll number\n");
    scanf("%d",&newStudent.rollno);
    printf("Enter the date of birth\n");
    printf("Enter the date\n");
    scanf("%d", &newStudent.date);
    printf("\n");
    printf("Enter the month\n");
    scanf("%d", &newStudent.month);
    printf("\n");
    printf("Enter the year\n");
    scanf("%d", &newStudent.year);
    printf("\n");
    printf("Enter the address\n");
    printf("Enter the house/flat number\n");
    scanf("%d", &newStudent.house_number);
    printf("\n");
    printf("Enter the Local Area\n");
    scanf("%s", newStudent.area);
    printf("\n");
    printf("Enter the state/city\n");
    scanf("%s", newStudent.city);
    printf("\n");
    printf("Enter father's first name\n");
    scanf("%s", newStudent.father_firstname);
    printf("\n");
    printf("Enter father's last name\n");
    scanf("%s", newStudent.father_lastname);
    printf("\n");
    printf("Enter Student phone number\n");
    scanf("%ld", &newStudent.student_phoneno);
    printf("\n");
    printf("Enter father's phone number\n");
    scanf("%ld", &newStudent.father_phoneno);
    printf("\n");
    printf("\n");
    printf("Record successfully added\n");
    printf("-------------------------------------------------------\n");

    t[var] = newStudent;
    var++;
}

void searchselectedstudents()
{
    struct student_info newStudent;
    int a, b;
    printf("Enter the range's starting number");
    scanf("%d", &a);
    printf("Enter the range's last number");
    scanf("%d", &b);
    for (int i = a - 1; i < b ; i++)
    {
        newStudent = t[i];
        printf("Student Information\n");
        printf("\n");
        printf("Student ID:%ld\n", newStudent.student_id);
        printf("First Name of the Student:%s\n", newStudent.first_name);
        printf("Last Name of the Student:%s\n", newStudent.last_name);
        printf("Roll Number of the Student:%d\n",newStudent.rollno);
        printf("Date of birth:%d-%d-%d\n", newStudent.date, newStudent.month, newStudent.year);
        printf("Address:%d,%s,%s\n", newStudent.house_number, newStudent.area, newStudent.city);
        printf("Father's first name: %s\n", newStudent.father_firstname);
        printf("Father's last name: %s\n", newStudent.father_lastname);
        printf("Student phone number:%ld\n", newStudent.student_phoneno);
        printf("Father's phone number:%ld\n", newStudent.father_phoneno);
        printf("-------------------------------------------------------\n");

        printf("\n");
        printf("\n");
    }
}

void deleteStudentRecord()
{
    struct student_info newStudent;
    long int id;
    printf("Enter the Student ID that you want to delete\n");  
    scanf("%ld", &id);
    char temp[100];
    for (int i = 0; i < var; i++)
    {
        if (t[i].student_id == id)
        {
            for(int j=i;j<var;j++){
                t[i]=t[i+1];

            }
            var--;
            saveStudentRecords("storage.txt");

            printf("Record is deleted\n");
            printf("-------------------------------------------------------\n");
            printf("\n");
            printf("\n");
            return;
        }
        
    }
    printf("Record does not exist\n");
    printf("-------------------------------------------------------\n");
    printf("\n");
    printf("\n");
}

void displayallstudents()
{
    struct student_info newStudent;
    for (int i = 0; i < var; i++)
    {
        newStudent = t[i];

        printf("Student Information\n");
        printf("Student ID:%ld\n", newStudent.student_id);
        printf("First Name of the Student:%s\n", newStudent.first_name);
        printf("Last Name of the Student:%s\n", newStudent.last_name);
        printf("Roll Number of the Student:%d\n",newStudent.rollno);
        printf("Date of birth:%d-%d-%d\n", newStudent.date, newStudent.month, newStudent.year);
        printf("Address:%d,%s,%s\n", newStudent.house_number, newStudent.area, newStudent.city);
        printf("Father's first name: %s\n", newStudent.father_firstname);
        printf("Father's last name: %s\n", newStudent.father_lastname);
        printf("Student phone number:%ld\n", newStudent.student_phoneno);
        printf("Father's phone number:%ld\n", newStudent.father_phoneno);
        printf("-------------------------------------------------------\n");

        printf("\n");
        printf("\n");
    }
}

void modify()
{
    struct student_info newStudent;
    long int id;
    printf("Enter the Student ID that you want to modify\n");
    scanf("%ld", &id);
    for (int i = 0; i < var; i++)
    {
        if (t[i].student_id == id)
        {
            printf("What do you want to modify\n");
            printf("1. First name\n");
            printf("2. Last name\n");
            printf("3. Roll Number");
            printf("4. Date\n");
            printf("5. Month\n");
            printf("6. Year\n");
            printf("7. House Number/Flat Number\n");
            printf("8. Area\n");
            printf("9. City\n");
            printf("10. Father's first name\n");
            printf("11. Father's last name\n");
            printf("12. Student's phone number\n");
            printf("13. Father's phone number\n");
            printf("14. Go to main menu\n");
            printf("-------------------------------------------------------\n");
            printf("\n");

            int x;
            printf("Enter the number that you want to edit\n");
            printf("Choice(1/2/3/4/5/6/7/8/9/10/11/12/13/14): ");
            scanf("%d", &x);

            switch (x)
            {
            case 1:
                printf("Enter new First name:\n");
                char new_fname[MAX_STRING_LENGTH];
                scanf("%s", new_fname);
                strcpy(t[i].first_name, new_fname);
                printf("Name modified\n");
                printf("-------------------------------------------------------\n");
                printf("\n");
                printf("\n");
                break;

            case 2:
                printf("Enter new Last Name:\n");
                char new_lname[MAX_STRING_LENGTH];
                scanf("%s", new_lname);
                strcpy(t[i].last_name, new_lname);
                printf("Last Name modified\n");
                printf("-------------------------------------------------------\n");
                printf("\n");
                printf("\n");
                break;



            case 3:
                printf("Enter new roll number\n");
                int nrollnumber;
                scanf("%d",&nrollnumber);
                t[i].rollno=nrollnumber;
                printf("Roll number modified\n");
                printf("-------------------------------------------------------\n");
                printf("\n");
                printf("\n");
                break;

            case 4:
                printf("Enter new date\n");
                int Ndate;
                scanf("%d", &Ndate);
                t[i].date = Ndate;
                printf("Date modified\n");
                printf("-------------------------------------------------------\n");
                printf("\n");
                printf("\n");
                break;

            case 5:
                printf("Enter new month\n");
                int nmonth;
                scanf("%d", &nmonth);
                t[i].month = nmonth;
                printf("Month modified\n");
                printf("-------------------------------------------------------\n");
                printf("\n");
                printf("\n");
                break;

            case 6:
                printf("Enter new year\n");
                int nyear;
                scanf("%d", &nyear);
                t[i].year = nyear;
                printf("Year modified\n");
                printf("-------------------------------------------------------\n");
                printf("\n");
                printf("\n");
                break;

            case 7:
                printf("Enter new house number\n");
                int nhouse;
                scanf("%d", &nhouse);
                t[i].house_number = nhouse;
                printf("House number modified\n");
                printf("-------------------------------------------------------\n");
                printf("\n");
                printf("\n");
                break;

            case 8:
                printf("Enter new area\n");
                char newArea[MAX_STRING_LENGTH];
                scanf("%s", newArea);
                strcpy(t[i].area, newArea);
                printf("Area modified\n");
                printf("-------------------------------------------------------\n");
                printf("\n");
                printf("\n");
                break;

            case 9:
                printf("Enter new city\n");
                char newCity[MAX_STRING_LENGTH];
                scanf("%s", newCity);
                strcpy(t[i].city, newCity);
                printf("City modified\n");
                printf("-------------------------------------------------------\n");
                printf("\n");
                printf("\n");
                break;

            case 10:
                printf("Enter new father's first name\n");
                char fatherfname[MAX_STRING_LENGTH];
                scanf("%s", fatherfname);
                strcpy(t[i].father_firstname, fatherfname);
                printf("Father's first name is modified\n");
                printf("-------------------------------------------------------\n");
                printf("\n");
                printf("\n");
                break;

            case 11:
                printf("Enter new father's last name\n");
                char fatherlname[MAX_STRING_LENGTH];
                scanf("%s", fatherlname);
                strcpy(t[i].father_lastname, fatherlname);
                printf("Father's last name is modified\n");
                printf("-------------------------------------------------------\n");
                printf("\n");
                printf("\n");
                break;

            case 12:
                printf("Enter student's new phone number\n");
                long int new_phonestudent;
                scanf("%ld", &new_phonestudent);
                t[i].student_phoneno = new_phonestudent;
                printf("Number modified\n");
                printf("-------------------------------------------------------\n");
                printf("\n");
                printf("\n");
                break;

            case 13:
                printf("Enter father's new phone number\n");
                long int new_fphone;
                scanf("%ld", &new_fphone);
                t[i].father_phoneno = new_fphone;
                printf("Number modified\n");
                printf("-------------------------------------------------------\n");
                printf("\n");
                printf("\n");
                break;

            case 14:
                return;
            default:
                printf("Enter the right choice\n");
                printf("-------------------------------------------------------\n");
                printf("\n");
                break;
            }
            saveStudentRecords("storage.txt");
        }
    }printf("No student with student id=%ld\n",id);
    printf("-------------------------------------------------------\n");
    printf("\n");

}

void searchstudentrecord()
{
    struct student_info newStudent;
    long int a;
    printf("Enter student id\n"); //5
    scanf("%ld", &a);
    // int *var;

    for (int i = 0; i < var; i++)
    {
        if (t[i].student_id == a)
        {
            newStudent = t[i];
            printf("Student Information:\n");
            printf("Student ID:%ld\n", newStudent.student_id);
            printf("First Name of the Student:%s\n", newStudent.first_name);
            printf("Last Name of the Student:%s\n", newStudent.last_name);
            printf("Roll Number of the Student:%d\n",newStudent.rollno);
            printf("Date of birth:%d-%d-%d\n", newStudent.date, newStudent.month, newStudent.year);
            printf("Address:%d,%s,%s\n", newStudent.house_number, newStudent.area, newStudent.city);
            printf("Father's first name: %s\n", newStudent.father_firstname);
            printf("Father's last name: %s\n", newStudent.father_lastname);
            printf("Student phone number:%ld\n", newStudent.student_phoneno);
            printf("Father's phone number:%ld\n", newStudent.father_phoneno);
            printf("-------------------------------------------------------\n");
            printf("\n");
            printf("\n");

            return;
        }
        
    
        
    }
    printf("There is no student with this Student_ID=%ld\n", a);
    printf("-------------------------------------------------------\n");
    printf("\n");
    printf("\n");
    return;
}

int main()
{
    while (1)
    {
        printf("\n");
        printf("Menu\n");
        printf("1. Create student record\n");
        printf("2. Search student record\n");
        printf("3. Display all student records\n");
        printf("4. Delete student record\n");
        printf("5. Modify record\n");
        printf("6. Enter specific record\n");
        // printf("7. Save student records to a file\n");
        printf("8. Load student records from a file\n");
        printf("9. Exit\n");
        printf("Enter your choice(1/2/3/4/5/6/7/8/9): ");

        int b;
        scanf("%d", &b);

        switch (b)
        {
        case 1:
            addstudents();
            break;

        case 2:
            searchstudentrecord();
            break;

        case 3:
            displayallstudents();
            break;

        case 4:
            deleteStudentRecord();
            break;

        case 5:
            modify();
            break;

        case 6:
            searchselectedstudents();
            break;

        case 7:
            saveStudentRecords("storage.txt");
            break;

        case 8:
            loadStudentRecords("storage.txt");
            break;

        case 9:
            exit(0);
        default:
            printf("Please enter the right option\n");
        }
    }
    return 0;
}
