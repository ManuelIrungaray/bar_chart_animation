/*
 Project 3  Animated Bar Chart
 File name: application.cpp Author: Arij Khan  NetId: akhan342  Course: CS 251
 System: Visual Studio
*/

// Bar Chart Animation
// This application uses BarChartAnimate (which uses BarChart, which uses Bar)
// to produce an animated bar chart.

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include "barchartanimate.h"
using namespace std;

/*
Creative component:
copy and paste this below and comment out "bca.animate(cout, 12, -1)" 
bca.animate(cout, 12, -1, speed)

Uncomment creativeAnimate function in barchartanimate and comment out animate function
Creative component will change the playback rate to even a faster rate than the default rate
*/

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
	
	bca.animate(cout, 12, -1);

	

    return 0;
}
