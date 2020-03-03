//
// Created by hugo on 03/03/2020.
//

#include "Game.h"
#include "Constants.h"
#include "Color.h"

void Game::addPipe(int debut, int fin) {
    if (fin < debut) {
        fin += NB_PIXEL;
    }

    for(int c = debut; c < fin; c += HAUTEUR * 3) {
        int delta = this->derniereColonneDessine - this->derniereColonneTube > 0 ? this->derniereColonneDessine - this->derniereColonneTube : this->derniereColonneDessine - this->derniereColonneTube + LARGEUR;
        if (delta == INTERVALLE_COLONE) {
            //TODO
            //this->mp_CentrePassage = (int)(32.0D + -16.0D + Math.random() * 32.0D);
        }

        int l;
        if (delta >= INTERVALLE_COLONE && delta <= INTERVALLE_COLONE + LARGEUR_COLONE) {
            for(l = c; l < c + (this->mp_CentrePassage - HAUTEUR_PASSAGE / 2) * 3; l += 3) {
                byteMap[l % NB_PIXEL] = PIPE_COLOR.getRed();
                byteMap[(l + 1) % NB_PIXEL] = PIPE_COLOR.getGreen();
                byteMap[(l + 2) % NB_PIXEL] = PIPE_COLOR.getBlue();
            }

            for(l = c + (this->mp_CentrePassage - HAUTEUR_PASSAGE / 2) * 3; l < c + (this->mp_CentrePassage + HAUTEUR_PASSAGE / 2) * 3; l += 3) {
                byteMap[l % NB_PIXEL] = BG_COLOR.getRed();
                byteMap[(l + 1) % NB_PIXEL] = BG_COLOR.getGreen();
                byteMap[(l + 2) % NB_PIXEL] = BG_COLOR.getBlue();
            }

            for(l = c + (this->mp_CentrePassage + HAUTEUR_PASSAGE / 2) * 3; l < c + HAUTEUR * 3; l += 3) {
                byteMap[l % NB_PIXEL] = PIPE_COLOR.getRed();
                byteMap[(l + 1) % NB_PIXEL] = PIPE_COLOR.getGreen();
                byteMap[(l + 2) % NB_PIXEL] = PIPE_COLOR.getBlue();
            }
        } else {
            for(l = c; l < c + HAUTEUR * 3; l += 3) {
                byteMap[l % NB_PIXEL] = BG_COLOR.getRed();
                byteMap[(l + 1) % NB_PIXEL] = BG_COLOR.getGreen();
                byteMap[(l + 2) % NB_PIXEL] = BG_COLOR.getBlue();
            }
        }

        if (delta == INTERVALLE_COLONE + LARGEUR_COLONE) {
            this->derniereColonneTube = this->derniereColonneDessine % LARGEUR;
        }

        this->derniereColonneDessine = (this->derniereColonneDessine + 1) % LARGEUR;
    }

}

void Game::MoveJoueur() {
    int cpt;
    int i;
    for(cpt = 0; cpt < LONGEUR_JOUEUR; ++cpt) {
        for(i = 0; i < LONGEUR_JOUEUR - 2; ++i) {
            byteMap[(this->positionJoueur + i * 3 + cpt * HAUTEUR * 3) % (HAUTEUR * LARGEUR * 3)] = BG_COLOR.getRed();
            byteMap[(this->positionJoueur + i * 3 + cpt * HAUTEUR * 3 + 1) % (HAUTEUR * LARGEUR * 3)] = BG_COLOR.getGreen();
            byteMap[(this->positionJoueur + i * 3 + cpt * HAUTEUR * 3 + 2) % (HAUTEUR * LARGEUR * 3)] = BG_COLOR.getBlue();
        }
    }

    this->positionJoueur = (this->positionJoueur + 2 * HAUTEUR * 3 + this->decalageJoueurConrrant * 3) % (HAUTEUR * LARGEUR * 3);
    cpt = 0;

    for(i = 0; i < LONGEUR_JOUEUR; ++i) {
        for(int j = 0; j < LONGEUR_JOUEUR - 2; ++j) {
            if (byteMap[(this->positionJoueur + j * 3 + i * HAUTEUR * 3) % (HAUTEUR * LARGEUR * 3)] == PIPE_COLOR.getRed() && cpt != 0 && cpt != 6 && cpt != 12 && cpt != 18 && cpt != 1 && cpt != 7 && cpt != 13 && cpt != 19 && cpt != 40 && cpt != 41 && cpt != 46 && cpt != 47) {
                perdu = true;
            }

            if (cpt == 38) {
                byteMap[(this->positionJoueur + j * 3 + i * HAUTEUR * 3) % (HAUTEUR * LARGEUR * 3)] = E_PLAYER_COLOR.getRed();
                byteMap[(this->positionJoueur + j * 3 + i * HAUTEUR * 3 + 1) % (HAUTEUR * LARGEUR * 3)] = E_PLAYER_COLOR.getGreen();
                byteMap[(this->positionJoueur + j * 3 + i * HAUTEUR * 3 + 2) % (HAUTEUR * LARGEUR * 3)] = E_PLAYER_COLOR.getBlue();
            } else if (cpt != 9 && cpt != 15 && cpt != 21 && cpt != 27 && cpt != 16 && cpt != 22 && cpt != 28) {
                if (cpt != 31 && cpt != 32 && cpt != 37) {
                    if (cpt != 0 && cpt != 6 && cpt != 12 && cpt != 18 && cpt != 1 && cpt != 7 && cpt != 13 && cpt != 19 && cpt != 40 && cpt != 41 && cpt != 46 && cpt != 47) {
                        byteMap[(this->positionJoueur + j * 3 + i * HAUTEUR * 3) % (HAUTEUR * LARGEUR * 3)] = B_PLAYER_COLOR.getRed();
                        byteMap[(this->positionJoueur + j * 3 + i * HAUTEUR * 3 + 1) % (HAUTEUR * LARGEUR * 3)] = B_PLAYER_COLOR.getGreen();
                        byteMap[(this->positionJoueur + j * 3 + i * HAUTEUR * 3 + 2) % (HAUTEUR * LARGEUR * 3)] = B_PLAYER_COLOR.getBlue();
                    }
                } else {
                    byteMap[(this->positionJoueur + j * 3 + i * HAUTEUR * 3) % (HAUTEUR * LARGEUR * 3)] = WHITE_COLOR.getRed();
                    byteMap[(this->positionJoueur + j * 3 + i * HAUTEUR * 3 + 1) % (HAUTEUR * LARGEUR * 3)] = WHITE_COLOR.getGreen();
                    byteMap[(this->positionJoueur + j * 3 + i * HAUTEUR * 3 + 2) % (HAUTEUR * LARGEUR * 3)] = WHITE_COLOR.getBlue();
                }
            } else {
                byteMap[(this->positionJoueur + j * 3 + i * HAUTEUR * 3) % (HAUTEUR * LARGEUR * 3)] = W_PLAYER_COLOR.getRed();
                byteMap[(this->positionJoueur + j * 3 + i * HAUTEUR * 3 + 1) % (HAUTEUR * LARGEUR * 3)] = W_PLAYER_COLOR.getGreen();
                byteMap[(this->positionJoueur + j * 3 + i * HAUTEUR * 3 + 2) % (HAUTEUR * LARGEUR * 3)] = W_PLAYER_COLOR.getBlue();
            }

            ++cpt;
        }
    }

    this->semaphore.lock();
    if (this->decalageJoueurConrrant <= 1 && this->isStart) {
        ++this->decalageJoueurConrrant;
    }

    this->semaphore.unlock();

}

void Game::init_game() {
    derniereColonneTube = 0;
    derniereColonneDessine = 0;
}

void Game::decaler() {
    this->decalage += DECALAGE;
}

void Game::updateGame() {
    this->decaler();
    this->addPipe(this->derniereColonneDessine * HAUTEUR * 3 % NB_PIXEL, (this->derniereColonneDessine + 2) * HAUTEUR * 3 % NB_PIXEL);
    this->MoveJoueur();
    this->update();

}
