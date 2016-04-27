#include"BSTMaze(1).h"

using namespace std;

int main(){

    int playMenu = 0;
    int lossCounter = 0;
    int mainMenu=0;
    mazeRoom *currentRoom;
    bool difficultyLevel = false;
    cout<<"========Welcome========"<<endl;
    while(mainMenu!=3){
        BSTMaze dungeon;
        cout<<"Choose an option:"<<endl;
        cout<<"1. Play!"<<endl;
        cout<<"2. How to Play."<<endl;
        cout<<"3. Quit."<<endl;
        cin>>mainMenu;
        if(mainMenu == 1){
            while(!difficultyLevel){
                cout<<"Choose your difficulty:"<<endl;
                cout<<"1. Easy"<<endl;
                cout<<"2. Medium"<<endl;
                cout<<"3. Hard"<<endl;
                cin>>playMenu;

                if(playMenu == 1){
                    currentRoom = dungeon.mazeBuild(9);
                    difficultyLevel = true;
                }

                else if(playMenu == 2){
                    currentRoom = dungeon.mazeBuild(17);
                    difficultyLevel = true;
                }

                else if(playMenu == 3){
                    currentRoom = dungeon.mazeBuild(33);
                    difficultyLevel = true;
                }

                else{
                    cout<<"That was not an option."<<endl;
                }
            }
            //difficultyLevel = dungeon.battle(50, 1, .5);
            //difficultyLevel = dungeon.battle(80, 1.5, 2);
            while(lossCounter <= 1){
                string input;
                int outcome=-1;
                dungeon.generateRoom(currentRoom->funcIndex);
                cin>>input;
                cout<< "outcome: " << outcome <<" index: "<<currentRoom->index<<" funcindex: "<<currentRoom->funcIndex<<endl;
                outcome = dungeon.action(input, currentRoom->funcIndex);
                cout<<outcome<<endl;
                if(outcome==0){
                    dungeon.traverseTree(currentRoom,true);
                }
                else{
                    dungeon.traverseTree(currentRoom,false);
                    lossCounter+=outcome;
                }
                if(lossCounter!=2 && currentRoom->right==NULL){
                    cout<<"You've made it to the trayshur"<<endl;
                    return 0;
                }
                else if(lossCounter==2){
                    BSTMaze dungeon;
                    currentRoom = dungeon.mazeBuild(8);
                    lossCounter==0;
                    cout<<"you will DIE"<<endl;
                }

            }
            difficultyLevel = false;
        }
        else if(mainMenu == 2){
            cout<< "Welcome to the Dungeon of Data Structure Horrors. In this game,"<<endl;
            cout<< "you will navigate your way through a treacherous binary search "<<endl;
            cout<< "tree composed of dungeons. These dungeons contain questions"<<endl;
            cout<< "and foes to test your strength, intelligence, and your"<<endl;
            cout<< "endurance. Complete the tasks at hand to reach the treasure room"<<endl;
            cout<< "and your escape to safety. If you are to unfortunately fail two"<<endl;
            cout<< "tasks, the disturbance will cause the dungeon to collapse and"<<endl;
            cout<< "send you to your doom. Answer any and all questions with only"<<endl;
            cout<< "lower case letters, numbers, and in singular form."<<endl<<endl;
            cout<< "Good luck."<<endl<<endl;
            cout<< "Press enter to return to the main menu."<<endl;
            string a;
            getline(cin,a);
            cin.ignore();
        }
        else if(mainMenu == 3){
            cout<<"Goodbye!"<<endl;
        }
    }
        return 0;
}
