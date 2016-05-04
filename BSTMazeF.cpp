#include "BSTMazeF.h"
#include <string>

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
    if(current != NULL)
    {
        if(current->right != NULL){
            BSTDelete(current->right);
        }
        if(current->left != NULL){
            BSTDelete(current->left);
        }
    }
    delete current;
}

int BSTMaze::hexToDec(int x){
    int letter;
    int y = 0;
    for(int p = 0; p < x; p++){
        letter = rand() % 100;
        y = y + letter;
    }
    return y;
}

bool BSTMaze::accuracyCheck(int first, int second){
    int sum;
    int firstLocation = hexToDec(first);
    int secondLocation = hexToDec(second);
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

int BSTMaze::battle(int enemyHealth, int enemyAttack, int enemyDefence){
    int action;
    while(enemyHealth != 0 || health != 0){
        cout<<"Will you:"<<endl;
        cout<<"1. Flee"<<endl;
        cout<<"2. Fight"<<endl;
        cin>>action;

        if(action == 1){
            cout<<"You ran away, heading down the left exit."<<endl;
            return 1;
        }

        else if(action == 2){
            bool miss = accuracyCheck(numberOfRooms, enemyDefence);
            bool critical = criticalCheck(numberOfRooms, enemyAttack, enemyDefence);
            if(!miss){
                if(critical){
                    cout<<"critical hit!"<<endl;
                    attack = attack + .5;
                    health = health-(enemyAttack*10-defence*5);
                    enemyHealth = enemyHealth-(attack*10-enemyDefence*5);
                    attack = attack - .5;
                }
                else{
                    health = health-(enemyAttack*10-defence*5);
                    enemyHealth = enemyHealth-(attack*10-enemyDefence*5);
                }

            }
            else{
                cout<<"You missed"<<endl;
            }
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

void BSTMaze::traverseTree(mazeRoom*& curr, bool win){
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
        case 1: cout<<"This is a antijoke room."<<endl;
                cout<<"What does 1 + 1 =  ?"<<endl;
                break;
        case 2: cout<<"This is a riddle room."<<endl;
                cout<<"Young I am tall, old I am short. I love to glow. Breath is my foe. What am I?"<<endl;
                break;
        case 3: cout<<"This is a antijoke room."<<endl;
                cout<<"What is grey and can't swim?"<<endl;
                break;
        case 4: cout<<"This is a combat room, are you ready? Y or N? "<<endl;
                break;
        case 5: cout<<"This is a quiz room."<<endl;
                cout<<"What is 8%3?"<<endl;
                break;
        case 6: cout<<"This is a quiz room."<<endl;
                cout<<"Velocity is the ____ of acceleration"<<endl;
                break;
        case 7: cout<<"This is a riddle room."<<endl;
                cout<<"The poor have me, the rich don't. If you eat me you will die. What am I?"<<endl;
                break;
        case 8: cout<<"This is a combat room, are you ready? Y or N? "<<endl;
                break;
        case 9: cout<<"This is a riddle room."<<endl;
                cout<<"What has a mouth but never eats, has a bed but does not sleep, and always runs but never walks?"<<endl;
                break;
        case 10: cout<<"This is a antijoke room."<<endl;
                cout<<"What is green and has wheels?"<<endl;
                break;
        case 11: cout<<"This is a quiz room."<<endl;
                cout<<"What is the closest planet to the sun?"<<endl;
                break;
        case 12: cout<<"This is a combat room, are you ready? Y or N? "<<endl;
                break;
        case 13: cout<<"This is a antijoke room."<<endl;
                cout<<"What's big, yellow, and hurts when it hits you in the eye?"<<endl;
                break;
        case 14: cout<<"This is a quiz room."<<endl;
                cout<<"What element isn't magnetic at room temperature (respond with element name)"<<endl;
                cout<<"a. iron"<<endl<<"b. cobalt"<<endl;
                cout<<"c. aluminum"<<endl<<"d. nickel"<<endl;
                break;
        case 15: cout<<"This is a riddle room."<<endl;
                cout<<"What is the longest word in the dictionary?"<<endl;
                break;
        case 16: cout<<"This is a quiz room."<<endl;
                cout<<"What is the powerhouse of the cell?"<<endl;
                break;
        case 17: cout<<"This is a combat room, are you ready? Y or N? "<<endl;
                break;
        case 18: cout<<"This is a meme room."<<endl;
                cout<<"What vape flavor screams organic?"<<endl;
                break;
        case 19: cout<<"This is a joke room."<<endl;
                cout<<"What's a magician's best friend?"<<endl;
                break;
        case 20: cout<<"This is a quiz room."<<endl;
                cout<<"How many moons does Mars have?"<<endl;
                break;
        case 21: cout<<"This is a combat room, are you ready? Y or N? "<<endl;
                break;
        case 22: cout<<"This is a meme room."<<endl;
                cout<<"Born too late to explore the world, born too early to explore the universe. Born just in time to browse dank ___s."<<endl;
                break;
        case 23: cout<<"This is a meme room."<<endl;
                cout<<"What does the green dinosaur say?"<<endl;
                break;
        case 24: cout<<"This is a quiz room."<<endl;
                cout<<"What changes . to -> ?"<<endl;
                break;
        case 25: cout<<"This is a quiz room."<<endl;
                cout<<"What's the front page of the internet?"<<endl;
                break;
        case 26: cout<<"This is a riddle room."<<endl;
                cout<<"What always falls and never goes up?"<<endl;
                break;
        case 27: cout<<"This is a riddle room."<<endl;
                cout<<"What stays on the corner but travels the world?"<<endl;
                break;
        case 28: cout<<"This is a combat room, are you ready? Y or N? "<<endl;
                break;
        case 29: cout<<"This is a combat room, are you ready? Y or N? "<<endl;
                break;
        case 30: cout<<"This is a meme room."<<endl;
                cout<<"It's just a _____ bro!"<<endl;
                break;
        case 31: cout<<"This is a quiz room."<<endl;
                cout<<"What subatomic particle was briefly (and incorrectly) thought to travel faster than light?"<<endl;
                break;
        case 32: cout<<"This is a quiz room."<<endl;
                cout<<"Which letter doesn't appear in the periodic table?"<<endl;
                break;
        case 33: cout<<"This is a combat room, are you ready? Y or N? "<<endl;
                break;
        default:
                cout <<"default" <<endl;
                break;
    }
}

int BSTMaze::action(string input, int funcIndex){
    switch(funcIndex){
        case 1: if(input=="window"){
                    cout<<"Good job!"<<endl;
                    return 0;
                }
                else{
                    cout<<"It's window, duhh. Didn't you learn anything in the first grade?!"<<endl;
                    return 1;
                }
        case 2: if(input=="candle"){
                    cout<<"Good job!"<<endl;
                    return 0;
                }
                else{
                    cout<<"The answer was: candle!"<<endl;
                    return 1;
                }
        case 3: if(input=="castle"){
                    cout<<"Good job!"<<endl;
                    return 0;
                }
                else{
                    cout<<"The answer was: castle!"<<endl;
                    return 1;
                }
        case 4: //combat
                return 0; //need to impliment 0 for loss and 1 for win
        case 5: if(input=="2" || input=="two"){
                    cout<<"Good job!"<<endl;
                    return 0;
                }
                else{
                    cout<<"The answer was: two!"<<endl;
                    return 1;
                }
        case 6: if(input=="derivative"){
                    cout<<"Good job!"<<endl;
                    return 0;
                }
                else{
                    cout<<"The answer was: derivative!"<<endl;
                    return 1;
                }
        case 7: if(input=="nothing"){
                    cout<<"Good job!"<<endl;
                    return 0;
                }
                else{
                    cout<<"The answer was: nothing!"<<endl;
                    return 1;
                }
        case 8: //combat
                return 0; //need to impliment 0 for loss and 1 for win
        case 9: if(input=="river"){
                    cout<<"Good job!"<<endl;
                    return 0;
                }
                else{
                    cout<<"The answer was: river!"<<endl;
                    return 1;
                }
        case 10: if(input=="grass"){
                    cout<<"Good job!"<<endl;
                    return 0;
                }
                else{
                    cout<<"The answer was: grass! I lied about the wheels"<<endl;
                    return 1;
                }
        case 11: if(input=="mercury"){
                    cout<<"Good job!"<<endl;
                    return 0;
                }
                else{
                    cout<<"The answer was: mercury!"<<endl;
                    return 1;
                }
        case 12: //combat
                return 0; //need to impliment 0 for loss and 1 for win
        case 13: if(input=="bulldozer"){
                    cout<<"Good job!"<<endl;
                    return 0;
                }
                else{
                    cout<<"The answer was: bulldozer!"<<endl;
                    return 1;
                }
        case 14: if(input=="aluminum"){
                    cout<<"Good job!"<<endl;
                    return 0;
                }
                else{
                    cout<<"The answer was: aluminum!"<<endl;
                    return 1;
                }
        case 15: if(input=="smiles"){
                    cout<<"Good job!"<<endl;
                    return 0;
                }
                else{
                    cout<<"The answer was: smiles!"<<endl;
                    return 1;
                }
        case 16: if(input=="mitochondria"){
                    cout<<"Good job!"<<endl;
                    return 0;
                }
                else{
                    cout<<"The answer was: mitochondria!"<<endl;
                    return 1;
                }
        case 17: //combat
                 return 0; //need to impliment 0 for loss and 1 for win
        case 18: if(input=="churro"){
                    cout<<"Good job!"<<endl;
                    return 0;
                }
                else{
                    cout<<"The answer was: churro!"<<endl;
                    return 1;
                }
        case 19: if(input=="labracadabrador"){
                    cout<<"Good job!"<<endl;
                    return 0;
                }
                else{
                    cout<<"The answer was: labracadabrador!"<<endl;
                    return 1;
                }
        case 20: if(input=="two" || input=="2"){
                    cout<<"Good job!"<<endl;
                    return 0;
                }
                else{
                    cout<<"The answer was: two!"<<endl;
                    return 1;
                }
        case 21: //combat
                return 0; //need to impliment 0 for loss and 1 for win
        case 22: if(input=="meme"){
                    cout<<"Good job!"<<endl;
                    return 0;
                }
                else{
                    cout<<"The answer was: meme!"<<endl;
                    return 1;
                }
        case 23: if(input=="yee"){
                    cout<<"Good job!"<<endl;
                    return 0;
                }
                else{
                    cout<<"The answer was: yee!"<<endl;
                    return 1;
                }
        case 24: if(input=="pointer"){
                    cout<<"Good job!"<<endl;
                    return 0;
                }
                else{
                    cout<<"The answer was: pointer!"<<endl;
                    return 1;
                }
        case 25: if(input=="reddit"){
                    cout<<"Good job!"<<endl;
                    return 0;
                }
                else{
                    cout<<"The answer was: reddit!"<<endl;
                    return 1;
                }
        case 26: if(input=="rain"){
                    cout<<"Good job!"<<endl;
                    return 0;
                }
                else{
                    cout<<"The answer was: rain!"<<endl;
                    return 1;
                }
        case 27: if(input=="stamp"){
                    cout<<"Good job!"<<endl;
                    return 0;
                }
                else{
                    cout<<"The answer was: stamp!"<<endl;
                    return 1;
                }
        case 28: //combat
                return 0; //need to impliment 0 for loss and 1 for win
        case 29: //combat
                return 0; //need to impliment 0 for loss and 1 for win
        case 30: if(input=="prank"){
                    cout<<"Good job!"<<endl;
                    return 0;
                }
                else{
                    cout<<"The answer was: prank!"<<endl;
                    return 1;
                }
        case 31: if(input=="neutrino"){
                    cout<<"Good job!"<<endl;
                    return 0;
                }
                else{
                    cout<<"The answer was: neutrino!"<<endl;
                    return 1;
                }
        case 32: if(input=="j"){
                    cout<<"Good job!"<<endl;
                    return 0;
                }
                else{
                    cout<<"The answer was: j!"<<endl;
                    return 1;
                }
        case 33: //combat
                return 0; //need to impliment 0 for loss and 1 for win
        default:
                cout <<"default" <<endl;
                break;
    }
}
