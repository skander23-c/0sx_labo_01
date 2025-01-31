// Déclaration des constantes et variables globales
const int DEL = 13;               // Broche de la LED intégrée
const int tempC = 250;            // Temps d'attente pour le clignotement
const int tempB = 1000;           // Temps d'attente entre les séquences
const int niveauxPWM = 255;       // Résolution PWM (0-255)
const int dureeTotale = 2048;     // Durée totale pour la variation PWM
const int frequenceClignotement = ceil(7 / 2) + 1; // Fréquence calculée
const int delaye= 2000; 

void setup() {
  Serial.begin(9600);             // Initialisation de la communication série
  pinMode(DEL, OUTPUT);           // Configuration de la broche LED comme sortie
  Serial.println("Début du programme - 2344779");
}

void allume() {
  Serial.println("Allume - 2344779");
  digitalWrite(DEL, HIGH);
  delay(delaye);                    // Maintient la LED allumée pendant 2 secondes
  digitalWrite(DEL, LOW);
  delay(tempB);
}

void clignotement() {
  Serial.println("Clignotement - 2344779");
  for (int i = 0; i < frequenceClignotement; i++) {
    digitalWrite(DEL, HIGH);
    delay(tempC);                 // Temps d'attente pour allumer la LED
    digitalWrite(DEL, LOW);
    delay(tempC);                 // Temps d'attente pour éteindre la LED
  }
  delay(tempB);                   // Pause avant la prochaine séquence
}

void variation() {
  Serial.println("Variation - 2344779");
  int delai = dureeTotale / niveauxPWM; // Calcul du délai entre chaque étape
  for (int i = niveauxPWM; i >= 0; i--) {
    analogWrite(DEL, i);          // Applique une intensité croissante à la LED
    delay(delai);
  }
}

void eteint() {
  Serial.println("Eteint - 2344779");
  digitalWrite(DEL, LOW);
  delay(delaye);
}

void compteurStatique() {
  static int compteur = 0;        // Conserve la valeur entre les appels
  compteur++;
  Serial.print("Tour: ");
  Serial.println(compteur);
}

void loop() {
  compteurStatique();             // Affiche le numéro du cycle actuel
  allume();                       // Allume la LED
  clignotement();                 // Fait clignoter la LED
  variation();                    // Fait varier l'intensité de la LED
  eteint();                       // Éteint la LED
}

