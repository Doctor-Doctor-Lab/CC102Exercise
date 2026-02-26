#include <iostream>
using namespace std;

int main() {
    string runAgain;

    do {
        const int salespeople = 4;
        const int products = 5;

        double sales[products][salespeople] = {0};

        while (true) {
            int sp, pr;
            double amount;

            cout << "Salesperson (1-4, 0 to stop): ";
            cin >> sp;
            if (sp == 0) break;

            cout << "Product (1-5): ";
            cin >> pr;
            cout << "Amount: ";
            cin >> amount;


            sales[pr - 1][sp - 1] += amount;
        }


        cout << "\nSalesperson\nProduct ";
        for (int sp = 1; sp <= salespeople; sp++) {
            cout << sp << " ";
        }
        cout << "Total\n";

        double grandTotal = 0;
        double colTotals[salespeople] = {0};


        for (int pr = 0; pr < products; pr++) {
            cout << (pr + 1) << " ";
            double rowTotal = 0;
            for (int sp = 0; sp < salespeople; sp++) {
                double amt = sales[pr][sp];
                cout << amt << " ";
                rowTotal += amt;
                colTotals[sp] += amt;
            }
            cout << rowTotal << endl;
            grandTotal += rowTotal;
        }


        cout << "Total ";
        for (int sp = 0; sp < salespeople; sp++) {
            cout << colTotals[sp] << " ";
        }
        cout << grandTotal << endl;


        cout << "\nDo you want to run the program again? (yes/no): ";
        cin >> runAgain;

    } while (runAgain == "yes" || runAgain == "Yes");

    cout << "Program terminated." << endl;
    return 0;
}
