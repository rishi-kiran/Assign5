/**
* Assignment 5: Page replacement algorithms
 * @file pagetable.cpp
 * @author Rishi Kiran 
 * @brief This class represents a traditional pagetable data structure.
 * @version 0.1
 */
//You must complete the all parts marked as "TODO". Delete "TODO" after you are done.
// Remember to add sufficient and clear comments to your code

#include "pagetable.h"
#include <iostream>
using namespace std;

// TODO: Add your implementation of PageTable
PageTable::PageTable(int num_pages){
   number_pages = num_pages;
   PageEntry obj;
   // populate page table
   for(int i = 1; i <= number_pages; i++){
       pages.push_back(obj);
   }
}
PageTable::~PageTable(){

}
