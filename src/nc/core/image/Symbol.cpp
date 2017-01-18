/* The file is part of Snowman decompiler. */
/* See doc/licenses.asciidoc for the licensing information. */

#include "Symbol.h"

//#include <QObject>

#include <nc/common/Unreachable.h>

#include <folly/FBString.h>

namespace nc {
namespace core {
namespace image {

folly::fbstring SymbolType::getName(Type type) {
    switch (type) {
        case NOTYPE:
            return folly::fbstring("None");
        case FUNCTION:
            return folly::fbstring("Function");
        case OBJECT:
            return folly::fbstring("Object");
        case SECTION:
            return folly::fbstring("Section");
    }
    unreachable();
}

} // namespace image
} // namespace core
} // namespace nc

/* vim:set et sts=4 sw=4: */
