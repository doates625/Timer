/**
 * @file Timer.h
 * @brief Class for Arduino and Mbed event timing
 * @author Dan Oates (WPI Class of 2020)
 * 
 * This class implements the Mbed Timer class for Arduino toallow for cross-
 * platform libraries and projects. This class uses the Arduino millis() and
 * micros() functions, and thus requires interrupts to be enabled for accuracy.
 * Because millis() and micros() return 32-bit integers, the Mbed method
 * Timer::read_high_resolution_us() which returns a 64-bit integer is not
 * implemented by this class.
 * 
 * Dependencies:
 * - Platform: https://github.com/doates625/Platform.git
 * 
 * References:
 * - Mbed Timer: https://os.mbed.com/docs/mbed-os/v5.14/mbed-os-api-doxy/_timer_8h_source.html
 */
#pragma once
#include <Platform.h>

#if defined(PLATFORM_ARDUINO)

/**
 * Class Declaration
 */
class Timer
{
public:
	Timer();
	void start();
	void stop();
	void reset();
	float read();
	uint32_t read_ms();
	uint32_t read_us();
	operator float();
protected:
	uint32_t start_time_us;
	uint32_t stop_time_us;
	bool running;
};

#endif