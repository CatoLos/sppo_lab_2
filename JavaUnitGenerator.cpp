#include "JavaUnitGenerator.h"

JavaUnitGenerator::JavaUnitGenerator() {}
JavaUnitGenerator::~JavaUnitGenerator() {}

std::shared_ptr<ClassUnit> JavaUnitGenerator::getClassUnit(std::string name, uint32_t modifier) const
{
    return std::make_shared< JavaClassUnit >(name, modifier);
}

std::shared_ptr<MethodUnit> JavaUnitGenerator::getMethodUnit(std::string name, std::string returnType, uint32_t flags) const
{
    return std::make_shared< JavaMethodUnit >(name, returnType, flags);
}

std::shared_ptr<PrintUnit> JavaUnitGenerator::getPrintUnit(std::string text) const
{
    return std::make_shared< JavaPrintUnit >(text);
}
