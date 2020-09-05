#include "libepd/libepd.hpp"

namespace libepd {
    EPaper::EPaper(GPIOManager& busy_pin, GPIOManager& reset_pin, SPIManager& spi, void (*delay)(int milliseconds)) {
        this->busy_pin = &busy_pin;
        this->reset_pin = &reset_pin;
        this->spi = &spi;
        this->delay = delay;
    }

    void EPaper::reset() {
        this->reset_pin->set(1);
        this->delay(200);
        this->reset_pin->set(0);
        this->delay(200);
        this->reset_pin->set(1);
    }
}