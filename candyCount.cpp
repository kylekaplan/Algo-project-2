/************************************************************
* By Felipe Gutierrez, Francisco Hernandez, Daniel Heshmaty *
*                                                           *
* This program should develop an algorithm to count the     *
* number of unique arrangements of pieces of candy          *                                      *
* Project 2, Analysis of Algorithms                         *
************************************************************/

#include <iostream>
#include <fstream>
using namespace std;
/*
 * Algorithm to count the number of unique arrangements of
 * pieces of candy
 * @n, the size (given in units of squares);
 * @s, the number of squares
 * @l, the number of long candies
 * @return the number of possible samplers
 */
long long naiiveAlgo(int n, int s, int l) {
    // Initialize the Arr.
    long long int Arr[n+1];

    // Set the first position of the array to 1.
    Arr[0] = 1;
    // Set the second position of the array to the number of squares.
    Arr[1] = s;
    // For loop that iterates from the second position of the array till
    // it is less than or equal to the size of the sampler.
    for(int i=2; i <=n; i++){
        //Set the right ride of the equation to the position at i.
        Arr[i]=s*Arr[i-1]+l*Arr[i-2];
    }
    //return the number of possible samplers.
    return Arr[n];
}

/**
 * Main Function
 */
int main() {

    // Initialize variables.
    ifstream input;
    ofstream output;
    int p, size, squareCandy, longCandy;
    char inputFilename[] = "input.txt";
    char outputFilename[] = "output.txt";

    // Open the file for reading.
    input.open(inputFilename);
    // Base Case if file does not exist.
    if (!input.is_open()){
        cout << "Can't open input file input.txt!\n";
        exit(1);
    }

    // Open the file for writing.
    output.open(outputFilename);
    // Base Case if file can not be created.
    if (!output.is_open()) {
        cout << "Can't open output file!\n";
        exit(1);
    }

    // Gets the next character (an unsigned char) from the specified stream
    input >> p;
    // if loop to read in the files while it does not reach end of file
    // and is not equal the the new line character
    for(int i =0; i<p; i++){
        // Reads formatted input from a stream and sets the value from the input
        // file to size, squareCandy and longCandy
        input >> size;
        input >> squareCandy;
        input >> longCandy;
        // Sets the value (number of possible samplers) returned from
        // naiiveAlgo to results.
        long long int results = naiiveAlgo(size, squareCandy, longCandy);
        // Adds the value of result into the output file.
        output << results << endl;
    }
    // Closes the input file.
    input.close();
    // Closes the output file.
    output.close();
    return 0;
}