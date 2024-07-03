#include<stdio.h>
#include<windows.h>
#include<conio.h>
int memberId = 0, count_size=0, i, j, flag;
struct member
{
    int id;
    char name[30];
    int semester;
    int room;
    int cost, due, deposit, foodCost, roomRent, advance;
} m,memberData[1000];
void menu();
void insert();
void del();
void display();
void search();
void countmember();
void payBill();
void checkBill();
void memberCost();
void swap();
void sortData(int l, int r);
void calculation();
int partition(int l, int r);
int main()
{
    menu();
    return 0;
}
void menu()
{
    system("cls");
    printf("\n\n\n     *********************************************************************\n");
    printf("\n      _____________:: DGITAL HOSTEL -:- MANAGEMENT SYSTEM ::______________\n");
    printf("\n     *********************************************************************\n\n");
    int choice;
    printf("\n\t1 - Insert Member Record\t\t2 - Delete Member Record\n\n\t3 - Search Member Record\t\t4 - Display Member Record\n\n\t5 - Count Total Records\t\t\t6 - Check Bill\n\n\t7 - Add Member Cost\t\t\t8 - Pay Bill\n\n\n\t\t\t  0 - Press to EXIT APP !\n");
    printf("\n\n\t\t\t  Enter Choice: ");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1 :
        insert();
        break;
    case 2 :
        del();
        break;
    case 3 :
        search();
        break;
    case 4 :
    {
        sortData(1,memberId);
        display();
        break;
    }
    case 5 :
    {
        countmember();
        break;
    }
    case 6 :
    {
        checkBill();
        break;
    }
    case 7 :
    {
        memberCost();
        break;
    }
    case 8 :
    {
        payBill();
        break;
    }
    default :
        exit(0);
        break;
    }
}
void insert()
{
    system("cls");
    printf("****** Add Member Information ******\n");
    printf("Member ID: ");
    scanf("%d",&m.id);
    flag = 0;
    for(i = 1; i <= memberId; i++)
    {
        if(memberData[i].id == m.id)
        {
            flag = 1;
            break;
        }
    }
    if(flag == 1)
    {
        printf("\n%d This id already exist.",m.id);
        getch();
        menu();
    }
    else
    {
        printf("Member Name: ");
        fflush(stdin);
        gets(m.name);
        printf("Batch: ");
        scanf("%d",&m.semester);
        printf("Room No: ");
        scanf("%d",&m.room);
        memberData[++memberId] = m;
        printf("\nYour Data Inserted Successfully.");
    }
    getch();
    menu();
}
void del()
{
    system("cls");
    if(memberId == 0 )
    {
        printf("\nThere Are No Member In The Record!!!\n");
        getch();
        menu();
    }
    printf("***** Member Information Delete Operation *****\n");
    printf("_______________________________________________________\n");
    printf("Enter The Member Id You Want To Delete: ");
    scanf("%d",&m.id);
    flag = 0;
    for(i = 1; i <= memberId; i++)
    {
        if(memberData[i].id == m.id)
        {
            flag = 1;
            m = memberData[i];
            break;
        }
    }
    if(flag == 0)
    {
        printf("\nYour Enter Member ID Not Founded!!!\n");
        getch();
        menu();
    }
    else
    {
        printf("\nThe Following Record Is Deleted.\n");
        printf("\nMember ID: %d",m.id);
        printf("\nMember Name: %s",m.name);
        printf("\nMember Batch: %d",m.semester);
        printf("\nMember Room: %d\n",m.room);
    }
    for(j = i; j < memberId; j++)
    {
        memberData[j] = memberData[j+1];
    }
    memberId--;
    getch();
    menu();
}
void display()
{
    system("cls");
    if(memberId == 0)
    {
        printf("\nThere are no member in the record !!!\n");
        getch();
        menu();
    }
    else
    {
        printf("****** All Member Record ******\n");
        printf("_______________________________________________\n");

        for( i = 1; i <= memberId; i++)
        {
            printf("\nMember ID: %d\n",memberData[i].id);
            printf("Member Name: %s\n",memberData[i].name);
            printf("Member Batch: %d\n",memberData[i].semester);
            printf("Member Room: %d\n",memberData[i].room);
        }
        getch();
        menu();
    }
}
void search()
{
    system("cls");
    if(memberId == 0)
    {
        printf("\nThere are no member in the record !!!\n");
        getch();
        menu();
    }
    else
    {
        printf("****** Member Data Searching ******\n");
        printf("_____________________________________________\n");
        printf("Enter The Member ID: ");
        scanf("%d",&m.id);
        flag = 0;
        for(i = 1; i <= memberId; i++)
        {
            if(memberData[i].id == m.id)
            {
                flag = 1;
                m = memberData[i];
                break;
            }
        }
        if(flag == 1)
        {
            printf("\nMember ID: %d",m.id);
            printf("\nMember Name: %s",m.name);
            printf("\nMember Batch: %d",m.semester);
            printf("\nMember Room: %d\n",m.room);
            getch();
            menu();
        }
        else
        {
            printf("\nMember Record Not Found!!!\n");
            getch();
            menu();
        }
    }
}
void countmember()
{
    system("cls");
    if(memberId == 0)
    {
        printf("\nThere are no member in the record !!!\n");
        getch();
        menu();
    }
    else
    {
        printf("****** Member Records ******\n");
        printf("_____________________________________________\n");
        printf("\nTotal Member Record : %d\n",memberId);
        getch();
        menu();
        return;
    }
}
void payBill()
{
    system("cls");
    printf("****** Pay Bill ******\n");
    printf("_____________________________________________\n");
    if(memberId == 0)
    {
        printf("\nThere are no member in the record !!!\n");
        getch();
        menu();
    }
    else
    {
        printf("\n\nEnter The Member ID: ");
        scanf("%d",&m.id);
        flag = 0;
        for(i = 1; i <= memberId; i++)
        {
            if(memberData[i].id == m.id)
            {
                flag = 1;
                m = memberData[i];
                break;
            }
        }
        if(flag == 1)
        {
            m.cost = m.foodCost + m.roomRent;
            m.due = m.cost - m.deposit;
            printf("\n\nYou Have to Pay: %d Tk\n",m.due);
            printf("\nMember Deposit: ");
            scanf("%d",&m.deposit);
            if(m.deposit == m.due)
            {
                printf("\n\nThank You! Your Bill Paid\n");
                m.cost = 0, m.foodCost = 0, m.roomRent = 0, m.deposit = 0, m.due = 0;
                memberData[i] = m;
                getch();
                menu();
            }
            else if(m.due < m.deposit)
            {
                m.advance = m.deposit - m.due;
                m.cost = 0, m.foodCost = 0, m.roomRent = 0, m.deposit = 0, m.due = 0;
                memberData[i] = m;
                printf("\n\nThank You! Your Bill Paid\n");
                printf("\nYour Changes Amount: %d Tk\n",m.advance);
                printf("\nYour Changes Notes:\n");
                calculation();
                getch();
                menu();
            }
            else
            {
                m.cost = m.foodCost + m.roomRent;
                m.due = m.cost - m.deposit;
                memberData[i] = m;
            }
            getch();
            menu();
        }
        else
        {
            printf("\nMember Record Not Found!!!\n");
            getch();
            menu();
        }
    }
}
void memberCost()
{
    system("cls");
    printf("****** Member Be Spent ******\n");
    printf("_____________________________________________\n");
    if(memberId == 0)
    {
        printf("\nThere are no member in the record !!!\n");
        getch();
        menu();
    }
    else
    {
        printf("Enter The Member ID: ");
        scanf("%d",&m.id);
        flag = 0;
        for(i = 1; i <= memberId; i++)
        {
            if(memberData[i].id == m.id)
            {
                flag = 1;
                m = memberData[i];
                break;
            }
        }
        if(flag == 1)
        {
            printf("\nMember Room Rent: ");
            scanf("%d",&m.roomRent);
            printf("\nMember Food Cost: ");
            scanf("%d",&m.foodCost);
            m.cost = m.foodCost + m.roomRent;
            m.due = m.cost - m.deposit;
            memberData[i] = m;
            getch();
            menu();
        }
        else
        {
            printf("\nMember Record Not Found!!!\n");
            getch();
            menu();
        }
    }
}
void checkBill()
{
    system("cls");
    printf("****** Check Bill ******\n");
    printf("_____________________________________________\n");
    if(memberId == 0)
    {
        printf("\nThere are no member in the record !!!\n");
        getch();
        menu();
    }
    else
    {
        printf("Enter The Member ID: ");
        scanf("%d",&m.id);
        flag = 0;
        for(i = 1; i <= memberId; i++)
        {
            if(memberData[i].id == m.id)
            {
                flag = 1;
                m = memberData[i];
                break;
            }
        }
        if(flag == 1)
        {
            printf("\nMember Name: %s",m.name);
            printf("\nMember Room No: %d\n",m.room);
            printf("\nMember Food Cost: %d\n",m.foodCost);
            printf("\nMember Room Rent: %d\n",m.roomRent);
            printf("\nMember Total Cost: %d\n",m.cost);
            printf("\nMember Deposit: %d\n",m.deposit);
            printf("\nMember Due: %d\n",m.due);
            getch();
            menu();
        }
        else
        {
            printf("\nMember Record Not Found!!!\n");
            getch();
            menu();
        }
    }
}
void calculation()
{
    int ans[10001];
    int notes[] = {1,2,5,10,20,50,100,500,1000};
    for(i = 1; i <= 1000; i++ )
    {
        ans[i] = 0;
    }
    for(i = 8; i >= 0; i--)
    {
        while(m.advance >= notes[i])
        {
            m.advance -= notes[i];
            ans[notes[i]]++;
        }
        if(m.advance == 0)
        {
            break;
        }
    }
    for(i = 1; i <= 1000; i++)
    {
        if(ans[i] != 0)
        {
            printf("\n%d Tk Note Need To %d Pieces\n",i,ans[i]);
        }
    }
}
void swap(struct member *a, struct member *b)
{
    struct member temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int l, int r)
{
    int pivot = memberData[r].room;
    int j = l - 1;
    for(i = l; i <= r - 1; i++)
    {
        if(memberData[i].room < pivot)
        {
            j++;
            swap(&memberData[i], &memberData[j]);
        }
    }
    swap(&memberData[j+1], &memberData[r]);
    return j + 1;
}
void sortData(int l, int r)
{
    if(l < r)
    {
        int pivot = partition(l, r);
        sortData(l, pivot - 1);
        sortData(pivot + 1, r);
    }
}
