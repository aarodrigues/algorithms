#include <iostream>

class ArrayList {
  public:
    ArrayList();
    ~ArrayList();
    void add(const int &index, const int &value);
    int get(const int &index);
    void add(const int &value);
    bool remove_by_val(const int &value);
    bool remove(const int &index);
    int size();
    void resize();
    void clear();
    bool contains(const int &value);

  private:
    int *array;
    int slot_size;
    int elemet_numbers;
    static const int defaut_size = 10;
    int last_element;
};