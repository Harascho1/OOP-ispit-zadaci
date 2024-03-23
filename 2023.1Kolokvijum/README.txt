Moramo da napravimo copy Konstruktor

Za klasu u kojoj cuvamo neku kolekciju tu moramo da napravimo:
1.	privatne metode: oslobodiMem() i zauzmi(int n)
2.	prilikom dodele moramo da imamo upit: if (typeid(*niz[i]) == typeid(Cokolada))
3.	ako je upit potvrdan onda radimo: temp.Add(new Cokolada(*dynamic_cast<Cokolada*>(niz[i])));
4.	ako nije onda: temp.Add(new Igracka(*dynamic_cast<Cokolada*>(niz[i])));