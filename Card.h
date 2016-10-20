/*
 * Name: Zixin Cheng
 * Course: SENG1120
 * Student number: 3218124
*/

#ifndef CZX_CARD
#define CZX_CARD
#include <cstdlib>
#include <iostream>
using namespace std;
namespace czx_project
{
	class Card
	{
		public:
		    // Constructor
			Card();
			Card (string initialFace, int initialValue, bool initialFaceUp = false);
			
			/*
			 * Mutator: Set face
			 * Precondition:  A valid value had been provided
			 * Postcondition: face get a value
			 */
			void setFace (const string newFace);
			
			/*
			 * Mutator: Set value
			 * Precondition:  A valid value had been provided
			 * Postcondition: variable "value" get a value
			 */
			void setValue (const int newValue);
			
			/*
			 * Mutator: Set face up status 
			 * Precondition:  A valid boolean (true or fase) had been provided
			 * Postcondition: faceUp get a boolean either true or false
			 */
			void setFaceUp (const bool newFaceUp);
			
			/*
			* Accessors: Get face
			* Precondition:  face has a valid value
			* Postcondition: Returned the value of variable "face"
			*/
			string getFace() const;
			
			/*
			* Accessors: Get value
			* Precondition:  variable "value" has a valid value
			* Postcondition: Returned the value of variable "value"
			*/
			int getValue() const;
			
			/*
			* Accessors: Get face up status
			* Precondition:  faceUp has a valid boolean
			* Postcondition: Returned the value of variable "faceUp"
			*/
			bool getFaceUp() const;
			
		private:
			string face;  // Card information
			int value;    // Card value
			bool faceUp;  // Card status: face up - true, face down - false
	};
	ostream& operator << (ostream& out, const Card& card);      // Overriding cout operator
	bool operator == (const Card& card1, const Card& card2);  // Overriding equals operator
}
#endif