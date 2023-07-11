#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <vector>
using namespace std;
string VPwinner;
string GSwinner;
string GSTwinner;
string GSCwinner;
vector<int> votedUserList;

class candidate
{
public:
	string name;
	string post;
	int id;
	int votes;

public:
	void getDetails()
	{
		cout << "enter your name" << endl;
		cin >> name;
		cout << "enter your scholarid"
			 << "\n";
		cin >> id;
		votes = 0;
	}
};

vector<pair<candidate, int>> GS;
vector<pair<candidate, int>> VP;
vector<pair<candidate, int>> GST;
vector<pair<candidate, int>> GSC;

class fic
{
public:
	void contactfic()
	{
		cout << "You can contact him through academic section. His contact info is not available currently" << endl;
	}
};

class notice
{
public:
	void shownotice()
	{
		cout << "The Gymkhana election 2023-24 will be held on 27th March, 2023. The interested candidate for various post can file their nomination from 22nd March, 2023 to 25th March, 2023. Results will be declared on 29th March,2023" << endl;
	}
};

class nomination : public candidate
{
public:
	int e = 0, f = 0, g = 0, h = 0;

	bool checkeligibility()
	{
		int a, b;
		cout << "please enter the number of backs you have." << endl;
		cin >> a;
		if (a == 0)
		{
			cout << "please enter your year." << endl;
			cin >> b;
			if (b == 3)
			{
				cout << "you are eligible" << endl;
				return true;
			}
			else
			{
				cout << "you are NOT eligible as you must be in third year for this post." << endl;
				return false;
			}
		}
		else
		{
			cout << "you are NOT eligible as you have backs." << endl;
			return false;
		}
	}

	void nominationgive()
	{
		if (checkeligibility())
		{
			candidate candidate;
			candidate.getDetails();
			cout << "which post do you want to nominate yourself for? Type 1 for VP, 2 for GS, 3 for GST, 4 for GSC" << endl;
			int c;
			cin >> c;
			switch (c)
			{
			case 1:
				VP.push_back(make_pair(candidate, f++));
				// VPlist[f]++;
				cout << "your nomination has been filed." << endl;
				break;
			case 2:
				GS.push_back(make_pair(candidate, e++));
				cout << "your nomination has been filed." << endl;
				break;
			case 3:
				GST.push_back(make_pair(candidate, g++));
				cout << "your nomination has been filed." << endl;
				break;
			case 4:
				GSC.push_back(make_pair(candidate, h++));
				cout << "your nomination has been filed." << endl;
				break;
			default:
				cout << "invalid" << endl;
				break;
			}
		}
	}
};

class voterlist : public nomination
{

private:
	string name;

public:
	bool eligibility()
	{
		int i;
		int year;
		int j;
		int k = 0;
		cout << "enter your scholar id" << endl;
		cin >> i;
		cout << "enter your b.tech year" << endl;
		cin >> year;
		if (year == 1 || year == 2 || year == 3)
		{
			if (votedUserList.size() == 0)
			{
				votedUserList.push_back(i);
				return true;
			}
			else
			{
				for (j = 0; j < int(votedUserList.size()); j++)
				{
					if (votedUserList[j] == i)
					{
						k = 1;
						return false;
					}
				}
				if (k == 0)
				{
					votedUserList.push_back(i);
					return true;
				}
			}
		}
		return false;
	}
	void castvote()
	{
		if (eligibility())
		{
			cout << "verified" << endl;
			cout << "votings for vp" << endl;
			for (int z = 0; z < int(VP.size()); z++)
			{
				cout << "name :" << VP[z].first.name << " press " << VP[z].second << " to vote" << endl;
			}
			int choice;
			cout << "you choose: " << endl;
			cin >> choice;
			for (int l = 0; l <= int(VP.size()); l++)
			{
				if (choice == VP[l].second)
				{
					VP[l].first.votes++;
					cout << "you voted for " << VP[l].first.name << "\n";
				}
			}
			cout << "votings for gs\n";
			for (int z = 0; z < int(GS.size()); z++)
				cout << "name : " << GS[z].first.name << " press " << GS[z].second << " to vote" << endl;
			cout << "you choose: ";
			cin >> choice;
			for (int l = 0; l < int(GS.size()); l++)
			{
				if (choice == GS[l].second)
				{
					GS[l].first.votes++;
					cout << "you voted for " << GS[l].first.name << "\n";
				}
			}
			cout << "votings for gst";
			for (int z = 0; z < int(GST.size()); z++)
				cout << "name : " << GST[z].first.name << " press " << GST[z].second << " to vote" << endl;
			cout << "you choose: ";
			cin >> choice;
			for (int l = 0; l < int(GST.size()); l++)
			{
				if (choice == GST[l].second)
				{
					GST[l].first.votes++;
					cout << "you voted for " << GST[l].first.name << "\n";
				}
			}
			cout << "votings for vp";
			for (int z = 0; z < int(GSC.size()); z++)
				cout << "name : " << GSC[z].first.name << " press " << GSC[z].second << " to vote" << endl;
			cout << "you choose: ";
			cin >> choice;
			for (int l = 0; l < int(GSC.size()); l++)
			{
				if (choice == GSC[l].second)
				{
					GSC[l].first.votes++;
					cout << "you voted for " << GSC[l].first.name << "\n";
				}
			}
		}
		else
		{
			cout << "you are not eligible to vote";
		}
	}
	int countvotes(vector<pair<candidate, int>> candidateList)
	{
		int max = 0;
		for (int i = 1; i < int(candidateList.size()); i++)
		{
			if (candidateList[max].first.votes < candidateList[i].first.votes)
			{
				max = i;
			}
		}
		return max;
	}
	void declareWinners()
	{
		cout << "The elected Vice President is : " << VP[countvotes(VP)].first.name << endl;
		cout << "The elected General Secretary is : " << GS[countvotes(GS)].first.name << endl;
		cout << "The elected General Secretary Cultural is : " << GSC[countvotes(GSC)].first.name << endl;
		cout << "The elected General Secretary Technical is : " << GST[countvotes(GST)].first.name << endl;
	}
};

int main()
{
	notice academic;
	fic fic;
	nomination nomination;
	voterlist voterlist;
	int y;
	int aa = 0;
	while (aa == 0)
	{
		cout << endl
			 << "------------------------------------" << endl;
		cout << "Hello! What do you want to do today? Press to 1 have a tour or 2 to exit" << endl;
		cin >> y;
		switch (y)
		{
		case 1:
			cout << "What is today's date? (give only the date as it is already known that it is march)" << endl;
			int date;
			cin >> date;
			if (date == 22 || date == 23 || date == 24 || date==25 )
			{
				int input1;
				cout << "Choose : 1 for Notice, 2 for contacting FIC or 3 for nomination" << endl;
				cin >> input1;
				switch (input1)
				{
				case 1:
					academic.shownotice();
					break;
				case 2:
					fic.contactfic();
					break;
				case 3:
					nomination.nominationgive();
					break;
				default:
					cout << "Wrong choice";
					break;
				}
			}
			else if (date == 27)
			{
				int input2;
				cout << "Choose : 1 for Notice, 2 for contacting FIC or 3 for voting" << endl;
				cin >> input2;
				switch (input2)
				{
				case 1:
					academic.shownotice();
					break;
				case 2:
					fic.contactfic();
					break;
				case 3:
					voterlist.castvote();
					break;
				default:
					cout << "Wrong choice";
					break;
				}
			}
			else if (date == 29)
			{
				int input3;
				cout << "Choose : 1 for Notice, 2 for contacting FIC or 3 for results" << endl;
				cin >> input3;
				switch (input3)
				{
				case 1:
					academic.shownotice();
					break;
				case 2:
					fic.contactfic();
					break;
				case 3:
					voterlist.declareWinners();
					break;
				default:
					cout << "Wrong choice";
					break;
				}
			}
			else
			{
				int input4;
				cout << "Choose : 1 for Notice, 2 for contacting FIC" << endl;
				cin >> input4;
				switch (input4)
				{
				case 1:
					academic.shownotice();
					break;
				case 2:
					fic.contactfic();
					break;
				default:
					cout << "wrong choice" << endl;
				}
			}
			break;
		case 2:
			aa = 1;
			break;
		default:
			cout << "invalid";
			break;
		}
	}
	return 0;
}
