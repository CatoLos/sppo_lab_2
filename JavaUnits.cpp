#include "JavaUnits.h"

JavaClassUnit::JavaClassUnit(const std::string& name, Flags modifier) :
    ClassUnit(name, modifier)
{}

JavaClassUnit::~JavaClassUnit()
{}

std::string JavaClassUnit::compile(unsigned int level) const
{
    std::string result = generateShift(level);

    switch (m_modifier)
    {
    case ClassUnit::PUBLIC:
        result += "public ";
        break;
    case ClassUnit::PRIVATE:
        result += "private ";
        break;
    case ClassUnit::PROTECTED:
        result += "protected ";
        break;
    }

    result += "class " + m_name + " {\n";

    for (size_t i = 0; i < ACCESS_MODIFIERS.size(); ++i)
    {
        if (m_fields[i].empty())
            continue;

        for (const auto& f : m_fields[i])
        {
            if (f)
                result += generateShift(level + 1) + ACCESS_MODIFIERS[i] + " " + f->compile(0);
        }
        result += "\n";
    }

    result += generateShift(level) + "};\n";

    return result;
}

JavaMethodUnit::JavaMethodUnit(const std::string& name,
    const std::string& returnType,
    Flags flags) :
    MethodUnit(name, returnType, flags)
{}

JavaMethodUnit::~JavaMethodUnit()
{}

std::string JavaMethodUnit::compile(unsigned int level) const
{
    std::string result = generateShift(level);

    if (m_flags & STATIC)
    {
        result += "static ";
    }

    result += m_returnType + " ";
    result += m_name + "()";
    result += " {\n";

    for (const auto& b : m_body)
    {
        if (b)
            result += b->compile(level + 2);
    }

    result += generateShift(level + 1) + "}\n";

    return result;
}

JavaPrintUnit::JavaPrintUnit(const std::string& text) :
    PrintUnit(text)
{}

JavaPrintUnit::~JavaPrintUnit()
{}

std::string JavaPrintUnit::compile(unsigned int level) const
{
    return generateShift(level) + "System.out.println( \"" + m_text + "\" );\n";
}
