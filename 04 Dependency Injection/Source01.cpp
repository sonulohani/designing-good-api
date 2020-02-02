#include <cstdio>
#include <fstream>
using namespace std;

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

class IFormatter
{
public:
	virtual void Format(char *buffer, int size) = 0;
};

class XMLFormatter : public IFormatter
{
public:
	XMLFormatter(const Integer &integer);
public:
	virtual void Format(char *buffer, int size);
private:
	const Integer &m_integer;
};

XMLFormatter::XMLFormatter(const Integer &integer) : m_integer(integer)
{

}

void XMLFormatter::Format(char *buffer, int size)
{
	sprintf_s(buffer, size, "<?xml version=\"1.0\" encoding=\"utf-8\"?><data><i>%d</i></data>", m_integer.GetInteger());
}

class HTMLFormatter : public IFormatter
{
public:
	HTMLFormatter(const Integer &integer);
public:
	virtual void Format(char *buffer, int size);
private:
	const Integer &m_integer;
};

HTMLFormatter::HTMLFormatter(const Integer &integer) : m_integer(integer)
{

}

void HTMLFormatter::Format(char *buffer, int size)
{
	sprintf_s(buffer, size, "<html><body><b>i</b>=%d</body></html>", m_integer.GetInteger());
}

class StringFormatter : public IFormatter
{
public:
	StringFormatter(const Integer &integer);
public:
	virtual void Format(char *buffer, int size);
private:
	const Integer &m_integer;
};

StringFormatter::StringFormatter(const Integer &integer) : m_integer(integer)
{

}

void StringFormatter::Format(char *buffer, int size)
{
	sprintf_s(buffer, size, "i=%d", m_integer.GetInteger());
}

void WriteToFile(IFormatter &formatter, const char *pOutputFileName)
{
	const int bufferSize = 100;
	char buffer[bufferSize];
	formatter.Format(buffer, bufferSize);
	ofstream fout(pOutputFileName);
	fout << buffer;
	fout.close();
}

int main()
{
	Integer u(5);

	XMLFormatter xmlFormatter(u);
	HTMLFormatter htmlFormatter(u);
	StringFormatter stringFormatter(u);

	WriteToFile(stringFormatter, "integer.txt");
	WriteToFile(htmlFormatter, "integer.html");
	WriteToFile(xmlFormatter, "integer.xml");

	return 0;
}