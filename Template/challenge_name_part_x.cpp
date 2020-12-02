#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

const string input_file_name = "input.txt";

int main(int argc, char **argv)
{
    vector<int> input_numbers;
    ifstream input_stream;

    input_stream.open(input_file_name, ifstream::in);

    int input_number;

    // Reading the file assuming it is full of space separated integers
    while (!input_stream.eof())
    {
        input_stream >> input_number;
        input_numbers.push_back(input_number);
    }

    input_stream.close();

    return EXIT_SUCCESS;
}