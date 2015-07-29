#ifndef UTILS_FLAG_HPP
#define UTILS_FLAG_HPP

#include "gflags/gflags.h"

namespace utils
{

	DECLARE_string(nrml_rocksdbpath);

	DECLARE_string(nrml_loggingpath);

	const std::string& rocksDBPath();

	const std::string& loggingPath();

}

#endif /* UTILS_FLAG_HPP */
