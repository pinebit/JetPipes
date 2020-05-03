#ifndef CONFIG_HPP
#define CONFIG_HPP

struct Config {
    static const int TubesCount = 16;
    static const int SceneRadius = 100;
    static const int TubeRadius = 2;
    static const int TubesGap = 1;
    static const int TubeSegments = 16;
    static const int MaxTubeLength = 256;
    static const int MaxRandomAttempts = 5;
};

#endif // CONFIG_HPP
