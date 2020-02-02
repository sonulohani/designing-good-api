#include <string>
#include <cassert>
using namespace std;

class Programmer
{
public:
	virtual void WriteProgram(string specification) = 0;
};

class CPlusPlusProgrammer : public Programmer
{
public:
	void WriteProgram(string specification) {}
};

class JavaProgrammer : public Programmer
{
public:
	void WriteProgram(string specification) {}
};

class Vendor1 : private CPlusPlusProgrammer
{
public:
	void DoProgramming(string specification)
	{
		WriteProgram(specification);
	}
};

class Vendor2
{
public:
	Vendor2() : m_pProgrammer(nullptr) {}
public:
	void SetProgrammer(Programmer *pProgrammer) { m_pProgrammer = pProgrammer; }
	void DoProgramming(string specification)
	{
		assert(m_pProgrammer != nullptr);
		m_pProgrammer->WriteProgram(specification);
	}
private:
	Programmer *m_pProgrammer;
};

int main()
{
	CPlusPlusProgrammer jill;
	JavaProgrammer van;

	Vendor1 myself;
	myself.DoProgramming("write a program to generate prime numbers");

	Vendor2 yourself;

	yourself.SetProgrammer(&van);
	yourself.DoProgramming("write a program to generate prime numbers");

	yourself.SetProgrammer(&jill);
	yourself.DoProgramming("write a program to generate prime numbers");

	return 0;
}

/*
• If a relationship can be expressed in more than one way,
  use the weakest relationship that's practical
• Inheritance is nearly the strongest relationship
• Composition has greater flexibility without affecting calling code
*/