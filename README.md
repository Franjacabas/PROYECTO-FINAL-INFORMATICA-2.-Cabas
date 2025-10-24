# PROYECTO-FINAL-INFORMATICA-2.-Cabas
Proyecto de la Materia Informatica 2. 
Este mismo consta de un trabajo en Arduino, processing y demas elementos aprendidos en clase. En si, mi proyecto se basará 
en una entrada/salida de un estacionamiento, donde el peaton podra ser avisado cuando un vehiculo estara por salir de la plaza;
mediante un buzzer y unos led. La deteccion de la salida del vehiculo sera por medio de un sensor HC-SR04, este mismo activara el buzzer y los led para
que el peaton tenga precaucion y este alerta. 
Mas adelante implementare por processing una interfaz donde la persona encargada del estacionamiento, pueda observar si hay lugares libres
para estacionar, tambien dando la posibilidad a los coches de afuera encontrar un lugar en este mismo. Con un display o pantalla donde en la calle
se observe cuantos lugares esten vacios o en caso de estar lleno, que se muestre. 
(02-10-2025) en breves actualizaciones de codigo en arduino.

(12-10-2025) ACTUALIZACION.
Implemente un Servomotor para el accionar de la barrera cuando se detecte un auto en la salida del estacionamiento. 
Mediante el sensor HC-SR04, se activa la alarma (Buzzer) alertando al peaton, tambien encendiendo un led rojo,y levantando la barrera para
que salga el vehiculo. Se implemento Pantalla para lograr que los automoviles que circulan, puedan ver si hay lugares para poder estacionar. (No finalizada esa parte)

(14-10-25) ACTUALIZACION.
Se implementaran sensores IR- 08H para colocar en las plazas de estacionamientos para detectar si hay lugar o no, previamente se mostrara el resultado
en la pantalla LCD 16x2. Para esta actualizacion, se requiere de un multiplexor 16 canales analogico (74HC4067), para obtener mas pines donde 
colocar los sensores IR.
A futuro se piensa implemetar en proccesing la interfaz anteriormente mencionada, con la idea de que si algun vehiculo quiere ingresar, el operador de 
el 'ok' para q se habilite la barrera y accesa el auto. Esto para implementar una parte bidireccional que nos solicita la consigna del PROYECTO.

(16-10-25) ACTUALIZACION.
Como mencionamos anteriormente, se implementaron los sensores IR-08H pero cometí el error de no informarme sobre esos sensores. Resulto que cuando se realizo la conexion,
el funcionamiento de este mismo solamente detectaba la vibracion de los objetos, no me detectaba si un objeto (automovil) estaba estatico. Lo que se implemente correctamente fue
la pantalla LCD 16X2, más un modulo I2C para facilitar la conexion, previamente soldando estos dos componentes. 

(17-10-25) ACTUALIZACION
Se compraron/cambiaron los sensores (se adjunto link el archivo de google docs como referencia). Y la conexion era igual a la de los sensores anteriores.
Ya con todos los componentes determinados teniamos todo el codigo ARDUINO LISTO. Se agrego Otro sensor HC-SR04 como detector de vehiculos en las plazas, por motivo
que cuando se compraron los sensores nuevos, no habia mas stock y por el momento se consiguieron dos (DOS SENSORES DE DETECCION DE OBSTACULOS + OTRO HC-SR04).

(18-10-25) COMIENZO PROCESSING
Se comenzo la programacion de codigo de processing, me base en mi idea original que era "dibujar" las plazas de estacionamiento para cadada sensor.
Con ayuda de PDF Y ARCHIVOS otorgados por la catedra y con un poco de ayuda de inteligencia artificial se pudo realizar el codigo.
EXTRA. A la interfaz se le agrego un boton, donde la logica era que cuando un vehiculo no registrado quisiera acceder al estacionamiento. Ese permiso
se le otorgue cuando el "cliente" pague. Entonces mediante el boton, se levanta la barra para su acceso.

(20-10-25) ARCHIVOS
al codigo arduino le voy a implementar una funcion donde pueda guardar en archivos, la actividad del estacinamiento. Hora, fecha, cuanto tiempo estuvo el vehiculo,
y en que plaza se encontraba.


