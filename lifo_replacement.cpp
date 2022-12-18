/**
* Assignment 5: Page replacement algorithms
 * @file lifo_replacement.cpp
 * @author Rishi Kiran 
 * @brief A class implementing the LIFO page replacement algorithms
 * @version 0.1
 */
// Remember to add sufficient and clear comments to your code

#include "lifo_replacement.h"

LIFOReplacement::LIFOReplacement(int num_pages, int num_frames)
: Replacement(num_pages, num_frames)
{

}

LIFOReplacement::~LIFOReplacement() {

}

// Access an invalid page, but free frames are available
void LIFOReplacement::load_page(int page_num) {
    page_table[page_num].valid = true; //update page table
    page_table[page_num].frame_num = frame_count; //assign frame number
    s.push(page_num); // add to stack
    frame_count++;
    num_pagefaults++;
}

// Access an invalid page and no free frames are available
int LIFOReplacement::replace_page(int page_num) {
    int page_change = s.top(); // get victim page number
    page_table[page_change].valid = false; // update page table
    s.pop(); // last page number in stack is popped
    s.push(page_num);
    page_table[page_num].valid = true; // update page table 
    page_table[page_num].frame_num = page_table[page_change].frame_num; //swap frame numbers
    num_pagereplaces++;
    num_pagefaults++;
    return 0;
}
