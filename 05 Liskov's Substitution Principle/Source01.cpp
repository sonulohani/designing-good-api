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

#pragma region Integer Implementation

Integer::Integer(int i) : m_i(i)
{

}

int Integer::GetInteger() const
{
	return m_i;
}

#pragma endregion

class IntegerFactory
{
public:
	Integer* CreateInteger(int i);
public:
	static IntegerFactory* GetInstance();
private:
	IntegerFactory() {}
private:
	static IntegerFactory *m_pIntegerFactory;
};

#pragma region IntegerFactory Implementation

IntegerFactory *IntegerFactory::m_pIntegerFactory = nullptr;

Integer* IntegerFactory::CreateInteger(int i)
{
	return new Integer(i);
}

IntegerFactory* IntegerFactory::GetInstance()
{
	if (m_pIntegerFactory == nullptr)
		m_pIntegerFactory = new IntegerFactory();
	return m_pIntegerFactory;
}

#pragma endregion

int main()
{
	IntegerFactory *pintFactory = IntegerFactory::GetInstance();
	Integer *pint = pintFactory->CreateInteger(5);
	int i = pint->GetInteger();
	delete pint; pint = nullptr;
	return 0;
}