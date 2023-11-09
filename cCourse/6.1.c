#include <stdio.h>
#include <stdbool.h>
#define MAX_IDS 32
#define MAX_EMPLOYEES 64

struct employee {
    int id;
    char firstName[64];
    char lastName[64];
    float income;
    bool ismanager;
};

int main() {
    
    //int my_ids[MAX_IDS];

    //float income;
    //char name[64];
    
    struct employee Fred;
    Fred.income = 100.00;
    Fred.ismanager = true;

    struct employee employees[MAX_EMPLOYEES];
    int i = 0;
    for (i = 0; i < MAX_EMPLOYEES; i++) {
        employees[i].income = 0;
        employees[i].ismanager = false;
    }

    printf("%f", employees[10].income);


}
