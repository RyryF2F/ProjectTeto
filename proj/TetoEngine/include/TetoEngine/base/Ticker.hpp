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
    template <int64_t tps = 20>
    class Ticker
    {
        public:
            //typedefs
            typedef std::function<void()> on_tick_t;

            //cpp td
            using tps_t = std::chrono::duration<int64_t, std::ratio<tps,60>>;

            //constructors
            Ticker (std::function<void()> onTick) : _onTick(onTick) , _isRunning(false) {}
            ~Ticker(){};

            /////////////

            void start()
            {
                if (_running) return;

                _running = true;
                std::thread run(&Ticker::timer_loop, this);
                run.detach();
            }

            void stop()
            {
                _running = false;
            }

            void setTPS(int64_t newTPS)
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
    };
}
