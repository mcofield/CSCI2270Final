#ifndef BSTMAZE_H
#define BSTMAZE_H
#include<string>

using namespace std;

struct mazeRoom{
    int index;
    int funcIndex;
    mazeRoom* right;
    mazeRoom* left;
    mazeRoom* parent;

    mazeRoom(){
        right = NULL;
        left = NULL;
        parent = NULL;
    };
    mazeRoom(int x, int fI, mazeRoom* r, mazeRoom* l, mazeRoom* p){
        index = x;
        funcIndex = fI;
        right = r;
        left = l;
        parent = p;
    }
};

class BSTMaze{
    public:
        void BSTMazeCreate(int rooms);
        BSTMaze();
        ~BSTMaze();
        bool battle(int, int, int); //if 1, left turn.  if 0, right turn.
        bool accuracyCheck(int, int);
        bool criticalCheck(int, int, int);
        int hexToDec(int);
    private:
        int health;
        int attack;
        int defence;
        mazeRoom *root;
        void BSTDelete(mazeRoom*);
        int leftTurns;
        int numberOfRooms;

};
#endif // BSTMAZE_H
