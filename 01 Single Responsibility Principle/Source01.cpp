#include <cstdio>

class Integer
{
public:
	Integer(int i);
public:
	void ToString(char *buffer, int size);
private:
	int m_i;
};

Integer::Integer(int i) : m_i(i)
{

}

void Integer::ToString(char *buffer, int size)
{
	sprintf_s(buffer, size, "i=%d", m_i);
}

int main()
{
	Integer u(5);
	const int bufferSize = 64;
	char buffer[bufferSize];

	u.ToString(buffer, bufferSize);
	printf("%s\n", buffer);

	return 0;
}