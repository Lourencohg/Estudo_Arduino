#include <LiquidCrystal.h>

// Mapeamento dos pinos: (RS, E, D4, D5, D6, D7)
LiquidCrystal lcd(19, 23, 18, 17, 16, 15);

String textoAtual = "";

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
}

void loop() {
  // 1. Verifica se chegou uma mensagem nova pela Serial
  if (Serial.available()) {
    textoAtual = Serial.readString();
    textoAtual.trim();
  }

  // 2. Se temos um texto, fazemos a rolagem em carrossel
  if (textoAtual.length() > 0) {
    
    // Criamos uma mensagem estendida com 16 espaços antes e depois do texto
    String textoFormatado = "                " + textoAtual + "                ";

    // Percorremos o texto cortando janelas de 16 caracteres
    for (int i = 0; i < textoAtual.length() + 16; i++) {
      
      // Se chegar mensagem nova no meio da animação, cancela para atualizar
      if (Serial.available()) {
        break;
      }

      // Pega exatamente 16 caracteres a partir da posição 'i'
      String tela = textoFormatado.substring(i, i + 16);

      lcd.setCursor(0, 0); // Vai para o início da primeira linha
      lcd.print(tela);    // Imprime a janela de 16 caracteres

      delay(300);          // Velocidade da rolagem
    }
  }
}