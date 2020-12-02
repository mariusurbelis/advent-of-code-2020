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

    input_stream.open(input_file_name, ifstream::in);

    int input_number;

    while (!input_stream.eof())
    {
        input_stream >> input_number;
        input_numbers.push_back(input_number);
    }

    input_stream.close();

    sort(input_numbers.begin(), input_numbers.end());

    int a, b, c;

    for (int i = 0; i < input_numbers.size(); i++)
    {
        for (int j = 0; j < input_numbers.size(); j++)
        {
            a = input_numbers[i];
            b = input_numbers[j];

            if (a + b > target_number)
                break;

            c = target_number - a - b;

            if (find(input_numbers.begin(), input_numbers.end(), c) != input_numbers.end())
            {
                cout << a * b * c << endl;
                return EXIT_SUCCESS;
            }
        }
    }

    return EXIT_SUCCESS;
}