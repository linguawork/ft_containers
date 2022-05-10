/*
about iterator_traits typedef in Russian STL of 98 standard by Stepanov:

шаблонный класс iterator_traits в качестве шаблона принимает итератор и наделяет его полями 
которые уже прописаны в основном итераторе 
Хотя эти поля повторяются важность класса iterator_traits в том что они обеспечивают 
частичную специализацию (partial specialization) КОТОРАЯ ОБРАБАТЫВАЕТ ВСЕ ТИПЫ УКАЗАТЕЛЕЙ
(некоторые компиляторы не поддерживают частичную специализацию)

Эта обработка определяет что все указатели это итератора произвольного доступа
(RAI) с типом расстояния ptrdiff_t

Ptrdiff - это целый тип который представляет разницу между любыми двумя объектами-указателями
указывающими на элементы одного массива ( typedef in C library <stddef.h>)
(книга С++ STL , стр 72)

*/