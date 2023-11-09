#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_EMPLOYEES 1000

//int g_numEmployees = 0; // hard to track where this is accessed exactly



struct employee {
    int id;
    int income;
    bool staff;
};

void initialize_employee(struct employee *e) {
    static int numEmployees = 0; //initializes in global scope but only we have access to it     
    numEmployees++;

    e->id = 0;
    e->income = 0;
    e->staff = false;
}

int main() {
  
    int n = 4;

    struct employee *employees = malloc(sizeof(struct employee)*n);
    if (employees == NULL) {
        printf("The allocator failed\n");
        return -1;
    }

    initialize_employee(&employees[0]);

    printf("%d\n", employees[0].income);
    
    free(employees);
    employees = NULL;

    

}
