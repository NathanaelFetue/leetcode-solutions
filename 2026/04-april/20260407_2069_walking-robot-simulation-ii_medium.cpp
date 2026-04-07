/*
 * Problem #2069 - Walking Robot Simulation II (Medium)
 * https://leetcode.com/problems/walking-robot-simulation-ii/
 *
 * Approach: Perimeter Precomputation with Modular Indexing
 * All valid perimeter positions and their associated facing directions are precomputed
 * during initialization by traversing the boundary (bottom, right, top, left edges).
 * Each step call simply advances an index modulo the perimeter length, avoiding
 * any actual simulation of individual moves.
 *
 * Key detail: The starting position (0,0) is given direction South (index 0 overridden)
 * because after completing a full loop it arrives from the left side facing South,
 * and the `moved` flag handles the special East-facing initial state before any steps.
 *
 * Time Complexity:
 *   - Constructor: O(w + h) to precompute perimeter positions and directions
 *   - step(): O(1) modular arithmetic
 *   - getPos() / getDir(): O(1) array lookup
 *
 * Space Complexity: O(w + h) for storing all perimeter coordinates and directions
 *
 * Runtime: 41 ms | Memory: 128 MB
 */

class Robot {
    int w, h, idx = 0;
    bool moved = false;
    
    // Pré-calculer toutes les positions + directions du périmètre
    vector<pair<int,int>> coords;
    vector<int> dirs; // 0=East 1=North 2=West 3=South
    
    const string DIRS[4] = {"East", "North", "West", "South"};

public:
    Robot(int width, int height) : w(width), h(height) {
        // Bas → droite (East)
        for (int x = 0; x < w; x++)     { coords.push_back({x, 0});      dirs.push_back(0); }
        // Droite → haut (North)
        for (int y = 1; y < h; y++)     { coords.push_back({w-1, y});    dirs.push_back(1); }
        // Haut → gauche (West)
        for (int x = w-2; x >= 0; x--) { coords.push_back({x, h-1});    dirs.push_back(2); }
        for (int y = h-2; y > 0; y--)  { coords.push_back({0, y});      dirs.push_back(3); }
        dirs[0] = 3;
    }

    void step(int num) {
        moved = true;
        idx = (idx + num) % (int)coords.size();
    }

    vector<int> getPos() {
        return {coords[idx].first, coords[idx].second};
    }

    string getDir() {
        if (!moved) return "East";
        return DIRS[dirs[idx]];
    }
};
/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */
