
#include "config-loader/ConfigLoader.h"

namespace codegen {

/**
 * 模板生成样例
 */
struct Point {
    template<typename, size_t>
    struct FIELD;
    static constexpr size_t _field_count_ = 2;
    static constexpr decltype("Point") _schema_name_ = "Point";
    double x;

    template<typename T>
    struct FIELD<T, 0> {
        T &obj;

        FIELD(T &obj) : obj(obj) {}

        auto value() -> decltype(auto) {
            return (obj.x);
        }

        static constexpr const char *name() {
            return ("x");
        }
    };

    double y;

    template<typename T>
    struct FIELD<T, 0 + 1> {
        T &obj;

        FIELD(T &obj) : obj(obj) {}

        auto value() -> decltype(auto) {
            return (obj.y);
        }

        static constexpr const char *name() {
            return ("y");
        }
    };
};


}
