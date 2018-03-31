/*
 * Authors: Sakeena Patanwala, Diego Hernandez, Kyle Kaplan
 * Date: 3/31/2018
 * Project: Dynamic Programming
 * Description: In this file, we developed an algorithm to count the number of unique arrangements of
 * pieces of candy. The algorithm takes in 3 parameters, the size of the candy sampler, the number of
 * different square candies, and the number of different long candies. The algorithm computes the number
 * of unique combinations of square and long candies that yields different samplers within the given
 * sampler size.
 */

#include <iostream>
#include <fstream>
using namespace std;

long long candyAlgorithm(int n, int s, int l){
    int i;
    long long int array1[n+1]; //long long is used instead due to large numbers

    array1[0] = 1; //base case
    array1[1] = s; //base case

    for( i = 2; i <= n ; i++ ){
        array1[i]= s*array1[i-1]+l*array1[i-2]; //RECURRENCE
    }

    return array1[n];
}

int main(){
    int i, numInstances, n, s, l;
    long long int varieties;

    ifstream inFile;
    ofstream outFile;

    inFile.open("../input.txt"); //tests if input.txt is succesfully opened, if not, an error given.
    if(!inFile.is_open()){
        cout << "Error: input.txt not opened!" << endl;
        exit(1);
    }

    outFile.open("../output.txt");

    inFile >> numInstances; //inputs how many test cases to test

    for(i = 0; i < numInstances ; i++){ //iterates through however many test cases are given
        inFile >> n; //inputs size of sampler candy
        inFile >> s; //inputs number of different square candy
        inFile >> l; //inputs number of different long candy

        varieties = candyAlgorithm(n, s, l); //stores number of varieties for current instance

        outFile << varieties << endl; //outputs current instance to the output file
    }

    inFile.close();
    outFile.close();

    return 0;
}