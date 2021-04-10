#include <stdio.h>
#include "sapitrello.h"
int main() {
    Board *board1;
    board1 = CreateBoard();
    User *user1,*user2;
    user1 = CreateUser();
    user2 = CreateUser();
    Card *card1,*card2, *card3;
    card1 = CreateCard();
    card2 = CreateCard();
    card3 = CreateCard();
    //AddBoard(st, board1);
    AddUser(board1,user1);
    AddUser(board1,user2);
    PrintBoard(board1);
    AddCard(board1,card1);
    AddCard(board1,card2);
    AddCard(board1,card3);
    AddUserToCard(card1,user2);
    PrintCard(card1);
    printAllCardsinBoard(board1);
    return 0;
}
