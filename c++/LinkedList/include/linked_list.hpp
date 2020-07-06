
class LinkedList {
    public:
      class Node {
          public:
            int data;
            Node *next;

            Node(const int &data) {
                this->data = data;
                this->next = nullptr;
            }
      };

      LinkedList();
      ~LinkedList();
      void append(const int &data);
      void preppend(const int &data);
      bool remove_head();
      bool remove_by_val(const int &data);
      int size();

    private:
      Node *head;
      int list_lenght;
};