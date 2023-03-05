#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main() {
    bool cont = true;
    int rawinputs[100];//raw input
    char numinput;
    char input[20];
    int in = 0;;
    int numofnums;
    int heap[100];
    char file[80];
    int total = 0;
    int size = 0;
    while (cont == true) {
        cout << "File (1) or input manually (2)?: ";
        cin >> in;
        if (in == 2) {
            for (int i = 0; i < 100; ++i) {
                cout << "Enter number, type \"s\" to stop: " ;
                cin >> numinput;
                if (numinput == 's') {
                    break;
                }
                size+=1;
                rawinputs[i] = (int)numinput-48;
            }
            cout << "Numbers inputted: ";
            for (int i = 0; i < size; ++i){
                cout << rawinputs[i] << " ";
            }
            cout << endl;
        }
        else if (in == 1) {
            cout << "Enter file name (Do not include .txt): ";
            cin >> file;
            cin.ignore();
            strcat(file, ".txt");//concatenate strings
            ifstream numFile;
            numFile.open(file);
            cout << "Numbers from file: ";
            while (numFile >> rawinputs[total]) {
                cout << rawinputs[total] << " ";
                total+=1;
                size+=1;
            }
            cout << endl;
            numFile.close();
        }
        else {
            cout << "Invalid input" << endl;
        }
        int heap[size];
            //copy above array into new array called heap
            for (int i = 0; i < size; ++i) {
                heap[i] = rawinputs[i];
            }
        size = 0;
    }
}