#include <iostream>
#include <memory>

namespace tavares{
    class Coord {
        private:
            int x,y;
        public:
            Coord();
            ~Coord();
            void coord_new(int new_x, int new_y);
            void show();
    };

    Coord::Coord() {
        x = 0;
        y = 0;
    }

    Coord::~Coord(){}

    void Coord::coord_new(int new_x, int new_y){
        x = new_x;
        y = new_y;
    }

    void Coord::show(){
        std::cout << "x = " << x << std::endl << "y = " << y << std::endl;
    }

    class Cube {
        private:
            int x,y,z;
        public:
            Cube();
            ~Cube();
            void setCube(int new_x, int new_y, int new_z);
            void show();
            void volume();
    };

    Cube::Cube() {
        x = 0;
        y = 0;
        z = 0;
    }

    Cube::~Cube(){}

    void Cube::setCube(int new_x, int new_y, int new_z){
        x = new_x;
        y = new_y;
        z = new_z;
    }

    void Cube::show(){
        std::cout << "x = " << x << std::endl << "y = " << y << std::endl << "z = " << z << std::endl;
    }

    void Cube::volume(){
        std::cout << x*y*z << std::endl;
    }
    
}

using namespace tavares;
int main() {
    std::unique_ptr<Coord> c1(new Coord);
    std::unique_prt<Cube> c2(new Cube);

    c1->coord_new(50,10);
    c2->setCube(10,20,30);
    c2->volume();

    return 0;
}