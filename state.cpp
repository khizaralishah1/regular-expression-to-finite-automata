#include "state.h"
#include <iomanip>
#include <iostream>
using namespace std;

int state::count = 1; // static member must be initialized. However, in newer compilers/c++ versions it is automatically initialized to 0.

state::state()
{
    name = count++;
    readA = readB = nullptr;
    nextStateInOrder = nullptr;
    isFinalState = false;
}

void state::operator=(state* s)
{
    name = s->name;
    readA = s->readA;
    readB = s->readB;
    // nextStateInOrder 
}

void state::setReadA(state *s)
{
    readA = s;
}

void state::setReadB(state *s)
{
    readB = s;
}

void state::setAsFinal()
{
    isFinalState = true;
}

bool state::getFinal()
{
    return isFinalState;
}

void state::setNexStateInOrder(state *s)
{
    nextStateInOrder = s;
}

state *state::getNextStateInOrder()
{
    return nextStateInOrder;
}

void state::printState()
{
    if(isFinalState)
        cout << setw(9) << "+" << name;
    else
        cout << setw(10) << name;

    if(readA != nullptr) 
        cout << setw(10) << readA->name;
    else 
        cout << setw(10) << "dead";

    if(readB != nullptr) 
        cout << setw(10) << readB->name;
    else 
        cout << setw(10) << "dead";

    cout << endl;
}