#include <iostream>
#include <vector>
using namespace std;

int main() {

    char again = 'y';

    while(again == 'y' || again == 'Y') {

        int students, days;

        cout << "Enter number of students: ";
        cin >> students;

        cout << "Enter number of days: ";
        cin >> days;

        vector<vector<int>> attendance;

        attendance.resize(students);

        for(int i = 0; i < students; i++) {
            attendance[i].resize(days);
        }
        
        for(int i = 0; i < students; i++) {
            cout << "\nStudent " << i+1 << " attendance: ";
            for(int j = 0; j < days; j++) {
                cin >> attendance[i][j];
            }
        }

        cout << "\n\nStudent\t";

        for(int d = 0; d < days; d++) {
            cout << "D" << d+1 << "\t";
        }

        cout << "Total\tPercentage\tRemarks\n";
        
        
        for(int i = 0; i < students; i++) {

            int total = 0;

            for(int j = 0; j < days; j++) {
                total = total + attendance[i][j];
            }

            double percent = 0;

            if(days != 0) {
                percent = ((double)total / days) * 100;
            }

            string remarks;

            if(percent < 50) {
                remarks = "DRP";
            } else {
                remarks = "OK";
            }

            cout << i+1 << "\t";

            for(int j = 0; j < days; j++) {
                cout << attendance[i][j] << "\t";
            }

            cout << total << "\t";
            cout << percent << "%\t\t";
            cout << remarks << endl;
        }

        cout << "\nRun again? (y/n): ";
        cin >> again;
        cout << endl;
    }

    return 0;
}