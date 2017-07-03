#include <iostream>
#include <iomanip>
#include <string.h>
#define _USE_MATH_DEFINES
#include <math.h>
using namespace std; 

struct ComplexNumber{
    double r = 0; // real number denoted by r 
    double i = 0; // imageinary number denoted by i  
};

double Complex_Addition(ComplexNumber, ComplexNumber); 
double Complex_Subtraction(ComplexNumber,ComplexNumber);
double Complex_Division(ComplexNumber, ComplexNumber);
double Complex_Multiplication(ComplexNumber, ComplexNumber);
void homeMenu();


int main(){
    ComplexNumber A, B; 
    string firstNum, secondNum, firstCN, secondCN, firstIM, secondIM; 
    bool keepGoing = true;
    string delimitForA = "i"; 
    string delimitForB = "j";
    int menuChoice; 
    double total; 

    cout << "Enter the complex number A = ";
    getline(cin, firstNum);
	size_t pos = firstNum.find("i");
	firstCN = firstNum.substr(0, pos);
	firstIM = firstNum.substr(pos);
	A.r = stod(firstCN);
	A.i = stod(firstIM);

    cout << "Enter the complex number B = ";
	getline(cin, secondNum);

	pos = secondNum.find("i");
	secondCN = secondNum.substr(0, pos);
	secondIM = secondNum.substr(pos);
	B.r = stod(firstCN);
	B.i = stod(firstIM);
    do{
    homeMenu();

    		switch (menuChoice) {
		case(1): {

			total = Complex_Addition(A, B);

			cout << firstNum << " + " << secondNum << "=" << total << endl;
			break;
		}
		case(2): {
			total = Complex_Subtraction(A, B);
			cout << firstNum << " - " << secondNum << "=" << total << endl;
			break;
		}
		case(3): {
			total = Complex_Multiplication(A, B);
			cout << firstNum << " * " << secondNum << "=" << total << endl;
			break;
		}
		case(4): {
			total = Complex_Division(A, B);
			cout << firstNum << " / " << secondNum << "=" << total << endl;
			break;
		}
		case(5): {
			cout << "Exiting Program" << endl << endl;
            keepGoing = false;
		}
             
		}
    }while(keepGoing == true);
    return 0; 
}


void homeMenu(){
cout << R"(	Available Operations:
(1). C = A+B
(2). C = A-B
(3). C = A*B
(4). C = A/B
(5). Exit
)" << endl;
cout << "what operation would you like to preform >>";
}

double Complex_Addition(ComplexNumber a, ComplexNumber b) {
	

	double results;
	results = (a.r + b.r)+(a.i + b.i);
	

	return results;
}

double Complex_Subtraction(ComplexNumber a, ComplexNumber b) {

	double results;
	results = (a.r - b.r) + (a.i - b.i);
	 
	return results;
}

double Complex_Multiplication(ComplexNumber a, ComplexNumber b) {

	double results;
	results = ((a.r * b.r) - (a.i * b.i)) + ((a.r * b.i) + (a.i * b.r));

	return results;
}

double Complex_Division(ComplexNumber a, ComplexNumber b) {

	double results;
	results = (((a.r * b.r) + (a.i * b.i)) / ((b.i * b.i) + (b.r * b.r))) + (((a.i * b.r) - (a.r * b.i)) / ((b.i * b.i) + (b.r * b.r)));

	return results;
}
