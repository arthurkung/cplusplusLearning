int foo()
{
    return 5;
}

int goo()
{
    return 6;
}
double hoo(int x)
{
    return 7;
}

int main()
{

    {
        int (*fcnPtr)() { &foo };   // fcnPtr points to function foo
        fcnPtr = &goo;              // fcnPtr now points to function goo
    }
    {
        double (*fcnPtr)(int) { &hoo };

        // explicit dereference
        (*fcnPtr)(5); // call function hoo(5) through fcnPtr3.

        // implicit dereference
        fcnPtr(5);
    }
    

    return 0;
}