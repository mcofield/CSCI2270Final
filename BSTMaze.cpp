#include "BSTMaze.h"
#include <string>
#include <iostream>

using namespace std;

void BSTMaze(){
    health = 200;
    attack = 1;
    defence = 1;
}

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

bool BSTMaze::battle(int enemyHealth, int enemyAttack, int enemyDefence){
    int action;
    while(enemyHealth != 0 && health != 0){
        cout<<"Will you:"<<endl;
        cout<<"1. Flee"<<endl;
        cout<<"2. Fight"<<endl;
        cout<<"\n"<<endl;
        cin>>action;

        if(action == 1){
            cout<<"You ran away, heading down the left exit."<<endl;
            return 1;
        }

        else if(action == 2){
            health = health-(enemyAttack*10-defence*5);
            enemyHealth = enemyHealth-(attack*10-enemyDefence*5);
        }
        else{
            cout<<"That was not an option."<<endl;
        }
        if(health<0){
            health = 0;
        }
        if(enemyHealth = 0){
            enemyHealth = 0;
        }
        cout<<"You now have "<<health<<" health"<<endl;
        cout<<"Your enemy still has "<<enemyHealth<<" health"<<endl;
        cout<<"\n"<<endl;
    }
    if(enemyHealth == 0){
        cout<<"You defeated the enemy!"<<endl;
        return 0;
    }
    else if(health == 0){
        cout<<"You died :("<<endl;
        return 1;
    }
    else{
        cout<<"something went wrong"<<endl;
        return 1;
    }
}
