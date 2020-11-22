#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <Windows.h>
#include "main.h"
#include "handler.h"

using namespace std;
int c;				//���� ī��Ʈ ����
int check = 0;		// for checking exceptions
const int MAX_LEN = 20;
void Loading(void);		// �ε� �Լ� �̸� ����.

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
	cout << "�̸� : " << name << endl;
	cout << "�ܾ� : " << balance << endl;
	cout << "----------------------------------------------" << endl;
}

Total::~Total()
{
	delete[] name;
}



void Handler::Menu(void) const
{
	cout << "����������  M E  N U  ���������" << endl;
	cout << "�� 1. ����  ����                            ��" << endl;
	cout << "�� 2. ��      ��                            ��" << endl;
	cout << "�� 3. ��      ��                            ��" << endl;
	cout << "�� 4. ��      ��                            ��" << endl;
	cout << "�� 5. ��      ��                            ��" << endl;
	cout << "������������������������" << endl;
	cout << "----------------------------------------------" << endl;
}

void Handler::Register(void)
{
	int id, balance;
	char name[MAX_LEN];

	cout << "���������� ����  ���� ���������" << endl;
	cout << "�� 1. ID_NUMBER                             ��" << endl;
	cout << "�� 2. ��      ��                            ��" << endl;
	cout << "�� 3. ��  ��  ��                            ��" << endl;
	cout << "��                                          ��" << endl;
	cout << "��                                          ��" << endl;
	cout << "������������������������" << endl;
	cout << "----------------------------------------------" << endl;
	cout << " ID_NUMBER(����)�Է� : ";
	while (true)
	{
		c = 0;
		cin >> id; cout << endl;
		for (int i = 0; i < accIndex; i++) // ID �ߺ� �˻�
		{
			if (accArr[i]->GetID() == id)
			{
				c++;
			}
		}

		if (c < 1)
		{
			cout << "�ڻ����Ǿ����ϴ�.��" << endl;
			break;
		}
		else
		{
			cout << " �����ϴ� ���̵��Դϴ�. �ٽ� �Է��ϼ���. : ";
		}
	}

	cout << " ��  ���� �Է��ϼ��� : "; cin >> name; cout << endl;
	cout << " �󸶸� �Ա� �ұ��? : "; cin >> balance; cout << endl;

	accArr[accIndex++] = new Total(id, balance, name);
	check = 1;
}

void Handler::Input(void)
{
	int id, money;
	cout << "����������  ��    ��  ���������" << endl;
	cout << "�� 1. ID_NUMBER                             ��" << endl;
	cout << "�� 2. ��  ��  ��                            ��" << endl;
	cout << "��                                          ��" << endl;
	cout << "��                                          ��" << endl;
	cout << "��                                          ��" << endl;
	cout << "������������������������" << endl;
	cout << "----------------------------------------------" << endl;
	cout << " ID_NUMBER(����)�Է� : ";


	while (true)
	{
		c = 0;
		cin >> id; cout << endl;

		for (int i = 0; i < accIndex; i++) // ID ����
		{
			if (accArr[i]->GetID() == id)
			{
				c++;
			}
		}

		if (c >= 1)
		{
			cout << "�������Ǿ����ϴ�.��" << endl;
			break;
		}
		else
		{
			cout << " ��ġ���� �ʽ��ϴ�. �ٽ� �Է��ϼ���. : ";
		}

	}

	cout << " �󸶸� �Ա� �ұ��? : "; cin >> money; cout << endl;
	for (int i = 0; i < accIndex; i++)
	{
		if (accArr[i]->GetID() == id)
		{
			accArr[i]->Input(money);
		}
	}
	cout << " �Ա��� �Ϸ�Ǿ����ϴ�." << endl;
}

void Handler::Output(void)
{
	int money, id;

	cout << "����������  ��    ��  ���������" << endl;
	cout << "�� 1. ID_NUMBER                             ��" << endl;
	cout << "�� 2. ��  ��  ��                            ��" << endl;
	cout << "��                                          ��" << endl;
	cout << "��                                          ��" << endl;
	cout << "��                                          ��" << endl;
	cout << "������������������������" << endl;
	cout << "----------------------------------------------" << endl;
	cout << " ID_NUMBER(����)�Է� : ";

	while (true)
	{
		c = 0;
		cin >> id; cout << endl;
		for (int i = 0; i < accIndex; i++) // ID ����
		{
			if (accArr[i]->GetID() == id)
			{
				c++;
			}
		}

		if (c >= 1)
		{
			cout << "�������Ǿ����ϴ�.��" << endl;
			break;
		}
		else
		{
			cout << " ��ġ���� �ʽ��ϴ�. �ٽ� �Է��ϼ���. : ";
		}

	}
	cout << " �󸶸� ��� �ұ��? : "; cin >> money; cout << endl;
	for (int i = 0; i < accIndex; i++)
	{
		if (accArr[i]->Output(money) == 0)
		{
			cout << " �ܾ��� �����մϴ�." << endl;
			Sleep(1000);
			cout << " �ʱ� ȭ������ ���ư��ϴ�.";
			Sleep(1000);
			Loading();
			system("cls");
			return;
		}
		else
		{
			cout << " ����� �Ϸ�Ǿ����ϴ�." << endl;
			Sleep(1000);
			cout << " �ʱ� ȭ������ ���ư��ϴ�.";
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
		cout << "���� : ";
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
				cout << " �����ϴ� ���°� �����ϴ�." << endl;
				Sleep(1000);
				cout << " ���¸� �����ϼ���.";
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
				cout << " �����ϴ� ���°� �����ϴ�." << endl;
				Sleep(1000);
				cout << " ���¸� �����ϼ���.";
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
				cout << " �����ϴ� ���°� �����ϴ�." << endl;
				Sleep(1000);
				cout << " ���¸� �����ϼ���.";
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
				cout << "��";
				Sleep(50);
			}
			cout << "                                      ";
			for (int i = 0; i < 10; i++)
			{
				cout << "                                        ��" << endl;
				Sleep(50);
			}
			cout << "                                        ";
			for (int i = 0; i < 15; i++)
			{
				cout << "��";
				Sleep(50);
				if (i == 14) cout << " EXIT" << endl;
			}
			system("pause");
			return 0;
		default:
			system("cls");
			cout << " �߸��� �Է��Դϴ�." << endl;
			Sleep(1000);
			cout << " �ʱ� ȭ������ ���ư��ϴ�." << endl;
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
		cout << "��";
		Sleep(50);
	}
	cout << endl << "          ";
	for (int i = 0; i < 18; i++)
	{
		cout << "��";
		Sleep(50);
	}
	cout << endl;
}