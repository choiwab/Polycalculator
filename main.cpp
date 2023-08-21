#include<iostream>
#include<string>
#include<fstream>
#include<exception>
#include<sstream>
#include<iomanip>
#include<cctype>

#include "linkedlist.h"
#include "polycalculator.h"
using namespace std;

//=====================================
void listCommands()
{
	cout<<"List of available Commands:"<<endl
		<<"display              : Display the Polynomials (Linked Lists)"<<endl
		<<"input                : Input Polynomial expressions from keyboard"<<endl
		<<"add                  : Add the Polynomials (Linked Lists)"<<endl
		<<"sub                  : Subtract the Polynomials (Linked Lists)"<<endl
		<<"mul                  : Multiply the polynomials (Linked Lists)"<<endl     
		<<"read <file_name>     : Load the data from <file> and add it into the Linked Lists"<<endl
		<<"write <file_name>    : Dump the contents of the resultant Linked list to a <file>"<<endl       
		<<"help                 : Display the list of available commands"<<endl
		<<"exit                 : Exit the Program"<<endl;
}
//=======================================
// main function
int main()
{
	PolyCalculator polycalc;

	listCommands();
	string user_input;
	string command;
	string parameter;
	do
	{
		// LinkedList myList;
		// if (polycalc.parse("2x^^3+5", myList) == true)
		// 	{cout << 0 << endl;}
		// else
		// {cout << 1 << endl;} 

		cout<<">";
		getline(cin,user_input);
		
		// parse userinput into command and parameter(s)
		stringstream sstr(user_input);
		getline(sstr,command,' ');
		getline(sstr,parameter);
		
		
		if(command =="display") 		polycalc.display();
		else if(command == "input")     polycalc.input();
		else if(command == "add")		polycalc.add();
		else if(command == "sub")		polycalc.sub();
		else if(command == "mul")		polycalc.mul();
		else if(command =="read")		polycalc.readData(parameter),polycalc.display();
		else if(command == "write")		polycalc.writeData(parameter);			
		else if(command == "help")			listCommands();
		else if(command == "exit" or command=="quit")			break;
		else 							cout<<"Invalid Command!!"<<endl;
	}while(true);

	return EXIT_SUCCESS;
}