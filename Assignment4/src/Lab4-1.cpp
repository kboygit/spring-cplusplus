//============================================================================
// Name        : Lab4-1.cpp
// Author      : Kirby James
// Description : C++ program to prompt user for a student’s scores calculate the average and assign a letter grade.
// 		 Prints the data and calculated results in a nice format.
//		 There are 3 test scores which counts for 60% of the grade, there is a quiz score which counts for 10% of the grade,
//		 and programming assignments score which counts for 30% of the grade.
//		 Used a straight curve to assign letter grades:
//============================================================================

/************************ Analysis *****************************
 1. Data needed:
	Name (Full name first and last including initial)
	three test scores
	assignment score
	quiz score

 2. Constants given:
	Test Weight set to 60%
	Assignment Weight set to 30%
	Quiz Weight set to 10%

************************ Algorithm *****************************
Step 1: Input
	Prompt User for Name (string)
		First name
		Initial
		Last name
	Prompt User for first test score(integer)
	Prompt User for second test score(integer)
	Prompt user for third test score(integer)
	Prompt User for assignment score(real no.)
	Prompt User for quiz score(integer)

		if input is between 90 - 100 the grade equivalent is A
		if input is between 80 - 90 the grade equivalent is B
		if input is between 70 - 80 the grade equivalent is C
		if input is between 60 - 70 the grade equivalent is D
		if input is between 0 - 60 the grade equivalent is F
		else Invalid Data

Step 2: Process
	Test Average = (first_test + second_test + third_test) / 3
	Average = (Test Average * test_weight) + (assignment_score * assignment_weight) + (quiz_score * quiz_weight)

Step 3: Output in a box format
	set precision of real numbers to 2
	Print Full Name with an informative label on line 1
	Print first test score with descriptive label and beside its equivalent grade
	Print second test score with descriptive label and  beside its equivalent grade
	Print third test score with descriptive label and beside its equivalent grade
	Print programming/assignment score with descriptive label and beside its equivalent grade
	Print quiz score with descriptive label and beside its equivalent grade
	Print Test Average with descriptive label and beside its equivalent grade
	Print Final Average with descriptive label and beside its equivalent grade
************************ End of Algorithm *****************************/


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
 * 90 - 100 	= A
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

    // INPUT:
    cout << left << setw(60);
    cout << "Please enter your full name including your initial : "<< flush;
    	getline(cin, full_name);
    	if (!cin) {
    		cout << "Please input your full name including your initial!";
    		exit(0);
    	}
    	else if (full_name != full_name){
    		cout << "Invalid data";
    		exit(0);
    	}

    cout << endl;
    cout << left << setw(60);
    cout << "Please enter your 1st test score(Integer): " << flush;
    	cin >> first_test;
    	if (!cin) {
    		cout << "Not an integer" << endl;
    		cout << "You can run again the program!" << endl;
    		exit(0);
    	}
    	else if (first_test < 0 || first_test > 100) {
    		cout << "Not in range";
    		cout << "You can run again the program!" << endl;
    		exit(0);
    	}

    cout << left << setw(60);
    cout << "Please enter your 2nd test score(Integer): " << flush;
    	cin >> second_test;
    	if (!cin) {
    		cout << "Not an integer" << endl;
    		cout << "You can run again the program!" << endl;
    		exit(0);
    	}
    	else if (first_test < 0 || first_test > 100) {
    		cout << "Not in range";
    		cout << "You can run again the program!" << endl;
    		exit(0);
    	}

    cout << left << setw(60);
    cout << "Please enter your 3rd test score(Integer): " << flush;
    	cin >> third_test;
    	if (!cin) {
    		cout << "Not an integer" << endl;
    		cout << "You can run again the program!" << endl;
    		exit(0);
    	}
    	else if (first_test < 0 || first_test > 100) {
    		cout << "Not in range";
    		cout << "You can run again the program!" << endl;
    		exit(0);
    	}

    cout << left << setw(60);
    cout << "Please enter your programming assignment score: " << flush;
    	cin >> assignment_score;
    	if (!cin) {
    		cout << "Not a real number" << endl;
    		cout << "You can run again the program!" << endl;
    		exit(0);
    	}
    	else if (assignment_score < 0 || assignment_score > 100) {
    		cout << "Not in range";
    		cout << "You can run again the program!" << endl;
    		exit(0);
    	}

    cout << left << setw(60);
    cout << "Please enter your quiz score: " << flush;
    	cin >> quiz_score;
    	if (!cin) {
    		cout << "Not an integer" << endl;
    		cout << "You can run again the program!" << endl;
    		exit(0);
    	}
    	else if (quiz_score < 0 || quiz_score > 100) {
    		cout << "Not in range";
    		cout << "You can run again the program!" << endl;
    		exit(0);
    	}
    cout << endl;

    // PROCESS:
    float test_average = getTestAverage (first_test, second_test, third_test);
    float average = getAverage (test_average, quiz_score, assignment_score);

    // OUTPUT:
    cout << "//=======================================================================================================================//" << endl;
    cout << right << setw(60) << "RESULTS" << endl;
    cout << "//=======================================================================================================================//" << endl;
    cout << "//\t\tName: " 				<< right << setw(60) << full_name 	<< setw(41) << z << endl;
    if ( validated (getGrade (first_test)) ) {
	cout << "//\t\t1st test score: " 		<< right << setw(40) << first_test	<< setw(6) << x << (char)(64 + getGrade(first_test))	<< setw(44) << z << endl;
    }
    if ( validated (getGrade (second_test)) ) {
	cout << "//\t\t2nd test score: " 		<< right << setw(40) << second_test 	<< setw(6) << x << (char)(64 + getGrade(second_test))	<< setw(44) << z << endl;
    }
    if ( validated (getGrade (third_test)) ) {
	cout << "//\t\t3rd test score: " 		<< right << setw(40) << third_test	<< setw(6) << x << (char)(64 + getGrade(third_test))	<< setw(44) << z << endl;
    }
    if ( validated (getGrade (assignment_score)) ) {
	cout << "//\t\tProgramming score: " 		<< right << setw(40) << setprecision(2) << showpoint << fixed << assignment_score << x << (char)(64 + getGrade(assignment_score)) << setw(44) << z << endl;
    }
    if ( validated (getGrade (quiz_score)) ) {
	cout << "//\t\tQuiz score: " 			<< right << setw(44) << quiz_score << setw(6) <<  x << (char)(64 + getGrade(quiz_score))	<< setw(44) << z << endl;
    }
    else {
	cout << "//\t\tInvalid data, sorry! see you again next semester" << endl;
    }
    cout << "//\t\tTest Average: " 			<< right << setw(45) << test_average	 << x << (char)(64 + getGrade(test_average))	<< setw(44) << z << endl;
    cout << "//\t\tYour Final Average: " 		<< right << setw(39) << average 	 << x << (char)(64 + getGrade(average))		<< setw(44) << z << endl;
    cout << "//=======================================================================================================================//" << endl;

    return 0;

	/*
	"#######################################"
	"# Submitted by: Kirby James Fernandez #"
	"#######################################"
	*/
}

