//============================================================================
// Name        : Lab3-1.cpp
// Author      : Kirby James Fernandez
// Version     :
// Copyright   :
// Description : Calculate the average for a given student based on the following
// information, each student has 3 test scores (60% of the grade), one quiz(10% of the grade)
// and a score for programming assignments(30% of the grade). Prompt user for their name and
// scores, then calculate the average and print the results in a nicely formatted.
//============================================================================

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main() {
	string	full_name,
		xtra = "//";

	int 	first_test,
		second_test,
		third_test,
		quiz_score;

	double	assignment_score;

	float	test_weight 		= 0.60,
		assignment_weight 	= 0.30,
		quiz_weight 		= 0.10;

	cout << left << setw(60);
	cout << "Please enter your full name including your initial: " << flush;
		getline(cin, full_name);

	/*
	 * 	ANOTHER OPTION:
	 * 	cout << "Please enter your three test score: " << flush;
	 * 	cin >> first_test >> second_test >> third_test;
	 */

	// Input:
	cout << endl;
	cout << left << setw(60);
	cout << "Please enter your 1st test score(Integer): "		<< flush;
		cin >> first_test;

	cout << left << setw(60);
	cout << "Please enter your 2nd test score(Integer): "		<< flush;
		cin >> second_test;

	cout << left << setw(60);
	cout << "Please enter your 3rd test score(Integer): "		<< flush;
		cin >> third_test;

	cout << left << setw(60);
	cout << "Please enter your programming assignment score: "	<< flush;
		cin >> assignment_score;

	cout << left << setw(60);
	cout << "Please enter your quiz score: " 			<< flush;
		cin >> quiz_score;
	cout << endl;

	// Process:
	int 	test_avg = (first_test + second_test + third_test) / 3;
	double	average = (test_avg * test_weight) + (quiz_score * quiz_weight) + (assignment_score * assignment_weight);


	// Output:
	cout << "//=======================================================================================================================//" << endl;
	cout << right << setw(60) << "RESULTS" << endl;
	cout << "//=======================================================================================================================//" << endl;
	cout << "//\t\tName: " 				<< right << setw(60) << full_name 	<< setw(41) << xtra << endl;
	cout << "//\t\t1st test score: " 		<< right << setw(40) << first_test	<< setw(51) << xtra << endl;
	cout << "//\t\t2nd test score: " 		<< right << setw(40) << second_test 	<< setw(51) << xtra << endl;
	cout << "//\t\t3rd test score: "		<< right << setw(40) << third_test 	<< setw(51) << xtra << endl;
	cout << "//\t\tTest Average: " 			<< right << setw(42) << test_avg 	<< setw(51) << xtra << endl;
	cout << "//\t\tQuiz score: " 			<< right << setw(44) << quiz_score 	<< setw(51) << xtra << endl;
	cout << "//\t\tProgramming score: " 		<< right << setw(40) << setprecision(2) << showpoint << fixed << assignment_score << setw(48) << xtra << endl;
	cout << "//\t\tYour Final Average: " 		<< right << setw(39) << average 	<< setw(48) << xtra << endl;
	cout << "//=======================================================================================================================//" << endl;

	/*
	"#######################################"
	"# Submitted by: Kirby James Fernandez #"
	"#######################################"
	*/

	return 0;
}
