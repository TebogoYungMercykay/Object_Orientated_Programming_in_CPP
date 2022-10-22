// C++ program to demonstrate classes
#include <iostream>

using namespace std;
class class_Name
{
    private:
    protected:
    public:
        string name;
        int id;   
        // printname is not defined inline
        void printname();
        // printid is defined inline
        void printid()
        {
            cout << "User id is: " << id;
        }
};
 
// Definition of printname using scope resolution operator ::
void class_Name::printname()
{
    cout << "User is: " << name;
}
// Main function
int main()
{
    class_Name obj1;
    obj1.name = "xyz";
    obj1.id=15;
    // call printname()
    obj1.printname();
    cout << endl;
    // call printid()
    obj1.printid();
    return 0;
}
