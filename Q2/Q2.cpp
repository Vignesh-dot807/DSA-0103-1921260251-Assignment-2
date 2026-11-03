include <iostream>
using namespace std;

int& highestMark(int marks[], int size) {
    int highestIndex = 0;
    for (int i = 1; i < size; ++i) {
        if (marks[i] > marks[highestIndex]) {
            highestIndex = i;
        }
    }
    return marks[highestIndex];
}

// DANGEROUS: do not call or use this function.
int& invalidLocalReference() {
    int local = 50;
    return local; // returns a reference to a destroyed local variable
}

int main() {
    int marks[] = {78, 92, 85, 88};
    highestMark(marks, 4) += 2;

    cout << "Updated marks: ";
    for (int mark : marks) cout << mark << ' ';
    cout << '\\n';
    cout << "Highest mark: " << highestMark(marks, 4) << '\\n';
    return 0;
}