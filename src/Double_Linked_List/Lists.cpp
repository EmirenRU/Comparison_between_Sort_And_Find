//
// Created by User on 30.11.2022.
//

#include <regex>
#include "Lists.h"

int Lists::count = 0;

Lists::Lists() {
    sorted = false;
    scenario = new char[2];
    scenario[0] = '1';
    scenario[1] = '1';
}

Lists::Lists(char s1, char s2)
{
    sorted = false;
    scenario = new char[2];
    scenario[0] = s1;
    scenario[1] = s2;
}

void Lists::push_back(int id, int value)
{
    if (sorted)
    {
        int* tmp = new int[2];

        tmp[0] = id;
        tmp[1] = value;

        // insert data.

        int res;

        switch (scenario[1])
        {
            case '1':
                res = fullSearch_insert(id);
                break;
            case '2':
                res = binarySearch_insert(0, v.size() - 1, id);
                break;
        }

        // [1, 5, 10, 15, 20, 25, 30] <- 2
        // mid = 15 > 2 -> mid = 5 > 2 -> mid = (0 + 1) / 2 = 0 -> 0 < 1 -> abs(1-0) <= 1 -> yes -> return l;


        if (res < v.size() && res != -1 && v[res][0] != id )
            v.insert(v.begin() + res, tmp);
        else if (res < v.size() && res != -1 && v[res][0] == id)
            v.insert(v.begin() + res - 1, tmp);
        else
            v.push_back(tmp);
    }

    if (!sorted)
    {
        int* tmp = new int[2];
        tmp[0] = id;
        tmp[1] = value;
        v.push_back(tmp);
    }


//        if (v.size() == 0)
//            v.push_back(tmp);
//        else if (v[v.size() - 1][0] < tmp[0] && sorted )
//            v.push_back(tmp);
//        else if (v[v.size() - 1][0] > tmp[0])
//            sorted = false;
//
//        if (!sorted) {
//            v.push_back(tmp);
//
//            switch (scenario[0]) {
//                case '1':
//                    bubbleSort();
//                    sorted = true;
//                    break;
//                case '2':
//                    quickSort(0, (int) v.size() - 1);
//                    sorted = true;
//                    break;
//                case '3':
//                    break;
//            }
//        }
}

void Lists::push_back(int* &arr) { v.push_back(arr); }

int Lists::fullSearch_insert(const int &id)
{
    for (int i = 0; i < v.size()-1; ++i) {
        count++;

        if (v[i][0] < id && v[i+1][0] > id) {
            return i;
        }
    }

    return -1;
}

int Lists::binarySearch_insert(int l, int r, const int &id)
{
    if (sorted) {

        if (l <= r) {
            count++;
            int mid = (l + r) / 2;



            if (v[mid][0] == id) { return mid; }
            if (v[mid][0] > id) { return binarySearch(l, mid - 1, id); }
            if (v[mid][0] < id) { return binarySearch(mid + 1, r, id); }

            if (mid == 0) {
                if (v[mid][0] == id && v[mid + 1][0] > id && v[mid - 1][0] < id)
                    return mid;
                else if (v[mid][0] < id && v[mid + 1][0] > id)
                    return mid;
                else if (v[mid][0] > mid && v[mid - 1][0] < id)
                    return mid - 1;
            }
        }
        if (r - l == 1) {
            if (v[r][0] == id)
                return r;
            if (v[l][0] == id)
                return l;
            if (id < v[l][0])
                return l - 1;
            if (v[l][0] < id && id < v[r][0])
                return l;
            if (v[r][0] < id)
                return r;
        }


    }
    return -1;
}
/*
 *
//            if(l == r && v[l][0] == id) return l;

            if (r - l == 1) {
//                if (v[r][0] == id)
//                    return r;
//                if (v[l][0] == id)
//                    return l;
                if (id < v[l][0])
                    return l - 1;
                if (v[l][0] < id && id < v[r][0])
                    return l;
                if (v[r][0] < id)
                    return r;
            }
            if (mid == 0) {
                if (v[mid][0] == id)
                    return mid;
                else if (v[mid][0] < id)
                    return mid;
                else if (v[mid][0] > mid)
                    return mid - 1;
            }
 */
int* &Lists::begin(){ return v.at(0); }
int* &Lists::end(){ return v.at(v.size() - 1); }

int Lists::fullSearch(const int &id)
{
    for (int i = 0; i < v.size(); ++i) {
        count++;

        if (v[i][0] == id) {
            return i;
        }
    }

    return -1;
}

int Lists::binarySearch(int l, int r, const int &id)
{
    if (sorted) {
        if (l <= r) {
            int mid = (l + r) / 2;
            count++;
            if (v[mid][0] == id) { return mid; }
            if (v[mid][0] > id) { return binarySearch(l, mid - 1, id); }
            if (v[mid][0] < id) { return binarySearch(mid + 1, r, id); }
        }
    }
     return -1;
}


int Lists::remove_by_ID(const int &id)
{

    int res;

    switch(scenario[1])
    {
        case '1':
            res = fullSearch(id);
            break;
        case '2':
            res = binarySearch(0,(int) v.size(), id);
            break;
    }

    if (res != -1)
    {
        v.erase(v.begin() + res, v.begin() + res);
        return res;
    }

    return -1;

//    // If it's exist
//    if (abs(v[0][0] - id) < abs(v[v.size()-1][0] - id)) {
//        for (int i = 0; i < v.size(); ++i)
//        {
//            count++;
//            if (v[i][0] == id)
//            {
//                v.erase(v.begin() + i, v.begin() + i);
//                return 1;
//            }
//
//        }
//    }
//    else if(abs(v[0][0] - id) > abs(v[v.size()-1][0] - id))
//    {
//        for (int i = (int)v.size()-1; i > 0; i--)
//        {
//            count++;
//
//            if (v[i][0] == id)
//            {
//                v.erase(v.begin() + i, v.begin() + i);
//                return 1;
//            }
//
//        }
//    }

}

void Lists::setSorted(bool flag) { sorted = flag; }


void Lists::bubbleSort()
{
    for (int i = 0; i < v.size(); i++) {
        for (int j = i; j < v.size() - 1; j++)
        {
            count++;

            if (v[i][0] > v[j][0])
                std::swap(v[i], v[j]);
        }
    }
}

int Lists::partition(int start, int end)
{
    int pivot = end;
    int j = start;
    for (int i = start; i < end; ++i)
    {
        ++count;

        if (v[i][0] < v[pivot][0])
        {
            std::swap(v[i], v[j]);
            ++j;
        }

    }

    std::swap(v[j], v[pivot]);
    return j;
}

void Lists::quickSort(int start, int end)
{
    if (v.size() > 1) {
        if (start < end) {
            int p = partition(start, end);
            quickSort(start, p - 1);
            quickSort(p + 1, end);
        }
    }
}

std::vector<int*> &Lists::getList() { return v;}
int Lists::getCount() { return count; }

void Lists::setScenario(char s1, char s2)
{
    scenario[0] = s1;
    scenario[1] = s2;
}

Lists::~Lists()
{
    count = 0;
    for (auto node : v)
        delete[] node;
}
