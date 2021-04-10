
#include <stdio.h>
#include "sapitrello.h"

int main() {
    SapiTrello *st;
    st = CreateSapiTrello();
    while (1) {
        PrintMenu();
        int choice;
        printf("Choose: ");
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
                PrintBoard(&st->boardList[0]);
                break;
        }
    }
    /*Board *board1;
    board1 = CreateBoard();
    User *user1, *user2;
    user1 = CreateUser();
    user2 = CreateUser();
    Card *card1, *card2, *card3;
    card1 = CreateCard();
//    card2 = CreateCard();
//    card3 = CreateCard();
    AddUser(board1, user1);
    AddUser(board1, user2);
    PrintBoard(board1);

    AddUserToCard(card1, user1);
    AddUserToCard(card1, user2);
    AddCard(board1, card1);
//    AddCard(board1, card2);
//    AddCard(board1, card3);
    PrintCard(card1);
    printAllCardsInBoard(board1);

    //get any status card
    //getAnyStatusCard(board1);

    //get any card status by title
    getStatusOfCardByTitle(board1);
    //change status of card
    setCardStatusByCardTitle(board1);
    setCardStatusByCardTitle(board1);
    setCardStatusByCardTitle(board1);

    //et user history for Card by title
    //getUserHistoryOfCardByTitle(board1);*/
    return 0;
}

