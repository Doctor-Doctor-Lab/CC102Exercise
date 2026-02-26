#include <iostream>
using namespace std;

int main() {
    string runAgain;

    do {
        int students, quizzes;

        cout << "Enter number of students: ";
        cin >> students;
        cout << "Enter number of quizzes: ";
        cin >> quizzes;

        double scores[students][quizzes];


        for (int i = 0; i < students; i++) {
            cout << "Student " << (i + 1) << " scores: ";
            for (int j = 0; j < quizzes; j++) {
                cin >> scores[i][j];
            }
        }


        cout << "\nStudent ";
        for (int q = 1; q <= quizzes; q++) {
            cout << "Q" << q << " ";
        }
        cout << "Average" << endl;


        for (int i = 0; i < students; i++) {
            cout << (i + 1) << "       ";
            double sum = 0;
            for (int j = 0; j < quizzes; j++) {
                cout << (int)scores[i][j] << "   ";
                sum += scores[i][j];
            }
            double average = sum / quizzes;

            average = ((int)(average * 100 + 0.5)) / 100.0;

            cout << average << endl;
        }

        cout << "\nDo you want to run the program again? (yes/no): ";
        cin >> runAgain;

    } while (runAgain == "yes" || runAgain == "Yes");

    cout << "Program terminated." << endl;

    return 0;
}
