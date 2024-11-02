

#include <iostream>

bool IsBetween(int edge1, int edge2, int edge3)
{
    // checks if edge1 between edge2 and edge3
    if (edge1 > edge2 && edge1 < edge3)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// left   bottom right top
// 0     1         2    3
bool CheckCorner(int r1[], int r2[])
{
    // bottom-left
    if (IsBetween(r1[0], r2[0], r2[2]) && IsBetween(r1[1], r2[1], r2[3]))
    {
        return true;
    }

    // bottom-right
    if (IsBetween(r1[2], r2[0], r2[2]) && IsBetween(r1[1], r2[1], r2[3]))
    {
        return true;
    }

    // top-left
    if (IsBetween(r1[0], r2[0], r2[2]) && IsBetween(r1[3], r2[1], r2[3]))
    {
        return true;
    }

    // top-right
    if (IsBetween(r1[2], r2[0], r2[2]) && IsBetween(r1[3], r2[1], r2[3]))
    {
        return true;
    }

    return false;
}

// left   bottom right top
// 0     1         2    3
bool CheckCross(int r1[], int r2[])
{
    if (IsBetween(r1[0], r2[0], r2[2]) && IsBetween(r1[2], r2[0], r2[2]) && !IsBetween(r1[1], r2[1], r2[3]) && !IsBetween(r1[3], r2[1], r2[3]))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool CheckOverlap(int r1[], int r2[])
{
    if (CheckCorner(r1, r2) || CheckCross(r1, r2))
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    int r1[4], r2[4]; // left, bottom, right, top

    std::cout << "Enter left, bottom, right, top coordinates of the first rectangle: ";
    for (int i = 0; i < 4; ++i)
    {
        std::cin >> r1[i];
    }

    std::cout << "Enter left, bottom, right, top coordinates of the second rectangle: ";

    for (int i = 0; i < 4; ++i)
    {
        std::cin >> r2[i];
    }

    std::cout << "The output is: ";
    if (CheckOverlap(r1, r2))
    {
        std::cout << "true\n";
    }
    else
    {
        std::cout << "false\n";
    }

    return 0;
}