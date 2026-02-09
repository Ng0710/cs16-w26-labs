#include <iostream> // for cin, cout, endl
#include <cstdlib>  // for exit()
#include <cmath>    // for pow() function ONLY
// YOU ARE NOT ALLOWED TO INCLUDE ANY OTHER LIBRARY!!! (zero grade penalty)
using namespace std;

// FUNCTION DECLARATIONS: YOU MUST DEFINE AND USE THESE (do not remove):
//      You can declare/define other functions if you like as well,
//      but you must use the 2 functions below.
int bin2d(string binstring);
string dec2bh(string sdec, char bh);

int main ( int argc, char *argv[] ) {

    // MISSING CODE HERE (you can remove these comments)
    // Check to see if the command-line arguments are being used correctly
    // Perform the conversion by calling the appropriate function
    // What happens next?!!?
    cout << "Usage: converter <options: d2b, d2h, b2d> <value>" << endl;
    if (argc != 3){
	cerr << "Number of arguments incorrect" << endl;
	return 0;
	}
    string type = argv[1];
    string num = argv[3];
    if(type == "d2b"){
	cout <<"The value in binary is: " << dec2bh(num, 'b') << endl;
	return 0;
	}
    else if (type == "d2h"){
	cout << "The value in hexadecimal is: " << dec2bh(num, 'h') << endl;
	return 0;
	}
    else if (type == "b2d"){
	if(bin2d(num) != -1){
		cout << "The value in decimal is: " << bin2d(num) << endl;
		return 0;
		}
	else{
		cerr << "Binary value contains non-binary digits." << endl;
		}
	}
    else{
	cerr << "Conversion option not picked" << endl;
	}
    return 0;
}

// MISSING FUNCTION DEFINITIONS HERE 
// Make sure you have Pre-Conditions and Post-Conditions defined for each function you define here!
// (you can remove these comments)

//pre-condtion: takes in a binary string
//post-condtion: returns a int of the decimal conversion

int bin2d(string binstring){
	// variable decleration
	int result = 0, temp = 0, count = 0;
	
	//check if the number is binary
	for(int i = 0; i < binstring.length(); i++){
		if (binstring[i] != '1' || binstring[i] != '0')
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

//pre-condition: takes in a string in decimal form
//post condition: returns either the binary or hexadecimal version of the inputed number as a string based on if a char h or b is inputed
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
    //converting to hexadecimal
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

