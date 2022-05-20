#include <iostream>
#include <Cell.hpp>
#include <Grid.hpp>
#include <unistd.h>
using namespace std;

std::vector<Cell> stack;

int main(int numbers,char** args){
    char mode = args[1][0];
    int level = 0;
    bool isFinal = false;
    switch(mode){
        case '1': level = EASY; break;
        case '2': level = MEDIUM; break;
        case '3': level = HARD; break;
        default: break;
    }
    try{
        Event evt;
        RenderWindow window(VideoMode(level*CELLWIDTH,level*CELLWIDTH),"Maze Generator",Style::Close);
        GridInit(level,window);
        Cell current = grid[0], previous(0,0);
        grid[index(current.getX(),current.getY(),level)].isActive = true;
        grid[index(current.getX(),current.getY(),level)].isVisited = true;
        while(window.isOpen()){
            while(window.pollEvent(evt)){
                if(evt.type == evt.Closed){
                    window.close();
                    cout<<"Window Closed"<<endl;
                    return EXIT_SUCCESS;
                }
            }
            if(current.getX()>=0 && current.getY()>=0){
                previous = current;
                current = RandNeighbour(current,level);
                
                if(current.getX()>=0 && current.getY()>=0){
                    //Remove wall
                    RemoveWall(grid[index(previous.getX(),previous.getY(),level)],
                            grid[index(current.getX(),current.getY(),level)]);

                    grid[index(previous.getX(),previous.getY(),level)].isActive = false;
                    grid[index(previous.getX(),previous.getY(),level)].isVisited = true;

                    grid[index(current.getX(),current.getY(),level)].isActive = true;
                    grid[index(current.getX(),current.getY(),level)].isVisited = true;

                    stack.push_back(previous);
                }else if(stack.size()!=0){
                    current = stack[stack.size()-1];
                    grid[index(previous.getX(),previous.getY(),level)].isActive = false;
                    grid[index(current.getX(),current.getY(),level)].isActive = true;
                    stack.pop_back();
                }
            } else{
                if(!isFinal){
                    grid[0].isActive = false;
                    cout<<"Maze generation complete"<<endl;
                    isFinal = true;
                }
            }
            usleep(50000);
            window.clear();
            DrawGrid(window);
            window.display();
        }
    }catch(exception exc){
        cerr<<exc.what()<<endl;
        return EXIT_FAILURE;
    }
}