#include "BSTMaze(1).h"

using namespace std;

BSTMaze::BSTMaze(){
    health = 200;
    attack = 1;
    defence = 1;
}
/*
mazeRoom BSTMaze::BSTMazeCreate(int rooms){
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
    return *root;
}
*/



mazeRoom *BSTMaze::mazeBuild(int rooms){
srand(time(NULL));
    vector<int> indicies;
    vector<mazeRoom*> ourRooms;
    for(int i=0;i<rooms;i++){
        int index = rand()%100+1;
        if(find(indicies.begin(),indicies.end(),index)!= indicies.end()){
            i--;
        }
        else{
            indicies.push_back(index);
        }
    }
    for(int i=0;i<indicies.size();i++){

        mazeRoom* building = new mazeRoom(indicies[i],i);
        ourRooms.push_back(building);
    }
    sort(ourRooms.begin(),ourRooms.end());
    root = sortTree(ourRooms,0,ourRooms.size()-1);

    return root; //this is where i got last and where it breaks
}

mazeRoom* BSTMaze::sortTree(vector<mazeRoom*> ourRooms, int start, int end){
    if(start>end){
        return NULL;
    }
    int mid=(start+end)/2;

    mazeRoom* curr = ourRooms[mid];

    curr->left = sortTree(ourRooms,start,mid-1);

    curr->right = sortTree(ourRooms,mid+1,end);

    return curr;
}

void BSTMaze::addRoomNode(int index, int fI){
    mazeRoom *newRoom = new mazeRoom;
    *newRoom = mazeRoom(index,fI);
    mazeRoom *temp = root;
    if(root==NULL){
        root=newRoom;
    }
    else{
        while(temp!=NULL){
            if((newRoom->index)<(temp->index)){
                if(temp->left==NULL){
                    temp->left = newRoom;
                    newRoom->parent=temp;
                    break;
                }
                temp = temp->right;
            }
            else{
                if(temp->right==NULL){
                    temp->right=newRoom;
                    newRoom->parent=temp;
                    break;
                }
                temp=temp->right;
            }
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

void BSTMaze::traverseTree(mazeRoom* curr, bool win){
    cout<<"traverse"<<endl;
    if(win){
        //cout<<curr->index<<endl;
        curr=curr->right;
        //cout<<curr->index<<endl;
    }
    else{
        curr=curr->left;
    }
}

void BSTMaze::generateRoom(int funcIndex){
    switch(funcIndex){
        case 1: cout<<"This is a riddle room."<<endl;
                cout<<"What movie is Chiddy Chiddy ! ! from?"<<endl;
                break;
        case 2: cout<<"This is a riddle room."<<endl;
                cout<<"func 2"<<endl;
                break;
        case 3: cout<<"This is a reflex room."<<endl;
                break;
        case 4: cout<<"This is a combat room."<<endl;
                break;
        case 5: cout<<"This is a quiz room."<<endl;
                cout<<"func 5"<<endl;
                break;
        case 6: cout<<"This is a quiz room."<<endl;
                cout<<"func 6"<<endl;
                break;
        case 7: cout<<"This is a quiz room."<<endl;
                cout<<"Func 7"<<endl;
                break;
        case 8: cout<<"This is a quiz room."<<endl;
                cout<<"Func 8"<<endl;
                break;
        default:
                cout <<"default" <<endl;
                break;
    }
}

int BSTMaze::action(string input, int funcIndex){
    switch(funcIndex+1){
        case 1: if(input=="y"){
                    cout<<"Good job!"<<endl;
                    return 0;
                }
                else{
                    cout<<"Die!"<<endl;
                    return 1;
                }
        case 2: if(input=="y"){
                    cout<<"Good job!"<<endl;
                    return 0;
                }
                else{
                    cout<<"Die!"<<endl;
                    return 1;
                }
        case 3: if(input=="y"){
                    cout<<"Good job!"<<endl;
                    return 0;
                }
                else{
                    cout<<"Die!"<<endl;
                    return 1;
                }
        case 4: if(input=="y"){
                    cout<<"Good job!"<<endl;
                    return 0;
                }
                else{
                    cout<<"Die!"<<endl;
                    return 1;
                }
        case 5: if(input=="y"){
                    cout<<"Good job!"<<endl;
                    return 0;
                }
                else{
                    cout<<"Die!"<<endl;
                    return 1;
                }
        case 6: if(input=="y"){
                    cout<<"Good job!"<<endl;
                    return 0;
                }
                else{
                    cout<<"Die!"<<endl;
                    return 1;
                }
        case 7: if(input=="y"){
                    cout<<"Good job!"<<endl;
                    return 0;
                }
                else{
                    cout<<"Die!"<<endl;
                    return 1;
                }
        case 8: if(input=="y"){
                    cout<<"Good job!"<<endl;
                    return 0;
                }
                else{
                    cout<<"Die!"<<endl;
                    return 1;
                }
    }
}
