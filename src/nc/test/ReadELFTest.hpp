#include <gtest/gtest.h>


#include <nc/core/Driver.h>
#include <nc/core/Context.h>

class ReadELFTest : public testing::Test
{

    public:

        nc::core::Context context;
};

TEST_F(ReadELFTest, simple_read_elf)
{
    folly::fbstring filename("/home/rchatsiri/workspacereverseengineer/android-file");
    nc::core::Driver::parse(context, filename);
}
