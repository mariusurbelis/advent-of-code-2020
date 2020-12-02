#include <iostream>

using namespace std;

int main()
{
    long answer = 0;

    for (int i = 0; i < 1000; i++)
    {
        for (int j = 0; j < 1000; j++)
        {
            for (int k = 0; k < 1000; k++)
            {
                answer++;
            }
        }
    }

    cout << answer << endl;

    return 0;
}