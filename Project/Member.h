#ifndef MEMBER_H_INCLUDED
#define MEMBER_H_INCLUDED

typedef struct
{    char lastname[40];
     char firstname[30];
     char id[20];
     char phonenumber[20];
     char address[100];
     char age[5];
     char emailadress[30];
} users;

users user [100];
users M_search_list[100];

void Registration();
void FindMemberByName();
void FindMemberByID();
void Remove_member();
void Print_Member_List();

#endif // MEMBER_H_INCLUDED
