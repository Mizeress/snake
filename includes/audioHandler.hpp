#define MINIAUDIO_IMPLEMENTATION
#include <miniaudio.h>

ma_engine engine;
ma_sound eatSound;

void initAudio() {
    ma_engine_init(NULL, &engine);
    ma_sound_init_from_file(&engine, "sound/eat.wav", 0, NULL, NULL, &eatSound);
}

void playEatSound() {
    ma_sound_seek_to_pcm_frame(&eatSound, 0); //To start
    ma_sound_start(&eatSound);
}

void cleanupAudio() {
    ma_sound_uninit(&eatSound);
    ma_engine_uninit(&engine);
}