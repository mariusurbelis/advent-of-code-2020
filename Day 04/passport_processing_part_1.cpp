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

    string text_line;
    string passport = "";

    int valid_passport_count = 0;

    while (!input_stream.eof())
    {
        getline(input_stream, text_line);

        passport += text_line;

        if (text_line == "")
        {
            if (passport.find("byr:") == string::npos ||
                passport.find("iyr:") == string::npos ||
                passport.find("eyr:") == string::npos ||
                passport.find("hgt:") == string::npos ||
                passport.find("hcl:") == string::npos ||
                passport.find("ecl:") == string::npos ||
                passport.find("iyr:") == string::npos ||
                passport.find("pid:") == string::npos)
            {
                passport = "";
                continue;
            }

            valid_passport_count++;

            passport = "";
        }
    }

    input_stream.close();

    cout << "Valid: " << valid_passport_count << endl;

    return EXIT_SUCCESS;
}