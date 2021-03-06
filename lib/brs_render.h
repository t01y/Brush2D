#ifndef _BRS_RENDER_H_
#define _BRS_RENDER_H_

// Frameworks
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <stdio.h> /* for fprintf() */
#include <stdlib.h> /* for atexit() */

typedef struct {
    SDL_Window         *window;
    SDL_Renderer       *camera;
}brs_render_conf_t, *brs_render_conf_tp;


typedef struct {
    int x;
    int y;
}brs_pos_t;

typedef struct {
    SDL_Rect            transform;      // Render Position (based on Screen)
    brs_pos_t           position;       // Rigidbody Position (based on World)
    brs_pos_t           pivot_offset;   // Pivot Offset
    SDL_Texture        *texture;
    char               *image_path;
    char                z_index;        // Different layer with different scroll speed, based on this index value
    char                fps;            // Frame Per Second
    void               *cont;
}brs_sprite_t;

#define BRS_SPRITE_AMOUNT   50

typedef struct {
    brs_sprite_t       *sprites_pool[BRS_SPRITE_AMOUNT];
    int                 top;
    brs_pos_t           camera_pos;
}brs_scene_t;

#define BRS_SCENE_AMOUNT    3
typedef struct {
    brs_scene_t         scene[BRS_SCENE_AMOUNT];
    SDL_Renderer       *camera;
}brs_scene_pool_t;

extern brs_module_t     brs_module_render_st;

extern void brs_Delay(unsigned int ms);
extern int brs_CreatSprite(brs_sprite_t *ctx);
extern void brs_AddSprite(brs_sprite_t *ctx, unsigned char index);
extern void brs_RenderScene(unsigned char index);
extern brs_pos_t *brs_CameraPosition(unsigned char index);

#endif