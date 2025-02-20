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

            void setOnTick(std::function<void(void)> onTick);

            void setTPS(tick_interval_t newTPS);


        private:

            void timer_loop();

            //int32_t _tickInterval = 20; //tps
            tick_interval_t _tickInterval;
            std::mutex _tickIntervalMutex; //tps locking
            std::atomic<bool> _isRunning;
            std::function<void(void)> _onTick; //ontick function
    };

    Ticker::Ticker()
    {

    }

    Ticker::~Ticker()
    {

    }

    void Ticker::start()
    {
        if (_isRunning) return;

        _isRunning = true;
        std::thread run(&Ticker::timer_loop, this);
        run.detach();
    }

    void Ticker::stop()
    {
        _isRunning = false;
    }

    void Ticker::setTPS(tick_interval_t newTPS)
    {
        _tickIntervalMutex.lock();
        _tickInterval = newTPS;
        _tickIntervalMutex.unlock();
    }

    void Ticker::timer_loop()
    {
        _tickIntervalMutex.lock(); //lock
        tick_interval_t tickInterval = _tickInterval; //safe
        while (_isRunning)
        {
            std::thread run(_onTick); //tick execution
            run.detach(); //bye

            std::this_thread::sleep_for(tickInterval);
            
        }

        _tickIntervalMutex.unlock(); //unlock
    }

    void Ticker::setOnTick(std::function<void(void)> onTick)
    {
        if (_isRunning)
        {
            stop();
        }

        _tickIntervalMutex.lock();
        _onTick = onTick;
        _tickIntervalMutex.unlock();
    }
}
