#ifndef FUNCTIONS_0D_H
#define FUNCTIONS_0D_H

/**
 * @brief Zwraca liczbe calkowita z przedzialu [min, max].
 *
 * @param min poczatek przedzialu losowania (wlacznie).
 * @param max koniec przedzialu losowania (wlacznie).
 * @return int - pseudolosowa wartosc z przedzialu [min, max].
 */
int i_rand(int min, int max);

/**
 * @brief Zwraca liczbe zmiennoprzecinkowa z przedzialu [min, max].
 * 
 * @param min poczatek przedzialu losowania (wlacznie).
 * @param max koniec przedzialu losowania (wlacznie).
 * @return double - pseudolosowa wartosc z przedzialu [min, max].
 */
double d_rand(double min, double max);

/**
 * @brief Zamienia wartosci dwoch zmiennych typu int, ktorych adresy przechowuja parametry first i second.
 * Adresy przekazane jako parametry powinny byc rozne (nie ma sensu zamiana wartosci ze soba).
 * 
 * @param first wskaznik do pierwszej zmiennej.
 * @param second wskaznik do drugiej zmiennej.
 */
void i_swap(int *restrict first, int *restrict second);

/**
 * @brief Zamienia wartosci zajmujace size bajtow pamieci, ktorych adresy przechowuja parametry first i second.
 * 
 * @param first wskaznik do poczatku pierwszego bloku pamieci.
 * @param second wskaznik do poczatku drugiego bloku pamieci.
 * @param size liczba bajtow pamieci do zamiany.
 */
void swap(void * first, void * second, size_t size);

#endif
