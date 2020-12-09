#include <iostream>
#include <fstream>
#include <vector>

#define MAX 25

#define TARGET 90433990

using namespace std;

long MinMaxSum(int lower, int higher);

const string input_file_name = "input.txt";

vector<long> input_numbers;

int main(int argc, char **argv)
{
    ifstream input_stream;

    input_stream.open(input_file_name, ifstream::in);

    long input_number;

    while (!input_stream.eof())
    {
        input_stream >> input_number;
        input_numbers.push_back(input_number);
    }

    int contiguous_lower = -1;
    int contiguous_higher = -1;
    long contiguous_sum = 0;

    for (int j = 0; j < input_numbers.size(); j++)
    {
        for (int i = j; i < input_numbers.size(); i++)
        {
            if (contiguous_sum == TARGET && (contiguous_higher - contiguous_lower >= 2))
            {
                cout << "The sum: " << MinMaxSum(contiguous_lower, contiguous_higher) << endl;
                return EXIT_SUCCESS;
            }

            if (contiguous_lower == -1)
            {
                contiguous_lower = i;
                contiguous_sum += input_numbers[i];
            }
            else
            {
                contiguous_higher = i;
                contiguous_sum += input_numbers[i];

                if (contiguous_sum > TARGET)
                {
                    contiguous_sum = 0;
                    contiguous_lower = -1;
                    contiguous_higher = -1;
                }
            }
        }

        contiguous_sum = 0;
        contiguous_lower = -1;
        contiguous_higher = -1;
    }

    input_stream.close();

    return EXIT_SUCCESS;
}

long MinMaxSum(int lower, int higher)
{
    int min_number = -1;
    int max_number = -1;

    for (int i = lower; i <= higher; i++)
    {
        if (min_number == -1 || input_numbers[i] < min_number)
            min_number = input_numbers[i];
        if (max_number == -1 || input_numbers[i] > max_number)
            max_number = input_numbers[i];
    }

    return min_number + max_number;
}