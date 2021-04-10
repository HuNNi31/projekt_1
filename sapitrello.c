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

Board *CreateBoard() {
    Board *ref = (Board *) malloc(sizeof(Board));
    printf("Enter a Board name:");
    scanf("%s", ref->name);
    ref->userListSize = 0;
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
    //status initialized by 0, equivalent to TODO
    ref->status = 0;
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
    printf("CardTitle: %s with status %s", card->title, getStatus(card->status));
    printf("Description: %s",card->desc);
    if (card->assignedUserId == 0) {
        printf("There is no working user on this card");
    } else {
        printf("User on %d", card->assignedUserId);
    }
}

//Card to Board
/*void AddCard(Board *board, Card *card){
    strcpy(board->userList[board->userListSize].name, user->name);
    board->userList[board->userListSize].id = user->id;
    board->userListSize = board->userListSize + 1;
}*/