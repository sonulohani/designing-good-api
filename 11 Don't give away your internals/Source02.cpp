#include <cstring>
#include <iostream>
using namespace std;

class Person
{
public:
	Person(char *pname);
	~Person();
public:
	char* GetName() const;
private:
	char *m_pname;
};

Person::Person(char *pname)
{
	int l = strlen(pname);
	m_pname = new char[l + 1];
	strcpy_s(m_pname, l + 1, pname);
}

Person::~Person()
{
	delete m_pname;
	m_pname = nullptr;
}

char * Person::GetName() const
{
	return m_pname;
}

int main() /*modified*/
{
	Person jhon("jhon");
	char *ptr = jhon.GetName();
	strcpy_s(ptr, 4, "Joe");
	cout << jhon.GetName() << endl;
	return 0;
}
