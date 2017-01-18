/* The file is part of Snowman decompiler. */
/* See doc/licenses.asciidoc for the licensing information. */

#include "DefaultDemangler.h"

#include <cstdlib>
#include <memory>
#include <folly/Conv.h>

#include <undname/undname.h>

extern "C" {
    /* Provided by libiberty. */
    char *__cxa_demangle(const char *mangled_name, char *output_buffer, size_t *length, int *status);
}

namespace nc {
namespace core {
namespace mangling {

namespace {

struct FreeDeleter {
    void operator()(void *ptr) const {
        free(ptr);
    }
};

folly::fbstring doDemangle(const char *symbol) {
    int status;
    if (auto output = std::unique_ptr<char[], FreeDeleter>(__cxa_demangle(symbol, nullptr, nullptr, &status))) {
        return output.get();// QLatin1String(output.get());
    }
    if (auto output = std::unique_ptr<char[], FreeDeleter>(__unDName(nullptr, symbol, 0, 0))) {
        /* __unDName returns the input string, if fails do demangle. */
        if (strcmp(output.get(), symbol)) {
            return  output.get();//QLatin1String(output.get());
        }
    }
    return folly::fbstring();
}

} // anonymous namespace

folly::fbstring DefaultDemangler::demangle(const folly::fbstring &symbol) const {
    auto byteArray = symbol;//.toLatin1();
    auto result = doDemangle(byteArray.data());//constData());
    std::string frontStr = folly::to<std::string>(symbol.front());

    if (result.empty()/*.isNull() */ && frontStr.compare(std::string("_")) == 0 ) {
        result = doDemangle(byteArray.data()+1);//.constData() + 1);
    }

    return result;
}

}}} // namespace nc::core::mangling

/* vim:set et sts=4 sw=4: */
