#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>    // std::sort()

struct Resident {
    unsigned id;
    char name[20];
    char surname[20];
};


bool comparator(const Resident &a, const Resident &b) {
       if (a.id != b.id) return a.id < b.id;
           if (strcmp(a.surname, b.surname) != 0) return strcmp(a.surname, b.surname) < 0;
           return strcmp(a.name, b.name) < 0;
       }


Resident median_of_medians(std::vector<Resident> &medians) {
    // if n <= 10 -> sort and find res
    if (medians.size() <= 10) {
        std::sort(medians.begin(), medians.end(), comparator);
        return medians[medians.size() / 2];
    }
    // make new array for medians of previous medians
    std::vector<Resident> medians_tmp;
    for (int i = 0; i < medians.size(); i += 5) {
        if (medians.size() - i < 5) {
            std::sort(medians.begin() + i, medians.end(), comparator);
            medians_tmp.push_back(medians[(i + medians.size()) / 2]);
        } else {
            std::sort(medians.begin() + i, medians.begin() + i + 5, comparator);
            medians_tmp.push_back(medians[i + 2]);
        }
    }
    // recursively find resid
    return median_of_medians(medians_tmp);
}

Resident magicFives(Resident *arr, unsigned k, unsigned n) {
    // if n <= 10 -> sort and find k
    if (n <= 10) {
        std::sort(arr, arr + n, comparator);
        return arr[k];
    }
    // divide array on n/5 subarrays
    std::vector<Resident> medians;
    for (int i = 0; i < n; i += 5) {
        if (n - i < 5) {
            //std::sort(arr + i, arr + n, comparator);
            medians.push_back(arr[(i + n) / 2]);
        } else {
            //std::sort(arr + i, arr + i + 5, comparator);
            medians.push_back(arr[i + 2]);
        }
    }
    // find median of medians
    Resident res = median_of_medians(medians);


    // lower to left from res
    unsigned el = 0;
    unsigned lower = 0;
    for (unsigned i = 0; i < n; ++i) {
        if (comparator(arr[i], res)) {
            std::swap(arr[i], arr[el]);
            el++;
            lower++;
        }
    }

    if (k < lower)
        return magicFives(arr, k, lower);
    else if (k >= lower)
        return magicFives(arr + lower, k - lower, n - lower);

       return Resident{0," ", " "};
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    unsigned n, m;
    std::cin >> n >> m;

    Resident residents[n];        // main array

    for (unsigned i = 0; i < n; ++i) {
        std::cin >>residents[i].name   >> residents[i].surname >> residents[i].id;
    }
       
       Resident res = magicFives(residents, m, n);
       
       std::cout<<res.name<<"\n"<<res.surname<<"\n"<<res.id<<std::endl;


    return 0;
}