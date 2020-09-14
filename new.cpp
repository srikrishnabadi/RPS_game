#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;
class Tool
{
int strength;
char type;
public:
void set_strength(int s)
{
	strength=s;
}
void set_type(char c)
{
    type=c;	
}
int get_strength()
{
    return strength;	
}
char get_type()
{
	return type;
}	
};

class Rock:public Tool
{
  public:
	Rock(int x=1)
	{
		set_strength(x);
		set_type('r');
	}
	int fight(Tool t)
	{
		int a;
		if(t.get_type()=='s')
		{
		   a=get_strength();
		   a=2*a;
		   set_strength(a);
	       return 1;
	    }
		if(t.get_type()=='p')
		{
		   a=get_strength();
		   a=a/2;
		   set_strength(a);	
		   return 2;
	    }
		else
		return 3;
	}
  	~Rock(){}		
};

class Paper:public Tool
{
  public:
	Paper(int x=1)
	{
	    set_strength(x);
		set_type('p');
	}
	int fight(Tool t)
	{
		int a;
		if(t.get_type()=='r')
		{
		   a=get_strength();
		   a=2*a;
		   set_strength(a);
	       return 1;
	    }
		if(t.get_type()=='s')
		{
		   a=get_strength();
		   a=a/2;
		   set_strength(a);	
		   return 2;
	    }
		else
		return 3;
	}
  	~Paper(){}		
};
class Scissors:public Tool
{
  public:
	Scissors(int x=1)
	{
		set_strength(x);
		set_type('s');	
	}
	int fight(Tool t)
	{
		int a;
		if(t.get_type()=='p')
		{
		   a=get_strength();
		   a=2*a;
		   set_strength(a);
	       return 1;
	    }
		if(t.get_type()=='r')
		{
		   a=get_strength();
		   a=a/2;
		   set_strength(a);	
		   return 2;
	    }
		else
		return 3;
	}
   ~Scissors(){}		
};

class RPSGame
{
 Tool* human;
 Tool* computer;
 int human_wins;
 int computer_wins;
 int ties;
 public:
	Rock r;
	Paper p;
	Scissors s; 
	RPSGame()
	{
		human=new Tool;
		computer=new Tool;
		human_wins=0;
        computer_wins=0;
        ties=0;
	}
 	
 	void display()
   {
 		char d,k,s;
 		int m,n,st1,st2;
 		cout<<"Welcome to Rock, Paper, Scissors!\n";
        cout<<"Do you want to choose different strengths for the tools? (y-yes, n-no)\n";
	    cin>>s;
	    if(s=='y') 
		{
	       cout<<"Enter the strength of your tool(1-5)\n";
		   cin>>st1;
		   human->set_strength(st1);
		   st2=rand() % 5 + 1;
		   computer->set_strength(st2);  
		}
 	do
 	{
 		cout<<"Choose your tool (r-rock, p-paper, s-scissor, e-exit):\n";
	    cin>>d;
	    if(d=='e')
	    break;
	    human->set_type(d);
	    m=rand() % 3 + 1;
	    if(m==1)
	    {
	      cout<<"Computer chose rock\n";
	      k='r';
	    }
	    if(m==2)
	    {
	      cout<<"Computer chose paper\n";
	      k='p';
	    }
        if(m==3)
        {
	      cout<<"Computer chose scissors\n";
	      k='s';
	    }
	    computer->set_type(k);	
		if(d=='r')
		{
		  Rock rk(st1);	
		  n=rk.fight(*computer);
	    }
		if(d=='p')
		{
		  Paper pr(st1);	
		  n=pr.fight(*computer);
	    }
		if(d=='s')
		{
		  Scissors ss(st1);	
		  n=ss.fight(*computer);
	    }
		if(n==1)
		{
		  	cout<<"You win!!! :-)"<<endl;
		  	human_wins++;
		}
		if(n==2)
		{
		  	cout<<"Computer wins! :-("<<endl;
		  	computer_wins++;
		}
		if(n==3)
		{
		  	cout<<"It is a tie!!!!"<<endl;
		  	ties++;
		}
		
	   cout<<"\nResult\n";
	   cout<<"Human wins: "<<human_wins<<endl;
	   cout<<"Computer wins: "<<computer_wins<<endl;
	   cout<<"Ties: "<<ties<<endl;
	}while(1);
}

~RPSGame() {}
	
};

int main()
{
	RPSGame rps;
	rps.display();
    return 0;
}
