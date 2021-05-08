#include <iostream>
#include "CppUnitGenerator.h"
#include "CsUnitGenerator.h"
#include "JavaUnitGenerator.h"
#include "CodeCompiler.h"

int main()
{
    CodeCompiler CppCompiler(std::make_shared<CppUnitGenerator>());
    CodeCompiler CsCompiler(std::make_shared<CsUnitGenerator>());
    CodeCompiler JavaCompiler(std::make_shared<JavaUnitGenerator>());

    std::cout << CppCompiler.compile() << std::endl;
    std::cout << CsCompiler.compile() << std::endl;
    std::cout << JavaCompiler.compile() << std::endl;

    return 0;
}
