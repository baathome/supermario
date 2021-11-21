/* Daniel da Silva Severiano dos Santos - cartao numero - turma
   Programa Final da disciplina de
 */

//includes
#include <stdio.h>
#include "raylib.h"
// #include "game.h"
#include "draw.h"
#include "player.h"
#include "level.h"
#include "inimigs.h"

//typedefs
typedef enum GameScreen { SPLASH = 0, MAINMENU, GAME, SCORE, HELP, ABOUT }                     GameScreen; // TODO: LOAD SCREEN
typedef enum MainMenuOption { NEWGAME = 0, CONTINUE, LOADMAP, RANKING, HELPS, ABOUTS, EXIT }   MainMenuOption;

int main() {
    //Variáveis da tela
    const int screenWidth = 1200;
    const int screenHeight = 700;
    const int splashscreenTimeout = 300;
    const char *windowTitle = "Super Mario DOS";

    char level[29][120]; //Matriz de posições do nível
    int currentLevel = 1;

    InitWindow(screenWidth, screenHeight, windowTitle);     //Inicializa janela da raylib

    Mario mario = initMario();

    Inimigs inimigs = initInimigs();

    Rectangle marioRec = { 0.0f, 0.0f, mario.txL.width / 8.0, mario.txL.height };
    Rectangle marioDestRec = { 0.0f, 0.0f, MARIO_WIDTH, MARIO_HEIGHT };

    Rectangle InimigsRec = { 0.0f, 0.0f, inimigs.txL.width / 5.0, inimigs.txL.height };
    Rectangle destInimigsRec = { 0.0f, 0.0f, INIMIGS_WIDTH, INIMIGS_HEIGHT };

    Platform platforms[20];

    //initPlatforms(&platforms, 20);

    printf("\n\n\nplatX = %d\n\n\n", platforms[0].start.x);


    MainMenuOption currentMainMenuOption = NEWGAME; //enum para listar a opção selecionada do menu principal
    bool flagExit = false; //flag para encerrar o jogo
    bool flagPause = false;     //flag para ver se o jogo está pausado

    GameScreen currentScreen = SPLASH;

    int framesCounter = 0;

    //Inicialização de recursos
    Font fontMario = LoadFontEx("resources/SuperMario256.ttf", 46, 0, 250); //Carrega a fonte para ser usada na janela

    SetExitKey(KEY_BACKSPACE); //Libera ESC para uso e encerra imediatamente a janela com Backspace

    //l_LoadLevel("resources/fases/fase1.txt");
    // g_CreateBlock(5.0, 5.0, 0);

    SetTargetFPS(60);
    inimigs.facingRight = true;

    //Loop do jogo
    while (!WindowShouldClose() && !flagExit) { //TOD: exit only through windowshouldclose
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
                    if (currentMainMenuOption == EXIT || IsKeyPressed(KEY_ESCAPE)) flagExit = 1;
                    else if (currentMainMenuOption == HELPS) currentScreen = HELP;
                    else if (currentMainMenuOption == ABOUTS) currentScreen = ABOUT;
                    else if (currentMainMenuOption == RANKING) currentScreen = SCORE;
                    else {
                        currentScreen = GAME;
                        framesCounter = 0;

                        if (currentMainMenuOption == NEWGAME) {
                            //loadLevel(1);
                            //load stage 1
                            currentLevel = 1;

                            mario = initMario();
                            bool sPlat = false;

                            FILE *file = fopen("resources/fases/fase1.txt", "r"); //TODO: safer read

                            for (int i = 0; i < 28; i++) {
                                for (int j = 0; j < 120; j++) {
                                    level[i][j] = getc(file);

                                    if (level[i][j] == 'm') {
                                        mario.pos.x = j;
                                        mario.pos.y = i;
                                    } else if (level[i][j] == 'p') {
                                        if (!sPlat) {
                                        }
                                    }
                                }

                                getc(file);
                            }

                            int x;
                            x = (int)getc(file) - 48;
                            getc(file);
                            x = (int)getc(file) - 48;
                            getc(file);
                            x = (int)getc(file) - 48;

                            fclose(file);
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
                if (flagPause) {
                    //TODO: option to save progress
                    if (IsKeyPressed(KEY_ESCAPE)) flagPause = false;
                    else if (IsKeyPressed(KEY_Q)) currentScreen = MAINMENU;
                    else if (IsKeyPressed(KEY_S)) {
                        //TODO: save and quit to main menu
                    }
                } else {
                    framesCounter++;
                    mario.pos.x += mario.speed.x * mario.speedMultiplier.x;
                    mario.pos.y += mario.speed.y * mario.speedMultiplier.y;

                    inimigs.pos.x += inimigs.speed.x;
                    inimigs.pos.y += inimigs.speed.y;

                    //printf("%f  x  %f\n", mario.pos.x, mario.pos.y);

                    if (framesCounter >= 60 / MARIO_ANIMATION_SPEED) {
                        framesCounter = 0;
                        mario.currentAnimationFrame++;
                        inimigs.currentAnimationFrame++;
                    }

                    //g_GameMain();
                    if (IsKeyPressed(KEY_UP) || IsKeyPressed(KEY_BACKSPACE)){
                      mario.pos.y +=  mario.speed.y + MARIO_JUMP - GRAVITY;
                    }
                    if (IsKeyPressed(KEY_ESCAPE)) flagPause = true;
                    else if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) {
                        mario.speed.x = 1;
                        mario.facingRight = true;

                        if (mario.currentAnimationFrame > MARIO_WALK3) mario.currentAnimationFrame = MARIO_WALK1;
                        if (mario.pos.x > 1200 ) mario.pos.x = 0;
                        //TODO: add check on Y velocity
                    } else if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A)) {
                        mario.speed.x = -1;
                        mario.facingRight = false;

                        if (mario.currentAnimationFrame > MARIO_WALK3) mario.currentAnimationFrame = MARIO_WALK1;
                        if (mario.pos.x < 0 ) mario.pos.x = 1200;
                        //TODO: add check on Y velocity
                    } else {
                        mario.speed.x = 0;
                        mario.currentAnimationFrame = 0;
                    }

                    if (inimigs.speed.x = 0) {
                        inimigs.currentAnimationFrame = 0;
                        if (inimigs.state == false) inimigs.currentAnimationFrame = INIMIGS_STUN;
                    } else if (inimigs.facingRight == true) {
                        inimigs.speed.x = 2;

                        if (inimigs.currentAnimationFrame > INIMIGS_WALK4) inimigs.currentAnimationFrame = INIMIGS_WALK1;
                        if (inimigs.pos.x > 1200 ) inimigs.pos.x = 0;
                        if (inimigs.lvl == 2 && inimigs.angry == false) inimigs.speed.x = 4;

                    } else if (inimigs.facingRight == false) {
                        inimigs.speed.x = -2;

                        if (inimigs.currentAnimationFrame > INIMIGS_WALK4) inimigs.currentAnimationFrame = INIMIGS_WALK1;
                        if (inimigs.pos.x < 0 ) inimigs.pos.x = 1200;
                        if (inimigs.lvl == 2 && inimigs.angry == false) inimigs.speed.x = -4;
                    }

                    InimigsRec.x = (inimigs.currentAnimationFrame * InimigsRec.width);

                    marioRec.x = (mario.currentAnimationFrame * marioRec.width);
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
                // DrawRectangle(0, 0, screenWidth, screenHeight, BLACK);
                // DrawText("GAME SCREEN", 20, 20, 40, MAROON);
                // DrawText("PRESS ENTER or TAP to JUMP to ENDING SCREEN", 130, 220, 20, MAROON);
                //d_Draw();

                if (mario.facingRight) DrawTexturePro(mario.txR, marioRec, marioDestRec, (Vector2) { mario.pos.x * -1.0, mario.pos.y }, 0, WHITE);  //TODO: fix phantom hand bug by splitting textures into single files and turning mario.txR and txL into arrays
                else DrawTexturePro(mario.txL, marioRec, marioDestRec, (Vector2) { mario.pos.x * -1.0, mario.pos.y }, 0, WHITE);

                if (inimigs.facingRight) DrawTexturePro(inimigs.txR, InimigsRec, destInimigsRec, (Vector2) { inimigs.pos.x * -1.0, inimigs.pos.y }, 0, WHITE);                            //TODO: fix phantom hand bug by splitting textures into single files and turning mario.txR and txL into arrays
                else DrawTexturePro(inimigs.txL, InimigsRec, destInimigsRec, (Vector2) { inimigs.pos.x * -1.0, inimigs.pos.y }, 0, WHITE);

                if (flagPause) {
                    DrawRectangle(0, 0, screenWidth, screenHeight, Fade(BLACK, 0.5));
                    DrawText("Aperte ESC para voltar ao jogo", 350, 250, 30, WHITE);
                    DrawText("Aperte Q para sair do jogo", 385, 290, 30, WHITE);
                    DrawText("Aperte S para salvar e sair do jogo", 320, 330, 30, WHITE);
                }
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

    UnloadFont(fontMario);
    unloadMarioTX(mario);
    unloadInimigsTX(inimigs);
    CloseWindow();

    return 0;
}
