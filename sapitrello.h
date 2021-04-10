//
// Created by Hunor on 10/04/2021.
//

#ifndef PROJEKT_1_SAPITRELLO_H
#define PROJEKT_1_SAPITRELLO_H


typedef struct User{

    int id;

    char name[50];

}User;
typedef struct Card{
    char title;
    char desc;
    int assignedUserId;
    int status;

}Card;
typedef struct Board{
    int userListSize;
    char name[50];
    User userList[];



}Board;
/*typedef struct SapiTrello{

    User user[];

}SapiTrello;
*/


User *CreateUser();
Board *CreateBoard();
void AddUser(Board *board, User *user );
void PrintBoard( Board *board);
void PrintUser( User *user);
Card *CreateCard();
void AddCard();
void PrintCard( Card *card);
#endif //PROJEKT_1_SAPITRELLO_H
