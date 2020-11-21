#include <iostream>
#include <cstring>
#include <Windows.h>

using namespace std;
const int MAX_LEN = 10;

//�Լ� ���� ����
void Loading(void);		// �ε�
void Menu(void);		// �޴�
void Register(void);	// ���� ����
void Input(void);		// �Ա�
void Output(void);		// ���
void Management(void);	// Management

enum {REGISTER = 1, INPUT, OUTPUT, MANAGEMENT, EXIT};
int accIndex = 0;

typedef struct			// ����ü
{
	int id, balance;
	char name[MAX_LEN];
} Account;				// ����ü ��Ī
Account accArr[100];	// ���� ����

int main(void)
{
	int start;

	while (true)
	{
		Menu();
		cout << "���� : ";
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
			cout << "Thank you ~ ������������������������ Exit" << endl;
			return 0;
		default:
			cout << " �ٽ� ��������." << endl;
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

void Menu(void)
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

void Register(void)
{
	int id, balance;
	char name[MAX_LEN];

	cout << "���������� ����  ���� ���������" << endl;
	cout << "�� 1. ��  ��  ��                            ��" << endl;
	cout << "�� 2. ��      ��                            ��" << endl;
	cout << "�� 3. ��  ��  ��                            ��" << endl;
	cout << "��                                          ��" << endl;
	cout << "��                                          ��" << endl;
	cout << "������������������������" << endl;
	cout << "----------------------------------------------" << endl;
	cout << " ���̵� �Է��ϼ��� : "; cin >> id; cout << endl;
	cout << " ��  ���� �Է��ϼ��� : "; cin >> name; cout << endl;
	cout << " �󸶸� �Ա� �ұ��? : "; cin >> balance; cout << endl;

	accArr[accIndex].id = id;
	accArr[accIndex].balance = balance;
	strcpy_s(accArr[accIndex].name, name);
	accIndex++;
}

void Input(void)
{
	int id, money;
	cout << "����������  ��    ��  ���������" << endl;
	cout << "�� 1. ȸ��    ID                            ��" << endl;
	cout << "�� 2. ��  ��  ��                            ��" << endl;
	cout << "��                                          ��" << endl;
	cout << "��                                          ��" << endl;
	cout << "��                                          ��" << endl;
	cout << "������������������������" << endl;
	cout << "----------------------------------------------" << endl;
	cout << " ���̵� �Է��ϼ��� : "; cin >> id; cout << endl;
	
		for (int i = 0; i < accIndex; i++) // ID ����
		{
			if (accArr[i].id == id)
			{
	
				cout << "�������Ǿ����ϴ�.��" << endl;
				break;
			}
			else
			{
				while (1)
				{
					cout << " ��ġ���� �ʽ��ϴ�. �ٽ� �Է��ϼ���. : "; cin >> id; //cout << endl;
					if (accArr[i].id == id)
					{
						cout << " �������Ǿ����ϴ�.��" << endl;
						break;
					}
				}
			}
		}
	
	cout << " �󸶸� �Ա� �ұ��? : "; cin >> money; cout << endl;
	for (int i = 0; i < accIndex; i++)
	{
		if (accArr[i].id == id)
		{
			accArr[i].balance += money;
		}
	}
	cout << " �Ա��� �Ϸ�Ǿ����ϴ�." << endl;

}

void Output(void)
{
	int money, id;

	cout << "����������  ��    ��  ���������" << endl;
	cout << "�� 1. ȸ��    ID                            ��" << endl;
	cout << "�� 2. ��  ��  ��                            ��" << endl;
	cout << "��                                          ��" << endl;
	cout << "��                                          ��" << endl;
	cout << "��                                          ��" << endl;
	cout << "������������������������" << endl;
	cout << "----------------------------------------------" << endl;
	cout << " ���̵� �Է��ϼ��� : "; cin >> id; cout << endl;

	for (int i = 0; i < accIndex; i++) // ID ����
	{
		if (accArr[i].id == id)
		{
			cout << "�������Ǿ����ϴ�.��" << endl;
			break;
		}
		else
		{
			while (1)
			{
				cout << " ��ġ���� �ʽ��ϴ�. �ٽ� �Է��ϼ���. : "; cin >> id; //cout << endl;
				if (accArr[i].id == id)
				{
					cout << " �������Ǿ����ϴ�.��" << endl;
					break;
				}
			}
		}
	}
	cout << " �󸶸� ��� �ұ��? : "; cin >> money; cout << endl;
	for (int i = 0; i < accIndex; i++)
	{
		if (accArr[i].balance < money)
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
			accArr[i].balance -= money;
			cout << " ����� �Ϸ�Ǿ����ϴ�." << endl;
		}
	}
}

void Management(void)
{
	for (int i = 0; i < accIndex; i++)
	{
		cout << "I  D : " << accArr[i].id << endl;
		cout << "�̸� : " << accArr[i].name << endl;
		cout << "�ܾ� : " << accArr[i].balance << endl;
		if(i!=accIndex-1)
		cout << "----------------------------------------------" << endl;
		

	}
}

