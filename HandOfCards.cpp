/*
 * Name: Zixin Cheng
 * Course: SENG1120
 * Student number: 3218124
 */

#include "HandOfCards.h"

using namespace std;

namespace czx_project
{
	HandOfCards::HandOfCards()
	{
		// Create a new list instance
		list = new LinkedList<Card>();
	}
	
	HandOfCards::~HandOfCards()
	{
		// Delete list, avoid memory leak
		delete list;
	}
	
	int HandOfCards::count()
	{
		int size = static_cast<int>(list -> getSize());
		int count = 0;
		// Move list to head
		list -> moveToHead();
		for (int i = 0; i < size; i ++)
		{
			// If face up has a value of true
			if (list->getCurrent().getFaceUp() == true)
			{
				// Count value
				count = count + list -> getCurrent().getValue();
			}
			// Move forward
			list -> forward();
		}
		return count;
	}
	
	int HandOfCards::countAll()
	{
		int size = static_cast<int>(list -> getSize());
		int count = 0;
		// Move list to head
		list -> moveToHead();
		// Count all card value
		for (int i = 0; i < size; i ++)
		{
		    count = count + list -> getCurrent().getValue();
			// Move forward
			list -> forward();
		}
		return count;
	}
	
	string HandOfCards::value()
	{
		int size = static_cast<int>(list -> getSize());
		string cardStr;
		// Move to head
		list -> moveToHead();
		// Traverse all elements in the list
		for (int i = 0; i < size; i ++)
		{
			// If faceUp is false, add ?-?
			if (list->getCurrent().getFaceUp() == false)
			{
				cardStr += "?-? ";
			}
			// Else add face
			else
			{
				cardStr += list->getCurrent().getFace() + " ";
			}
			// Move forward
			list -> forward();
		}
		return cardStr;
	}
	
	void HandOfCards::faceUp()
	{
		int size = static_cast<int>(list -> getSize());
		
		// Traverse all elements in the list
		for (int i = 0; i < size; i ++)
		{
			list -> moveToHead();
			// get current card
			Card card = list -> getCurrent();
			// remove head element
			list -> removeFromHead();
			// Set faceUp to true and add the card to tail
			add (card, true);
		}
	}
	
	void HandOfCards::add(Card card, const bool faceUp)
	{
		// set faceUp
		card.setFaceUp(faceUp);
		// add to tail
		list -> addToTail(card);
	}
	
	ostream& operator << (ostream& out, HandOfCards& cards)
    {
        out << cards.value();  // Output the return string of function getFace()
        return out;             // Return back the result
    }
}