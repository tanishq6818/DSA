int ninjaAndTriangle(int n) {
    int height = static_cast<int>(std::floor((-1.0 + std::sqrt(1 + 8 * n)) / 2));
    return height;
}
