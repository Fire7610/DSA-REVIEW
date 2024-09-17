#include <stdio.h>
#include <stdlib.h>

void convert(char input[], int output[])
{
    for (int i = 0; i < 9; i++)
    {   
        if(input[i] < 10)
            output[i] = input[i] - '0';
        if(input[i] == 'A')
            output[i] = 10;
        if(input[i] == 'B')
            output[i] = 11;
        if(input[i] == 'C')
            output[i] = 12;
        if(input[i] == 'D')
            output[i] = 13;
        if(input[i] == 'E')
            output[i] = 14;
        if(input[i] == 'F')
            output[i] = 15;
    }
}

void convert2(char input[], int output[])
{
    for (int i = 0; i < 9; i++)
    {
        if(input[i] < 10)
            output[i] = input[i] + '0';
        if(input[i] == 10)
            output[i] = 'A';
        if(input[i] == 11)
            output[i] = 'B';
        if(input[i] == 12)
            output[i] = 'C';
        if(input[i] == 13)
            output[i] = 'D';
        if(input[i] ==  14)
            output[i] = 'E';
        if(input[i] == 15)
            output[i] = 'F';
    }
}

int main()
{
    char input1[9] = {'9', '9', '9', '9', '9', '9', '9', '9', '9'};
    char input2[9] = {'2', '2', '2', '2', '2', '2', '2', '2', '2'};

    int output1[9];
    int output2[9];

    char output3[9];

    convert(input1, output1);
    convert(input2, output2);

    int result[9];

    for(int i = 0; i < 9; i++)
        result[i] = output1[i] + output2[i];

    convert2(result, output3);

    for(int i = 0; i < 9; i++)
        printf("%c", output3[i]);
    return 0;
}