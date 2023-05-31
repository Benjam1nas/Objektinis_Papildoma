# Objektinis_Papildoma
Papildoma užduotis objektiniam programavimui

# Užduoties formuluotė

1. Suskaičiuokite, kiek kartų kiekvienas skirtingas žodis pasikartoja Jūsų tekste. Tekstą galite paimti iš bet kur, pvz.: Vikipediją straipsnį apie Vilnių (Geriau kad būtu kitoks tekstas, ne mažiau 1000 žodžių). Tuomet realizacijos output'e (išoriniame faile) išveskite skirtingus žodžius (kableliai, taškai ir kiti skyrybos ženklai nėra žodžiu dalis!), kurie pasikartojo dažniau negu 1 kartą, o taip pat ir count'erį, nurodantį kiek kartų konkretus žodis pasikartojo.
2. Sukurkite cross-reference tipo lentelę kurioje būtų nurodyta, kurioje teksto vietoje (kurioje(-iose) teksto eilutėse) kiekvienas iš daugiau negu vieną kartą pasikartojantis žodis buvo paminėtas.
3. URL adresų suradimas Jūsų tekste. Kaip ir pirmos užduoties atveju, tekstą galite paimti iš bet kur, račiau būtina, kad tame tekste būtų bent keli URL'ai, pateikti "pilnu" https://www.vu.lt/ ar "sutrumpintu" pavidalu: www.vu.lt. Jūsų tikslas, iš to teksto išrinkti visus šiuos URL'us ir grąžiai atspausdinti ekrane (ar išvesti į failą)!
4. Repozicija turi būti parengta pagal visus ankstesnių darbų galutinėms versijoms galiojančius reikalavimus.
5. Papildoma užduotis iš asociatyvių konteinerių ir/ar std::string tematikos bus paskirta egzamino metu "individualiai"!

# Užduoties atlikimas

Susikuriame keleta unordered_map konteinerių. Viename iš jų sudedame sudedame žodžius ir kiekviena kartą skaitant duomenis iš failo pridedama po 1 kai sutampa žodis. Taip pat skaičiuojamos eilutės, kuriose tie žodžiai yra panaudoti, šią informaciją sudedame į kitą unordered map. Norint turėti tikslius duomenis reikia tikrinti ar nėra įvairių simbolių, tam pasitelkiame std::isalnum funckiją. Taip pat raides padarome mažosiomis. URL ieškojamui naudojame regex. URL išvedame į konsolę, o skaičiavimo rezultatus į failą. 

Programa daryta su Visual Studio 2022 su cmake integracija.
