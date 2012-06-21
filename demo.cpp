#include <iostream>

#include "entity.h"
#include "component.h"

using namespace std;

class A : public Component
{
	public:
		A() : a(42) {}
		int a;
		void cake()
		{
			cout << "A" << endl;
		}
};

class B : public Component
{
	public:
		void pie()
		{
			cout << "B" << endl;
			cout << entity->getComponent<A>()->a << endl;
		}
};

int main(int argc, const char *argv[])
{
	Entity e;
	e.addComponent<A>();
	e.addComponent<B>();
	e.getComponent<A>()->cake();
	e.getComponent<B>()->pie();
}
