#include <wiringPi.h>
#include <iostream>
//Number of rows and columns (square multiplex)
const int NumRCS = 7;

const int LED_ROWS[NumRCS] = { 23, 24, 25, 12, 16, 20, 21 };
const int LED_CLMS[NumRCS] = { 17, 27, 22, 10, 13, 19, 26 };

int main(int argc, char**argv) {
    wiringPiSetup(); // Initializes wiringPi using wiringPi's simplified number system.
    wiringPiSetupGpio(); // Initializes wiringPi using the Broadcom GPIO pin numbers
        
    for (int i = 0; i < NumRCS; i++) {
        pinMode (LED_ROWS[i], OUTPUT);
        pinMode (LED_CLMS[i], OUTPUT);
    }
    
    while (1) {
        // ALL LEDS ON
        for( int i = 0; i < NumRCS; i++ ) {
            digitalWrite( LED_ROWS[i], HIGH );
            for( int j = 0; j < NumRCS; j++ ) {
                digitalWrite( LED_CLMS[j], HIGH);
                delay(1);
                digitalWrite( LED_CLMS[j], LOW);
            }
            digitalWrite( LED_ROWS[i], LOW );
            delay (1);
        }        
        
        for ( int numCircle = 0; numCircle < 4; numCircle++ ) {
            double start = millis();
            
            for( int i = 0; i < NumRCS; i++ ) {
                digitalWrite( LED_ROWS[i], HIGH );
                for( int j = 0; j < NumRCS; j++ ) {
                    digitalWrite( LED_CLMS[j], HIGH);
                    delay(1);
                    digitalWrite( LED_CLMS[j], LOW);
                }
                digitalWrite( LED_ROWS[i], LOW );

                delay (1);
            }
        }
    }
    return 0;
}

void openHand() {
    for(int i = 0; i < NumRCS; i++) {
        digitalWrite(LED_ROWS[i], HIGH);
        switch(i) {
            case 0, 1:
                int temp[] = {22, 13, 26};
                for(int j = 0; j < 3; j++) {
                    digitalWrite(temp[j], HIGH);
                    delay(1);
                    digitalWrite(temp[j], LOW);
                }
            case 2:
                int temp[] = {17, 22, 13, 26};
                for(int j = 0; j < 4; j++) {
                    digitalWrite(temp[j], HIGH);
                    delay(1);
                    digitalWrite(temp[j], LOW);
                }
            case 3: 
                int temp[] = {17, 22, 10, 13, 19, 26};
                for(int j = 0; j < 6; j++) {
                    digitalWrite(temp[j], HIGH);
                    delay(1);
                    digitalWrite(temp[j], LOW);
                }
            case 4:
                for(int j = 0; j < NumRCS; j++) {
                    digitalWrite(LED_CLMS[j], HIGH);
                    delay(1);
                    digitalWrite(LED_CLMS[j], LOW);
                }
            case 5:
                int temp[] = {27, 22, 10, 13, 19};
                for(int j = 0; j < 5; j++) {
                    digitalWrite(temp[j], HIGH);
                    delay(1);
                    digitalWrite(temp[j], LOW);
                }
            case 6:
                int temp[] = {22, 10};
                for(int j = 0; j < 2; j++) {
                    digitalWrite(temp[j], HIGH);
                    delay(1);
                    digitalWrite(temp[j], LOW);
                }
        }
    }
}

void closedHand() {
    for(int i = 0; i < NumRCS; i++) {
        digitalWrite(LED_ROWS[i], HIGH);
        switch(i) {
            case 2:
                int temp[] = {22, 10, 13, 19};
                for(int j = 0; j < 4; j++) {
                    digitalWrite(temp[j], HIGH);
                    delay(1);
                    digitalWrite(temp[j], LOW);
                }
            case 3, 4: 
                for(int j = 0; j < NumRCS; j++) {
                    digitalWrite(LED_CLMS[j], HIGH);
                    delay(1);
                    digitalWrite(LED_CLMS[j], LOW);
                }
            case 5:
                int temp[] = {27, 22, 10, 13, 19};
                for(int j = 0; j < 5; j++) {
                    digitalWrite(temp[j], HIGH);
                    delay(1);
                    digitalWrite(temp[j], LOW);
                }
            case 6:
                int temp[] = {22, 10};
                for(int j = 0; j < 2; j++) {
                    digitalWrite(temp[j], HIGH);
                    delay(1);
                    digitalWrite(temp[j], LOW);
                }
        }
    }
}

void mouthOpen() {
    for(int i = 0; i < NumRCS; i++) {
        digitalWrite(LED_ROWS[i], HIGH);
        switch(i) {
            case 1, 5:
                int temp[] = {22, 10, 13};
                for(int j = 0; j < 3; j++) {
                    digitalWrite(temp[j], HIGH);
                    delay(1);
                    digitalWrite(temp[j], LOW);
                }
            case 2, 4:
                for(int j = 0; j < NumRCS; j++) {
                    digitalWrite(temp[j], HIGH);
                    delay(1);
                    digitalWrite(temp[j], LOW);
                }
            case 3:
                digitalWrite(17, HIGH);
                digitalWrite(26, HIGH);
                delay(1);
                digitalWrite(17, LOW);
                digitalWrite(26, LOW);
        }
    }
}

void mouthClosed() {
    for(int i = 0; i < NumRCS; i++) {
        digitalWrite(LED_ROWS[i], HIGH);
        switch(i) {
            case 2, 5:
                int temp[] = {22, 10, 13};
                for(int j = 0; j < 3; j++) {
                    digitalWrite(temp[j], HIGH);
                    delay(1);
                    digitalWrite(temp[j], LOW);
                }
            case 3, 4:
                for(int j = 0; j < NumRCS; j++) {
                    digitalWrite(LED_CLMS[j], HIGH);
                    delay(1);
                    digitalWrite(LED_CLMS[j], LOW);
                }
        }
    }
}

void lasso() {
    for(int i = 0; i < NumRCS; i++) {
        digitalWrite(LED_ROWS[i], HIGH);
        switch(i) {
            case 0:
                int temp[] = {27, 19};
                for(int j = 0; j < 2; j++) {
                    digitalWrite(temp[j], HIGH);
                    delay(1);
                    digitalWrite(temp[j], LOW);
                }
            case 1:
                int temp[] = {27, 22, 13, 19};
                for(int j = 0; j < 4; j++) {
                    digitalWrite(temp[j], HIGH);
                    delay(1);
                    digitalWrite(temp[j], LOW);
                }
            case 2: 
                int temp[] = {22, 10, 13};
                for(int j = 0; j < 3; j++) {
                    digitalWrite(temp[j], HIGH);
                    delay(1);
                    digitalWrite(temp[j], LOW);
                }
            case 3, 4: 
                for(int j = 0; j < NumRCS; j++) {
                    digitalWrite(LED_CLMS[j], HIGH);
                    delay(1);
                    digitalWrite(LED_CLMS[j], LOW);
                }
            case 5:
                int temp[] = {27, 22, 10, 13, 19};
                for(int j = 0; j < 5; j++) {
                    digitalWrite(temp[j], HIGH);
                    delay(1);
                    digitalWrite(temp[j], LOW);
                }
            case 6:
                int temp[] = {22, 10};
                for(int j = 0; j < 2; j++) {
                    digitalWrite(temp[j], HIGH);
                    delay(1);
                    digitalWrite(temp[j], LOW);
                }
        }
    }
}
