#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>

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

void RotateWaypoint(v2 &waypoint, bool right)
{
    int x = waypoint.x;
    int y = waypoint.y;
    waypoint.x = right ? y : -y;
    waypoint.y = right ? -x : x;
}

void MoveWaypoint(v2 &position, dir direction, int units)
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

void ExecuteInstruction(v2 &position, v2 &waypoint, char instruction_char, int instruction_number)
{
    if (instruction_char == 'F')
    {
        position.x += waypoint.x * instruction_number;
        position.y += waypoint.y * instruction_number;
    }
    else if (instruction_char == 'R' || instruction_char == 'L')
    {
        while (instruction_number >= 90)
        {
            instruction_number -= 90;
            RotateWaypoint(waypoint, instruction_char == 'R');
        }
    }
    else
    {
        MoveWaypoint(waypoint, (dir)instruction_char, instruction_number);
    }
}

int main(int argc, char **argv)
{
    ifstream input_stream;
    string input_instruction;
    char instruction_char;
    int instruction_number;
    v2 waypoint, position;

    position.x = 0;
    position.y = 0;

    waypoint.x = 10;
    waypoint.y = 1;

    input_stream.open(input_file_name, ifstream::in);

    while (!input_stream.eof())
    {
        input_instruction = "";

        input_stream >> input_instruction;

        if (input_instruction == "")
            break;

        instruction_char = input_instruction[0];

        instruction_number = stoi(input_instruction.substr(1, input_instruction.length()));

        cout << "Instruction: " << input_instruction << endl;
        cout << "Position: (" << position.x << ", " << position.y << ") Waypoint: (" << waypoint.x << ", " << waypoint.y << ")" << endl;

        ExecuteInstruction(position, waypoint, instruction_char, instruction_number);

        cout << "Position: (" << position.x << ", " << position.y << ") Waypoint: (" << waypoint.x << ", " << waypoint.y << ")" << endl
             << endl;
    }

    input_stream.close();

    cout << "x:" << position.x << " y:" << position.y << endl;
    cout << "Manhattan distance: " << abs(position.x) + abs(position.y) << endl;

    return EXIT_SUCCESS;
}