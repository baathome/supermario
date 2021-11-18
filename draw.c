#include "draw.h"
#include "raylib.h"

void drawSplash(Font font, const char *text) { //Desenha a tela de inicialização
    DrawTextEx(font, text, (Vector2) { 126.0f, 275.0f }, (float)font.baseSize * 1.75 + 5, 2, BROWN);
    DrawTextEx(font, text, (Vector2) { 150.0f, 275.0f }, (float)font.baseSize * 1.75, 2, MAROON);

    DrawTextEx(font, "pressione [Enter] para pular", (Vector2) { 815.0f, 670.0f }, (float)font.baseSize * 0.40, 2, BROWN);
}

void drawHelp(Font font) { //Desenha a tela de ajuda (manual)
    DrawTextEx(font, "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tAtaque os inimigos por baixo para enfraquece-los\n\t\t\t\tDepois de enfraquecidos, voce pode mata-los simplesmente passando por cima deles\n\t\t\t\t\t\tBata na caixa especial para adquirir grandes poderes (sem as responsabilidades)", (Vector2) { 5.0f, 50.0f }, (float)font.baseSize * 0.45, 0, BROWN);
    DrawTextEx(font, "\t\t\t\tA / <-\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tIr para a esquerda\n\n\t\t\t\tD / ->\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t Ir para a direita\n\n\t\t\t\tS / v\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tDescer da plataforma atual\n\nW / ^ / [espaco]\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tPular\n\n\t\t\t\t\tESC\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tPausar\n\n\n\n\tAperte ESC ou Enter para retornar ao menu principal", (Vector2) { 150.0f, 230.0f }, (float)font.baseSize * 0.5, 2, BROWN);
}

void drawMainMenu(Font font, const char *text, int currentMainMenuOption) { //Desenha o menu principal
    Color mainMenuSelectedArray[7];     //array de cores para pintar a opção selecionada do menu principal

    DrawTextEx(font, text, (Vector2) { 272.0f, 75.0f }, (float)font.baseSize * 1.2 + 2, 2, BROWN);
    DrawTextEx(font, text, (Vector2) { 280.0f, 75.0f }, (float)font.baseSize * 1.2, 2, MAROON);

    for (int i = 0; i < 7; i++) {
        mainMenuSelectedArray[i] = WHITE;
    }

    mainMenuSelectedArray[currentMainMenuOption] = BLUE;

    DrawText("Novo Jogo", 500, 200, 36, mainMenuSelectedArray[0]);
    DrawText("Continuar", 506, 250, 36, mainMenuSelectedArray[1]);
    DrawText("Carregar Mapa", 450, 300, 36, mainMenuSelectedArray[2]);
    DrawText("Ranking", 522, 350, 36, mainMenuSelectedArray[3]);
    DrawText("Ajuda", 542, 400, 36, mainMenuSelectedArray[4]);
    DrawText("Sobre", 538, 450, 36, mainMenuSelectedArray[5]);
    DrawText("Sair", 557, 500, 36, mainMenuSelectedArray[6]);
}
