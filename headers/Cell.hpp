#ifndef CELL
#define CELL

#include <SFML/Graphics.hpp>
#define CELLWIDTH size+borderWidth
using namespace sf;

const int size = 35,borderWidth = 3;
const Vector2f cellSize(size+borderWidth,size+borderWidth), borderSize(size+borderWidth,borderWidth);
const Color unvisited = Color::Magenta, visited = Color::White, activeCell = Color::Blue, borderColor = Color::Black;

class Cell{
    int posX,posY;
    public: 
        bool isLeft,isBottom,isRight,isTop,isVisited,isActive;
        Cell(int a,int b):posX(a),posY(b){
            isVisited=isActive=false;
            isLeft=isBottom=isRight=isTop=true;
        }
        void drawCell(RenderWindow&);
        int getX() const { return posX; }
        int getY() const { return posY; }
};

void Cell::drawCell(RenderWindow& window){
    RectangleShape cell(cellSize);
    if(isActive) cell.setFillColor(activeCell);
    else cell.setFillColor((isVisited)?visited:unvisited);
    cell.setPosition(posX*size,posY*size);
    window.draw(cell);
    if(isLeft){
        RectangleShape left(borderSize);
        left.setFillColor(borderColor);
        left.setRotation(90);
        left.setPosition(size*posX+borderWidth,size*posY);
        window.draw(left);
    }
    if(isBottom){
        RectangleShape bottom(borderSize);
        bottom.setFillColor(borderColor);
        bottom.setPosition(size*posX,size*(posY+1));
        window.draw(bottom);
    }
    if(isRight){
        RectangleShape right(borderSize);
        right.setFillColor(borderColor);
        right.setRotation(90); right.setPosition(size*(posX+1)+borderWidth,size*posY);
        window.draw(right);
    }
    if(isTop){
        RectangleShape top(borderSize);
        top.setFillColor(borderColor);
        top.setPosition(size*posX,size*posY);
        window.draw(top);
    }
}

#endif //CELL