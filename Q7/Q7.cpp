class TransactionHistory {
    static const int CAPACITY = 10;
    double items[CAPACITY]{};
    int start = 0;
    int count = 0;

public:
    void add(double value) {
        if (count < CAPACITY) {
            int writeIndex = (start + count) % CAPACITY;
            items[writeIndex] = value;
            ++count;
        } else {
            items[start] = value;
            start = (start + 1) % CAPACITY;
        }
    }

    void print() const {
        for (int i = 0; i < count; ++i) {
            int index = (start + i) % CAPACITY;
            std::cout << items[index] << '\\n';
        }
    }
};