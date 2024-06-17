/**
Ref: https://medium.com/@lokeshbihani99/strategy-pattern-in-c-00c76cbee275
*/
#include <iostream>
#include <vector>
using namespace std;

// Strategy Interface
class SortStrategy {
public:
    virtual ~SortStrategy() = default;
    virtual void sort(vector<int>& data) = 0;
};

// Concrete Strategies (implementations)
class BubbleSort : public SortStrategy {
public:
    void sort(vector<int>& data) override {
        // bubble sort algorithm
        cout << "bubblesort\n";
    }
};

class QuickSort : public SortStrategy {
public:
    void sort(vector<int>& data) override {
        // quick sort algorithm
        cout << "quicksort\n";
    }
};

// Context (uses Strategy interface)
class Sorter {
private:
    SortStrategy* strategy;

public:
    Sorter(SortStrategy* strategy) : strategy(strategy) {}

    void set_strategy(SortStrategy* strategy) {
        this->strategy = strategy;
    }

    void sort(vector<int>& data) const {
        strategy->sort(data);
    }
};

int main() {
    vector<int> numbers = {5, 2, 8, 1, 4};

    Sorter sorter(new BubbleSort()); // Use BubbleSort initially
    sorter.sort(numbers);

    // Dynamically change strategy to QuickSort
    sorter.set_strategy(new QuickSort());
    sorter.sort(numbers);

    return 0;
}
