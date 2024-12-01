#include <main.h>

#define contde 200

int16 V_INTERVALO_INCREMENTO = 1000;
int16 contador = 0;
int8 unidade, dezena, centena, milhar;

int8 fase = 0;
int8 inicio;
int16 velocidade;
int1 unidade_ativo = 0, dezena_ativo = 0, centena_ativo = 0, milhar_ativo = 0;
int1 unidade_ativode = 0, dezena_ativode = 0, centena_ativode = 0, milhar_ativode = 0;
int1 comeca = 0;

int8 mostra_u, mostra_d, mostra_c, mostra_m;
int8 contador_u = 0, contador_d = 0, contador_c = 0, contador_m = 0;
int8 decremento_u = 0, decremento_d = 0, decremento_c = 0, decremento_m = 0;

int1 para_1 = 0, para_2 = 0, para_3 = 0;

int16 unidade_ativodecont, dezena_ativodecont, centena_ativodecont, milhar_ativodecont;

int8 contador_tela_inicial = 0;
int8 finalfase = 100;
int1 vez_contador_tela_inicial = 0;

const int8 listadisplay4[] = {0x08,0x00,0x00,0x01,0x02,0x04,0b01001000,0b01000000,0b01000000,0b01000001,0b01000010,0b01000100};
const int8 listadisplay3[] = {0x00,0x08,0x01,0x00,0x00,0x00,0x00,0b01001000,0b01000001,0x00,0x00,0x00};
const int8 listadisplay2[] = {0x00,0x01,0x08,0x00,0x00,0x00,0x00,0b01000001,0b01001000,0x00,0x00,0x00};
const int8 listadisplay1[] = {0x01,0x00,0x00,0x08,0x10,0x20,0b01000001,0b01000000,0b01000000,0b01001000,0b01010000,0b01100000};

const int8 u1 [] = {4, 3, 3, 3, 5, 5, 8, 8, 4, 3, 3, 3, 5, 5, 8, 8, 5, 10, 11, 11, 12, 12};
const int8 d1 [] = {3,0 , 2, 6, 4, 2, 2, 3, 2, 1, 1, 4, 2, 5,0, 2, 6, 4, 2, 2, 3, 2, 1, 1, 4, 2, 5, 10, 10, 10, 11, 11, 12, 12};
const int8 c1 [] = {3,0 , 2, 6, 2, 5, 2, 2, 7, 5, 2, 3, 2, 6,0, 2, 5, 2, 2, 7, 5, 2, 1, 10, 10, 10, 10, 10, 11, 11, 12, 12};
const int8 m1 [] = {2, 1, 1, 1, 9, 5, 3, 3, 2, 4, 8, 1, 1, 1, 9, 5, 3, 3, 2, 4, 8, 10, 10, 10, 10, 11, 11, 12, 12};

const int8 u2[] = {1, 5, 2, 1, 5, 2, 1, 2, 1, 1, 1,1, 5, 2, 1, 5, 2, 1, 2, 1, 1, 1, 1, 8, 7,6,4, 10, 10, 10, 10, 11, 11, 11, 12, 12};
const int8 d2[] = {2, 3, 2, 1, 1, 3, 2, 1, 2, 1, 1, 1, 3, 3, 2, 1, 1, 2, 2, 1, 2, 1, 1, 1, 3,8, 6, 1,6,4, 10, 10, 10, 11, 11, 11, 12, 12};
const int8 c2[] = {3, 1, 3, 1, 2, 1, 3, 1, 3, 1, 7,1, 3, 1, 2, 1, 3, 1, 3, 1, 7, 1, 1, 2, 5, 3,6,4, 10, 10, 11, 11, 11, 12, 12};
const int8 m2[] = {4, 5, 4, 5, 3, 1, 1, 7, 5, 4, 5, 3, 1, 1, 7, 1, 1, 1, 4, 5,6,4, 10, 11, 11, 11, 12, 12};

const int8 u3[] = {2, 2, 2, 2, 3, 3, 2, 1, 1, 1, 1, 3, 1, 4, 6, 2, 2, 5, 2, 2, 2, 2, 4, 2, 5, 2, 1, 1, 1, 1, 1, 11, 11, 11, 12, 12};
const int8 d3[] = {2, 2, 2, 2, 3, 3, 4, 3, 3, 1, 1, 2, 1, 1, 4, 2, 5, 2, 2, 2, 2, 2, 3, 1, 2, 3, 2, 2, 1, 10, 10, 10, 10, 10, 10, 11, 11, 11, 12, 12};
const int8 c3[] = {2, 2, 2, 2, 3, 6, 3, 1, 1, 1, 2, 1, 1, 3, 1, 2, 5, 2, 2, 2, 2, 2, 2, 2, 3, 2, 1, 2, 3, 1, 1, 10, 10, 10, 10, 11, 11, 11, 12, 12};
const int8 m3[] = {2, 2, 2, 2, 3, 3, 2, 1, 1, 3, 1, 2, 1, 7, 5, 2, 2, 2, 2, 2, 2, 2, 1, 5, 2, 2, 4, 1, 1, 1, 10, 10, 11, 11, 11, 12, 12};

const int8 u4[] = {6, 1, 7, 3, 2, 3, 7, 7, 5,6, 1, 7, 3, 2, 3, 7, 7, 5, 10, 10, 11, 11, 12, 12};
const int8 d4[] = {5, 1, 1, 5, 3, 4, 3, 3, 1, 1, 1, 3, 6,5, 1, 1, 5, 3, 4, 3, 3, 1, 1, 1, 3, 6, 10, 10, 11, 11, 12, 12};
const int8 c4[] = {4, 5, 1, 1, 3, 6, 3, 1, 1, 3, 1, 1, 7,4, 5, 1, 1, 3, 6, 3, 1, 1, 3, 1, 1, 7, 10, 10, 11, 11, 12, 12};
const int8 m4[] = {3, 7, 1, 3, 8, 3, 9, 8, 3, 7, 1, 3, 8, 3, 9, 8,10, 10, 11, 11, 12, 12};

const int8 display_numbers[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F, 0b00001000,0b01001000,0b01001001};

int1 pasou_fase_1 = 0;
int1 pasou_fase_2 = 0;
int1 pasou_fase_3 = 0;
int1 pasou_fase_4 = 0;

int16 contador_ms = 0;

void verificaerro0();
void verificaerro9();

void tela_inicial();

void escolha_de_fase();

void fase1();
void fase4();
void fase3();
void fase2();

void falha();

void delay(int8 n);
void verificabotao();
void atualiza_display();

void lista_u();
void lista_d();
void lista_c();
void lista_m();
void testalista();

void chama();

#INT_TIMER0
void TIMER0_isr(void) {
   set_timer0(get_timer0() + 131); // Ajuste do temporizador para 1ms

   contador_ms++; // Incrementa o contador de milissegundos

   if (contador_ms >= V_INTERVALO_INCREMENTO) { // Se atingir o intervalo de 1 segundo
      contador_ms = 0; // Reseta o contador de milissegundos

      para_3 = 0;

      contador_tela_inicial++;

      if (inicio) {
         inicio--;
         decremento_u = 0;
         contador_u = 0;
         decremento_d = 0;
         contador_d = 0;
         decremento_c = 0;
         contador_c = 0;
         decremento_m = 0;
         contador_m = 0;
      }

      if (fase && comeca) {
         contador++;
         verificaerro9();
         verificaerro0();
         unidade_ativo = 0;
         dezena_ativo = 0;
         centena_ativo = 0;
         milhar_ativo = 0;
      }

      if (contador_tela_inicial > 5) { // Se o contador atingir 0, reseta para 9999
         contador_tela_inicial = 0;
      }
      testalista();

   }
}
void main() {
   setup_timer_0(RTCC_INTERNAL | RTCC_DIV_8 | RTCC_8_BIT); // 1ms overflow
   enable_interrupts(INT_TIMER0);
   enable_interrupts(GLOBAL); // Habilita interrup��es globais

   output_d(0);

   fase = 0;
   unidade_ativodecont = contde;
   dezena_ativodecont = contde;
   centena_ativodecont = contde;
   milhar_ativodecont = contde;

   while (TRUE) {

      if (!fase) {
         V_INTERVALO_INCREMENTO = V_INTERVALO_INCREMENTO / (3 * (pasou_fase_1 + pasou_fase_2 + pasou_fase_3 + pasou_fase_4) + 5);
         tela_inicial();
         V_INTERVALO_INCREMENTO = V_INTERVALO_INCREMENTO * (3 * (pasou_fase_1 + pasou_fase_2 + pasou_fase_3 + pasou_fase_4) + 5);
         escolha_de_fase();

         if (fase == 1) {
            contador = 0;
            comeca = 1;
            velocidade = V_INTERVALO_INCREMENTO;
            para_1 = 0;
            para_2 = 0;
            while (fase) {
               fase1();
            }
            comeca = 0;

            if (contador < finalfase) {
               falha();
               contador = 0;
            }

            if (contador >= finalfase + 4)
               pasou_fase_1 = 1;

            V_INTERVALO_INCREMENTO = velocidade;
            fase = 0;

         }

         if (fase == 2) {
            contador = 0;
            comeca = 1;
            velocidade = V_INTERVALO_INCREMENTO;
            para_1 = 0;
            para_2 = 0;
            while (fase) {
               fase2();
            }
            comeca = 0;

            if (contador < finalfase) {
               falha();
               contador = 0;
            }
            if (contador >= finalfase + 4)
               pasou_fase_2 = 1;

            V_INTERVALO_INCREMENTO = velocidade;
            fase = 0;
         }

         if (fase == 3) {
            contador = 0;
            comeca = 1;
            velocidade = V_INTERVALO_INCREMENTO;
            para_1 = 0;
            para_2 = 0;
            while (fase) {
               fase3();
            }
            comeca = 0;

            if (contador < finalfase) {
               falha();
               contador = 0;
            }
            if (contador >= finalfase + 4)
               pasou_fase_3 = 1;

            V_INTERVALO_INCREMENTO = velocidade;
            fase = 0;

         }

         if (fase == 4) {
            contador = 0;
            comeca = 1;
            velocidade = V_INTERVALO_INCREMENTO;
            para_1 = 0;
            para_2 = 0;
            V_INTERVALO_INCREMENTO = V_INTERVALO_INCREMENTO * 0.60;
            while (fase) {
               fase4();
            }
            comeca = 0;

            if (contador < finalfase) {
               falha();
               contador = 0;
            }
            if (contador >= finalfase + 4)
               pasou_fase_4 = 1;

            V_INTERVALO_INCREMENTO = velocidade;
            fase = 0;
         }

      }
      contador = 0;
   }
}

void fase1() {
   chama();

   atualiza_display(); // Atualiza o display
   verificabotao();

   if (contador == 50 && !para_1) {
      V_INTERVALO_INCREMENTO = V_INTERVALO_INCREMENTO * 0.85;
      para_1 = 1;
   }

   if (contador == 75 && !para_2) {
      V_INTERVALO_INCREMENTO = V_INTERVALO_INCREMENTO * 0.85;
      para_2 = 1;
   }

   if (contador == finalfase + 5)
      fase = 0;

}

void fase2() {
   chama();

   atualiza_display(); // Atualiza o display
   verificabotao();

   if (contador == 12 && !para_1) {
      V_INTERVALO_INCREMENTO = V_INTERVALO_INCREMENTO * 0.90;
      para_1 = 1;
   }

   if (contador == 24 && !para_2) {
      V_INTERVALO_INCREMENTO = velocidade;
      para_2 = 1;
      para_1 = 0;
   }

   if (contador == 48 && !para_1) {
      V_INTERVALO_INCREMENTO = V_INTERVALO_INCREMENTO * 0.80;
      para_2 = 0;
      para_1 = 1;
   }

   if (contador == 72 && !para_2) {
      V_INTERVALO_INCREMENTO = V_INTERVALO_INCREMENTO * 0.90;
      para_2 = 1;
      para_1 = 0;
   }

   if (contador == 96 && !para_1) {
      V_INTERVALO_INCREMENTO = V_INTERVALO_INCREMENTO * 0.90;
      para_1 = 1;
   }

   if (contador == finalfase + 5)
      fase = 0;
}

void fase3() {

   chama();
   atualiza_display(); // Atualiza o display
   verificabotao();

   if ((contador + 1) % 3 == 0 && !para_1 && contador < 30) {
      V_INTERVALO_INCREMENTO = V_INTERVALO_INCREMENTO * 0.94;
      para_1 = 1;
      para_2 = 0;
   }

   if ((contador + 1) % 4 == 0 && !para_2 && (contador + 1) % 12) {
      para_1 = 0;
      para_2 = 1;
   }

   if (contador == finalfase + 5)
      fase = 0;

}

void fase4() {

   chama();

   atualiza_display(); // Atualiza o display
   verificabotao();

   if (contador == finalfase + 5)
      fase = 0;

}

void chama() {
   unidade = mostra_u;
   dezena = mostra_d;
   centena = mostra_c;
   milhar = mostra_m;
}

void escolha_de_fase() {

   if (!input(S4)) {
      fase = 4;
   }

   if (!input(S3)) {
      fase = 3;
   }
   if (!input(S2)) {
      fase = 2;
   }
   if (!input(S1)) {
      fase = 1;

   }
   if (fase) {

      output_low(DM);
      output_low(DD);
      output_low(DC);
      output_low(DU);
      inicio = 3;
      V_INTERVALO_INCREMENTO = V_INTERVALO_INCREMENTO * 2;
      output_high(DU);

      while (inicio > 0) {
         unidade = inicio;
         dezena = 12;
         centena = 12; // Unidades
         milhar = inicio;
         atualiza_display();
         delay(30);

      }
      V_INTERVALO_INCREMENTO = V_INTERVALO_INCREMENTO / 2;
   }
}

void falha() {

   inicio = 7;

   unidade = 12;
   if ((contador % 10)) {
      dezena = -(contador % 10) + 10;
      centena = -((contador / 10) % 10) + 9;
   } else {
      dezena = 0;
      centena = -((contador / 10) % 10) + 10;
   }

   milhar = 12;

   while (inicio) {
      atualiza_display();

      delay(15);
   }
}

void tela_inicial() {

   if (contador_tela_inicial == 1 || contador_tela_inicial == 2) {

      output_low(DM);
      output_low(DU);

      if (vez_contador_tela_inicial) {
         output_low(DC);
         output_high(DD);
         if (!pasou_fase_3) {
            output_d(listadisplay3[contador_tela_inicial]);
         } else {
            output_d(listadisplay3[contador_tela_inicial + 6]);
         }

         vez_contador_tela_inicial = 0;
      } else {
         output_low(DD);
         output_high(DC);

         if (!pasou_fase_2) {
            output_d(listadisplay2[contador_tela_inicial]);
         } else {
            output_d(listadisplay2[contador_tela_inicial + 6]);
         }

         vez_contador_tela_inicial = 1;
      }

   } else {
      output_low(DD);
      output_low(DC);

      if (vez_contador_tela_inicial) {
         output_low(DM);
         output_high(DU);

         if (!pasou_fase_4) {
            output_d(listadisplay4[contador_tela_inicial]);
         } else {
            output_d(listadisplay4[contador_tela_inicial + 6]);
         }

         vez_contador_tela_inicial = 0;
      } else {
         output_low(DU);
         output_high(DM);

         if (!pasou_fase_1) {
            output_d(listadisplay1[contador_tela_inicial]);
         } else {
            output_d(listadisplay1[contador_tela_inicial + 6]);
         }

         vez_contador_tela_inicial = 1;
      }
   }
   delay(35);

}

void atualiza_display() {
   delay(25);
   if (input_state(DU)) {
      output_low(DU);
      output_high(DD);
      output_d(display_numbers[dezena]);
   } else if (input_state(DD)) {
      output_low(DD);
      output_high(DC);
      output_d(display_numbers[centena]);
   } else if (input_state(DC)) {
      output_low(DC);
      output_high(DM);
      output_d(display_numbers[milhar]);
   } else {
      output_low(DM);
      output_high(DU);
      output_d(display_numbers[unidade]);
   }
}

void delay(int8 n) {
   int8 i;
   for (i = 0; i < n; i++) {
      // NOP
   }
}

void verificabotao() {
   if (!input(S4) && !unidade_ativode) {
      unidade_ativo = 1;
      unidade_ativode = 1;
   }

   if (!input(S3) && !dezena_ativode) {
      dezena_ativo = 1;
      dezena_ativode = 1;
   }
   if (!input(S2) && !centena_ativode) {
      centena_ativo = 1;
      centena_ativode = 1;
   }
   if (!input(S1) && !milhar_ativode) {
      milhar_ativo = 1;
      milhar_ativode = 1;
   }

   if (unidade_ativode) {
      unidade_ativodecont--;
      if (!unidade_ativodecont) {
         unidade_ativodecont = contde;
         unidade_ativode = 0;
      }
   }
   if (dezena_ativode) {
      dezena_ativodecont--;
      if (!dezena_ativodecont) {
         dezena_ativodecont = contde;
         dezena_ativode = 0;
      }
   }
   if (centena_ativode) {
      centena_ativodecont--;
      if (!centena_ativodecont) {
         centena_ativodecont = contde;
         centena_ativode = 0;
      }
   }
   if (milhar_ativode) {
      milhar_ativodecont--;
      if (!milhar_ativodecont) {
         milhar_ativodecont = contde;
         milhar_ativode = 0;
      }
   }

}

void verificaerro9() {
   if ((unidade_ativo && unidade) || (dezena_ativo && dezena) || (centena_ativo && centena) || (milhar_ativo && milhar)) {
      fase = 0;
   }
}

void verificaerro0() {
   // Se a unidade est� ativa e seu valor � diferente de zero, reseta o contador
   if ((!unidade_ativo && !unidade) || (!dezena_ativo && !dezena) || (!centena_ativo && !centena) || (!milhar_ativo && !milhar)) {
      fase = 0;
   }

}

void testalista() {
   lista_u();
   lista_d();
   lista_c();
   lista_m();

}

void lista_u() {

   if (fase == 1)
      mostra_u = u1[contador_u] - decremento_u;

   if (fase == 2)
      mostra_u = u2[contador_u] - decremento_u;

   if (fase == 3)
      mostra_u = u3[contador_u] - decremento_u;

   if (fase == 4)
      mostra_u = u4[contador_u] - decremento_u;

   if (mostra_u <= 9) {
      if (!mostra_u) {
         contador_u++;
         decremento_u = 0;
      } else {
         decremento_u++;
      }
   } else {
      contador_u++;
   }

}
void lista_d() {

   if (fase == 1)
      mostra_d = d1[contador_d] - decremento_d;

   if (fase == 2)
      mostra_d = d2[contador_d] - decremento_d;

   if (fase == 3)
      mostra_d = d3[contador_d] - decremento_d;

   if (fase == 4)
      mostra_d = d4[contador_d] - decremento_d;

   if (mostra_d <= 9) {
      if (!mostra_d) {
         contador_d++;
         decremento_d = 0;
      } else {
         decremento_d++;
      }
   } else {
      contador_d++;
   }

}
void lista_c() {

   if (fase == 1)
      mostra_c = c1[contador_c] - decremento_c;

   if (fase == 2)
      mostra_c = c2[contador_c] - decremento_c;

   if (fase == 3)
      mostra_c = c3[contador_c] - decremento_c;

   if (fase == 4)
      mostra_c = c4[contador_c] - decremento_c;

   if (mostra_c <= 9) {
      if (!mostra_c) {
         contador_c++;
         decremento_c = 0;
      } else {
         decremento_c++;
      }
   } else {
      contador_c++;
   }

}
void lista_m() {

   if (fase == 1)
      mostra_m = m1[contador_m] - decremento_m;

   if (fase == 2)
      mostra_m = m2[contador_m] - decremento_m;

   if (fase == 3)
      mostra_m = m3[contador_m] - decremento_m;

   if (fase == 4)
      mostra_m = m4[contador_m] - decremento_m;

   if (mostra_m <= 9) {
      if (!mostra_m) {
         contador_m++;
         decremento_m = 0;
      } else {
         decremento_m++;
      }
   } else {
      contador_m++;
   }

}
