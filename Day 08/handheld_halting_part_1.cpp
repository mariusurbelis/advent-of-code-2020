#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

const string input_file_name = "input.txt";

int main(int argc, char **argv)
{
    vector<string> instructions;

    vector<int> visited_instructions;

    ifstream input_stream;

    string input_instruction;

    input_stream.open(input_file_name, ifstream::in);

    while (!input_stream.eof())
    {
        getline(input_stream, input_instruction);
        
        if (input_instruction == "")
            break;
        
        instructions.push_back(input_instruction);
    }

    string instruction_text;
    int i = 0, operation_number;

    int accumulator = 0;

    while (i < instructions.size())
    {
        visited_instructions.push_back(i);

        stringstream instruction_stream;

        instruction_stream << instructions[i];
        instruction_stream >> instruction_text;
        instruction_stream >> operation_number;

        if (instruction_text == "acc")
        {
            accumulator += operation_number;
            i++;
        }
        else if (instruction_text == "jmp")
        {
            i += operation_number;

            if ((find(visited_instructions.begin(), visited_instructions.end(), i) != visited_instructions.end()))
                break;
        }
        else if (instruction_text == "nop")
        {
            i++;
        }
    }

    cout << "Accumulator: " << accumulator << endl;

    input_stream.close();

    return EXIT_SUCCESS;
}