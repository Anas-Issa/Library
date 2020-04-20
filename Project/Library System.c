#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "Books.h"
#include "Member.h"
#include "Borrow.h"

char c,e;
int i,j,k,l;  // counters
int  n, n_member,n_borrow;

FILE *pbook,*pmember,*pborrow;
int * ptr ;
books * popular ;

int save=1 ;

void open_file();

int main()
{
    open_file();
    popular = ( books * ) malloc( n * sizeof(books) );

    while (1)
    {

        popular = ( books * ) realloc ( popular, n * sizeof(books) );
        most_popular_books(popular);

        printf("\t\t\t Welcome To The Library System \n");
        printf("\t\t\t ----------------------------- \n");
        printf("\n Most Popular books : \n\n");

        for (i=0; i<l; i++)
            printf(" --> %s\t\t\t\t%06d\n",popular[i].title,popular[i].ISBN);

        printf("\n\n\n 1- Book Management \n");
        printf("\n 2- Member Management \n");
        printf("\n 3- Borrow Management \n");
        printf("\n 4- Save the changes \n");
        printf("\n 5- Exit \n\n");


        c=getchar();
        while ( c!='1' && c!='2' && c!='3' && c!='4' && c!='5' )
        {
            printf(" please enter a valid choice (1,2,3,4 or 5)\n");
            getchar();
            c=getchar();
        }
        getchar();

        system("cls");

        switch (c)
        {
        case '1':
        {
            printf("\t\t\t Welcome To The Library System \n");
            printf("\t\t\t ----------------------------- \n");

            printf("\n 1- Insert a new book \n");
            printf("\n 2- Search a book \n");
            printf("\n 3- Delete a book \n");
            printf("\n 4- Add a copy \n");
            printf("\n 5- Print The Books List \n\n");
            printf("\n 6- Back to main menu \n\n");


            c=getchar();
            while ( c!='1' && c!='2' && c!='3' && c!='4' && c!='5' && c!='6' )
            {
                printf(" please enter a valid choice (1,2,3,4,5 or 6)\n");
                getchar();
                c=getchar();
            }
            getchar();

            switch (c)
            {
            case '1':
            {
                save=0;
                system("cls");
                printf("\t\t\t Welcome To The Library System \n");
                printf("\t\t\t ----------------------------- \n");

                Insert_New_Book();
                break;
            }
            case '2':
            {
                system("cls");
                printf("\t\t\t Welcome To The Library System \n");
                printf("\t\t\t ----------------------------- \n");

                printf("\n Search by : ");
                printf("\n --------- \n");
                printf("\n 1- Title \n");
                printf("\n 2- ISBN \n");
                printf("\n 3- Author name \n");
                printf("\n 4- Category \n\n");

                c=getchar();
                while ( c!='1' && c!='2' && c!='3' && c!='4' )
                {
                    printf(" please enter a valid choice (1,2,3 or 4)\n");
                    getchar();
                    c=getchar();
                }
                getchar();

                switch (c)
                {
                case '1':
                {
                    FindBookByTitle();
                    break;
                }
                case '2':
                {
                    FindBookByISBN();
                    break;
                }
                case '3':
                {
                    FindBookByAuthorName();
                    break;
                }
                case '4':
                {
                    FindBookByCategory();
                    break;
                }
                }
                break;
            }
            case '3':
            {
                save=0;
                system("cls");
                printf("\t\t\t Welcome To The Library System \n");
                printf("\t\t\t ----------------------------- \n");

                Delete_book();

                break;
            }
            case '4':
            {
                save=0;
                system("cls");
                printf("\t\t\t Welcome To The Library System \n");
                printf("\t\t\t ----------------------------- \n");

                AddCopy ();
                break;
            }
            case '5':
            {
                system("cls");
                printf("\t\t\t Welcome To The Library System \n");
                printf("\t\t\t ----------------------------- \n");

                Print_Book_List ();
                break;
            }
            case '6':
            {
                system("cls");
                break;
            }

            }

            break;
        }
        case '2':
        {
            printf("\t\t\t Welcome To The Library System \n");
            printf("\t\t\t ----------------------------- \n");

            printf("\n 1- Registration \n");
            printf("\n 2- Search Members \n");
            printf("\n 3- Remove Member \n");
            printf("\n 4- Print members list \n\n");
            printf("\n 5- Back to main menu \n\n");


            c=getchar();
            while ( c!='1' && c!='2' && c!='3' && c!='4' && c!='5')
            {
                printf(" please enter a valid choice (1,2,3,4 or 5)\n");
                getchar();
                c=getchar();
            }
            getchar();

            switch (c)
            {
            case '1':
            {
                save=0;
                system("cls");
                printf("\t\t\t Welcome To The Library System \n");
                printf("\t\t\t ----------------------------- \n");
                Registration();
                break;
            }
            case '2':
            {
                system("cls");
                printf("\t\t\t Welcome To The Library System \n");
                printf("\t\t\t ----------------------------- \n");

                printf("\n Search by : ");
                printf("\n --------- \n");
                printf("\n 1- Member Name \n");
                printf("\n 2- ID \n\n");

                c=getchar();
                while ( c!='1' && c!='2')
                {
                    printf(" please enter a valid choice (1 or 2)\n");
                    getchar();
                    c=getchar();
                }
                getchar();

                switch (c)
                {
                case '1':
                {
                    FindMemberByName();
                    break;
                }
                case '2':
                {
                    FindMemberByID();
                    break;
                }

                }
                break;
            }
            case '3':
            {
                save=0;
                Remove_member();
                system("cls");
                break;
            }

            case '4':
            {
                system("cls");
                printf("\t\t\t Welcome To The Library System \n");
                printf("\t\t\t ----------------------------- \n");
                Print_Member_List();
                break;
            }
            case '5':
            {
                system("cls");
                break;
            }

            }

            break;
        }
        case '3':
        {
            save=0;
            printf("\t\t\t Welcome To The Library System \n");
            printf("\t\t\t ----------------------------- \n");

            printf("\n 1- Borrow a book \n");
            printf("\n 2- Return a book \n");
            printf("\n 3- overdue books \n\n");
            printf("\n 4- Back to main menu \n\n");


            c=getchar();
            while ( c!='1' && c!='2' && c!='3' && c!='4')
            {
                printf(" please enter a valid choice (1,2,3 or 4)\n");
                getchar();
                c=getchar();
            }
            getchar();

            switch (c)
            {
            case '1':
            {
                Borrow_Book();
                break;
            }
            case '2':
            {
                Return_Book();
                break;
            }
            case '3':
            {
                OverDue();
                break;
            }
            case '4':
            {
                system("cls");
                break;
            }
            }
            break;
        }
        case '4':
        {

            pbook=fopen("Books.xls","w");
            for (i=0; i<n; i++)
            {
                fprintf(pbook,"%d\t%s\t%s\t%s\t%s\t%d\t%d\t%s\n",book[i].ISBN,book[i].title,book[i].author,book[i].publisher,book[i].DateOfPublishing,book[i].NumberOFCopies,book[i].CurrentAvalibleBook,book[i].category);
            }
            save=1;
            fclose(pbook);

            pmember=fopen("Members.xls","w");
            for (i=0; i<n_member; i++)
            {
                fprintf(pmember,"%s\t%s\t%s\t%s\t%s\t%s\t%s\n",user[i].firstname,user[i].lastname,user[i].id,user[i].phonenumber,user[i].address,user[i].age,user[i].emailadress);
            }
            fclose(pmember);

            pborrow=fopen("Borrow.xls","w");
            for (i=0; i<n_borrow; i++)
            {
                fprintf(pborrow,"%d\t%s\t%d/%d/%d\t%d/%d/%d\t%d/%d/%d\n",borrow_list[i].book_code,borrow_list[i].user_code,borrow_list[i].date_issued.day,borrow_list[i].date_issued.month,borrow_list[i].date_issued.year,borrow_list[i].date_to_return.day,borrow_list[i].date_to_return.month,borrow_list[i].date_to_return.year,borrow_list[i].date_returned.day,borrow_list[i].date_returned.month,borrow_list[i].date_returned.year);
            }
            fclose(pborrow);

            system("cls");
            printf("\t\t\tData Saved Successfully !\n");
            getchar();
            system("cls");
            break;
        }
        case '5':
        {
            if (save==0)
            {
                printf("\t\t\t Welcome To The Library System \n");
                printf("\t\t\t ----------------------------- \n");

                printf("\n 1- Save & Exit \n");
                printf("\n 2- Exit without saving \n\n");
                printf("\n 3- Back to main menu \n\n");


                c=getchar();
                while ( c!='1' && c!='2' && c!='3' )
                {
                    printf(" please enter a valid choice (1,2 or 3)\n");
                    getchar();
                    c=getchar();
                }
                getchar();

                switch (c)
                {
                case '1':
                {
                    pbook=fopen("Books.xls","w");
                    for (i=0; i<n; i++)
                    {
                        fprintf(pbook,"%d\t%s\t%s\t%s\t%s\t%d\t%d\t%s\n",book[i].ISBN,book[i].title,book[i].author,book[i].publisher,book[i].DateOfPublishing,book[i].NumberOFCopies,book[i].CurrentAvalibleBook,book[i].category);
                    }
                    fclose(pbook);

                    pmember=fopen("Members.xls","w");
                    for (i=0; i<n_member; i++)
                    {
                        fprintf(pmember,"%s\t%s\t%s\t%s\t%s\t%s\t%s\n",user[i].firstname,user[i].lastname,user[i].id,user[i].phonenumber,user[i].address,user[i].age,user[i].emailadress);
                    }
                    fclose(pmember);

                    pborrow=fopen("Borrow.xls","w");
                    for (i=0; i<n_borrow; i++)
                    {
                        fprintf(pborrow,"%d\t%s\t%d/%d/%d\t%d/%d/%d\t%d/%d/%d\n",borrow_list[i].book_code,borrow_list[i].user_code,borrow_list[i].date_issued.day,borrow_list[i].date_issued.month,borrow_list[i].date_issued.year,borrow_list[i].date_to_return.day,borrow_list[i].date_to_return.month,borrow_list[i].date_to_return.year,borrow_list[i].date_returned.day,borrow_list[i].date_returned.month,borrow_list[i].date_returned.year);
                    }
                    save=1;
                    fclose(pborrow);
                    free(popular);

                    system("cls");
                    printf("\t\t\t Saved Successfully ! \n\n\n\t\t\t\t THANK YOU\n\t\t\t\t ---------\n\n\n\n");
                    exit(0);
                    break;
                }
                case '2':
                {
                    printf("\n\n\n \t\t\tAre You Sure ? \n\t\t\t  1-yes\t\t2-no\n\n");
                    e=getchar();
                    while ( e!='1' && e!='2' )
                    {
                        printf(" please enter a valid choice (1or2)\n");
                        getchar();
                        e=getchar();
                    }
                    getchar();

                    switch (e)
                    {
                    case '1':
                    {
                        system("cls");
                        printf("\n\t\t\t\t THANK YOU\n\t\t\t\t ---------\n\n\n\n");
                        free(popular);

                        exit(0);
                    }
                    case '2':
                    {
                        system("cls");
                        break;
                    }
                    }

                }
                case '3':
                {
                    system("cls");
                    break;
                }
                if (c=='1')
                    break;
                else
                    continue;

                }

            }
            if (save==1)
            {
                system("cls");
                printf("\n\t\t\t\t THANK YOU\n\t\t\t\t ---------\n\n\n\n");
                free(popular);

                exit(0);

            }

        }

        }
    }
    return 0;

}
void open_file()
{
    i=0;
    n=0;
    pbook=fopen("Books.xls","r");
    if (pbook == NULL )
    {
        system("cls");
        printf("\n\n\t\t Books Data is not found !!");
        printf("\n\n\t Do you still want to continue and create a new Data ?");
        printf("\n\n\t\t\t  1-yes\t\t2-no\n\n");
        c=getchar();
        while ( c!='1' && c!='2' )
        {
            printf(" please enter a valid choice (1or2)\n");
            getchar();
            c=getchar();
        }
        getchar();

        switch (c)
        {
        case '1':
        {
            system("cls");
            break;
        }
        case '2':
        {
            system("cls");
            printf("\n\t\t\t\t THANK YOU\n\t\t\t\t ---------\n\n\n\n");
            free(popular);
            exit(0);
        }
        }


    }
    else
    {
        while (!feof(pbook))
        {
            fscanf(pbook,"%d\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%d\t%d\t%s\n",&book[i].ISBN,book[i].title,book[i].author,book[i].publisher,book[i].DateOfPublishing,&book[i].NumberOFCopies,&book[i].CurrentAvalibleBook,book[i].category);
            i++;
        }
        n=i;

        fclose(pbook);

    }

    i=0;
    n_member=0;
    pmember=fopen("Members.xls","r");
    if (pmember==NULL)
    {
        system("cls");
        printf("\n\n\t\t Members Data is not found !!");
        printf("\n\n\t Do you still want to continue and create a new Data ?");
        printf("\n\n\t\t\t  1-yes\t\t2-no\n\n");
        c=getchar();
        while ( c!='1' && c!='2' )
        {
            printf(" please enter a valid choice (1or2)\n");
            getchar();
            c=getchar();
        }
        getchar();

        switch (c)
        {
        case '1':
        {
            system("cls");
            break;
        }
        case '2':
        {
            system("cls");
            printf("\n\t\t\t\t THANK YOU\n\t\t\t\t ---------\n\n\n\n");
            free(popular);

            exit(0);
        }
        }


    }
    else
    {
        while (!feof(pmember))
        {
            fscanf(pmember,"%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%s\n",user[i].firstname,user[i].lastname,user[i].id,user[i].phonenumber,user[i].address,user[i].age,user[i].emailadress);
            i++;
        }
        n_member=i;
        fclose(pmember);
    }

    i=0;
    n_borrow=0;
    pborrow=fopen("Borrow.xls","r");
    if (pborrow==NULL)
    {
        system("cls");
        printf("\n\n\t\t Borrow Data is not found !!");
        printf("\n\n\t Do you still want to continue and create a new Data ?");
        printf("\n\n\t\t\t  1-yes\t\t2-no\n\n");
        c=getchar();
        while ( c!='1' && c!='2' )
        {
            printf(" please enter a valid choice (1or2)\n");
            getchar();
            c=getchar();
        }
        getchar();

        switch (c)
        {
        case '1':
        {
            system("cls");
            break;
        }
        case '2':
        {
            system("cls");
            printf("\n\t\t\t\t THANK YOU\n\t\t\t\t ---------\n\n\n\n");
            free(popular);

            exit(0);
        }
        }


    }
    else
    {
        while (!feof(pborrow))
        {
            fscanf(pborrow,"%d\t%[^\t]\t%d/%d/%d\t%d/%d/%d\t%d/%d/%d\n",&borrow_list[i].book_code,borrow_list[i].user_code,&borrow_list[i].date_issued.day,&borrow_list[i].date_issued.month,&borrow_list[i].date_issued.year,&borrow_list[i].date_to_return.day,&borrow_list[i].date_to_return.month,&borrow_list[i].date_to_return.year,&borrow_list[i].date_returned.day,&borrow_list[i].date_returned.month,&borrow_list[i].date_returned.year);
            i++;
        }
        n_borrow=i;
        fclose(pborrow);
    }
}

void most_popular_books(books P [] )
{

    ptr = (int *) malloc( n* sizeof(int) );

    k=-1;
    l=0;
    for (i=0; i<n; i++)
    {
        ptr[i] = book[i].NumberOFCopies-book[i].CurrentAvalibleBook;
        if (ptr[i]>k)
            k=ptr[i];
    }


    while (l<5 && k>=0)
    {
        for (i=0; i<n; i++)
            if (ptr[i]==k)
            {
                P[l]=book[i];
                l++;
            }
        k--;
    }

    free(ptr);
}


void Insert_New_Book()
{
    while(1)

    {

        puts("\nBook Title : ");
        gets(book[n].title);

        puts("\nAuthor : ");
        gets(book[n].author);

        puts("\nPublisher : ");
        gets(book[n].publisher);

        puts("\nDate of publishing : ");
        gets(book[n].DateOfPublishing);

        puts("\nNumber of copies : ");
        scanf("%d",&book[n].NumberOFCopies);

        book[n].CurrentAvalibleBook=book[n].NumberOFCopies;

        if (n==0)
            book[n].ISBN=1;
        else
            book[n].ISBN=(book[n-1].ISBN)+1 ;



        system("cls");
        getchar();


        printf("\t\t\t Welcome To The Library System \n");
        printf("\t\t\t ----------------------------- \n");


        printf(" Book details:\n\n %s\tby: %s\t%s\n\nDate of publication: %s\t No.of copies: %d ",book[n].title,book[n].author,book[n].publisher,book[n].DateOfPublishing,book[n].NumberOFCopies);

        printf("\n\n\n \t\t\tIS this information correct ? \n\t\t\t  1-yes\t\t2-no\n\n");
        c=getchar();
        while ( c!='1' && c!='2' )
        {
            printf(" please enter a valid choice (1or2)\n");
            getchar();
            c=getchar();
        }
        getchar();

        switch (c)
        {
        case '1':
        {
            system("cls");
            printf("\t\t\t Welcome To The Library System \n");
            printf("\t\t\t ----------------------------- \n");

            printf("\t\t\t Please choose the book category \n");
            printf("\n 1- political \n");
            printf("\n 2- Scientific \n");
            printf("\n 3- Novels \n");
            printf("\n 4- Historical \n");
            printf("\n 5- Literature \n");
            printf("\n 6- FUN \n\n");

            e=getchar();
            while ( e!='1' && e!='2' && e!='3' && e!='4' && e!='5' && e!='6' )
            {
                printf(" please enter a valid choice (between 1-6)\n");
                getchar();
                e=getchar();
            }
            getchar();

            switch (e)
            {
            case '1':
            {
                strcpy(book[n].category,"political");
                break;
            }
            case '2':
            {
                strcpy(book[n].category,"Scientific");
                break;
            }
            case '3':
            {
                strcpy(book[n].category,"Novels");
                break;
            }
            case '4':
            {
                strcpy(book[n].category,"Historical");
                break;
            }
            case '5':
            {
                strcpy(book[n].category,"Literature");
                break;
            }
            case '6':
            {
                strcpy(book[n].category,"FUN");
                break ;
            }
            }

            system("cls");
            printf("\t\t\tBook saved successfully ! ");
            printf("\n\n\t\t\tYour Book ISBN is : %06d ",book[n].ISBN);
            n++;
            getchar();
            system("cls");
            break;
        }
        case '2':
        {
            system("cls");
            printf("\t\t\tPlease reinsert your book information\n\n");
            break;
        }
        }

        if (c=='1')
            break;
        else
            continue;
    }
}

void FindBookByTitle()
{

    char book_name[50];
    while (1)
    {
        l=0;
        system("cls");
        printf("\t\t\t Welcome To The Library System \n");
        printf("\t\t\t ----------------------------- \n");
        printf("\n Enter the title (or part of it) : ");
        gets(book_name);
        if (strlen(book_name)==0 || strlen(book_name)==1)
        {
            system("cls");
            printf("\t\t\t Welcome To The Library System \n");
            printf("\t\t\t ----------------------------- \n");
            printf("\n\t\t Please enter a valid title (a longer title) !\n\n");

            printf("\n 1- Reenter your title \n");
            printf("\n 2- End search \n\n");

            c=getchar();
            while ( c!='1' && c!='2' )
            {
                printf(" please enter a valid choice (1 or 2)\n");
                getchar();
                c=getchar();
            }
            getchar();


            if (c=='2')
            {
                system("cls");
                break;
            }

        }
        else
        {
            for (i=0; i<n; i++)
            {
                k=1;
                for (j=0; j<strlen(book[i].title); j++)
                {
                    if (book_name[0]==book[i].title[j] || (book_name[0]+32)==book[i].title[j] || (book_name[0])==(book[i].title[j]+32))
                        for (k=1; k<strlen(book_name); k++)
                        {
                            if (book_name[k]!=book[i].title[j+k] && (book_name[k]+32)!=book[i].title[j+k] && (book_name[k])!=(book[i].title[j+k]+32))
                                break;
                        }

                    if (k==strlen(book_name))
                        break;
                }
                if (k==strlen(book_name))
                {
                    search_list[l]=book[i];
                    l++;
                }

            }
            if(l==0)
            {
                system("cls");
                printf("\t\t\t Welcome To The Library System \n");
                printf("\t\t\t ----------------------------- \n");
                printf("\n\t\t\t Sorry the book is not found !\n\n");

                printf("\n 1- Reenter your title \n");
                printf("\n 2- End search \n\n");

                c=getchar();
                while ( c!='1' && c!='2' )
                {
                    printf(" please enter a valid choice (1 or 2)\n");
                    getchar();
                    c=getchar();
                }
                getchar();


                if (c=='2')
                {
                    system("cls");
                    break;
                }

            }
            else
            {
                system("cls");
                printf("\t\t\t Welcome To The Library System \n");
                printf("\t\t\t ----------------------------- \n");
                printf("\n Books found:\n -----------\n\n");
                for (i=0; i<l; i++)
                {
                    printf("\n Book %d:\n\n %s\tby: %s\t%s\n\nDate of publication: %s\n\n ISBN: %06d\t Category: %s\n\n No.of copies: %d\t No.of available copies: %d\n\n",(i+1),search_list[i].title,search_list[i].author,search_list[i].publisher,search_list[i].DateOfPublishing,search_list[i].ISBN,search_list[i].category,search_list[i].NumberOFCopies,search_list[i].CurrentAvalibleBook);
                }
                system("pause");
                system("cls");
                break;
            }
        }
    }
}

void FindBookByISBN()
{
    int book_ISBN;
    while (1)
    {
        system("cls");
        printf("\t\t\t Welcome To The Library System \n");
        printf("\t\t\t ----------------------------- \n");
        printf("\n Enter the ISBN : ");
        scanf("%d",&book_ISBN);

        for (i=0; i<n; i++)
        {
            if(book_ISBN==book[i].ISBN)
                break;
        }
        if(i==n)
        {
            system("cls");
            printf("\t\t\t Welcome To The Library System \n");
            printf("\t\t\t ----------------------------- \n");
            printf("\n\t\t\t Sorry the book is not found !\n\n");

            printf("\n 1- Reenter your ISBN \n");
            printf("\n 2- End search \n\n");

            c=getchar();
            while ( c!='1' && c!='2' )
            {
                printf(" please enter a valid choice (1 or 2)\n");
                getchar();
                c=getchar();
            }


            if (c=='2')
            {
                system("cls");
                break;
            }

        }
        else
        {
            system("cls");
            printf("\t\t\t Welcome To The Library System \n");
            printf("\t\t\t ----------------------------- \n");
            printf("\n\t\t\t\t   Book found\n\n");
            printf(" Book details:\n -------------\n\n %s\tby: %s\t%s\n\nDate of publication: %s\n\n ISBN: %06d\t Category: %s\n\n No.of copies: %d\t No.of available copies: %d\n\n\n",book[i].title,book[i].author,book[i].publisher,book[i].DateOfPublishing,book[i].ISBN,book[i].category,book[i].NumberOFCopies,book[i].CurrentAvalibleBook);
            system("pause");
            getchar();
            system("cls");
            break;
        }
    }

}

void FindBookByAuthorName()
{
    char author_name[50];
    while (1)
    {
        l=0;
        system("cls");
        printf("\t\t\t Welcome To The Library System \n");
        printf("\t\t\t ----------------------------- \n");
        printf("\n Enter the Author name : ");
        gets(author_name);

        for (i=0; i<n; i++)
        {
            for (j=0; j<strlen(book[i].author); j++)
                if(author_name[j]!= book[i].author[j] && (author_name[j]+32) != book[i].author[j] && author_name[j]!= (book[i].author[j]+32))
                    break;
            if (j==strlen(book[i].author))
            {
                search_list[l]=book[i] ;
                l++;
            }
        }
        if(l==0)
        {
            system("cls");
            printf("\t\t\t Welcome To The Library System \n");
            printf("\t\t\t ----------------------------- \n");
            printf("\n\t\t\t   No books are found !");
            printf("\n\t\t   (may be the author name is misspelled) \n\n");

            printf("\n 1- Reenter the name \n");
            printf("\n 2- End search \n\n");

            c=getchar();
            while ( c!='1' && c!='2' )
            {
                printf(" please enter a valid choice (1 or 2)\n");
                getchar();
                c=getchar();
            }
            getchar();


            if (c=='2')
            {
                system("cls");
                break;
            }

        }
        else
        {
            system("cls");
            printf("\t\t\t Welcome To The Library System \n");
            printf("\t\t\t ----------------------------- \n");
            printf("\n\t\t\t Books written by : %s\n\n",author_name);
            for (i=0; i<l; i++)
            {
                printf("\n Book %d:\n\n %s\tby: %s\t%s\n\nDate of publication: %s\n\n ISBN: %06d\t Category: %s\n\n No.of copies: %d\t No.of available copies: %d\n\n",(i+1),search_list[i].title,search_list[i].author,search_list[i].publisher,search_list[i].DateOfPublishing,search_list[i].ISBN,search_list[i].category,search_list[i].NumberOFCopies,search_list[i].CurrentAvalibleBook);
            }
            system("pause");
            system("cls");
            break;
        }
    }

}

void Delete_book()
{
    int book_ISBN;
    while (1)
    {
        system("cls");
        printf("\t\t\t Welcome To The Library System \n");
        printf("\t\t\t ----------------------------- \n");
        printf("\n Enter the book ISBN : ");
        scanf("%d",&book_ISBN);

        for (i=0; i<n; i++)
        {
            if(book_ISBN==book[i].ISBN )
                break;
        }
        if(i==n)
        {
            system("cls");
            printf("\t\t\t Welcome To The Library System \n");
            printf("\t\t\t ----------------------------- \n");
            printf("\n\t\t\t Sorry the book is not found !\n\n");

            printf("\n 1- Reenter your ISBN \n");
            printf("\n 2- Back to main menu \n\n");

            getchar();
            c=getchar();
            while ( c!='1' && c!='2' )
            {
                printf(" please enter a valid choice (1 or 2)\n");
                getchar();
                c=getchar();
            }
            getchar();


            if (c=='2')
            {
                system("cls");
                break;
            }

        }
        else
        {
            if (book[i].CurrentAvalibleBook == book[i].NumberOFCopies )
            {
                system("cls");
                printf("\t\t\t Welcome To The Library System \n");
                printf("\t\t\t ----------------------------- \n");
                printf("\n Book details:\n -------------\n\n %s\tby: %s\t%s\n\nDate of publication: %s\n\n ISBN: %06d\t Category: %s\n\n No.of copies: %d\t No.of available copies: %d\n\n\n",book[i].title,book[i].author,book[i].publisher,book[i].DateOfPublishing,book[i].ISBN,book[i].category,book[i].NumberOFCopies,book[i].CurrentAvalibleBook);

                printf("\n\n\n \t\tIS this the book you want to delete ? \n\t\t\t  1-yes\t\t2-no\n\n");

                getchar();

                c=getchar();
                while ( c!='1' && c!='2' )
                {
                    printf(" please enter a valid choice (1or2)\n");
                    getchar();
                    c=getchar();
                }

                switch (c)
                {
                case '1':
                {
                    for (j=i; j<n-1; j++)
                    {
                        book[j]=book[j+1];
                    }
                    n--;

                    system("cls");
                    printf("\t\t\t Book deleted successfully !\n");

                    getchar();
                    system("cls");
                    break;

                }
                case '2':
                {
                    system("cls");
                    printf("\t\t\t Welcome To The Library System \n");
                    printf("\t\t\t ----------------------------- \n");
                    printf("\n 1- Reenter your ISBN \n");
                    printf("\n 2- Back to main menu \n\n");

                    e=getchar();
                    while ( e!='1' && e!='2' )
                    {
                        printf(" please enter a valid choice (1 or 2)\n");
                        getchar();
                        e=getchar();
                    }
                    getchar();
                }
                }


                if (e=='2')
                {
                    system("cls");
                    break;
                }


                if (c=='1')
                {
                    system("cls");
                    break;
                }
            }

            else
            {
                system("cls");
                printf("\t\t\t Welcome To The Library System \n");
                printf("\t\t\t ----------------------------- \n");
                printf("\n\t Sorry The book can't be deleted ( %d copy(ies) are borrowed ) !\n\n", book[i].NumberOFCopies - book[i].CurrentAvalibleBook );

                printf("\n 1- Reenter your ISBN \n");
                printf("\n 2- Back to main menu \n\n");

                getchar();
                c=getchar();
                while ( c!='1' && c!='2' )
                {
                    printf(" please enter a valid choice (1 or 2)\n");
                    getchar();
                    c=getchar();
                }
                getchar();


                if (c=='2')
                {
                    system("cls");
                    break;
                }
            }
        }
    }

}

void AddCopy ()
{
    int book_ISBN;
    while (1)
    {
        system("cls");
        printf("\t\t\t Welcome To The Library System \n");
        printf("\t\t\t ----------------------------- \n");
        printf("\n Enter the book ISBN : ");
        scanf("%d",&book_ISBN);

        for (i=0; i<n; i++)
        {
            if(book_ISBN==book[i].ISBN)
                break;
        }
        if(i==n)
        {
            system("cls");
            printf("\t\t\t Welcome To The Library System \n");
            printf("\t\t\t ----------------------------- \n");
            printf("\n\t\t\t Sorry the book is not found !\n\n");

            printf("\n 1- Reenter your ISBN \n");
            printf("\n 2- Back to main menu \n\n");

            c=getchar();
            while ( c!='1' && c!='2' )
            {
                printf(" please enter a valid choice (1 or 2)\n");
                getchar();
                c=getchar();
            }
            getchar();


            if (c=='2')
            {
                system("cls");
                break;
            }

        }
        else
        {

            system("cls");
            printf("\t\t\t Welcome To The Library System \n");
            printf("\t\t\t ----------------------------- \n");
            printf("\n Book details:\n -------------\n\n %s\tby: %s\t%s\n\nDate of publication: %s\n\n ISBN: %06d\t Category: %s\n\n No.of copies: %d\t No.of available copies: %d\n\n\n",book[i].title,book[i].author,book[i].publisher,book[i].DateOfPublishing,book[i].ISBN,book[i].category,book[i].NumberOFCopies,book[i].CurrentAvalibleBook);

            printf("\n\n\n \t\tIS this the book you want to add copies to ? \n\t\t\t  1-yes\t\t2-no\n\n");

            getchar();
            c=getchar();
            while ( c!='1' && c!='2' )
            {
                printf(" please enter a valid choice (1or2)\n");
                getchar();
                c=getchar();
            }

            switch (c)
            {
            case '1':
            {
                int n_copies;
                system("cls");
                printf("\t\t\t Welcome To The Library System \n");
                printf("\t\t\t ----------------------------- \n");
                printf("\n Enter the number of copies : ");
                scanf("%d",&n_copies);

                book[i].NumberOFCopies += n_copies;
                book[i].CurrentAvalibleBook += n_copies;

                system("cls");
                printf("\t\t\t copies added successfully !\n");

                getchar();
                getchar();
                system("cls");
                break;

            }
            case '2':
            {
                system("cls");
                printf("\t\t\t Welcome To The Library System \n");
                printf("\t\t\t ----------------------------- \n");
                printf("\n 1- Reenter your ISBN \n");
                printf("\n 2- Back to main menu \n\n");

                e=getchar();
                while ( e!='1' && e!='2' )
                {
                    printf(" please enter a valid choice (1 or 2)\n");
                    getchar();
                    e=getchar();
                }
                getchar();
            }
            }


            if (e=='2')
            {
                system("cls");
                break;
            }


            if (c=='1')
            {
                system("cls");
                break;
            }

        }
    }

}

void Print_Book_List()
{
    printf("\n BOOK LIST:\n ---------\n\n");

    for (i=0; i<n; i++)
        printf(" Book %d :\n\n %s\tby: %s\t%s\n\n ISBN: %06d\n\n Date of publication: %s\t Category: %s\n\n No.of copies : %d\t No.of available copies : %d\n\n\n\n ",i+1,book[i].title,book[i].author,book[i].publisher,book[i].ISBN,book[i].DateOfPublishing,book[i].category,book[i].NumberOFCopies,book[i].CurrentAvalibleBook);

    system("pause");
    system("cls");
}

void FindBookByCategory()
{
    l=0;
    char catagory [13];
    system("cls");
    printf("\t\t\t Welcome To The Library System \n");
    printf("\t\t\t ----------------------------- \n");
    printf("\n Choose the category :\n ");
    printf("\n 1- political \n");
    printf("\n 2- Scientific \n");
    printf("\n 3- Novels \n");
    printf("\n 4- Historical \n");
    printf("\n 5- Literature \n");
    printf("\n 6- FUN \n\n");

    e=getchar();
    while ( e!='1' && e!='2' && e!='3' && e!='4' && e!='5' && e!='6' )
    {
        printf(" please enter a valid choice (between 1-6)\n");
        getchar();
        e=getchar();
    }
    getchar();

    switch (e)
    {
    case '1':
    {
        strcpy(catagory,"political");
        for (i=0; i<n; i++)
        {
            if (strcmp(book[i].category,"political")==0)
            {
                search_list[l]=book[i] ;
                l++;
            }
        }
        break;
    }
    case '2':
    {
        strcpy(catagory,"Scientific");
        for (i=0; i<n; i++)
        {
            if (strcmp(book[i].category,"Scientific")==0)
            {
                search_list[l]=book[i] ;
                l++;
            }
        }
        break;
    }
    case '3':
    {
        strcpy(catagory,"Novels");
        for (i=0; i<n; i++)
        {
            if (strcmp(book[i].category,"Novels")==0)
            {
                search_list[l]=book[i] ;
                l++;
            }
        }
        break;
    }
    case '4':
    {
        strcpy(catagory,"Historical");
        for (i=0; i<n; i++)
        {
            if (strcmp(book[i].category,"Historical")==0)
            {
                search_list[l]=book[i] ;
                l++;
            }
        }
        break;
    }
    case '5':
    {
        strcpy(catagory,"Literature");
        for (i=0; i<n; i++)
        {
            if (strcmp(book[i].category,"Literature")==0)
            {
                search_list[l]=book[i] ;
                l++;
            }
        }
        break;
    }
    case '6':
    {
        strcpy(catagory,"FUN");
        for (i=0; i<n; i++)
        {
            if (strcmp(book[i].category,"FUN")==0)
            {
                search_list[l]=book[i] ;
                l++;
            }
        }
        break;
    }
    }

    if(l==0)
    {
        system("cls");
        printf("\t\t\t Welcome To The Library System \n");
        printf("\t\t\t ----------------------------- \n");
        printf("\n\t\t     There is No books in this category !\n\n\n");
        system("pause");
        system("cls");
    }
    else
    {
        system("cls");
        printf("\t\t\t Welcome To The Library System \n");
        printf("\t\t\t ----------------------------- \n");
        printf("\n\t\t\t%s Books \n\n",catagory);
        for (i=0; i<l; i++)
        {
            printf("\n Book %d:\n\n %s\tby: %s\t%s\n\nDate of publication: %s\n\n ISBN: %06d\t Category: %s\n\n No.of copies: %d\t No.of available copies: %d\n\n",(i+1),search_list[i].title,search_list[i].author,search_list[i].publisher,search_list[i].DateOfPublishing,search_list[i].ISBN,search_list[i].category,search_list[i].NumberOFCopies,search_list[i].CurrentAvalibleBook);
        }
        printf("\n\n\n");
        system("pause");
        system("cls");
    }
}

void Registration()
{
    while(1)
    {

        puts("\n\nfirst name: ");
        gets(user[n_member].firstname);

        puts("\n\nlast name: ");
        gets(user[n_member].lastname);

        puts("\n\nid: ");

        while (1)
        {
            gets(user[n_member].id);

            for (j=0; j<(strlen(user[n_member].id)); j++)
                if ( user[n_member].id [j] < 48 || user[n_member].id [j] > 57 )
                    break;
            if (j<(strlen(user[n_member].id) ) )
                printf("please reenter a valid id (numbers only) :");
            else
                break;
        }

        puts("\n\naddress : ");
        gets(user[n_member].address);

        puts("\nphone number : (01xxx xxx xxx) ");

        while (1)
        {
            gets(user[n_member].phonenumber);

            for (j=0; j<(strlen(user[n_member].phonenumber)); j++)
                if ( user[n_member].phonenumber [j] < 48 || user[n_member].phonenumber [j] > 57 )
                    break;
            if (j<(strlen(user[n_member].phonenumber)) || strlen(user[n_member].phonenumber) != 11   || user[n_member].phonenumber[0]!='0' || user[n_member].phonenumber[1]!='1' )
                printf("please reenter a valid id (11 positive numbers only ) :");

            else
                break;
        }


        puts("\n\nage : ");

        while (1)
        {
            gets(user[n_member].age);

            for (j=0; j<(strlen(user[n_member].age)); j++)
                if ( user[n_member].age [j] < 48 || user[n_member].age [j] > 57 )
                    break;
            if (j<(strlen(user[n_member].age)) || strlen(user[n_member].age) > 2 )
                printf("please reenter a valid id (numbers only (between 0-100)) :");
            else
                break;
        }


        puts("\n\nemail address : ");
        gets(user[n_member].emailadress);

        system("cls");
        printf("\t\t\t Welcome To The Library System \n");
        printf("\t\t\t ----------------------------- \n");

        printf(" user details:\n\n name: %s\t%s\n\nid: %s\n\naddress: %s\n\nphone number: %s\tage: %s\n\nemail address: %s\n ",user[n_member].firstname,user[n_member].lastname,user[n_member].id,user[n_member].address,user[n_member].phonenumber,user[n_member].age,user[n_member].emailadress);

        printf("\n\n\n \t\t\tIS this information correct ? \n\t\t\t  1-yes\t\t2-no\n\n");

        c=getchar();
        while ( c!='1' && c!='2' )
        {
            printf(" please enter a valid choice (1or2)\n");
            getchar();
            c=getchar();
        }
        getchar();

        switch (c)
        {
        case '1':
        {
            n_member ++;
            system("cls");
            printf("\t\t\tMember added successfully ! ");
            getchar();
            system("cls");
            break;
        }
        case '2':
        {
            system("cls");
            printf("\t\t\tPlease reinsert your member information\n\n");
            break;
        }
        }

        if (c=='1')
            break;
        else
            continue;
    }
}

void FindMemberByName()
{

    char entered_member_name[50];
    char member_name [50];
    while (1)
    {
        l=0;
        system("cls");
        printf("\t\t\t Welcome To The Library System \n");
        printf("\t\t\t ----------------------------- \n");
        printf("\n Enter the Name (or part of it) : ");
        gets(entered_member_name);
        if (strlen(entered_member_name)==0 || strlen(entered_member_name)==1)
        {
            system("cls");
            printf("\t\t\t Welcome To The Library System \n");
            printf("\t\t\t ----------------------------- \n");
            printf("\n\t\t Please enter a valid Name (more than one letter) !\n\n");

            printf("\n 1- Reenter the Name \n");
            printf("\n 2- End search \n\n");

            c=getchar();
            while ( c!='1' && c!='2' )
            {
                printf(" please enter a valid choice (1 or 2)\n");
                getchar();
                c=getchar();
            }
            getchar();


            if (c=='2')
            {
                system("cls");
                break;
            }

        }
        else
        {
            for (i=0; i<n_member; i++)
            {
                k=1;
                strcpy(member_name,user[i].firstname);
                strcat(member_name," ");
                strcat(member_name,user[i].lastname);
                for (j=0; j<strlen(member_name); j++)
                {
                    if (entered_member_name[0]==member_name[j] || (entered_member_name[0]+32)==member_name[j] || (entered_member_name[0])==(member_name[j]+32))
                        for (k=1; k<strlen(entered_member_name); k++)
                        {
                            if (entered_member_name[k]!=member_name[j+k] && (entered_member_name[k]+32)!=member_name[j+k] && (entered_member_name[k])!=(member_name[j+k]+32))
                                break;
                        }

                    if (k==strlen(entered_member_name))
                        break;
                }
                if (k==strlen(entered_member_name))
                {
                    M_search_list[l]=user[i];
                    l++;
                }

            }
            if(l==0)
            {
                system("cls");
                printf("\t\t\t Welcome To The Library System \n");
                printf("\t\t\t ----------------------------- \n");
                printf("\n\t\t\t Sorry the user is not found !\n\n");

                printf("\n 1- Reenter the Name \n");
                printf("\n 2- End search \n\n");

                c=getchar();
                while ( c!='1' && c!='2' )
                {
                    printf(" please enter a valid choice (1 or 2)\n");
                    getchar();
                    c=getchar();
                }
                getchar();


                if (c=='2')
                {
                    system("cls");
                    break;
                }

            }
            else
            {
                system("cls");
                printf("\t\t\t Welcome To The Library System \n");
                printf("\t\t\t ----------------------------- \n");
                printf("\n Members found:\n -----------\n\n");
                for (i=0; i<l; i++)
                {
                    printf("\n Member %d:\n ---------\n\n name: %s\t%s\n\nid: %s\n\naddress: %s\n\nphone number: %s\tage: %s\n\nemail address: %s\n ",(i+1),M_search_list[i].firstname,M_search_list[i].lastname,M_search_list[i].id,M_search_list[i].address,M_search_list[i].phonenumber,M_search_list[i].age,M_search_list[i].emailadress);
                }
                system("pause");
                system("cls");
                break;
            }
        }
    }
}

void FindMemberByID()
{
    char member_ID [50];
    while (1)
    {
        system("cls");
        printf("\t\t\t Welcome To The Library System \n");
        printf("\t\t\t ----------------------------- \n");
        printf("\n Enter the ID : ");
        gets(member_ID);

        for (i=0; i<n_member; i++)
        {
            if(strcmp(member_ID,user[i].id)==0)
                break;
        }
        if(i==n_member)
        {
            system("cls");
            printf("\t\t\t Welcome To The Library System \n");
            printf("\t\t\t ----------------------------- \n");
            printf("\n\t\t\t Sorry this ID is not found !\n\n");

            printf("\n 1- Reenter your ID \n");
            printf("\n 2- End search \n\n");

            c=getchar();
            while ( c!='1' && c!='2' )
            {
                printf(" please enter a valid choice (1 or 2)\n");
                getchar();
                c=getchar();
            }
            getchar();


            if (c=='2')
            {
                system("cls");
                break;
            }

        }
        else
        {
            system("cls");
            printf("\t\t\t Welcome To The Library System \n");
            printf("\t\t\t ----------------------------- \n");
            printf("\n\t\t\t\t   Member found\n\n");
            printf(" user details:\n ------------\n\n name: %s\t%s\n\nid: %s\n\naddress: %s\n\nphone number: %s\tage: %s\n\nemail address: %s\n ",user[i].firstname,user[i].lastname,user[i].id,user[i].address,user[i].phonenumber,user[i].age,user[i].emailadress);
            system("pause");
            system("cls");
            break;
        }
    }

}

void Remove_member()
{

    char user_id[50];
    while (1)
    {
        if (n_member==0)
        {
            system("cls");
            printf("\t\t\t Welcome To The Library System \n");
            printf("\t\t\t ----------------------------- \n");
            printf("\n Sorry there is no members ! ");
            system("pause");
            break;
        }
        else
        {
            system("cls");
            printf("\t\t\t Welcome To The Library System \n");
            printf("\t\t\t ----------------------------- \n");
            printf("\n Enter the Member ID : ");
            gets(user_id);

            for (i=0; i<n_member; i++)
            {
                if(strcmp(user_id,user[i].id)==0)
                    break;
            }
            if(i==n)
            {
                system("cls");
                printf("\t\t\t Welcome To The Library System \n");
                printf("\t\t\t ----------------------------- \n");
                printf("\n\t\t\t Sorry this ID is not found !\n\n");

                printf("\n 1- Reenter your ID \n");
                printf("\n 2- Back to main menu \n\n");

                c=getchar();
                while ( c!='1' && c!='2' )
                {
                    printf(" please enter a valid choice (1 or 2)\n");
                    getchar();
                    c=getchar();
                }
                getchar();


                if (c=='2')
                {
                    system("cls");
                    break;
                }

            }
            else
            {
                for (j=0; j<n_borrow; j++)
                {
                    if(strcmp(user_id,borrow_list[j].user_code)==0)
                        break;
                }

                if (j==n_borrow)
                {
                    system("cls");
                    printf("\t\t\t Welcome To The Library System \n");
                    printf("\t\t\t ----------------------------- \n");
                    printf(" user details:\n ------------\n\n name: %s\t%s\n\nid: %s\n\naddress: %s\n\nphone number: %s\tage: %s\n\nemail address: %s\n ",user[i].firstname,user[i].lastname,user[i].id,user[i].address,user[i].phonenumber,user[i].age,user[i].emailadress);

                    printf("\n\n\n \t\tIS this the Member you want to remove ? \n\t\t\t  1-yes\t\t2-no\n\n");
                    c=getchar();
                    while ( c!='1' && c!='2' )
                    {
                        printf(" please enter a valid choice (1or2)\n");
                        getchar();
                        c=getchar();
                    }
                    getchar();

                    switch (c)
                    {
                    case '1':
                    {
                        for (j=i; j<n_member-1; j++)
                        {
                            user[j]=user[j+1];
                        }
                        n_member--;

                        system("cls");
                        printf("\t\t\t Member deleted successfully !\n");

                        getchar();
                        system("cls");
                        break;

                    }
                    case '2':
                    {
                        system("cls");
                        printf("\t\t\t Welcome To The Library System \n");
                        printf("\t\t\t ----------------------------- \n");
                        printf("\n 1- Reenter your ID \n");
                        printf("\n 2- Back to main menu \n\n");

                        e=getchar();
                        while ( e!='1' && e!='2' )
                        {
                            printf(" please enter a valid choice (1 or 2)\n");
                            getchar();
                            e=getchar();
                        }
                        getchar();
                    }
                    }


                    if (e=='2')
                    {
                        system("cls");
                        break;
                    }


                    if (c=='1')
                    {
                        system("cls");
                        break;
                    }

                }
                else
                {
                    system("cls");
                    printf("\t\t\t Welcome To The Library System \n");
                    printf("\t\t\t ----------------------------- \n");
                    printf("\n\t Sorry this member still has books ( Can't be removed ) !\n\n");

                    printf("\n 1- Reenter your ID \n");
                    printf("\n 2- Back to main menu \n\n");

                    c=getchar();
                    while ( c!='1' && c!='2' )
                    {
                        printf(" please enter a valid choice (1 or 2)\n");
                        getchar();
                        c=getchar();
                    }
                    getchar();


                    if (c=='2')
                    {
                        system("cls");
                        break;
                    }
                }
            }
        }
    }

}


void Print_Member_List()
{
    printf("\n MEMBERS LIST:\n ---------\n\n");

    for (i=0; i<n_member; i++)
        printf("\n Member %d :\n\n Name: %s\t%s\n\nID: %s\n\nAddress: %s\tPhone number: %s\n\nAge: %s\t\tEmail address: %s\n\n ",(i+1),user[i].firstname,user[i].lastname,user[i].id,user[i].address,user[i].phonenumber,user[i].age,user[i].emailadress);
    system("pause");
    system("cls");
}


void Borrow_Book()
{
    char user_id[20];
    int book_isbn;
    int count = 0,days;

    time_t currtime;
    struct tm * timeinfo;
    time ( &currtime );
    timeinfo = localtime ( &currtime );

    while (1)
    {
        system("cls");
        printf("\t\t\t Welcome To The Library System \n");
        printf("\t\t\t ----------------------------- \n");
        printf("\n Enter the ID : ");
        gets(user_id);

        for (i=0; i<n_member; i++)
        {
            if(strcmp(user_id,user[i].id)==0)
                break;
        }
        if(i== n_member)
        {
            system("cls");
            printf("\t\t\t Welcome To The Library System \n");
            printf("\t\t\t ----------------------------- \n");
            printf("\n\t\t\t Sorry this ID is not found !\n\n");

            printf("\n 1- Reenter your ID \n");
            printf("\n 2- End search \n\n");

            c=getchar();
            while ( c!='1' && c!='2' )
            {
                printf(" please enter a valid choice (1 or 2)\n");
                getchar();
                c=getchar();
            }
            getchar();


            if (c=='2')
            {
                system("cls");
                break;
            }

        }
        else
        {
            for(i=0; i<n_borrow; i++)
            {
                if( (strcmp(user_id,borrow_list[i].user_code) == 0) && borrow_list[i].date_returned.day == 0)
                    count++;
            }
            if (count >=3)
            {
                system("cls");
                printf("\t\t\t Welcome To The Library System \n");
                printf("\t\t\t ----------------------------- \n");
                printf("\n\t\t This member has already three books !!\n\n");
                system("pause");
                system("cls");
                break;

            }
            else
            {
                while (1)
                {
                    system("cls");
                    printf("\t\t\t Welcome To The Library System \n");
                    printf("\t\t\t ----------------------------- \n");

                    printf("\n Search by : ");
                    printf("\n --------- \n");
                    printf("\n 1- Title \n");
                    printf("\n 2- ISBN \n");
                    printf("\n 3- Author name \n");
                    printf("\n 4- Category \n\n");

                    c=getchar();
                    while ( c!='1' && c!='2' && c!='3' && c!='4' )
                    {
                        printf(" please enter a valid choice (1,2,3 or 4)\n");
                        getchar();
                        c=getchar();
                    }
                    getchar();

                    switch (c)
                    {
                    case '1':
                    {
                        FindBookByTitle();
                        break;
                    }
                    case '2':
                    {
                        FindBookByISBN();
                        break;
                    }
                    case '3':
                    {
                        FindBookByAuthorName();
                        break;
                    }
                    case '4':
                    {
                        FindBookByCategory();
                        break;
                    }
                    }

                    system("cls");
                    printf("\t\t\t Welcome To The Library System \n");
                    printf("\t\t\t ----------------------------- \n");
                    printf("\n\t\t\t Did you find your book ? \n\n");

                    printf("\n 1- Yes \n");
                    printf("\n 2- No \n");
                    printf("\n 3- Search again \n\n");


                    c=getchar();
                    while ( c!='1' && c!='2' && c!='3' )
                    {
                        printf(" please enter a valid choice (1,2 or 3)\n");
                        getchar();
                        c=getchar();
                    }
                    getchar();

                    if (c=='1' || c=='2')
                        break;
                }
                if (c=='2')
                {
                    system("cls");
                    break;
                }
                system("cls");
                printf("\t\t\t Welcome To The Library System \n");
                printf("\t\t\t ----------------------------- \n");
                printf("\n  Enter the book ISBN : ");
                scanf("%d",&book_isbn);
                for (j=0; j<n; j++)
                {
                    if ((book_isbn == book[j].ISBN) && book[j].CurrentAvalibleBook >0 )
                    {
                        break;
                    }
                }
                if (j==n)
                {
                    system("cls");
                    printf("\t\t\t Welcome To The Library System \n");
                    printf("\t\t\t ----------------------------- \n");
                    printf("\n Sorry, this book is not available right now!!\n");
                    system("pause");
                    getchar();
                    system("cls");
                    break;
                }
                else
                {
                    book[j].CurrentAvalibleBook--;
                    borrow_list[n_borrow].date_issued.day = timeinfo->tm_mday;
                    borrow_list[n_borrow].date_issued.month = timeinfo->tm_mon+1;
                    borrow_list[n_borrow].date_issued.year = timeinfo->tm_year+1900;
                    borrow_list[n_borrow].book_code = book_isbn;
                    strcpy(borrow_list[n_borrow].user_code,user_id);

                    system("cls");
                    printf("\t\t\t Welcome To The Library System \n");
                    printf("\t\t\t ----------------------------- \n");

                    printf("\nThe Current Date is: %d/%d/%d\n",borrow_list[n_borrow].date_issued.day,borrow_list[n_borrow].date_issued.month,borrow_list[n_borrow].date_issued.year);

                    printf("\n\nEnter the number of days : ");
                    scanf("%d",&days);
                    while ( days <= 0 )
                    {
                        printf("\n\nEnter a valid number of days : ");
                        scanf("%d",&days);
                    }

                    currtime += days * 24 * 60 * 60;
                    timeinfo = localtime(&currtime);

                    borrow_list[n_borrow].date_to_return.day = timeinfo->tm_mday;
                    borrow_list[n_borrow].date_to_return.month = timeinfo->tm_mon+1;
                    borrow_list[n_borrow].date_to_return.year = timeinfo->tm_year+1900;

                    printf("\n\nThe  Date to return is: %d/%d/%d\n",borrow_list[n_borrow].date_to_return.day,borrow_list[n_borrow].date_to_return.month,borrow_list[n_borrow].date_to_return.year);

                    n_borrow ++;

                    system("pause");
                    getchar();
                    system("cls");

                    break;

                }
            }
        }
    }
}

void Return_Book()
{
    char member_ID [50];
    time_t currtime;
    struct tm * timeinfo;
    time ( &currtime );
    timeinfo = localtime ( &currtime );

    while (1)
    {
        k=0;
        system("cls");
        printf("\t\t\t Welcome To The Library System \n");
        printf("\t\t\t ----------------------------- \n");
        printf("\n Enter the ID : ");
        gets(member_ID);

        for (i=0; i<n_borrow; i++)
        {
            if(strcmp(member_ID,borrow_list[i].user_code)==0 && borrow_list[i].date_returned.day ==0 )
            {
                for (j=0; j<n; j++)
                {
                    if(borrow_list[i].book_code==book[j].ISBN)
                    {
                        search_list[k]=book[j];
                        break;
                    }
                }
                k++;

            }
        }
        if(k==0)
        {
            system("cls");
            printf("\t\t\t Welcome To The Library System \n");
            printf("\t\t\t ----------------------------- \n");
            printf("\n\t\t\t Sorry this member didn't borrow any books !\n\n");

            printf("\n 1- Reenter your ID \n");
            printf("\n 2- Back to main menu \n\n");

            c=getchar();
            while ( c!='1' && c!='2' )
            {
                printf(" please enter a valid choice (1 or 2)\n");
                getchar();
                c=getchar();
            }
            getchar();


            if (c=='2')
            {
                system("cls");
                break;
            }

        }
        else
        {

            system("cls");
            printf("\t\t\t Welcome To The Library System \n");
            printf("\t\t\t ----------------------------- \n");
            printf("\n\t\t\t Books borrowed by this member : \n\n");
            for (i=0 ; i<k ; i++)
                printf("\n --> Book %d: %s\t\t %06d",(i+1),search_list[i].title,search_list[i].ISBN);

            printf("\n Enter the book no. you want to return : ");
            scanf("%d",&l);

            while ( l <= 0 || l> k )
            {
                printf("\n Enter a valid choice : ");
                scanf("%d",&l);
            }

            for (j=0; j<n; j++)
            {
                if(search_list[l-1].ISBN==book[j].ISBN)
                {
                    book[j].CurrentAvalibleBook++;
                    break;
                }
            }

            for (j=0; j<n_borrow; j++)
            {
                if(search_list[l-1].ISBN==borrow_list[j].book_code  &&  strcmp(member_ID,borrow_list[j].user_code)==0 )
                {
                    borrow_list[j].date_returned.day = timeinfo->tm_mday;
                    borrow_list[j].date_returned.month = timeinfo->tm_mon+1;
                    borrow_list[j].date_returned.year = timeinfo->tm_year+1900;
                    break;
                }
            }

            system("cls");
            printf("\t\t\t Welcome To The Library System \n");
            printf("\t\t\t ----------------------------- \n");
            printf("\n\t\t\t Book returned successfully  \n\t\t   Thank you for visiting our library  \n");

            printf("\nThe Returned Date is: %d/%d/%d\n",borrow_list[j].date_returned.day,borrow_list[j].date_returned.month,borrow_list[j].date_returned.year);
            system("pause");
            getchar();
            system("cls");
            break;
        }
    }

}
void OverDue()
{

    time_t currtime;
    struct tm * timeinfo;
    time ( &currtime );
    timeinfo = localtime ( &currtime );
    int flag = 0;

    system("cls");
    printf("\t\t\t Welcome To The Library System \n");
    printf("\t\t\t ----------------------------- \n");
    printf("\n\t\t\t The overdue books  \n\n");


    for (i=0; i< n_borrow; i++)
    {
        if (borrow_list[i].date_returned.day == 0 && borrow_list[i].date_returned.month == 0 && borrow_list[i].date_returned.year == 0)
        {
            if (borrow_list[i].date_to_return.year<=timeinfo->tm_year+1900)
                if (borrow_list[i].date_to_return.month <= timeinfo->tm_mon+1 )
                    if (borrow_list[i].date_to_return.day<timeinfo->tm_mday )
                    {
                        flag = 1;
                        for ( k=0; k<n; k++)
                        {
                            if (borrow_list[i].book_code == book[k].ISBN)
                            {
                                printf("\n ---> Title: %s \t\tISBN: %d ",book[k].title,book[k].ISBN);
                                break;
                            }
                        }
                        for ( j=0; j<n_member; j++)
                        {
                            if (strcmp(borrow_list[i].user_code,user[j].id)==0)
                            {
                                printf("\n\t Member Name : %s \t\t ID: %s ",user[j].firstname,user[j].id);
                                printf("\n\t Due Date : %d/%d/%d \n _______________________________________________________________\n",borrow_list[i].date_to_return.day,borrow_list[i].date_to_return.month,borrow_list[i].date_to_return.year);
                                break;
                            }
                        }
                    }

 }

    }       system("pause");
        system("cls");

    if ( flag == 0 )
    {
        printf(" \n\nThere is no overdue Book !!\n\n\n");
        system("pause");
        system("cls");
    }
}
