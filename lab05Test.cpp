// IMPORTANT NOTE TO USER: 
// The only parts of the program that you should change are:
// 1. The function definitions that are currently on lines 30-32.
// 2. The addition of more test cases in the main() function.
// PLEASE LEAVE ALL OTHER CODE (especially the ASSERT_EQUAL() functions) AS-IS!
//
#include <iostream>
#include <cstdlib> 
#include <cmath>
#include <string>
#include <vector>
// YOU ARE NOT ALLOWED TO INCLUDE ANY OTHER LIBRARY!!! (zero grade penalty)

using namespace std;

// FYI, templates are a way to make a variable type "flexible".
// We'll cover these at some point, but for now just leave these alone.
template <typename T>
void ASSERT_EQUAL(T, T);

template <typename T>
void ASSERT_EQUAL(const vector<T>&, const vector<T>&);

// FUNCTION DECLARATIONS: YOU MUST DEFINE AND USE THESE IN THE TESTS (do not remove):
vector<string> split(string target, string delimiter);
int bin2d(string binstring);
string dec2bh(string sdec, char bh);

// THE FOLLOWING DEFINITIONS FOR THE 3 FUNCTIONS ARE STUBS.
// REMOVE THEM AND THEN COPY YOUR OWN 3 FUNCTION DEFINITIONS:
vector<string> split(string target, string delimiter) { 
	// variable declarations
        string temp;
        vector<string> result;
        int t;
        // while loop that will run as along as the target string still has the delimiter in it
        while(t = target.find(delimiter) != string::npos){
                // adding each part of the string to the vector
                int d = delimiter.length();
                int t = target.find(delimiter);
                temp = target.substr(0,t);
		if(!temp.empty())
                	result.push_back(temp);
                target.erase(0, (t+d));
        }
        result.push_back(target);
        return result;
}

int bin2d(string binstring) { 
 // variable decleration
        int result = 0, temp = 0, count = 0;

        //check if the number is binary
        for(int i = 0; i < binstring.length(); i++){
                if (binstring[i] != '1' && binstring[i] != '0')
                        return -1;
                }
        // for loop to convert
        for (int i = (binstring.length()-1); i >= 0; i --){
                temp = binstring[count] - 48;
                result += pow(2,i) * temp;
                ++count;
        }
        return result;
}

string dec2bh(string sdec, char bh){
     // variable decleration
    string result;
    int num, rem;
    num = stoi(sdec);
    // converting to binary
    if(bh == 'b'){
        while(num != 0){
            rem = num % 2;
            if(rem == 1)
                result += '1';
            else
                result += '0';
            num = num / 2;
        }

    }
    if(bh == 'h'){
        while(num != 0){
            rem = num % 16;
            switch(rem){
                case 0:
                    result += '0';
                    break;

                case 1:
                    result += '1';
                    break;

                case 2:
                    result += '2';
                    break;

                case 3:
                    result += '3';
                    break;

                case 4:
                    result += '4';
                    break;

                case 5:
                    result +='5';
                    break;

                case 6:
                    result += '6';
                    break;

                case 7:
                    result += '7';
                    break;

                case 8:
                    result += '8';
                    break;

                case 9:
                    result += '9';
                    break;

	        case 10:
                    result += 'A';
                    break;

                case 11:
                    result += 'B';
                    break;

                case 12:
                    result += 'C';
                    break;

                case 13:
                    result += 'D';
                    break;

                case 14:
                    result += 'E';
                    break;

                case 15:
                    result += 'F';
                    break;
            }
            num = num / 16;
        }
    }
    // reversing the string so it is not backwards
    int n = result.length();
    char t;
    for (int i = 0; i < n/2; i++){
        t = result[i];
        result[i] = result[n-i- 1];
        result[n - i - 1] = t;
    }
    return result;
}


int main() {
    cout << "Testing split..." << endl;    
    vector<string> answer;

    // Testing split function
    answer = {"Apples", "Bananas", "Cherries", "Dragon Fruits", "Elderberries"};
    ASSERT_EQUAL(answer, split("Apples,Bananas,Cherries,Dragon Fruits,Elderberries", ","));

    answer = {"The", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dog"};
    ASSERT_EQUAL(answer, split("The quick brown fox jumps over the lazy dog", " "));

    answer = {"It w", "s r", "re, I w", "s there."};
    ASSERT_EQUAL(answer, split("It was rare, I was there.", "a"));

    answer = {"Can you hear me?", " - The Machine"};
    ASSERT_EQUAL(answer, split("\"Can you hear me?\" - The Machine", "\""));

    answer = {"10", "20", "30", "40"};
    ASSERT_EQUAL(answer , split("10,20,30,40", ","));

    answer = {"a", "b", "c", "d"};
    ASSERT_EQUAL(answer , split("a:b:c:d", ":"));
    // Feel free to add additional test cases and edge cases
    // answer = {}
    // ASSERT_EQUAL(answer, split("", ""));


    cout << endl << "Testing bin2d..." << endl;
    // Testing binary to decimal
    ASSERT_EQUAL(0, bin2d("0"));
    ASSERT_EQUAL(2, bin2d("10"));
    ASSERT_EQUAL(6, bin2d("110"));
    ASSERT_EQUAL(9,bin2d("1001"));
    ASSERT_EQUAL(45,bin2d("101101"));
    ASSERT_EQUAL(246, bin2d("11110110"));

    cout << "Testing dec2hb..." << endl;
    // Testing decimal to binary
    ASSERT_EQUAL(string("1010"), dec2bh("10", 'b'));
    ASSERT_EQUAL(string("1111"), dec2bh("15", 'b'));
    ASSERT_EQUAL(string("1100100"), dec2bh("100", 'b'));
    ASSERT_EQUAL(string("110"), dec2bh("6", 'b'));

    // Testing decimal to hex conversion
    ASSERT_EQUAL(string("A"), dec2bh("10", 'h'));
    ASSERT_EQUAL(string("64"), dec2bh("100", 'h'));
    ASSERT_EQUAL(string("6"), dec2bh("6", 'h')); 

    // Feel free to add additional test cases and edge cases
    // ASSERT_EQUAL(string("64"), dec2bh("100", 'h')); 


    return 0;
}


// Template function to compare expected and actual values.
// If the values match, it prints a "PASSED" message; otherwise, a "FAILED" message.
template <typename T>
void ASSERT_EQUAL(T expected, T actual) {
    if (expected == actual) {
        cout << "PASSED: Expected and actual values are equal: " << expected << endl;
    } else {
        cout << "FAILED: Expected " << expected << " but got " << actual << endl;
    }
}

template <typename T>
void ASSERT_EQUAL(const vector<T>& expectation, const vector<T>& actuality) {
    T expect;
    T actual;
    if (expectation.size() != actuality.size()) {
	    cout << "FAILED: Expected vector of size " << expectation.size() << " but got " << actuality.size() << endl;
	    return;
    }
    for (size_t i = 0; i < min(expectation.size(), actuality.size()); i++) {
	    expect = expectation[i];
	    actual = actuality[i];
    	if (expect == actual) continue;
        cout << "FAILED: With index=" << i << ", Expected " << endl << "\t\"" << expect << "\"\n" << "\tbut got " << endl << "\t\"" << actual << "\"\n";
	    return;
    }

    cout << "PASSED: Expected and actual values are equal:";
    for (const T& expect: expectation) cout << endl << "\t" << expect;
    cout << endl << endl;    
}

