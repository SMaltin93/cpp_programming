#include <bits/stdc++.h>
#include "bintree.cpp"
#include <vector>
#include <array>

using namespace std;

void report(const array<pair<int, int>, 800> &results) {
 
    double average_height = 0;
    int highest_max_height = 0;
    double average_min_height = 0;
    int lowest_min_height = 0;
    double average_difference = 0;
    int greatest_difference = 0;
    int lowest_difference = 0;

    for (int i = 0; i < results.size(); i++) {
        average_height += results[i].first + results[i].second;
        if (results[i].first > highest_max_height) {
            highest_max_height = results[i].first;
        }
        average_min_height += results[i].second;
        if (results[i].second < lowest_min_height) {
            lowest_min_height = results[i].second;
        }
        average_difference += results[i].first - results[i].second;
        if (results[i].first - results[i].second > greatest_difference) {
            greatest_difference = results[i].first - results[i].second;
        }
        if (results[i].first - results[i].second < lowest_difference) {
            lowest_difference = results[i].first - results[i].second;
        }
    }
    average_height /= results.size() * 2;
    average_min_height /= results.size();
    average_difference /= results.size();

    cout << "The average height of the tree in 800 iterations: " << average_height << endl;
    cout << "The highest maximum height: " << highest_max_height << endl;
    cout << "The average minimum height: " << average_min_height << endl;
    cout << "The lowest minimum height: " << lowest_min_height << endl;
    cout << "The average difference between minimum and maximum height: " << average_difference << endl;
    cout << "The greatest difference between minimum and maximum height: " << greatest_difference << endl;
    cout << "The lowest difference between minimum and maximum height: " << lowest_difference << endl;

}

int main() {
   vector <int> values(9000);
    for (int i = 1; i <= 9000; i++) {
         values[i] = i;
    }

    shuffle(values.begin(), values.end(), default_random_engine(930103));
    // create a vector to store the results of the 800 iterations
    array<pair<int, int>, 800> results;

    for (int i = 0; i < 800; i++) {
        // create a new tree
        Node *root = nullptr;
        // insert the first 9000 values
        for (int j = 0; j < values.size(); j++) {
            insert(root, values[j], values[j]);
        }
        results[i] = make_pair(max_height(root), min_height(root));

        // delete the tree
        delete_tree(root);

        
        next_permutation(values.begin(), values.end());
    }

    report(results);

    return 0;

}