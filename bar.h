/*
 Project 3  Animated Bar Chart
 File name: bar.h Author: Manuel Irungaray
 System: Visual Studio
*/


#include <iostream>
#include <string>
using namespace std;

//
// Bar
//
class Bar {
 private:
    // Private member variables for a Bar object
    //Defining private member variables for this class
    // NOTE: You should not be allocating memory on the heap for this class.
    int value;
    string name; 
    string category; 

 public:
    // default constructor:
    Bar() {
        
        // TO DO:  Write this constructor.
        name = ""; //name to empty string
        value = 0; 
        category = ""; //category to empty string 
        
    }
    //
    // a second constructor:
    //
    // Parameter passed in constructor Bar object.
    //
    Bar(string name, int value, string category) {
        
        // TO DO:  Write this constructor.
        this->name = name; 
        this->value = value; 
        this->category = category; 
        
    }
    // getName:
	string getName() {
        return name; //getter
	}

    // getValue:
	int getValue() {
        return value;  //getter
	}

    // getCategory:
	string getCategory() {
        return category; //getter
	}

	  // operators
     // Allows us to compare two Bar
    // objects.  Comparison should be based on the Bar's value.
	bool operator<(const Bar &other) const {
        if(this->value < other.value)
        {
            return true;
        }
        else
        {
            return false; 
        }

	}
    //operator comparasion <=
	bool operator<=(const Bar &other) const {
        if( this->value <= other.value)
        {
            return true;
        }
        else
        {
            return false; 
        }
       
	}
    //operator comparasion <
	bool operator>(const Bar &other) const {
        if(other.value < this->value)
        {
            return true; 
        }

        else
        {
            return false; 
        }
	}
    //operator comparasion >=
	bool operator>=(const Bar &other) const {
        if(other.value <= this->value)
        {
            return true;
        }
        else
        {
            return false; 
        }
	}
};
