#pragma once

#include <string>

namespace json
{
    class object;
    class array;

    class value
    {
    public:
        value() = default;
        value(const value &rhs) = default;
        value(const json::object &obj);
        value(const json::array &arr);

        ~value() = default;

        bool parse(const std::string &content);
        bool valid() const;

        int as_int() const;
        double as_double() const;
        std::string as_string() const;
        object as_object() const;
        array as_array() const;

        std::string to_string() const;

        static json::value string(const char *str);
        static json::value string(const std::string &str);
        static json::value number(int num);
        static json::value number(double num);
        static json::value boolean(bool b);
        //static json::value object(const json::object &obj);
        //static json::value array(const json::array &arr);
        static json::value null();

    private:
        std::string m_raw;
        bool m_valid = true;
    };
} // namespace json