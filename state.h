//#pragma once
#include <iostream>
using namespace std;

class state
{
private:
    int name;                                                                    // name of the state, say 1, 2, 3, etc
    bool isFinalState;                                                   //every state will have either false or true
    state *readA, *readB;                                            // address of next state to go to when a or b is read
    state *nextStateInOrder;                                            // keeps track of next states in terms of their count, from 1 to 2, to 3, and so on.
    static int count;                                                        // it will count the total number of states in the state, will increment by 1 every time a state is created, it will be used to set the name of each state like 1, 2, 3, 4, and so on. Start state will be named as 1.

public:
    state();
    void operator=(state* s);
    void setReadA(state*);
    void setReadB(state*);
    void setAsFinal();
    bool getFinal();
    void setNexStateInOrder(state*);
    void printState();
    state* getNextStateInOrder();
};