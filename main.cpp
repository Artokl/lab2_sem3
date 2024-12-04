#include "ArraySequence.h"
#include "Generator.h"
#include "PersonComparators.h"
#include "QuickSort.h"

int main() {
    ArraySequence<Person> persons;
    GettingDataFromFile("persons.csv", persons);
    const QuickSorter<Person> sorter;
    sorter.Sort(persons, AscendingComparatorByHeight);
    PuttingDataToFile("output.csv", persons);
}
