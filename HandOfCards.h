/*
 * Name: Zixin Cheng
 * Course: SENG1120
 * Student number: 3218124
 */
 
#ifndef CZX_HANDOFCARDS
#define CZX_HANDOFCARDS
#include <cstdlib>
#include <iostream>
#include "LinkedList.h"
#include "Card.h"
using namespace std;

namespace czx_project
{
	class HandOfCards
	{
		public:
		    // Constructor
			HandOfCards();
			
			// Destructor
			~HandOfCards();
			
			/*
			 * Member function: Counts the value of the hand stored in the list (faceUp Only)
			 * Precondition:    None
			 * Postcondition:   The value of counts had been ereturned
			 */
			int count();
			
			/*
			 * Member function: Counts the value of the hand stored in the list (faceUp and faceDown)
			 * Precondition:    None
			 * Postcondition:   The value of counts had been returned
			 */
			int countAll();
			
			/* 
			 * Member function: Returns a string displaying the sequence of cards stored in HandOfCards
			 * Precondition:    At least one card should exist in the list
			 * Postcondition:   The sequence of cards had been returned
			 */
			string value();
			
			/* 
			 * Member function: Make all cards in hand face up
			 * Precondition:    At least one card should exist in the list
			 * Postcondition:   All cards in hand had been set to face up
			 */
			void faceUp();
			
			/*
			 * Member function: Add a card into list
			 * Precondition:    Nonw
			 * Postcondition:   A card had been added into the list
			 */
			void add(Card card, const bool faceUp);
			
		private:
		    LinkedList<Card>* list;  // Variable for linked list
	};
	ostream& operator << (ostream& out, HandOfCards& cards);      // Overriding cout operator
}
#endif