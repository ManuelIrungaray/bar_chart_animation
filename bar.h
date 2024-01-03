/*
 Animated Bar Chart
 File name: bar.h Author: Manuel Irungaray
 System: Visual Studio
*/


#include <iostream>
#include <string>
using namespace std;

// Bar
class Bar {
 private:
    // Private member variables for a Bar object
    //Defining private member variables for this class
    int value;
    string name; 
    string category; 

 public:
    // default constructor:
    Bar() {
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
        this->name = name; 
        this->value = value; 
        this->category = category; 
        
    }
	string getName() {
        return name; //getter
	}

	int getValue() {
        return value;  //getter
	}

	string getCategory() {
        return category; //getter
	}

	// operator comparasion < 
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
