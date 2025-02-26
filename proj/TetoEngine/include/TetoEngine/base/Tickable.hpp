#pragma once

#include <chrono>
#include <atomic>
#include <mutex>
#include <thread>
#include "raylib.h"
#include <functional>

namespace teto
{

    using tick_interval_t = std::chrono::duration<int32_t, std::milli>;

    class Tickable
    {
        public:

        Tickable();
        ~Tickable();

        void startTicking();
        void stopTicking();

        virtual void onTick() = 0;

        void setTickInterval(tick_interval_t newTPS);

        private:

        void tickLoop();

        tick_interval_t _tickInterval;
        std::mutex _tickIntervalMutex;
        std::atomic<bool> _isRunning = false;
        
    };
}