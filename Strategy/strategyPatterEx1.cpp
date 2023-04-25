#include <iostream>

using namespace std;

class FlyBehavior{ public: virtual void fly() const = 0; };
class QuackBehavior{ public: virtual void quack() const = 0; };

class Duck{
    public:
        FlyBehavior *fly;
        QuackBehavior *quack;
        Duck() = default;
        Duck(FlyBehavior *fly, QuackBehavior *quack): fly(fly), quack(quack){};
        
        void performFly(){ fly->fly(); }
        void performQuack(){ quack->quack(); }
};
class MallarDuck : public Duck{
    public:
        MallarDuck() = default;
        MallarDuck(FlyBehavior *fly, QuackBehavior *quack): Duck(fly, quack){};
};

class GoldenDuck : public Duck{
    public:
        GoldenDuck() = default;
        GoldenDuck(FlyBehavior *fly, QuackBehavior *quack): Duck(fly, quack){};
};

class FlyWithWings: public FlyBehavior{ public: virtual void fly() const { cout << "\nIm flying"; } };
class FlyWithNoWings: public FlyBehavior{ public: virtual void fly() const { cout << "\nI cant fly :<"; }; };

class Quack: public QuackBehavior{ public: virtual void quack() const { cout << "\nIm quacking"; }; };
class CantQuack: public QuackBehavior{ public: virtual void quack() const { cout << "\nI cant quack :("; }; };

void print(Duck *duck){
    duck->performFly();
    duck->performQuack();
}

int main()
{
    Quack q;  CantQuack cq;
    FlyWithWings fww; FlyWithNoWings fnw;
    
    MallarDuck md(&fww, &q);
    GoldenDuck gd(&fnw, &cq);
    
    print(&md); print(&gd);

    return 0;
}    