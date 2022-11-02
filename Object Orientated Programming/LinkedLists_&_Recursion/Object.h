#ifndef OBJECT_H
#define OBJECT_H
#include <sstream>

class Object {
    private:
    protected:
        char icon;
        int xPos;
        int yPos;
        // Part 2
        bool solid;
        bool lit;
    public:
        Object* nextHoriz;
        Object* nextVert;
        Object* prevVert;
        Object* prevHoriz;
        Object* above;
        Object* below;
        Object(int x, int y);
        char getIcon();
        int getCoord(bool dimension);
        Object* getNext(bool dimension);
        Object* getPrev(bool dimension);
        void setNext(Object* obj, bool dimension);
        void setPrev(Object* obj, bool dimension);
        // Part 2
        void update();
        bool isSolid();
        void updateLight(char direction, int intensity);
        void ineract();
};
#endif