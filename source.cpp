#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>


int getRange(int x)
{
    return (rand() % (x * 2 + 1)) - x;
}
int main(int argc, char** argv)
{
    srand(time(0));

    printf("Bad perlin noise (with bugs)\n\n");

    printf("Please input numbers only, this is C++ \n\n");

    while (1)
    {
        try
        {
            std::vector<int> randGen;

            int start;
            int length;
            int range;

            printf("\n\nStarting number (The first number will be in range of this number):\n");
            scanf_s("%i", &start);
            printf("Length (How many numbers):\n");
            scanf_s("%i", &length);
            printf("Range (What is the range of randomness): \n");
            scanf_s("%i", &range);

            printf("Here we go\n\n");

            randGen.push_back(start);

            for (int i2 = 1; i2 < length + 1; i2++)
            {
                    randGen.push_back(randGen[i2 - 1] + getRange(range));
            }

            for (int i2 = 0; i2 < length - 1; i2++)
            {
                printf("%i, ", randGen[i2]);
            }
            printf("%i", randGen[randGen.size() - 1]);        
            }
        catch(...)
        {
            continue;
        }
    }
}
