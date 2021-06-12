#include "pch.h"
#include "CppUnitTest.h"

#include "../wypozyczalnia_sam/Klient.hpp"
#include "../wypozyczalnia_sam/Klient.cpp"

#include "../wypozyczalnia_sam/Model.hpp"
#include "../wypozyczalnia_sam/Model.cpp"

#include "../wypozyczalnia_sam/Osoba.hpp"
#include "../wypozyczalnia_sam/Osoba.cpp"

#include "../wypozyczalnia_sam/Pracownik.hpp"
#include "../wypozyczalnia_sam/Pracownik.cpp"

#include "../wypozyczalnia_sam/Samochod.hpp"
#include "../wypozyczalnia_sam/Samochod.cpp"

#include "../wypozyczalnia_sam/vectors.hpp"
#include "../wypozyczalnia_sam/vectors.cpp"

#include "../wypozyczalnia_sam/Wypozyczenie.hpp"
#include "../wypozyczalnia_sam/Wypozyczenie.cpp"

using namespace std;

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(KlientGetPesel)
		{
			string imie = "Anna";
			string nazwisko = "Bak";
			string pesel = "839021832";
			string telefon = "32784943";

			Klient k(imie, nazwisko, pesel, telefon);
			Assert::AreEqual(pesel, k.GetPesel());
		}

		TEST_METHOD(KlientFind)
		{
			string imie = "Anna";
			string nazwisko = "Bak";
			string pesel = "839021832";
			string telefon = "32784943";

			Klient k(imie, nazwisko, pesel, telefon);
			klient.push_back(k);

			Assert::AreEqual(int(klient.size()) - 1, Klient::Find(pesel)); //jest taki pesel w bazie wiêc metoda zwraca indeks obiektu na liœcie
			Assert::AreEqual(-1, Klient::Find("389213738")); //nie ma takiego peselu w bazie wiêc metoda zwraca -1
		}

		TEST_METHOD(PracownikGetPesel)
		{
			string imie = "Anna";
			string nazwisko = "Bak";
			string pesel = "839021832";
			string telefon = "32784943";
			string stanowisko = "serwisant";

			Pracownik p(imie, nazwisko, pesel, telefon, stanowisko);
			Assert::AreEqual(pesel, p.GetPesel());
		}

		TEST_METHOD(PracownikFind)
		{
			string imie = "Anna";
			string nazwisko = "Bak";
			string pesel = "839021832";
			string telefon = "32784943";
			string stanowisko = "serwisant";

			Pracownik p(imie, nazwisko, pesel, telefon, stanowisko);
			pracownik.push_back(p);
			Assert::AreEqual(int(pracownik.size()) - 1, Pracownik::Find(pesel)); //jest taki pesel w bazie wiêc metoda zwraca indeks obiektu na liœcie
			Assert::AreEqual(-1, Pracownik::Find("345021864")); //nie ma takiego peselu w bazie wiêc metoda zwraca -1
		}

		TEST_METHOD(SamochodIsModel)
		{
			Model m1("model1", "model1", 120, "automatyczna", "benzyna", 10.00, 5, 5, 8, 1, 120);
			Model m2("model2", "model2", 140, "automatyczna", "benzyna", 12.00, 5, 5, 10, 1, 140);

			model.push_back(m1);
			model.push_back(m2);

			DateOC OC("2020", "12", "11");

			Samochod s(m1, "KR39233", "bialy", 300000, 2010, OC);

			samochod.push_back(s);

			Assert::AreEqual(true, Samochod::IsModel(0)); //Zwraca true jeœli istnieje samochód korzystaj¹cy z modelu zawartym w liœcie dla indexu 0
			Assert::AreEqual(false, Samochod::IsModel(1)); //Nie istnieje samochód korzystaj¹cy z drugiego modelu wiêc zwraca false

			samochod.clear();
			model.clear();
		}

		TEST_METHOD(SamochodGetModel)
		{

			string wersja = "wersja";
			string wersja2 = "wersja2";
			Model m1("model", wersja, 120, "automatyczna", "benzyna", 10.00, 5, 5, 8, 1, 120);
			Model m2("model1", wersja2, 120, "automatyczna", "benzyna", 10.00, 5, 5, 8, 1, 120);

			model.push_back(m1);
			model.push_back(m2);

			DateOC OC("2020", "12", "11");

			Samochod s(m1, "KR39233", "bialy", 300000, 2010, OC);

			samochod.push_back(s);
			
			//u¿ycie metody GetModel() jest poprzedzone metod¹ IsModel() - dany model istnieje
			Assert::AreEqual(true, model[0].Compare( Samochod::GetModel(wersja))); //Zwraca true jeœli istnieje samochód korzystaj¹cy z modelu zawartym w liœcie dla indexu 0
			Assert::AreEqual(false, model[1].Compare(Samochod::GetModel(wersja))); //Zwraca false jeœli nie istnieje samochód korzystaj¹cy z danego modelu


			samochod.clear();
			model.clear();
		}

		TEST_METHOD(SamochodFind)
		{

			Model m1("model", "model1", 120, "automatyczna", "benzyna", 10.00, 5, 5, 8, 1, 120);

			model.push_back(m1);

			DateOC OC("2020", "12", "11");

			string nr_rej1 = "KR39233";

			string nr_rej2 = "KR23454";

			Samochod s1(m1, nr_rej1, "bialy", 300000, 2010, OC);

			Samochod s2(m1, nr_rej2, "bialy", 300000, 2010, OC);

			samochod.push_back(s1);
			samochod.push_back(s2);

			Assert::AreEqual(0, Samochod::Find(nr_rej1)); //zwraca indeks elementu listy której nr rejestracyjny jest równy podanemu
			Assert::AreEqual(1, Samochod::Find(nr_rej2));
			Assert::AreEqual(-1, Samochod::Find("Nieznany")); //zwraca -1 jeœli nie znaleziono samochodu o podanym nr rejestracyjnym
			
			samochod.clear();
			model.clear();
		}

		TEST_METHOD(SamochodGetNrRej)
		{

			Model m1("model", "model1", 120, "automatyczna", "benzyna", 10.00, 5, 5, 8, 1, 120);

			model.push_back(m1);

			DateOC OC("2020", "12", "11");

			string nr_rej1 = "KR39233";

			Samochod s1(m1, nr_rej1, "bialy", 300000, 2010, OC);

			samochod.push_back(s1);

			Assert::AreEqual(nr_rej1, Samochod::GetNrRej(0)); //zwraca nr_rejestracyjny dla obiektu o danym indeksie w liœcie

			samochod.clear();
			model.clear();
		}

		TEST_METHOD(WypozyczenieGetNoGetStatus)
		{

			Model m1("model", "model1", 120, "automatyczna", "benzyna", 10.00, 5, 5, 8, 1, 120);

			model.push_back(m1);

			DateOC OC("2020", "12", "11");

			Samochod s1(m1, "KR39233", "bialy", 300000, 2010, OC);

			Klient k("Adam", "Nowak", "99121308476", "384759374");

			Pracownik p("Adam", "Nowak", "99121308476", "384759374", "recepcjonista");

			klient.push_back(k);

			pracownik.push_back(p);

			samochod.push_back(s1);

			Date d("2020", "12", "22", "13", "00");

			int number = 0;
			int status = 3;

			Wypozyczenie w(d, d, k, s1, p, 200000, 230000, status, number);

			Assert::AreEqual(number, w.GetNo());
			Assert::AreEqual(status, w.GetStatus());

			samochod.clear();
			model.clear();
			wypozyczenie.clear();
			klient.clear();
			pracownik.clear();
		}
	};
}
