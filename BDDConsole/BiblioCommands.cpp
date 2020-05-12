#include "BiblioCommands.h"

std::regex BiblioCommands::m_regexCMDAddBook{"add (-B \".*\") | (-B \".*\" -A \".*\""};
std::regex BiblioCommands::m_regexCMDAddAuthor{ "add -A \".*\"" };
std::regex BiblioCommands::m_regexCMDListBook{"list -B"};
std::regex BiblioCommands::m_regexCMDListAuthor{"list -A"};
std::regex BiblioCommands::m_regexCMDFindBook{"find -B \".*\""};
std::regex BiblioCommands::m_regexCMDFindAuthor{ "find -A \".*\"" };