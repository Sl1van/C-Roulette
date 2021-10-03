#include <iostream>
#include <string>
#include <math.h>
#include <cmath>
#include <climits>
#include <time.h>

int calcWinnings(int amountOfZeros, int budget, int initialWager, int seed){
    int wager = initialWager;
    int initalBudget = budget;

    srand (seed);

    for (unsigned int i = 0; i<1000; i++)
    {
        if(budget-wager<0 ){
            break;
        }
        if (((double)rand() / RAND_MAX * (36.00 + amountOfZeros)) <= 18.00)
        {
            //user won
            budget += wager;
            wager = initialWager;
        }
        else
        {
            budget -= wager;
            wager = wager*2;
        }
    }
    return budget - initalBudget;
}


int main()
{
    int amountOfZeros = 2;
    int budget = 5000;
    int initialWager = 15;
    int dataSetSize = 100;

    std::cout << "Starting simulation with the following values: ";
    std::cout  << "amountOfZeros: " << amountOfZeros << ", budget: " <<budget << ", initialWager: " << initialWager << "\n";

    int winnings = 0;
    int seed = time ( NULL);
    for(int i ; i<dataSetSize;i++){
        int currentWinnings = calcWinnings(amountOfZeros, budget, initialWager, seed);
        seed = (currentWinnings *23 % 13) * winnings;
        winnings += currentWinnings;
    }
    std::cout << "Money gained/lost: " << winnings << "\n";
    std::cout << "Money gained/lost per round: " << winnings/dataSetSize << "\n";
}
