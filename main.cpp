#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <conio.h>

using namespace std;

void game_map();
void ask_roll_again();
void rules();
void clear_screen();

int main()
{
    srand(static_cast<unsigned int>(time(nullptr)));

    int select;

    cout << "\n                                              CONSOLE RANDOM" << endl << endl;
    cout << "                                              1. Start Game" << endl;
    cout << "                                              2. Rules" << endl;
    cout << "                                              3. Exit" << endl << endl;
    cout << "                                              Select: ";
    cin >> select;

    switch(select){
    case 1:
        game_map();
        break;
    case 2:
        rules();
        break;
    case 3:
        exit(0);
    }
    return 0;
}

void clear_screen(){
    system("cls");
}

void rules(){

    clear_screen();
    cout << "\n\n                                               --- GAME OBJECTIVE --" << endl;
    cout << "                        - User and AI roll a number between 1 and 10" << endl;
    cout << "                        - The user loses health if the rolled numbers are the same." << endl;
    cout << "                        - The game ends if the user 's health reaches 0 (WIN) or if the user rolls a 10. (LOSE)" << endl << endl;

    cout << "-                                               --- GAME MECHANICS --" << endl;
    cout << "                        - User and AI take turns rolling." << endl;
    cout << "                        - User starts with 5 lives." << endl;
    cout << "                        - If the user's roll matches the AI's roll, the user loses 1 life" << endl;
    cout << "                        - The user wins by rolling 10 before losing all lives." << endl << endl;

    cout << "                                               -- Good luck --" << endl << endl;
    cout << "                                       PRESS ANY KEY TO RETURN..." << endl << endl;
    _getch();
    clear_screen();
    main();

}

class Character{
    public:
        Character_info(){
            player_index = rand() % number_of_index;
            enemy_index = rand() % number_of_index;
        }
        int get_user_life(){
            return life;
        }
        int get_user_index(){
            return player_index;
        }
        int get_enemy_index(){
            return enemy_index;
        }
        int decrement_life(){
            if (life > 0){
                life--;
            }
            else{
                cout << "You Lose!!" << endl;
            }
            return life;
        }
    private:
        int life = 5;
        int number_of_index = 10;
        int player_index;
        int enemy_index;

};

void game_map(){
    Character character_object;
    // player
    string array_map[10] = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10"};

    int user_index = character_object.get_user_index();
    int enemy_index = character_object.get_enemy_index();
    int life = character_object.get_user_life();
    clear_screen();
    cout << "\n                                          Your index: " << user_index + 1 << endl;
    cout << "                                          Enemy index: " << enemy_index + 1 << endl << endl;

    array_map[user_index] = "X";

    cout << "                                                    [" << array_map[0] << "]" << endl;
    cout << "                                                     |" << endl;
    cout << "                                                     |" << endl;
    cout << "                                                     |" << endl;
    cout << "                           +----------|-[" << array_map[1] << "]----------|-------[" << array_map[2] << "]------+" << endl;
    cout << "                                      |              |                |" << endl;
    cout << "                                      |              |                |" << endl;
    cout << "                                      |              |                |" << endl;
    cout << "                                      |              |                |" << endl;
    cout << "                                      |              |                |" << endl;
    cout << "                           +---[" << array_map[3] << "]----|------[" << array_map[4] << "]-----|---------------[" << array_map[5] << "]----------+" << endl;
    cout << "                                      |              |                |" << endl;;
    cout << "                                      |             [" << array_map[7] << "]               |" << endl;
    cout << "                                      |              |                |" << endl;
    cout << "                                      |              |                |" << endl;
    cout << "                                      |[" << array_map[6] << "]-----------|---------[" << array_map[8] << "]----|----------------+" << endl;
    cout << "                                      |              |" << endl;
    cout << "                                      |              |" << endl;
    cout << "                                      |              |" << endl;
    cout << "                                      |              |" << endl;
    cout << "                           +---[" << array_map[9] << "]---|--------------+" << endl;
    cout << "                                      |" << endl;
    cout << "                                      |" << endl;
    cout << "                                      |" << endl;
    cout << "                                      +" << endl;

    if (user_index + 1 == 10){
        cout << "You win!" << endl;
        cout << "Total life left: " << life << endl;
    }
    else if (user_index == enemy_index){
        cout << "You and AI meet on one index. 1 life will be deducted!" << endl;
        cout << "Total life left: " << character_object.decrement_life() << endl;
    }
    else{
        cout << "Roll again" << endl;
        cout << "Total life left: " << life << endl;

    }
    ask_roll_again();
}

void ask_roll_again(){
    char roll;
    while (true){
        cout << "Do you want to roll again? [Y/N]";
        cin >> roll;

        if (roll == 'Y' || roll == 'y'){
            game_map();
        }
        else if (roll == 'N' || roll == 'n'){
            exit(0);
        }
        else{
            cout << "Invalid input" << endl;
        }
    }
}





