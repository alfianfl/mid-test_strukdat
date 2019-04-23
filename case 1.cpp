
/*
Program		: Data klasemen
Nama		: Alfian Fadhil Labib
NPM			: 140810180055
Deskripsi	: 

*/

#include<iostream>
using namespace std;

struct elemlist
{
    int no;
    char tim[20];
    int gol;
    char asal[20];
    elemlist* next;
};
typedef elemlist* pointer;
typedef pointer list;

void createList(list& first)
{
    first = NULL;
}

void createElmt(pointer& pBaru)
{
    pBaru = new elemlist;
    cout << " Tim		: "; cin >> pBaru->tim;
    cout << " Asal Daerah	: "; cin >> pBaru->asal;
    cout << " gol		: "; cin >> pBaru->gol;

    pBaru->next =  NULL;
}
 
void insertfirst(list& first, pointer pBaru)
{
    if (first==NULL)
    {
        first = pBaru;
    }

    else
    {
        pBaru->next = first;
        first = pBaru;
    }
}

void traversal(list First){
    cout<<"\nNo\t"<<"\tNama\t\t"<<"Asal\t\t"<<"Gol\t"<<endl;
    pointer pBantu;
    pBantu=First;
    int i=1;
    while(pBantu != NULL){
        cout<<i<<"\t\t"<<pBantu->tim<<"\t"<<pBantu->asal<<"\t\t"<<pBantu->gol<<endl;
        pBantu=pBantu->next;
        i++;
    }
}

void reverse (list& first)
{
    pointer current = first;
    pointer prev = NULL, next = NULL;

    while (current != NULL)
    {
        next = current->next;
        current->next = first;
        prev = current;
        current = next;
    }
    first = prev;
}
void retraversal(list first, int k)
{
	k=6;
    reverse(first);
    pointer pBantu;
    if (first == NULL)
    {
        cout << "List kosong" << endl;
    }
    else
    {
        pBantu=first;
        do
        {
            for(int i = 0; i < k; i++)
            {
                cout << pBantu->no ;
                cout << pBantu->tim;
	            cout << pBantu->asal;
	            cout << pBantu->gol; 
	            pBantu=pBantu->next;
            }cout<<endl;
            pBantu=pBantu->next;
        } while (pBantu != NULL);
    }
    cout << endl;
}
void tukar(pointer& a,pointer& b){
    int temp = a->gol;
    a->gol = b->gol;
    b->gol = temp;
}

void sorting(list& First){
    int swapped, i;
    pointer ptr1;
    pointer lptr = NULL;

    if (First == NULL)
        return;

    do{
        swapped = 0;
        ptr1 = First;

        while(ptr1->next!=lptr){
            if (ptr1->gol>ptr1->next->gol){
                tukar(ptr1,ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while(swapped);
}






main()
{
    pointer p;
    list l;
    int k;
    
    createList(l);
    
    cout<<"Masukan Banyak Data : ";cin>>k;
	
	for(int i=0;i<k;i++){
    createElmt(p);
    insertfirst(l,p);
}
	
    traversal(l);
    cout<<" sorting : ";
    sorting(l);
    traversal(l);
    
      
}
