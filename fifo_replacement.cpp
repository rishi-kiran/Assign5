/**
* Assignment 5: Page replacement algorithms
 * @file fifo_replacement.cpp
 * @author Rishi Kiran 
 * @brief A class implementing the FIFO page replacement algorithms
 * @version 0.1
 */
// Remember to add sufficient and clear comments to your code

#include "fifo_replacement.h"
#include <iostream>
using namespace std;

FIFOReplacement::FIFOReplacement(int num_pages, int num_frames)
: Replacement(num_pages, num_frames)
{
}


FIFOReplacement::~FIFOReplacement() {

}

void FIFOReplacement::load_page(int page_num) {
       page_table[page_num].valid = true; //update page_table
       page_table[page_num].frame_num = frame_count; // assign a frame number
       l.push(page_num); // add to queue
       frame_count++;
       num_pagefaults++;
}

int FIFOReplacement::replace_page(int page_num) {
    int page_change = l.front(); // get victim page number
    page_table[page_change].valid = false; // update page table
    l.pop(); // take page number out of queue
    l.push(page_num); // add new page number 
    page_table[page_num].valid = true;  // update page table
    page_table[page_num].frame_num = page_table[page_change].frame_num; //assign frame number of old page number to new page number
    num_pagereplaces++;
    num_pagefaults++;
    return 0;
}
