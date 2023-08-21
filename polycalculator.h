#ifndef POLYCACLULATOR_H
#define POLYCACLULATOR_H
#include<fstream>
#include<string>
#include "linkedlist.h"
using namespace std;
//=======================================
class PolyCalculator
{
	private:
		LinkedList list1;
		LinkedList list2;
		LinkedList list3;
	public:
		void input(); //take input the values of polynomial expressions
		void add(); //add both polynomials (list1 and list2) and save the result in list3
		void sub(); //subtract list2 from list1 and save the results in list3
		void mul(); //multiply both polynomials (list1 and list2) and save the result in list3
		void readData(string); //read a file and load the data into the linked lists (list1 and list2)
		void writeData(string); //write the polynomial expressions and the results of addition,subtraction and multiplication to a file
		bool parse(string,LinkedList&);
		void display(); //display both polynomials (list1 and list2)
	private:
};

#endif