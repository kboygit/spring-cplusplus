//============================================================================
// Name        : assignment-1.cpp
// Author      : Kirby James
//============================================================================

/************************ Analysis *****************************
	1. Data needed:
		Full Name
		Loan Amount
		Annual Interest Rate
		Loan Period in Years
	2. Constants:
		MAX ( set to 1000 using define )

************************ Algorithm *****************************
	Step 1: Input:
		Prompt User for Full Name (string)
		Prompt User if he/she like to create an amortization schedule
			Answers would be (y, Y) or (n, N)
			If user enter enter y Y it will execute the function amortizationDetails(proceed, name).
			Then if answers with a n N the program will stop, otherwise program will output blank then it will stop.

		Inside the amortizationDetails function:
			Declared local variables with specific datatypes:
				double loanAmount
				double annualInterestRate
				int numberOfYears
				double monthlyPayment
				int numberOfPayments
		Initialize these variables to zero:
			double totalInterest = 0
			double totalCostOfLoan = 0

		Prompt User for Loan Amount (No space and comma otherwise it will produce a blank output then stop):
			validates if the input is not true it will continue asking for the right input with descriptive sentence
		Prompt user for Annual Interest Rate
			validates if the input is not true it will continue asking for the right input with descriptive sentence
		Prompt User for Number of years to pay off loan
			validates if the input is not true it will continue asking for the right input with descriptive sentence

	Step 2: Process:
		Wherein:
		r = interest rate per period set to data type double
		n = total number of payments or periods set to data type integer
		r set to annualInterest Rate / ( 12 months x 100 )
		n set to number of years x 12

		Calculation for paymount amount:
        monthlyPayment = loanAmount * (r / ( 1 - ( (1+r)^-n )
        numberOfPayments = numberOfYears * 12

		declare array in variable names(set it to an empty array with a MAX equal to 1000):
		double endingBalance[MAX] = {}
        double monthlyInterestRate[MAX] = {}
        double principal[MAX] = {}

        USED A FOR LOOP, TO LOOP THROUGH EACH PAYMENTS UNTIL NUMBEROFPAYMENTS IS REACHED:
       	it will loop through each payments until it is less than numberOfPayments in this case is < 12 which is 11,
       	then increment it by +1:
			for (int x = 0; x < numberOfPayments; x++) {
					monthlyInterestRate[x] = loanAmount * ((annualInterestRate / 12) / 100);
					principal[x] = monthlyPayment - monthlyInterestRate[x];
					endingBalance[x] = loanAmount - principal[x];
					loanAmount -= principal[x];
					totalInterest += monthlyInterestRate[x];
			}

		set totalCostofLoan = totalCostofLoan + totalInterest

	Step 3: Output in a simple format:
		Print full name with an informative label on line 1
		Print loan amount with an informative label
		Print Annual Interest rate with descriptive label
		Print Monthly Payment with descriptive label
		Print number of payments which is number of years times 12
		Print total interest with descriptive label
		Print total cost of loan with descriptive label
		Prints the following in a box like format:
		(It will loop through all the possible calculations until it reaches to total number of payments)
			Payment No.
			Payment Amount
			Principal
			Interest
			Ending Balance
		Prompt the user again if he/she wants to create another amortization table
			Answers would be (y, Y) or (n, N)
			If user enter enter y Y it will execute the function amortizationDetails(proceed, name).
			Then if answers with a n N the program will stop, otherwise program will output blank then it will stop.
************************ End of Algorithm **********************/

#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
#define MAX 1000 // SET MAX TO 1000
using namespace std;

// CREATED A FUNCTION THAT WILL EXECUTE WHEN THE USER ANSWER A 'Y/y'
void amortizationDetails(char proceed, string name)
{

        double loanAmount;
        double annualInterestRate;
        int numberOfYears;

        double monthlyPayment;
        int numberOfPayments;
        double totalInterest = 0;
        double totalCostOfLoan = 0;

        cout << left << setw(55);
        cout << "Loan Amount(No space and comma!): ";
        cin >> loanAmount;
        while (!cin) {
        	cout << left << setw(55);
        	cout << "Loan Amount(No space and comma!): ";
        	cin.clear();
        	cin.ignore(128, '\n');
        	cin >> loanAmount;
        }

        cout << left << setw(55);
        cout << "Annual Interest Rate: ";
        cin >> annualInterestRate;
        while(!cin) {
        	cout << left << setw(55);
        	cout << "Annual Interest Rate: ";
        	cin.clear();
        	cin.ignore(128, '\n');
        	cin >> annualInterestRate;
        }

        cout << left << setw(55);
        cout << "Number of years to pay off the loan: ";
        cin >> numberOfYears;
        while(!numberOfYears) {
        	cout << left << setw(55);
        	cout << "Number of years to pay off the loan: ";
        	cin.clear();
        	cin.ignore(128, '\n');
        	cin >> numberOfYears;

        }
        cout << endl;

        cout << right << setw(58) << "Loan Payment Information for " << name << ":\n" << endl;

        cout << right << setw(37) << "Loan amount" 			 << right << setw(23) << fixed << showpoint << setprecision(2) << "$" << loanAmount << endl;
        cout << right << setw(47) << "Annual interest rate " << right << setw(17) << fixed << showpoint << setprecision(3) << annualInterestRate << "%" << endl;
        cout << right << setw(47) << "Loan period in years " << right << setw(13) << numberOfYears << endl;
        cout << endl;

        totalCostOfLoan = loanAmount;

        double endingBalance[MAX] = {};
        double monthlyInterestRate[MAX] = {};
        double principal[MAX] = {};

        double r = annualInterestRate / (12 * 100);
        int n = numberOfYears * 12;
        monthlyPayment = loanAmount * (r / (1 - pow(1 + r, -n)));

        numberOfPayments = numberOfYears * 12;

        // USED A FOR LOOP, TO LOOP THROUGH EACH PAYMENTS UNTIL NUMBEROFPAYMENTS IS REACHED
        for (int x = 0; x < numberOfPayments; x++) {
                monthlyInterestRate[x] = loanAmount * ((annualInterestRate / 12) / 100);
                principal[x] = monthlyPayment - monthlyInterestRate[x];
                endingBalance[x] = loanAmount - principal[x];
                loanAmount -= principal[x];
                totalInterest += monthlyInterestRate[x];
        }

        totalCostOfLoan += totalInterest;

        // OUTPUT OF ALL PAYMENTS
        cout << right << setw(46) << "Monthly payment     " << right << setw(14) << fixed << showpoint << setprecision(2) << "$" << monthlyPayment << endl;
        cout << right << setw(46) << "Number of payments  " << right << setw(15) << numberOfPayments << endl;
        cout << right << setw(46) << "Total interest      " << right << setw(14) << "$" << totalInterest << endl;
        cout << right << setw(46) << "Total cost of loan  " << right << setw(14) << "$" << totalCostOfLoan << "\n" << endl;

        cout << "Payment No. \t\t Payment Amount \t Principal \t Interest \t Ending Balance\n" << endl;
        for (int x = 0; x < numberOfPayments; x++) {
                cout << x + 1;
                cout << " \t ";
                cout << fixed << showpoint;
                cout << setprecision(2);
                cout << " \t\t ";
                cout << monthlyPayment;
                cout << " \t\t ";
                cout << principal[x];
                cout << " \t ";
                cout << monthlyInterestRate[x];
                cout << "   \t ";
                cout << endingBalance[x] << endl;

        }

        // AFTER OUTPUTTING ALL OF THE NUMBER OF PAYMENTS IT WILL ASK AGAIN IF USER WANTS TO CREATE ANOTHER TABLE
        cout << endl << "Do you like to create another amortization schedule [y/n]?: ";
        cin >> proceed;

        if (proceed == 'y' || proceed == 'Y'){
                amortizationDetails(proceed, name);
        }
        else {
                exit(0);
        }
}

int main()
{
        string name;
        char proceed;

        cout << left << setw(55);
        cout << "What is your full name?: ";
        getline(cin, name);

        cout << left << setw(55);
        cout << "Do you like to create an amortization schedule[y/n]?: ";
        cin >> proceed;
        if (proceed == 'y' || proceed == 'Y'){
        	amortizationDetails(proceed, name);
        }
        else {
        	exit(0);
        }
        return 0;
}
