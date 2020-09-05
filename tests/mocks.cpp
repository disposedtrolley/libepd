#include "libepd/libepd.hpp"

using namespace std;

namespace mocks {

class GPIOManager : public libepd::GPIOManager {
    vector<int> level_history{};

public:
    GPIOManager(){};

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


class SPIManager : public libepd::SPIManager {

public:
    SPIManager(){};

    void send(){}
};


void mock_delay(int milliseconds) {};
}

