#include <iostream>
#include "CppUnitGenerator.h"

std::string generateProgram(const std::shared_ptr<IUnitGenerator>& generator)
{
    auto classUnit = generator->getClassUnit("MyClass", ClassUnit::PUBLIC);

    auto functionUnit1 = generator->getMethodUnit("testFunc1", "void");
    classUnit->add(functionUnit1, ClassUnit::PUBLIC);

    auto functionUnit2 = generator->getMethodUnit("testFunc2", "void", MethodUnit::STATIC);
    classUnit->add(functionUnit2, ClassUnit::PRIVATE);

    auto functionUnit3 = generator->getMethodUnit("testFunc3", "void", MethodUnit::VIRTUAL | MethodUnit::CONST);
    classUnit->add(functionUnit3, ClassUnit::PUBLIC);

    auto functionUnit4 = generator->getMethodUnit("testFunc4", "void", MethodUnit::STATIC);
    auto printUnit = generator->getPrintUnit(R"(Hello, world!\n)");

    functionUnit4->add(printUnit);

    classUnit->add(functionUnit4, ClassUnit::PROTECTED);

    return classUnit->compile();
}

int main()
{
    std::cout << generateProgram(std::make_shared<CppUnitGenerator>());
    return 0;
}
