#include "CsUnitGenerator.h"

CsUnitGenerator::CsUnitGenerator() {}
CsUnitGenerator::~CsUnitGenerator() {}

std::shared_ptr<ClassUnit> CsUnitGenerator::getClassUnit(std::string name, uint32_t modifier) const
{
    return std::make_shared< CsClassUnit >(name, modifier);
}

std::shared_ptr<MethodUnit> CsUnitGenerator::getMethodUnit(std::string name, std::string returnType,
    uint32_t flags) const
{
    return std::make_shared< CsMethodUnit >(name, returnType, flags);
}

std::shared_ptr<PrintUnit> CsUnitGenerator::getPrintUnit(std::string text) const
{
    return std::make_shared< CsPrintUnit >(text);
}
