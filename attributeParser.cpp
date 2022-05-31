#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
using namespace std;

string retruntags(string userInput)
{
    string totalString; 
    return totalString += userInput;
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    
    int line_num;
    int queries;
    string userInput;
    string tt;
    
    
    cin >> line_num >> queries;
    cin.ignore();
    
    int i = 0;
    while (i < line_num)
    {
        getline (cin, userInput);
        tt = retruntags(userInput);
        cout << tt;
        i++;
    }
    string q;
    cin >> q;
    cout << "\n" << q;

      
    return 0;
}
