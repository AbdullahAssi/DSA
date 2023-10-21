#include <iostream>
using namespace std;

class Triangle {
    int width;
    int height;
    int length;
public:
    Triangle(int w, int h, int l) : width(w), height(h), length(l) {
        int ans = width * height * length;
        cout << "The area of the box is " << ans/2 << endl;
    }
    void Perimeter(){
        int ans = width+ height + length;
        cout<<"The Parameter of the triangle is "<<ans;
    }
};

int main() {
    cout << "Task No 1:"<<endl;


    
    int w = 3; 
    int h = 4; 
    int l = 5; 

    Triangle myObj(w, h, l);
    myObj.Perimeter();
    return 0;
}