#ifndef LIBEPD_LIBEPD_H
#define LIBEPD_LIBEPD_H

namespace libepd {
    class SPIManager {
    public:
        virtual void send() = 0;
    };

    class GPIOManager {
    public:
        virtual void set(int logic_level) = 0;
        virtual int get() = 0;
    };

    class EPaper {
        GPIOManager *busy_pin;
        GPIOManager *reset_pin;
        SPIManager *spi;
        void (*delay)(int milliseconds);

    public:
        EPaper(GPIOManager& busy_pin,
               GPIOManager& reset_pin,
               SPIManager& spi,
               void (*delay)(int milliseconds));

        void reset();
    };
}

#endif //LIBEPD_LIBEPD_H
