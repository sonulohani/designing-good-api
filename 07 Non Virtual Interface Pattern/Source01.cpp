#include <cassert>
#include <iostream>

class ReaderWriterLock
{
public:
	void acquire() const { /*acquire lock*/ }
	void release() const { /*release lock*/ }
};

struct SomeComplexDataType
{
	bool check_invariants() { return true; }

};

class Base {
private:
	ReaderWriterLock lock_;
	SomeComplexDataType data_;
public:
	void read_from(std::istream & i) // Note non-virtual
	{
		lock_.acquire();
		assert(data_.check_invariants());

		read_from_impl(i);

		assert(data_.check_invariants());
		lock_.release();
	}
	void write_to(std::ostream & o) const
	{
		lock_.acquire();
		write_to_impl(o);
		lock_.release();
	}
	virtual ~Base() {}
private:
	virtual void read_from_impl(std::istream &) = 0;
	virtual void write_to_impl(std::ostream &) const = 0;
};
class XMLReaderWriter : public Base
{
private:
	virtual void read_from_impl(std::istream &) override
	{
		// Read XML.
	}
	virtual void write_to_impl(std::ostream &) const override
	{
		// Write XML.
	}
};

class TextReaderWriter : public Base
{
private:
	virtual void read_from_impl(std::istream &) {}
	virtual void write_to_impl(std::ostream &) const {}
};

/*
• Consider making virtual functions nonpublic, and public functions nonvirtual
• Only if derived classes need to invoke the base implementation of a virtual function,
  make the virtual function protected
*/
