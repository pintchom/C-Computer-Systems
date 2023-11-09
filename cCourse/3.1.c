#include <stdio.h>

//Global Scope
//
int g_numPersons = 0;

void other_func() {
    int personId = 1;
}

int main() {
    // type name = initial value;
    int personId = 0;

    personId += 1;
    {
        int personId = 0;
        personId += 1;
    }
}
