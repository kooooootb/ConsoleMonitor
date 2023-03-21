#ifndef MAIN_UTILFUNCTIONS_H
#define MAIN_UTILFUNCTIONS_H

/**
 * Название файла с сообщениями помощи
 */
static constexpr char HELPFILENAME[] = "help.txt";

/**
 * Функция проверяет является ли входной символ пробелом или другим пропускаемым знаком (символ табуляции)
 * @param symbol входной символ
 * @return true если входной символ - пропускаемый знак, false - otherwise
 */
bool isWhitespace(char symbol);

/**
 * Функция печатает сообщение помощи для данного индекса
 * Нумерация сообщений происходит с помощью перенумерования BaseCommand::Commands (COMMANDSAMOUNT выводит информацию о мониторе)
 * @return поток вывода
 */
std::ostream &showHelp(std::ostream &ostream, int index);

/**
 * Преобразует символы в строке в нижний регистр
 * @param text строка
 */
void toLower(std::string &text);

#endif //MAIN_UTILFUNCTIONS_H
