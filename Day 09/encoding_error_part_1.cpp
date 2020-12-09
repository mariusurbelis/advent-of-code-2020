#include <iostream>
#include <fstream>
#include <vector>

#define MAX 25

using namespace std;

bool SumExistsInRange(int current_id);

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

    for (int i = MAX; i < input_numbers.size(); i++)
    {
        if (!SumExistsInRange(i))
        {
            cout << input_numbers[i] << endl;
            break;
        }
    }

    input_stream.close();

    return EXIT_SUCCESS;
}

bool SumExistsInRange(int current_id)
{
    for (int i = current_id - MAX; i < current_id; i++)
    {
        for (int j = current_id - MAX; j < current_id; j++)
        {
            if (i == j)
                continue;

            if (input_numbers[i] + input_numbers[j] == input_numbers[current_id])
                return true;
        }
    }

    return false;
}