# Libreria CVR_Neopixel_ws2812
Esta librería está construida con el fin de controlar modulos leds basados en ws2812 bajo el compilador xc8 de MPLABX
This library is built in order to control LED modules in ws2812 under MPLABX xc8 compiler

# Escrito por CVR ELECTRONICA | Written by CVR ELECTRONICA
En caso de que deseas ayuda o necesites la construccion de una librería para el control de un sensor, modulo etc. No dudes en contactarno
In case you want help or need the construction of a library to control a sensor, module etc. Do not hesitate to contact us

Emai: develop@cvrelectronica.com
Web: www.cvrelectronica.com
WhatsApp: +57 301 546 8124

# FUNCIONES DE LA LIBRERÍA | LIBRARY FUNCTIONS

- neopixel_setColor(char r, char g, char b, char numberOfLeds,char showChanges); 
- neopixel_reset();
- neopixel_turnOneLed(char index,char r, char g, char b);
- neopixel_turnFromTo(char indexF,char indexT,char r, char g, char b);
- neopixel_offLeds(char index, char reset);

# Descripcion de funciones | Functions description

## neopixel_setColor(char r, char g, char b, char numberOfLeds,char showChanges);

* Enciende un numero de leds desde el primer led con el valor rgb asignado, los cambios pueden o no ser mostrados (esto con el fin por ejemplo de poder encender un numero de leds de un color y el resto de otro color) asignando el valor del parametro showChanges. 
* Si desea por ejemplo encender el led 1 -> azul, led 2-> verde, led 3 -> rojo use el siguiente codigo:
'''
  neopixel_setColor(0,0,255,1,neopixel_noshow_changes);
  neopixel_setColor(0,255,0,1,neopixel_noshow_changes);
  neopixel_setColor(255,0,0,1,neopixel_show_changes);
'''

* It turns on a number of LEDs from the first LED with the assigned rgb value, the changes may or may not be shown (this in order for example to be able to turn on a number of LEDs of one color and the rest of another color) assigning the value of the showChanges parameter.
* If you want for example to turn on led 1 -> blue, led 2-> green, led 3 -> red use the following code:
'''
   neopixel_setColor (0,0,255,1, neopixel_noshow_changes);
   neopixel_setColor (0,255,0,1, neopixel_noshow_changes);
   neopixel_setColor (255,0,0,1, neopixel_show_changes);
'''

## neopixel_reset();
* Envía la condicion de reset al modulo, esta funcion es usada internamente por otras funciones, pero puede ser usada de forma particular de se necesario. 
* Send the reset condition to the module, this function is used internally by other functions, but can be used in a particular way if necessary.

## neopixel_turnOneLed(char index,char r, char g, char b);
* Encuende un led (index) y apaga el resto de los led. Los led encienden del color asignado en los parametros de la funcion
* Turn on one led (index) and turn off the rest of the led. The LEDs light up in the color assigned in the function parameters

## neopixel_turnFromTo(char indexF,char indexT,char r, char g, char b);
* Enciende todos los leds desde -> hasta (from -> to) el index seleccionado. Los led encienden del color asignado en los parametros de la funcion 
* Turn on all LEDs from -> to (from -> to) the selected index. The LEDs light up in the color assigned in the function parameters

## neopixel_offLeds(char index, char reset);
* Apaga los leds desde la posicion en la que se encuentre la transmision de datos (ultimo led configurado) hasta el index recibido como parametro.  los cambios pueden o no ser mostrados (esto con el fin por ejemplo de poder manipular el resto de leds) asignando el valor del parametro reset mediante el cual se envia la condicion de reset al modulo la cual indica el fin de la transmision de datos.
* Turn off the LEDs from the position in which the data transmission is (last configured LED) to the index received as a parameter. the changes may or may not be shown (this in order, for example, to be able to manipulate the rest of the LEDs) assigning the value of the reset parameter by means of which the reset condition is sent to the module which indicates the end of the data transmission.