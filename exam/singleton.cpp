# include <iostream>
# include <memory>

using namespace std;

template <typename T>
class Singleton
{
public:
	static T& instance()
	{
		static unique_ptr<T> MyInst = make_unique<T>();
		return *MyInst;
	}

	Singleton(const Singleton<T>&) = delete;
	Singleton<T>& operator=(const Singleton<T>&) = delete;
private:
	Singleton() = default;
};

// --------------------------------------------------------------------------------------------------

class Product
{
public:
	static shared_ptr<Product> instance()
	{
		class Proxy : public Product {};

		static shared_ptr<Product> myInstance = make_shared<Proxy>();

		return myInstance;
	}
	~Product() { cout << "Calling the destructor;" << endl; }

	void f() { cout << "Method f;" << endl; }

	Product(const Product&) = delete;
	Product& operator =(const Product&) = delete;

private:
	Product() { cout << "Calling the default constructor;" << endl; }
};

int main()
{
	shared_ptr<Product> ptr(Product::instance());

	ptr->f();
}
