#include "CsUnits.h"

CsClassUnit::CsClassUnit(const std::string& name, Flags modifier) :
    ClassUnit(name, modifier)
{}

CsClassUnit::~CsClassUnit()
{}

std::string CsClassUnit::compile(unsigned int level) const
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
        result += "pprotected ";
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
                result += generateShift(level + 1) + ACCESS_MODIFIERS[i] + " " + f->compile();
        }
        result += "\n";
    }

    result += generateShift(level) + "};\n";

    return result;
}

CsMethodUnit::CsMethodUnit(const std::string& name,
    const std::string& returnType,
    Flags flags) :
    MethodUnit(name, returnType, flags)
{}

CsMethodUnit::~CsMethodUnit()
{}

std::string CsMethodUnit::compile(unsigned int level) const
{
    std::string result = generateShift(level);

    if (m_flags & STATIC)
        result += "static ";
    else if (m_flags & VIRTUAL)
        result += "virtual ";

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

CsPrintUnit::CsPrintUnit(const std::string& text) :
    PrintUnit(text)
{}

CsPrintUnit::~CsPrintUnit()
{}

std::string CsPrintUnit::compile(unsigned int level) const
{
    return generateShift(level) + "Console.WriteLine( \"" + m_text + "\" );\n";
}
