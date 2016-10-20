/*
 * Name: Zixin Cheng
 * Course: SENG1120
 * Student number: 3218124
*/

#ifndef CZX_Node
#define CZX_Node
#include <cstdlib>
#include <iostream>
using namespace std;
namespace czx_project
{
	template <typename value_type>
	class Node
	{
		public:
			/* Constructor
			 * Precondition:  None
			 * Postcondition: variables data, next and previous had been initialized
			 */
			Node(const value_type& initialData = value_type(), Node<value_type>* initialNext = NULL, Node<value_type>* initialPrevious = NULL);
			
			/*
			 * Destructor
			 */
			~Node();

			/*
			 * Mutator: Set data
			 * Precondition:  A valid value had been provided
			 * Postcondition: Data get a value
			 */
			void setData(const value_type& newData);

			/*
			 * Mutator: Set next
			 * Precondition:  A valid next Node had been provided
			 * Postcondition: next get a Node
			 */
			void setNext(Node<value_type>* newNext);

		   /*
			* Mutator: Set previous
			* Precondition:  A valid previous Node had been provided
			* Postcondition: previous get a Node
			*/
			void setPrevious(Node<value_type>* newPrevious);

		   /*
			* Accessors: Get data
			* Precondition:  Data has a valid value
			* Postcondition: Returned the value of variable "data"
			*/
			value_type getData() const;
			
			/*
			 * Accessors: Get previous Node
			 * Precondition:  Previous has a valid value (pointer)
			 * Postcondition: Return the value of pointer "previous"
			 */
			const Node<value_type>* getPrevious () const;
			
			/*
			 * Accessors: Get previous Node (constant)
			 * Precondition:  Previous has a valid value (pointer)
			 * Postcondition: Return the value of pointer "previous"
			 */
			 Node<value_type>* getNext();
			 
			 /*
			 * Accessors: Get next Node
			 * Precondition:  Next has a valid value (pointer)
			 * Postcondition: Return the value of pointer "next"
			 */
			const Node<value_type>* getNext () const;
			
			/*
			 * Accessors: Get next Node (constant)
			 * Precondition:  Next has a valid value (pointer)
			 * Postcondition: Return the value of pointer "next"
			 */
			 Node<value_type>* getPrevious();

		private:
			value_type data;   // Variable to store card information
			Node<value_type>* next;        // Variable to store the address of next Node
			Node<value_type>* previous;    // Variable to store the address of previous Node
	};
}
#include "Node.template"
#endif