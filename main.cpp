#include "ArraySequence.h"
#include "BinaryInsertionSort.h"
#include "Generator.h"
#include "MergeSort.h"
#include "PersonComparators.h"
#include "QuickSort.h"

int main() {
    std::string filename = "input.csv";
    GeneratePersons(filename, 500);
}
