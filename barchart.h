/*
 Project 3  Animated Bar Chart
 File name: barchart.h Author: Arij Khan  NetId: akhan342  Course: CS 251
 System: Visual Studio
*/

#include <iostream>
#include <algorithm>
#include <map>
#include "myrandom.h" // used in graders, do not remove
#include "bar.h"

using namespace std;

// Constants used for bar chart animation.  You will primarily
// use these in barchartanimate.h, but you might find some useful here.
const string BOX = "\u29C8";
const string CLEARCONSOLE = "\033[2J";
const string RESET("\033[0m");


//
// NOTE: COMMENT AND UNCOMMENT AS NEEDED BASED ON YOUR TERMINAL
//
// Color codes for light mode terminals
// const string RED("\033[1;36m");
// const string PURPLE("\033[1;32m");
// const string BLUE("\033[1;33m");
// const string CYAN("\033[1;31m");
// const string GREEN("\033[1;35m");
// const string GOLD("\033[1;34m");
// const string BLACK("\033[1;37m");
// const vector<string> COLORS = {RED, PURPLE, BLUE, CYAN, GREEN, GOLD, BLACK};

// Color codes for darker mode terminals
const string CYAN("\033[1;36m");
const string GREEN("\033[1;32m");
const string GOLD("\033[1;33m");
const string RED("\033[1;31m");
const string PURPLE("\033[1;35m");
const string BLUE("\033[1;34m");
const string WHITE("\033[1;37m");
//const string RESET("\033[0m");
const vector<string> COLORS = {CYAN, GREEN, GOLD, RED, PURPLE, BLUE, WHITE};



//
// BarChart
//
class BarChart {
 private:
    //
    // Private member variables for the abstraction.
    // This implementation uses a low-level C array, bars, to store a list of
    // Bars, and also a frame to store in the time frame of the bar that will determine the order of bars

    Bar* bars;  // pointer to a C-style array
    int capacity; //the size of the array
    int size; //the number of elements in the array
    string frame; //time-frame in file 
    
 public:
    
    // default constructor:
    BarChart() {
        bars = nullptr; //set ptr to null 
        capacity = 0; 
        size = 0; 
        frame = ""; 
        
    }
    
    // parameterized constructor:
    // Parameter passed in determines memory allocated for bars.
    //If n = 10, then space for 10 bars is allocated
    BarChart(int n) {
        
        capacity = n; 
        size = 0;
        bars = new Bar[n]; //allocating array space of size n 
        frame = ""; 
    }

    //
    // copy constructor:
    //
    // Called automatically by C++ to create an BarChart that contains
    // a copy of an existing BarChart.  Example: this occurs when passing
    // BarChart as a parameter by value.
    //
    BarChart(const BarChart& other) {
        //other is the object we want to copy from
      
        this->bars = new Bar[other.capacity]; //allocates space for how much ever capacity value is
        this->size = other.size; 
        this->capacity = other.capacity; 
        this->frame = other.frame; 

        for(int i = 0; i < other.size; i++)
        {
            this->bars[i] = other.bars[i]; //copys the values from one array into the other 
        }
        
    }
    //
    // copy operator=
    //
    // Called when you assign one BarChart into another, i.e. this = other;
    //
    BarChart& operator=(const BarChart& other) {
        // if(bars != NULL){
        //   delete [] bars;
        // }
        delete [] bars;

        this->bars = new Bar[other.capacity]; //allocates space for how much ever capacity value is
        this->capacity = other.capacity; 
        this->size = other.size; 
        this->frame = other.frame; 

        for(int j = 0; j < other.size; j++)
        {
            this->bars[j] = other.bars[j]; //copys the values from one array into the other 
        }

        return *this;
    }

    // clear
    // frees memory and resets all private member variables to default values.
    void clear() {

        size = 0; 
        capacity = 0; 
        delete [] bars; //freeing memory on the heap 
        bars = nullptr;
        
    }
    
    //
    // destructor:
    //
    // Called automatically by C++ to free the memory associated by the
    // BarChart.
    //
    virtual ~BarChart() {

        if(bars != NULL)
        {
            delete [] bars; 
            bars = nullptr; 
        }
        
    }
    
    // setFrame
    void setFrame(string frame) {
    
        this->frame = frame; //setter
        
    }
    
    // getFrame()
    // Returns the frame of the BarChart object.
    string getFrame() {
        
        return frame; //getter
    }

    // addBar
    // adds a Bar to the BarChart.
    // returns true if successful
    // returns false if there is not room
    bool addBar(string name, int value, string category) {
        
        // TO DO:  Write this function.
        if(size == capacity)
        {
            //TEST CASE: UNCOMMENT WHEN TESTING
           // cout << "CAPACITY REACHED" << endl;
            return false; 
        }
        else
        {
            Bar addBar(name, value, category); 
            bars[size] = addBar; //add the object as an element into the array
            size++; //added one element into the array
            return true; 
        }
    }
    
    // getSize()
    // Returns the size (number of bars) of the BarChart object.
    int getSize() {
        return size; 
    }
    
    // operator[]
    // Returns Bar element in BarChart.
    // This gives public access to Bars stored in the Barchart.
    // If i is out of bounds, the it throws an out_of_range error message:
    Bar& operator[](int i) {
        //Bar b;
        
        // TO DO:  Write this function.
        //if i is out of bounds
        if(i < 0 || i >= this->size)
        {
            throw out_of_range("BarChart: i out of bounds");  
            exit(0); 
        }
        
        return this->bars[i];  // TO DO:  update this, it is only here so code compiles.
    }
    
    // dump
    // Used for printing the BarChart object.
    // Recommended for debugging purposes.  output is any stream (cout,
    // file stream, or string stream).
    // Format:
    // "frame: 1
    // aname 5 category1
    // bname 4 category2
    // cname 3 category3" <-newline here
    void dump(ostream &output) { 
        sort(bars, bars + size, greater<Bar>()); //sorts the bars based on their values from descending order
        // TO DO:  Write this function.
        output << "frame: " << frame << endl; 

        for(int i = 0; i < size; i++)
        {
            output << bars[i].getName() << " "; //prints passed in name from the object 
            output << bars[i].getValue() << " "; //prints passed in value from the object 
            output << bars[i].getCategory(); //prints passed in name from the object 

            output << endl; 

        }
        
    }
    
    // graph
    // Used for printing out the bar.
    // output is any stream (cout, file stream, string stream)
    // colorMap maps category -> color
    // top is number of bars you'd like plotted on each frame (top 10? top 12?)
    void graph(ostream &output, map<string, string> &colorMap, int top) {
    	int lenMax = 60;  // this is number of BOXs that should be printed
                          // for the top bar (max value)
        string barstr = "";
        string color;
        sort(bars, bars + size, greater<Bar>()); //sorts the bars based on their values from descending order
        int maxValue = bars[0].getValue(); //Gets the highest value from the bars (we know it will be the first one because its already sorted)
        int len = 0.0; 
        int numberOfBoxes = 0; //holds number of boxes (len)
         
        // TO DO: read this example and this erase it.
        // e.g. Here I am plotting 60 red BOXs to output
        for(int i = 0; i < top && i < size; i++)
        {
            
          len = ((bars[i].getValue()+  0.0) / maxValue) * lenMax;  
          numberOfBoxes = len; 
          //if category is not found within color map and if map is empty, set the color to black/white
          if(colorMap.size() == 0 && colorMap.find(bars[i].getCategory()) == colorMap.end())
          {
            color = WHITE; 
          }
          color = colorMap[bars[i].getCategory()]; //gets the value of that category and stores it in color 

            for (int j = 0; j < numberOfBoxes; j++)
            {
                barstr += BOX;
            }
            output << color << barstr << " "; 
            output << bars[i].getName() << " "<< bars[i].getValue() << endl; //prints the name and value 
            barstr = ""; 
            numberOfBoxes = 0; 
        }


       
    }
    
};

