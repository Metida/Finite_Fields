template<int N>
class Foo {

    int data;

public:
    Foo(int data) : data(data) {}

    template<int M>
    friend
    void f(Foo<M> const &) {}
};

int main()
{
    Foo<4> a(42);
    f(a);


    Foo<6> b(43);
    f(b);
}
