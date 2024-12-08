#include "spriteArray.h"

SpriteArray SpriteArray_new(int size) {
    SpriteArray* arr = malloc(sizeof(arr) + sizeof(Sprite) * size);
    
    arr->length = 0;
    arr->maxLength = size;

    return *arr; 
}

SpriteArray SpriteArray_push(SpriteArray* array, Sprite value) {
    array->data[array->length++] = value;
}