#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

const string input_file_name = "input.txt";

struct Instruction
{
    string text;
    int number;
};

int main(int argc, char **argv)
{
    vector<Instruction> instructions;
    vector<int> visited_instructions;

    ifstream input_stream;

    string input_instruction;
    string instruction_text;

    int accumulator = 0;
    int i = 0, operation_number;

    input_stream.open(input_file_name, ifstream::in);

    while (!input_stream.eof())
    {
        getline(input_stream, input_instruction);

        if (input_instruction == "")
            break;

        stringstream instruction_stream;

        instruction_stream << input_instruction;
        instruction_stream >> instruction_text;
        instruction_stream >> operation_number;

        Instruction new_instruction;

        new_instruction.number = operation_number;
        new_instruction.text = instruction_text;

        instructions.push_back(new_instruction);
    }

    for (int fixed = 0; fixed < instructions.size(); fixed++)
    {
        if (instructions[fixed].text == "nop")
            instructions[fixed].text = "jmp";
        else if (instructions[fixed].text == "jmp")
            instructions[fixed].text = "nop";

        while (i < instructions.size())
        {
            visited_instructions.push_back(i);

            if (instructions[i].text == "acc")
            {
                accumulator += instructions[i].number;
                i++;
            }
            else if (instructions[i].text == "jmp")
            {
                i += instructions[i].number;

                if ((find(visited_instructions.begin(), visited_instructions.end(), i) != visited_instructions.end()))
                    break;
            }
            else if (instructions[i].text == "nop")
            {
                i++;
            }
        }

        if (instructions[fixed].text == "nop")
            instructions[fixed].text = "jmp";
        else if (instructions[fixed].text == "jmp")
            instructions[fixed].text = "nop";

        if (i >= instructions.size())
            break;

        i = 0;
        accumulator = 0;
        visited_instructions.clear();
    }

    cout << "Accumulator: " << accumulator << endl;

    input_stream.close();

    return EXIT_SUCCESS;
}