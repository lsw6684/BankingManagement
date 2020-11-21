#include <iostream>
#include <cstring>
#include <Windows.h>

using namespace std;
const int MAX_LEN = 10;

//함수 먼저 선언
void Loading(void);		// 로딩
void Menu(void);		// 메뉴
void Register(void);	// 계좌 생성
void Input(void);		// 입금
void Output(void);		// 출금
void Management(void);	// Management

enum {REGISTER = 1, INPUT, OUTPUT, MANAGEMENT, EXIT};
int accIndex = 0;

typedef struct			// 구조체
{
	int id, balance;
	char name[MAX_LEN];
} Account;				// 구조체 별칭
Account accArr[100];	// 계좌 저장

int main(void)
{
	int start;

	while (true)
	{
		Menu();
		cout << "선택 : ";
		cin >> start;
		cout << endl;

		switch (start)
		{
		case REGISTER:
			system("cls");
			Register();
			system("cls");
			break;
		case INPUT:
			system("cls");
			Input();
			system("cls");
			break;
		case OUTPUT:
			system("cls");
			Output();
			system("cls");
			break;
		case MANAGEMENT:
			system("cls");
			Management();
			system("pause");
			system("cls");
			break;
		case EXIT:
			system("cls");
			cout << "Thank you ~ ▶▶▶▶▶▶▶▶▶▶▶▶ Exit" << endl;
			return 0;
		default:
			cout << " 다시 누르세요." << endl;
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

void Menu(void)
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

void Register(void)
{
	int id, balance;
	char name[MAX_LEN];

	cout << "■■■■■■■■■ 계좌  생성 ■■■■■■■■" << endl;
	cout << "■ 1. 아  이  디                            ■" << endl;
	cout << "■ 2. 이      름                            ■" << endl;
	cout << "■ 3. 입  금  액                            ■" << endl;
	cout << "■                                          ■" << endl;
	cout << "■                                          ■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "----------------------------------------------" << endl;
	cout << " 아이디를 입력하세요 : "; cin >> id; cout << endl;
	cout << " 이  름을 입력하세요 : "; cin >> name; cout << endl;
	cout << " 얼마를 입금 할까요? : "; cin >> balance; cout << endl;

	accArr[accIndex].id = id;
	accArr[accIndex].balance = balance;
	strcpy_s(accArr[accIndex].name, name);
	accIndex++;
}

void Input(void)
{
	int id, money;
	cout << "■■■■■■■■■  입    금  ■■■■■■■■" << endl;
	cout << "■ 1. 회원    ID                            ■" << endl;
	cout << "■ 2. 입  금  액                            ■" << endl;
	cout << "■                                          ■" << endl;
	cout << "■                                          ■" << endl;
	cout << "■                                          ■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "----------------------------------------------" << endl;
	cout << " 아이디를 입력하세요 : "; cin >> id; cout << endl;
	
		for (int i = 0; i < accIndex; i++) // ID 인증
		{
			if (accArr[i].id == id)
			{
	
				cout << "★인증되었습니다.★" << endl;
				break;
			}
			else
			{
				while (1)
				{
					cout << " 일치하지 않습니다. 다시 입력하세요. : "; cin >> id; //cout << endl;
					if (accArr[i].id == id)
					{
						cout << " ★인증되었습니다.★" << endl;
						break;
					}
				}
			}
		}
	
	cout << " 얼마를 입금 할까요? : "; cin >> money; cout << endl;
	for (int i = 0; i < accIndex; i++)
	{
		if (accArr[i].id == id)
		{
			accArr[i].balance += money;
		}
	}
	cout << " 입금이 완료되었습니다." << endl;

}

void Output(void)
{
	int money, id;

	cout << "■■■■■■■■■  출    금  ■■■■■■■■" << endl;
	cout << "■ 1. 회원    ID                            ■" << endl;
	cout << "■ 2. 출  금  액                            ■" << endl;
	cout << "■                                          ■" << endl;
	cout << "■                                          ■" << endl;
	cout << "■                                          ■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "----------------------------------------------" << endl;
	cout << " 아이디를 입력하세요 : "; cin >> id; cout << endl;

	for (int i = 0; i < accIndex; i++) // ID 인증
	{
		if (accArr[i].id == id)
		{
			cout << "★인증되었습니다.★" << endl;
			break;
		}
		else
		{
			while (1)
			{
				cout << " 일치하지 않습니다. 다시 입력하세요. : "; cin >> id; //cout << endl;
				if (accArr[i].id == id)
				{
					cout << " ★인증되었습니다.★" << endl;
					break;
				}
			}
		}
	}
	cout << " 얼마를 출금 할까요? : "; cin >> money; cout << endl;
	for (int i = 0; i < accIndex; i++)
	{
		if (accArr[i].balance < money)
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
			accArr[i].balance -= money;
			cout << " 출금이 완료되었습니다." << endl;
		}
	}
}

void Management(void)
{
	for (int i = 0; i < accIndex; i++)
	{
		cout << "I  D : " << accArr[i].id << endl;
		cout << "이름 : " << accArr[i].name << endl;
		cout << "잔액 : " << accArr[i].balance << endl;
		if(i!=accIndex-1)
		cout << "----------------------------------------------" << endl;
		

	}
}

