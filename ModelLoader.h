#pragma once


#include "tiny_obj_loader.h"
#include "Mdel.h"

#include "GL_utilities.h"
#include <vector>

// ===== ModelLoader class =====

class ModelLoader {
private:
    // Needed by the model loader, should be cleared after usage by each function
    std::vector<tinyobj::shape_t> shapes;
    std::vector<tinyobj::material_t> materials;

    // Needed since multiple functions refer to this one
    std::vector<TextureData*> textures;

    bool AddModels(std::vector<Mdel*>* models);

    bool CalculateMinMax(lv3** maxVertex, lv3** minVertex);

    bool LoadModels(const char* path);

    bool LoadTextures();

    void CalculateTangents();

public:
    ModelLoader() {};

    bool LoadScene(const char* path, std::vector<Mdel*>* outModels);

    bool LoadScene(const char* path, std::vector<Mdel*>* outModels,
        lv3** outMaxVertex, lv3** outMinVertex);

    bool LoadModel(const char* path, Mdel* outModel);

    GLuint LoadTexture(const char* path);
};
