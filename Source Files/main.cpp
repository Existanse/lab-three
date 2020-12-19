#include <iostream>
#include "../Header Files/ExpressionEvaluator.h"
#include "../Header Files/CustomExpressionEvaluator.h"
#include "../Header Files/Subtractor.h"
#include "../Header Files/Multiplier.h"
#include "../Header Files/Photographer.h"
#include "../Header Files/Designer.h"
/*Написать в ООП-стиле код программы, позволяющей работать с арифметическими
выражениями разного вида, оперирующими вещественными числами: вычислять
        результат выражения, выводить запись выражения на консоль и в файл лога.
Например, для вычисления выражений вида (10+4+2+3+7+1) и (1+2.5) будет
        использоваться класс Summator, выражений вида (2*3*7*1) – класс Multiplier, и т.д.
В коде необходимо отразить следующее:
 Создать интерфейс ILoggable с 2 методами (функционал логирования):
Запись лога всего выражения на консоль:
void logToScreen()
Добавление записи лога всего выражения в файл лога:
void logToFile(const std::string& filename).
 Создать абстрактный класс ExpressionEvaluator, реализующий интерфейс
        ILoggable и предоставляющий чисто виртуальный метод double calculate() для
        вычисления результата произвольного выражения. Количество операндов должно
        храниться в отдельном члене класса. Сами операнды х1,х2,х3 и т.д. должны
        храниться в члене данного класса – массиве, в куче (динамической памяти).
 Класс ExpressionEvaluator должен предоставлять два конструктора и
        виртуальный деструктор. В конструкторе без параметров выделять память под 20
операндов и инициализировать их нулями, в конструкторе с параметром n –
выделять память под n элементов и инициализировать нулями. Также необходимо
реализовать 2 метода, позволяющие присвоить операндам конкретные значения:
Присвоить значение value одному операнду на позиции pos:
void setOperand(size_t pos, double value)
Заполнить сразу группу из n операндов массивом значений ops:
void setOperands(double ops[], size_t n)
 В деструкторе должна освобождаться память, выделенная в конструкторе.
 Создать два подкласса класса ExpressionEvaluator, работающих со стандартными
        выражениями, в соответствии с вариантом, из четырех возможных:
Summator – сумма всех операндов (х1 + х2 + х3 + х4 + ...)
Subtractor – разность всех операндов (х1 – х2 – х3 – х4 – ...)
Multiplier – произведение всех операндов (х1 * х2 * х3 * х4 * ...)
Divisor – частное всех операндов (х1/х2/х3/х4/...), но если хоть один
операнд равен 0, то результату выражения присвоить также 0.
 Создать подкласс CustomExpressionEvaluator, работающий со специфическими
        выражениями, вид которых приведен в варианте.
 Подклассы ExpressionEvaluator, для которых порядок следования операндов
важен, должны также реализовывать интерфейс IShuffle. Данный интерфейс
объявляет 2 перегруженных метода (функционал перемешивания операндов):
Произвольно перемешать операнды:
void shuffle()
Перемешать операнды, находящиеся на позициях i и j:
void shuffle(size_t i, size_t j)
В функции main() необходимо продемонстрировать работу созданных классов:
 Создать массив из трех указателей на класс обработки арифметических выражений.
 В соответствии с вариантом, создать в куче три объекта конкретных подклассов
обработки арифметических выражений и установить на них указатели; присвоить
        их операндам значения двумя способами (поэлементным и групповым).
 Продемонстрировать полиморфизм: организовать проход в цикле по указателям и
        вывести лог выражения на консоль и в файл (в консоли отобразить еще и сам
        результат выражения).
 Организовать цикл по указателям, в теле которого средствами С++ проверить,
реализует ли текущий объект интерфейс IShuffle. Если да, то вызвать один из
        методов shuffle() этого объекта и отобразить на экране запись выражения после
        перемешивания операндов, а также вычислить и отобразить результат нового
        выражения.
Ниже приведена желательная структура проекта (например, для случая, когда нужно
использовать классы Summator и Multiplier):
Примечание. Отрицательные операнды при выводе записи выражения на экран и в
файл должны автоматически браться в скобки (подробнее см. приложение В)*/
void taskOne();
void taskTwo();

int main() {
    taskOne();
    taskTwo();
    return 0;
}

#pragma region Task One
void taskOne(){
//    CustomExpressionEvaluator: 5 операндов, присвоить группой 5, 10, -2.5, -40, -2.
//    Subtractor: 9 операндов, присвоить группой 120,-12, 83.2, -1.5, 5, 7, 2, 18.5, 76.
//    Multiplier: 2 операнда, присвоить поэлементно -1.5, 80.
    printf("%s\n", "----Task One----");
    ExpressionEvaluator* evaluators[3];

    double customOperands[] = {5, 10, -2.5, -40, -2};
    auto* customExpressionEvaluator = new CustomExpressionEvaluator(5);
    evaluators[0] = customExpressionEvaluator;
    evaluators[0]->setOperands(customOperands, 5);

    double subtractorOperands[] = {120, -12, 83.2, -1.5, 5, 7, 2, 18.5, 76};
    evaluators[1] = new Subtractor(9);
    evaluators[1]->setOperands(subtractorOperands, 9);

    evaluators[2] = new Multiplier(2);
    evaluators[2]->setOperand(0, -1.5);
    evaluators[2]->setOperand(1, 80);

    for(auto & evaluator : evaluators){
        std::cout<<evaluator->getName()<<':'<<std::endl;
        std::cout<<'<'<<evaluator->getN()<<'>'<<std::endl;
        evaluator->logToFile("Lab3.log");
        evaluator->logToScreen();
        std::cout<<"<Result: "<<evaluator->calculate()<<">"<<std::endl;
    }
    for(auto & evaluator : evaluators) {
        IShuffle* shufflable = dynamic_cast<IShuffle*>(evaluator);
        if(shufflable!= nullptr){
            std::cout<<evaluator->getName()<<" is shuffleable!"<<std::endl;
            std::cout<<"Before shuffling: "<< std::endl;
            evaluator->logToScreen();
            shufflable->shuffle();
            std::cout<<"After shuffling: "<< std::endl;
            evaluator->logToScreen();
        }
    }
    for(auto & evaluator : evaluators) {
        delete evaluator;
    }
}
#pragma endregion
#pragma region Task Two
/*Дополнить код задания 3 лабораторной работы № 2, написав еще два класса по
        предметной области, в соответствии с вариантом. Продумать и корректно реализовать
схему наследования классов. В главной функции продемонстрировать применение
        интерфейса, полиморфизм и RTTI на примере 3-4 объектов классов, по аналогии с
заданием 1.
Примечание. Данное задание творческое. Вы можете свободно вводить различные
        свойства и метода классов, не указанные явно в задании.*/
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
void taskTwo(){
    printf("%s\n", "----Task Two----");
    Employee* employees[4];

    Photographer* bo = new Photographer("barack", "obama", "m", 1984, 2000, 3.5, "0713123123", 6);
    employees[0] = bo;
    Photographer* bg = new Photographer("bill", "gates", "m", 1978, 2005, 3.4, "0713123124", 4);
    employees[1] = bg;

    Designer* qe = new Designer("queen", "elizabeth", "f", 1000, 2020, 4.1, "0713123125");
    employees[2] = qe;
    Designer* th = new Designer("tom", "hanks", "m", 1960, 2001, 2, "0713126126");
    employees[3] = th;
    printf("Our employees are:\n");
    for(auto & employee : employees) {
        employee->printInfo();
    }
    printf("Now everybody who can process a photo will:\n");
    for(auto & employee : employees) {
        employee->printInfo();
        IPictureProcessor* processor = dynamic_cast<IPictureProcessor*>(employee); //rtti
        if(processor != nullptr){
            processor->process("any photo");
            employee->printInfo();
        }
    }
    for (auto & employee : employees){
        delete employee;
    }
}