/* Антон (ikael) из Казани объяснил мне, как работают iterator_traits
Суть - класс (все же структура) она создана для определения типа итератора который подается. 
Подаваться может и простой указатель который мы должны определить как итератор через структуры класса 
iterator_traits






Записал видео и сохранил */


template<class Iter>
typename ft::iterator_traits<Iter>::difference_type
do_distance(Iter first, Iter last, std::input_iterator_tag) {

	typename ft::iterator_traits<Iter>::difference_type diff = 0;
	while (first != last) {
		++first;
		++diff;
	}
	return diff;
}

template<class Iter>
typename ft::iterator_traits<Iter>::difference_type
do_distance(Iter first, Iter last, std::random_access_iterator_tag)
{ return last - first; }

template<class Iter>
typename ft::iterator_traits<Iter>::difference_type
distance(Iter first, Iter last) {
	return do_distance(first, last,
      typename ft::iterator_traits<Iter>::iterator_category());
}