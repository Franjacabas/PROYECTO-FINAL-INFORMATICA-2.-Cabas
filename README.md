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

