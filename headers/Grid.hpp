#ifndef GRID
#define GRID

#include <Cell.hpp>
#include <vector>
#include <iostream>
#define EASY 10
#define MEDIUM 15
#define HARD 20

std::vector<Cell> grid;

int index(int i,int j,int n){
    if(i<0 || j<0 || i>n-1 || j>n-1) throw std::string("Index out of Bounds");
    return j+i*n;
}

//TODO: Initializes the Grid
void GridInit(int n,RenderTexture& w){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            Cell x = Cell(i,j);
            if(i==0) x.isLeft = false;
            if(i==n-1) x.isRight = false;
            if(j==0) x.isTop = false;
            if(j==n-1) x.isBottom = false;
            x.drawCell(w);
            grid.push_back(x);
        }
    }
}

void DrawGrid(RenderTexture& win){
    for(int i=0;i<grid.size();i++) grid[i].drawCell(win);
}

//TODO: Return a random neighbour based on the current cell
Cell RandNeighbour(Cell& current,int n){
    std::vector<Cell> neighbours;
    try{
        if(current.isTop){
            Cell top = grid[index(current.getX(),current.getY()-1,n)];
            if(!top.isVisited) neighbours.push_back(top);
        }
        if(current.isRight){
            Cell right = grid[index(current.getX()+1,current.getY(),n)];
            if(!right.isVisited) neighbours.push_back(right);
        }
        if(current.isBottom){
            Cell bottom = grid[index(current.getX(),current.getY()+1,n)];
            if(!bottom.isVisited) neighbours.push_back(bottom);
        }
        if(current.isLeft){
            Cell left = grid[index(current.getX()-1,current.getY(),n)];
            if(!left.isVisited) neighbours.push_back(left);
        }
        if(neighbours.size()==0) return Cell(-1,-1);
        srand(time(NULL));
        return neighbours[0+(rand()%(neighbours.size()))];
    }catch(std::string str){
        std::cerr<<str<<std::endl;
    }
}

//TODO : Remove wall between 2 adjacent cells
void RemoveWall(Cell &a,Cell &b){
    int x = a.getX()-b.getX();
    if(x==1){
        a.isLeft = false;
        b.isRight = false;
    }else if(x==-1){
        a.isRight = false;
        b.isLeft = false;
    }
    int y = a.getY()-b.getY();
    if(y==1){
        a.isTop = false;
        b.isBottom = false;
    }else if(y==-1){
        a.isBottom = false;
        b.isTop = false;
    }
}

#endif //GRID