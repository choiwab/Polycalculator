#include "polycalculator.h"
#include <iostream>
#include <cctype>
#include <sstream>
using namespace std;

bool onfile = false;   //flag to prevent printing into terminal when writing data into file

void PolyCalculator::input()
{
	list1.removeAll();       //remove previous inputs
	list2.removeAll();

	string list1;            //assign string to save inputs
	string list2;

	do{
		cout << "Enter first Polynomial expression : ";      //receive input until valid input in taken
		getline(cin, list1);
	}while(parse(list1, this->list1)==false);
	cout << endl;

	do{
		cout << "Enter second Polynomial expression : ";
		getline(cin , list2);
	}while(parse(list2, this -> list2)==false);
	cout << endl;
}

void PolyCalculator::add()
{
	Node* one = list1.head;         //create pointers to all lists
	Node* two = list2.head;
	Node* three = list3.head;

	if(three != NULL)           //clear list3
	{
		list3.removeAll();
	}
	while(one != NULL)      	//insert content of list1 into list3
	{
		list3.insert(one->coef, one -> expo);
		one = one ->next;
	}
	while(two != NULL)			//insert content of list2 into list3
	{
		list3.insert(two -> coef, two ->expo);
		two = two ->next;
	}

	if(onfile == false)			//do not print when write function is called
	{
		cout << "Exp1 + Exp2 = ";
		list3.print(cout);
	}


}

void PolyCalculator::sub()       //same process as above
{
	Node* one = list1.head;
	Node* two = list2.head;
	Node* three = list3.head;

	if(three != NULL)
	{
		list3.removeAll();
	}
	while(one != NULL)
	{
		list3.insert(one->coef, one -> expo);
		one = one ->next;
	}
	while(two != NULL)
	{
		list3.insert(-(two -> coef), two ->expo);
		two = two ->next;
	}

	if(onfile == false)
	{
	cout << "Exp1 + Exp2 = ";
	list3.print(cout);
	}
}

void PolyCalculator::mul()
{
	Node* one = list1.head;
	Node* two = list2.head;
	Node* three = list3.head;

	if(three != NULL)    
	{
		list3.removeAll();
	}

	while(one != NULL)    					//iterate list1
	{
		two = list2.head;					//return to the first node of list2 for multiplication		
		while(two != NULL)					//iterate list2
		{
		list3.insert((one->coef) * (two->coef), (one->expo) + (two -> expo));    //multiply coefficients and add exponents
		two = two-> next;					
		}
		one = one -> next;    				
	}

	if(onfile == false)
	{
	cout << "Exp1 * Exp2 = ";
	list3.print(cout);
	}
}

void PolyCalculator::readData(string filename)
{
	ifstream fin(filename); 		
	string eq;

	if(list1.head != NULL)				//remove content from both list1 and list2
	{
		list1.removeAll();
	}
	if(list2.head != NULL)
	{
		list2.removeAll();
	}

	if(fin)								//read each line from file and parse
	{
		getline(fin, eq);
		parse(eq, list1);
		getline(fin, eq);
		parse(eq, list2);

		fin.close();
	}
	else
		perror("");

}

void PolyCalculator::writeData(string filename) 
{
	onfile = true;
	ofstream fout;
	fout.open(filename);
	//string list1 = "4x + 5";

	if(fout) 						
	{
		fout << "Exp1 = ";					//print each equation into file
		list1.print(fout);
		fout << endl;
		fout << "Exp2 = ";
		list2.print(fout);
		fout << endl;
		fout << "Exp1 + Exp2 = ";			//perform either addition, subtraction, or multiplication and print into file
		add();
		list3.print(fout);
		fout << endl;
		fout << "Exp1 - Exp2 = ";
		sub();
		list3.print(fout);
		fout << endl;
		fout << "Exp1 * Exp2 = ";
		mul();
		list3.print(fout);
		fout << endl;
	}
	onfile = false;
}

// void PolyCalculator::write(LinkedList& lst,ofstream& fout)
// {


	
// }

bool PolyCalculator::parse(string str,LinkedList& lst)
{
	str.erase(std::remove_if(str.begin(), str.end(), ::isspace));		//remove white spaces from the string
	int length = str.length();
	char* array = new char[length+1];									//convert string into array
	strcpy(array, str.c_str());

	if(array[0] != 'x' && isdigit(array[0]) == false && array[0]!='-') 	//if the string doesn't start with a x, "-" or is not a digit, return false
		return false;
	if(array[length-1] !='x' && isdigit(array[length-1]) == false) 		//if the string doesn't end with a x or is not a digit, return false
		return false;

	for(int i =0; i < length-1; i++)									//iterate through string
	{ 
		if(array[i]=='x') 												//if the next string after 'x' is not '^', '+', or '-', return false  
		{
			if ((array[i+1] != '^') && (array[i+1] != '+') && (array[i+1] !='-'))
				return false;
		}

		if(array[i] == '+' || array[i] == '-')							//if the next string after "+" or "-" is either "+", "-", or "^", return false
		{
			if(array[i+1] == '+' || array[i+1] == '-' || array[i+1] == '^')
				return false;
		}

		if(array[i] == '^')												//if the next string after '^' is not a digit, return false
		{
			if(isdigit(array[i+1])==false)   //also checks if the expo is negative because it starts with a '-'
				return false;
		}

		if(isdigit(array[i])==true)										//if the next string after a digit is '^', return false
		{
			if(array[i+1]=='^')
				return false;
		}
	}
	
	str.erase(std::remove_if(str.begin(), str.end(), ::isspace));	
	stringstream sstr(str);

	int coef;
	int expo;
	char oper;
	char dummy;

	while(sstr.peek()!=EOF)					//iterate string using sstr.peek()
	{
		expo = 0;							//initialize expo to 0 and coef as 1
		coef = 1;
		if(sstr.peek() == '+' || sstr.peek() == '-')	//store operator into oper
			{sstr >> oper;
	}
		if(isdigit(sstr.peek()))			//store next digit as coefficient
			{sstr >> coef;
	}
		if(sstr.peek()=='x')				//store 'x' into dummy and initialize expo as 1
			{sstr >> dummy;
		expo = 1;}
		if(sstr.peek()=='^')				//store '^' into dummy and store next digit as exponent
		{
			sstr >> dummy;
			sstr.peek();
			sstr >> expo;
		}
		if(oper == '-')						//if operator was '-' store coefficient as negative
			{coef = int(coef) * (-1);
	}
	lst.insert(coef, expo);					//insert information into list
	}
	return true;
}


void PolyCalculator::display()
{
	cout << "Equation1 : " ;
	list1.print(cout);
	cout << endl;
	cout << "Equation2 : " ;
	list2.print(cout);
	cout << endl;
}