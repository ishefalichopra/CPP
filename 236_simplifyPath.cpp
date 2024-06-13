#include <bits/stdc++.h>
using namespace std;

// Given a string path, which is an absolute path (starting with a slash '/') to a file or directory
// in a Unix-style file system, convert it to the simplified canonical path.

// In a Unix-style file system, a period '.' refers to the current directory, a double period '..' refers
// to the directory up a level, and any multiple consecutive slashes (i.e. '//') are treated as a single slash '/'.
// For this problem, any other format of periods such as '...' are treated as file/directory names.

// The canonical path should have the following format:
// - The path starts with a single slash '/'.
// - Any two directories are separated by a single slash '/'.
// - The path does not end with a trailing '/'.
// - The path only contains the directories on the path from the root directory to the target file or directory
// (i.e., no period '.' or double period '..')


string simplifyPath(string path) {
        vector<string> stack;
        string part;

        // Iterate through the path character by character
        for (int i = 0; i < path.size(); ++i) {
            if (path[i] == '/')
                continue; // Skip slashes

            // Extract the part between slashes
            part.clear();
            while (i < path.size() && path[i] != '/') {
                part += path[i];
                ++i;
            }

            if (part == "." || part.empty()) {
                continue; // Skip current directory symbols and empty parts
            } else if (part == "..") {
                if (!stack.empty()) {
                    stack.pop_back(); // Go up one directory level if possible
                }
            } else {
                stack.push_back(
                    part); // Add valid directory/file names to the stack
            }
        }

        // Build the simplified path
        string result = "/";
        for (int i = 0; i < stack.size(); ++i) {
            result += stack[i];
            if (i < stack.size() - 1) {
                result += "/";
            }
        }

        return result;
    }

int main()
{
    string path;
    cin>>path;
    cout<<simplifyPath(path)<<endl;
    

    return 0;
}