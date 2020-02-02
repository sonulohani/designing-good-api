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

class Format
{
public:
	static void ToXML(char *buffer, int size, const Integer &integer);
	static void ToHTML(char *buffer, int size, const Integer &integer);
	static void ToString(char *buffer, int size, const Integer &integer);
};

void Format::ToXML(char *buffer, int size, const Integer &integer)
{
	sprintf_s(buffer, size, "<?xml version=\"1.0\" encoding=\"utf-8\"?><data><i>%d</i></data>", integer.GetInteger());
}

void Format::ToHTML(char *buffer, int size, const Integer &integer)
{
	sprintf_s(buffer, size, "<html><body><b>i</b>=%d</body></html>", integer.GetInteger());
}

void Format::ToString(char *buffer, int size, const Integer &integer)
{
	sprintf_s(buffer, size, "i=%d", integer.GetInteger());
}

int main()
{
	Integer u(5);
	const int bufferSize = 100;
	char buffer[bufferSize];

	Format::ToString(buffer, bufferSize, u);
	printf("%s\n", buffer);

	Format::ToHTML(buffer, bufferSize, u);
	printf("%s\n", buffer);

	Format::ToXML(buffer, bufferSize, u);
	printf("%s\n", buffer);

	return 0;
}