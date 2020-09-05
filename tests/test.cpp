#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"
#include "libepd/libepd.hpp"
#include "mocks.cpp"

using namespace std;
using namespace libepd;


TEST_CASE("Test device reset") {
    mocks::GPIOManager reset_pin_mgr = mocks::GPIOManager();
    mocks::GPIOManager busy_pin_mgr = mocks::GPIOManager();
    mocks::SPIManager spi_mgr = mocks::SPIManager();

    EPaper epd = EPaper(busy_pin_mgr, reset_pin_mgr, spi_mgr, mocks::mock_delay);

    epd.reset();

    // Reset pin should be pulled back high after resetting.
    REQUIRE(reset_pin_mgr.get() == 1);

    // Reset pin should've been pulled low once.
    int count_low_states{0};
    for (int level : reset_pin_mgr.get_level_history()) {
        if (level == 0) count_low_states++;
    }
    REQUIRE(count_low_states == 1);
}