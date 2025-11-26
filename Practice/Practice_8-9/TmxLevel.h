#pragma once

#include <string>
#include <vector>
#include <map>
#include <SFML/Graphics.hpp>

// В картах TMX объект - это область на карте, имеющая имя, тип,
//  границы, набор пользовательских свойств (в формате ключ-значение)
//  и текстурные координаты.
// Текстурные координаты позволяют связать с объектом спрайт,
//  использующий основную текстуру карты как источник данных.

// Объявление структуры
// Получает характеристики объекта, объявляет функции перемещения по координатам, выделяет память для имени, типа объекта, его области,
// объявляет словарь с характеристиками объекта, спрайт объекта
struct TmxObject
{
    int id;
    int GetPropertyInt(const std::string &propertyName);
    float GetPropertyFloat(const std::string &propertyName);
    std::string GetPropertyString(const std::string &propertyName);

    void MoveBy(const sf::Vector2f &movement);
    void MoveTo(const sf::Vector2f &position);

    std::string name;
    std::string type;
    sf::FloatRect rect;
    std::map<std::string, std::string> properties;

    sf::Sprite sprite;
};


// В картах TMX слой - это набор тайлов (спрайтов),
//  из которых складывается ландшафт карты.
// Слоёв может быть несколько, что позволяет нарисовать,
//  например, слой травы поверх слоя земли.

// Объявление структуры
// Выделяет память для уровня прозрачности слоя, массива тайлов
struct TmxLayer
{
    sf::Uint8 opacity = 0;
    std::vector<sf::Sprite> tiles;
};

// Объявление класса
// Объявляет функции, возвращающие первый объект с определенным именем, массив всех объектов с определенным именем, массив размера тайла,
// ширину тайловой карты, высоту тайловой карты, массив размера тайловой карты, объявляет функцию отрисовки всех слоев тайлов,
// выделяет память для ширины карты в тайлах, высоты карты в тайлах, ширины тайла, высоты тайла, номера первого тайла, общей текстры всех тайлов,
// массива объектов и массива слоев тайлов
class TmxLevel
{
  public:
    // Загружает данные из TMX в память объекта.
    bool LoadFromFile(const std::string &filepath);

    TmxObject GetFirstObject(const std::string &name) const;
    std::vector<TmxObject> GetAllObjects(const std::string &name) const;
    sf::Vector2i GetTileSize() const;
    float GetTilemapWidth() const;
    float GetTilemapHeight() const;
    sf::Vector2f GetTilemapSize() const;

    // Рисует все слои тайлов один за другим,
    //  но не рисует объекты (рисованием которых должна заниматься игра).
    // Принимает любую цель для рисования, например, sf::RenderWindow.
    void Draw(sf::RenderTarget &target) const;

  private:
    int m_width = 0;
    int m_height = 0;
    int m_tileWidth = 0;
    int m_tileHeight = 0;
    int m_firstTileID = 0;
    sf::Texture m_tilesetImage;
    std::vector<TmxObject> m_objects;
    std::vector<TmxLayer> m_layers;
};
