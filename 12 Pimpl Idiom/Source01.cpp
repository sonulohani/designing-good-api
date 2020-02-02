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

int main()
{
	Integer u(5);
	int i = u.GetInteger();
	return 0;
}