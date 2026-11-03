#include <iostream>
using namespace std;

void applyByValue(long long fee, int percent) {
    fee -= fee * percent / 100;
}

void applyByReference(long long& fee, int percent) {
    fee -= fee * percent / 100;
}

void applyByPointer(long long* fee, int percent) {
    if (fee != nullptr) {
        *fee -= *fee * percent / 100;
    }
}

int main() {
    long long valueFee = 45000;
    long long referenceFee = 45000;
    long long pointerFee = 45000;

    applyByValue(valueFee, 10);
    applyByReference(referenceFee, 10);
    applyByPointer(&pointerFee, 10);

    cout << "After call by value     : " << valueFee << '\\n';
    cout << "After call by reference : " << referenceFee << '\\n';
    cout << "After call by pointer   : " << pointerFee << '\\n';
    return 0;
}
