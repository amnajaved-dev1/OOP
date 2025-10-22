// DBMS of EMPLYEES.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMPLOYEES 100
#define MAX_NAME_LENGTH 50

struct Employee {
    int employeeID;
    char name[MAX_NAME_LENGTH];
    float salary;
};

void addEmployee(struct Employee employees[], int* count) {
    if (*count >= MAX_EMPLOYEES) {
        printf("Database is full. Cannot add more employees.\n");
        return;
    }

    printf("Enter employee ID: ");
    scanf_s("%d", &employees[*count].employeeID);

    printf("Enter employee name: ");
    scanf_s("%s", employees[*count].name, (unsigned)_countof(employees[*count].name));

    printf("Enter employee salary: ");
    scanf_s("%f", &employees[*count].salary);

    (*count)++;
}

void displayEmployees(struct Employee employees[], int count) {
    printf("Employee details in the database:\n");
    printf("ID\tName\t\tSalary\n");
    for (int i = 0; i < count; ++i) {
        printf("%d\t%s\t\t%.2f\n", employees[i].employeeID, employees[i].name, employees[i].salary);
    }
}

void saveEmployeesToFile(struct Employee employees[], int count, const char* filename) {
    FILE* file;
    if (fopen_s(&file, filename, "w") != 0) {
        printf("Error opening file for writing.\n");
        return;
    }

    for (int i = 0; i < count; ++i) {
        fprintf(file, "%d,%s,%.2f\n", employees[i].employeeID, employees[i].name, employees[i].salary);
    }

    fclose(file);
    printf("Employee data saved to %s successfully.\n", filename);
}

int main() {
    struct Employee employees[MAX_EMPLOYEES];
    int count = 0;
    char filename[] = "employee_database.txt"; // Change this filename if needed

    int choice;
    do {
        printf("\nEmployee Database Management System\n");
        printf("1. Add an employee\n");
        printf("2. Display all employees\n");
        printf("3. Save employees to file\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf_s("%d", &choice);

        switch (choice) {
        case 1:
            addEmployee(employees, &count);
            break;
        case 2:
            displayEmployees(employees, count);
            break;
        case 3:
            saveEmployeesToFile(employees, count, filename);
            break;
        case 4:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file