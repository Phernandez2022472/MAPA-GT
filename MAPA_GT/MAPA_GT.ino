/*
 * Fundacion Kinal
 * Centro educativo tecnico laboral Kinal
 * Electronica
 * Grado: Quinto
 * Sección: A
 * Curso: Taller de electronica digital y reparación de computadoras I
 * Nombres: Angello Gabriel Mansilla Dieguez, Christian Emmanuel Solorzano Ralda, Pablo David Hernandez Ajiataz.
 * Carnet: 2022380, 2022323, 2022472.
 * Proyecto: Mapa De Guatemala.
*/

#include <Wire.h>
#include <PCF8574.h>
#include <SoftwareSerial.h>

#define ALTAVERAPAZ 0 //I2C1
#define BAJAVERAPAZ 1
#define CHIMALTENANGO 2
#define CHIQUIMULA 3
#define GUATEMALA 4
#define ELPROGRESO 5
#define ESCUINTLA 6


#define HUHUETENANGO 0 //I2C2
#define IZABAL 1
#define JALAPA 2
#define JUTIAPA 3
#define PETEN 4
#define QUETZALTENANGO 5
#define QUICHE 6

#define RETALHULEU 0 //I2C3
#define SACATEPEQUEZ 1
#define SANMARCOS 2
#define SANTAROSA 3
#define SOLOLA 4
#define SUCHITEPEQUEZ 5
#define TOTONICAPAN 6

#define ZACAPA 2 //Ultimo departamento

#define ZumbadorPin 12 // Buzzer

int c = 261; //Notas
int d = 294;
int e = 329;
int f = 349;
int g = 391;
int gS = 415;
int a = 440;
int aS = 455;
int b = 466;
int cH = 523;
int cSH = 554;
int dH = 587;
int dSH = 622;
int eH = 659;
int fH = 698;
int fSH = 740;
int gH = 783;
int gSH = 830;
int aH = 880;

long Departgen = 1; //Generador de departaentos
String RECEPCIONLED; //Variable que iguala lo que se lea en el monitor serial.
bool noretorno; //Variable para evitar que retorne a un valor

SoftwareSerial BLUTU(10, 11);

PCF8574 I2C1;
PCF8574 I2C2;
PCF8574 I2C3;

void setup() {
  I2C1.begin(0x20);
  I2C2.begin(0x22);
  I2C3.begin(0x24);

  pinMode(ZumbadorPin, OUTPUT);
  pinMode(ZACAPA,OUTPUT);
  BLUTU.begin(9600);
  Serial.begin(9600);

  noretorno = false;
  BLUTU.println("---            BIENVENIDO AL MAPA DE GUATEMALA              ---");
  BLUTU.println("---                        ATENCION                         ---");
  BLUTU.println("---ESCRIBE LAS CABECERAS DE LOS DEPARTAMENTOS QUE SE TE PIDE---");
  BLUTU.println(" ");
}
void loop() {

  switch (Departgen) {
    case (1):

      if (noretorno == false) {
        CLEARI2C();
        I2C1.write(0,LOW);
        BLUTU.println("CABECERA DE Alta Verapaz");
        noretorno = true;
      }

      if (BLUTU.available()) {
        RECEPCIONLED = BLUTU.readStringUntil('\n');
        if (RECEPCIONLED == "Coban" || RECEPCIONLED == "coban") {
          BLUTU.println("CORRECTO");
          BLUTU.println(" ");
          noretorno = false;
          Departgen = random(1, 22);

        } else {
          BLUTU.println("INCORRECTO");
          BLUTU.println(" ");
          cancion();
          noretorno = false;
          Departgen = random(1, 22);
        }
      }

      break;

    case (2):

      if (noretorno == false) {
        CLEARI2C();
        I2C1.write(1,LOW);
        BLUTU.println("CABECERA DE Baja Verapaz");
        noretorno = true;
      }

      if (BLUTU.available()) {
        RECEPCIONLED = BLUTU.readStringUntil('\n');
        if (RECEPCIONLED == "Salama" || RECEPCIONLED == "salama") {
          BLUTU.println("CORRECTO");
          BLUTU.println(" ");
          noretorno = false;
          Departgen = random(1, 22);

        } else {
          BLUTU.println("INCORRECTO");
          BLUTU.println(" ");
          cancion();
          noretorno = false;
          Departgen = random(1, 22);
        }
      }

      break;

    case (3):

      if (noretorno == false) {
        CLEARI2C();
        I2C1.write(2,LOW);
        BLUTU.println("CABECERA DE Chimaltenango");
        noretorno = true;
      }

      if (BLUTU.available()) {
        RECEPCIONLED = BLUTU.readStringUntil('\n');
        if (RECEPCIONLED == "Chimaltenango" || RECEPCIONLED == "chimaltenango") {
          BLUTU.println("CORRECTO");
          BLUTU.println(" ");
          noretorno = false;
          Departgen = random(1, 22);

        } else {
          BLUTU.println("INCORRECTO");
          BLUTU.println(" ");
          cancion();
          noretorno = false;
          Departgen = random(1, 22);
        }
      }
      break;

    case (4):

      if (noretorno == false) {
        CLEARI2C();
        I2C1.write(3,LOW);
        BLUTU.println("CABECERA DE Chiquimula");
        noretorno = true;
      }

      if (BLUTU.available()) {
        RECEPCIONLED = BLUTU.readStringUntil('\n');
        if (RECEPCIONLED == "Chiquimula" || RECEPCIONLED == "chiquimula") {
          BLUTU.println("CORRECTO");
          BLUTU.println(" ");
          noretorno = false;
          Departgen = random(1, 22);

        } else {
          BLUTU.println("INCORRECTO");
          BLUTU.println(" ");
          cancion();
          noretorno = false;
          Departgen = random(1, 22);
        }
      }
      break;

    case (5):
      if (noretorno == false) {
        CLEARI2C();
        I2C1.write(4,LOW);
        BLUTU.println("CABECERA DE El Progreso");
        noretorno = true;
      }
      if (BLUTU.available()) {
        RECEPCIONLED = BLUTU.readStringUntil('\n');
        if (RECEPCIONLED == "Guastatoya" || RECEPCIONLED == "guastatoya") {
          BLUTU.println("CORRECTO");
          BLUTU.println(" ");
          noretorno = false;
          Departgen = random(1, 22);


        } else {
          BLUTU.println("INCORRECTO");
          BLUTU.println(" ");
          cancion();
          noretorno = false;
          Departgen = random(1, 22);
        }
      }
      break;

    case (6):
      if (noretorno == false) {
        CLEARI2C();
        I2C1.write(5,LOW);
        BLUTU.println("CABECERA DE Escuintla");
        noretorno = true;
      }

      if (BLUTU.available()) {
        RECEPCIONLED = BLUTU.readStringUntil('\n');
        if (RECEPCIONLED == "Escuintla" || RECEPCIONLED == "Escuintla") {
          BLUTU.println("CORRECTO");
          BLUTU.println(" ");
          noretorno = false;
          Departgen = random(1, 22);

        } else {
          BLUTU.println("INCORRECTO");
          BLUTU.println(" ");
          cancion();
          noretorno = false;
          Departgen = random(1, 22);
        }
      }
      break;

    case (7):
      if (noretorno == false) {
        CLEARI2C();
        I2C1.write(6,LOW);
        BLUTU.println("CABECERA DE Guatemala");
        noretorno = true;
      }

      if (BLUTU.available()) {
        RECEPCIONLED = BLUTU.readStringUntil('\n');
        if (RECEPCIONLED == "Guatemala" || RECEPCIONLED == "guatemala") {
          BLUTU.println("CORRECTO");
          BLUTU.println(" ");
          noretorno = false;
          Departgen = random(1, 22);

        } else {
          BLUTU.println("INCORRECTO");
          BLUTU.println(" ");
          cancion();
          noretorno = false;
          Departgen = random(1, 22);
        }
      }
      break;

    case (8):

      if (noretorno == false) {
        CLEARI2C();
        I2C2.write(0,LOW);
        BLUTU.println("CABECERA DE Huehuetenango");
        noretorno = true;
      }

      if (BLUTU.available()) {
        RECEPCIONLED = BLUTU.readStringUntil('\n');
        if (RECEPCIONLED == "Huehuetenango" || RECEPCIONLED == "huehuetenango") {
          BLUTU.println("CORRECTO");
          BLUTU.println(" ");
          digitalWrite(3, HIGH);
          noretorno = false;
          Departgen = random(1, 22);

        } else {
          BLUTU.println("INCORRECTO");
          BLUTU.println(" ");
          cancion();
          noretorno = false;
          Departgen = random(1, 22);
        }
      }
      break;


    case (9):
      if (noretorno == false) {
        CLEARI2C();
        I2C2.write(1,LOW);
        BLUTU.println("CABECERA DE Izabal");
        noretorno = true;
      }


      if (BLUTU.available()) {
        RECEPCIONLED = BLUTU.readStringUntil('\n');
        if (RECEPCIONLED == "Puerto Barrios" || RECEPCIONLED == "puerto barrios") {
          BLUTU.println("CORRECTO");
          BLUTU.println(" ");
          noretorno = false;
          Departgen = random(1, 22);

        } else {
          BLUTU.println("INCORRECTO");
          BLUTU.println(" ");
          cancion();
          noretorno = false;
          Departgen = random(1, 22);
        }
      }
      break;


    case (10):
      if (noretorno == false) {
        CLEARI2C();
        I2C2.write(2,LOW);
        BLUTU.println("CABECERA DE Jalapa");
        noretorno = true;
      }

      if (BLUTU.available()) {
        RECEPCIONLED = BLUTU.readStringUntil('\n');
        if (RECEPCIONLED == "Jalapa" || RECEPCIONLED == "jalapa") {
          BLUTU.println("CORRECTO");
          BLUTU.println(" ");
          noretorno = false;
          Departgen = random(1, 22);

        } else {
          BLUTU.println("INCORRECTO");
          BLUTU.println(" ");
          cancion();
          noretorno = false;
          Departgen = random(1, 22);
        }
      }
      break;


    case (11):
      if (noretorno == false) {
        CLEARI2C();
        I2C2.write(3,LOW);
        BLUTU.println("CABECERA DE Jutiapa");
        noretorno = true;
      }

      if (BLUTU.available()) {
        RECEPCIONLED = BLUTU.readStringUntil('\n');
        if (RECEPCIONLED == "Jutiapa" || RECEPCIONLED == "jutiapa") {
          BLUTU.println("CORRECTO");
          BLUTU.println(" ");
          noretorno = false;
          Departgen = random(1, 22);

        } else {
          BLUTU.println("INCORRECTO");
          BLUTU.println(" ");
          cancion();
          noretorno = false;
          Departgen = random(1, 22);
        }
      }
      break;

    case (12):
      if (noretorno == false) {
        CLEARI2C();
        I2C2.write(4,LOW);
        BLUTU.println("CABECERA DE Peten");
        noretorno = true;
      }

      if (BLUTU.available()) {
        RECEPCIONLED = BLUTU.readStringUntil('\n');
        if (RECEPCIONLED == "Flores" || RECEPCIONLED == "flores") {
          BLUTU.println("CORRECTO");
          BLUTU.println(" ");
          noretorno = false;
          Departgen = random(1, 22);

        } else {
          BLUTU.println("INCORRECTO");
          BLUTU.println(" ");
          cancion();
          noretorno = false;
          Departgen = random(1, 22);
        }
      }
      break;


    case (13):
      if (noretorno == false) {
        CLEARI2C();
        I2C2.write(5,LOW);
        BLUTU.println("CABECERA DE Quetzaltenango");
        noretorno = true;
      }

      if (BLUTU.available()) {
        RECEPCIONLED = BLUTU.readStringUntil('\n');
        if (RECEPCIONLED == "Quetzaltenango" || RECEPCIONLED == "quetzaltenango") {
          BLUTU.println("CORRECTO");
          BLUTU.println(" ");
          noretorno = false;
          Departgen = random(1, 22);

        } else {
          BLUTU.println("INCORRECTO");
          BLUTU.println(" ");
          cancion();
          noretorno = false;
          Departgen = random(1, 22);
        }
      }
      break;

    case (14):
      if (noretorno == false) {
        CLEARI2C();
        I2C2.write(6,LOW);
        BLUTU.println("CABECERA DE Quiche");
        noretorno = true;
      }


      if (BLUTU.available()) {
        RECEPCIONLED = BLUTU.readStringUntil('\n');
        if (RECEPCIONLED == "Santa Cruz" || RECEPCIONLED == "santa cruz") {
          BLUTU.println("CORRECTO");
          BLUTU.println(" ");
          noretorno = false;
          Departgen = random(1, 22);
        } else {
          BLUTU.println("INCORRECTO");
          BLUTU.println(" ");
          cancion();
          noretorno = false;
          Departgen = random(1, 22);
        }
      }
      break;


    case (15):
      if (noretorno == false) {
        CLEARI2C();
        I2C3.write(0,LOW);
        BLUTU.println("CABECERA DE Retalhuleu");
        noretorno = true;
      }

      if (BLUTU.available()) {
        RECEPCIONLED = BLUTU.readStringUntil('\n');
        if (RECEPCIONLED == "Retalhuleu" || RECEPCIONLED == "retalhuleu") {
          BLUTU.println("CORRECTO");
          BLUTU.println(" ");
          noretorno = false;
          Departgen = random(1, 22);
        } else {
          BLUTU.println("INCORRECTO");
          BLUTU.println(" ");
          cancion();
          noretorno = false;
          Departgen = random(1, 22);
        }
      }
      break;


    case (16):
      if (noretorno == false) {
        CLEARI2C();
        I2C3.write(1,LOW);
        BLUTU.println("CABECERA DE Sacatepequez");
        noretorno = true;
      }

      if (BLUTU.available()) {
        RECEPCIONLED = BLUTU.readStringUntil('\n');
        if (RECEPCIONLED == "Antigua Guatemala" || RECEPCIONLED == "antigua guatemala") {
          BLUTU.println("CORRECTO");
          BLUTU.println(" ");
          noretorno = false;
          Departgen = random(1, 22);
        } else {
          BLUTU.println("INCORRECTO");
          BLUTU.println(" ");
          cancion();
          noretorno = false;
          Departgen = random(1, 22);
        }
      }
      break;


    case (17):
      if (noretorno == false) {
        CLEARI2C();
        I2C3.write(2,LOW);
        BLUTU.println("CABECERA DE San Marcos");
        noretorno = true;
      }

      if (BLUTU.available()) {
        RECEPCIONLED = BLUTU.readStringUntil('\n');
        if (RECEPCIONLED == "San Marcos" || RECEPCIONLED == "san marcos") {
          BLUTU.println("CORRECTO");
          BLUTU.println(" ");
          noretorno = false;
          Departgen = random(1, 22);
        } else {
          BLUTU.println("INCORRECTO");
          BLUTU.println(" ");
          cancion();
          noretorno = false;
          Departgen = random(1, 22);
        }
      }
      break;

    case (18):
      if (noretorno == false) {
        CLEARI2C();
        I2C3.write(3,LOW);
        BLUTU.println("CABECERA DE Santa Rosa");
        noretorno = true;
      }

      if (BLUTU.available()) {
        RECEPCIONLED = BLUTU.readStringUntil('\n');
        if (RECEPCIONLED == "Cuilapa" || RECEPCIONLED == "cuilapa") {
          BLUTU.println("CORRECTO");
          BLUTU.println(" ");
          noretorno = false;
          Departgen = random(1, 22);
        } else {
          BLUTU.println("INCORRECTO");
          BLUTU.println(" ");
          cancion();
          noretorno = false;
          Departgen = random(1, 22);
        }
      }
      break;


    case (19):
      if (noretorno == false) {
        CLEARI2C();
        I2C3.write(4,LOW);
        BLUTU.println("CABECERA DE Solola");
        noretorno = true;
      }

      if (BLUTU.available()) {
        RECEPCIONLED = BLUTU.readStringUntil('\n');
        if (RECEPCIONLED == "Solola" || RECEPCIONLED == "solola") {
          BLUTU.println("CORRECTO");
          BLUTU.println(" ");
          noretorno = false;
          Departgen = random(1, 22);
        } else {
          BLUTU.println("INCORRECTO");
          BLUTU.println(" ");
          cancion();
          noretorno = false;
          Departgen = random(1, 22);
        }
      }
      break;


    case (20):
      if (noretorno == false) {
        CLEARI2C();
        I2C3.write(5,LOW);
        BLUTU.println("CABECERA DE Suchitepequez");
        noretorno = true;
      }

      if (BLUTU.available()) {
        RECEPCIONLED = BLUTU.readStringUntil('\n');
        if (RECEPCIONLED == "Mazatenango" || RECEPCIONLED == "mazatenango") {
          BLUTU.println("CORRECTO");
          BLUTU.println(" ");
          noretorno = false;
          Departgen = random(1, 22);
        } else {
          BLUTU.println("INCORRECTO");
          BLUTU.println(" ");
          cancion();
          noretorno = false;
          Departgen = random(1, 22);
        }
      }
      break;

    case (21):
      if (noretorno == false) {
        CLEARI2C();
        I2C3.write(6,LOW);
        BLUTU.println("CABECERA DE Totonicapan");
        noretorno = true;
      }


      if (BLUTU.available()) {
        RECEPCIONLED = BLUTU.readStringUntil('\n');
        if (RECEPCIONLED == "Totonicapan" || RECEPCIONLED == "totonicapan") {
          BLUTU.println("CORRECTO");
          BLUTU.println(" ");
          noretorno = false;
          Departgen = random(1, 22);
        } else {
          BLUTU.println("INCORRECTO");
          BLUTU.println(" ");
          cancion();
          noretorno = false;
          Departgen = random(1, 22);
        }
      }
      break;

    case (22):
      if (noretorno == false) {
        CLEARI2C();
        digitalWrite(2,HIGH);
        BLUTU.println("CABECERA DE Zacapa");
        noretorno = true;
      }
      if (BLUTU.available()) {
        RECEPCIONLED = BLUTU.readStringUntil('\n');
        if (RECEPCIONLED == "Zacapa" || RECEPCIONLED == "zacapa") {
          BLUTU.println("CORRECTO");
          BLUTU.println(" ");
          noretorno = false;
          Departgen = random(1, 22);
        } else {
          BLUTU.println("INCORRECTO");
          BLUTU.println(" ");
          cancion();
          noretorno = false;
          Departgen = random(1, 22);
        }
      }
      break;
  }
}

void cancion() {
  tone(ZumbadorPin, a, 500);
  delay(500 + 50);
  tone(ZumbadorPin, a, 500);
  delay(500 + 50);
  tone(ZumbadorPin, a, 500);
  delay(500 + 50);
  tone(ZumbadorPin, f, 350);
  delay(350 + 50);
  tone(ZumbadorPin, cH, 150);
  delay(150 + 50);

  tone(ZumbadorPin, a, 500);
  delay(500 + 50);
  tone(ZumbadorPin, f, 350);
  delay(350 + 50);
  tone(ZumbadorPin, cH, 150);
  delay(150 + 50);
  tone(ZumbadorPin, a, 1000);
  delay(1000 + 50);

  tone(ZumbadorPin, eH, 500);
  delay(500 + 50);
  tone(ZumbadorPin, eH, 500);
  delay(500 + 50);
  tone(ZumbadorPin, eH, 500);
  delay(500 + 50);
  tone(ZumbadorPin, fH, 350);
  delay(350 + 50);
  tone(ZumbadorPin, cH, 150);
  delay(150 + 50);

  tone(ZumbadorPin, gS, 500);
  delay(500 + 50);
  tone(ZumbadorPin, f, 350);
  delay(350 + 50);
  tone(ZumbadorPin, cH, 150);
  delay(150 + 50);
  tone(ZumbadorPin, a, 1000);
  delay(1000 + 50);

  tone(ZumbadorPin, aH, 500);
  delay(500 + 50);
  tone(ZumbadorPin, a, 350);
  delay(350 + 50);
  tone(ZumbadorPin, a, 150);
  delay(150 + 50);
  tone(ZumbadorPin, aH, 500);
  delay(500 + 50);
  tone(ZumbadorPin, gSH, 250);
  delay(250 + 50);
  tone(ZumbadorPin, gH, 250);
  delay(250 + 50);

  tone(ZumbadorPin, fSH, 125);
  delay(125 + 50);
  tone(ZumbadorPin, fH, 125);
  delay(125 + 50);
  tone(ZumbadorPin, fSH, 250);
  delay(250 + 50);
  delay(250);
  tone(ZumbadorPin, aS, 250);
  delay(250 + 50);
  tone(ZumbadorPin, dSH, 500);
  delay(500 + 50);
  tone(ZumbadorPin, dH, 250);
  delay(250 + 50);
  tone(ZumbadorPin, cSH, 250);
  delay(250 + 50);

  // virtuosismo :)))

  tone(ZumbadorPin, cH, 125);
  delay(125 + 50);
  tone(ZumbadorPin, b, 125);
  delay(125 + 50);
  tone(ZumbadorPin, cH, 250);
  delay(250 + 50);
  delay(250);
  tone(ZumbadorPin, f, 125);
  delay(125 + 50);
  tone(ZumbadorPin, gS, 500);
  delay(500 + 50);
  tone(ZumbadorPin, f, 375);
  delay(375 + 50);
  tone(ZumbadorPin, a, 125);
  delay(125 + 50);

  tone(ZumbadorPin, cH, 500);
  delay(500 + 50);
  tone(ZumbadorPin, a, 375);
  delay(375 + 50);
  tone(ZumbadorPin, cH, 125);
  delay(125 + 50);
  tone(ZumbadorPin, eH, 1000);
  delay(1000 + 50);


  tone(ZumbadorPin, aH, 500);
  delay(500 + 50);
  tone(ZumbadorPin, a, 350);
  delay(350 + 50);
  tone(ZumbadorPin, a, 150);
  delay(150 + 50);
  tone(ZumbadorPin, aH, 500);
  delay(500 + 50);
  tone(ZumbadorPin, gSH, 250);
  delay(250 + 50);
  tone(ZumbadorPin, gH, 250);
  delay(250 + 50);

  tone(ZumbadorPin, fSH, 125);
  delay(125 + 50);
  tone(ZumbadorPin, fH, 125);
  delay(125 + 50);
  tone(ZumbadorPin, fSH, 250);
  delay(250 + 50);
  delay(250);
  tone(ZumbadorPin, aS, 250);
  delay(250 + 50);
  tone(ZumbadorPin, dSH, 500);
  delay(500 + 50);
  tone(ZumbadorPin, dH, 250);
  delay(250 + 50);
  tone(ZumbadorPin, cSH, 250);
  delay(250 + 50);


  tone(ZumbadorPin, cH, 125);
  delay(125 + 50);
  tone(ZumbadorPin, b, 125);
  delay(125 + 50);
  tone(ZumbadorPin, cH, 250);
  delay(250 + 50);
  delay(250);
  tone(ZumbadorPin, f, 250);
  delay(250 + 50);
  tone(ZumbadorPin, gS, 500);
  delay(500 + 50);
  tone(ZumbadorPin, f, 375);
  delay(375 + 50);
  tone(ZumbadorPin, cH, 125);
  delay(125 + 50);

  tone(ZumbadorPin, a, 500);
  delay(500 + 50);
  tone(ZumbadorPin, f, 375);
  delay(375 + 50);
  tone(ZumbadorPin, c, 125);
  delay(125 + 50);
  tone(ZumbadorPin, a, 1000);
  delay(1000 + 50);
}

void CLEARI2C ()
{
 I2C1.write(0,HIGH);
 I2C1.write(1,HIGH);
 I2C1.write(2,HIGH);
 I2C1.write(3,HIGH);
 I2C1.write(4,HIGH);
 I2C1.write(5,HIGH);
 I2C1.write(6,HIGH);

 I2C2.write(0,HIGH);
 I2C2.write(1,HIGH);
 I2C2.write(2,HIGH);
 I2C2.write(3,HIGH);
 I2C2.write(4,HIGH);
 I2C2.write(5,HIGH);
 I2C2.write(6,HIGH); 

 I2C3.write(0,HIGH);
 I2C3.write(1,HIGH);
 I2C3.write(2,HIGH);
 I2C3.write(3,HIGH);
 I2C3.write(4,HIGH);
 I2C3.write(5,HIGH);
 I2C3.write(6,HIGH);

 digitalWrite(ZACAPA,LOW);

  
}
