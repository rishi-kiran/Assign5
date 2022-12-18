/**
* Assignment 5: Page replacement algorithms
 * @file lru_replacement.cpp
 * @author Rishi Kiran 
 * @brief A class implementing the LRU page replacement algorithms
 * @version 0.1
 */
// Remember to add sufficient and clear comments to your code

#include "lru_replacement.h"
#include <climits>
#include <iostream>
using namespace std;
LRUReplacement::LRUReplacement(int num_pages, int num_frames)
: Replacement(num_pages, num_frames)
{

}

LRUReplacement::~LRUReplacement()
{

}

void LRUReplacement::touch_page(int page_num)
{
     if(!dq.empty()){
          dq.erase(lru[page_num]); // update page num reference number
          dq.push_front(page_num);// push page number to fron tof list
          lru[page_num] = dq.begin(); // assign page number iterator to hash map
       }
}

void LRUReplacement::load_page(int page_num) {
     page_table[page_num].valid = true; //update page table
     page_table[page_num].frame_num = frame_count; // assign frame number
     dq.push_front(page_num); // add page number to list
     lru[page_num] = dq.begin(); // put page number iterator in hash map
     frame_count++;
     num_pagefaults++;
}

int LRUReplacement::replace_page(int page_num) {
    int hold = dq.back(); // get lru page number

    page_table[hold].valid = false; // update page table
    page_table[page_num].valid = true;  
    page_table[page_num].frame_num = page_table[hold].frame_num; //swap page numbers
    dq.pop_back(); // delete lru page number
    lru.erase(hold); // delete lru page number from hash map
    dq.push_front(page_num); //add new page number
    lru[page_num] = dq.begin(); // add page number iterator to hash map
    num_pagefaults++;
    num_pagereplaces++;
    return 0;
}
