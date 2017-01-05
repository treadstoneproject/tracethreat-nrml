#include "Flags.hpp"

namespace utils
{
    DEFINE_string(nrml_rocksdbpath,"",
            "RocksDB database file path in formath dirv/rocksdb_file");


    DEFINE_string(nrml_loggingpath,"",
            "Loggin path write file");

    const std::string& rocksDBPath()
    {
        return FLAGS_nrml_rocksdbpath;
    }

    const std::string& loggingPath()
    {
        return FLAGS_nrml_loggingpath;
    }

}


