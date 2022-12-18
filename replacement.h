/**
* Assignment 5: Page replacement algorithms
 * @file replacement.h
 * @author Rishi Kiran
 * @brief A base class for different page replacement algorithms.
 * @version 0.1
 */
// Remember to add sufficient and clear comments to your code
#pragma once

#include "pagetable.h"
#include <climits>
#include <queue>
#include <bits/stdc++.h> 

/**
 * @brief A base class to simulate page replacement algorithms.
 * A specific page replacement algorithm, e.g. FIFO or LRU, should be subclass of this.
 */
class Replacement
{
protected:      // subclasses can access these members
    // Member variable for the page table
    PageTable page_table;
    list<int> dq; // lru list
    unordered_map<int, list<int>::iterator> lru; // lru hash map
    int num_references = 0; // count references
    int num_pagefaults = 0; //count page faults
    int num_pagereplaces = 0; //cout page replaces
    int number_pages; 
    int number_frames;
    int frame_count = 0; // keep track of frame numbers
    int holder = 0; // hold recently used page number
    int total_count = 0;
	
public:
	/**
	 * @brief 
	 * @param num_pages Total number of logical pages for the simulation.
	 * @param num_frames Total number of available free frames.
	 */
	Replacement(int num_pages, int num_frames);

    /**
     * @brief Destructor
     */
    virtual ~Replacement();

    /**
	 * @brief Simulate a single page access.
     * @details If the page is valid, it calls the touch_page function. 
     *          If the page is not valid but free frames are available, it calls the load_page function.
     *          If the page is not valid and there is no free frame, it calls the replace_page function.
     * @param page_num The logical page number.
	 * @param is_write whether this access a memory write
	 * @return whether it's a page fault: true if it's a page fault
	 */
    virtual bool access_page(int page_num, bool is_write = false);

    /**
	 * @brief Accesss a page alreay in physical memory
	 * It may be overridden in a subclass 
	 * @param page_num The logical page number.
     */
    virtual void touch_page(int page_num) {}

    /**
     * @brief Access an invalid page, but free frames are available.
     * Assign the page to an available  frame, not replacement needed
     * It may be overridden in a subclass 
     * @param page_num The logical page number.
     */
    virtual void load_page(int page_num) {}


    /**
	 * @brief Access an invalid page and no free frame is available.
     * Select a victim page to be replaced.
	 * It is a pure virtual function to be implemented in specific replacement subclasses.
     * @param page_num  The logical page number of the desired page.
	 * @return Selected victim page #
	 */
    virtual int replace_page(int page_num) = 0;

    /**
	 * @brief Get the ith entry of the page table
	 */
    PageEntry getPageEntry(int page_num) {
        return page_table[page_num];
    }

    /**
	 * @brief Print the statistics of simulation
	 */
    void print_statistics() const;
};