#ifndef TEMPLATES_HPP
#define TEMPLATES_HPP

template<typename Container, typename Lambda>
Container filter(Container a, Lambda const& lambda) {
	Container ausgabe{0};
	std::transform(a.begin(), a.end(), ausgabe.begin(), lambda);
	return ausgabe;
}

#endif