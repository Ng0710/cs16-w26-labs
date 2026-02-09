#include <iostream> // for cin, cout
#include <vector>   // for vector
#include <string>   // for getline()
// YOU ARE NOT ALLOWED TO INCLUDE ANY OTHER LIBRARY!!! (zero grade penalty)
using namespace std;

// FUNCTION DECLARATION: YOU MUST DEFINE AND USE THIS (do not remove):
//      You can declare/define other functions if you like as well,
//      but you must use function split() below.
vector<string> split(string target, string delimiter);

int main() {
    string line1, line2;
    cout << "Enter string to split:" << endl;
    getline(cin, line1);
    if (line1.length() == 0){
	return 0;
    }
    cout << "Enter delimiter string:" << endl;
    getline(cin, line2);
    if (line2.length() == 0){
	return 0;
    }
    cout << "The substrings are:";
    vector<string> result = split(line1,line2);
    for(int i = 0; i < result.size(); i++){
	if (i < result.size() - 1)
		cout <<"\"" << result[i] <<"\", ";
	else
		cout <<"\"" << resultd[i] << "\""<< endl;
       }
    return 0;
}

// MISSING FUNCTION DEFINITIONS HERE 
// Make sure you have Pre-Conditions and Post-Conditions defined for each function you define here!
// (you can remove these comments)

//pre-condition: takes in two strings
//post-condition: returns a vector that has the parts of the first string in each index seperated based on the delimiter

vector<string> split(string target, string delimiter){
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
