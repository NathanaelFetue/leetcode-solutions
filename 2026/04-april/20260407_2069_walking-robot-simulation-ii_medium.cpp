/*
 * Problem #2069 - Walking Robot Simulation II (Medium)
 * https://leetcode.com/problems/walking-robot-simulation-ii/
 *
 * Approach: Precompute Perimeter Path
 * All valid boundary positions and their corresponding facing directions are precomputed
 * once during construction, tracing the perimeter clockwise (East → North → West → South).
 * Each step() call reduces to a single modular index advance over the precomputed array,
 * avoiding repeated simulation. A special case handles the origin direction before any move.
 *
 * Time Complexity:
 *   - Constructor: O(w + h) to precompute all perimeter positions
 *   - step(): O(1) — modular arithmetic only
 *   - getPos() / getDir(): O(1) — direct array lookup
 *
 * Space Complexity: O(w + h) for storing the precomputed coords and dirs arrays
 *
 * Runtime: 21 ms | Memory: 127.9 MB
 */

class Robot {
    int w, h, idx = 0;
    bool moved = false;
    
    // Pré-calculer toutes les positions + d
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
