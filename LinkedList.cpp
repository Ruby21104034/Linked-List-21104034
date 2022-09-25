#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    string member;
    string name;
    int age;
    Node *next;
    Node *prev;
    Node(string s1, string s2, int val)
    {
        member = s1;
        name = s2;
        age = val;
        next = NULL;
        prev = NULL;
    }
};
void inserthead(Node *&head, string member, string name, int val)
{
    Node *n = new Node(member, name, val);
    n->next = head;
    if (head != NULL)
    {
        head->prev = n;
    }
    head = n;
}
void insertEnd(Node *&head, string member, string name, int val)
{
    Node *n = new Node(member, name, val);
    if (head == NULL)
    {
        inserthead(head, member, name, val);
        return;
    }
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
    n->prev = temp;
}
// insertion in a doubly linked list

void display(Node *head)
{
    Node *temp = head;
    while (head != NULL)
    {
        cout << temp->member << " ";
        cout << temp->name << " ";
        cout << temp->age << " ";
        cout << endl;
        temp = temp->next;
    }
    // cout << endl;
}
void deleteAtHead(Node *&head)
{
    Node *todelete = head;
    head = head->next;
    head->prev = NULL;
    delete todelete;
}
void deletion(Node *&head, int pos)
{
    if (pos == 1)
    {
        deleteAtHead(head);
        return;
    }
    Node *temp = head;
    int count = 1;
    while (temp != NULL && count != pos)
    {
        temp = temp->next;
        count++;
    }
    temp->prev->next = temp->next;
    if (temp->next != NULL)
    {
        temp->next->prev = temp->prev;
    }
    delete temp;
}
int main()
{
    Node *head = NULL;
    int n;
    cout << "Enter the number of family members to be inserted into the linked list : ";
    cin >> n;
    int age;
    string name;
    string member;
    
    for (int i = 0; i < n; i++)
    {
        // Node *head = NULL;
        cout << "Relation : ";
        cin >> member;
        cout << "Name : ";
        cin >> name;
        cout << "Age : ";
        cin >> age;
        insertEnd(head, member, name, age);
    }

    // display(head);

    cout << "1. To add member at beginning" << endl
         << "2. To add member at end" << endl
         << "3. To delete a member" << endl
         << "4. Exit" << endl;
    int a;
    cout << "Choose a function : " << endl;
    cin >> a;
    if (a == 1)
    {
        cout << "Relation : ";
        cin >> member;
        cout << "Name : ";
        cin >> name;
        cout << "Age : ";
        cin >> age;
        inserthead(head, member, name, age);
        cout << "Inserted at head" << endl;
    }
    else if (a == 2){
        cout << "Relation : ";
        cin >> member;
        cout << "Name : ";
        cin >> name;
        cout << "Age : ";
        cin >> age;
        insertEnd(head, member, name, age);
        cout << "Inserted at end" << endl;
    }

    else if(a==3){
        cout<<"Enter the position to be deleted from the list : "<<endl;
        int b;
        cin>>b;
        deletion(head, b);
    }
    
    display(head);
    return 0;
}

//With simple sorting ,the family members can be linked on the basis of age