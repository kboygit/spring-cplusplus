//============================================================================
// Name        : Assignment 2
// Author      : Kirby James
//============================================================================

/************************ Algorithm *****************************
	1. Data needed:
        A. Prompt user for the input file name
        B. Prompt user for the output file name

     3. Process:
        open the input file
        netIncome is equal to grossIncome minus tax
        totalnetIncome is totalIncome plus netIncome
        call the function getMinandMax to assess its grossIncome range


     4. Output:
        print out programmer name in the output file
        print out assignment no 6
        print out what this program does

        Header Format
        print out name, employee ID, gross income, taxes, net income in one line.

        I put comments as labels for the rest.

 Function getMinAndMax ( void )
    2 arguments passed (a double grossIncome and a string employeeName)
    I. initialize setInitial variable eq. to zero
            if setInitial is zero
            set maxNetIncome to grossIncome
            set minNetIncome to grossIncome

    II. initialize setInitial variable eq. to one
            if grossIncome is greater maxNetIncome
            assign maxNetIncome to grossIncome
            assign the name of employee having maxNetIncome

            if grossIncome is less than minNetIncome
            assign minNetIncome to grossIncome
            assign the name of employee having minNetIncome

 Function computeTax ( double )
    1 argument passed ( a double grossIncome )
    I. initialize tax eq. to zero
        if grossIncome greater than zero and less than 3500
        assign tax eq. to zero

        else if grossIncome greater or equal to 3500 and less than 8000
        assign tax to difference of grossIncome and 3500 times 6%

        else if grossIncome greater or equal to 8000 and less than 20000
        assign tax to 270 plus the difference of grossIncome and 8000 times 11%

        else if grossIncome greater or equal to 20000 and less than 34000
        assign tax to 1590 plus the difference of grossIncome and 20000 times 17%

        else if grossIncome greater or equal to 34000 and less than 54000
        assign tax to 3970 plus the difference of grossIncome and 34000 times 24%

        else if grossIncome is over 54000 or equal
        assign tax to 8770 plus the difference of grossIncome and 54000 time 32%

        else
        tax is negative 1

        then return the tax computed from the range of grossIncome


 Function validIdLength ( bool )
    1 argument passed ( an integer employeeId )
    I. Set variable valid to false
       Initialize counter to zero

    while employeeId ( condition proceed with the block inside )
    set employeeId divide by 10
    then increment it

    if counter equals to 4 valid is true
    then return valid whatever the condition it is
 ************************ End of Algorithm **********************/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

// Global variables
double totalNetIncome = 0, minNetIncome = 0, maxNetIncome = 0;
string minEmployeeName, maxEmployeeName;

int setInitial = 0;
void getMinAndMax(double grossIncome, string employeeName) { //
    if (setInitial == 0) {
        maxNetIncome = grossIncome;
        minNetIncome = grossIncome;
    }

    setInitial = 1;

    if (grossIncome > maxNetIncome) {
        maxNetIncome = grossIncome;
        maxEmployeeName = employeeName;
    }

    if (grossIncome < minNetIncome) {
        minNetIncome = grossIncome;
        minEmployeeName = employeeName;
    }
}

//
double computeTax(double grossIncome) {
    double tax = 0;

    if (grossIncome > 0 && grossIncome < 3500) {
        tax = 0;
    }
    else if (grossIncome >= 3500 && grossIncome < 8000) {
        tax = (grossIncome - 3500) * .06;
    }
    else if (grossIncome >= 8000 && grossIncome < 20000) {
        tax = 270 + ((grossIncome - 8000) * .11);
    }
    else if (grossIncome >= 20000 && grossIncome < 34000) {
        tax = 1590 + ((grossIncome - 20000) * .17);
    }
    else if (grossIncome >= 34000 && grossIncome < 54000) {
        tax = 3970 + ((grossIncome - 34000) * .24);
    }
    else if (grossIncome >= 54000) {
        tax = 8770 + ((grossIncome - 54000) * .32);
    }
    else {
        tax = -1;
    }
    return tax;
}

//
bool validIdLength(int employeeId) {
    bool valid = false;
    int counter = 0;

    while (employeeId) {
        employeeId = employeeId / 10;
        counter++;
    }

    if (counter == 4) {
        valid = true;
    }

    return valid;
}

//
int main() {

    int employeeId, employeeCounter = 0;
    double grossIncome, netIncome, averageIncome = 0, tax = 0;
    string iFileName, oFileName, employeeName;
    ifstream fin;
    ofstream fout;

    // Get the input filename from the user
    cout << "Please enter input file name: ";
    cin >> iFileName;

    cout << endl;

    //Get the output filename from the user
    cout << "Please enter output file name: ";
    cin >> oFileName;

    // Open the file
    fin.open(iFileName.c_str());
    // If the file successfully opened, process it
    if (fin) {
        fout.open(oFileName.c_str());

        fout << "Programmer: " << setw(30) << "Kirby Fernandez" << endl;
        fout << "Programming Assignment " << setw(5) <<  "6" << endl;
        fout << "This program will calculate and reports tax liability in a table format." << endl;
        fout << endl;

        fout <<  "Name"  << setw(20) << "ID";
        fout << setw(24) << "Gross Income";
        fout << setw(20) << "Taxes";
        fout << setw(22) << "Net Income";
        fout << endl;

        fout << "===========================================================================================" << endl;

        string proceedNext;
        // Read input from the file
        while (getline(fin, employeeName))
        {
            /*
            ALIGNMENTS NOT GOOD ON THIS PART
            WILL FIX ALIGNMENTS ON THE NEXT ASSIGNMENT
            */

            fin  >> employeeId >> grossIncome;
            getline(fin, proceedNext);
            // Check if Id length is valid
            if (validIdLength(employeeId)) {
                tax = computeTax(grossIncome);
                // If the function computeTax() returns -1, grossIncome is invalid
                if (tax == -1) {
                    fout << employeeName << setw(11) << employeeId << setw(18) << grossIncome << setw(38) << "**** Invalid Income " << endl;
                }
                // Proceed with tax and netIncome computation if employeeId and grossIncome are valid
                else {
                    netIncome = grossIncome - tax;
                    fout << employeeName << setw(16) << employeeId << setw(20) << grossIncome << setw(25) << tax << setw(20) << netIncome << endl;
                    totalNetIncome += netIncome;
                    getMinAndMax(netIncome, employeeName);
                    employeeCounter++;
                }
            }
            else {
                fout << employeeName << setw(15) << employeeId << setw(17) << grossIncome << setw(34) << "**** Invalid ID" << endl;
            }

        }

        // Calculate Average Net Income; employeeCounter = number of users with valid Id or grossIncome
        averageIncome = totalNetIncome / employeeCounter;

        fout << endl;
        fout << "Average net income " << setw(17) << "$" << averageIncome << endl;

        fout << "Highest net income " << setw(27) << maxEmployeeName << setw(19) << "$" << maxNetIncome << endl;
        fout << "Lowest net income "  << setw(27) << minEmployeeName << setw(20) << "$" << minNetIncome;

        // Close the input file.
        fin.close();
        // Close the output file
        fout.close();
    }
    else {
        cout << "Error opening the file.\n";
    }

    return 0;
}
