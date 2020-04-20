#ifndef BOOKS_H_INCLUDED
#define BOOKS_H_INCLUDED

typedef struct
{
    int day;
    int month;
    int year;
} Date;

typedef struct book
{
    char title[50];
    char author[50];
    char publisher[50];
    int ISBN ;
    char DateOfPublishing[15];
    int NumberOFCopies ;
    int CurrentAvalibleBook;
    char category[12];
} books;

books book [100];
books search_list[100];



void most_popular_books( books P[] );
void Insert_New_Book();
void FindBookByTitle();
void FindBookByISBN();
void FindBookByAuthorName();
void FindBookByCategory();
void Delete_book();
void Print_Book_List();
void AddCopy ();


#endif // BOOKS_H_INCLUDED
