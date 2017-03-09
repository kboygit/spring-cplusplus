//============================================================================
// Name        : Lunch.cpp
// Author      : Kirby James
// Version     :
// Copyright   : N/A
// Description : Program Lunch calculates the number of calories in a cheese sandwich.
// Each sandwich contains 2 slices of bread, 3 slices of cheese, 4 pieces of pickles,
// and 2 grams of mayonnaise.
//============================================================================

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main() {
	// Local Variable Decalariation of Constants
	const int BREAD = 63;			// calories in a slice of bread
	const int CHEESE = 106;			// calories in a slice of cheese
	const int MAYONNAISE = 49;		// calories in 1 gram of mayonnaise
	const int PICKLE = 25;			// calories in a slice of pickle

	// Initialize
	string full_Name;
	int	bread_Slices,
		cheese_Slices,
		mayo_Amount,
		pickle_Pieces;


							// ERROR : PICKLES instead of PICKLE
							// FIRST OUTPUT : 243 expected is 642
	/*TotalCalories = BREAD + CHEESE + MAYONNAISE + PICKLE; */

	cout << right << setw(65) << "Welcome to my Calorie Counter." << endl;
	cout << left << setw(25) << "\nPlease enter your name:" << flush;
		getline(cin, full_Name);

	cout << "Hi " << full_Name << ", please enter number of ingredient used on your sandwich.\n" << endl;

	cout << left << setw(70);
	cout << "Please enter number of slices of bread used (0 if not used):" 		<< flush;
		cin >> bread_Slices;	// 2
	cout << left << setw(70);
	cout << "Please enter number of slices of cheese used (0 if not used):"		<< flush;
		cin >> cheese_Slices;	// 3
	cout << left << setw(70);
	cout << "Please enter amount of mayonnaise in grams used (0 if not used): "	<< flush;
		cin >> mayo_Amount;	// 2
	cout << left << setw(70);
	cout << "Please enter number of pieces of pickle used (0 if not used):" 	<< flush;
		cin >> pickle_Pieces;	// 4

	float 	bread_Calories = BREAD * bread_Slices,
		cheese_Calories = CHEESE * cheese_Slices,
		mayo_Calories = MAYONNAISE * mayo_Amount,
		pickle_Calories = PICKLE * pickle_Pieces;

	float TotalCalories = (bread_Calories) + (cheese_Calories) + (mayo_Calories) + (pickle_Calories);

	cout << left << setw(31) << "\nBread calories:"		<< setprecision(2) << showpoint << fixed << bread_Calories << endl;
	cout << left << setw(30) << "Cheese calories:"		<< cheese_Calories 					   << endl;
	cout << left << setw(30) << "Mayonnaise calories:"	<< mayo_Calories					   << endl;
	cout << left << setw(30) << "Pickle calories:"		<< pickle_Calories					   << endl;
	cout << left << setw(30) << "\nTotal calories:"		<< TotalCalories					   << endl;

	cout << "\nThere were " << TotalCalories << " calories in your lunch yesterday." << endl;
	cout << "What is for lunch today? Funny!!!!\n" << endl;

	/* Submitted by: Kirby */
	cout << right << setw(70) << "#######################################" << endl;
	cout << right << setw(70) << "# Submitted by: Kirby James	    #" << endl;
	cout << right << setw(70) << "#######################################" << endl;

	return 0;
}
