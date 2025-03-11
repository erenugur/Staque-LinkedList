#include <iostream>
#include "Staque.h"
using namespace std;

int main() {

    Staque myStaque;
    myStaque.insert(1);
    myStaque.insert(3);
    myStaque.insert(2);
    myStaque.insert(4);
    myStaque.insert(6);
    myStaque.insert(8);
    myStaque.insert(9);

    myStaque.display(cout);

    myStaque.removeEven();
    myStaque.removeEven();
    myStaque.removeOdd();

    myStaque.display(cout);

    return 0;
}
