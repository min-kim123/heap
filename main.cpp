#include <iostream>
#include <fstream>
#include <cstring>
#include <math.h>
using namespace std;
/*
Author: Min Kim
Program Description: This program will ask the user for a file or manual input of a series of numbers. It will sort the numbers into 
a heap array and remove, print array, or print in tree form.
Date: 3/7/23
*/
void sort(int heap[], int size);
void printarray(int heap[], int size);
void remove(int heap[], int& size);
void removeall(int heap[], int& size);
void printtree(int heap[], int spot, int size);

int main() {
    bool cont = true;
    bool cont2 = true;
    int rawinputs[100];//raw input
    int numinput;
    int in = 0;
    int numofnums;
    int* heap[100];
    char file[80];
    int total = 0;
    int size = 0;
    int in2 = 0;
    int num = 0;//when asking user what number to delete
    while (cont == true) {
        cout << "File (1), input manually (2), or quit(3)?: ";
        cin >> in;
        if (in == 2) {
            for (int i = 0; i < 100; ++i) {
                cout << "Enter number, type \"-1\" to stop: " ;
                cin >> numinput;
                if (numinput == -1) {
                    break;
                }
                size+=1;
                rawinputs[i] = numinput;
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
        else if (in == 3) {
            break;
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
        printarray(heap, size);//print sorted array
        //remove, remove all, print tree
        while (cont2 == true) {
            cout << "Remove largest number (1), remove all (2), print tree (3), or exit this number set (4)?: ";
            cin >> in2;
            if (in2 == 1) {
                remove(heap, size);
                printarray(heap, size);//print array again
            }
            else if (in2 == 2) {
                removeall(heap, size);//remove all
            }
            else if (in2 == 3) {
                printtree(heap, 0, size);//print tree
            }
            else if (in2 == 4) {
                cont2 = false;//break 
            }
            else {
                cout << "Invalid input" << endl;
            }
        }
        cont2 = true;//reset to true
        size = 0;//reset size to 0
    }
}

void printarray(int heap[], int size) {
    cout << "Array in heap order: ";
    for (int i = 0; i < size; ++i)
        cout << heap[i] << " ";
    cout << endl;
}

void sort(int heap[], int size) {
    int index = (size/2)-1;//starting index
    for (int i = index; i >= 0; --i) {
        bool cont = true;
        while (cont == true) {
            int index_largest = i;//
            int index_left = 2 * i + 1; //find value of right index
            int index_right = 2 * i + 2; //find value left index
            if ((index_left < size) && (heap[index_left] > heap[index_largest])) {
                index_largest = index_left;
            }
            if ((index_right < size) && (heap[index_right] > heap[index_largest])) {
                index_largest = index_right;
            }
            if (index_largest == i) {//if parent is already larger than children, move on to next parent
                cont = false;
                break;
            }
            swap(heap[i], heap[index_largest]);
            i = index_largest;//update i
        }
    }
}

void remove(int heap[], int& size) {//deletes and resorts
    int count = 0;
    int temp = heap[0];
    for (int i = 0; i < size; ++i) {
            heap[i] = heap[i+1];
    }
    heap[size] = '\0';
    size-=1;
    sort(heap, size);//resort after deletion
    cout << "Number removed: " << temp << endl;
}

void removeall(int heap[], int & size){//remove all, calls the remove function
    while (heap[0] != '\0') {
        remove(heap, size);
    }
    printarray(heap, size);
}

void printtree(int heap[], int spot, int size) {//print tree
    if(spot >= size) {
        return;
    }
    printtree(heap, spot*2+1, size);
    int num = spot+1;
    while (floor(num) > 1) {//print tabs
        num = floor(num)/2;
        cout << "\t";
    }
    cout << heap[spot] << endl;
    printtree(heap, spot*2+2, size);
}