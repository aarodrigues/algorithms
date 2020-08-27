#include <iostream>
#include <vector>

class BinarySearch {
    public:
        bool search(std::vector<int> ordered_list, const int &item) {
            return binarySearch(ordered_list, 0, ordered_list.size()-1, item);
        }

    private:
        bool binarySearch(std::vector<int> ordered_list, const int &start, const int &end, const int &item) {
            if(start > end)
                return false;

            int middle = start + ((end - start)/2);
            if(ordered_list.at(middle) > item) {
                return binarySearch(ordered_list, start, middle-1, item);
            }else if(ordered_list.at(middle) < item){
                return binarySearch(ordered_list, middle+1, end, item);
            }else {
                return true;
            }
        }
};