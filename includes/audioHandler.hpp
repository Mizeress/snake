#define MINIAUDIO_IMPLEMENTATION
#include <miniaudio.h>
#include <string>

ma_engine engine;
ma_sound eatSound;
ma_sound deathSound;
ma_sound backgroundMusic;

const string songPath = "sound/";

void initAudio() {
    ma_engine_init(NULL, &engine);
    ma_sound_init_from_file(&engine, (songPath + "eat.wav").c_str(), 0, NULL, NULL, &eatSound);
    ma_sound_init_from_file(&engine, (songPath + "RetroSnake.wav").c_str(), 0, NULL, NULL, &backgroundMusic);
    ma_sound_init_from_file(&engine, (songPath + "explosion.wav").c_str(), 0, NULL, NULL, &deathSound);
    ma_sound_set_looping(&backgroundMusic, MA_TRUE);
}

void playBackgroundMusic() {
    ma_sound_start(&backgroundMusic);

}

void playEatSound() {
    ma_sound_seek_to_pcm_frame(&eatSound, 0); //To start
    ma_sound_start(&eatSound);
}

void playDeathSound() {
    ma_sound_seek_to_pcm_frame(&deathSound, 0); //To start
    ma_sound_start(&deathSound);
}

void cleanupAudio() {
    ma_sound_uninit(&eatSound);
    ma_sound_uninit(&backgroundMusic);
    ma_engine_uninit(&engine);
}