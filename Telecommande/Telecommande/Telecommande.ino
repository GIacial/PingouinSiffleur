#define BOUTON_VALID 5
#define BOUTON_TIR  2
#define BOUTON_SCORE 4
#define BOUTON_STOP 3
#define POTENTIO A0
#define NB_PROG 4

int progChoix;

void setup() {
  // put your setup code here, to run once:
   Serial.begin(9600);

  pinMode(POTENTIO, INPUT);
  pinMode(BOUTON_VALID , INPUT_PULLUP);
  pinMode(BOUTON_TIR , INPUT_PULLUP);
  pinMode(BOUTON_SCORE , INPUT_PULLUP);
  pinMode(BOUTON_STOP , INPUT_PULLUP);
  calculProg();
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(BOUTON_VALID) != HIGH){
    delay(5);  //attente fin rebond du bu0on
    calculProg();
    Serial.print("Prog ");
    Serial.print(progChoix);
    Serial.println(" Validation");
  }
  
  if(digitalRead(BOUTON_TIR) != HIGH){
    delay(5);  //attente fin rebond du button
    Serial.print("Prog ");
    Serial.print(progChoix);
    Serial.println("TIR");
  }

   if(digitalRead(BOUTON_SCORE) != HIGH){
    delay(5);  //attente fin rebond du button
    Serial.print("Prog ");
    Serial.print(progChoix);
    Serial.println("SCORE");
  }

   if(digitalRead(BOUTON_STOP) != HIGH){
    delay(5);  //attente fin rebond du button
    Serial.println("STOP");
  }
  delay(200);
}

void calculProg(){
  int valPotentio = analogRead(POTENTIO);
   progChoix = valPotentio /(1024/NB_PROG);
}


