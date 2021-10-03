#include <iostream>
#include <string>
#include <math.h>
#include <cmath>
#include <climits>
#include <time.h>

int calcWinnings(int amountOfZeros, int budget, int initialWager){
    int wager = initialWager;

    srand ( time ( NULL));

    for (unsigned int i = 0; i<1000; i++)
    {
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
        std::cout << "Budget: ";
        std::cout << budget;
        std::cout << "\n";

        if(budget < 0){
            std::cout << "You lost all your money. Rounds surived = ";
            std::cout << i;
            std::cout << "\n";
            break;
        }
    }
    return 0;
}


int main()
{
    calcWinnings(2, 1500, 15);
}
