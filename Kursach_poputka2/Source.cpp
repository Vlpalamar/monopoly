#pragma once
#include<iostream>
#include<time.h>
#include<Windows.h>
#include<conio.h>
#include<string>
#include<fstream>


using namespace std;
void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void SetColor(int text, int background)
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}
//создать динамический массив
template<class T>
T* Create_Din_Arr(T*& p, int& size)
{
	if (!p)
	{
		p = new T[size];
	}
	return p;
}
template<class T>
T* addElemArray(T*& p, int& size, T elem)
{
	T* t = new T[size + 1];
	for (size_t i = 0; i < size; i++)
	{
		t[i] = p[i];

	}

	t[size] = elem;
	(size)++;
	delete[] p;
	p = t;

	return p;
}

struct pole
{
	string type;
	string name;
	int color;
	int owner;
	int price_for_buy;
	int price_for_hous;
	int amount_of_hous;
	int rent;
	int price_for_sell;


};
pole* p = nullptr;

struct player
{
	int player_color;	
	int number;
	int bank = 3000;
	int position = 0;
	bool direction = 1;
	int deley = 0;
	
};
struct game
{
	int size = 38;
	player* players = nullptr;
	string file_players="filePlayers";
	string file_pole="filePole";
	void filds();
	void course_of_terns();
	void ch_color();
	int D6_throw();
	int amount_of_players();
	void new_game();
	void rules();
	void SortMass(int* m, int n);
	void map();
	void game_menu();
	void pole_info(int ch);
	void menu();
	void move(int turn);
	void sell(int i);
	void pay(int i, int sum);
	void build_house(int i);
	void visual();
	void info_all();
	void save_players();
	void save_Pole();
	void load();
	


};
void game::rules()
{
	setlocale(0, "");
	system("cls");
	string tmp;
	ifstream fin;
	fin.open("rules.txt");
	while (!fin.eof())
	{

		getline(fin, tmp);
		cout << tmp << endl;

	}
	cout << endl;
	system("pause");

}
//бросок кубиков
int game::D6_throw()
{
	int D6_1 = 0;
	int D6_2 = 0;
	D6_1 = rand() % 6 + 1;
	D6_2 = rand() % 6 + 1;
	cout <<"First D6:"<< D6_1 << " second D6:" << D6_2 << endl;
	if (D6_1 == D6_2)
	{
		cout << "ƒ”ЅЋ№!!!!!" << endl;
	}
	return D6_1 + D6_2;
}
int size_res = 0;
//void game::save_players()
//{
//	string file1;
//	file1 = file_players;
//	file1=file1+".bin";
//	ofstream fout(file1, ios::binary);
//	for (size_t i = 0; i < size_res; i++)
//	{
//		fout.write((char*)&players[i], sizeof(player));
//	}
//	fout.close();
//}
//
//void game::save_Pole()
//{
//	string file2;
//	file2 = file_pole;
//	file2 = file2 + ".bin";
//	ofstream fout(file2, ios::binary);
//	for (size_t i = 0; i < size_res; i++)
//	{
//		fout.write((char*)&p[i], sizeof(pole));
//	}
//	fout.close();
//}


//void game::load()
//{
//	
//	
//	string file1= file_players;
//	string file2= file_pole;
//
//	file1 = file1 + ".bin";
//	file2 = file2 + ".bin";
//	if (p)
//	{
//		delete[]p;
//		p = nullptr;
//		size = 0;
//	}
//	if (players)
//	{
//		delete[]players;
//		players = nullptr;
//		size_res = 2;
//	}
//	ifstream fin1(file1, ios::binary);
//	pole c1;
//	if (fin1.is_open())
//	{
//		while (fin1.read((char*)&c1, sizeof(pole)))
//		{
//			addElemArray(p, size, c1);
//		}
//		fin1.close();
//	}
//	else
//	{
//		cout << "File not found!" << endl;
//		system("pause");
//	}
//	ifstream fin2(file2, ios::binary);
//	player c2;
//	if (fin2.is_open())
//	{
//		while (fin2.read((char*)&c2, sizeof(player)))
//		{
//			addElemArray(players, size_res, c2);
//		}
//		fin2.close();
//	}
//	else
//	{
//		cout << "File not found!" << endl;
//		system("pause");
//	}
//
//	
//}



void game::filds()
{
	
	Create_Din_Arr(p, size);

	p[0].type = "start"; p[0].name = "start"; p[0].color =  0;
	p[1].name = "metro"; p[1].color = 6; p[1].price_for_buy = 160; p[1].price_for_hous = 100;
	p[2].type = "plus_money"; p[2].name = "plus_money"; p[2].color = 0;
	p[3].name = "ashan"; p[3].color = 6;  p[3].price_for_buy = 160; p[3].price_for_hous = 100;
	p[4].name = "Ikea"; p[4].color = 6;  p[4].price_for_buy = 160; p[4].price_for_hous = 100;
	p[5].type = "pause"; p[5].name = "pause"; p[5].color = 0;
	p[6].name = "jandex"; p[6].color = 8;
	p[7].name = "SubWay"; p[7].color = 2;  p[7].price_for_buy = 200; p[7].price_for_hous = 100;
	p[8].name = "KFC"; p[8].color = 2;  p[8].price_for_buy = 200; p[8].price_for_hous = 100;
	p[9].type = "teleport"; p[9].name = "teleport"; p[9].color = 0;
	p[10].name = "MacDonalds"; p[10].color = 2;  p[10].price_for_buy = 200; p[10].price_for_hous = 100;
	p[11].type = "jail"; p[11].name = "jail"; p[11].color = 0;
	p[12].name = "Nike"; p[12].color = 5;  p[12].price_for_buy = 280; p[12].price_for_hous = 200;
	p[13].name = "reebok"; p[13].color = 5;  p[13].price_for_buy = 280; p[13].price_for_hous = 200;
	p[14].name = "adidas"; p[14].color = 5;  p[14].price_for_buy = 280; p[14].price_for_hous = 200;
	p[15].name = "microsoft"; p[15].color = 8;
	p[16].name = "scania"; p[16].color = 4;  p[16].price_for_buy = 400; p[16].price_for_hous = 200;
	p[17].type = "plus_money"; p[17].name = "plus_money"; p[17].color = 0;
	p[18].name = "man"; p[18].color = 4;  p[18].price_for_buy = 400; p[18].price_for_hous = 200;
	p[19].type = "Casino"; p[19].name = "Casino"; p[19].color = 0;
	p[20].name = "sony"; p[20].color = 3;  p[20].price_for_buy = 480; p[20].price_for_hous = 300;
	p[21].type = "minus_money"; p[21].name = "minus_money"; p[21].color = 0;
	p[22].name = "LG"; p[22].color = 3;  p[22].price_for_buy = 480; p[22].price_for_hous = 300;
	p[23].name = "sumsung"; p[23].color = 3;  p[23].price_for_buy = 480; p[23].price_for_hous = 300;
	p[24].type = "revers"; p[24].name = "revers"; p[24].color = 0;
	p[25].name = "Google"; p[25].color = 8;
	p[26].name = "bilain"; p[26].color = 1;  p[26].price_for_buy = 520; p[26].price_for_hous = 300;
	p[27].name = "megaphone"; p[27].color = 1;  p[27].price_for_buy = 520; p[27].price_for_hous = 300;
	p[28].type = "teleport"; p[28].name = "teleport"; p[28].color = 0;
	p[29].name = "MTS"; p[29].color = 1;  p[29].price_for_buy = 520; p[29].price_for_hous = 300;
	p[30].type = "Nothing"; p[30].name = "relax(ofc_no)"; p[30].color = 0;
	p[31].name = "gucci"; p[31].color = 11; p[31].price_for_buy = 700; p[31].price_for_hous = 350;
	p[32].name = "chanel"; p[32].color = 11; p[32].price_for_buy = 700; p[32].price_for_hous = 350;
	p[33].name = "lacost"; p[33].color = 11; p[33].price_for_buy = 700; p[33].price_for_hous = 350;
	p[34].name = "Apple"; p[34].color = 8;
	p[35].name = "pepsi"; p[35].color = 15; p[35].price_for_buy = 900; p[35].price_for_hous = 450;
	p[36].type = "minus_money"; p[36].name = "minus_money"; p[36].color = 0;
	p[37].name = "CocaColla"; p[37].color = 15; p[37].price_for_buy = 900; p[37].price_for_hous = 450;
	for (size_t i = 0; i < 38; i++)
	{
		if (p[i].color == 8)
		{
			p[i].rent = 50;
			p[i].owner = -1;
			p[i].price_for_buy = 500;
			p[i].price_for_hous = -1;
			p[i].amount_of_hous = -1;
			p[i].price_for_sell = (p[i].price_for_buy / 2);
			p[i].type = "unoccupied field";
		}
		if (p[i].color != 0 and p[i].color != 8)
		{
			p[i].price_for_sell = (p[i].price_for_buy / 2);
			p[i].rent = (p[i].price_for_buy / 20);
			p[i].owner = -1;
			p[i].amount_of_hous = 0;
			p[i].type = "unoccupied field";
		}
		else if (p[i].color == 0)
		{

			p[i].owner = -2;
			p[i].price_for_buy = -1;
			p[i].price_for_hous = -1;
			p[i].amount_of_hous = -1;
			p[i].rent = -1;
			p[i].price_for_sell = -1;
		}
	}

}
int game::amount_of_players()
{

	int amountPlayers = 2;
	int ch = 0;
	do
	{
		cout << "SELECT amount OF Players" << endl;
		cout << "------------------------" << endl << endl;
		cout << "\t" << "<" << "\t" << amountPlayers << "\t" << ">" << endl;
		ch = _getch();
		system("cls");
		if (ch == 162 or ch == 77)
		{
			amountPlayers++;
		}
		else if (ch == 228 or ch == 75)
		{
			amountPlayers--;
		}
		if (amountPlayers > 4)
		{
			amountPlayers = 2;
		}
		if (amountPlayers < 2)
		{
			amountPlayers = 4;
		}
	} while ( ch != 13);
	cout << "выбрана игра на " << amountPlayers << "-человек" << endl;
	size_res = amountPlayers;
	Create_Din_Arr(players, amountPlayers);
	return amountPlayers;

}

void game::SortMass(int* m, int n)
{
	for (int i = n - 1; i >= 1; i--)
		for (int j = 0; j < i; j++)
		{
			if (m[j] < m[j + 1])
			{
				int foo = m[j];
				m[j] = m[j + 1];
				m[j + 1] = foo;
				swap(players[j], players[j + 1]);
			}
		}
}
void game::ch_color()
{
	int ch = 0;
	int h = 1;
	for (size_t i = 0; i < size_res; i++)
	{
		do
		{
			cout << "Player " << i+1 << "SELECT ur color" << endl;
			cout << "------------------------" << endl << endl;
			cout << "\t" << "<" << "\t";
			SetColor(15, h);
			cout << " ";
			SetColor(15, 0);
			cout << "\t" << ">" << endl;
			ch = _getch();
			system("cls");
			if (ch == 162 or ch == 77)
			{
				h++;
			}
			else if (ch == 228 or ch == 75)
			{
				h--;
			}
			if (h > 15)
			{
				h = 1;
			}
			if (h < 1)
			{
				h = 15;
			}
		} while (ch != 27 and ch != 13);

		players[i].player_color = h;

	}

}
void game::course_of_terns()
{
	system("cls");
	int* corse_array = nullptr;			//переменна€ запоминающа€ данные кубика что бы в дальнейшем анализировать ;
	Create_Din_Arr(corse_array, size_res);
	for (size_t i = 0; i < size_res; i++)
	{
		cout << "player number[" << i+1 << "]Press any button to throw D6"<<endl;
		system("pause");
		corse_array[i] = D6_throw();
		cout << "U got " << corse_array[i] << endl;
		system("pause");
	}
	SortMass(corse_array,  size_res);
	for (size_t i = 0; i < size_res; i++)
	{
		cout << "player with color: ";
		SetColor(players[i].player_color, 0);
		cout << "o";
		SetColor(15, 0); 
		cout<< " go " << i+1 << "-d"<<endl;
	}
	for (size_t i = 0; i < size_res; i++)
	{
		players[i].number = i + 1;
	}
	system("pause");
}
void game::map()
{
	system("cls");
	cout << "   [s][1][+][3][4][P][6][7][8][T][10][#]"<< endl;
	cout << "[37]	 			     [12]" << endl;
	cout << "[-]				     [13]" << endl;
	cout << "[35]			 	     [14]" << endl;
	cout << "[34]				     [15]" << endl;
	cout << "[33]			 	     [16]" << endl;
	cout << "[32]				     [+]" << endl;
	cout << "[31]				     [18]" << endl;
	cout << "[0][29][T][27]26][25][R][23][22][-][20][C]" << endl << endl;
	

}
void game::visual()
{
	for (size_t i = 0; i < size_res; i++)
	{
		SetColor(players[i].player_color, 0);
		cout << "player :" << i+1<<"\t";
	}
	cout << endl;
	SetColor(7, 0);
	for (size_t i = 0; i < size_res; i++)
	{
		
		cout<<"   " << players[i].bank << " $" << "\t";
	}
	cout << endl;
	for (size_t i = 0; i < size_res; i++)
	{

		cout << "field: " << players[i].position<<" "<<p[players[i].position].name << "\t";
	}
	cout << endl;
	cout << endl;
	
}
void game::info_all()
{
	system("cls");
	for (size_t i = 0; i < 38; i++)
	{
		cout << "[" << i << "]";
		if (p[i].owner>-2)
		{
			SetColor(p[i].color, 0);
			cout << p[i].name;
			SetColor(7, 0);
			if (p[i].owner > -1)
			{
				cout << " owned by player :";
				SetColor(players[i].player_color, 0);
				cout << p[i].owner + 1;
				SetColor(7, 0);
			}
		}
		else
		{
			cout << "       ";
			SetColor(p[i].color, 15);
			cout<< p[i].name;
			SetColor(7, 0);
		}
		
		cout << endl;
	}
}
void  game::game_menu()
{

	int ch = 0;
	int ch1 = 0;
	
	do
	{
		for (size_t i = 0; i < size_res; i++)
		{

			cout << "1.get info about field.\n2.throw D6 to make a move.\n3.Build a house.\n4.show all info about fields.\n5.Exit" << endl;
			cin >> ch;
			switch (ch)
			{
			case 1:
				cout << "Enter number of field u want to know about :";

				cin >> ch1;
				cout << endl;
				pole_info(ch1);
				break;
			case 2:
				move(i);
				/*save_players();
				save_Pole();*/
				break;
			case 3:
				build_house(i);
			
				/*save_Pole();*/
				break;
			case 4:
				info_all();
				break;
			case 5:
				exit(0); 
				break;
			default:
				break;
			}
			if (i==size_res)
			{
				i = 0;
			}

		}

	} while (true);
}
void game::sell(int i)
{
	int sell = 0;
	cout << "select field u wanna sell" << endl;
	cin >> sell;
	if (p[sell].owner == i)
	{
		if (p[sell].color == 8  )
		{
			for (size_t j = 0; j < 38; j++)
			{

				if (p[j].owner == i and p[j].color == 8)
				{
					p[j].rent = p[j].rent / 2;
				}
			}
		}

		



		if (p[sell].amount_of_hous > 0)
		{
			p[sell].amount_of_hous--;
			players[i].bank = players[i].bank + p[sell].price_for_sell;
			if (p[sell].amount_of_hous==1)
			{
				p[sell].rent = (p[sell].price_for_buy / 4);
			}
			if (p[sell].amount_of_hous==2)
			{
				p[sell].rent = ((p[sell].price_for_buy / 4) * 3);
			}
			if (p[sell].amount_of_hous == 3)
			{
				p[sell].rent = (p[sell].price_for_buy * 2);
			}
			if (p[sell].amount_of_hous == 4)
			{
				p[sell].rent = (p[sell].price_for_buy * 4);
			}
			if (p[sell].amount_of_hous == 0)
			{
				p[sell].rent = (p[sell].price_for_buy /20);
			}

		}
		else if (p[sell].amount_of_hous == 0)
		{
			players[i].bank = players[i].bank + p[sell].price_for_sell;
			p[sell].owner = -1;
		}
	}
	else
	{
		cout << "that's not your field" << endl;
		system("pause");
	}
}
void game::pay(int i, int sum)
{
	bool Exit_flag = 1;
	do
	{
		pole_info(players[i].position);
		int ch2 = 0;
		cout << "1.pay\n2.sell.\n3.exit" << endl;
		cin >> ch2;
		switch (ch2)
		{
		case 1:
			if (players[i].bank >= sum)
			{
				players[i].bank = players[i].bank - sum;
				Exit_flag = 0;
			}
			else
			{
				cout << "not enough money" << endl;
			}
			
			
			break;
		case 2:
			sell(i);
			break;
		case 3:
			Exit_flag = 0;
			break;
		default:
			break;
		}
	} while (Exit_flag != 0);
}
void game::build_house(int i)
{
	int ch = 0;
	int ch_color = 0;
	int own_color = 0;
	cout << "Enter number of Field u wanna build a house: ";
	cin >> ch;
	cout << endl;
	if (p[ch].amount_of_hous!=-1 and p[ch].amount_of_hous<6 and p[ch].owner==i)
	{
		for (size_t j = 0; j < 38; j++)
		{
			if ( p[j].color==p[ch].color)
			{
				ch_color++;
			}
		}
		for (size_t j = 0; j < 38; j++)
		{
			if (p[j].color == p[ch].color and p[j].owner==p[ch].owner)
			{
				own_color++;
			}
		}
		if (ch_color==own_color)
		{
			
			pay(i, p[ch].price_for_hous);
			p[ch].amount_of_hous++;
			if (p[ch].amount_of_hous==1)
			{
				p[ch].rent = (p[ch].price_for_buy / 4);
			}
			if (p[ch].amount_of_hous==2)
			{
				p[ch].rent = ((p[ch].price_for_buy / 4) * 3);
			}
			if (p[ch].amount_of_hous == 3)
			{
				p[ch].rent = (p[ch].price_for_buy * 2);
			}
			if (p[ch].amount_of_hous == 4)
			{
				p[ch].rent = (p[ch].price_for_buy * 4);
			}
			if (p[ch].amount_of_hous == 5)
			{
				p[ch].rent = (p[ch].price_for_buy * 4.5);
			}
		}
	}
	else
	{
		cout << "u can't build a house here" << endl;
	}
}

void  game::pole_info(int ch)
{
		if (p[ch].color!=0 and p[ch].color != 8)
		{
			
			SetColor(p[ch].color, 0);
			cout << "\t" << p[ch].name;
			SetColor(7, 0);
			cout<<"["<<ch<<"]"<< endl;
		
			if (p[ch].amount_of_hous > 0)
			{
				cout << p[ch].amount_of_hous << endl;
			}
			if (p[ch].owner == -1)
			{
				cout << "field isn't ocupated" << endl;
			}
			else
			{
				cout << "owned by player: ";
				SetColor(players[p[ch].owner].player_color, 0);
				cout<< p[ch].owner+1<< endl;
				SetColor(7, 0);
			}
			cout<<"price for buy: " << p[ch].price_for_buy << "$" << endl;
			cout << "price for hous: "<<p[ch].price_for_hous << "$" << endl;
			cout<<"*-\t"<< (p[ch].price_for_buy/4) << "$" << endl;
			cout << "**-\t" << ((p[ch].price_for_buy / 4)*3) << "$" << endl;
			cout << "***-\t" << (p[ch].price_for_buy * 2) << "$" << endl;
			cout << "****-\t" << (p[ch].price_for_buy * 4) << "$" << endl;
			SetColor(14, 0);
			cout << "*";
			SetColor(7, 0);
			cout<< "-\t"<<(p[ch].price_for_buy * 4.5) << "$" << endl;
			cout<< "price for sell: "<< p[ch].price_for_sell << "$" << endl;
			cout<<"\t\tif u stand here u will pay:" << p[ch].rent<<"$" << endl;
		}
		if (p[ch].color == 8)
		{
			SetColor(p[ch].color, 0);
			cout << "\t" << p[ch].name << endl;
			SetColor(7, 0);
			if (p[ch].owner == -1)
			{
				cout << "field isn't ocupated" << endl;
			}
			else
			{
				cout << "owned by player: " << p[ch].owner << endl;
			}
			cout << "price for buy: " << p[ch].price_for_buy << "$" << endl;
			cout << "*-\t" << "100" << "$" << endl;
			cout << "**-\t" << "200" << "$" << endl;
			cout << "***-\t" << "400" << "$" << endl;
			cout << "****-\t" << "800" << "$" << endl;
			cout << "price for sell: " << p[ch].price_for_sell << "$" << endl;
			cout << "\t\tif u stand here u will pay:" << p[ch].rent << "$" << endl;

		}
		if (p[ch].color==0)				
		{
			cout << "\t";
			SetColor(p[ch].color, 15);
			cout << p[ch].name << endl;
			SetColor(7, 0);
			if (p[ch].name=="minus_money")
			{
				cout << "player loose 200$" << endl;
			}
			if (p[ch].name == "pluse_money")
			{
				cout << "player get 200$" << endl;
			}
			if (p[ch].name == "revers")
			{
				cout << "your next turn will be in oposite way " << endl;
			}
			if (p[ch].name == "start")
			{
				cout << "every time your cross this field u get 200$ " << endl;
			}
			if (p[ch].name == "jail")
			{
				cout << "just a visit, don't worry " << endl;
			}
			if (p[ch].name == "relax(ofc_no)")
			{
				cout << "if u get this field u will be arested :D " << endl;
			}
			if (p[ch].name == "teleport")
			{
				cout << "this field will carry u to 1,5,9 or 14 fields " << endl;
			}
			if (p[ch].name == "Casino")
			{
				cout << "u can win or lose up to 300$ " << endl;
			}
		}
		cout << endl << endl;
}
void game::move(int i)
{
	
		system("cls");
		map();
		visual();
		
		cout << endl << "!!!!player " << i + 1 << "make your turn!!!" << endl;
		bool Exit_flag = 1;
		int move=0;
		move = D6_throw();
		
		if (players[i].deley==0)
		{

		
			if (players[i].direction==1)
			{
				players[i].position = players[i].position + move;
				if (players[i].position + move>=38)
				{
					players[i].position = (players[i].position + move) % 38;
					players[i].bank = players[i].bank + 200;
				}
			}
			if (players[i].direction == 0)
			{
				players[i].position = players[i].position - move;
				players[i].direction = 1;
			}
		
			if (p[players[i].position].type == "teleport")
			{
				int tele = 0;
				tele = rand() % 4;
				if (tele == 0)
				{
					players[i].position = players[i].position + 1;
				}
				if (tele == 1)
				{
					players[i].position = players[i].position + 5;
				}
				if (tele == 2)
				{
					players[i].position = players[i].position + 9;
				}
				if (tele == 3)
				{
					players[i].position = players[i].position + 14;
				}
			}
			if (p[players[i].position].type== "unoccupied field")
			{
				pole_info(players[i].position);
				do
				{
					int ch = 0;
					cout << "1.ocupate the field.\n2.sell.\n3.end turn" << endl;
					cin >> ch;
					switch (ch)
					{
					case 1:
						if (players[i].bank>=p[players[i].position].price_for_buy)
						{
							players[i].bank = players[i].bank - p[players[i].position].price_for_buy;
							p[players[i].position].owner = i ;
							p[players[i].position].type = "occupied";
							if (p[players[i].position].color==8)
							{
								
								for (size_t j = 0; j < 38; j++)
								{

									if (p[j].owner == i and p[j].color==8)
									{	
										p[j].rent = p[j].rent * 2;
									}
								}

								
							}
							Exit_flag = 0;
						}
						else
						{
							cout << "not enough money" << endl;
							system("pause");
						}
						break;
					case 2:
						sell(i);
						break;
					case 3:
						Exit_flag = 0;
						break;
					default:
						break;
					}
				} while (Exit_flag!=0);
			}
			if (p[players[i].position].type == "plus_money")
			{

				players[i].bank = players[i].bank + 200;
				pole_info(players[i].position);

			}
			if (p[players[i].position].type == "minus_money")
			{
				pole_info(players[i].position);
				pay(i, 200);
			
			}
			if (p[players[i].position].type == "revers")
			{
				pole_info(players[i].position);
				players[i].direction = 0;
			}
			if (p[players[i].position].type == "Nothing")		
			{
				pole_info(players[i].position);
				players[i].position = 11;
				players[i].deley = 3;
			}
			if (p[players[i].position].type == "Casino")
			{
				int price=0;
				do
				{
					pole_info(players[i].position);
					int ch2 = 0;
					cout << "1.play\n2.Exit." << endl;
					cin >> ch2;
					switch (ch2)
					{
					case 1:
						price=rand() % 7 -3;
						price = price * 100;
						if (price>=0)
						{
							cout << "Congratulation!! you won " << price <<"$"<< endl;
						}
						else
						{
							cout << "haha u lost " << price <<"$"<< endl;
							pay(i, price);
							Exit_flag = 0;
						}
						break;
					case 2:
						Exit_flag = 0;
						break;
					default:
						break;
					}
				} while (Exit_flag != 0);
			}
			if (p[players[i].position].type == "pause")
			{
				pole_info(players[i].position);
				players[i].deley=1;
				
			}

			if (p[players[i].position].type == "occupied")
			{
				if (p[players[i].position].owner!=i)
				{
					pay(i, p[players[i].position].rent);
					players[p[players[i].position].owner].bank = players[p[players[i].position].owner].bank + p[players[i].position].rent;
				}
				
			}

		}
	else
	{
	
		players[i].deley--;
		cout << players[i].deley << "more turns need to wait " << endl;

	}
}

void game::new_game()
{
	game g;
	system("cls");
	g.amount_of_players();
	system("pause");
	g.ch_color();	
	g.course_of_terns();
	g.map();
	g.game_menu();
		
}


void game::menu()
{
	 filds();
	 bool exit_flag=1;
	do {
		
		system("cls");
		cout << "1.load\n2.Start new game\n3.Rules\n4.exit" << endl;
		int ch = 0;
		cin >> ch;

		switch (ch)
		{
		case 1:
			/*load();*/
			break;
		case 2:
			new_game();
			break;
		case 3:
			rules();
			break;
		case 4:
			exit_flag = 0;
			break;
		default:
			break;
		}
	} while (exit_flag!=0);
}

int main()
{
	srand(time(0));
	setlocale(0, "");
	
	game g;
	g.menu();

	
	int size = 38;
	Create_Din_Arr(p, size);

}

