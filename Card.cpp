/*
 * Name: Zixin Cheng
 * Course: SENG1120
 * Student number: 3218124
*/

#include "Card.h"
namespace czx_project
{
	Card::Card()
	{
		// Accept empty value but do nothing
	}
	Card::Card(string initialFace, int initialValue, bool initialFaceUp)
	{
		face = initialFace;     // Set the initial value of face
		value = initialValue;   // Set the initial value of variable "value"
		faceUp = initialFaceUp; // Set the initial value of faceUp
	}
	
	void Card::setFace (string newFace)
	{
		face = newFace;  // Set the new value of face
	}
	
	void Card::setValue (const int newValue)
	{
		value = newValue;  // Set the new value of variable "value"
	}
	
	void Card::setFaceUp (const bool newFaceUp)
	{
		faceUp = newFaceUp;  // Set the new value of setUp
	}
	
	string Card::getFace() const
	{
		return face; // return the value of face
	}
	
	int Card::getValue() const
	{
		return value; // return the value of variable "value"
	}
	
	bool Card::getFaceUp() const
	{
		return faceUp;  // return the value of faceUp
	}
	
	// Overload the cout operator
    ostream& operator << (ostream& out, const Card& card)
    {
        out << card.getFace();  // Output the return string of function getFace()
        return out;             // Return back the result
    }
	
	bool operator == (const Card& card1, const Card& card2)
	{
		return(card1.getFace() == card2.getFace());
	}
}