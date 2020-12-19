//
// Created by Michael on 07/11/2020.
//
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
#include <time.h>
#include <iostream>
#include "../Header Files/Designer.h"

Designer::Designer() {

}
Designer::Designer(std::string _firstName, std::string _lastName, std::string _gender, int _yearOfBirth,
                           int _yearOfCareerStart, double _rating, std::string _phoneNumber) {
    firstName = _firstName;
    lastName = _lastName;
    gender = _gender;
    yearOfBirth = _yearOfBirth;
    yearOfCareerStart = _yearOfCareerStart;
    rating = _rating;
    phoneNumber = _phoneNumber;
}

void Designer::process(const std::string &photo_path) {
    std::srand(time(0));
    printf("%s %s %s\n", "Image was produced by", firstName.c_str(), lastName.c_str());
    double newRating = double((rand() + 1)%10)/10;
    rating+=newRating;
}
void Designer::printInfo(){
    std::cout << firstName << " " << lastName << ", " << gender << ", " << rating <<"★, " << yearOfBirth << ", " << yearOfCareerStart<<std::endl;
}
double Designer::getRating(){
    return rating;
}


