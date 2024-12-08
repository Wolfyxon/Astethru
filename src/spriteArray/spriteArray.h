#ifndef SPRITE_ARRAY_H
#define SPRITE_ARRAY_H

#include "../sprite/sprite.h"

typedef struct {
    int length;
    int maxLength;
    Sprite data[];
} SpriteArray;

SpriteArray SpriteArray_new(int size);

void SpriteArray_push(SpriteArray* array, Sprite sprite);
void SpriteArray_removeAt(SpriteArray* array, int index);

#endif