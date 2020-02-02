#include <cstdio>

class Integer
{
public:
	Integer(int i);
public:
	int GetInteger() const;
private:
	int m_i;
};

Integer::Integer(int i) : m_i(i)
{

}

int Integer::GetInteger() const
{
	return m_i;
}

class Convert
{
public:
	void ToHTML(char *buffer, int size, const Integer &integer);
	void ToString(char *buffer, int size, const Integer &integer);
};

void Convert::ToHTML(char *buffer, int size, const Integer &integer)
{
	sprintf_s(buffer, size, "<html><body><b>i</b>=%d</body></html>", integer.GetInteger());
}

void Convert::ToString(char *buffer, int size, const Integer &integer)
{
	sprintf_s(buffer, size, "i=%d", integer.GetInteger());
}

int main()
{
	Integer u(5);
	const int bufferSize = 64;
	char buffer[bufferSize];

	Convert convert;

	convert.ToString(buffer, bufferSize, u);
	printf("%s\n", buffer);

	convert.ToHTML(buffer, bufferSize, u);
	printf("%s\n", buffer);

	return 0;
}

/*
• Give one entity one cohesive responsibility
• A class should have only one reason to change.
*/