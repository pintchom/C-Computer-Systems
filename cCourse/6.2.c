#include <stdio.h>
#include <stdbool.h>

#define MAX_EMPLOYEES 1000

struct employee {
    int id;
    char firstName[64];
    char lastName[64];
    float income;
    bool ismanager;
};

union myunion { // Only creates room for the biggest element that grants access to all other elements of the union 
    int x;
    char c;
    short s;
};

int main() {
    struct employee exmployees[MAX_EMPLOYEES];

    union myunion u;
    u.x = 0x41424344;
    printf("%hx %hhx\n", u.s, u.c);
}
