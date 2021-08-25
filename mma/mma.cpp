#include <iostream>
#include <memory>
#include <cmath>
#include <math.h>

/* 
equações: 
    f(t) = m*a(t) + k*y(t) + b*v(t)
    f(t) = m*y''(t) + b*y'(t) + k*y(t)
    EDO: mx²+bx+k=0 -> x = (-b +- sqr(b²-4mk))/2m (Soluções: x1, x2)
    b²-4mk > 0 -> superamortecido
    b²-4mk = 0 -> criticamente amortecido
    b²-4mk < 0 -> subamortecido
    => y(t) = C1*e^(x1*t) + C2*e^(x2*t)
    Variáveis iniciais:
    y(0) = y0 = C1+C2
    y'(0) = v0 = C1*x1 + C2*x2
    y''(0) = a0 = C1*x1² + C2*x2²
    C1 = (v0 - y0*x2)/(x1-x2)
    C2 = (v0 - y0*x1)/(x2-x1)
*/

class Model {
    private:
        double m,b,k;
        double x1,x2;
        double v0,a0,y0;
        double C1, C2;
    public:
        Model(double newM, double newB, double newK);
        ~Model();
        //valores iniciais do sistema massa-mola-amortecedor
        void setStart(double newV0, double newA0, double newY0);
        double getx1();
        double getx2();
        double getC1();
        double getC2();
};

Model::Model(double newM, double newB, double newK){
    m = newM;
    b = newB;
    k = newK;
    v0 = 0;
    a0 = 0;
    y0 = 0;
    C1 = 0;
    C2 = 0;
    x1 = (-b + pow((pow(b,2)-4*m*k),1/2))/(2*m);
    x2 = (-b - pow((pow(b,2)-4*m*k),1/2))/(2*m);
}

Model::~Model(){};

void Model::setStart(double newV0, double newA0, double newY0) {
    v0 = newV0;
    a0 = newA0;
    y0 = newY0;
    C1 = (v0 - y0*x2)/(x1-x2);
    C2 = (v0 - y0*x1)/(x2-x1);
}

double Model::getx1(){
    return x1;
}
double Model::getx2(){
    return x2;
}
double Model::getC1(){
    return C1;
}
double Model::getC2(){
    return C2;
}

class Controler {
    private:
        double C1,C2,x1,x2;
    public:
        Controler();
        ~Controler();
        void setControler(Model sistem);
        void Y(double t);
        void V(double t);
        void A(double t);
};

Controler::Controler(){
    C1 = 0;
    C2 = 0;
    x1 = 0;
    x2 = 0;
}
Controler::~Controler(){}

void Controler::setControler(Model sistem){
    std::cout << "Defina coordenada, velocidade e aceleração iniciais" << std::endl;
    std::cout << "y(0) = ";
    double y0;
    std::cin >> y0;
    std::cout << "v(0) = ";
    double v0;
    std::cin >> v0;
    std::cout << "a(0) = ";
    double a0;
    std::cin >> a0;

    sistem.setStart(v0, a0, y0);

    C1 = sistem.getC1();
    C2 = sistem.getC2();
    x1 = sistem.getx1();
    x2 = sistem.getx2();
}

void Controler::Y(double t){
    std::cout << "y(" << t << ") = " << C1*exp(x1*t) + C2*exp(x2*t);
}
void Controler::V(double t){
    std::cout << "v(" << t << ") = " << C1*x1*exp(x1*t) + C2*x2*exp(x2*t);
}
void Controler::V(double t){
    std::cout << "v(" << t << ") = " << C1*pow(x1,2)*exp(x1*t) + C2*pow(x2,2)*exp(x2*t);
}

int main(){
    std::cout << "Escolha os valores de massa, constante de amortecimento e constante da mola" << std::endl;
    std::cout << "m = ";
    double m;
    std::cin >> m;
    std::cout << "b = ";
    double b;
    std::cin >> b;
    std::cout << "k = ";
    double k;
    std::cin >> k;
    
    Model sistem = Model(m, b, k);
    std::unique_ptr<Controler> control(new Controler);

    control->setControler(sistem);
    
    while (true) {
        std::cout << "Escolha uma das opções" << std::endl << "1 - posição instantânea\n" << "2 - velocidade instantânea\n" << "3 - aceleração instantânea\n" << "0 - encerrar" << std::endl;
        char option = ' ';
        double t = 0;
        std::cin >> option;
        switch (option) {
            case '1':
                std::cout << "t = ";
                std::cin >> t;
                control->Y(t);
            case '2':
                std::cout << "t = ";
                std::cin >> t;
                control->V(t);
            case '3':
                std::cout << "t = ";
                std::cin >> t;
                control->A(t);
            case '0':
                break;
    };

    sistem.~Model();

    return 0;
}