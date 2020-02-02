#include <cstdio>
#include <typeinfo>

class NotImplementedException
{};

class IRTTI
{
public:
	virtual const type_info& GetType() = 0;
};

class IClonnable
{
public:
	virtual void* Clone() = 0;
};

class Integer : public IRTTI, public IClonnable
{
public:
	Integer(int i);
public:
	int GetInteger() const;
public:
	const type_info& GetType();
public:
	void* Clone();
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

const type_info& Integer::GetType()
{
	return typeid(*this);
}

void* Integer::Clone()
{
	return new Integer(m_i);
}

#pragma endregion

class IntegerFactory : public IRTTI
{
public:
	Integer* CreateInteger(int i);
public:
	static IntegerFactory* GetInstance();
private:
	IntegerFactory() {}
public:
	const type_info& GetType();
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

const type_info& IntegerFactory::GetType()
{
	return typeid(*this);
}

#pragma endregion


int main()
{
	IntegerFactory *pintFactory = IntegerFactory::GetInstance();
	const type_info &intfactory_typeinfo = pintFactory->GetType();
	printf("%s\n", intfactory_typeinfo.name());

	Integer *pint = pintFactory->CreateInteger(5);
	int i = pint->GetInteger();
	const type_info &int_typeinfo = pint->GetType();
	printf("%s\n", int_typeinfo.name());

	Integer *pint2 = static_cast<Integer*>(pint->Clone());
	int j = pint2->GetInteger();
	const type_info &int_typeinfo2 = pint2->GetType();
	printf("%s\n", int_typeinfo2.name());

	delete pint; pint = nullptr;
	delete pint2; pint2 = nullptr;
	return 0;
}

/*
• Clients should not be forced to depend upon interfaces that they don't use.
*/