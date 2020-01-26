UTFT_CTE.cpp - Addon library for Henning Karlsen's UTFT library (2.4.1 or above) to support drawing text and images on the serial flash of the CTE LCD modules (v.1.2)

Copyright (C)2014 Coldtears electronics. All right reserved
  
http://stores.ebay.com/coldtears-electronics-store/
  
Currently support CTE modules:
 1. CTE 7" LCD Module w/Font IC (CTE50)
 2. CTE 5" LCD Module w/Font IC (CTE70)
 3. CTE 4.3" LCD Module w/Font IC 480x272
 4. CTE 4.0" LCD Module w/Font IC (CTE40)
 5. CTE 3.5" IPS LCD Module w/Font IC (CTE35IPS)
 6. CTE 3.2" LCD Module w/Font IC 480x320 (CTE32HR)
 7. CTE 3.2" Wide LCD Module w/Font IC 400x240 (CTE32W)
 8. CTE 3.2" LCD Module w/Font IC 320x240 (CTE32)

The addon library enable the drawing of text of 10 different sizes which is based on the Font IC of the CTE LCD modules. It also support drawing of images/icon preloaded in the Font IC of the Modules. To import images to the Font IC, please use a seperate library "Image importer library for CTE LCD modules"

Demo sketches are avalibable for the above 8 modules (without any sketch modification) for arduino MEGA2560 and arduino DUE using CTE shield
 
If you are using CTE shield for DUE, you need to uncomment "#define CTE_DUE_SHIELD 1" in the HW_ARM_defines.h in the \hardware\arm folder of the UTFT library
 
Feel free to modify the code to suite your needs, any improvement or comments,
Please send email to coldtearselectronics@gmail.com

UTFT library can be downloaded at:
http://electronics.henningkarlsen.com/
  
This library is free software; you can redistribute it and/or
modify it under the terms of the CC BY-NC-SA 3.0 license.
Please see the included documents for further information.