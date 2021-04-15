//
// Created by Hunor on 10/04/2021.
//
#define MAX 65
#define _CRT_SECURE_NO_WARNINGS

#include "string.h"

#include "sapitrello.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

//ctrl + shift +u = kicsi size;
SapiTrello *CreateSapiTrello() {
    SapiTrello *ref = (SapiTrello *) malloc(sizeof(SapiTrello));
    ref->userListSize = 0;
    ref->cardListSize = 0;
    ref->boardListSize = 0;
    ref->cardList = (struct Card *) malloc(sizeof(Card) * MAX);
    ref->userList = (struct User *) malloc(sizeof(User) * MAX);
    ref->boardList = (struct Board *) malloc(sizeof(Board) * MAX);

    return ref;
}

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
    ref->cardListSize = 0;
    ref->cardList = (struct Card *) malloc(sizeof(Card) * MAX);
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

void PrintUsersBoard(Board *board) {
    printf("BoardName: %s\n", board->name);
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
    ref->assignedUser.id = 0;
    ref->userHistoryList = (struct User *) malloc(sizeof(User) * MAX);
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
    printf("Description: %s\n", card->desc);
    if (card->assignedUser.id == 0) {
        printf("There is no working user on this card\n");
    } else {
        printf("Assigned user %s\n", card->assignedUser.name);
    }
    printf("Assigned user history(%d):\n", card->userHistoryListSize);
    for (int i = 0; i < card->userHistoryListSize; i++) {
        PrintUser(&card->userHistoryList[i]);
    }
    printf("\n");
}

//Card to Board
void AddCard(Board *board, Card *card) {
    int index = board->cardListSize;
    strcpy(board->cardList[index].title, card->title);
    strcpy(board->cardList[index].desc, card->desc);
    strcpy(board->cardList[index].assignedUser.name, card->assignedUser.name);
    board->cardList[index].assignedUser.id = card->assignedUser.id;
    board->cardList[index].userHistoryList = card->userHistoryList;
    board->cardList[index].userHistoryListSize = card->userHistoryListSize;
    board->cardList[index].status = card->status;
    board->cardListSize = board->cardListSize + 1;
}

void AddUserToCard(Card *card, User *user) {
    strcpy(card->assignedUser.name, user->name);
    card->assignedUser = *user;
    strcpy(card->userHistoryList[card->userHistoryListSize].name, user->name);
    card->userHistoryList[card->userHistoryListSize].id = user->id;
    card->userHistoryListSize = card->userHistoryListSize + 1;
}

void printAllCardsInBoard(Board *board) {
    for (int i = 0; i < board->cardListSize; ++i) {
        PrintCard(&board->cardList[i]);
    }
}

// (x)
void getAnyStatusCard(Board *board) {
    printf("To see Cards with Status: TODO/DOING/DONE"
           " \nType the expected status:");
    char status[6];
    scanf("%s", status);
    for (int i = 0; i < board->cardListSize; ++i) {
        if (strcmp(status, getStatus(board->cardList[i].status)) == 0) {
            PrintCard(&board->cardList[i]);
        }
    }
}

void getStatusOfCardByTitle(Board *board) {
    printf("To see a specific Card's status type in the Cards' title:");
    char title[50];
    scanf("%s", title);
    for (int i = 0; i < board->cardListSize; ++i) {
        if (strcmp(title, board->cardList[i].title) == 0) {
            printf("Status: %s\n", getStatus(board->cardList[i].status));
        }
    }
}

void getUserHistoryOfCardByTitle(Board *board) {
    printf("To see the users who worked on some Card type in the Cards' title:\n");
    char title[50];
    scanf("%s", title);
    for (int i = 0; i < board->cardListSize; ++i) {
        if (strcmp(title, board->cardList[i].title) == 0) {
            for (int j = 0; j < board->cardList[i].userHistoryListSize; ++j) {
                PrintUser(&board->cardList[i].userHistoryList[j]);

            }
        }
    }
}

void setCardStatusByCardTitle(Board *board) {
    printf("To change the status of card, type the Card's Title:\n");
    char title[50];
    scanf("%s", title);
    for (int i = 0; i < board->cardListSize; ++i) {
        if (strcmp(title, board->cardList[i].title) == 0) {
            if (board->cardList[i].status == 2) {
                printf("This Card is Done");
            } else {
                board->cardList[i].status = board->cardList[i].status + 1;
                printf("Changed Status to: %s\n", getStatus(board->cardList[i].status));
            }

        }
    }
}

void stCreateBoard(SapiTrello *sapiTrello) {
    Board *board = CreateBoard();
    sapiTrello->boardList[sapiTrello->boardListSize] = *board;
    sapiTrello->boardListSize++;
}

void stCreateCard(SapiTrello *sapiTrello) {
    Card *card = CreateCard();
    sapiTrello->cardList[sapiTrello->cardListSize] = *card;
    sapiTrello->cardListSize++;
}

void stCreateUser(SapiTrello *sapiTrello) {
    User *user = CreateUser();
    sapiTrello->userList[sapiTrello->userListSize] = *user;
    sapiTrello->userListSize++;
    PrintUser(user);
}

void getBoards(SapiTrello *sapiTrello) {
    for (int i = 0; i < sapiTrello->boardListSize; ++i) {
        PrintUsersBoard(&sapiTrello->boardList[i]);
    }
}

void getUsers(SapiTrello *sapiTrello) {
    for (int i = 0; i < sapiTrello->userListSize; ++i) {
        PrintUser(&sapiTrello->userList[i]);
    }
}

void getCards(SapiTrello *sapiTrello) {
    for (int i = 0; i < sapiTrello->cardListSize; ++i) {
        PrintCard(&sapiTrello->cardList[i]);
    }
}

void stAddUserToBoard(SapiTrello *sapiTrello) {
    int id;
    char name[200];
    User *user;
    Board *board;
    printf("Enter id of the user to add:\n");
    scanf("%d", &id);
    printf("Enter Board name where to add user:\n");
    scanf("%s", &name);
    for (int i = 0; i < sapiTrello->userListSize; ++i) {
        if (id == sapiTrello->userList[i].id) {
            user = &sapiTrello->userList[i];
        }
    }
    for (int i = 0; i < sapiTrello->boardListSize; ++i) {
        if (strcmp(name, sapiTrello->boardList[i].name) == 0) {
            board = &sapiTrello->boardList[i];
        }
    }
    AddUser(board, user);
}

void stAddUserToCard(SapiTrello *sapiTrello) {
    int id;
    char name[200];
    User *user;
    Card *card;
    printf("Enter id of the user to add:\n");
    scanf("%d", &id);
    printf("Enter Card name where to add user:\n");
    scanf("%s", &name);
    for (int i = 0; i < sapiTrello->userListSize; ++i) {
        if (id == sapiTrello->userList[i].id) {
            user = &sapiTrello->userList[i];
        }
    }
    for (int i = 0; i < sapiTrello->cardListSize; ++i) {
        if (strcmp(name, sapiTrello->cardList[i].title) == 0) {
            card = &sapiTrello->cardList[i];
        }
    }
    AddUserToCard(card, user);
}

void stAddCardToBoard(SapiTrello *sapiTrello) {

    char boardName[200];
    char cardName[200];
    Board *board;
    Card *card;
    printf("Enter name of the card to add:\n");
    scanf("%s", &cardName);
    printf("Enter Board name where to add card:\n");
    scanf("%s", &boardName);
    for (int i = 0; i < sapiTrello->cardListSize; ++i) {
        if (strcmp(cardName, sapiTrello->cardList[i].title) == 0) {
            card = &sapiTrello->cardList[i];
        }
    }
    for (int i = 0; i < sapiTrello->boardListSize; ++i) {
        if (strcmp(boardName, sapiTrello->boardList[i].name) == 0) {
            board = &sapiTrello->boardList[i];
        }
    }
    AddCard(board, card);
}

void stPrintUsersOnBoard(SapiTrello *sapiTrello) {
    Board *board;
    char boardName[200];
    printf("Enter name of the Board to print:\n");
    scanf("%s", &boardName);

    for (int i = 0; i < sapiTrello->boardListSize; ++i) {
        if (strcmp(boardName, sapiTrello->boardList[i].name) == 0) {
            board = &sapiTrello->boardList[i];
        }
    }
    PrintUsersBoard(board);
}

void stPrintCardsOnBoard(SapiTrello *sapiTrello) {
    Board *board;
    char boardName[200];
    printf("Enter name of the Board to print the cards:\n");
    scanf("%s", &boardName);

    for (int i = 0; i < sapiTrello->boardListSize; ++i) {
        if (strcmp(boardName, sapiTrello->boardList[i].name) == 0) {
            board = &sapiTrello->boardList[i];
        }
    }
    printAllCardsInBoard(board);
}

void stCardsByStatusOnBoard(SapiTrello *sapiTrello) {
    Board *board;
    char boardName[200];
    printf("Enter name of the Board to print the cards:\n");
    scanf("%s", &boardName);

    for (int i = 0; i < sapiTrello->boardListSize; ++i) {
        if (strcmp(boardName, sapiTrello->boardList[i].name) == 0) {
            board = &sapiTrello->boardList[i];
        }
    }
    getAnyStatusCard(board);
}

void stSetCardStatusOnBoard(SapiTrello *sapiTrello) {
    Board *board;
    char boardName[200];
    printf("Enter name of the Board to print the cards:\n");
    scanf("%s", &boardName);

    for (int i = 0; i < sapiTrello->boardListSize; ++i) {
        if (strcmp(boardName, sapiTrello->boardList[i].name) == 0) {
            board = &sapiTrello->boardList[i];
        }
    }
    setCardStatusByCardTitle(board);
}

void stGetUserHistoryOfCardByTitle(SapiTrello *sapiTrello) {
    Board *board;
    char boardName[200];
    printf("Enter name of the Board to print the card's History :\n");
    scanf("%s", &boardName);

    for (int i = 0; i < sapiTrello->boardListSize; ++i) {
        if (strcmp(boardName, sapiTrello->boardList[i].name) == 0) {
            board = &sapiTrello->boardList[i];
        }
    }
    getUserHistoryOfCardByTitle(board);
}

void stDeleteCard(SapiTrello *sapiTrello) {
    Card *card, *temp;
    char cardName[200];
    int index = -1;
    printf("Enter Title of the Card to delete :\n");
    scanf("%s", &cardName);

    for (int i = 0; i < sapiTrello->cardListSize; ++i) {
        if (strcmp(cardName, sapiTrello->cardList[i].title) == 0) {
            card = &sapiTrello->cardList[i];
            //free(card);
            for (int j = i; j < sapiTrello->cardListSize; ++j) {
                sapiTrello->cardList[j] = sapiTrello->cardList[j + 1];

                //free(card);
            }
            sapiTrello->cardListSize--;
        }
    }
}

void PrintMenu() {
    SapiTrello *st;
    st = CreateSapiTrello();

    printf("You've got many choices young one, enter the number\n");
    printf("1......Create Board\n");
    printf("2......Create User\n");
    printf("3......Create Card\n");
    printf("4......Get Boards\n");
    printf("5......Get Users\n");
    printf("6......Get Cards\n");
    printf("7......Add User To Board\n");
    printf("8......Add User To Card\n");
    printf("9......Add Card To Board\n");
    printf("10.....Print Users on Board\n");
    printf("11.....Print All Cards on Board\n");
    printf("12.....Search card by Status on Board\n");
    printf("13.....Set Card Status on Board\n");
    printf("14.....Delete Card\n");

    while (1) {

        int choice;
        printf("Choose:");
        scanf("%i", &choice);
        switch (choice) {
            case 1:
                stCreateBoard(st);
                break;
            case 2:
                stCreateUser(st);
                break;
            case 3:
                stCreateCard(st);
                break;
            case 4:
                getBoards(st);
                break;
            case 5:
                getUsers(st);
                break;
            case 6:
                getCards(st);
                break;
            case 7:
                stAddUserToBoard(st);
                PrintUsersBoard(&st->boardList[0]);
                break;
            case 8:
                stAddUserToCard(st);
                PrintCard(&st->cardList[0]);
                break;
            case 9:
                stAddCardToBoard(st);
                printAllCardsInBoard(&st->boardList[0]);
                break;
            case 10:
                stPrintUsersOnBoard(st);

                break;
            case 11:
                stPrintCardsOnBoard(st);

                break;
            case 12:
                stCardsByStatusOnBoard(st);

                break;
            case 13:
                stSetCardStatusOnBoard(st);

                break;
            case 14:
                stDeleteCard(st);

                break;
        }
    }
//    printf("13.....Get User History Of Card By Title\n");
//    printf("14.....Get Status Of Card By Title\n");
//    printf("15.....Get any status of card\n");
//    printf("16.....Set Card Status By Card Title\n");


}
