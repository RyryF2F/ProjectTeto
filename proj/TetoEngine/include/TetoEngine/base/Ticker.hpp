#pragma once

#include <chrono>
#include <thread>
#include <atomic>
#include <functional>
#include <mutex>
#include <ratio>

/**
 * Timer for handling ticks within game

 */
namespace teto
{

    //template <int32_t tps>
    //using tps_duration = std::chrono::duration<double, std::ratio<1,20>>;
    using tick_interval_t = std::chrono::duration<int32_t, std::milli>; //e.g. 50ms is 20tps

    class Ticker
    {
        public:
            //typedef std::function<void()> on_tick_t;

            Ticker();

            ~Ticker();

            void start();

            void stop();

            void setOnTick(const std::function<void()>& onTick);

            void setTPS(tick_interval_t newTPS);


        private:

            void timer_loop();

            //int32_t _tickInterval = 20; //tps
            tick_interval_t _tickInterval;
            std::mutex _tickIntervalMutex; //tps locking
            std::atomic<bool> _isRunning;
            std::function<void(void)> _onTick; //ontick function
    };
}
