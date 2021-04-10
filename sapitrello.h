//
// Created by Hunor on 10/04/2021.
//

#ifndef PROJEKT_1_SAPITRELLO_H
#define PROJEKT_1_SAPITRELLO_H


typedef struct User {

    int id;

    char name[50];

} User;
typedef struct Card {
    char title[50];
    char desc[200];
    User assignedUser;
    int status;
    int userHistoryListSize;
    User *userHistoryList;

} Card;
typedef struct Board {
    int userListSize;
    int cardListSize;
    char name[50];
    Card *cardList;
    User userList[];


} Board;

typedef struct SapiTrello {
    int boardListSize;
    int userListSize;
    int cardListSize;
    User *userList;
    Board *boardList;
    Card *cardList;

} SapiTrello;

SapiTrello *CreateSapiTrello();

Board *CreateBoard();

User *CreateUser();

Card *CreateCard();

void AddUser(Board *board, User *user);

void AddCard(Board *board, Card *card);

void AddUserToCard(Card *card, User *user);

void PrintBoard(Board *board);

void PrintUser(User *user);

void PrintCard(Card *card);

void printAllCardsInBoard(Board *board);


void getAnyStatusCard(Board *board);

void getStatusOfCardByTitle(Board *board);

void getUserHistoryOfCardByTitle(Board *board);

void setCardStatusByCardTitle(Board *board);

void stCreateBoard(SapiTrello *sapiTrello);

void stCreateCard(SapiTrello *sapiTrello);

void stCreateUser(SapiTrello *sapiTrello);

void getBoards(SapiTrello *sapiTrello);

void getUsers(SapiTrello *sapiTrello);

void getCards(SapiTrello *sapiTrello);
void stAddUserToBoard(SapiTrello *sapiTrello);
void PrintMenu();

#endif //PROJEKT_1_SAPITRELLO_H
