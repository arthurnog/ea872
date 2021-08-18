#include <iostream>

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

    void Coord::coord_new(int new_x, int new_y){
        x = new_x;
        y = new_y;
    }

    void Coord::show(){
        std::cout << "x = " << x << "\n" << "y = " << y << std::endl;
    }

    class Cube {
        private:
            int x,y,z;
        public:
            Cube();
            ~Cube();
            void cube_new(int new_x, int new_y, int new_z);
            void show();
            void volume();
    };

    Cube::Cube() {
        x = 0;
        y = 0;
        z = 0;
    }

    void Cube::cube_new(int new_x, int new_y, int new_z){
        x = new_x;
        y = new_y;
        z = new_z;
    }

    void Cube::show(){
        std::cout << "x = " << x << "\n" << "y = " << y << "\n" << "z = " << z << std::endl;
    }

    void Cube::volume(){
        std::cout << x*y*z << std::endl;
    }
    
}

using namespace tavares;
int main() {
    Coord *c1 = new Coord();
    Cube *c2 = new Cube();

    c1->coord_new(50,10);
    c2->cube_new(10,20,30);
    c2->volume();

    return 0;
}