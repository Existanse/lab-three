//
// Created by Michael on 06.10.2020.
//
/*Класс ФОТОГРАФ.
Данные: имя, фамилия, пол, год рождения, год начала деятельности, рейтинг.
Создать 2 фотографов в куче и одного в стеке. Данные первых двух заполнить с
помощью сеттеров, а третий проинициализировать с помощью конструктора с
параметрами. В главной функции проимитировать три фотосессии и голосование
зрителей по их результатам (нарастить рейтинг каждого фотографа на случайное число
из диапазона 0.0..1.0; если количество проголосовавших людей меньше 10, то не
наращивать рейтинг). Вывести список фотографов в порядке убывания суммарного
рейтинга.*/
//Класс ФОТОГРАФ + классы ДИЗАЙНЕР, СОТРУДНИК.
//Реализовать схему наследования классов и корректно распределить по классам данные:
//имя, фамилия, пол, год рождения, год начала деятельности, рейтинг, телефон,
//        количество фотографий в портфолио.
//Интерфейс обработки компьютерных изображений IPictureProcessor с методом void
//process(const std::string& photo_path). Реализация метода в классе фотографа:
//вывод на экран сообщения “Photo was processed by /имя_фотографа/”, а также
//наращивание количества фотографий в портфолио. Реализация метода в классе
//дизайнера: вывод на экран сообщения “Image was produced by /имя_дизайнера/”, а также
//изменение рейтинга на некоторую величину. В main() cоздать 2 фотографов и 2
//дизайнеров, продемонстрировать полиморфизм process().
#ifndef LABTHREECPP_PHOTOGRAPHER_H
#define LABTHREECPP_PHOTOGRAPHER_H
#include <iostream>
#include "Employee.h"
#include "IPictureProcessor.h"

class Photographer: public Employee, public IPictureProcessor{
    public:
        Photographer();
        Photographer(std::string firstName, std::string lastName, std::string gender, int yearOfBirth, int yearOfCareerStart, double rating, std::string phoneNumber, int totalPhotos);
        void printInfo() override;
        virtual ~Photographer(){}
        void process(const std::string &photo_path) override;
        int getTotalPhotos();
    private:
        int totalPhotos = 0;
};


#endif //LABTHREECPP_PHOTOGRAPHER_H