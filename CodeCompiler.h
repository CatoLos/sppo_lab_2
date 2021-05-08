#pragma once
#include "IUnitGenerator.h"

class CodeCompiler
{
public:

    explicit CodeCompiler(const std::shared_ptr<IUnitGenerator>& UnitGen = nullptr);
    ~CodeCompiler();

    void setUnitGenerator(const std::shared_ptr<IUnitGenerator>& UnitGen);
    std::shared_ptr<IUnitGenerator> getUnitGenerator();

    std::string compile();

private:

    std::shared_ptr<IUnitGenerator> m_ugen;
};
