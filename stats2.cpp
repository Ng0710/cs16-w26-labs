#include <iostream> // for cout, cin, endl
#include <cmath>    // for pow -- the only one you're allowed to use from this lib
#include <iomanip>  // for setprecision, setw -- the only ones you're allowed to use from this lib
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;


// FUNCTION DECLARATIONS: YOU MUST USE THESE (do not remove):
void bubbleSort(int *array, int size);
double average(int *array, int size);
double median(int* array, int size);
double stddev(int* array, int size);

int main() {
    // Sets the printing of floating-point numbers
    // to show only 2 places after the decimal point
    cout << fixed << showpoint;
    cout << setprecision(2);
    int *g = nullptr,n = 0;
    string filename;
    cout << "Enter filename: ";
    getline(cin,filename);
    ifstream inFile(filename);
    if (inFile.fail()){
	cerr << "Cannot open " << filename << endl;
	exit(1);
        }
    while ( inFile >> next)
	++n;
    if(n == 0 ){
        cout << "Error!";
        return 0;
        }
    g = new int[n];
    cout << "Enter grades (each of a new line):" << endl;
    for(int i = 0; i < n; i++){
        double num;
        if (inFile >> num){
         	g[i] = int(num);
        }
    }
	
    if(n > 0 ){
            cout << "Here are some statistics:" << endl;
            cout << "      N: " << n << endl;
            cout << "Average: " << average(g , n) << endl;
            cout << " Median: " << median(g, n) << endl;
            cout << " StdDev: " << stddev(g, n) << endl;
        }
    delete []g;
    g = nullptr;
    inFile.close();
    return 0;
}

// This is bubbleSort - it is given for you to use.
// Pre-Condition:: It takes in a dynamic int array and its size
// Post-Condition: It sorts the array in ascending order of its values
void bubbleSort(int *array, int size) {
  int temp;
  for (int i = size-1; i >= 0; i--) {
    for (int j = 1; j <= i; j++) {
      if (array[j-1] > array[j]) {
        temp = array[j-1];
        array[j-1] = array[j];
        array[j] = temp;
      } // if
    } // for j
  } // for i
}

//pre-condition: take in a dynamic int array and its size
//post-condition: return a value that is the average of all the entries in an array
double average(int* array, int size){
        //variable decleration
        double sum = 0, average;

        //for loop to add all the values of the array together
        for (int i = 0; i < size; i++)
                sum += array[i];

        //finding the average of the array
        average = sum/size;
        return average;
}


//pre-condition: takes in a dynamic int array and its size
//post-condition: returns the median of the array
double median(int* array, int size){
        //variable decleration
        double median;
        bubbleSort(array,size);
        //conditional statements to see if size is odd or even
        if (size % 2 == 0)
                median = array[(size/2) - 1] + double(array[size/2] - array[(size/2) - 1])/2;
        else
                median = array[(size/2)];
        return median;
}


//pre-condition:takes in a dynamic int array and its size
//post-condition: returns the standard deviation of the array

double stddev(int* array, int size){
        // variable decleration
        double avr = average(array, size);
        double sum = 0;
        double stddev = 0;
        if (size == 1)
                return stddev;
        //for loop to add all the values of the array
        for(int i = 0; i < size; i++)
                sum += pow((array[i] - avr), 2);

        //variable decleration to get the divisor
        double divi = ((double)1/(size-1));

        //finding the standard deviation
        stddev += pow(((divi)*(sum)),0.5);
        return stddev;
}




