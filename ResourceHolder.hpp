#pragma once
#include <map>
#include <memory>
#include <string>
#include <stdexcept>
#include <cassert>

// шаблонный класс, хранитель ресурсов
template <class Resource, class Identifier>
class ResourceHolder {
private:
	// словарь со ссылками на ресурсы
	std::map<Identifier, std::unique_ptr<Resource>> resources;

public:
	ResourceHolder() {}

	// загрузить ресурс (идентификатор, имя файла)
	void load(Identifier id, const std::string& filename);
	// веернуть ссылку на ресурс по идентификатору
	Resource& get(Identifier id);
};

template <class Resource, class Identifier>
void ResourceHolder<Resource, Identifier>::load(Identifier id, const std::string& filename)
{
	// создаём умный указатель на новый объект
	std::unique_ptr<Resource> resource(new Resource());

	// загружаем ресурс по указанному имени файла
	if (!resource->loadFromFile(filename))
		throw std::exception("ResourceHolder::load - Failed to load a texture.");

	// insert возвращает пару: итератор, показывающий на вставленный объект
	// и BOOLEAN об успешности вставки
	auto inserted = resources.insert(std::make_pair(id, std::move(resource)));

	// если FALSE, значит прошло с ошибкой
	assert(inserted.second);
}

template <class Resource, class Identifier>
Resource& ResourceHolder<Resource, Identifier>::get(Identifier id)
{
	// возвращает итератор на найденный объект
	auto found = resources.find(id);
	// или end, если объект не найден
	assert(found != resources.end());

	// возвращается std::pair какой-то закрученный, нас интересует второй объект из пары
	return *found->second;
}

