/*
 * Name: Zixin Cheng
 * Course: SENG1120
 * Student number: 3218124
 */

#ifndef CZX_DECKOFCARDS
#define CZX_DECKOFCARDS
#include <cstdlib>
#include <iostream>
#include "LinkedList.h"
#include "Card.h"
using namespace std;
namespace czx_project
{
    class DeckOfCards
    {
        public:
            // Constructor
            DeckOfCards();
			
			// Destructor
			~DeckOfCards();
        
            // Member functions
            /*
             * Member function: Use Yates algorithm to randomizes the sequence of cards
             * Precondition:    Linked list is exist and cards are stored in the linked list
             * Postcondition:   Cards had been shuffled randomly
             */
            void shuffle();
        
            /*
             * Member functio: Return the length of cards linked list
             * Precondition:   None
             * Postcondition:  Return back the length of cards linked list
             */
            size_t length() const;
        
            /*
             * Member function: Whether there are any cards in DeckOfCards or not
             * Precondition:    None
             * Postcondition:   Returned whether there are any cards in DeckOfCards or not
             */
            bool empty();
        
            /*
             * Member function: The position in the list with the first occurrence of the input parameter,
             * Precondition:    None
             * Postcondition:   Returns the position in the list with the first occurrence of the input parameter;
             *                  -1 if the card is not in the deck.
             */
            int position(const Card card) const;
        
            /*
             * Member function: Get the sequence of cards in DeckOfCards
             * Precondition:    Cards are exist in the linked list
             * Postcondition:   The sequence of cards stored in DeckOfCards returned
             */
            string value();
        
            /*
             * Member function: Removes the corresponding card in DeckOfCards
             * Precondition:    None
             * Postcondition:   The corresponding card had been removed from the linked list
             */
            bool remove(const Card card);
			
			/*
			 * Member function: Removes the top card from the deque
			 * Precondition:    At least one card exist in the linked list
			 * Postcondition:   The top card of the deque had been removed;
		     * 					The card which had been removed just now had been returned
			 */
			Card pop();
			
			/*
			 * Member function: Adds a card to the top of the deque
			 * Precondition:    None
			 * Postcondition:   The card had already been added into the deque
			 */
			void push(const Card& pushItem);
        
        private:
            LinkedList<Card>* list;  // Variable for linked list
    };
    ostream& operator << (ostream& out, DeckOfCards& cards); // Overriding cout operator
}

#endif
