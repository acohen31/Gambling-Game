#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <limits>
using namespace std;

void directions(){
    system("clear");
    cout << "Rules:\n";
    cout << "Place a bet and pick a number between (1-10)\n";
    cout << "If you guess the correct number you get 10x your money back!\n"; 
}

bool validName(string name){
    for (int i = 0; i < name.length(); i++){
        if(name[i] < 'a' or name[i] > 'z'){
            name[i] += 32;
        }
        if(name[i] < 'a' or name[i] > 'z') return false;
    }
    return true;
}

void cinFail(int &input){
    while(cin.fail()){
        cin.clear(); // Clear bad input flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input: please re-enter: ";
        cin >> input;
    }
}

int main(){
    system("clear");
    // inits
    srand(time(0));
    string playerName = "";
    int playerBalance;
    int playerGuess;
    int playerBet;
    int randNumber;
    char playerChoice;

    cout << "\nWelcome to Aviv's Casino!\n\n";
    cout << "Please enter your name: ";
    cin >> playerName;
    while(!validName(playerName)){
        cout << "\nInvalid input: please re-enter: ";
        cin >> playerName;
    }
    cout << "Please enter your starting balance: ";
    cin >> playerBalance;
    if(cin.fail()) cinFail(playerBalance);
    cin.clear();
    
    do{
        system("clear");
        directions();
        cout << "Current balance: $" << playerBalance << endl;
        // Player's bet
        do{
            cout << playerName << " please enter how much you would like to bet on the next round: $";
            cin >> playerBet;
            if(cin.fail()) cinFail(playerBet);
            cin.clear();
            if(playerBet > playerBalance) cout << "\nBet cannot exceed your balance of: $" << playerBalance << endl;
        } while(playerBet > playerBalance);
        playerBalance -= playerBet;
        // Player's number
        do{
            playerGuess = '\0';
            cout << "\nPlease enter the number you'd like to place your bet on between 1-10: ";
            cin >> playerGuess;
            if(cin.fail()) cinFail(playerGuess);
            cin.clear();
            if(playerGuess < 1 or playerGuess > 10) cout << "\n The number is between 1-10.\n";
        }while(playerGuess < 1 or playerGuess > 10);
        // Random number between 1-10
        randNumber = rand()%(10-1 + 1) + 1;
        if(playerGuess == randNumber){
            cout << "\nCongratulations you just won $" << 10*playerBet << "!";
            playerBalance += (10*playerBet);
        }else{
            cout << "\nSorry wrong number!";
        }
        cout << "\n" << playerName << " enter Y or y to go again, anything else to stop: ";
        cin >> playerChoice;
    }while(playerChoice == 'Y' or playerChoice == 'y');
    cout << "\nYou're leaving with: $" << playerBalance << endl;
    cout << "Thanks for playing!\n";
}