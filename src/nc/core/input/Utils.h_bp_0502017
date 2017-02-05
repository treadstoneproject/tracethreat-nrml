/* The file is part of Snowman decompiler. */
/* See doc/licenses.asciidoc for the licensing information. */

#pragma once

#pragma once

//#include <nc/config.h>

//#include <std::ifstream>
//#include <folly::fbstring>

#include <fstream>
#include <folly/FBString.h>

#include <nc/common/CheckedCast.h>

namespace nc {
namespace core {
namespace input {

template <class T>
bool read(std::ifstream *source, T &obj, std::size_t count = 1) {
    std::size_t size = sizeof(obj) * count;
    //return checked_cast<std::size_t>(source->read(reinterpret_cast<char *>(&obj), size)) == size;
    source->read(reinterpret_cast<char*>(&obj), sizeof(obj));
    return (sizeof(obj) * count) == size;    
    //return ;
}

template <std::size_t size>
folly::fbstring getAsciizString(const char (&buffer)[size]) {
    return folly::fbstring();//::fromLatin1(buffer, qstrnlen(buffer, size));
}

inline folly::fbstring getAsciizString(const std::vector<unsigned char> &bytes, std::size_t offset = 0) {
    if (offset < checked_cast<std::size_t>(bytes.size())) {
        return folly::fbstring();
       
                /* ::fromLatin1(bytes.data() + offset,
                                   qstrnlen(bytes.data() + offset, checked_cast<int>(bytes.size() - offset))); */
    } else {
        return folly::fbstring();
    }
}
}}} // namespace nc::core::input

/* vim:set et sts=4 sw=4: */
