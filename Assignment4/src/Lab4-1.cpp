//============================================================================
// Name        : Lab4-1.cpp
// Author      : Kirby James
// Description : C++ program to prompt user for a student’s scores calculate the average and assign a letter grade.
// 				 Prints the data and calculated results in a nice format.
//				 There are 3 test scores which counts for 60% of the grade, there is a quiz score which counts for 10% of the grade,
//				 and programming assignments score which counts for 30% of the grade.
//				 Used a straight curve to assign letter grades:
//============================================================================

#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>

// USED PREPROCESSOR DIRECTIVES INSTEAD OF DECLARING CONSTANT VARIABLES
#define TEST_WEIGHT 0.60
#define ASSIGNMENT_WEIGHT 0.30
#define QUIZ_WEIGHT 0.10

using namespace std;

enum GRADE {DEFAULT, A, B, C, D, E, F};

float getTestAverage (int, int, int);
float getAverage (float, int, float);
GRADE getGrade (float);
bool validated (GRADE g);

// PROCESS:
float getTestAverage (int a, int b, int c) {
    return (a + b + c) / 3;
}

float getAverage (float a, int b, float c) {
    return (a * TEST_WEIGHT) + (b * QUIZ_WEIGHT) + (c * ASSIGNMENT_WEIGHT);
}

//
GRADE getGrade (float g) {
    if ( g <= 100 && g >= 90 ) return A;
    else if ( g <= 90 && g >= 80 ) return B;
    else if ( g <= 80 && g >= 70 ) return C;
    else if ( g <= 70 && g >= 60 ) return D;
    else if ( g <= 60 && g >= 0 )  return F;
    return DEFAULT;
}

/*
 * 90 - 100 = A
 * 80 - 90 	= B
 * 70 - 80	= C
 * 60 - 70	= D
 * ElSE 	= F
 */

// CORRESPONDS TO ITS EQUIVALENT GRADE:
bool validated (GRADE g) {
    switch (g) {
    case A:
    case B:
    case C:
    case D:
    case F:
	return true;
    default:
	return false;
    }
}

int main () {
    string	full_name,
		z = "//",
		x = " | ";

    int first_test,
	second_test,
	third_test,
	quiz_score;

    float assignment_score;

    cout << left << setw(60);
    cout << "Please enter your full name including your initial : "<< flush;
    	getline(cin, full_name);

    cout << endl;
    cout << left << setw(60);
    cout << "Please enter your 1st test score(Integer): " << flush;
    	cin >> first_test;

    cout << left << setw(60);
    cout << "Please enter your 2nd test score(Integer): " << flush;
    	cin >> second_test;

    cout << left << setw(60);
    cout << "Please enter your 3rd test score(Integer): " << flush;
    	cin >> third_test;

    cout << left << setw(60);
    cout << "Please enter your programming assignment score: " << flush;
    	cin >> assignment_score;

    cout << left << setw(60);
    cout << "Please enter your quiz score: " << flush;
    	cin >> quiz_score;
    cout << endl;

    float test_average = getTestAverage (first_test, second_test, third_test);
    float average = getAverage (test_average, quiz_score, assignment_score);

    cout << "//=======================================================================================================================//" << endl;
    cout << right << setw(60) << "RESULTS" << endl;
    cout << "//=======================================================================================================================//" << endl;
    cout << "//\t\tName: " 					<< right << setw(60) << full_name 	<< setw(41) << z << endl;
    if ( validated (getGrade (first_test)) ) {
	cout << "//\t\t1st test score: " 			<< right << setw(40) << first_test	<< setw(6) << x << (char)(64 + getGrade(first_test))	<< setw(44) << z << endl;
    }
    if ( validated (getGrade (second_test)) ) {
	cout << "//\t\t2nd test score: " 			<< right << setw(40) << second_test 	<< setw(6) << x << (char)(64 + getGrade(second_test))	<< setw(44) << z << endl;
    }
    if ( validated (getGrade (third_test)) ) {
	cout << "//\t\t3rd test score: " 			<< right << setw(40) << third_test	<< setw(6) << x << (char)(64 + getGrade(third_test))	<< setw(44) << z << endl;
    }
    if ( validated (getGrade (assignment_score)) ) {
	cout << "//\t\tProgramming score: " 			<< right << setw(40) << setprecision(2) << showpoint << fixed << assignment_score << x << (char)(64 + getGrade(assignment_score)) << setw(44) << z << endl;
    }
    if ( validated (getGrade (quiz_score)) ) {
	cout << "//\t\tQuiz score: " 				<< right << setw(44) << quiz_score 	<< setw(6) <<  x << (char)(64 + getGrade(quiz_score))	<< setw(44) << z << endl;
    }
    else {
	cout << "//\t\tInvalid data, sorry! see you again next semester" << endl;
    }
    cout << "//\t\tTest Average: " 				<< right << setw(45) << test_average 	 << x << (char)(64 + getGrade(test_average))	<< setw(44) << z << endl;
    cout << "//\t\tYour Final Average: " 			<< right << setw(39) << average 	 << x << (char)(64 + getGrade(average))         << setw(44) << z << endl;
    cout << "//=======================================================================================================================//" << endl;

    return 0;

	/*
	"#######################################"
	"# Submitted by: Kirby James Fernandez #"
	"#######################################"
	*/
}
