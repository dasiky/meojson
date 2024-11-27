#include <iostream>
#include <vector>
#include "json.h"
#include "json_array.h"
#include "json_parser.h"
using namespace std;
//using namespace json;
void test() {
    auto v = json::parser::parse(R"(  ["\u123"])");
    if (v.has_value())
        cout << v.value()[0].format() << endl;
}

class Test {
public:
    template <typename... Args>
    Test(Args&& ... args) {
        cout << sizeof...Args << endl;
        cout << sizeof...args << endl;
    }
};

int main()
{
    Test t = { {"1", 2}, {"2", "3"} };
    /*** Parse ***/
    {
        std::cout << "****** Parsing ****** " << std::endl;
        std::string content = R"(
        {
            "prject": {
                "name": "meojson",
                "list": [
                    1, 2, 3
                ]
            }
        }
        )";
        //std::cout << content << std::endl;

        auto ret = json::parser::parse(content);

        if (ret)
        {
            auto value = ret.value(); // As also, you can use rvalues, like `auto value = std::move(ret).value();`
            // Output "meojson"
            std::cout << value["prject"]["name"].as_string() << std::endl;
            // Output 2
            std::cout << value["prject"]["list"][1].as_integer() << std::endl;
        }
        else
        {
            std::cout << "parse failed" << std::endl;
        }
    }

    std::cout << std::endl;

    /*** Generate ***/
    {
        std::cout << "****** Generating ******" << std::endl;

        json::value json;
        json["hello"] = "meojson";
        json["Pi"] = 3.1416;

        json["arr"] = json::array(
            {"a", "b", "c"});
        json["obj"] = json::object(
            {{"obj_key1", "aaa"},
             {"obj_key2", 123},
             {"obj_key3", true}});
        json["obj_another"]["child"]["grand"] = "i am grand";

        // Output "{"obj_another":{"child":{"grand":"i am grand"}},"obj":{"obj_key3":true,"obj_key2":123,"obj_key1":"aaa"},"arr":["a","b","c"],"Pi":3.141600,"hello":"meojson"}"
        std::cout << json.to_string() << std::endl;

        std::cout << json.format() << std::endl;
    }

    std::cout << std::endl;

    return 0;
}
