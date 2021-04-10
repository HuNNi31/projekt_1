#include <stdio.h>
#include "sapitrello.h"
int main() {
    Board *board1;
    board1 = CreateBoard();
    User *user1,*user2;
    user1 = CreateUser();
    user2 = CreateUser();
    //AddBoard(st, board1);
    AddUser(board1,user1);
    AddUser(board1,user2);
    PrintBoard(board1);

    return 0;
}
