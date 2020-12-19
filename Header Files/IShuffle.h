//
// Created by Michael on 07/11/2020.
//

#ifndef LABTHREECPP_ISHUFFLE_H
#define LABTHREECPP_ISHUFFLE_H


class IShuffle {
    public:
        virtual void shuffle() const = 0;
        virtual void shuffle(size_t i, size_t j) const = 0;
        virtual ~IShuffle(){}
};


#endif //LABTHREECPP_ISHUFFLE_H
