/* The file is part of Snowman decompiler. */
/* See doc/licenses.asciidoc for the licensing information. */

#include "StringToInt.h"
#include <folly/Conv.h>

namespace nc {

/*
namespace {

#define NC_CONVERSION_TABLE(CONVERSION)         \
    CONVERSION(toInt, int)                      \
    CONVERSION(toUInt, unsigned int)            \
    CONVERSION(toLong, long)                    \
    CONVERSION(toULong, unsigned long)          \
    CONVERSION(toLongLong, long long)           \
    CONVERSION(toULongLong, unsigned long long)

#define NC_CONVERSION_FUNCTION(METHOD, TYPE)                            \
    inline bool stringToInt(const folly::fbstring &s, int base, TYPE &result) { \
        bool ok;                                                        \
        result = s.METHOD(&ok, base);                                   \
        return ok;                                                      \
    }

NC_CONVERSION_TABLE(NC_CONVERSION_FUNCTION)

} // anonymous namespace
*/

template<class T>
boost::optional<T>
stringToInt(const folly::fbstring &s, int base) {
/*
    T result;
    if (stringToInt(s, base, result)) {
        return result;
    }
    return boost::none;
*/
 return folly::to<T>(s);
}

/*
#define NC_CONVERSION_INSTANTIATION(METHOD, TYPE) \
    template boost::optional<TYPE> stringToInt(const folly::fbtring &, int);

NC_CONVERSION_TABLE(NC_CONVERSION_INSTANTIATION)
*/
} // namespace nc

/* vim:set et sts=4 sw=4: */
