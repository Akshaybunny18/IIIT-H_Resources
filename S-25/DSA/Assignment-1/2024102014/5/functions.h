#include <stdio.h>
#include <stdlib.h>
typedef struct PtrNode{
    int Element;
    int Column;
    int Row;
    struct PtrNode* NextNode; 
} PtrNode;
typedef struct Row{
    PtrNode *Col;
    int rowNum;
    struct Row* next;
    PtrNode *end;
} Row;
struct hi{
    int row;
    int col;
    int val;
};
void append(Row *rowend, int element, int column, int row);
void appendRow(Row** headend, PtrNode* head, int row);
void append1(int element, int column, int row);
void printRow(Row* head);
void printAll(Row* head);
void add(Row* head1, Row* head2, int row, int col);
void mul(Row* head1, Row* head2, int row, int colrow, int col);
void tra(Row* head, int row, int col);
void freenode(PtrNode* head);
void freeRow(Row* head);