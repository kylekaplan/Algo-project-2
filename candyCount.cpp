/************************************************************
* By Felipe Gutierrez, Francisco Hernandez, Daniel Heshmaty *
*                                                           *
* This program should develop an algorithm to count the     *
* number of unique arrangements of pieces of candy          *                                      *
* Project 2, Analysis of Algorithms                         *
************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <sstream>
#include <vector>
#include<cmath>
using namespace std;
/*
 * Algorithm to count the number of unique arrangements of
 * pieces of candy
 * @n, the size (given in units of squares);
 * @s, the number of squares
 * @l, the number of long candies
 * @return the number of possible samplers
 */

int naiiveAlgo(int n, int s, int l) {
    int answer;
    int index;
    n = n + 1;
    index = n;
    int* a = NULL;   // Pointer to int, initialize to nothing.
    a = new int[index];  // Allocate n ints and save ptr in a.

    // Set the first position of the array to 1.
    a[0] = 1;
    cout << "first is " << a[0];
    // Set the second position of the array to the number of squares.
    a[1] = s;
    // For loop that iterates from the second position of the array till
    // it is less than or equal to the size of the sampler.
    for(int i=2; i <=n-1; i++){
        //Set the right ride of the equation to the position at i.
        a[i]=(s*a[i-1])+(l*a[i-2]);
        cout << "iter num " << i << " is " << a[i] << endl;
    }
    answer = a[n - 1];
    delete [] a;  // When done, free memory pointed to by a.
    *a = NULL;     // Clear a to prevent using invalid memory reference.
    //return the number of possible samplers.
//    cout << "answer: " << answer << endl;
    return answer;
}

/**
 * Main Function
 */
int main() {
    ofstream output;
    // Open the file for writing.
    output.open("../output.txt");
    // Base Case if file can not be created.
    if (!output.is_open()) {
        cout << "Can't open output file!\n";
        exit(1);
    }

    std::ifstream infile("../input.txt");

    bool first = true;
    int p;
    std::string line;
    while (std::getline(infile, line))
    {
        if(first) {
            first = false;
            p = stoi(line);
        } else {
            std::istringstream iss(line);
            int size;
            int squareCandy;
            int longCandy;
//            if (!(iss >> first_on_line >> second_on_line >> third_on_line)) { break; } // error
            if (iss >> size >> squareCandy >> longCandy) {
                cout << size;
                int results = naiiveAlgo(size, squareCandy, longCandy);
                // Adds the value of result into the output file.
//                cout << results;
                output << results << endl;
            }
        }
    }
    // Closes the output file.
    output.close();
    return 0;
}
