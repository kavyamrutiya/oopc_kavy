#include <iostream>
using namespace std;

class Coordinates {
private:
    int x, y;

public:
    
    Coordinates(int xVal = 0, int yVal = 0) {
        x = xVal;
        y = yVal;
    }

    Coordinates* Move(int dx, int dy) {
        x += dx;
        y += dy;
        return this;
    }

  
    void Display() const {
        cout << "(" << x << ", " << y << ")" << endl;
    }
};


int main() {
    Coordinates* p = new Coordinates(5, 10);

    cout << "Initial Position: ";
    p->Display();

   
    p->Move(3, -2)->Move(-1, 4)->Move(0, -5);

    cout << "Final Position: ";
    p->Display();

    delete p;
    return 0;
}