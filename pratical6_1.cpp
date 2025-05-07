#include <iostream>
using namespace std;

class Dynamic_Array {
private:
    int* Data;
    int Size;
    int Capacity;


    void Resize() {
        Capacity *= 2;
        int* newData = new int[Capacity];
        for (int i = 0; i < Size; ++i)
            newData[i] = Data[i];
        delete[] Data;
        Data = newData;
    }

public:
 
    Dynamic_Array(int initCapacity = 4) {
        Capacity = initCapacity;
        Size = 0;
        Data = new int[Capacity];
    }

    
    ~Dynamic_Array() {
        delete[] Data;
    }

   
    void Insert(int value) {
        if (Size == Capacity)
            Resize();
        Data[Size++] = value;
    }

   
    void Delete(int index) {
        if (index < 0 || index >= Size) {
            cout << "Invalid index.\n";
            return;
        }
        for (int i = index; i < Size - 1; ++i)
            Data[i] = Data[i + 1];
        --Size;
    }

  
    void Display() const {
        cout << "Array: ";
        for (int i = 0; i < Size; ++i)
            cout << Data[i] << " ";
        cout << endl;
    }
};

int main() {
    Dynamic_Array Arr;

    Arr.Insert(10);
    Arr.Insert(20);
    Arr.Insert(30);
    Arr.Insert(40);
    Arr.Display();

    Arr.Delete(1); 
    Arr.Display();

    Arr.Insert(50);
    Arr.Display();

    return 0;
}