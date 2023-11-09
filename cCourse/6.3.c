#include <stdio.h>
#include <stdbool.h>

#define MAX_EMPLOYEES 1000

__attribute__((__packed__))struct employee {
    int id;
    char firstName[64];
    char lastName[64];
    float income;
    bool ismanager;
};

int main() {
    stuct employee exmployees[MAX_EMPLOYEES];

    
}

