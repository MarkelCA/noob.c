#include <cstdio>
#include <iostream>

class myClass
{
    public: 
        int x, y;
        char a, b;

        int sum(int x, int y){
        return x+y;
        }

};

class Circle
{  
    // private data member
    private:
        double radius;
      
    // public member function   
    public:   
        void compute_area(double r)
        {   // member function can access private
            // data member radius
            radius = r;
             
            double area = 3.14*radius*radius;
             
            std::cout << "Radius is: " << radius << "\n";
            std::cout << "Area is: " << area;
        }
     
};
class Parent
{  
    // protected data members
    protected:
    int id_protected;
    
};
 
// sub class or derived class from public base class
class Child : public Parent
{
    public:
    void setId(int id)
    {
         // Child class is able to access the inherited protected data members of base class
         
        id_protected = id;
         
    }
     
    void displayId() 
    {
        std::cout << "id_protected is: " << id_protected << "\n";
    }
};
int main()
{

    // Public
    printf("Public:\n");
    myClass p1 = {0, 1};
    p1.a = 'a';
    std::cout << "Character is: " << p1.a;

    printf("\n--------------\n");
    printf("Private:\n");
    // Private
    Circle obj;
    obj.compute_area(1.5);

    printf("\n--------------\n");
    printf("Protected:\n");
    // Protected
    Child obj1;
    obj1.setId(81);
    obj1.displayId();

return 0;
}
