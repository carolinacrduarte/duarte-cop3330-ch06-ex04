/*
 *  UCF COP3330 Fall 2021 Assignment 5 Solution
 *  Copyright 2021 Carolina Duarte
 */

/*
Write a program where you first enter a set of name-and-value pairs, such as Joe 17 and Barbara 22. For each pair, add the name to a vector called names and the number to a vector called scores (in corresponding positions, so that if names[7]=="Joe" then scores[7]==17). Terminate input with NoName 0. Check that each name is unique and terminate with an error message if a name is entered twice. Write out all the (name,score) pairs, one per line.

Define a class Name_value that holds a string and a value. Rework exercise 19 in Chapter 4 to use a
vector<Name_value> instead of two vectors.
*/

//Header file.
#include "std_lib_facilities.h" 

class Name_value {
public:
	string name;
	int value;
};

vector<Name_value> nv;

//To add to vector:
void add() {
    
    Name_value temp;
    bool next;
    next = true; 

    while (next == true) {
		cout << "Please enter the 'Name Value' pair or terminate inserting NoName 0 instead: ";
		cin >> temp.name >> temp.value;
		if (temp.name == "NoName" && temp.value == 0) {
			next = false;
		}
		else {
			nv.push_back(temp);
        }  
    }
};

//Checks if all pairs are unique:
void twice() {
    int c = 0;

    for(int i = 0; i < nv.size(); i++) {
        for(int j = i+1; j<(nv.size()-i-1); j++) {
            if(nv[i].name == nv[j].name)
            {
                c++;
                break;
            }
        }
        if(c!=0)
        {
            cout<<"ERROR. One of the pairs has been inserted by user twice."<<endl;
            break;
        }
    }    
};

//Displays all entries:
void display() {
    for(int i = 0; i < nv.size(); i++)
    {
        cout<<"Name: "<<nv[i].name<<"\nScore: "<<nv[i].value<<endl;
    }
};

int main() {
    add();
    twice();
    display();
    return 0;
}