#include <iostream>
using namespace std;

struct Parcel {
    double weightKg;
};

double charge(double weightKg, bool express = false, bool insured = false) {
    double total = weightKg * 50.0;
    if (express) total += 30.0;
    if (insured) total += 20.0;
    return total;
}

double charge(int weightGrams) {
    return (weightGrams / 1000.0) * 50.0;
}

double charge(float weightKg) {
    return charge(static_cast<double>(weightKg));
}

double charge(const Parcel& parcel) {
    return charge(parcel.weightKg);
}

int main() {
    Parcel p{2.5};

    cout << "charge(2): " << charge(2) << '\\n';
    cout << "charge(2.0): " << charge(2.0) << '\\n';
    cout << "charge(2.0f): " << charge(2.0f) << '\\n';
    cout << "charge(2000): " << charge(2000) << '\\n';
    cout << "charge(2.0, true): " << charge(2.0, true) << '\\n';
    cout << "charge(Parcel): " << charge(p) << '\\n';
    return 0;
}