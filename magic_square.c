#include <stdio.h>

int magic_square_test(int square[3][3])
{
    // returns 1 for magic, 0 for not

    // check rows
    for (int i = 0; i < 3; i++)
    {
        int row_total = 0;
        for (int j = 0; j < 3; j++)
        {
            row_total += square[i][j];
        }
        if (row_total != 15)
        {
            return 0;
        }
    }

    // check columns
    for (int j = 0; j < 3; j++)
    {
        int column_total = 0;
        for (int i = 0; i < 3; i++)
        {
            column_total += square[i][j];
        }
        if (column_total != 15)
        {
            return 0;
        }
    }

    // check diagonals
    if (square[0][0] + square[1][1] + square[2][2] != 15)
    {
        return 0;
    }
    if (square[0][2] + square[1][1] + square[2][0] != 15)
    {
        return 0;
    }

    // return true for magic square
    return 1;
}

void print_square(int square[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", square[i][j]);
        }
        printf("\n");
    }
}

void test_square(int square[3][3])
{
    if (magic_square_test(square) == 1)
    {
        printf("This is a magic square:\n");
    }
    else
    {
        printf("This is not a magic square:\n");
    }
    print_square(square);
    printf("\n");
}

int main()
{
    int magic_square[3][3] =
    {
        {2, 9, 4},
        {7, 5, 3},
        {6, 1, 8}
    };

    int not_magic_square[3][3] =
    {
        {5, 8, 3},
        {6, 9, 4},
        {7, 2, 1}
    };
    test_square(magic_square);
    test_square(not_magic_square);
}
