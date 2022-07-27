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

    std::vector<int> randGen;

    int start;
    int length;
    int range;

    printf("Bad perlin noise (with bugs)\n\n");

    printf("Please input numbers only, this is C++ \n\n");

    printf("Starting number (The first number will be in range of this number):\n");
    scanf_s("%i", &start);
    printf("Length (How many numbers):\n");
    scanf_s("%i", &length);
    printf("Range (What is the range of randomness): \n");
    scanf_s("%i", &range);

    printf("Here we go\n\n");

    //This block is where the magic begins
    {
        randGen.push_back(start + getRange(range));

        for (int i = 1; i < length + 1; i++)
        {
            randGen.push_back(randGen[i - 1] + getRange(range));
        }

        for (int i = 0; i < length - 1; i++)
        {
            printf("%i, ", randGen[i]);
        }
        printf("%i", randGen[randGen.size() - 1]);
    }

}