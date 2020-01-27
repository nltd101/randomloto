#include "iostream"
#include <cstdlib> 
#include <ctime> 
#include <fstream>
using namespace std;
void printArray(int** array,int n,int m) {
    fstream f("loto.txt",ios::app);
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < m; j++)
        {
            if (array[i][j]!=0)
            {
                f << array[i][j] << "\t";
            }
            else
            {
                f << "\t";
            }
          
        }
        f << endl;
    }
    f << endl;
    f.close();
}
void generateLOTO(int** result,int* trace,int *a,int size,int x,int y)
{
    for (size_t i = 0; i < size; i++)
    {
        trace[i] = 0;
    }
    for (int i = 0; i < y; i++)
    {
        result[i] = new int[x];
        for (size_t j = 0; j < (x - 1) / 2; j++)
        {
            int position;
            do
            {
                position = (rand() % x);
            } while (a[position]==1); 
            a[position] = 1;
        }

        for (int j = 0; j < x; j++)
        {

            if (a[j] == 0)
            {
                int value;
                do
                {
                    value = (rand() % size) + 1;
                } while (trace[value] == 1);
                result[i][j] = value;
                trace[value] = 1;
            }
            else
            {
                a[j] = 0;
                result[i][j] = 0;
            }
        }

    }
}
void main() {
    int x = 6;
    int y = 3;
    int i;
    srand((unsigned)time(0));
    int size;
    size = x * y;
    int* a = new int[x];
    for (int j = 0; j < x; j++)
    {
        a[j] = 0;
    }
    int** result = new int* [y];
    int* trace = new int[size];
    for (size_t i = 0; i < 20; i++)
    {
        generateLOTO(result, trace, a, size, x, y);
        printArray(result, y, x);
       
    }
   
}