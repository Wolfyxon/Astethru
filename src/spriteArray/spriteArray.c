#include "spriteArray.h"
#include <stdio.h>

SpriteArray* SpriteArray_new(int size) {
    int msize = sizeof(SpriteArray) + sizeof(Sprite) * size;
    SpriteArray* arr = malloc(msize);
    
    if(arr == NULL) {
        fprintf(stderr, "Failed to allocate memory for SpriteArray. Size: %i Memory size: %i \n", size, msize);
        exit(1);
    }

    arr->length = 0;
    arr->maxLength = size;

    return arr; 
}

void SpriteArray_push(SpriteArray* array, Sprite value) {
    array->data[array->length++] = value;
}

void SpriteArray_removeAt(SpriteArray* array, int index) {
    for(int i = index; i < array->length; i++) {
        array->data[i] = array->data[i + 1];
    }
}