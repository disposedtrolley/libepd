#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"
#include "libepd/libepd.hpp"

using namespace std;
using namespace libepd;

class MockResetPinManager : public GPIOManager {
    vector<int> level_history{};

public:
    MockResetPinManager(){};

    void set(int logic_level) {
        this->level_history.push_back(logic_level);
    }

    int get() {
        return this->level_history[this->level_history.size() - 1];
    }

    vector<int> get_level_history() {
        return this->level_history;
    }
};

void mock_delay(int milliseconds) {};

TEST_CASE("Test device reset") {
    MockResetPinManager reset_pin_mgr = MockResetPinManager();

    EPaper epd = EPaper(nullptr, &reset_pin_mgr, nullptr, mock_delay);

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