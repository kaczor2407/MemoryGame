#include <iostream>
#include <vector>
#include <cstdlib>
#include <time.h>
#include <Windows.h>

using namespace std;

class Memory;
void Menu();

HANDLE h;
vector<int> mem;
int Size_l = 5;
int Size_m = 7;
int Size_h = 10;
int score = 0;

int temp_l[5];
int temp_m[7];
int temp_h[10];
static int j = 0;
char write;
bool allCorrectly = true;

class Memory
{
public:
    int l[5];
    int m[7];
    int h[10];
    Memory(int Size);
    Memory() {};
    void display_Random();
    void logic();
};

Memory::Memory(int Size)
{
    if(Size == 5)
    {
        for(int i = 0 ; i < Size ; i++)
        {
            l[i] = rand()%10;
            mem.push_back(l[i]);

        }
    }
    else if(Size == 7)
    {
        for(int i = 0 ; i < Size ; i++)
        {
            m[i] = rand()%10;
            mem.push_back(m[i]);

        }
    }
    else if(Size == 10)
    {
        for(int i = 0 ; i < Size ; i++)
        {
            h[i] = rand()%10;
            mem.push_back(h[i]);

        }
    }

}

void Memory::display_Random()
{
    if(write == 'l')
    {
        for(int i = 0 ; i < Size_l ; i++ )
        {
            cout<<l[i]<<" ";
        }
    }
    if(write == 'm')
    {
        for(int i = 0 ; i < Size_m ; i++)
        {
            cout<<m[i]<<" ";
        }
    }
    if(write == 'h')
    {
        for(int i = 0 ; i < Size_h ; i++)
        {
            cout<<h[i]<<" ";
        }
    }
}
void random_Numbers();

void Memory::logic()
{

    cout<<"Input remember numbers"<<endl;

    if(write == 'l')
    {
        for(int x = 0 ; x < Size_l ; x++)
        {
            cin>>temp_l[x];
        }
        for(int i = 0 ; i < Size_l ; i++)
        {

            if(mem[i] == temp_l[i])
            {
                score++;
                allCorrectly = true;

            }
            else if(mem[i] != temp_l[i])
            {
                allCorrectly = false;
            }
        }
        if(allCorrectly)
            cout<<"Score is "<<score<<" / 5";
        if(!allCorrectly)
            cout<<"Score is "<<score<<" / 5 and You lost with computer!";
    }

    if(write == 'm')
    {
        for(int x = 0 ; x < Size_m ; x++)
        {
            cin>>temp_m[x];
        }
        for(int i = 0 ; i < Size_m ; i++)
        {

            if(mem[i] == temp_m[i])
            {
                score++;
                allCorrectly = true;

            }
            else if(mem[i] != temp_m[i])
            {
                allCorrectly = false;
            }
        }
        if(allCorrectly)
            cout<<"Score is "<<score<<" / 7";
        if(!allCorrectly)
            cout<<"Score is "<<score<<" / 7 and You lost with computer!";
    }
    if(write == 'h')
    {
        for(int x = 0 ; x < Size_h ; x++)
        {
            cin>>temp_h[x];
        }
        for(int i = 0 ; i < Size_h ; i++)
        {

            if(mem[i] == temp_h[i])
            {
                score++;
                allCorrectly = true;

            }
            else if(mem[i] != temp_h[i])
            {
                allCorrectly = false;
            }
        }
        if(allCorrectly)
            cout<<"Score is "<<score<<" / 10";
        if(!allCorrectly)
            cout<<"Score is "<<score<<" / 10 and You lost with computer!";
    }


}
void choose_of_level()
{
    h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute( h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    system("CLS");
    cout<<"-------Select the difficult level------- "<<endl;
    cout<<"write (l) You must remember 5 numbers"<<endl;
    cout<<"write (m) You must remember 7 numbers"<<endl;
    cout<<"write (h) You must remember 10 numbers"<<endl;

    cin>>write;

    switch(write)
    {
    case 'l':
        random_Numbers();
        break;
    case 'm':
        random_Numbers();
        break;
    case 'h':
        random_Numbers();
        break;
    }
}

void random_Numbers()
{
    if(write == 'l')
    {

        Memory l(Size_l);
        l.display_Random();
        Sleep(10000);
        system("CLS");
        Menu();
    }
    else if(write == 'm')
    {

        Memory m(Size_m);
        m.display_Random();
        Sleep(10000);
        system("CLS");
        Menu();
    }
    else if(write == 'h')
    {

        Memory h(Size_h);
        h.display_Random();
        Sleep(10000);
        system("CLS");
        Menu();
    }
}
void Menu()
{
    h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute( h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);


    int choose;
    Memory m;
    cout<<"------Memory number Game------"<<endl;
    cout<<"1 - Play Game #########"<<endl;
    cout<<"2 - Difficult level #########"<<endl;
    cout<<"3 - Exit #########"<<endl;

    cin>>choose;
    switch(choose)
    {
    case 1:
        m.logic();
        break;
    case 2:
        choose_of_level();
        break;
    case 3:
        system("Exit");
    }


}
int main()
{
    srand(time(0));
    Menu();
    return 0;
}
