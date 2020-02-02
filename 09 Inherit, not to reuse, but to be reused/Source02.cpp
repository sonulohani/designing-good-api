#include <cassert>

class IRectangle
{
public:
	virtual unsigned GetHeight() const = 0;
	virtual unsigned GetWidth() const = 0;
	virtual void SetHeight(unsigned height) = 0;
	virtual void SetWidth(unsigned width) = 0;
};

class Rectangle : public IRectangle
{
public:
	Rectangle() : m_height(0), m_width(0) {}
public:
	unsigned GetHeight() const { return m_height; }
	unsigned GetWidth() const { return m_width; }
	void SetHeight(unsigned height) { m_height = height; }
	void SetWidth(unsigned width) { m_width = width; }
public:
	int GetArea() { return m_height * m_width; }
private:
	unsigned m_height;
	unsigned m_width;
};

class Square
{
public:
	void SetHeight(unsigned height)
	{
		m_r.SetHeight(height);
		m_r.SetWidth(height);
	}
	void SetWidth(unsigned width)
	{
		m_r.SetHeight(width);
		m_r.SetWidth(width);
	}
public:
	int GetArea() { return m_r.GetHeight() * m_r.GetHeight(); }
private:
	Rectangle m_r;
};

class RectangleTest
{
public:
	void TestRectangleArea(Rectangle &r)
	{
		r.SetHeight(5);
		r.SetWidth(6);
		int expectedArea = 30;
		assert(expectedArea == r.GetArea());
	}
};

class SquareTest
{
public:
	void TestSqaureArea(Square &s)
	{
		s.SetHeight(5);
		int expectedArea = 25;
		assert(expectedArea == s.GetArea());
	}
};

int main()
{
	Rectangle r;
	Square s;

	RectangleTest rectangleTest;
	rectangleTest.TestRectangleArea(r);

	SquareTest squareTest;
	squareTest.TestSqaureArea(s);

	return 0;
}

/*
Public inheritance is substitutability
Inherit, not to reuse, but to be reused

*/