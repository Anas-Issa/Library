#ifndef BORROW_H_INCLUDED
#define BORROW_H_INCLUDED

typedef struct
{
    int book_code;
    char user_code[20];
    Date date_issued ;
    Date date_to_return;
    Date date_returned;

} borrow;

borrow borrow_list[100];

void Borrow_Book();
void Return_Book();
void OverDue();


#endif // BORROW_H_INCLUDED
