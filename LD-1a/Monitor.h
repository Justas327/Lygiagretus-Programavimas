//
// Created by justas327 on 2019-10-10.
//

#ifndef LD_1A_MONITOR_H
#define LD_1A_MONITOR_H


#include <condition_variable>
#include "Car.h"

class Monitor {
private:
    /**
     * Finds place for car object in sorted array
     * @param car Carr object
     * @return Found index
     */
    int find_index(Car &car);

    /**
     * Shifts all cars array to right by one from given index
     * @param index Index
     */
    void shift_list(int index);

    unsigned int size;
    unsigned int capacity;

    mutex lock;

    volatile bool finished;
    Car *list;
public:
    /**
     * Initialises cars array to given size
     * @param size Cars array size
     */
    Monitor(int size);

    /**
     * Deletes cars array
     */
    ~Monitor();

    /**
     * Adds given car object to array
     * @param new_car New car
     * @param sorted true if array is sorted, false if not
     */
    void add(Car &new_car, bool sorted=false);

    /**
     * Returns car object by given index
     * @param index index in array
     * @return Found car
     */
    Car get(unsigned int index);

    /**
     * Returns current cars count
     * @return Cars count
     */
    unsigned int get_size();

    /**
     * Flag for setting no more data will be added in the future
     */
    void data_loading_finished();

    /**
     * Checks flag if there will be more data added
     * @return true if there will be more data, false if not
     */
    bool is_loading_finished();

    /**
     * Pops car object from the array end
     */
    Car pop();
};


#endif //LD_1A_MONITOR_H