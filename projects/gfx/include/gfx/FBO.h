/*
---------------------------------------------------------------------------------
 
                                               oooo
                                               `888
                oooo d8b  .ooooo.  oooo    ooo  888  oooo  oooo
                `888""8P d88' `88b  `88b..8P'   888  `888  `888
                 888     888   888    Y888'     888   888   888
                 888     888   888  .o8"'88b    888   888   888
                d888b    `Y8bod8P' o88'   888o o888o  `V88V"V8P'
 
                                                  www.roxlu.com
                                             www.apollomedia.nl
                                          www.twitter.com/roxlu
 
---------------------------------------------------------------------------------
*/
#include <vector>
#include <glad/glad.h>

#define ROXLU_USE_LOG
#define ROXLU_USE_OPENGL
#define ROXLU_USE_MATH
#include <tinylib.h>

namespace gfx {

  class FBO {
  public:
    FBO();
    ~FBO();
    int init(int w, int h);   /* allocate an FBO; very basic, no special options for now :) */
    int shutdown();           /* destroy the FBO + all created textures. */
    void bind();
    void unbind();
    GLuint addTexture(GLenum format, int w, int h, GLenum internalFormat, GLenum type, GLenum attachment);  /* create a new texture - WE TAKE OWNERSHIP AND DESTROY THE TEXTURES IN SHUTDOWN */
    int isComplete();
    void setDrawBuffer(GLenum attach);
    void blit(GLenum attachment, int x, int y, int w, int h);  /* use the given attachment as as read buffer and blit it into the current draw framebuffer, so make sure you've set your draw framebuffer. */

  public:
    GLuint fbo;
    std::vector<GLuint> textures;
    int width;
    int height;
  };

} /* namespace gfx */
