#include<iostream>
#include"BSTMaze.h"

using namespace std;

int main(){
    int openingMenu = 0;
    BSTMaze dungeon;
    bool difficultyLevel = false;
    cout<<"========Welcome========"<<endl;
    while(!difficultyLevel){
        cout<<"Choose your difficulty:"<<endl;
        cout<<"1. Easy"<<endl;
        cout<<"2. Medium"<<endl;
        cout<<"3. Hard"<<endl;
        cin>>openingMenu;

        if(openingMenu == 1){
            dungeon.BSTMazeCreate(8);
            difficultyLevel = true;
        }

        else if(openingMenu == 2){
            dungeon.BSTMazeCreate(16);
            difficultyLevel = true;
        }

        else if(openingMenu == 3){
            dungeon.BSTMazeCreate(32);
            difficultyLevel = true;
        }

        else{
            cout<<"That was not an option."<<endl;
        }


    return 0;
}
