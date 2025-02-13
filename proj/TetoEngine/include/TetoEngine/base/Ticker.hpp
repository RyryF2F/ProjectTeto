#pragma once

#include <chrono>
#include <thread>
#include <atomic>
#include <functional>
#include <mutex>

/**
 * Timer for handling ticks within game
 * hopefully threaded
 */
namespace teto
{
    class Ticker
    {
        public:
            typedef std::chrono::duration<int64_t, std::nano> tick_interval_t;
            typedef std::function<void()> on_tick_t;

            ///////////////
  
            Ticker (std::function<void()> onTick, std::chrono::duration<int64_t, std::nano> tickInterval) 
            : _onTick (onTick)
            , _tickInterval (tickInterval)
            , _running (false) {}

            ~Ticker(){};

            ///////////////////

            void start () 
            {
                if (_running) return;


                _running = true;
                std::thread run(&Ticker::timer_loop, this);
                run.detach();
            }

            void stop () 
            { 
                _running = false; 
            }

            void setDuration(std::chrono::duration<int64_t, std::nano> tickInterval)
            {
                _tickIntervalMutex.lock();
                _tickInterval = tickInterval;
                _tickIntervalMutex.unlock();
            }
    
        private:
            void timer_loop()
            {
                while (_running) 
                {
                    std::thread run(_onTick );
                    run.detach();

                    _tickIntervalMutex.lock();
                    std::chrono::duration<int64_t, std::nano> tickInterval = _tickInterval;
                    _tickIntervalMutex.unlock();
                    std::this_thread::sleep_for( tickInterval );
                }
            }

            std::atomic<bool> _running;
            on_tick_t         _onTick;
            tick_interval_t   _tickInterval;
            std::mutex        _tickIntervalMutex;
    };
}
