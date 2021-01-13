
// C program to illustrate call-by-methods
#include "iostream"
#include "unordered_map"



class Entity{
public:
        Entity()
        : x{}
        , y{}
        , z{}
        {}
        ~Entity() = default;
        int getValueX() const{return x;}
        int getValueY() const{return y;}
        int getValueZ() const{return z;}
        void setValueX(int X) { x = X;}
        void setValueY(int Y) {y = Y;}
        void setValueZ(int Z) {z = Z;}


private:
        int x;
        int y;
        int z;
public:
        std::unordered_map<std::string , int > person;
};



//Driver program
int main()
{
    Entity* entity;
    entity = new Entity();
    entity->setValueX(5);
    entity->setValueY(10);
    entity->setValueZ(20);

    std::cout<<"value of x  "<<entity->getValueX()<<std::endl;
    std::cout<<"value of y  "<<entity->getValueY()<<std::endl;
    std::cout<<"value of z  "<<entity->getValueZ()<<std::endl;

    // storing persons in the map
    entity->person["Buddha"] = 24;
    entity->person["Arpan"] = 24;
    entity->person["Amartya"] = 26;

    // iterating over map
    for(auto& x : entity->person){
        std::cout<<"Name: "<<x.first<<"  Age: "<<x.second<<std::endl;
    }

    delete entity;
}