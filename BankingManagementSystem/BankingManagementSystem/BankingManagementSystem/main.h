#ifndef __TOTAL__
#define __TOTAL__
class Total				//��ü Ŭ����
{
private:
	int id, balance;
	char* name;
public:
	Total(int id, int money, char* gName);
	Total(const Total& ref);

	int GetID() const;
	void Input(int money);
	int Output(int money);
	void Management() const;
	~Total();
};
#endif