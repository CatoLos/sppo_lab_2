#include "CodeCompiler.h"


CodeCompiler::CodeCompiler(const std::shared_ptr<IUnitGenerator>& UnitGen):
    m_ugen(UnitGen)
{}

CodeCompiler::~CodeCompiler()
{}

void CodeCompiler::setUnitGenerator(const std::shared_ptr<IUnitGenerator>& UnitGen)
{
    m_ugen = UnitGen;
}

std::shared_ptr<IUnitGenerator> CodeCompiler::getUnitGenerator()
{
    return m_ugen;
}

std::string CodeCompiler::compile()
{
    auto classUnit = m_ugen->getClassUnit("MyClass", ClassUnit::PUBLIC);

    auto functionUnit1 = m_ugen->getMethodUnit("testFunc1", "void");
    classUnit->add(functionUnit1, ClassUnit::PUBLIC);

    auto functionUnit2 = m_ugen->getMethodUnit("testFunc2", "void", MethodUnit::STATIC);
    classUnit->add(functionUnit2, ClassUnit::PRIVATE);

    auto functionUnit3 = m_ugen->getMethodUnit("testFunc3", "void", MethodUnit::VIRTUAL | MethodUnit::CONST);
    classUnit->add(functionUnit3, ClassUnit::PUBLIC);

    auto functionUnit4 = m_ugen->getMethodUnit("testFunc4", "void", MethodUnit::STATIC);
    auto printUnit = m_ugen->getPrintUnit(R"(Hello, world!\n)");

    functionUnit4->add(printUnit);

    classUnit->add(functionUnit4, ClassUnit::PROTECTED);

    return classUnit->compile();
}


