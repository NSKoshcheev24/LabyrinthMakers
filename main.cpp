#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <conio.h>
using namespace std;

void showLabyrinth(vector<vector<char>>& maze, int size, int x, int y)
{
    system("cls");

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (i == x && j == y)
                printf("P ");
            else
                printf("%c ", maze[i][j]);
        }
        printf("\n");
    }
}

void gameCall() {
    srand(time(0));

    int size = 0;

    while (true)
    {
        printf("Enter labyrinth size (10-50): ");

        if (scanf_s("%d", &size) == 1 && size >= 10 && size <= 50)
            break;

        printf("Invalid size!\n");

        int ch;
        while ((ch = getchar()) != '\n' && ch != EOF)
        {
        }
    }

    if (size < 10 || size > 50)
    {
        printf("Invalid labyrinth size!\n");
        return;
    }

    vector<vector<char>> maze(size, vector<char>(size, '.'));
    int middle = size / 2;
    int doorColumn = size / 2;

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (rand() % 3 == 0)
                maze[i][j] = '#';
        }
    }

    for (int j = 0; j < size; j++)
        maze[middle][j] = '#';

    int keyRow = 1 + rand() % (middle - 1);
    int keyColumn = rand() % size;

    maze[0][0] = '.';
    for (int i = 0; i <= keyRow; i++)
        maze[i][0] = '.';
    for (int j = 0; j <= keyColumn; j++)
        maze[keyRow][j] = '.';
    for (int i = keyRow; i < middle; i++)
        maze[i][keyColumn] = '.';

    int left = keyColumn < doorColumn ? keyColumn : doorColumn;
    int right = keyColumn > doorColumn ? keyColumn : doorColumn;
    for (int j = left; j <= right; j++)
        maze[middle - 1][j] = '.';

    for (int i = middle + 1; i < size - 1; i++)
        maze[i][doorColumn] = '.';
    for (int j = doorColumn; j < size; j++)
        maze[size - 2][j] = '.';

    maze[keyRow][keyColumn] = 'K';
    maze[middle][doorColumn] = 'D';
    maze[size - 1][size - 1] = 'E';

    int x = 0, y = 0;
    bool hasKey = false;

    while (true)
    {
        showLabyrinth(maze, size, x, y);

        int key = _getch();

        if (key == 224)
        {
            key = _getch();

            int sizex = x, sizey = y;

            if (key == 72) sizex--;
            if (key == 80) sizex++;
            if (key == 75) sizey--;
            if (key == 77) sizey++;

            if (sizex >= 0 && sizex < size &&
                sizey >= 0 && sizey < size &&
                maze[sizex][sizey] != '#' &&
                (maze[sizex][sizey] != 'D' || hasKey))
            {
                x = sizex;
                y = sizey;

                if (maze[x][y] == 'K')
                {
                    hasKey = true;
                    maze[x][y] = '.';
                    maze[middle][middle] = '.';
                }
            }
        }

        if (x == size - 1 && y == size - 1)
        {
            showLabyrinth(maze, size, x, y);
            printf("\nWin.\n");
            break;
        }
    }
}

void helpCall() {
    system("cls");
    printf("\nHelp:\n"
    "Your goal is to get to the exit.\n"
    "Exit is E, you are P, walls are #, the key is K and the locked door is D.\n"
    "The key appears randomly in the upper half. Picking it up removes the door.\n"
    "You start from the top-left corner and the exit is on the bottom-right corner.\n"
    "You move yourself with arrow-keys on your keyboard.\n"
    "When you start the game you can choose the size of the labyrinth from 10*10 to 50*50.\n"
    "That's it.\n");
}

int main()
{
    int choice;
    printf("\n1. Start game\n2. Help\n3. Exit\n");
    scanf_s("%d", &choice);
    switch (choice) {
    case 1:
        gameCall();
        break;
    case 2:
        helpCall();
        main();
        break;
    case 3:
        exit(0);
        break;
    default:
        system("cls");
        printf("Invalid choice.\n");
        main();
        break;
    }
}