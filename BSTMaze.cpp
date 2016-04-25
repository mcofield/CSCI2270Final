#include "BSTMaze.h"
#include <string>
#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

BSTMaze::BSTMaze(){
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
                tmp = tmp->right;
            }
            tmp->right = n;
        }
    }
}

BSTMaze::~BSTMaze(){
    BSTDelete(root);
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
/*
int BSTMaze::hexToDec(int x){
    int* z = &x;
    //double t = static_cast<double>(z);
    int y;
    int letter;
    //string temporaryString = to_string(t);
    for(int p = 0; p < 8; p++){
        letter = atoi(z[p]);
        y = y + letter;
    }
    return y;
}

bool BSTMaze::accuracyCheck(int first, int second){
    int sum;
    int firstLocation = hexToDec(first);
    cout<<"firstLocation is "<<firstLocation<<endl;
    int secondLocation = hexToDec(second);
    cout<<"SecondLocation is "<<secondLocation<<endl;
    sum = firstLocation + secondLocation;
    if(sum%6 < 2){
        return true;
    }
    else
        return false;
}

bool BSTMaze::criticalCheck(int first, int second, int third){
    int sum2;
    int firstLocation = hexToDec(first);
    int secondLocation = hexToDec(second);
    int thirdLocation = hexToDec(third);
    sum2 = firstLocation + secondLocation + thirdLocation;
    if((sum2)%10 < 2){
        return true;
    }
    else
        return false;
}
*/
bool BSTMaze::battle(int enemyHealth, int enemyAttack, int enemyDefence){
    int action;
    while(enemyHealth != 0 && health != 0){
        cout<<"Will you:"<<endl;
        cout<<"1. Flee"<<endl;
        cout<<"2. Fight"<<endl;
        cin>>action;

        if(action == 1){
            cout<<"You ran away, heading down the left exit."<<endl;
            return 1;
        }

        else if(action == 2){
            /*bool miss = accuracyCheck(enemyHealth, enemyDefence);
            bool critical = criticalCheck(enemyHealth, enemyAttack, enemyDefence);
            if(!miss){
                if(critical){
                    cout<<"critical hit!"<<endl;
                    attack = attack + .5;
                    health = health-(enemyAttack*10-defence*5);
                    enemyHealth = enemyHealth-(attack*10-enemyDefence*5);
                    attack = attack - .5;
                }
                else{*/
                    health = health-(enemyAttack*10-defence*5);
                    enemyHealth = enemyHealth-(attack*10-enemyDefence*5);
                /*}

            }
            else{
                cout<<"You missed"<<endl;
            }*/
        }
        else{
            cout<<"That was not an option."<<endl;
        }
        if(health<0){
            health = 0;
        }
        if(enemyHealth < 0){
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
