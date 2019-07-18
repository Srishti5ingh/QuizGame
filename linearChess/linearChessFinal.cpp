#include<bits/stdc++.h>
using namespace std;

#define MAX_MOVES 4
char startMoves[MAX_MOVES+1];
char finishMoves[MAX_MOVES+1];
char startc[MAX_MOVES+1];

//template<int MAX_MOVES>

bool validInput(char* str)
{
    for (int i=0; i<MAX_MOVES; i++)
    {
        if (str[i] == 'L' || str[i] == 'R' || str[i] == '-' || str[i] == '\0')
        return true;
        else
        return false;
        
    }
   
}

void calcMoves(char* start)
{
    strcpy(startc, start);
    for (int i=0; i<MAX_MOVES; i++)
    {
        if (startc[i] == 'R' && startc[i+1] == '-')
        {
            startc[i] = '-';
            startc[i+1] = 'R';
        }
        else
        {
            //start[i] == start[i];
        }
        
    }
    
     for (int i=0; i<MAX_MOVES; i++)
    {
        if (startc[i] == 'R' && startc[i+1] == '-')
        {
            startc[i] = '-';
            startc[i+1] = 'R';
        }
        else
        {
            //start[i] == start[i];
        }
    }
  
}
        

void compareMoves (char* startc, char* finish)
{
    if(strcmp(startc, finish) == 0)
    cout << "True" << endl;
    else
    cout << "False" <<endl;
}


int main()
{
    
    cout << "Enter start moves" <<endl;
    for (int i=0; i<MAX_MOVES; i++)
    {
          cin>> startMoves[i];
          
        }
        
        if(validInput(startMoves)){
           calcMoves(startMoves);
            
        }
            
        else{
            cout<< "Invalid start moves"<<endl;
            exit(0);
        }
            
        
    cout << "Enter finish moves" <<endl;
    for (int i=0; i<MAX_MOVES; i++)
    {
          cin>> finishMoves[i];
          
        }
    if(validInput(finishMoves)){
        //cout<< "valid input";
        compareMoves(startc, finishMoves);
    }
    else
    {
        cout <<"Invalid finish moves"<<endl;
    }
    
    return 0;
}
    