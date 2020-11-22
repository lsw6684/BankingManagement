#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <Windows.h>
#include "main.h"
#include "handler.h"

using namespace std;
int c;				//인증 카운트 변수
int check = 0;		// for checking exceptions
const int MAX_LEN = 20;
void Loading(void);		// 로딩 함수 미리 선언.

enum { eREGISTER = 1, eINPUT, eOUTPUT, eMANAGEMENT, eEXIT };	//switch



Total::Total(int id, int money, char* gName) : id(id), balance(money)
{
	name = new char[strlen(gName) + 1];
	strcpy(name, gName);
}

Total::Total(const Total& ref) : id(ref.id), balance(ref.balance)
{
	name = new char[strlen(ref.name) + 1];
	strcpy(name, ref.name);
}

int Total::GetID() const { return id; }		//get

void Total::Input(int money)
{
	balance += money;
}

int Total::Output(int money)
{
	if (balance < money) return 0;
	balance -= money;
	return money;
}

void Total::Management() const
{

	cout << "I  D : " << id << endl;
	cout << "이름 : " << name << endl;
	cout << "잔액 : " << balance << endl;
	cout << "----------------------------------------------" << endl;
}

Total::~Total()
{
	delete[] name;
}



void Handler::Menu(void) const
{
	cout << "■■■■■■■■■  M E  N U  ■■■■■■■■" << endl;
	cout << "■ 1. 계좌  생성                            ■" << endl;
	cout << "■ 2. 입      금                            ■" << endl;
	cout << "■ 3. 출      금                            ■" << endl;
	cout << "■ 4. 관      리                            ■" << endl;
	cout << "■ 5. 종      료                            ■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "----------------------------------------------" << endl;
}

void Handler::Register(void)
{
	int id, balance;
	char name[MAX_LEN];

	cout << "■■■■■■■■■ 계좌  생성 ■■■■■■■■" << endl;
	cout << "■ 1. ID_NUMBER                             ■" << endl;
	cout << "■ 2. 이      름                            ■" << endl;
	cout << "■ 3. 입  금  액                            ■" << endl;
	cout << "■                                          ■" << endl;
	cout << "■                                          ■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "----------------------------------------------" << endl;
	cout << " ID_NUMBER(숫자)입력 : ";
	while (true)
	{
		c = 0;
		cin >> id; cout << endl;
		for (int i = 0; i < accIndex; i++) // ID 중복 검사
		{
			if (accArr[i]->GetID() == id)
			{
				c++;
			}
		}

		if (c < 1)
		{
			cout << "★생성되었습니다.★" << endl;
			break;
		}
		else
		{
			cout << " 존재하는 아이디입니다. 다시 입력하세요. : ";
		}
	}

	cout << " 이  름을 입력하세요 : "; cin >> name; cout << endl;
	cout << " 얼마를 입금 할까요? : "; cin >> balance; cout << endl;

	accArr[accIndex++] = new Total(id, balance, name);
	check = 1;
}

void Handler::Input(void)
{
	int id, money;
	cout << "■■■■■■■■■  입    금  ■■■■■■■■" << endl;
	cout << "■ 1. ID_NUMBER                             ■" << endl;
	cout << "■ 2. 입  금  액                            ■" << endl;
	cout << "■                                          ■" << endl;
	cout << "■                                          ■" << endl;
	cout << "■                                          ■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "----------------------------------------------" << endl;
	cout << " ID_NUMBER(숫자)입력 : ";


	while (true)
	{
		c = 0;
		cin >> id; cout << endl;

		for (int i = 0; i < accIndex; i++) // ID 인증
		{
			if (accArr[i]->GetID() == id)
			{
				c++;
			}
		}

		if (c >= 1)
		{
			cout << "★인증되었습니다.★" << endl;
			break;
		}
		else
		{
			cout << " 일치하지 않습니다. 다시 입력하세요. : ";
		}

	}

	cout << " 얼마를 입금 할까요? : "; cin >> money; cout << endl;
	for (int i = 0; i < accIndex; i++)
	{
		if (accArr[i]->GetID() == id)
		{
			accArr[i]->Input(money);
		}
	}
	cout << " 입금이 완료되었습니다." << endl;
}

void Handler::Output(void)
{
	int money, id;

	cout << "■■■■■■■■■  출    금  ■■■■■■■■" << endl;
	cout << "■ 1. ID_NUMBER                             ■" << endl;
	cout << "■ 2. 출  금  액                            ■" << endl;
	cout << "■                                          ■" << endl;
	cout << "■                                          ■" << endl;
	cout << "■                                          ■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "----------------------------------------------" << endl;
	cout << " ID_NUMBER(숫자)입력 : ";

	while (true)
	{
		c = 0;
		cin >> id; cout << endl;
		for (int i = 0; i < accIndex; i++) // ID 인증
		{
			if (accArr[i]->GetID() == id)
			{
				c++;
			}
		}

		if (c >= 1)
		{
			cout << "★인증되었습니다.★" << endl;
			break;
		}
		else
		{
			cout << " 일치하지 않습니다. 다시 입력하세요. : ";
		}

	}
	cout << " 얼마를 출금 할까요? : "; cin >> money; cout << endl;
	for (int i = 0; i < accIndex; i++)
	{
		if (accArr[i]->Output(money) == 0)
		{
			cout << " 잔액이 부족합니다." << endl;
			Sleep(1000);
			cout << " 초기 화면으로 돌아갑니다.";
			Sleep(1000);
			Loading();
			system("cls");
			return;
		}
		else
		{
			cout << " 출금이 완료되었습니다." << endl;
			Sleep(1000);
			cout << " 초기 화면으로 돌아갑니다.";
			Sleep(1000);
			Loading();
			system("cls");
			return;
		}
	}
}

Handler::Handler() : accIndex(0)
{ }

void Handler::Management(void) const
{
	for (int i = 0; i < accIndex; i++)
	{
		accArr[i]->Management();
		cout << endl;
	}
}

Handler::~Handler()
{
	for (int i = 0; i < accIndex; i++)
		delete accArr[i];
}

int main(void)
{
	Handler handler;
	int start;

	while (true)
	{
		handler.Menu();
		cout << "선택 : ";
		cin >> start;
		cout << endl;

		switch (start)
		{
		case eREGISTER:
			system("cls");
			handler.Register();
			system("cls");
			break;
		case eINPUT:
			if (check == 0)
			{
				cout << " 존재하는 계좌가 없습니다." << endl;
				Sleep(1000);
				cout << " 계좌를 생성하세요.";
				Loading();
				system("cls");
				break;
			}
			system("cls");
			handler.Input();
			system("cls");
			break;
		case eOUTPUT:
			if (check == 0)
			{
				cout << " 존재하는 계좌가 없습니다." << endl;
				Sleep(1000);
				cout << " 계좌를 생성하세요.";
				Loading();
				system("cls");
				break;
			}
			system("cls");
			handler.Output();
			system("cls");
			break;
		case eMANAGEMENT:
			if (check == 0)
			{
				cout << " 존재하는 계좌가 없습니다." << endl;
				Sleep(1000);
				cout << " 계좌를 생성하세요.";
				Loading();
				system("cls");
				break;
			}
			system("cls");
			handler.Management();
			system("pause");
			system("cls");
			break;
		case eEXIT:
			system("cls");
			cout << "Thank you ~ ";
			for (int i = 0; i < 15; i++)
			{
				cout << "▶";
				Sleep(50);
			}
			cout << "                                      ";
			for (int i = 0; i < 10; i++)
			{
				cout << "                                        ▼" << endl;
				Sleep(50);
			}
			cout << "                                        ";
			for (int i = 0; i < 15; i++)
			{
				cout << "☞";
				Sleep(50);
				if (i == 14) cout << " EXIT" << endl;
			}
			system("pause");
			return 0;
		default:
			system("cls");
			cout << " 잘못된 입력입니다." << endl;
			Sleep(1000);
			cout << " 초기 화면으로 돌아갑니다." << endl;
			Loading();
			system("cls");
		}

	}

	system("pause");
	return 0;

}

void Loading(void)
{
	cout << endl << " Loading..";
	Sleep(1000);
	for (int i = 0; i < 18; i++)
	{
		cout << "■";
		Sleep(50);
	}
	cout << endl << "          ";
	for (int i = 0; i < 18; i++)
	{
		cout << "■";
		Sleep(50);
	}
	cout << endl;
}