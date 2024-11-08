#include <iostream>
#include <vector>
#include <string>
using namespace std;

string simplifyPath(string path) {
    string ok;
    vector<string> store;
    int i = 1, n = path.size();
    
    while (i < n) {
        while (i < n && path[i] == '/') i++; // Skip consecutive slashes
        while (i < n && path[i] != '/') ok += path[i++]; // Build the directory/file name

        if (ok == ".." && !store.empty()) {
            store.pop_back(); // Go up one directory
        } else if (!ok.empty() && ok != "." && ok != "..") {
            store.push_back(ok); // Add valid directory/file to the stack
        }
        ok.clear(); // Reset `ok` for the next part
    }

    // Reconstruct the canonical path
    ok = "/";
    for (const auto& str : store) {
        ok += str + "/";
    }
    if (ok.size() > 1) ok.pop_back(); // Remove the trailing slash if path is not root

    return ok;
}

int main() {
    string path1 = "/home//foo/";        // Expected: "/home/foo"
    string path2 = "/a/./b/../../c/";    // Expected: "/c"
    string path3 = "/../";               // Expected: "/"
    string path4 = "/home/";             // Expected: "/home"
    
    cout << "Simplified path for '" << path1 << "' : " << simplifyPath(path1) << endl;
    cout << "Simplified path for '" << path2 << "' : " << simplifyPath(path2) << endl;
    cout << "Simplified path for '" << path3 << "' : " << simplifyPath(path3) << endl;
    cout << "Simplified path for '" << path4 << "' : " << simplifyPath(path4) << endl;

    return 0;
}
