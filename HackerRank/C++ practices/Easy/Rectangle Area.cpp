//Shiro23

//https://www.hackerrank.com/challenges/rectangle-area/copy-from/99533154

#include <iostream>

using namespace std;

class Rectangle{
    protected:
    int width, height;
    public:
    virtual void display(){
        cout << width << " " << height << "\n";
    }
};

class RectangleArea : public Rectangle{
    public:
    void read_input(){
        int w,h;
        cin >> w >> h;
        width = w;
        height = h;
    }
    void display() override{
        cout << height * width << "\n";
    }
};

int main()
{
    /*
     * Declare a RectangleArea object
     */
    RectangleArea r_area;
    
    /*
     * Read the width and height
     */
    r_area.read_input();
    
    /*
     * Print the width and height
     */
    r_area.Rectangle::display();
    
    /*
     * Print the area
     */
    r_area.display();
    
    return 0;
}