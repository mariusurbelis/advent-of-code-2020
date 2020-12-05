#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;

pair<string, string> SplitString(string val);
bool IsValid(string statement_input);

const string input_file_name = "input.txt";

int main(int argc, char **argv)
{
    vector<int> input_numbers;
    ifstream input_stream;

    input_stream.open(input_file_name, ifstream::in);

    string text_line;
    string passport = "";

    int passport_count = 0;
    int invalid_passport_count = 0;
    int line_i = 0;

    while (!input_stream.eof())
    {
        getline(input_stream, text_line);

        passport += (line_i != 0) ? ' ' + text_line : text_line;
        line_i++;

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

            passport_count++;

            stringstream passport_stream;
            passport_stream << passport;

            string one_field;

            while (!passport_stream.eof())
            {
                passport_stream >> one_field;

                if (!IsValid(one_field))
                {
                    invalid_passport_count++;
                    break;
                }
            }

            passport = "";
            line_i = 0;
        }
    }

    input_stream.close();

    cout << "Valid: " << passport_count - invalid_passport_count << endl;

    return EXIT_SUCCESS;
}

pair<string, string> SplitString(string val)
{
    string arg;
    string::size_type pos = val.find(':');

    if (val.npos != pos)
    {
        arg = val.substr(pos + 1);
        val = val.substr(0, pos);
    }

    return make_pair(val, arg);
}

bool IsValid(string statement_input)
{
    pair<string, string> statement = SplitString(statement_input);

    if (statement.first == "byr")
    {
        int year;

        try
        {
            year = stoi(statement.second);
        }
        catch (const std::exception &e)
        {
            return false;
        }

        if (year >= 1920 && year <= 2002)
            return true;
    }
    else if (statement.first == "iyr")
    {
        int year;

        try
        {
            year = stoi(statement.second);
        }
        catch (const std::exception &e)
        {
            return false;
        }

        if (year >= 2010 && year <= 2020)
            return true;
    }
    else if (statement.first == "eyr")
    {
        int year;

        try
        {
            year = stoi(statement.second);
        }
        catch (const std::exception &e)
        {
            return false;
        }

        if (year >= 2020 && year <= 2030)
            return true;
    }
    else if (statement.first == "hgt")
    {
        int height;

        try
        {
            height = stoi(statement.second);
        }
        catch (const std::exception &e)
        {
            return false;
        }

        if (statement.second.find("in") != string::npos)
        {
            if (height >= 59 && height <= 76)
                return true;
        }
        else if (statement.second.find("cm") != string::npos)
        {
            if (height >= 150 && height <= 193)
                return true;
        }
    }
    else if (statement.first == "hcl")
    {
        if (statement.second[0] != '#')
            return false;

        return all_of(statement.second.begin() + 1, statement.second.end(), [](char i) { return ((i >= 'a' && i <= 'f') || (i >= '0' && i <= '9')); });
    }
    else if (statement.first == "ecl")
    {
        if (statement.second == "amb" || statement.second == "blu" || statement.second == "brn" ||
            statement.second == "gry" || statement.second == "grn" || statement.second == "hzl" || statement.second == "oth")
            return true;
    }
    else if (statement.first == "pid")
    {
        if (statement.second.length() != 9)
            return false;

        try
        {
            stoi(statement.second);
        }
        catch (const std::exception &e)
        {
            return false;
        }

        return true;
    }
    else if (statement.first == "cid")
    {
        return true;
    }

    return false;
}