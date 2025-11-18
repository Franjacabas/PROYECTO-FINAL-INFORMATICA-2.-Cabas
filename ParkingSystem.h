
  ParkingSystem.h - LibrerÃ­a completa para sistema de estacionamiento
  Incluye todas las clases y funciones del proyecto
*/

#ifndef ParkingSystem_h
#define ParkingSystem_h

#include <Arduino.h>
#include <Servo.h>
#include <LiquidCrystal_I2C.h>

// ========== CLASE SENSOR DISTANCIA ==========
class SensorDistancia {
  private:
    int trig;
    int echo;
    
  public:
    SensorDistancia(int t, int e);
    long medirDistancia();
};

// ========== CLASE MULTIPLEXOR ==========
class Multiplexor {
  private:
    int pinS0, pinS1, pinS2, pinS3, pinSIG;
    
  public:
    Multiplexor(int s0, int s1, int s2, int s3, int sig);
    void inicializar();
    void seleccionarCanal(int canal);
    bool leerSensorIR(int canal);
};

// ========== CLASE COMUNICACION ==========
class Comunicacion {
  public:
    static void enviarDatos(bool p1, bool p2, bool p3);
    static char leerComando();
};

// ========== CLASE BARRERA MANUAL ==========
class BarreraManual {
  private:
    bool activa;
    unsigned long tiempoInicio;
    
  public:
    BarreraManual();
    void activar();
    void desactivar();
    bool estaActiva();
    int tiempoRestante();
    void actualizar();
};

// ========== CLASE DISPLAY LCD ==========
class DisplayLCD {
  private:
    LiquidCrystal_I2C* lcd;
    
  public:
    DisplayLCD(LiquidCrystal_I2C* pantalla);
    void inicializar();
    void mostrarBienvenida();
    void mostrarBarreraManual(int segundos);
    void mostrarVehiculoSaliendo();
    void mostrarEstadoPlazas(int libres, bool p1, bool p2, bool p3);
};

// ========== CLASE CONTROLADOR BARRERA ==========
class ControladorBarrera {
  private:
    Servo* servo;
    int pinRojo;
    int pinVerde;
    int pinBuzz;
    
  public:
    ControladorBarrera(Servo* s, int rojo, int verde, int buzzer);
    void inicializar();
    void abrir();
    void cerrar();
    void activarAlarma();
};

#endif
