/*
 Animated Bar Chart
 File name: application.cpp Author: Manuel Irungaray
 System: Visual Studio
*/

// Bar Chart Animation
// This application uses BarChartAnimate (which uses BarChart, which uses Bar)
// to produce an animated bar chart.

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <string>
#include "barchartanimate.h"
using namespace std;

int main() {
    unsigned int speed = 25000;
    string filename = "cities.txt";
    ifstream inFile(filename);
    string title;
    string line;
    getline(inFile, title);
    string xlabel;
    getline(inFile, xlabel);
    string source;
    getline(inFile, source);
    getline(inFile, line); //reads the empty line
    BarChartAnimate bca(title, xlabel, source);
    
    while (!inFile.eof()) {
        bca.addFrame(inFile);
    }

    bca.animate(std::cout, 10, -1 );
    return 0;
}
