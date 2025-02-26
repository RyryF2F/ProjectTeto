#include "TetoEngine/base/Tickable.hpp"

teto::Tickable::Tickable()
{
    
}

teto::Tickable::~Tickable()
{
    _isRunning = false;
}

void teto::Tickable::startTicking()
{
    if (_isRunning)
    {
        TraceLog(LOG_INFO, "Failed to start ticking tickable.");
    }

    //std::thread run(&Tickable::tickLoop, std::reference_wrapper<Tickable>(this));
    std::thread run([this] () { this->tickLoop(); });
    run.detach();
}

void teto::Tickable::stopTicking()
{
    _isRunning = false;
}

void teto::Tickable::setTickInterval(tick_interval_t newTPS)
{
    if (_tickIntervalMutex.try_lock())
    {
        _tickInterval = newTPS;
        _tickIntervalMutex.unlock();
    }else
    {
        TraceLog(LOG_WARNING, "Failed to unlock a ticking mutex to change tick interval.");
    }
}

void teto::Tickable::tickLoop()
{
    if (_tickIntervalMutex.try_lock())
    {
        tick_interval_t tickInterval = _tickInterval;
        //Tickable const& tickable = _tickable;
        while (_isRunning)
        {
            //std::thread run(&Tickable::onTick, tickable);
            std::thread run([this] () { this->onTick(); });
            run.detach();
            std::this_thread::sleep_for(tickInterval);
        }
    }else
    {
        TraceLog(LOG_INFO, "Failed to lock new tick loop thread.");
    }
}