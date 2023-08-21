#include "linkedlist.h"
#include <iostream>
using namespace std;

LinkedList::LinkedList ()
{ 
	this->head = NULL;
}
//====================================
// destructor to clean up all nodes
LinkedList::~LinkedList ()    
{
	Node* curr = this -> head;         //traverse through all nodes and delete nodes
	while(curr != NULL)
	{
		Node* next = curr->next;
		delete curr;
		curr = next;
	}
}

void LinkedList::insert(int coef,int expo)
{
	Node* u = new Node(coef, expo);        //assign new node
	u->coef = coef;
	u->expo = expo;

	Node* temp = head;       //assign temporary node to head
	Node* prev = NULL;       //assign temporary node to NULL, will be used for storing previous node

	if(head == NULL)        //if list is empty, assign new node as head
	{
		head= u;
		return;
	}

	while(temp != NULL &&  temp -> expo > expo)    //traverse through nodes to identify position to insert new node
	{
		prev = temp;
		temp = temp->next;
	}

	if(temp != NULL && temp -> expo == expo )     //if exponent of the new node and a prexisting one is the same, add coefficients
	{
		temp -> coef += coef;

		if(temp -> coef == 0)       //if coefficients add up to zero, delete the node
		{
			if(prev == NULL)
			{
				head = temp -> next;     //if the node for deletion is the head, assign new head
			}
			else
			{
				prev -> next = temp ->next;   //if not, connect the previous node to the next node 
			}

		delete temp;      //delete node
		}
	}
	else
	{
		if(prev == NULL)       //if the new node has the largest exponent, assign as new head
		{
			head = u;
		}
		else
		{
			prev -> next = u;       //if the new node is in the middle, connect the previous node to the new node
		}

		u->next = temp;        //assign new node's next to the temporary node
		}
	}


void LinkedList::print(ostream &os) const
{

	Node* curr = this -> head;      
	while(curr != NULL)        //traverse through all nodes 
	{
		if(curr -> expo == 0)    //if the exponent of the node is 0 
		{
			if(curr->coef >= 0)    //if the coefficient is positive, print with "+"
				{os << "+" << curr -> coef; }
			else if(curr->coef <0)     //if the coefficient is negative, print coefficient as it the integer is stored with "-"
			{
				os << curr->coef;
			}
		}
		else if(curr -> expo ==1)      //if the exponent is 1
		{
			if(curr->coef >= 0 && curr -> coef != 1 && curr -> coef != -1)    //print node with positive coefficent with "+"
				{os << "+" << curr -> coef<<"x"; }
			else if(curr-> coef ==1)      //if the coefficient is 1, simply print "x"
			{
				os << "x";
			}
			else if(curr -> coef == -1)     //if the coefficeint is -1, simply print "-x"
			{
				os << "-" << "x";
			}
			else if(curr->coef <0)     //if the coefficient is negative, print coefficient
			{
				os  << curr->coef<< "x";
			}
		} 
		else                                   							//if the exponent is more than 1
		{
			if(curr->coef >= 0 && curr -> coef != 1 && curr -> coef != -1)    //same process as above
				{os << "+" << curr -> coef<<"x^"<< curr->expo; }
			else if(curr-> coef ==1)
			{
				os << "x^"<< curr -> expo;
			}
			else if(curr -> coef == -1)
			{
				os << "-" << "x^"<< curr -> expo;
			}
			else if(curr->coef <0)
			{
				os  << curr->coef <<"x^" << curr -> expo;
			}
		}
		curr = curr ->next; 
	}
	os << endl;

}
 
void LinkedList::removeAll()					//traverse throuhgh all nodes and remove nodes
{
	Node*temp = this ->head;
	while(head != NULL)
	{
		temp = head;
		head = head -> next;
		free(temp);
	}

}