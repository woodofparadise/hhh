#include<iostream>
#include<ctime>
#include<cstdlib>
#include<vector>
#include<string>
#include<conio.h>
#include<stack>
#include<iomanip>
using namespace std;
int map[4][4]={-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
bool game_over=false;
bool no_move=true;
bool game_start=true;
int count=0;
int score=0;
void Load_Map()
{
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            map[i][j]=-1;
        }
    }
}
void Insert_Data()
{
    vector<int> blank;
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            if(map[i][j]<0)
            {
                blank.push_back(i);
                blank.push_back(j);
            }
        }
    }
    int len=blank.size();
    if(len==0)
    {
        game_over=true;
        cout<<"game_over!"<<endl;
    }
    else
    {
        srand(time(0));
        int position=rand()%(len/2);
        int x=blank[2*position];
        int y=blank[2*position+1];
        if(game_start)
        {
            map[x][y]=2;
            game_start=false;
        }
        else if(count<=1&&no_move==false)
        {
            map[x][y]=2;
        }
        else if(count>1)
        {
            map[x][y]=4;
        }
    }
}
void Show_Map()
{
    cout<<"score : "<<score<<endl;
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            cout<<setw(5);
            if(map[i][j]>0)
            {
               cout<<map[i][j]<<" "; 
            }
            else
            {
                cout<<"_"<<" ";
            }
        }
        cout<<endl<<endl;
    }
}
void Change_1()
{
    int check[4][4];
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            check[i][j]=map[i][j];
        }
    }
    for(int i=0;i<4;i++)
    {
        stack<int> data;
        for(int j=3;j>=0;j--)
        {
            if(map[j][i]>0)
            {
                data.push(map[j][i]);
                map[j][i]=-1;
            }
        }
        int temp=-1;
        while(!data.empty())
        {
            temp++;
            map[temp][i]=data.top();
            data.pop();
        }
        for(int j=0;j<temp;j++)
        {
            if(map[j][i]==map[j+1][i]&&map[j][i]>0)
            {
                count++;
                map[j][i]*=2;
                score+=map[j][i];
                for(int k=j+1;k<3;k++)
                {
                    map[k][i]=map[k+1][i];
                }
                map[3][i]=-1;
            }
        }
    }
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            if(check[i][j]!=map[i][j])
            {
                no_move=false;
            }
        }
    }
}
void Change_2()
{
    int check[4][4];
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            check[i][j]=map[i][j];
        }
    }
    for(int i=0;i<4;i++)
    {
        stack<int> data;
        for(int j=3;j>=0;j--)
        {
            if(map[i][j]>0)
            {
                data.push(map[i][j]);
                map[i][j]=-1;
            }
        }
        int temp=-1;
        while(!data.empty())
        {
            temp++;
            map[i][temp]=data.top();
            data.pop();
        }
        for(int j=0;j<temp;j++)
        {
            if(map[i][j]==map[i][j+1])
            {
                count++;
                map[i][j]*=2;
                score+=map[i][j];
                for(int k=j+1;k<3;k++)
                {
                    map[i][k]=map[i][k+1];
                }
                map[i][3]=-1;
            }
        }
    }
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            if(check[i][j]!=map[i][j])
            {
                no_move=false;
            }
        }
    }
}
void Change_3()
{
    int check[4][4];
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            check[i][j]=map[i][j];
        }
    }
    for(int i=0;i<4;i++)
    {
        stack<int> data;
        for(int j=0;j<4;j++)
        {
            if(map[j][i]>0)
            {
                data.push(map[j][i]);
                map[j][i]=-1;
            }
        }
        int temp=-1;
        while(!data.empty())
        {
            temp++;
            map[3-temp][i]=data.top();
            data.pop();
        }
        for(int j=3;j>3-temp;j--)
        {
            if(map[j][i]==map[j-1][i])
            {
                count++;
                map[j][i]*=2;
                score+=map[j][i];
                for(int k=j-1;k>0;k--)
                {
                    map[k][i]=map[k-1][i];
                }
                map[0][i]=-1;
            }
        }
    }
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            if(check[i][j]!=map[i][j])
            {
                no_move=false;
            }
        }
    }
}
void Change_4()
{
    int check[4][4];
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            check[i][j]=map[i][j];
        }
    }
    for(int i=0;i<4;i++)
    {
        stack<int> data;
        for(int j=0;j<4;j++)
        {
            if(map[i][j]>0)
            {
                data.push(map[i][j]);
                map[i][j]=-1;
            }
        }
        int temp=-1;
        while(!data.empty())
        {
            temp++;
            map[i][3-temp]=data.top();
            data.pop();
        }
        for(int j=3;j>3-temp;j--)
        {
            if(map[i][j]==map[i][j-1])
            {
                count++;
                map[i][j]*=2;
                score+=map[i][j];
                for(int k=j-1;k>0;k--)
                {
                    map[i][k]=map[i][k-1];
                }
                map[i][0]=-1;
            }
        }
    }
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            if(check[i][j]!=map[i][j])
            {
                no_move=false;
            }
        }
    }
}
void Move_Merge()
{
    char command;
    command=getch();
    no_move=true;
    switch(command)
    {
        case('w'):Change_1();break;
        case('a'):Change_2();break;
        case('s'):Change_3();break;
        case('d'):Change_4();break;
        default:cout<<"error!"<<endl;
    }
}
int main()
{
    void Load_Map();
    cout<<"Press 1 to start,2 to exit"<<endl;
    int if_start;
    cin>>if_start;
    game_over=(if_start==1?false:true);
    while(!game_over)
    {
        system("cls");
        Insert_Data();
        count=0;
        Show_Map();
        cout<<"Press wasd to move!"<<endl;
        no_move=true;
        Move_Merge();
    }
    system("pause");
    return 0;
}