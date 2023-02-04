#include "fa.h"
#include <iomanip>
#include <iostream>
using namespace std;

void fa::createFiniteAutomata(string regularExpression)
{
    int len = regularExpression.length();

                                                            //taking care of all the invalid cases.
    if(len == 0)                                            // regular expression with no length will have no FA
        return;
    else if(regularExpression[0] == '*')                                    // the kleene star/closure symbol cannot come as the first symbol. So RE is invalid if it does.
        return;

    char lastRead = '-';                                    // dummy character. To keep last one so that we can read the next one, and decide what will happen in the FA regarding the last character depending on what the next character is. If next is a different character, then last one will lead to a new state, otherwise if next on is kleene closure symbol * then that last charater will make the loop on that state

    start = new state;
    currentState = start;

    for(int i=0; i<len; ++i)
    {
        if(regularExpression[i] == ' ')
        {
            continue;
        }
        else if(regularExpression[i] == '+')                                                                            //creating FA3 when we already have FA1 and FA2
        {
            
        }
        else if(regularExpression[i] == '*')
        {   
            // will create a loop
            if(lastRead == 'a')
            {
                currentState->setReadA(currentState); 
            }
            else
            {
                currentState->setReadB(currentState);
            }
            lastRead = '-';
        }
        else if(regularExpression[i] != '(')                                                                                // taking care of the input alphabets either (a, b) or (1, 0)
        {
            if(lastRead != '-')
            {
                state* newState = new state;

                if(lastRead == 'a')
                {
                    currentState->setReadA(newState);
                }
                else
                {
                    currentState->setReadB(newState);
                }

                currentState->setNexStateInOrder(newState);
                currentState = newState;
            }

            lastRead = regularExpression[i];
        }
        else if(regularExpression[i] == '(')
        {
            state* brackStart = new state();
            brackStart = currentState;
            //currentState;
        }
    }

    currentState->setAsFinal();
};

void fa::printTransitionTable()
{
    cout << setw(10) << "STATE" << setw(10) << "a" << setw(10) << "b" << endl;

    state* temp = start;
    while(temp != nullptr)
    {
        temp->printState();
        temp = temp->getNextStateInOrder();
    }
}

