#include <cstring>
#include <iostream>
using namespace std;

class Person
{
public:
	Person(char *pname);
	~Person();
public:
	const char* GetName() const;
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

const char * Person::GetName() const
{
	return m_pname;
}

int main()
{
	Person jhon("jhon");
	const char *ptr = jhon.GetName();
	delete ptr; // document such misuse
	cout << jhon.GetName() << endl;
	return 0;
}
