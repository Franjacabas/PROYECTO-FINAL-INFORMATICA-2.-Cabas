
#include "ParkingSystem.h"

// ========== SENSOR DISTANCIA ==========
//DEFINO EL CONSTRUCTOR DE LA CLASE SensorDistancia
SensorDistancia::SensorDistancia(int t, int e) {
  trig = t;
  echo = e;
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
}
//SE DEFINE EL METODO. Los metodos en clases son como "funciones" propias de esa clase
long SensorDistancia::medirDistancia() {
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  
  long duracion = pulseIn(echo, HIGH);
  long distancia = duracion * 0.034 / 2;
  return distancia;
}

// ========== MULTIPLEXOR ==========
Multiplexor::Multiplexor(int s0, int s1, int s2, int s3, int sig) 
{
  pinS0 = s0;
  pinS1 = s1;
  pinS2 = s2;
  pinS3 = s3;
  pinSIG = sig;
}

void Multiplexor::inicializar() {
  pinMode(pinS0, OUTPUT);
  pinMode(pinS1, OUTPUT);
  pinMode(pinS2, OUTPUT);
  pinMode(pinS3, OUTPUT);
  pinMode(pinSIG, INPUT);
}

void Multiplexor::seleccionarCanal(int canal) {
  digitalWrite(pinS0, bitRead(canal, 0));
  digitalWrite(pinS1, bitRead(canal, 1));
  digitalWrite(pinS2, bitRead(canal, 2));
  digitalWrite(pinS3, bitRead(canal, 3));
  delayMicroseconds(10);
}

/*bool Multiplexor::leerSensorIR(int canal) {
  seleccionarCanal(canal);
  delay(50);
  int lectura = digitalRead(pinSIG);
  return (lectura == LOW);
}*/
 

bool Multiplexor::leerSensorIR(int canal) {
	// Limpiar canal primero
	digitalWrite(pinS0, LOW);
	digitalWrite(pinS1, LOW);
	digitalWrite(pinS2, LOW);
	digitalWrite(pinS3, LOW);
	delay(10);
	
	// Seleccionar canal
	seleccionarCanal(canal);
	delay(50);
	
	// Leer 3 veces y promediar
	int lecturas = 0;
	for(int i = 0; i < 3; i++) {
		lecturas += digitalRead(pinSIG);
		delay(5);
	}
	
	// Si 2 de 3 lecturas dan LOW, está ocupado
	return (lecturas < 2);
}

// ========== COMUNICACION ==========
void Comunicacion::enviarDatos(bool p1, bool p2, bool p3) {
  Serial.print("P1:");
  Serial.print(p1 ? "1" : "0");
  Serial.print(",P2:");
  Serial.print(p2 ? "1" : "0");
  Serial.print(",P3:");
  Serial.println(p3 ? "1" : "0");
}

char Comunicacion::leerComando() {
  if (Serial.available() > 0) {
    return Serial.read();
  }
  return '\0';
}

// ========== BARRERA MANUAL ==========
BarreraManual::BarreraManual() {
  activa = false;
  tiempoInicio = 0;
}

void BarreraManual::activar() {
  activa = true;
  tiempoInicio = millis();
}

void BarreraManual::desactivar() {
  activa = false;
}

bool BarreraManual::estaActiva() {
  return activa;
}

int BarreraManual::tiempoRestante() {
  if (!activa) return 0;
  unsigned long transcurrido = millis() - tiempoInicio;
  int restante = (5000 - transcurrido) / 1000;
  return max(0, restante);
}

void BarreraManual::actualizar() {
  if (activa && (millis() - tiempoInicio >= 5000)) {
    activa = false;
  }
}

// ========== DISPLAY LCD ==========
DisplayLCD::DisplayLCD(LiquidCrystal_I2C* pantalla) {
  lcd = pantalla;
}

void DisplayLCD::inicializar() {
  lcd->init();
  lcd->backlight();
  mostrarBienvenida();
}

void DisplayLCD::mostrarBienvenida() {
  lcd->clear();
  lcd->setCursor(0, 0);
  lcd->print("Sistema Parking");
  lcd->setCursor(0, 1);
  lcd->print("3 Plazas");
  delay(2000);
  lcd->clear();
}

void DisplayLCD::mostrarBarreraManual(int segundos) {
  lcd->clear();
  lcd->setCursor(0, 0);
  lcd->print("Barrera Manual");
  lcd->setCursor(0, 1);
  lcd->print("Cerrando en ");
  lcd->print(segundos);
  lcd->print("s");
}

void DisplayLCD::mostrarVehiculoSaliendo() {
  lcd->clear();
  lcd->setCursor(0, 0);
  lcd->print("Vehiculo");
  lcd->setCursor(0, 1);
  lcd->print("Saliendo...");
}

void DisplayLCD::mostrarEstadoPlazas(int libres, bool p1, bool p2, bool p3) {
  lcd->clear();
  
  if (libres == 0) {
    lcd->setCursor(0, 0);
    lcd->print("No hay lugar");
    lcd->setCursor(0, 1);
    lcd->print("Parking lleno");
  } 
  else if (libres == 1) {
    lcd->setCursor(0, 0);
    lcd->print("1 lugar libre");
    lcd->setCursor(0, 1);
    if (!p1) lcd->print("Plaza 1");
    else if (!p2) lcd->print("Plaza 2");
    else lcd->print("Plaza 3");
  } 
  else if (libres == 2) {
    lcd->setCursor(0, 0);
    lcd->print("2 lugares libres");
    lcd->setCursor(0, 1);
    if (p1) lcd->print("P2 y P3");
    else if (p2) lcd->print("P1 y P3");
    else lcd->print("P1 y P2");
  } 
  else {
    lcd->setCursor(0, 0);
    lcd->print("3 lugares libres");
    lcd->setCursor(0, 1);
    lcd->print("Bienvenido!");
  }
}

// ========== CONTROLADOR BARRERA ==========
ControladorBarrera::ControladorBarrera(Servo* s, int rojo, int verde, int buzzer) {
  servo = s;
  pinRojo = rojo;
  pinVerde = verde;
  pinBuzz = buzzer;
}

void ControladorBarrera::inicializar() {
  pinMode(pinRojo, OUTPUT);
  pinMode(pinVerde, OUTPUT);
  pinMode(pinBuzz, OUTPUT);
  
  digitalWrite(pinRojo, LOW);
  digitalWrite(pinVerde, HIGH);
  digitalWrite(pinBuzz, LOW);
}

void ControladorBarrera::abrir() {
  digitalWrite(pinRojo, HIGH);
  digitalWrite(pinVerde, LOW);
  servo->write(90);
}

void ControladorBarrera::cerrar() {
  digitalWrite(pinRojo, LOW);
  digitalWrite(pinVerde, HIGH);
  digitalWrite(pinBuzz, LOW);
  servo->write(0);
}

void ControladorBarrera::activarAlarma() {
  for (int i = 0; i < 3; i++) {
    digitalWrite(pinBuzz, HIGH);
    delay(150);
    digitalWrite(pinBuzz, LOW);
    delay(150);
  }
}

