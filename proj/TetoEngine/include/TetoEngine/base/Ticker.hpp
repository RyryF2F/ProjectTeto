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

    template <int32_t tps>
    using tps_duration = std::chrono::duration<int32_t, std::ratio<1,tps>>;


    template <int32_t tps = 20>
    class Ticker
    {
        public:
            //typedefs
            typedef std::function<void()> on_tick_t;

            //cpp td
            //using tps_t = std::chrono::duration<int, std::ratio<tps,60>>;

            //constructors
            Ticker (std::function<void()> onTick) : _onTick(onTick) , _isRunning(false) {}
            ~Ticker(){};

            /////////////

            void start()
            {
                if (_isRunning) return;

                _isRunning = true;
                std::thread run(&Ticker::timer_loop, this);
                run.detach();
            }

            void stop()
            {
                _isRunning = false;
            }

            void setTPS(int newTPS)
            {
                _tickIntervalMutex.lock();
                tps = newTPS;
                _tickIntervalMutex.unlock();
            }

        private:

            void timer_loop()
            {
                while (_isRunning)
                {
                    std::thread run(_onTick); //tick time
                    run.detach();

                    _tickIntervalMutex.lock();
                    tps_t _tps = tps; //this should be right...?
                    _tickIntervalMutex.unlock();
                    std::this_thread::sleep_for(_tps);
                }
            }

            std::atomic<bool> _isRunning;
            on_tick_t _onTick;
            std::mutex _tickIntervalMutex;
            //int64_t _tpsd;
            tps_duration<tps> _tickInterval;
            
    };
}
