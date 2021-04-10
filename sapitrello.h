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
    char title[50];
    char desc[200];
    User assignedUser;
    int status;
    int userHistoryListSize;
    User userHistoryList[];

}Card;
typedef struct Board{
    int userListSize;
    int cardListSize;
    char name[50];
    Card *cardList;
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
void AddCard(Board *board, Card *card);
void PrintCard( Card *card);
void AddUserToCard(Card *card,User *user);
void printAllCardsinBoard(Board *board);
#endif //PROJEKT_1_SAPITRELLO_H
