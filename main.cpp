#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

const long max_length = 10000;
string line;
int list[max_length];

class dataSort
{
public:
    void read();
    int partition(int*, int, int);
    void quickSort(int*, int, int);
    void print(int*);
private:

};

void dataSort::read()
{
    int n = 0;
    fstream myFile;
    myFile.open("data10k.txt");

        while (myFile.good())
        {
            getline(myFile, line);
            stringstream(line) >> list[n];
            n++;
        }
}

void dataSort::print(int *list)
{

    for (int n = 0; n < max_length; n++)
    {
        cout << list[n] << " \n";
    }
}

int dataSort::partition(int* list, int p, int r)
{
    int pivotElement = list[r];

    while ( p < r )
    {
        while ( list[p] < pivotElement )
            p++;

        while ( list[r] > pivotElement )
            r--;

        if ( list[p] == list[r] )
            p++;
        else if ( p < r )
        {
            int tmp = list[p];
            list[p] = list[r];
            list[r] = tmp;
        }
    }

    return r;
}

void dataSort::quickSort(int* list, int p, int r)
{
    if ( p < r )
    {
        int pivot = partition(list, p, r);
        quickSort(list, p, pivot-1);
        quickSort(list, pivot+1, r);
    }
}

int main()
{
    //cout << "Hello world!" << endl;

    dataSort ascend;

    ascend.read();
    ascend.quickSort(list, 0, max_length - 1);
    ascend.print(list);

    return 0;
}
