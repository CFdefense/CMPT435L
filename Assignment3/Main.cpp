#include <fstream>
#include <vector>
#include <iostream>
#include <string>

using namespace std;

int main() {

    //! File Reading and Manipulation

    // Counting Vertices
    int vCount = 0;

    //Dynamic Array to Hold Edges
    vector<int> edgePairs;
    //for use of edgepairs: edgePairs.push_back(1); cout << edgePairs.size() << endl;

    //Other Variables
    string fileLine;

    // Open File to be Read
    ifstream myFile ("magicitems.txt");
    
    if(!myFile) {
        cout << "File Could Not Be Read" << endl;
    } else {
        // Check to see if file s
        while(!myFile.eof()) {

            // get next line from file to manipulate
            getline(myFile, fileLine);

            //Filter and Manipulate Inputs
            for(std::string::size_type i = 0; i < fileLine.length(); i++) {
                //Look for an A or a for 'add'
                if(int(fileLine[i] == 65) || int(fileLine[i] == 97)) {
                    //traverse rest of string to find numbers to be pulled
                    for(std::string::size_type j = i+1; i < fileLine.length(); i++) {
                        //if multiple numbers back to back
                        if()

                        //if only one number
                        if()
                    }

                }
            }
        }
    }


    return 0;
}