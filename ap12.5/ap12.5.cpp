// ap12.5.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
#include <fstream>
using namespace std;

typedef int Info;
struct Elem
{
    Elem* link;
    Info info;
};

void push(Elem*& top, Info value);
void printStack(Elem* top);
void printStackWithoutMultiples(Elem* top, int number);

void push(Elem*& top, Info value)
{
    Elem* tmp = new Elem;
    tmp->info = value;
    tmp->link = top;
    top = tmp;
}


void printStack(Elem* top)
{
    while (top != NULL)
    {
        cout << top->info << " ";
        top = top->link;
    }
    cout << endl;
}

void printStackWithoutMultiples(Elem* top, int number)
{
    if (top == NULL) {
        return;
    }

    printStackWithoutMultiples(top->link, number);

    if (top->info % number != 0) {
        cout << top->info << " ";
    }
}

int main()
{
    ofstream file("input.txt");
    file << 2 << endl;
    file << 67 << endl;
    file << 10 << endl;
    file << 7 << endl;
    file << 25 << endl;
    file.close();

    Elem* top = NULL;
    ifstream inputFile("input.txt");

    int number;
    while (inputFile >> number)
    {
        push(top, number);
    }
    inputFile.close();

    cout << "Stack: ";
    printStack(top);

    int multiple;
    cout << "Enter a number: ";
    cin >> multiple;

    cout << "Stack without multiples of " << multiple << ": ";
    printStackWithoutMultiples(top, multiple);

    return 0;
}
