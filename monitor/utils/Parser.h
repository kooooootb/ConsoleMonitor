#ifndef MONITOR_PARSER_H
#define MONITOR_PARSER_H

#include <vector>
#include <map>
#include <string>

using posArgs_t = std::vector<std::string>;
using keyArgs_t = std::map<std::string, int>;
using boolArgs_t = std::vector<std::string>;

class Parser{
private:
    posArgs_t posArgs;
    keyArgs_t keyArgs;

    void parseInput(const std::string &input);

protected:
    /**
     * Функция выделяет слово начинающееся с данного индекса в данной строке
     * @param input данная строка
     * @param index данный индекс
     * @return подстрока
     */
    static std::string parseWord(const std::string &input, size_t &index);
    /**
     * Выделяет ключ из строки
     * @param input входная строка с ключом
     * @param index индекс символа содержащего первый символ '-'
     * @return выделенный ключ
     */
    static keyArgs_t::key_type parseKey(const std::string &input, size_t &index);
    /**
     * Выделяет значение ключа из строки и перевод его в целочисленное значение
     * @param input входная строка со значением
     * @param index индекс символа содержащего первый символ значения
     * @return выделенное значение
     * @throw ParseException при переполнении целочисленного типа или при невозможности преобразовать строку в число
     */
    static keyArgs_t::mapped_type parseKeyValue(const std::string &input, size_t &index);
public:
    explicit Parser(const std::string &input);

    const keyArgs_t &getKeyArgs() const { return keyArgs; }
    keyArgs_t &getKeyArgs() { return keyArgs; }
    const posArgs_t &getPosArgs() const { return posArgs; }
    posArgs_t &getPosArgs() { return posArgs; }
};

#endif //MONITOR_PARSER_H
