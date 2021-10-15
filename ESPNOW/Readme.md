
# ESP-NOW
En esta ocasión te hablaré del protocolo ESP-Now, el cual podremos usarlo en nuestros mirocontroladores ESP32, ESP8266, y seguramente en el resto de familia ESP. ESP-Now es un protocolo de comunicación entre varios dispositivos creado por Espressif, el cual es similar al utilizado en los dispositivos de baja energía que funcionan en la banda de 2.4Ghz. Su funcionamiento requiere de emparejamiento de los dispositivos, pero una vez hecho la conexión será automática.

## ESP32 soporta las siguientes características:
```
Comunicación unicast encriptada y sin encriptar
Se pueden mezclar clientes con encriptación y sin encriptación
Permite enviar hasta 250-bytes de carga útil
Se pueden configurar callbacks para informar a la aplicación si la transmisión fue correcta
Largo alcance, pudiendo superar los 200m en campo abierto.
```
## Pero también tiene sus limitaciones, las cuales son:
```
El número de clientes con encriptación está limitado. Esta limitación es de 10 clientes para el modo Estación, 6 como mucho en modo punto de acceso o modo mixto.
El número total de clientes con y sin encriptación sin encriptación es del 20.
Sólo se pueden enviar 250 bytes como mucho.
En palabras simples, ESP-Now es un protocolo de comunicación que nos permitirá intercambiar pequeños mensajes (hasta 250 bytes), entre nuestros microcontroladores ESP. 
Este protocolo es muy versátil y nos permitirá realizar conexiones en una dirección o en ambas direcciones, en diferentes configuraciones.
 ```
## Tipos de comunicación
 ```
Comunicación ESP-Now en una dirección
Este tipo de comunicación se compone de uno o varios dispositivos ESP que funcionarán como maestros y esclavos. 
La comunicación la iniciará el dispositivo o dispositivos maestros, y será recibida por el o los esclavos. 
Entre las diferentes configuraciones de las que disponemos para la configuración en una dirección, podemos distinguir las siguientes:
  ```
## Un maestro y un esclavo
## Un maestro y varios esclavos
## Varios maestros y un esclavo

