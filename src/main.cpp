/*
*********************************************************************************************************
*
*	模块名称 : 主程序模块。
*	文件名称 : main.cpp
*	版    本 : V1.0
*	说    明 :
*
*
*	修改记录 :
*		版本号    日期       作者            说明
*		v1.0    2017-11-24  王永东        Dynamixel XL-320 servos
*
*	Copyright (C), 2014-2024, 岡山大学
*
*********************************************************************************************************
*/

// ----------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include "diag/Trace.h"

#include "Timer.h"
#include "BlinkLed.h"
#include "usart.h"


// Definitions visible only within this translation unit.
namespace
{
  // ----- Timing definitions -------------------------------------------------

  // Keep the LED on for 2/3 of a second.
  constexpr Timer::ticks_t BLINK_ON_TICKS = Timer::FREQUENCY_HZ * 3 / 4;
  constexpr Timer::ticks_t BLINK_OFF_TICKS = Timer::FREQUENCY_HZ
      - BLINK_ON_TICKS;
}

// ----- main() ---------------------------------------------------------------

// Sample pragmas to cope with warnings. Please note the related line at
// the end of this function, used to pop the compiler diagnostics status.
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wmissing-declarations"
#pragma GCC diagnostic ignored "-Wreturn-type"





u8 Success_Command[30]={0x55};
int
main(int argc, char* argv[])
{
  // Send a greeting to the trace device (skipped on Release).
  trace_puts("Hello ARM World!");

  // At this stage the system clock should have already been configured
  // at high speed.
  trace_printf("System clock: %u Hz\n", SystemCoreClock);

  Timer timer;
  timer.start();

  BlinkLed blinkLed;

  // Perform all necessary initialisations for the LED.
  blinkLed.powerUp();
  uart_init(115200);
  uart2_init(115200);
  uint32_t seconds = 0;

  // Infinite loop
  while (1)
    {

	  USART1_SendString("I am USART1\r\n");
	  USART1_SendData(seconds);
	  USART2_SendString("I am USART2\r\n");
	  USART2_SendData(seconds);

      blinkLed.turnOn();
      timer.sleep(seconds== 0 ? Timer::FREQUENCY_HZ : BLINK_ON_TICKS);

      blinkLed.turnOff();
      timer.sleep(BLINK_OFF_TICKS);

      ++seconds;

      // Count seconds on the trace device.
      trace_printf("Second %u\n", seconds);
    }
  // Infinite loop, never return.
}

#pragma GCC diagnostic pop

// ----------------------------------------------------------------------------
