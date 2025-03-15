#ifndef CAMERA_H
#define CAMERA_H

class Camera {
public:
    int imageWidth;
    double aspectRatio = 16.0 / 9.0;

    void render() {}

private:
    int image_height; // Rendered image height
};

#endif