#include <cstring>
#include <iostream>
using namespace std;

class Person
{
public:
	Person(char *pname);
	~Person();
public:
	const char* GetName() const; /*modified*/
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

const char * Person::GetName() const /*modified*/
{
	return m_pname;
}

int main()
{
	Person jhon("jhon");
	const char *ptr = jhon.GetName(); /*modified*/
	strcpy_s(ptr, 4, "Joe");
	cout << jhon.GetName() << endl;
	return 0;
}
