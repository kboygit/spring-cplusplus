//============================================================================
// Name        : Assignment 3
// Author      : Kirby James
//============================================================================

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

// Function Prototypes
void getFileName(string &iFileName, string &oFileName);
void openFileName(ifstream &fin, string &iFileName);
void processFileName(ofstream &fout, string &oFileName);
void readInputFromFile(ifstream &fin, ofstream &fout, string &employeeName, double &grossIncome, int &employeeId, double &netIncome, int &employeeCounter);
void calcNetIncome(ofstream &fout, double &averageIncome, int &employeeCounter, double &totalNetIncome);
void closeFileName(fstream &fin, ofstream &fout);
void getMinAndMax(double grossIncome, string employeeName);
double computeTax(double grossIncome);
bool validIdLength(int employeeId);
void openIfSuccessful(ifstream &fin, ofstream &fout, string &oFileName, string &employeeName, double &averageIncome, int &employeeCounter, double &netIncome, double &grossIncome, int &employeeId);

// Global variables
double totalNetIncome = 0, minNetIncome = 0, maxNetIncome = 0;
string minEmployeeName, maxEmployeeName;

// Prompt User for input and output file names
void getFileName(string &iFileName, string &oFileName) {
    // Get the input filename from the user
    cout << "Please enter input file name: ";
    cin >> iFileName;

    cout << endl;

    //Get the output filename from the user
    cout << "Please enter output file name: ";
    cin >> oFileName;
}

// Open input file name
void openFileName(ifstream &fin, string &iFileName) {
    // Open the file
    fin.open(iFileName.c_str());
}

// If the file successfully opened, process it
void processFileName(ofstream &fout, string &oFileName) {
    fout.open(oFileName.c_str());

    fout << "Programmer: " << "\t\t" << "Kirby Fernandez" << endl;
    fout << "Programming Assignment " << "\t" << "6" << endl;
    fout << "This program will calculate and reports tax liability in a table format." << endl;
    fout << endl;

    fout << "Name" << "\t\t" << "ID";
    fout << "\t" << "Gross Income";
    fout << "\t" << "Taxes";
    fout << "\t" << "Net Income";
    fout << endl;

    fout << "===========================================================================================" << endl;
}

string proceedNext;
// Read input from the file
void readInputFromFile(ifstream &fin, ofstream &fout, string &employeeName, double &grossIncome, int &employeeId, double &netIncome, int &employeeCounter) {
    double tax = 0;
    while (getline(fin, employeeName)) {
        fin >> employeeId >> grossIncome;
        getline(fin, proceedNext);
        // Check if Id length is valid
        if (validIdLength(employeeId)) {
            tax = computeTax(grossIncome);
            // If the function computeTax() returns -1, grossIncome is invalid
            if (tax == -1) {
                fout << employeeName << "\t" << employeeId << "\t" << grossIncome << "\t" << "**** Invalid Income " << endl;
            }
            // Proceed with tax and netIncome computation if employeeId and grossIncome are valid
            else {
                netIncome = grossIncome - tax;
                fout << employeeName << "\t" << employeeId << "\t" << grossIncome << "\t\t" << tax << "\t" << netIncome << endl;
                totalNetIncome += netIncome;
                getMinAndMax(netIncome, employeeName);
                employeeCounter++;
            }
        }
        else {
            fout << employeeName << "\t" << employeeId << "\t" << grossIncome << "\t" << "**** Invalid ID" << endl;
        }

    }
}

// Calculate Average Net Income; employeeCounter = number of users with valid Id or grossIncome
void calcNetIncome(ofstream &fout, double &averageIncome, int &employeeCounter, double &totalNetIncome) {
    averageIncome = totalNetIncome / employeeCounter;

    fout << endl;
    fout << "Average net income " << "\t" << "$" << averageIncome << endl;

    fout << "Highest net income " << "\t" << maxEmployeeName << "\t" << "$" << maxNetIncome << endl;
    fout << "Lowest net income " << "\t" << minEmployeeName << "\t" << "$" << minNetIncome;
}

// Close File names
void closeFileName(ifstream &fin, ofstream &fout) {
    // Close the input file.
    fin.close();
    // Close the output file
    fout.close();
}

// set Min and Max
int setInitial = 0;
void getMinAndMax(double grossIncome, string employeeName) {
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

// compute tax with specific ranges
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

// check validates Id Legth
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

// If the file successfully opened, process it
void openIfSuccessful(ifstream &fin, ofstream &fout, string &oFileName, string &employeeName, double &averageIncome, int &employeeCounter, double &netIncome, double &grossIncome, int &employeeId) {
    if (fin) {
        // call processFileName()
        processFileName(fout, oFileName);

        // call readInputFromFile()
        readInputFromFile(fin, fout, employeeName, grossIncome, employeeId, netIncome, employeeCounter);

        // call calcNetIncome
        calcNetIncome(fout, averageIncome, employeeCounter, totalNetIncome);

        // call closeFileName
        closeFileName(fin, fout);
    }
    else {
        cout << "Error opening the file." << endl;
    }
}


int main() {
    // as is to get used to pass by reference
    int employeeId, employeeCounter = 0;
    double grossIncome, netIncome, averageIncome = 0;
    string iFileName, oFileName, employeeName;
    ifstream fin;
    ofstream fout;

    // Call getFileName() function to read inputFileName & outputFileName
    getFileName(iFileName, oFileName);

    // Call openFileName() function to open file name
    openFileName(fin, iFileName);

    // Call openIfSuccessful() function to open if file is present
    openIfSuccessful(fin, fout, oFileName, employeeName, averageIncome, employeeCounter, netIncome, grossIncome, employeeId);

    return 0;
}
