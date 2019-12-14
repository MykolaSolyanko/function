# Функции
## Что такое функция?
Часто можно слышать что функция это именованное объединение групы логически связанных операторов, или позволяет выполнять логическое структурирование программы(разбивая на подзадачи более сложную задачу), или избежание повторяющихся кусков кода(в народе copy/paste). Все это верно, но немного детализируем описанные слова.
В большинстве случаев это имя котрое объединяет групу операторов, выполняющих определенную задачу, и что важно это имя может быть вызвано в любой части программы.
Часто мы слышим такое понятие как алгоритм, так вот это и есть именованое структурированное объединение групы операторов выполняющих алгоритм. Давайте на примере рассмотрим алгоритм сортировки. Под именем `sort` мы понимаем что эта функция будет выполнять сортировку, или `pow` мы понимаем что эта функция возведет в степень число. Но не все функции можно назвать алгоритмами, часто это бывают подпрограммы некоторых алгоритмов или задач, которые неназовешь алгоритмом, это просто некая структурированая група операторов которая даст более логическое структурированое понятие в том же самом алгоритме. Расмотрим пример сортировки данных в файле, псевдокод такой:
```
открыть файл

считать данные с файла

отсортировать данные в файле

вывести на экран

записать отсортированные данные в файл

закрыть файл
```

Как видим с перечисленных шагов у нас есть задача(функция) отсортировать данные в файле, она отличаеться от привычной задачи сортировки данных в контейнере(последовательности), и нам надо специализировать ее для нашей задачи. В этой задачи(функции) мы разбиваем ее на подзадачи:

1. Подзадача открытия файла (назвать алгоритмом сложно, просто логически структурированная часть).
2. Подзадача чтения файла (алгоритмом назвать тоже сложно).
3. Отсортировать данные (это уже часть алгоритма).
4. Вывод на экран (алгоритмом назвать тоже сложно).
5. Подзадача записи в файл (алгоритмом назвать тоже сложно).
6. Закрытия файла.


Как видим мы одну задачу структурировали(разбили) на несколько подзадач, и применили один общий алгоритм сортировка на данных.
Алгоритм, это некий общий термин который позволяет разработчикам более общим прнятием общаться чем вдаваться в детали сути задачи. Например сортировка, мы не говорим взять одну последовательнсоть, пробежаться по элементам этой последовательности, взять первый элемент сравнить со следующим, вообщем..... Мы говорим используй сортировку, и всем становиться все понятно.
Принимают также такое понятие как дублирование кода, например в вашем коде часто применяеться одинакова последовательность кода, ее сложно например назвать алгоритмом, но ее можно назвать логическим названием, для уменьшения так называемого копи паста).

## Синтаксис функции
Функция имеет следующий синтаксис
```
тип_возвращаемого_значения имя_функции (список параметров) {
  тело функции
}
```
С описания все просто) Простым словом у функции есть имя (которое соответсвет правилам индетификаторам, и служит логическим описание что делает функция), есть входные данные определяемые понятием `список параметров `(правильно сказать данные), над которыми она выполняет некие действия, и выходные данные  определяемое `тип_возвращаемого_значения`(результат работы функции). И `тело функции` выполняющую группу логически связанных операторов. Что важно то что `список параметров ` или `тип_возвращаемого_значения` могут отсутсвовать, так как функция не всегда обязана что то принимать или что то возращать.

## Список параметров
Список параметров это данные с которыми будет работать ваша функция.
Сам параметр это как объвление обычной переменной(имеет тип и название). Список параметров разделяеться запятой, имена параметров должны отличаться. Дальше эти параметры будут использоваться в теле функции как обычные переменные. Параметры это данные которые будут передаваться при вызове функции. 
Иногда можно услышать что их называют фактическими и формальными параметрами
```
long calc(int a, int b) {
  return a + b;
}

....
int value1 = 40;
int value2 = 50;
calc(value1, value2);
``` 
В примере выше параметры `а` и `и` в функции `calc` есть формальными параметрами, а переменные `value1` и `value2` есть фактическими параметрами при вызове функции.

Стоит заметить что в С++ нет такого понятия как именованная позиционная передача параметров(хотя пропозолов по этому поводу есть очень много), и это может быть причиной логической ошибкой при передаче параметров одного типа. Например:
```
void move(float x, float y)
```

С примера выше видно что можно передать не правильные координаты, поменяв их местами. Есть масса способов это бороть, один из них это применение пользовательских типов (которые мы будем изучать дальше на курсе).

Список параметров может и отсутсвовать, т.е. функция может и не принимать параметров, в этом случае просто пишут пустые скобочки, скобки нельзя опускать, должны писаться объязательно, например
```cpp
bool HasInternetConnection();
или
bool HasInternetConnection(void); // но это редкий случай что так пишут, лучше так не писать
```

Также при перечеслении параметров, тип  необходимо писать перед каждой переменной.
```
long calc(int a, int b); // правильное написание

long calc(int a, b); // являеться синтаксической ошибкой
``` 

## Возвращаемое значение функции
Функции могут как возвращать значение, так и не возвращать.
Возращаемое значение случит результатом выполнения функции, это может быть вычеслительный результат(функция `pow`), логический(например `isdigit` т.е. проверка являеться символ цифрой), и системной(т.е. возврат кода ошибки). Но их может быть много и других.

Для того чтобы вернуть результат из функции необходимо в теле функции указать ключеое слово`return` за которым следует выражение, литерал, переменная в случае если функции должна вернуть результат своей работы.
Функции не возвращающие значения позначаються ключевым словом `void`, это даже не ключевое слово это как маркер ничего(недействительный).
Ключевое слово `return ` это как прерывание выполнение функции, т.е. если в теле функции написать `return`, то дальнейшее выполнение функции будет прервано, и управление перейдет к месту где наша функция была вызвана. И это даже будет работать если функция ничего возращать не будет, тогда если указать просто ключевое слово `return` без выражения, или переменной или литерала, то будет просто прервано выполнения программы.

В теле функции оператор `return` может встречаться в многих местах (в условных операторах, циклах и т.д.), но если функция возращает значение тогда выражение после `return` должно быть возможным преобразовываться в тип возращаемого значения указаного в объявления функции.
Если функция в которай указан тип возращаемого значения, но в теле функции не указан опреатор `return` или указан пустым, то мы возможно получим ошибку компиляции или предупреждения от компилятора.

```cpp
#include <cmath>
#include <iostream>

double calcSqrt(int a) {
  if (a >= 0) {
    return sqrt(a);
  } else {
    // получим ошибку компиляции что return без значения
    // return; // так как тут мы не узали возращаемое значение
    // получим ошибку несовместимости типов, выражение будет типа &a -> int *
    // return &a;
    return 0.0; 
  }
}

bool isDigit(unsigned char ch) {
  return (ch >= 48 && ch <= 57); // возращаемое значение будет тип bool
}

// в качестве возращаемого значения можно указать auto,
// в этом случае компилятор сам выведит тип возращаемого значения, как при обьявлении переменной
auto calcSumm(int a, int b, int c) {
  return a + b + c; // возращаемый тип будет как минимум  int
}


 /*
 в этом случае будет ошибка компиляции, так в одном return будет тип int
 тогда как в другом будет double
 если мы указали в качестве возращаемого значения ключевое слово auto, то у нас все return в теле функции
 должны возращать или выражения или литерал и переменные одного типа, нельзя в одном return указать один тип,
 а в другом return указать другой тип
 */
/*auto errorDeducation(bool val) {
  if (val) {
    return 123; // возвращаемый тип int
  } else {
    return 3.14f;   // ошибка: возращаемый тип float
  }
}*/

int main(int argc, char const *argv[]) {
  std::cout << calcSqrt(10) << std::endl;
  std::cout << std::boolalpha;
  std::cout << isDigit('a') << std::endl;
  std::cout << isDigit('1') << std::endl;
  std::cout << isDigit('&') << std::endl;
  std::cout << calcSumm(10, 5, 15)) << std::endl;
  // std::cout << errorDeducation(false));
  return 0;
}

```
Как видно из примера выше начиная с С++11 с появление ключевого слова `auto`, вывод типа также возможен и для возращаемого значения функции. Вывод возвращаемого значения также включает все правила как и для обычных правил вывода типа (для переменной). Вывод типа не возможен, если несколько операторов `return` будут иметь разные типовые возвращаемые зачения, т.е. если при автоматическом выводе типа в нескольких операторах `return` указать разные несовместимые типы, например `float и int`, то компиялтор выдаст ошибку что он незнает какой тип ему надо вывести.

## Способы передачи параметров в функцию
### Передача по значению
Этот способ передачи это простое копирование одних переменных(фактических) в другие (в формальные). Т.е. любые изменения сделаные с формальными параметрами никак не влияют на актуальные параметры (фактические параметры). Это самы простой способ передачи. Т.е. у нас разные копии объектов котрые не влияют друг-на-друга. Иногда аргумент указывают как `const`, и говорят что это бесполезное ведь мы никак не изменим оригинальное значение, это правда, но модификатор `const` полезный в том случае если необходимо указать что значение переменной не измениться на протяжении выполнения функции. Иногда можно увидеть что аргументы функции могут быть указаны c помощью ключевого слова `auto`. И это на некоторых компиляторах работает, но **очень важно** что автоматический вывод типа, запрещен стандартом ISO, и если ваш код компилируеться на одном компияторе, то возможно ваш код не будет компилироваться другим компилятором. Есть такая опция компилятора `pedantic` мы его уже расматривали когда изучали масивы, при указании которого наш код перестанет компилироваться если указать опцию(флаг) `pedantic` при компиляции.
```cpp
#include <iostream>

void justPrint(int a, int b) {
  a = 10;
  std::cout << a << std::endl;
  b = 25;
  std::cout << b std::endl;
}

int main(int argc, char const *argv[]) {
  int a = 40;
  int b = 88;
  std::cout << a << std::endl;
  std::cout << b << std::endl;
  justPrint(a, b);

  std::cout << "After called function justPrint" << std::endl;
  std::cout << a << std::endl;
  std::cout << b << std::endl;
  return 0;
}
```

### Стек и вызов функции
При вызове функции происходит довольно много интересного.
Интересно то как вызов функции вляет на такую память как stack(работающих по принципу LIFO), т.е .при вызове фунции алгоритм приблизительно такой

1. Ложиться адресс возврата функции, т.е. адресс инструкции следующей за вызовом функци.
2. Ложаться параметры(ее аргументы) при вызове функции
3. Ложаться все локальные переменные обьявленные в теле функции в стек
4. Возвращаемое значения используеться по соглашонному регистру

Из описаного алгоритма вытекает то что мы можем получить переполнение стека, т.е. чем больше мы параметров передадим тем больше мы увеличиваем размер стека и чем больше мы объявляем локальных переменных тем больше растет стек. Если есть ограичения на стек(что всегда истино на большинстве систем) то мы можем получить переполнения стека.
Теперь видно что количество параметров при вызове функции ограничиваеться размером стека.

https://www.viva64.com/ru/t/0087/

### Соглашения о вызове
Это соглашение описывает как будут передаваться аргументы в стек, какие будут применяться ругистры, способ возврата результата с подпрограммы, кто ответсвенный за очистку стека.
Например в С/С++ применяеться это `cdecl` и `thiscall`

Более детально о соглашении о вызове можно прочитать ниже по ссылкам.
https://ru.wikipedia.org/wiki/%D0%A1%D0%BE%D0%B3%D0%BB%D0%B0%D1%88%D0%B5%D0%BD%D0%B8%D0%B5_%D0%BE_%D0%B2%D1%8B%D0%B7%D0%BE%D0%B2%D0%B5

https://scc.ustc.edu.cn/zlsc/sugon/intel/compiler_c/main_cls/bldaps_cls/common/bldaps_calling_conv.htm

https://docs.microsoft.com/en-us/cpp/cpp/argument-passing-and-naming-conventions?view=vs-2017


### Передача по указателю
Как мы знаем с предыдущих разделов указатель это просто переменная хранящая адресс другой переменной (как пример). И в связи с этим это один из способов, скажем так этот способ есть наследия языка С, изменения фактического параметра, т.е.  возможность работать внутри вызываеной функции с оригинальным значением переменной посредсвом адресса переменной указанным в указателе.

Что важно заметить что в качестве аргумента мы создаем переменную указатель, которая будет просто хранить адресс аргмента который был передан при вызове функции. Важным в этом случае становиться понятие константности данных куда указывает указатель, ведь это становиться логичным если мы работаем с оригинальным значением.

Зачем вообще передавать параметры которые могут меняться в теле функции? Это необходимо в ряде случаев:
1. Это возможность возврата с функции нескольких значений
2. Возможность передачи массива, так как он неявно преобразовываеться в указатель на первый элемент. 
3. Возможность избежания тяжоловесного копирования пользовательських объектов (это мы рассмотрим в следующих лекциях курса).

Мы знаем что указатель может как содержать адресс другой переменной так и null, из этого следует что перед разыменование указателя необходимо его проверить на null. **Это очень важное замечание**.
Часто у новичков есть ошибка как возрат из функции адресса локальной переменной. Это результат прриводит к неопределенному поведению, т.к. мы знаем что локальная переменная выделяеться на стеке и удаляеться когда выходит из области видимости, в нашем примере областью видимости локальных переменных внутри функции есть сама функция, и соответсвенно после того как функция завершит свое выполнение, переменной больше не будет на стеке. И возможный исход разыменование такого указателя может привести в падению программы.
```cpp
#include <iostream>

void copy_swap_func(int a, int b) {
  int tmp = a;
  a = b;
  b = tmp;
}

void swap_func(int* a, int* b) {
  if (a != nullptr && b != nullptr) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
  } else {
    std::cout << "One of the argument is null\n" << std::endl;
  }
}

int main(void) {
  int first_value = 10;
  int second_value = 20;
  std::cout << first_value << second_value << std::endl;;
  copy_swap_func(first_value, second_value); // ничего не измениться т.к. внутри функции происходим обмен данными для копий
  std::cout << first_value <<  second_value <<  std::endl;
  swap_func(&first_value, &second_value); // значения в переменных first_value и second_value изменяться, т.к. происходит передача по указателю 
  std::cout << first_value << second_value << std::endl;
  swap_func(&first_value, nullptr); // напечатаеться сообщение что один из аргументов null

  return 0;
}
```

### Массив как параметр функции
После того как мы с вами рассмотрели способ передачи аргументов по указателю, тот стоит задать себе такой маленький вопрос а как же передавать масивы в функции?
Можно подумать что массивы можно передавать по значение, ну как бы логично, но не совсем. Давайте вспомним что происходит при вызове функции, да да и еще раз да, происходит наполнение памяти стека, данными необходимыми при вызове функции, а представте что если у нас функция вызывает другую функцию, а другая функция вызвает еще другую(под другой функцией мы понимаем функцию с разным именем). И что если мы в кажестве аргументов будем передавать массивы по значению, т.е. весь массив будет просто копироваться в память стека при вызове функции. Я думаю что тут всем очевидный исход, что таких функций мы много не вызовем. Так и подумали разработчики языка С(ведь передача по указателю это наследия языка С), и решили что это будет не эфективно копировать весь массив при вызове функции, а давайте будет вместо всего массива использовать указатель на первый элемент массива. **Вот** откуда пошла возможность неявного преобразования имени масива в указатель на первый элемент. Я вам скажу что это гениально и элегантно)

Делаем вывод из выше сказаного
- Массивы в отличие от примитивных типов не передаются по значению
- Размерность массива при передачи как параметра в функцию игрнорируется(это вызывает в большинства не понимание)
- Определение размера массива как мы расатривали в передыдущих лекциях с помощью sizeof дает не те ожидаимые результаты. Одним словом получить размер масива(количество элементов) спомощью имени указателя не получиться.
- При передачи как параметра в функцию многомерного массива размерность первого уровня игнорируеться как и для одномерных массивов, а вот размер второго уровня необходимо указывать, иначе будет ошибка компиляции(это надо принять как есть).

```cpp
#include <iostream>

void incorrect_print_array(int array[5]/*the same int array[]*/ /*the same as int* array*/) {
  // результат будет не такой как ожидается(см. раздел с указателями)
  std::cout << SIZE_ARRAY(array) << std::endl;
  for (size_t i = 0; i < 5; ++i) {
    std::cout << array[i] << " ";
  }
  std::cout << std::endl;
}

void correct_print_array(int array[], size_t length) {
  for (size_t i = 0; i < length; ++i) {
    std::cout << array[i] << " ";
  }
  std::cout << std::endl;
}

// при передачи многомерного массива первый уровень игнорируеться компилятором как при работе с одномерным массивом
// а вот размер второго уровня обьязателен, если его указать или передать неверный размер то будет ошибка компиляции
void print_2D_array(int array[][2], size_t length_first_dim) {
  for (size_t i = 0; i < length_first_dim; ++i) {
    for (size_t j = 0; j < 2; ++j) {
      std::cout << array[i][j] << " ";
    }
    std::cout << std::endl;
  }
}

int main() {
  int array[5] = {5, 4, 3, 2, 1};
  int array2[7] = {7, 6, 5, 4, 3, 2, 1};
  size_t SIZE_ARRAY = sizeof(array) / sizeof(array[0]);
  std::cout << SIZE_ARRAY << std::endl;
  buble_sort(array);
  // buble_sort(array2); compiler error initialization of reference of type ‘int (&)[5]’ from expression of type ‘int [7]’

  incorrect_print_array(array); // print 1 2 3 4 5
  // программа компилируеться без ошибок, так как по умолчанию размер массива игнорируеться
  incorrect_print_array(array2); // print 7 6 5 4 3
  size_t SIZE_ARRAY2 = sizeof(array2) / sizeof(array2[0]);
  correct_print_array(array2, SIZE_ARRAY2); // print 7 6 5 4 3 2 1

  int array2D[][2] = {{1,2}, {3,4}, {5,6}};
  size_t SIZE_ARRAY_FIRST_LEVEL = sizeof(array2D) / sizeof(array2D[0]);
  print_2D_array(array2D, SIZE_ARRAY(array2D));
  // int array2D_error[][3] = {{1,2,3}, {4,5,6}, {7,8,9}};
  // print_2D_array(array2D_error, SIZE_ARRAY(array2D_error)); // compilation error, несовместимость типов(размеров)
  return 0;
}
```
**Обратите внимание** на функцию `incorrect_print_array` мы ей передаем как параметр аргумента массив, но как было сказано раньше и указано в коментариях к функции, не важно что вы укажете в скобочках массива т.е. размер, или пустый скобочки, компиятор просто это все проигнорирует и преобразует это все просто в указтель на первый элемент массива который вы передали при вызове функции в нашем примере это `int* array`. Иногда ставят просто `[]` это больше используют для читабельности кода нежели для правильности, т.е. читающему кода говорить что должен передаеваться массив, если бы это был просто указатель, то это было бы не очевидно что внутри функции будет работа с массивом. Но возникает тогда важный вопрос а как же указать размер массива? Тут есть как минимум два распространненых подхода. Первый как в примере в функции `correct_print_array` мы передаем вторым параметром размер массива, но это чревато многим ошибкам, т.е. ошибиться в размере массива достаточно легко, и мы можем получить неопределенное поведение при выходе за границы массива. Второй способ который я больше всего предпочитаю, и как  по мне менее подвержен ошибкам это передача указателя на начало массива и указателя на элемент следующий за последним элементом массива. Вы конечно помните что стандартом оговорено получения адресса элемнта массива следующий за последним элемнтом массива являеться коректным.
Давайте перепишем пример с указателями
```cpp
void print_array(const int* begin, const int* const end) {
  while (begin != end) {
    std::cout << *begin << " ";
  }
  std::cout << std::endl;
}

int main() {
  size_t SIZE {5};
  int array[SIZE] {1, 2, 3, 4, 5};
  print_array(array, array + SIZE);
}
```
Как по мне код стал выразительней. Тут важно сказать что функция написана в стиле STL(стандартная библиотека). Но тут еще стоит обратить на интерфейс функции, `begin` это указатель котрый будет указывать на первый элемент массива и мы его иициализируем переменной массива `array`, который согласно стандарту будет неявно преобразован в указатель на первый элемент. Но важно то что мы указали `const int*`, это значит что мы небудем изменять то на что указывает `begin`. А вот аргумент `end` его смысл это указатель на элемент следующий за последним элементом массива, и посмотрите как он инициализируеться `array + SIZE`, таким способом мы передаем указатель на этот самый последний элемент. И что важно это его интерфейс, мы его обьявили как константный указатель на константные данные, т.е. это говорит читающему ваш код что `end` не что иное как маркер конца обхода массива.
Почему я предпочитаю такой подход, это то что такой интерфейс говорит что эта функция будет обходить последовательность в диапазоне `[begin, end)` 

## Тернарный оператор
Иногда в функции в зависимости от входного значения нужно вернуть либо одно значение или другое, ну простым словом написать оператор `if`.
Пример
```cpp
// напишем функцию которая если значение нечетное, то мы возращаем инкриментируемое значенние
// иначе возращаем декриментируемое значение 
size_t IncDecOddEven(size_t value) {
  if (value % 2 != 0) {
    return value + 1;
  }
  return value - 1;
}
```
как видите в нашей функции есть два `return`, этого можно избежать если использовать тернарный оператор.
Тернарный оператор это сокращенная форма записи `if - else`. Но важно что тернарные операторы это односторочные операторы и они просто заменяют однострочные `if - else`.
Давайте перепишим наш пример с применением тернарного оператора
```cpp
size_t IncDecOddEven(size_t value) {
  return value % 2 != 0 ? return value + 1 : value - 1;
}
```
Как видно из кода наш пример стал намного элегантней, и читабелен.
Смысл этого оператора такой, что если наше условие истиное, т.е. возращает `true`, то будет выполнено выражение идущее после `?`, иначе будет выполнено выражение после `:`. Как видно это класическая и читабельная замена простого `if - else`.
Вы должны понимать что тернарный оператор можно использовать и для инициализации или присвоение переменной.

```cpp

size_t value = 10;

...
size_t new_value = value % 2 ? value + 1 : value - 1;

// вместо такого
/*
size_t new_value;
if (value % 2) {
  new_value = value + 1;
} else {
  new_value = value - 1;
}
*/
```

## Параметры по умолчанию
Можно также некоторым аргументам задавать значения по умолчанию, и при вызове функции аргумент у которого установлен значение по умолчанию, можно опускать, и параметр будет проинициализирован при вызове функции этим аргументом по умолчанию. Т.е. это похоже на объявление с инициализацией. Параметры по умолчанию должны идти с права на лево, нельзя для одного параметра указать значение по умолчанию, потом для другого опустить, а для следующего задать
Например
```cpp
#include <iostream>

// компилятор выдаст ошибку компиляции,
// в том что мы пропустили значение по умолчанию для второго аргумента
/*long calc(int a = 10, int b) {
  return a + b;
}*/

long calc(int a, int b = 5) {
  return a + b;
}

int main(int argc, char const *argv[]) {
    std::cout << calc(10, 20)) << std::endl;; // 30
    // в примере параметр b будет инициализирован значением по умолчанию 5
    std::cout << calc(10)) << std::endl; // 15
    return 0;
}
```