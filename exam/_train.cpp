#include <iostream>
#include <memory>

using namespace std;

template <typename T>
concept Abstract = is_abstract_v<T>;

template <typename T>
concept NotAbstract = !is_abstract_v<T>;

template <typename Tprod, typename ...Args>
concept Constructible = constructible_from<Tprod, Args...>;

template <typename Tbase, typename Tprod>
concept Derived = derived_from<Tprod, Tbase>;



class Product;

template <Abstract Tbase, typename ...Args>
class Creator
{
public:
    virtual ~Creator() = default;
    virtual unique_ptr<Tbase> CreateProduct(Args&&... a) = 0;
};

template <typename Tbase, typename Tprod, typename ...Args>
requires Abstract<Tbase> && NotAbstract<Tprod> && Derived<Tbase, Tprod> && Constructible<Tprod, Args...>
class ConCreator1: public Creator<Tbase, Args...>
{
public:
    virtual unique_ptr<Tbase> CreateProduct(Args&&... a) override
    {
        return make_unique<Tprod>(forward<Args>(a)...);
    }
};

class Product
{
public:
    virtual ~Product() = 0;
};
Product::~Product() = default;

class ConProd1: public Product
{
    int i;
    double d;
public:
    virtual ~ConProd1() override {};
    ConProd1(int i, double d): i(i), d(d) {}
};

int main(void)
{
    shared_ptr<Creator<Product, int, double>> cr = make_shared<ConCreator1<Product, ConProd1, int, double>>();
    unique_ptr<Product> p = cr->CreateProduct(1, 2.);
}
