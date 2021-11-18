/* Daniel da Silva Severiano dos Santos - cartao numero - turma
   Programa Final da disciplina de
 */

//includes
#include "raylib.h" // lint-disable-line no-use-before-define
#include "game.h"
#include "draw.h"
#include "level.h"

//typedefs
typedef enum GameScreen { SPLASH = 0, MAINMENU, GAME, SCORE, HELP, ABOUT }                     GameScreen;
typedef enum MainMenuOption { NEWGAME = 0, CONTINUE, LOADMAP, RANKING, HELPS, ABOUTS, EXIT }   MainMenuOption;

typedef struct Animation {
    int currentFrame;
    int frameSpeed;

    float marioWidth;
    float marioHeight;
    Rectangle marioLeft;
    Rectangle marioRight;
} Animation;

Animation initAnimation() {
    Animation aux;

    aux.currentFrame = 0;
    aux.frameSpeed = 12;

    aux.marioWidth = 16.0;
    aux.marioHeight = 20.0;

    aux.marioLeft.x = 3.0;
    aux.marioLeft.y =  603.0f;
    aux.marioLeft.width = aux.marioWidth;
    aux.marioLeft.height = aux.marioHeight;

    aux.marioRight.x = 3.0;
    aux.marioRight.y =  633.0f;
    aux.marioRight.width = aux.marioWidth;
    aux.marioRight.height = aux.marioHeight;

    return aux;
}

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

int main() {
    //Variáveis da tela
    const int screenWidth = 1200;
    const int screenHeight = 700;
    const int splashscreenTimeout = 300;
    const char *windowTitle = "Super Mario DOS";

    MainMenuOption currentMainMenuOption = NEWGAME; //enum para listar a opção selecionada do menu principal
    int exit = 0; //flag para encerrar o jogo

    GameScreen currentScreen = SPLASH;

    Animation animation = initAnimation(); //Inicializa variáveis referentes a animações, como frame speed e tamanhos de texturas
    int framesCounter = 0;

    InitWindow(screenWidth, screenHeight, windowTitle); //Inicializa janela da raylib

    //Inicialização de recursos
    Font fontMario = LoadFontEx("resources/SuperMario256.ttf", 46, 0, 250); //Carrega a fonte para ser usada na janela
    Texture2D marioTextures = LoadTexture("resources/texturemap.png");

    Vector2 marioPosition = { 5.0f, 5.0f };

    SetExitKey(KEY_BACKSPACE); //Libera ESC para uso e encerra imediatamente a janela com Backspace

    l_LoadLevel("resources/fases/fase1.txt");
    // g_CreateBlock(5.0, 5.0, 0);

    SetTargetFPS(60);

    //Loop do jogo
    while (!WindowShouldClose() && !exit) {
        //Lógica
        switch (currentScreen) {
            case SPLASH: {
                //Tela de inicialização

                framesCounter++;

                //Temporizador da tela de inicialização (pressione enter para pular)
                if (framesCounter > splashscreenTimeout || IsKeyPressed(KEY_ENTER)) {
                    currentScreen = MAINMENU;
                }
            } break;

            case MAINMENU: {
                if (IsKeyPressed(KEY_ENTER) || IsKeyPressed(KEY_ESCAPE)) {
                    if (currentMainMenuOption == EXIT || IsKeyPressed(KEY_ESCAPE)) exit = 1;
                    else if (currentMainMenuOption == HELPS) currentScreen = HELP;
                    else if (currentMainMenuOption == ABOUTS) currentScreen = ABOUT;
                    else if (currentMainMenuOption == RANKING) currentScreen = SCORE;
                    else {
                        currentScreen = GAME;

                        if (currentMainMenuOption == NEWGAME) {
                            //load stage 1
                        } else if (currentMainMenuOption == CONTINUE) {
                            //loadsave
                        } else if (currentMainMenuOption == LOADMAP) {
                            //loadmap
                        }
                    }
                } else if (IsKeyPressed(KEY_DOWN)) {
                    if (currentMainMenuOption == 6) currentMainMenuOption = 0;
                    else currentMainMenuOption++;
                } else if (IsKeyPressed(KEY_UP)) {
                    if (!currentMainMenuOption) currentMainMenuOption = 6;
                    else currentMainMenuOption--;
                }
            } break;

            case GAME: {
                if (IsKeyPressed(KEY_ESCAPE)) {
                    //TODO: pause game, option to save progress
                } else if (IsKeyPressed(KEY_LEFT) || IsKeyPressed(KEY_A)) {
                    //L
                } else if (IsKeyPressed(KEY_RIGHT) || IsKeyPressed(KEY_D)) {
                    //R
                } else if (IsKeyPressed(KEY_DOWN) || IsKeyPressed(KEY_S)) {
                    //go down
                } else if (IsKeyPressed(KEY_UP) || IsKeyPressed(KEY_W) || IsKeyPressed(KEY_SPACE)) {
                    //jump
                } else {
                    //player doesnt move/ necessary? or just run after ifs
                }
            } break;

            case SCORE: {
                // TODO: add scoreboard
                if (IsKeyPressed(KEY_ENTER) || IsKeyPressed(KEY_ESCAPE)) {
                    currentScreen = MAINMENU;
                }
            } break;

            case HELP: {
                if (IsKeyPressed(KEY_ENTER) || IsKeyPressed(KEY_ESCAPE)) {
                    currentScreen = MAINMENU;
                }
            } break;

            case ABOUT: {
                // TODO: add section
                if (IsKeyPressed(KEY_ENTER) || IsKeyPressed(KEY_ESCAPE)) {
                    currentScreen = MAINMENU;
                }
            } break;

            default: break;
        }
        //----------------------------------------------------------------------------------
        //Gráficos
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(BLACK);

        switch (currentScreen) {
            case SPLASH: {
                drawSplash(fontMario, windowTitle);

                if (framesCounter < splashscreenTimeout / 2) {
                    DrawRectangle(0, 0, screenWidth, screenHeight - 100, Fade(BLACK, (splashscreenTimeout / 2 - framesCounter) / (splashscreenTimeout * 0.5)));
                } else {
                    DrawRectangle(0, 0, screenWidth, screenHeight - 100, Fade(BLACK, (framesCounter - splashscreenTimeout / 2) / (splashscreenTimeout * 0.5)));
                }
            } break;

            case MAINMENU: {
                drawMainMenu(fontMario, windowTitle, currentMainMenuOption);
            } break;

            case GAME: {
                // TODO: Draw GAMEPLAY screen here!
                // DrawRectangle(0, 0, screenWidth, screenHeight, BLACK);
                // DrawText("GAME SCREEN", 20, 20, 40, MAROON);
                // DrawText("PRESS ENTER or TAP to JUMP to ENDING SCREEN", 130, 220, 20, MAROON);
                d_Draw();
            } break;

            case SCORE: {
                // TODO: Draw ENDING screen here!
                DrawRectangle(0, 0, screenWidth, screenHeight, BLUE);
                DrawText("SCORE SCREEN", 20, 20, 40, DARKBLUE);
                DrawText("PRESS ENTER or TAP to RETURN to TITLE SCREEN", 120, 220, 20, DARKBLUE);
            } break;

            case HELP: {
                drawHelp(fontMario);
            } break;

            case ABOUT: {
                //bla
            } break;

            default: break;
        }

        EndDrawing();
    }

    UnloadTexture(marioTextures);
    CloseWindow();

    return 0;
}
