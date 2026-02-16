// Include statements go here...
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <fstream>
#include <cstdlib>
using namespace std;

// FUNCTION DECLARATIONS: YOU MUST DEFINE AND USE THESE (do not remove):
//      You can declare/define other functions if you like as well,
//      but you must use the 3 functions below.
// See lab description for more on these functions.

string findLastWord(string line);
void cleanUp(string &word);
bool compareWords(string word1, string word2);

int main() {
    // MISSING CODE HERE (you can remove these comments)
    // Create input stream object, then get a filename from user (check it too)
    // Read the lines in your file and check on rhyming, per our definition
    // Finally, print the results (see lab descriptions for examples)
    
    string filename;
    cout << "Enter file name: ";
    cin >> filename;
    
    ifstream inFile(filename);
    if (inFile.fail()){
	cerr << "Cannot open " << filename << endl;
	exit(1);
        }
    string currentLine, currentLastWord, previousLastWord;
    int lineCount = 0;
    int rhymeCount = 0;

    while(getline(inFile, currentLine)){
	if(currentLine.empty())
		continue;
	lineCount++;
	currentLastWord = findLastWord(currentLine);
	cleanUp(currentLastWord);
	if(lineCount > 1){
		if(currentLastWord.size() >= 2 && previousLastWord.size() >= 2){
			if(compareWords(currentLastWord, previousLastWord)){
				cout << previousLastWord << " and " << currentLastWord << endl;
				rhymeCount++;
				}
			}
		}
	previousLastWord = currentLastWord;
    }
    
    cout << fixed << showpoint;
    cout << setprecision(2);
    if (rhymeCount > 0) {
	if(rhymeCount > 1){
		cout << "There is " << rhymeCount << " pairs of rhyming words." << endl;
		cout << "There is " << lineCount << " lines in this poem, so the rhyme-line density is: " << (double)rhymeCount/lineCount << endl;
	}
	else{
		cout << "There is " << rhymeCount << " pair of rhyming words." << endl;
		cout << "There is " << lineCount << " lines in this poem, so the rhyme-line density is: " << (double)rhymeCount/lineCount << endl;
		}
	}
     else{
	cout << "No rhymes found." << endl;
	cout << "There are " << lineCount << " lines in this poem." << endl;		
		}
    inFile.close();
    return 0;
}

// MISSING FUNCTION DEFINITIONS HERE
// Make sure you have Pre-Conditions and Post-Conditions defined for each function you define here!
// (you can remove these comments)

//precondition: takes in a string 
//post condtion: returns the last word of the string

string findLastWord(string line){
	//finding index of the start of the last word
	int l = line.rfind(" ");

	//finding the last word
	string result = line.substr(l, (line.size()-1));
	return result;
}

//precondition: takes in a string that contains a word and punctiation
//post condition: returns a word with only lettes in the string

void cleanUp(string &word){
	//setting a temp string to sort into
	string temp;

	//cleaning up the word string to have only letters in it
	for (int i = 0; i < word.size(); i++){
		if (isalpha(word[i]))
			temp += word[i];
	}
	word = temp;
}

//precondition: Takes in two strings that have words
//postcondition: returns trues if the words rhyme and false if they do not

bool compareWords(string word1, string word2){
	// collecting the sizes of the words
	int size1 = word1.size();
	int size2 = word2.size();

	//comparing the two words to see if they rhyme
	if ((word1[size1 - 1] == word2[size2 - 1]) && (word1[size1 - 2] == word2[size2 - 2]))
		return true;
	else 
		return false;
}
