/* Daniel da Silva Severiano dos Santos - cartao numero - turma
   Programa Final da disciplina de
 */

//includes
#include "raylib.h" // lint-disable-line no-use-before-define

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
    aux.marioLeft.x = aux.marioWidth;
    aux.marioLeft.x = aux.marioHeight;

    aux.marioRight.x = 3.0;
    aux.marioRight.y =  633.0f;
    aux.marioRight.x = aux.marioWidth;
    aux.marioRight.x = aux.marioHeight;

    return aux;
}

int main() {
    //Variáveis da tela
    const int screenWidth = 1200;
    const int screenHeight = 700;
    const int splashscreenTimeout = 300;
    const char *windowTitle = "Super Mario DOS";

    MainMenuOption currentMainMenuOption = NEWGAME; //enum para listar a opção selecionada do menu principal
    int exit = 0; //flag para encerrar o jogo
    Color mainMenuSelectedArray[7]; //array de cores para pintar a opção selecionada do menu principal

    GameScreen currentScreen = SPLASH;

    Animation animation = initAnimation(); //Inicializa variáveis referentes a animações, como frame speed e tamanhos de texturas
    int framesCounter = 0;

    InitWindow(screenWidth, screenHeight, windowTitle); //Inicializa janela da raylib

    //Inicialização de recursos
    Font fontMario = LoadFontEx("resources/SuperMario256.ttf", 46, 0, 250); //Carrega a fonte para ser usada na janela
    Texture2D marioTextures = LoadTexture("resources/texturemap.png");







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
                // TODO: Update TITLE screen variables here!

                // Press enter to change to GAMEPLAY screen
                if (IsKeyPressed(KEY_ENTER)) {
                    if (currentMainMenuOption == EXIT) exit = 1;
                    else if (currentMainMenuOption == ABOUTS) currentScreen == ABOUT;
                    else if (currentMainMenuOption == HELPS) currentScreen == HELP;
                    else if (currentMainMenuOption == RANKING) currentScreen == SCORE;
                    else {
                        currentScreen = GAME;

                        if (currentMainMenuOption == NEWGAME) {
                        } else if (currentMainMenuOption == CONTINUE) {
                        } else if (currentMainMenuOption == LOADMAP) {
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
                // TODO: Update GAMEPLAY screen variables here!

                // Press enter to change to ENDING screen
                if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP)) {
                    currentScreen = SCORE;
                }
            } break;

            case SCORE: {
                // TODO: Update ENDING screen variables here!

                // Press enter to return to TITLE screen
                if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP)) {
                    currentScreen = MAINMENU;
                }
            } break;

            case HELP: {
                // TODO: Update ENDING screen variables here!

                // Press enter to return to TITLE screen
                if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP)) {
                    currentScreen = MAINMENU;
                }
            } break;

            case ABOUT: {
                // TODO: Update ENDING screen variables here!

                // Press enter to return to TITLE screen
                if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP)) {
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
                //Tela de inicialização
                DrawTextEx(fontMario, windowTitle, (Vector2) { 126.0f, 275.0f }, (float)fontMario.baseSize * 1.75 + 5, 2, BROWN);
                DrawTextEx(fontMario, windowTitle, (Vector2) { 150.0f, 275.0f }, (float)fontMario.baseSize * 1.75, 2, MAROON);

                DrawTextEx(fontMario, "pressione [Enter] para pular", (Vector2) { 815.0f, 670.0f }, (float)fontMario.baseSize * 0.40, 2, BROWN);

                if (framesCounter < splashscreenTimeout / 2) {
                    DrawRectangle(0, 0, screenWidth, screenHeight - 100, Fade(BLACK, (splashscreenTimeout / 2 - framesCounter) / (splashscreenTimeout * 0.5)));
                } else {
                    DrawRectangle(0, 0, screenWidth, screenHeight - 100, Fade(BLACK, (framesCounter - splashscreenTimeout / 2) / (splashscreenTimeout * 0.5)));
                }
            } break;

            case MAINMENU: {
                // TODO: Draw TITLE screen here!
                DrawRectangle(0, 0, screenWidth, screenHeight, BLACK);
                DrawTextEx(fontMario, windowTitle, (Vector2) { 272.0f, 75.0f }, (float)fontMario.baseSize * 1.2 + 2, 2, BROWN);
                DrawTextEx(fontMario, windowTitle, (Vector2) { 280.0f, 75.0f }, (float)fontMario.baseSize * 1.2, 2, MAROON);

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
            } break;

            case GAME: {
                // TODO: Draw GAMEPLAY screen here!
                DrawRectangle(0, 0, screenWidth, screenHeight, BLACK);
                DrawText("GAME SCREEN", 20, 20, 40, MAROON);
                DrawText("PRESS ENTER or TAP to JUMP to ENDING SCREEN", 130, 220, 20, MAROON);
            } break;

            case SCORE: {
                // TODO: Draw ENDING screen here!
                DrawRectangle(0, 0, screenWidth, screenHeight, BLUE);
                DrawText("SCORE SCREEN", 20, 20, 40, DARKBLUE);
                DrawText("PRESS ENTER or TAP to RETURN to TITLE SCREEN", 120, 220, 20, DARKBLUE);
            } break;

            default: break;
        }

        EndDrawing();
    }

    //Liberação de memória/Descarregamento de recursos

    UnloadFont(fontMario);
    UnloadTexture(marioTextures);

    CloseWindow();

    return 0;
}
