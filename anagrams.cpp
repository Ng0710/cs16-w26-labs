#include <iostream>
#include <string>
#include <cctype>
using namespace std;

//pre-condition: takes in a string
//post condition: returns a string that only has lowercase letters
string clean_string(string line);

// pre-condition: takes in two strings
// post-condition: returns true if the two strings are anagrams and false if they are not.
bool IsAnagram(string line1, string line2);

int main()
{
	// string decleration
    	string entry1, entry2;
	cout<< "Enter first string:" << endl;
	getline(cin, entry1);
	cout << "Enter second string:" << endl;
	getline(cin, entry2);

	//check to see if the inputs are anagrams
	if(IsAnagram(entry1, entry2) == 0)
	    cout << "The strings are not anagrams." << endl;
	else
	    cout << "The strings are anagrams." << endl;

    return 0;
}

string clean_string(string line){
    //new empty string to be added to
    string clean = "";
    // interates over a string and only adds letters to the clean string
    for(int i= 0; i < line.length(); i++)
        if(isalpha(line[i]))
            clean += tolower(line[i]);
            
    return clean;
    
}

bool IsAnagram(string line1, string line2){
    // declares strings and calls on the clean_string function
    string cl1, cl2;
    cl1 = clean_string(line1);
    cl2 = clean_string(line2);
    
    //checks to see if the lengths of the strings are the same
    if(cl1.length() != cl2.length())
        return false;
    // count array to hold the value of each letter
    int count[26] = {0};
    
    //takes each letter in each string and finds the difference between their ASCII value
    for(int i = 0; i < cl1.length(); i++){
        count[cl1[i] - 'a']++;
        count[cl2[i] - 'a']--;
    }
    // checks to see if all indexs of count array = 0
    for(int i = 0; i < 26; i ++)
        if(count[i] != 0)
            return false;
    
    return true;
    
}
