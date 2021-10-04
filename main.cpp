#include <iostream>
#include <string>
#include <math.h>
#include <cmath>
#include <climits>
#include <time.h>
#include <random>
using namespace std;

int calcWinnings(int amountOfZeros, int budget, int initialWager)
{
    int wager = initialWager;
    int initalBudget = budget;

    // Random seed
    static random_device rd;

    // Initialize Mersenne Twister pseudo-random number generator
    static mt19937 gen(rd());

    // Generate pseudo-random numbers
    // uniformly distributed in range (1, 100)
    uniform_int_distribution<> dis(1, 36.00 + amountOfZeros);

    for (unsigned int i = 0; i<1000; i++)
    {
        if(budget-wager<0 )
        {
            break;
        }
        int winningNumber = dis(gen);
        if (winningNumber <= 18.00)
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
    srand(time(NULL));

    int amountOfZeros = 2;
    int budget = 5000;
    int initialWager = 15;
    int dataSetSize = 100000;

    std::cout << "Starting simulation with the following values: ";
    std::cout  << "dataSetSize: " << dataSetSize << ", amountOfZeros: " << amountOfZeros << ", budget: " <<budget << ", initialWager: " << initialWager << "\n";

    int winnings = 0;
    for(int i = 0; i<dataSetSize; i++)
    {
        int currentWinnings = calcWinnings(amountOfZeros, budget, initialWager);
        winnings += currentWinnings;
    }
    std::cout << "Money gained/lost: " << winnings << "\n";
    std::cout << "Money gained/lost per round: " << winnings/dataSetSize << "\n";
}
