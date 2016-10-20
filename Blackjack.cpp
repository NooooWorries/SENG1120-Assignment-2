/*
 * Name: Zixin Cheng
 * Course: SENG1120
 * Student number: 3218124
 */
#include <iostream> // for cout and endl
#include <cstdlib>  // for srand, rand and atoi
#include <ctime>    // for time
#include "DeckOfCards.h"
#include "HandOfCards.h"
using namespace czx_project;
/**
 * This is an example program that shows how to seed a random number generator
 * using a number provided from the command line and then access those random numbers.
 *
 * It will use a number provided on the command line (e.g. test_random.exe 12321) if one exists
 * otherwise it will seed the random nmber using the current time in seconds
 *
 * @param argc the number of arguments provided to the main function (this includes the program name itself)
 * @param argv an array of strings containing each of the arguments
 *
 * @author Trent Houliston
 */
int main(int argc, char* argv[])
{
    // Make sure we have at least two arguments
    // The first argument will be the program name e.g. myCode.exe
    // The second argument will be the seed for the random number generator
    if (argc >= 2)
    {
        // Use atoi (ascii to integer) to convert our argument to a number
        // note that if the user enters an invalid number this will be 0
        int seed = atoi(argv[1]);

        // Use that number to seed the random number generator
        srand(seed);
    }
    // If we don't have at least two arguments seed the random number generator using the current time
    else
    {
        // Get the current time as an integer
        int seed = time(NULL);

        // Use that number to seed the random number generator
        srand(seed);
    }
	
	// Demo program
	// Step 1
    DeckOfCards* cards = new DeckOfCards();  // Create a new cards object				     
	cards-> shuffle();                       // Shuffle (Yates algorithms)
    
	// Step 2 - New instance of HandOfCards
	HandOfCards* player1 = new HandOfCards();
	HandOfCards* dealer = new HandOfCards();
	
	// Step 3
	player1 -> add (cards -> pop(), true); // Give a card to player 1
	dealer -> add (cards -> pop(), true);  // Give a card to player 2
	player1 -> add (cards -> pop(), true); // Give another card to player 1
	dealer -> add (cards -> pop(), false); // Give another card to player 2
	
	// Step 4: Display card info for player 1 and dealer
	// Step 5: Check whether achieve to 21
	// If player achieve to 21, player win
	if (player1 -> count() == 21)
	{
		dealer -> faceUp();
		cout << "Player: " << *player1 << "(" << player1-> count() << " points)"<< endl;
		cout << "Dealer: " << *dealer << "(" << dealer-> count() << " points)" << endl;
		cout << "The player is the winner!" << endl;
		exit(0);
	}
	// If dealer achieve to 21, dealer win
	else if (dealer -> countAll() == 21)
	{
		dealer -> faceUp();
		cout << "Player: " << *player1 << "(" << player1-> count() << " points)"<< endl;
		cout << "Dealer: " << *dealer << "(" << dealer-> count() << " points)" << endl;
		cout << "The dealer is the winner!" << endl;
		exit(0);
	}
	// If both player and dealer achieve to 21, tie
	else if (player1 -> count() == 21 && dealer -> countAll() == 21)
	{
		dealer -> faceUp();
		cout << "Player: " << *player1 << "(" << player1-> count() << " points)"<< endl;
		cout << "Dealer: " << *dealer << "(" << dealer-> count() << " points)" << endl;
		cout << "Tie! There are no winners." << endl;
		exit(0);
	}
	// If player burst, dealer win
	else if (player1 -> count() > 21)
	{
		dealer -> faceUp();
		cout << "Player: " << *player1 << "(" << player1-> count() << " points)"<< endl;
		cout << "Dealer: " << *dealer << "(" << dealer-> count() << " points)" << endl;
		cout << "The dealer is the winner!" << endl;
		exit(0);
	}
	// If dealer burst, player win
	else if (dealer -> countAll() > 21)
	{
		dealer -> faceUp();
		cout << "Player: " << *player1 << "(" << player1-> count() << " points)"<< endl;
		cout << "Dealer: " << *dealer << "(" << dealer-> count() << " points)" << endl;
		cout << "The player is the winner!" << endl;
		exit(0);
	}
	else
	{
		cout << "Player: " << *player1 << "(" << player1-> count() << " points)"<< endl;
		cout << "Dealer: " << *dealer << "(" << dealer-> count() << " points)" << endl;
	}
	// Step 6: Ask player hit or stand
	
	int i = 0;
	do
	{
		cout << "Player, do you want to Hit (1) or Stand (2)?" << endl;
		cin >> i;
		if (i == 1)
		{
			player1 -> add (cards -> pop(), true); // Give a card to player 1

			// If player achieve to 21, player win
			if (player1 -> count() == 21)
			{
				dealer -> faceUp();
				cout << "Player: " << *player1 << "(" << player1-> count() << " points)"<< endl;
				cout << "Dealer: " << *dealer << "(" << dealer-> count() << " points)" << endl;
				cout << "The player is the winner!" << endl;
				exit(0);
			}
			// If dealer achieve to 21, dealer win
			else if (dealer -> countAll() == 21)
			{
				dealer -> faceUp();
				cout << "Player: " << *player1 << "(" << player1-> count() << " points)"<< endl;
				cout << "Dealer: " << *dealer << "(" << dealer-> count() << " points)" << endl;
				cout << "The dealer is the winner!" << endl;
				exit(0);
			}
			// If both player and dealer achieve to 21, tie
			else if (player1 -> count() == 21 && dealer -> countAll() == 21)
			{
				dealer -> faceUp();
				cout << "Player: " << *player1 << "(" << player1-> count() << " points)"<< endl;
				cout << "Dealer: " << *dealer << "(" << dealer-> count() << " points)" << endl;
				cout << "Tie! There are no winners." << endl;
				exit(0);
			}
			// If player burst, dealer win
			else if (player1 -> count() > 21)
			{
				dealer -> faceUp();
				cout << "Player: " << *player1 << "(" << player1-> count() << " points)"<< endl;
				cout << "Dealer: " << *dealer << "(" << dealer-> count() << " points)" << endl;
				cout << "The dealer is the winner!" << endl;
				exit(0);
			}
			// If dealer burst, player win
			else if (dealer -> countAll() > 21)
			{
				dealer -> faceUp();
				cout << "Player: " << *player1 << "(" << player1-> count() << " points)"<< endl;
				cout << "Dealer: " << *dealer << "(" << dealer-> count() << " points)" << endl;
				cout << "The player is the winner!" << endl;
				exit(0);
			}
			else
			{
				cout << "Player: " << *player1 << "(" << player1-> count() << " points)"<< endl;
				cout << "Dealer: " << *dealer << "(" << dealer-> count() << " points)" << endl;
			}
		}
	} while (i == 1 && player1-> count() <= 21);
	
	if (i == 2)
	{
		// Step 7
		while (dealer -> countAll() <= 17)
		{
			dealer -> add (cards -> pop(), true);
		}
	}
	
	// Step 8
	dealer -> faceUp();
	cout << "Player: " << *player1 << "(" << player1-> count() << " points)"<< endl;
	cout << "Dealer: " << *dealer << "(" << dealer-> count() << " points)" << endl;
	
	// Step 9
	// If player achieve to 21, player win
	if (player1 -> count() == 21)
	{
		cout << "The player is the winner!" << endl;
		exit(0);
	}
	// If dealer achieve to 21, dealer win
	else if (dealer -> countAll() == 21)
	{
		cout << "The dealer is the winner!" << endl;
		exit(0);
	}
	// If both player and dealer achieve to 21, tie
	else if (player1 -> count() == 21 && dealer -> countAll() == 21)
	{
		cout << "Tie! There are no winners." << endl;
		exit(0);
	}
	// If player burst, dealer win
	else if (player1 -> count() > 21)
	{
		cout << "The dealer is the winner!" << endl;
		exit(0);
	}
	// If dealer burst, player win
	else if (dealer -> countAll() > 21)
	{
		cout << "The player is the winner!" << endl;
		exit(0);
	}
	else if (dealer -> countAll() > player1 -> count() && dealer -> countAll() <= 21)
	{
		cout << "The dealer is the winner!" << endl;
		exit(0);
	}
	else if (player1 -> count() > dealer -> countAll() && player1 -> count() <=21)
	{
		cout << "The player is the winner!" << endl;
		exit(0);
	}
	else if (dealer -> countAll() == player1 -> count() && dealer -> countAll() <= 21 && player1 -> count() <=21)
	{
		cout << "Tie! There are no winners." << endl;
		exit(0);
	}
	// Delete instances, avoid memory leak
    delete cards;
	delete player1;
	delete dealer;
    return 0;
	
}
