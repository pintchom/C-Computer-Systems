#include <stdio.h>
#include <stdbool.h>
struct employee {
    int id;
    int income;
    bool staff;
};

void initialize_employee(struct employee *e) {
    e->id = 0;
    e->income = 0;
    e->staff = false;
}

int main() {
    
    // a pointer is a value that happens to be an address 
    
    //int x = 3; // makes rooms in the stack at its address 
               
    //int *pX = &x; // create int pointer pX that sets its value to the address of X
                  
    //printf("%d\n", *pX);
    //printf("%p\n", pX);   
    //

    struct employee Ralph;
    initialize_employee(&Ralph);

    printf("%d\n", Ralph.income);
}
