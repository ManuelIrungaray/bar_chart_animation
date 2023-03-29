/*
 Project 3  Animated Bar Chart
 File name: barcharanimate.h Author: Arij Khan  NetId: akhan342  Course: CS 251
 System: Visual Studio
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <map> 
#include <vector>
#include <unistd.h>
#include "myrandom.h" // used by graders, do not remove
#include "barchart.h"
  
using namespace std;

class BarChartAnimate {
 private:
    //
    // Private member variables for the abstraction.
    // This implementation uses a low-level C array, bars, to store a list of
    // BarCharts.
    //Also includes title, xlabel, sourc that will be read in from the file and outputted
    BarChart* barcharts;  // pointer to a C-style array
    int size;
    int capacity;
    map<string, string> colorMap;
    string title;
    string xlabel; 
    string source; 
    int colorIndex; 

 public:

    // a parameterized constructor:
    // Like the ourvector, the barcharts C-array should be constructed here
    // with a capacity of 4.
    BarChartAnimate(string title, string xlabel, string source) {
        
        // TO DO:  Write this constructor.
        this->title = title; 
        this->xlabel = xlabel; 
        this->source = source; 
        this->capacity = 4;
        this->size = 0; 
        this->colorIndex = 0; //color index to count thru the vector 
        barcharts = new BarChart[4]; 
        
    }

    
    // destructor:
    // Called automatically by C++ to free the memory associated
    // by BarChartAnimate.
    //
    virtual ~BarChartAnimate() {
        
        // TO DO:  Write this destructor.
        delete [] barcharts; 
        
    }

    // addFrame:
    //adds a new BarChart to the BarChartAnimate object from the file stream.
    //checks to see if array is ever full, if so we allocate more space for it
    //see if category is already in the map, if not add the category along with a color from the color vector 
    void addFrame(ifstream &file) {

       
        if (size == capacity)
        {
            //doubling the array  
             int newCapacity = capacity * 2;
             BarChart* newArray = new BarChart[newCapacity];

            // copy the elements from A to the new array:
             for (int i = 0; i < size; ++i)
             {
                newArray[i].setFrame(barcharts[i].getFrame()); 
                newArray[i] = barcharts[i];
             }

            //  deletes barcharts
            // set newArray values into barcharts array values along with capacity 
             delete[] barcharts;
             barcharts = newArray;
             capacity = newCapacity;
         }  

        string line = ""; 
        string tempString; 
        string barName; 
        string barName2;
        string barValue; 
        string category; 
        int number = 0; 
        
        
        getline(file, line); //reads the first line 
        number = stoi(line); //gets the number

         BarChart bc(number); 
 
    if(!file.fail()) {
        for(int i = 0; i < number; i++)
        {
             

            getline(file, tempString, ','); //gets frame value
            
            bc.setFrame(tempString);   

            getline(file, barName, ','); //gets the name
            getline(file, barName2, ','); 
            //cout << barName << endl; 
            getline(file, barValue, ','); //gets the value 

            getline(file, category); //gets the category 
            
            bc.addBar(barName, stoi(barValue), category); 
            //cout << bc.getSize() << endl; 
            if(this->colorIndex == COLORS.size())
            {
               this->colorIndex = 0; //resets the index
            }

        //if category is not in map
          if(colorMap.count(category) != 1)
          {
            colorMap.insert({category, COLORS[colorIndex]}); //add category and color 
            this->colorIndex++; 
          }

            
        }
    
        barcharts[size] = bc; //adding the barchart object into the array
        size++; 
        getline(file, line); //reads the empty line
        
       
    }
      
}

    // animate:
    // this function plays each frame stored in barcharts.  In order to see the
    // animation in the terminal, you must pause between each frame.  To do so,
    // type:  usleep(3 * microsecond);
    // Additionally, in order for each frame to print in the same spot in the
    // terminal (at the bottom), you will need to type: output << CLEARCONSOLE;
    // in between each frame.
    
	void animate(ostream &output, int top, int endIter) {
     
		unsigned int microsecond = 50000; //playback rate
        if(endIter == -1)
        {
            endIter = size;  
        }
              

        for(int i = 0; i < endIter; i++)
        {
            usleep( 3 * microsecond); //set delay period
            output << CLEARCONSOLE; 
      

            output << WHITE << this->title << endl; //print title in black(read in application.cpp)
            output << WHITE << this->source << endl; //print source in black(read in application.cp[])
            barcharts[i].graph(cout, colorMap, top); //prints the graph of the bar chart
            output << WHITE << this->xlabel << endl; //print label in black(read in application.cpp)
            output << WHITE << "Frame: " << barcharts[i].getFrame() << endl; //print barChart frame in black
            
        }
                
	}
    

   /*
    CREATIVE COMPONENT
    void creativeAnimate(ostream &output, int top, int endIter, unsigned int speed) {
     
		unsigned int microsecond = speed; //playback rate
        if(endIter == -1)
        {
            endIter = size;  
        }
              

        for(int i = 0; i < endIter; i++)
        {
            usleep( 3 * microsecond); //set delay period
            output << CLEARCONSOLE; 
      

            output << WHITE << this->title << endl; //print title in black(read in application.cpp)
            output << WHITE << this->source << endl; //print source in black(read in application.cp[])
            barcharts[i].graph(cout, colorMap, top); //prints the graph of the bar chart
            output << WHITE << this->xlabel << endl; //print label in black(read in application.cpp)
            output << WHITE << "Frame: " << barcharts[i].getFrame() << endl; //print barChart frame in black
            
        }
                
	}
    */

    //
    // Public member function.
    // Returns the size of the BarChartAnimate object.
    int getSize(){ 
        return size; 
    }

    //
    // Public member function.
    // Returns Bar element in BarChart.
    // This gives public access to Bars stored in the Barchart.
    // If i is out of bounds, the it throws an out_of_range error message
    BarChart& operator[](int i){
        // TO DO:  Write this function.
        if(i < 0 || i >= this->size)
        {
            throw out_of_range("BarChartAnimate: i out of bounds");  
        }
        return this->barcharts[i]; 
    }
};
