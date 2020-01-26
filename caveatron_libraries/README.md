This repository [https://github.com/Caveatron/caveatron_libraries] contains additional libraries necessary to build Caveatron, sourced from elsewhere and with (possibly) different licenses from Caveatron itself. 

In some cases, minor changes have been made to the libraries to provided fixes necessary for Caveatron; these have been noted inside the libraries themselves in the `MODIFIED FOR CAVEATRON.txt` files.

Please refer to the `README` in the main Caveatron repository [https://github.com/Caveatron/caveatron] for details on how to install and use these libraries.

## DueTimer
Interrupt-driven timer for Arduino Due. Used for GUI and other timed functions
* __Author:__ Ivan Seidel 
* __License:__ MIT
* __Original Source:__ https://github.com/ivanseidel/DueTimer
* __Modified for Caveatron?__ No

## Eigen 3.2.10
Library of high level mathematical functions. Used for hard and soft iron calibration calculations.
* __Author:__ Volunteer team 
* __License:__ MPL2
* __Original Source:__ eigen.tuxfamily.org/
* __Modified for Caveatron?__ Yes – modified version does not retain original functionality

## LSM303 3.0.1
Library for Pololu LSM303 magnetometer and accelerometer carrier boards.
* __Author:__ Pololu Corporation 
* __License:__ MIT
* __Original Source:__ https://github.com/pololu/lsm303-arduino
* __Modified for Caveatron?__ Yes – original functionality retained

## MAX17043
Library for Maxim MAX1704 battery fuel gauge.
* __Author:__ Luca Dentella
* __License:__ None
* __Original Source:__ https://github.com/lucadentella/ArduinoLib_MAX17043
* __Modified for Caveatron?__ Yes – original functionality retained

## SDFat 2017-04-26
Provides read/write access to FAT16/FAT32 file systems on SD/SDHC flash cards.
* __Author:__ Bill Greiman
* __License:__ MIT
* __Original Source:__ https://github.com/greiman/SdFat 
* __Modified for Caveatron?__ No

## SparkfunBQ27441
Library for Sparkfun Battery Babysitter module.
* __Author:__ Sparkfun Electronics 
* __License:__ CC BY-SA 4.0
* __Original Source:__ https://github.com/sparkfun/Battery_Babysitter
* __Modified for Caveatron?__ Yes – original functionality retained

## Sweep
Library for SWEEP LIDAR module hardware.
* __Author:__ Scanse LLC 
* __License:__ None
* __Original Source:__ https://github.com/scanse/sweep-arduino
* __Modified for Caveatron?__ Yes – original functionality retained

## URTouch
General library supporting a wide range of touchscreens
* __Author:__ Henning Karlsen, Rinky-Dink Electronics
* __License:__ CC BY-NC-SA 3.0
* __Original Source:__ http://www.rinkydinkelectronics.com/library.php?id=92
* __Modified for Caveatron?__ Yes – original functionality retained

## UTFT
General library supporting a wide range of graphical display modules
* __Author:__ Henning Karlsen, Rinky-Dink Electronics
* __License:__ CC BY-NC-SA 3.0
* __Original Source:__ http://www.rinkydinkelectronics.com/library.php?id=51
* __Modified for Caveatron?__ Yes – original functionality retained

## UTFT-CTE
Library to support display of text and graphics on the original Font ICs on Coldtears Electronics touchscreen modules
* __Author:__ Coldtears Electronics
* __License:__ CC BY-NC-SA 3.0
* __Original Source:__ http://www.coldtears-electronics.com/images/UTFT_CTE.zip
* __Modified for Caveatron?__ Yes – modified version does not retain original functionality

## UTFT-GHL
**Note: This library is not distributed with the Caveatron code at the author's request and is not available for public download. You must purchase a supported display to obtain the library.**

Library to support display of text and graphics on the newer Font ICs on Coldtears Electronics touchscreen modules
* __Author:__ Graham Lawrence
* __License:__ © Graham Lawrence
* __Original Source:__ http://www.utftghl.com/ (note – code not available for public download)
* __Modified for Caveatron?__ No
