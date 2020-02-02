struct IntegerImpl;

class Integer
{
public:
	Integer(int i);
	~Integer();
public:
	int GetInteger() const;
private:
	IntegerImpl *m_pIntegerImpl;
};

#pragma region Integer Implementation

struct IntegerImpl
{
	int m_i;
};

Integer::Integer(int i)
{
	m_pIntegerImpl = new IntegerImpl();
	m_pIntegerImpl->m_i = i;
}

Integer::~Integer()
{
	delete m_pIntegerImpl;
	m_pIntegerImpl = nullptr;
}

int Integer::GetInteger() const
{
	return m_pIntegerImpl->m_i;
}

#pragma endregion

int main()
{
	Integer u(5);
	int i = u.GetInteger();
	return 0;
}