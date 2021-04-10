//
// Created by Hunor on 10/04/2021.
//
#define MAX 65

#include "string.h"

#include "sapitrello.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

//ctrl + shift +u = kicsi size;
struct User arr_user[MAX];

User *CreateUser() {

    User *ref = (User *) malloc(sizeof(User));
    printf("Enter a User name:");
    scanf("%s", ref->name);


    srand(time(NULL));   // Initialization, should only be called once.
    int id = rand() % 1999;
    ref->id = id;

    return ref;
}
/*const char* getUserById(int id, User *userList,int listSize){
    for (int i = 0;i<listSize;++i){
        if (userList[i].id == id){
            return userList[i].name;
        }

    }

}*/

Board *CreateBoard() {
    Board *ref = (Board *) malloc(sizeof(Board));
    printf("Enter a Board name:");
    scanf("%s", ref->name);
    ref->userListSize = 0;
    ref->cardListSize = 0;
    return ref;
}

//User to Board
void AddUser(Board *board, User *user) {

    strcpy(board->userList[board->userListSize].name, user->name);
    board->userList[board->userListSize].id = user->id;
    board->userListSize = board->userListSize + 1;

}

void PrintUser(User *user) {
    printf("User: %s %d\n", user->name, user->id);
}

void PrintBoard(Board *board) {
    printf("Boardname: %s\n", board->name);
    for (int i = 0; i < board->userListSize; ++i) {
        PrintUser(&board->userList[i]);
    }

}

Card *CreateCard() {
    Card *ref = (Card *) malloc(sizeof(Card));
    printf("Enter a Card title:");
    scanf("%s", ref->title);
    printf("Enter Description:");
    scanf("%s", ref->desc);
    //status initialized by 0, equivalent to //TODO
    ref->status = 0;
    ref->assignedUser.id = 0;
    ref->userHistoryListSize = 0;
    return ref;
}

const char *getStatus(int status) {
    if (status == 0) {
        return "TODO";
    } else if (status == 1) {
        return "DOING";
    } else return "DONE";
}


void PrintCard(Card *card) {
    printf("CardTitle: %s with status %s\n", card->title, getStatus(card->status));
    printf("Description: %s\n",card->desc);
    if (card->assignedUser.id == 0) {
        printf("There is no working user on this card\n");
    } else {
        printf("Assigned user %s\n", card->assignedUser.name);
    }
}

//Card to Board
void AddCard(Board *board, Card *card){
    board->cardList = (struct Card*) malloc(sizeof(Card)*(board->cardListSize+1));
    strcpy(board->cardList[board->cardListSize].title, card->title);
    strcpy(board->cardList[board->cardListSize].desc, card->desc);
    board->cardList[board->cardListSize].assignedUser= card->assignedUser;
    board->cardList[board->cardListSize].status= card->status;
    board->cardListSize = board->cardListSize + 1;
}

void AddUserToCard(Card *card,User *user){
    strcpy(card->assignedUser.name, user->name);
    card->assignedUser = *user;
    card->userHistoryList[card->userHistoryListSize] = *user;
    card->userHistoryListSize = card->userHistoryListSize +1 ;
}

void printAllCardsinBoard(Board *board){
    for (int i=0;i<board->cardListSize;++i){
        PrintCard(&board->cardList[i]);
    }

}