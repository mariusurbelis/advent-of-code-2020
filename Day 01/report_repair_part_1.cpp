#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

const string input_file_name = "input.txt";

const int target_number = 2020;

int main(int argc, char **argv)
{
    vector<int> input_numbers;
    
    ifstream input_stream;

    int input_number;

    input_stream.open(input_file_name, ifstream::in);

    while (!input_stream.eof())
    {
        input_stream >> input_number;
        input_numbers.push_back(input_number);
    }

    input_stream.close();

    for (int i = 0; i < input_numbers.size(); i++)
    {
        if (find(input_numbers.begin(), input_numbers.end(), target_number - input_numbers[i]) != input_numbers.end())
        {
            cout << "Success " << input_numbers[i] << " " << target_number - input_numbers[i] << " = " << input_numbers[i] * (target_number - input_numbers[i]) << endl;
            break;
        }
    }

    return EXIT_SUCCESS;
}