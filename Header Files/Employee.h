//
// Created by Michael on 07/11/2020.
//

#ifndef LABTHREECPP_EMPLOYEE_H
#define LABTHREECPP_EMPLOYEE_H

#include <string>
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
class Employee{
    public:
        virtual void printInfo() = 0;
        virtual ~Employee(){}
    protected:
        std::string firstName;
        std::string lastName;
        std::string gender;
        int yearOfBirth;
        int yearOfCareerStart;
        double rating;
        std::string phoneNumber;
};
#endif //LABTHREECPP_EMPLOYEE_H
