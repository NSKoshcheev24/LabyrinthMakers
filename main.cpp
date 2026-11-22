#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <conio.h>
using namespace std;

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
        //gameCall();
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
