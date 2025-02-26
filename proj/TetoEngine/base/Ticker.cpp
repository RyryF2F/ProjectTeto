#include "TetoEngine/base/Ticker.hpp"

    teto::Ticker::Ticker()
    {

    }

    teto::Ticker::~Ticker()
    {

    }

    void teto::Ticker::start()
    {
        if (_isRunning) return;

        _isRunning = true;
        std::thread run(&Ticker::timer_loop, this);
        run.detach();
    }

    void teto::Ticker::stop()
    {
        _isRunning = false;
    }

    void teto::Ticker::setTPS(tick_interval_t newTPS)
    {
        _tickIntervalMutex.lock();
        _tickInterval = newTPS;
        _tickIntervalMutex.unlock();
    }

    void teto::Ticker::timer_loop()
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

    void teto::Ticker::setOnTick(const std::function<void(void)>& onTick)
    {
        if (_isRunning)
        {
            stop();
        }

        _tickIntervalMutex.lock();
        _onTick = onTick;
        _tickIntervalMutex.unlock();
    }