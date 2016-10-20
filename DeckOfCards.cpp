/*
 * Name: Zixin Cheng
 * Course: SENG1120
 * Student number: 3218124
 */

#include "DeckOfCards.h"

using namespace std;

namespace czx_project
{
    DeckOfCards::DeckOfCards()
    {
        list = new LinkedList<Card>();
        string cardNum [13] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};  // Card number
        string cardSuite [4] = {"S", "H", "C", "D"};  // Card suite
        Card* card = new Card();  // Create new card
        int i = 0; int j = 0;
		
		// Add cards into linked list
        for (i = 0; i < 4 ; i ++)
        {
            for (j = 0; j < 13; j ++)
            {
				// Set the card value
				card -> setFace (cardNum[j] + "-" + cardSuite[i]);
				if (cardNum[j] == "J" || cardNum[j] == "Q" || cardNum[j] == "K")
					card -> setValue(10);
				else if (cardNum[j] == "A")
					card -> setValue(11);
				else
					card -> setValue (atoi(cardNum[j].c_str()));
				card -> setFaceUp(false);
				// Push card into stack and shuffle
                push(*card);
				shuffle();
            }
        }
        delete card;  // Delete variable, avoid memory leak
    }
    
	DeckOfCards::~DeckOfCards()
	{
		delete list;
	}
    void DeckOfCards::shuffle()
    {
        int length = DeckOfCards::length();  // Get the length of linked list
        int random = 0;  // Initialize int variable - random
        
        // Yates algorithms to shuffle card
        for (int i = length - 1; i >= 1; i --)
        {
            random = rand() % i;   // Random number
            list->swap(random,i);  // Swap two cards
        }
    }
    
    size_t DeckOfCards::length() const
    {
        return list->getSize();  // Get the length from linked list
    }
    
    bool DeckOfCards::empty()
    {
        bool isEmpty = false;  // Initialize boolean variable
        if (list -> getSize() == 0)
        {
            isEmpty = true;    // If the size of linked is empty, set boolean to true
        }
        return isEmpty;        // Return the result
    }
    
    int DeckOfCards::position (const Card card) const
    {
				
        return list->search(card);  // Search the card from linked list
    }
    
    bool DeckOfCards::remove(const Card card)
    {
        // Remove a card based on card string
        bool isSuccess = true;              // Declare a new boolean and initialize it
        int position = list->search(card);  // Get the position of a sppecific card
		int size = static_cast<int>(length());  // Convert size_t to int
        if (position == -1)    				// If card not found
		{
            isSuccess = false;              // Fail to delete if the card that user provided is not exist
		}
		else if (position == 0)				// If card is located at the head of linked list, remove head
		{
			list->removeFromHead();    
		}
		else if (position >=1 && position <= size - 2)
		{			     
            list->moveToHead();                 // Move to the head of the linked list
            for (int i = 0; i < position; i ++)
			{
                list->forward();                // Move forward to the card that user want to delete				
			}		
            list->removeCurrent();              // Delete the card	
		}
		else if (position == size - 1)		// If card is located at the tail of the linked list, remove tail
		{		
			list ->removeFromTail();
		}	
        return isSuccess;                   // Return back the result
    }
    
    string DeckOfCards::value()
    {
        string cardInfo;                        // Declare a new string
        list->moveToHead();                 // Move to the head of the linked list
        //For each card
        for (size_t i = 0; i < DeckOfCards::length(); i ++)
        {
            cardInfo += list-> getCurrent().getFace();    // Get the value of current card
            cardInfo += " ";                    // Add to card string
            list -> forward();              // Move one position forward
        }
        return cardInfo;                        // Return back the result
    }
    
	Card DeckOfCards::pop()
	{
		return list -> removeFromHead();  // Remove the head element in linkedlist and return the value
	}
	
	void DeckOfCards::push(const Card& pushItem)
	{
		list -> addToHead(pushItem);
	}
	
    // Overload the cout operator
    ostream& operator << (ostream& out, DeckOfCards& cards)
    {
        out << cards.value();  // Output the return string of function value()
        return out;            // Return back the result
    }
    
}