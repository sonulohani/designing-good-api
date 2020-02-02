#include <cstdio>
#include <sstream>

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
	//sprintf_s(buffer, size, "<?xml version=\"1.0\" encoding=\"utf-8\"?><data><i>%d</i></data>", m_integer.GetInteger());
	std::ostringstream s;
	s << "<?xml version=\"1.0\" encoding=\"utf-8\"?><data><i>%d</i></data>";
	std::string str = s.str();
	strcpy_s(buffer, size, str.c_str());
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

// A non-member function that invokes virtual function
void Print(IFormatter &formatter)
{
	const int bufferSize = 100;
	char buffer[bufferSize];
	formatter.Format(buffer, bufferSize);
	printf("%s\n", buffer);
}

int main()
{
	Integer u(5);

	XMLFormatter xmlFormatter(u);
	HTMLFormatter htmlFormatter(u);
	StringFormatter stringFormatter(u);

	Print(stringFormatter);
	Print(htmlFormatter);
	Print(xmlFormatter);

	return 0;
}

/*
• Open for extension, closed for modification
*/