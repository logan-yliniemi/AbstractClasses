#include <iostream>

class shape;
class triangle;
class circle;

////// SHAPE (Abstract Class)

class shape{
    //friend triangle;
    //friend circle;
protected:
    double area;
public:
    virtual double calc_area() = 0;
    virtual double get_area() = 0;
    void set_area(double a);
    
    const double pi = 3.1415;
};

void shape::set_area(double a){
    area = a;
}

///// TRIANGLE (Instantiation of Shape Abstract Class)

class triangle: public shape{
    double width;
    double height;
    
public:
    double calc_area(); /// required by being a shape
    double get_area(); /// required by being a shape
    void set_height(double);
    void set_width(double);
};

double triangle::calc_area(){
    area = 0.5 * width * height;
    return area;
}

void triangle::set_height(double h){
    height = h;
}

void triangle::set_width(double w){
    width = w;
}

double triangle::get_area(){
    return area;
}

///// CIRCLE (Instantiation of Shape Abstract Class

class circle: public shape{
    double radius;
    double diameter;
    
public:
    double get_area();
    double calc_area();
    void set_radius(double);
    void calc_diameter_from_radius();
};

double circle::calc_area(){
    area = pi * radius * radius;
    return area;
}

double circle::get_area(){
    return area;
}

void circle::set_radius(double r){
    radius = r;
}

void circle::calc_diameter_from_radius(){
    diameter = 2 * radius;
}

class testing{
    circle tc;
    triangle tt;
    bool circletest();
    bool triangletest();
    
public:
    bool suite();
};

bool testing::suite(){
    bool pass_indicator = false;
    bool ct_indicator = false;
    bool tt_indicator = false;
    try{
        
    if(circletest()){
        ct_indicator = true;
    }
    else{throw 123;}
    if(triangletest()){
        tt_indicator = true;
    }
    else{throw 321;}
    }
    catch(int a){
        std::cout << "ERROR IN TESTING SUITE: " << a << std::endl;
    }
    return pass_indicator;
}

bool testing::circletest(){
    bool pass_indicator = false;
    tc.set_radius(4.0);
    tc.calc_diameter_from_radius();
    tc.calc_area();
    
    if(tc.get_area() == tc.pi * 16.0){
        pass_indicator = true;
    }
    return pass_indicator;
}

bool testing::triangletest(){
    
    tt.set_height(5.0);
    tt.set_width(2.0);
    tt.calc_area();
    
    if(tt.get_area() == 5.0){
        return true;
    }
    return false;
}

double general_area(shape* S){ /// function that takes a generic shape
    double A;
    
    S->calc_area();
    A = S->get_area();
    
    std::cout << "general area function returns: " << A << std::endl;
    
    return A;
}

int main() {
    
    testing X;
    X.suite();
    
    triangle T;
    circle C;
    
    T.set_height(3.0);
    T.set_width(4.0);
    T.set_area(T.calc_area());
    std::cout << "TRIANGLE AREA IS: " << T.get_area() << std::endl;
    
    C.set_radius(2.0);
    C.calc_diameter_from_radius();
    C.set_area(C.calc_area());
    std::cout << "CIRCLE AREA IS: " << C.get_area() << std::endl;
    
    triangle* pT = &T;
    general_area(pT);
    
    return 0;
}
