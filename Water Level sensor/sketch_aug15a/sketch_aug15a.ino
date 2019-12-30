// MODULES
#include <LiquidCrystal.h>

int wtr = A1;

// Create a custom value for the LCD screen
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  
  

}

void loop() {
  int value = analogRead(wtr); //Read data from analog pin and store it to value variable
  lcd.setCursor(0,0);
  
  if (value<=480){ 
    lcd.print("0mm - Empty!"); 
  }
  else if (value>480 && value<=530){ 
    lcd.print("0mm to 5mm"); 
  }
  else if (value>530 && value<=615){ 
    lcd.print("5mm to 10mm"); 
  }
  else if (value>615 && value<=660){ 
    lcd.print("10mm to 15mm"); 
  } 
  else if (value>660 && value<=680){ 
    lcd.print("15mm to 20mm"); 
  }
  else if (value>680 && value<=690){ 
    lcd.print("20mm to 25mm"); 
  }
  else if (value>690 && value<=700){ 
    lcd.print("25mm to 30mm"); 
  }
  else if (value>700 && value<=705){ 
    lcd.print("30mm to 35mm"); 
  }
  else if (value>705){ 
    lcd.print("35mm to 40mm"); 
  }
  free(value);
  delay(5000); // Check for new value every 5 sec

}
