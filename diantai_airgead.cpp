#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    // variables to store input
    float initInv, monDep, AnuInt, months, years;
    // variables for year end total amount, interest, and year end interest
    float totalAm, intAmt, yearTotInt;

    // requirement for user display
    cout << "********************************\n";
    cout << "********** Data Input **********\n";
    cout << "Initial Investment Amount: \n";
    cout << "Monthly Deposit: \n";
    cout << "Annual Interest: \n";
    cout << "Number of years: \n";

    // pause in order to wait for user input
    system("PAUSE");

    // gather the data from the user
    cout << "********************************\n";
    cout << "********** Data Input **********\n";
    cout << "Initial Investment Amount: $";
    cin >> initInv;
    cout << "Monthly Deposit: $";
    cin >> monDep;
    cout << "Annual Interest: %";
    cin >> AnuInt;
    cout << "Number of years: ";
    cin >> years;
    months = years * 12;

    system("PAUSE");

    // we're gonna set the total amount to initial investment
    totalAm = initInv;

    // display the year data without monthly deposits
    cout << "\nBalance and Interest Without Additional Monthly Deposits\n";
    cout << "==============================================================\n";
    cout << "Year\t\tYear End Balance\tYear End Earned Interest\n";
    cout << "--------------------------------------------------------------\n";

    for (int i = 0; i < years; i++)
    {

        // calculating yearly interest
        intAmt = (totalAm) * ((AnuInt / 100));

        // calculating year end total
        totalAm = totalAm + intAmt;

        // printing results to table that the user will see and showcasing only two decimal points
        cout << (i + 1) << "\t\t$" << fixed << setprecision(2) << totalAm << "\t\t\t$" << intAmt << "\n";
    }

    // set total amount to initial investment
    totalAm = initInv;

    // display the year data with monthly deposits
    cout << "\n\nBalance and Interest With Additional Monthly Deposits\n";
    cout << "==============================================================\n";
    cout << "Year\t\tYear End Balance\tYear End Earned Interest\n";
    cout << "--------------------------------------------------------------\n";

    for (int i = 0; i < years; i++)
    {

        // we're setting the yearly interest to zero at the start of the year
        yearTotInt = 0;

        for (int j = 0; j < 12; j++)
        {

            // calculating monthly interest
            intAmt = (totalAm + monDep) * ((AnuInt / 100) / 12);

            // calculating month end interest
            yearTotInt = yearTotInt + intAmt;

            // calculating month end total
            totalAm = totalAm + monDep + intAmt;
        }

        cout << (i + 1) << "\t\t$" << fixed << setprecision(2) << totalAm << "\t\t\t$" << yearTotInt << "\n";
    }

    return 0;
}