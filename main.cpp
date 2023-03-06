#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

void sort(int heap[], int size);
void printarray(int heap[], int size);

int main() {
    bool cont = true;
    int rawinputs[100];//raw input
    char numinput;
    char input[20];
    int in = 0;
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
        sort(heap, size);//sort array
        //print array 
        cout << "Array in heap order: ";
        for (int i = 0; i < size; ++i) {
            cout << heap[i] << " ";
        }
        cout << endl;
        size = 0;//reset size to 0
    }
}
void printarray(int heap[], int size)
{
    cout << "Array in heap order: ";
    for (int i = 0; i < size; ++i)
        cout << heap[i] << " ";
    cout << endl;
}


void sort(int heap[], int size) {
    int index = (size/2) - 1;
  
    for (int i = index; i >= 0; --i) {
        cout << "for" << endl;
        bool cont = true;
        while (cont == true) {
            cout << "while " << endl;
            int largest = i;
            int index_left = 2 * i + 1; //find value of right index
            int index_right = 2 * i + 2; //find value left index
            if ((index_left < size) && (heap[index_left] > heap[largest])) {
                largest = index_left;
            }
            if ((index_right < size) && (heap[index_right] > heap[largest])) {
                largest = index_right;
            }
            if (largest == i) {
                cont = false;
                break;
            }
            swap(heap[i], heap[largest]);
            printarray(heap, size);
        }
    }
}