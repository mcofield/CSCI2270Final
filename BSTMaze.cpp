#include "BSTMaze.h"
#include <string>
#include <iostream>

using namespace std;

void BSTMaze(){}

void BSTMaze::BSTMazeCreate(int rooms){
    root = NULL;
    mazeRoom* tmp;
    for(int x = 0; x < rooms; x++){
        mazeRoom* n = new mazeRoom;
        if(root == NULL){
            root = n;
        }
        else{
            tmp = root;
            while(tmp->right != NULL){
                tmp = tmp->right
            }
            tmp->right = n;
        }
    }
}

void BSTMaze::~BSTMaze(){
    BSTdelete();
}

void BSTMaze::BSTDelete(mazeRoom* current){
    if(current->right != NULL){
        BSTDelete(current->right);
    }
    if(current->left != NULL){
        BSTDelete(current->left);
    }
    delete current;
}
