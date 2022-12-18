/**
* Assignment 5: Page replacement algorithms
 * @file replacement.cpp
 * @author Rishi Kiran 
 * @brief A base class for different page replacement algorithms.
 * @version 0.1
 */
// Remember to add sufficient and clear comments to your code

#include "replacement.h"
#include <iostream>
using namespace std;


Replacement::Replacement(int num_pages, int num_frames)
: page_table(num_pages)
{
	number_pages = num_pages;
        number_frames = num_frames;
}

Replacement::~Replacement()
{

}

bool Replacement::access_page(int page_num, bool is_write)
{
    num_references++; 
    page_table[page_num].count++;
    // If the page is valid, it calls the touch_page function. 
    if(page_table[page_num].valid == true){
/*
       if(!dq.empty()){
          dq.erase(lru[page_num]); // update page num reference number
          dq.push_front(page_num);// push page number to fron tof list 
          lru[page_num] = dq.begin(); // assign page number iterator to hash map
       }
*/
       touch_page(page_num);
       return false;
    }
     // If the page is not valid but free frames are available, it calls the load_page function.
    else if(page_table[page_num].valid == false && frame_count != number_frames){
       load_page(page_num);
       return true;
    }
    // If the page is not valid and there is no free frame, it calls the replace_page function.
    else{
       replace_page(page_num);
       return true;
    }
}


// Print out statistics of simulation
void Replacement::print_statistics() const {
    // print out the number of references, number of page faults and number of page replacements
    cout << "Number of references: \t\t"  << num_references << endl;
    cout << "Number of page faults: \t\t" << num_pagefaults << endl;
    cout << "Number of page replacements: \t"  << num_pagereplaces << endl;
}
