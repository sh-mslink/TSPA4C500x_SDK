#include "in_config.h"
#include "hal_global.h"
#include "ble_app.h"


/*
 * main: This is actually main task. 
 *  Note: The _main_init in the RTX_CM_lib.h is 
 *              main entry routine (OS is initialized 
 *              in there).
 */
int main (void)
{
    //Initialize platform.
    hal_global_post_init();
    
    //Enter HCI mode
    ble_config(true, NULL);
    
    //Wait for HCI communication
    while(1);
}
