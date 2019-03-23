/**
 * @file delay.h
 *
 * @brief Delay function.
 *
 * @author Lucas Haug <lucas.haug@thunderatz.org>
 *
 * @date 03/2019
 */

#ifndef __DELAY_H__
#define __DELAY_H__

/*****************************************
 * Public Functions Prototypes
 *****************************************/

#if defined (WIN_32)
#include <windows.h>
#define delay(ms) Sleep((ms))
#else
#include <unistd.h>
#define delay(ms) usleep((ms) * 1000)
#endif

#endif // __DELAY_H__
