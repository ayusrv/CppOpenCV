#ifndef ITEM
#define ITEM


//Class created for Item
class item{
    private:
        //Product Type
        int prod_type;
        //Number of Items
        int number_of_items;
        //Total cash in hand =100;
        int cash_in_hand;
        //cost per item Pizza->20 and Burger->10
        int cost_per_item;
    public:
        //Deafult Constructor
        item();
        //Sell Item class
        void sellItem();
};

#endif