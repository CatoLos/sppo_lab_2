#pragma once
#include "IUnitGenerator.h"
#include "CppUnits.h"

class CppUnitGenerator : public IUnitGenerator
{
public:

    explicit CppUnitGenerator();
    ~CppUnitGenerator();

    std::shared_ptr<ClassUnit> getClassUnit(std::string name, uint32_t modifier = ClassUnit::NONE) const override;

    std::shared_ptr<MethodUnit> getMethodUnit(std::string name, std::string returnType,
        uint32_t flags = MethodUnit::NONE) const override;

    std::shared_ptr<PrintUnit> getPrintUnit(std::string text) const override;
};
