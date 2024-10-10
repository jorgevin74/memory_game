#include "MemoryGame.hpp"
#include <iomanip> 


MemoryGame::MemoryGame()
{
    numPairs = 3;
    numSlots = 8;

    values = new string[numSlots];

    for(int i = 0; i < numSlots; i++){
        if(i == 0){
            int randnum = rand() % 1000; 
            values[i] = to_string(randnum);
            values[i+1] = to_string(randnum);
        }

        if(i == 2){
            int randnum = rand() % 1000; 
            values[i] = to_string(randnum);
            values[i + 1] = to_string(randnum);
        }

        if(i == 4){
            int randnum = rand() % 1000; 
            values[i] = to_string(randnum);
            values[i + 1] = to_string(randnum);
        }

        if(i == 6){
            values[i] = "";
            values[i + 1] = "";
        }

    }

    bShown = new bool[numSlots];


    for(int i = 0; i < numSlots; i++){
        bShown[i] = false;
    }


}

MemoryGame::MemoryGame(int numPairs, int numSlots)
{

    if((numPairs <= 0 || numSlots <= 0 ) || numSlots < numPairs*2){

        MemoryGame::numPairs = 3;
        MemoryGame::numSlots = 8;

    }

    else{

        MemoryGame::numPairs = numPairs;
        MemoryGame::numSlots = numSlots;
    }

    values = new string[numSlots];
    for(int i = 0; i < MemoryGame::numPairs; i++){
        int randnum = rand() % 1000; 
        values[2*i] = to_string(randnum);
        values[2*i + 1] = to_string(randnum);
    }

    for(int i = MemoryGame::numSlots - 1; i >= MemoryGame::numPairs*2; i--){
        values[i] = "";
    }

    bShown = new bool[numSlots];


    for(int i = 0; i < numSlots; i++){
        bShown[i] = false;
    }


}

MemoryGame::MemoryGame(string *words, int size, int numSlots)
{

    if((size <= 0 || numSlots <= 0) || numSlots < size*2){
        numSlots = (size * 2);
    }

    MemoryGame::numPairs = size;
    MemoryGame::numSlots = numSlots;

    values = new string[numSlots];

    for(int i = 0; i < MemoryGame::numPairs; i++){
    
        values[2*i] = words[i];
        values[2*i + 1] = words[i];
    }

    for(int i = MemoryGame::numPairs * 2; i < MemoryGame::numPairs*2; i++){
        values[i] = "";
    }

    bShown = new bool[numSlots];

    for(int i = 0; i < numSlots; i++){
        bShown[i] = false;
    }

}


MemoryGame::~MemoryGame(){
    delete[] values;
    values = nullptr;
    delete[] bShown;
    bShown = nullptr;
}

void MemoryGame::play() 
{
    randomize();
    int pairsFound = 0;
    int round = 0;
    while(pairsFound < numPairs){
        round++;
        
    }
}

void MemoryGame::display() const
{
    cout << " ";
    for(int i = 0; i < numSlots; i++){
        cout << setw(3) << i;
        cout << setw(3) << " ";
    }
    cout << endl;
    cout << "+";
    for(int i = 0; i < numSlots; i++){
        cout << "-----+";
    }
    cout << endl;
    cout << "|";
    for(int i = 0; i < numSlots; i++){
        if(bShown[i]){
            cout << setw(5) << values[i] << "|";
        }
        else{
            cout << "     |";
        }
    }
    cout << endl;
    cout << "+";
    for(int i = 0; i < numSlots; i++){
        cout << "-----+";
    }
    cout << endl;
}


void MemoryGame::randomize()
{

    int size = numSlots;

    int randnum;
    
    int lastindex;

    for(int i = size; i > 1; i--){

        randnum = rand() % size;

        lastindex = size - 1;

        swap(values[randnum], values[lastindex]);

        size--;

    }

}

int MemoryGame::input() const
{
    int size = numSlots;
    int lastindex = size - 1;
    int input;
    cout << "Enter a unflipped card in [0, 7]: ";
    cin >> input;
    if(input < 0 || input > 7){
        cout << "input is not in [0, 7]. Re-enter:  "; 
        cin >> input;
    }
    return input;

}

