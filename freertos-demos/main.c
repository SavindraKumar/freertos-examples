//! @addtogroup Intialisation
//! @brief Intialise FreeRTOS Kernel
//! @{
//!
//****************************************************************************/
//! @file main.c
//! @brief Intialise FreeRTOS Kernel
//! @author Savindra Kumar(savindran1989@gmail.com)
//! @bug No known bugs.
//!
//****************************************************************************/
//****************************************************************************/
//                           Includes
//****************************************************************************/
//standard header files
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
//FreeRTOS Kernel header files
#include "FreeRTOS.h"
#include "task.h"
//user defined header files
#include "example1.h"

//****************************************************************************/
//                           Defines and typedefs
//****************************************************************************/

//****************************************************************************/
//                           Private Functions
//****************************************************************************/

//****************************************************************************/
//                           Extern Functions
//****************************************************************************/
void vApplicationMallocFailedHook(void);
void vApplicationIdleHook(void);
void vApplicationStackOverflowHook(TaskHandle_t pxTask, char *pcTaskName);

//****************************************************************************/
//                           Private variables
//****************************************************************************/

//****************************************************************************/
//                           external variables
//****************************************************************************/



//****************************************************************************/
//                    G L O B A L  F U N C T I O N S
//****************************************************************************/
int main(void)
{
	//start freertos scheduler
	vTaskStartScheduler();

	while (1)
	{
		//it should never reach here
	}

	return 0;
}

void vApplicationMallocFailedHook(void)
{
	vAssertCalled(__LINE__, __FILE__);
}

void vApplicationIdleHook(void)
{

}

void vApplicationStackOverflowHook(TaskHandle_t pxTask, char *pcTaskName)
{
	(void)pcTaskName;
	(void)pxTask;

	vAssertCalled(__LINE__, __FILE__);
}

void vApplicationTickHook(void)
{

}

void vApplicationDaemonTaskStartupHook(void)
{
	//call example1 after freertos schduler started
	example1();
}

void vAssertCalled(unsigned long ulLine, const char * const pcFileName)
{
	(void)ulLine;
	(void)pcFileName;

	printf("ASSERT! Line %ld, file %s, GetLastError() %ld\r\n", ulLine, pcFileName, GetLastError());
}
/******************************************************************************
 *                           L O C A L  F U N C T I O N S
 *****************************************************************************/
/******************************************************************************
 *                             End of file
 ******************************************************************************/
 /** @}*/