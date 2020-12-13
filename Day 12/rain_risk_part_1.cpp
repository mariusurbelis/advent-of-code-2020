#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

const string input_file_name = "input.txt";

enum dir
{
    north = 'N',
    east = 'E',
    south = 'S',
    west = 'W'
};

struct v2
{
    int x;
    int y;
};

void TurnShip(dir &direction, int degrees, bool right)
{
    while (degrees >= 90)
    {
        degrees -= 90;

        /*
            The enumerator could not be incremented as it has been assigned characters
            for easier movement direction handling
        */
        switch (direction)
        {
        case north:
            direction = right ? east : west;
            break;
        case east:
            direction = right ? south : north;
            break;
        case south:
            direction = right ? west : east;
            break;
        case west:
            direction = right ? north : south;
            break;
        default:
            break;
        }
    }
}

void MoveShip(v2 &position, dir direction, int units)
{
    switch (direction)
    {
    case north:
        position.y += units;
        break;
    case east:
        position.x += units;
        break;
    case south:
        position.y -= units;
        break;
    case west:
        position.x -= units;
        break;

    default:
        break;
    }
}

void ExecuteInstruction(v2 &position, dir &direction, char instruction_char, int instruction_number)
{
    if (instruction_char == 'F')
        MoveShip(position, direction, instruction_number);
    else if (instruction_char == 'R')
        TurnShip(direction, instruction_number, true);
    else if (instruction_char == 'L')
        TurnShip(direction, instruction_number, false);
    else
        MoveShip(position, (dir)instruction_char, instruction_number);
}

int main(int argc, char **argv)
{
    ifstream input_stream;
    string input_instruction;
    char instruction_char;
    int instruction_number;
    dir direction = east;
    v2 position;

    position.x = 0;
    position.y = 0;

    input_stream.open(input_file_name, ifstream::in);

    while (!input_stream.eof())
    {
        input_instruction = "";

        input_stream >> input_instruction;

        if (input_instruction == "")
            break;

        instruction_char = input_instruction[0];

        instruction_number = stoi(input_instruction.substr(1, input_instruction.length()));

        // Assumption that all the numbers are 90 degree increments
        if (instruction_char == 'R' || instruction_char == 'L')
            if (instruction_number % 90 != 0)
                cout << "ERROR: " << instruction_number << endl;

        ExecuteInstruction(position, direction, instruction_char, instruction_number);
    }

    input_stream.close();

    cout << "x:" << position.x << " y:" << position.y << endl;
    cout << "Manhattan distance: " << abs(position.x) + abs(position.y) << endl;

    return EXIT_SUCCESS;
}