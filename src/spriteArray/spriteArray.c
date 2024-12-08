#include "spriteArray.h"

SpriteArray SpriteArray_new(int size) {
    SpriteArray* arr = malloc(sizeof(arr) + sizeof(Sprite) * size);
    
    arr->length = 0;
    arr->maxLength = size;

    return *arr; 
}

void SpriteArray_push(SpriteArray* array, Sprite value) {
    array->data[array->length++] = value;
}

void SpriteArray_removeAt(SpriteArray* array, int index) {
    for(int i = index; i < array->length; i++) {
        array->data[i] = array->data[i + 1];
    }
}