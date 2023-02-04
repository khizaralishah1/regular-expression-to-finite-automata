//#pragma once
#include "state.h"
#include <iostream>
using namespace std;

class fa                                                                                    // is a 5-tuple containing input alphabet, start state, transition functions, final state(s)
{
private:
    state* start;                                                                           //start state. it is a single one, and is not a member of any other state and is unique
    state* bracketStartStateHead;
    bool isFinal;
    
    state* currentState;                                                                        // keep track of which state on which we are currently reading the RE.
    public:
    fa(): start(nullptr), currentState(nullptr), bracketStartStateHead(nullptr) { }                     //compiler will initialize it because of member initializer list usage. If start = nullptr is written inside the {} paranthesis then will will assign nullptr to start, that is the assignment, not the initialization. 
    void createFiniteAutomata(string);                                                      //takes RE as an argument and create an FA that accepts/recognizes the language represented by that RE
    void printTransitionTable();
};