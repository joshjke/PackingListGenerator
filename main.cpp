/******************************************************
 * file:        main.cpp
 * project:     PackingListGenerator
 * author-date: JoshJKe - 10/13/18
 * description: generates a packing list from several
 * parameters Weather, Activity, Days, People,
 * and Temperature
 ******************************************************/

#include <iostream>
#include <string>

using namespace std;

const int WEATHER_CONDITION_NUMBER = 4;
const int TEMPERATURE_CONDITION_NUMBER = 7;
const int CATEGORY_NUMBER = 5;
const int SUBCATEGORY_NUMBER = 12;

struct Item
{
public:
    Item(string name, double daysUntilRefresh)
    {
        this->name = name;
        this->daysUntilRefresh = daysUntilRefresh;
    }

    string name;
    double daysUntilRefresh;
};

void clothingListGenerator(Item clothingCatalogue[][SUBCATEGORY_NUMBER], int weatherCondition, int nights)
{
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "|| Camping List || " << nights << " nights ||" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    for (int i = 0; i < SUBCATEGORY_NUMBER; i++)
    {
        if (clothingCatalogue[weatherCondition][i].name != "blank")
        {
            cout << clothingCatalogue[weatherCondition][i].name << " x";
            cout << 1 + int(nights/clothingCatalogue[weatherCondition][i].daysUntilRefresh) << endl;
        }
    }
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
}

int main()
{
    Item  t_shirt("T-Shirt", 1), underwear("Underwear", 1), baseballHat("Baseball Hat", 14),
    hikingPants("Hiking Pants", 3), jeans("Jeans", 3), shorts("Shorts", 2), shortSocks("Short Socks", 1),
    beanie("Beanie", 7), snowCoat("Winter Coat", 30), snowGloves("Gloves", 7), woolSocks("Wool Socks", 1),
    windBreaker("windBreaker", 14), tennisShoes("Tennis Shoes", 120), snowBoots("Winter Boots", 120),
    rainBoots("Rain Boots", 120), sandals("Sandals", 60), longSocks("Long Socks", 1), scarf("Scarf", 7),
    sunglasses("Sunglasses", 120), sweatshirt("Sweatshirt", 4), pajamas("Pajamas", 2), hikingShoes("Hiking Shoes", 120),
    rainJacket("Rain Jacket", 14), windJacket("Wind Jacket", 14), snowPants("Snow Pants", 14),
    umbrella("Umbrella", 21), blank("blank", 0);



    enum WeatherCondition {CLEAR, WIND, RAIN, SNOW};
    enum TemperatureCondition {FREEZING, VERY_COLD, COLD, MEDIUM, MILD, SPICY, FIRE};
    enum CategoryList {CLOTHING, TOILETRY, FOOD, BEDDING, FURNISHING};
    //    Item itemArrayTest[2] = {beanie, winterCoat};

    // [TEMPERATURE_CONDITION_NUMBER][CATEGORY_NUMBER]
    Item itemCatalogue[WEATHER_CONDITION_NUMBER][SUBCATEGORY_NUMBER] =
    {
    { t_shirt, underwear, hikingPants, shortSocks, hikingShoes, baseballHat, pajamas, sweatshirt, windJacket, sunglasses, shorts, sandals}, // CLEAR
    { t_shirt, underwear, hikingPants, longSocks, hikingShoes, baseballHat, pajamas, sweatshirt, windJacket, sunglasses, blank, blank}, // WIND
    { t_shirt, underwear, hikingPants, woolSocks, rainBoots, beanie, pajamas, sweatshirt, rainJacket, snowPants, umbrella, blank}, // RAIN
    { t_shirt, underwear, hikingPants, woolSocks, snowBoots, beanie, pajamas, sweatshirt, snowCoat, snowPants, scarf, blank} // SNOW

    };
    int weather = 0;
    int nights = 0;
    while (weather < 1 || weather > 4)
    {
        cout << "Enter a number for a weather condition" << endl;
        cout << "1 for CLEAR, 2 for WIND, 3 for RAIN, 4 for SNOW: ";
        cin >> weather;
    }


    cout << "Enter the number of nights: ";
    cin >> nights;
    cout << endl << endl;

    clothingListGenerator(itemCatalogue, weather-1, nights);

    return 0;
}
