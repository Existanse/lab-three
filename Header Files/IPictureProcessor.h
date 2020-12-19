//
// Created by Michael on 07/11/2020.
//

#ifndef LABTHREECPP_IPICTUREPROCESSOR_H
#define LABTHREECPP_IPICTUREPROCESSOR_H

#include <string>

class IPictureProcessor{
    public:
        virtual void process(const std::string& photo_path) = 0;
        virtual  ~IPictureProcessor(){}
};
#endif //LABTHREECPP_IPICTUREPROCESSOR_H
