#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <FUNCS/frame_size_callback.hpp>

#include <FUNCS/key_callback.hpp>
#include <FUNCS/mouse_callback.hpp>

#include <FUNCS/cube_logic.hpp>
#include <FUNCS/draw_functions.hpp>

void arraySet(int *array, int size, ...) {
    int *ptr = &size;
    for (int i = 0; size > 0; i++, size--)
        array[i] = *(ptr += 2);
}

#endif